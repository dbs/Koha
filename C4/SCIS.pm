package C4::SCIS;

# Copyright (C) 2009 KohaAloha
# <mason at kohaaloha dot com> 
#
# This file is part of Koha.
#
# Koha is free software; you can redistribute it and/or modify it under the
# terms of the GNU General Public License as published by the Free Software
# Foundation; either version 2 of the License, or (at your option) any later
# version.
#
# Koha is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
# A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with
# Koha; if not, write to the Free Software Foundation, Inc., 59 Temple Place,
# Suite 330, Boston, MA  02111-1307 USA

use strict;
use warnings;

use C4::Context;
use C4::Koha;
use C4::ImportBatch;
use C4::Debug;

use WWW::Mechanize;
use MARC::Batch;
use HTML::TreeBuilder;

#use Smart::Comments '####';

use vars qw($VERSION @ISA @EXPORT );

BEGIN {
    $VERSION = 1.00;

my $input = new CGI;
    require Exporter;
    @ISA = qw( Exporter );

    # to add biblios
    # EXPORTED FUNCTIONS.
    push @EXPORT, qw(
        GetScisLogin
        GetScisBatch
        GetScisBatches

        GetScisMARC
        ModScisMARC

        AddRemoteScisOrder
        GetRemoteScisOrder
        GetRemoteScisIDs

        AddScisBatch
        GetScisBatchItems

        AddScisBatchImport
        AddScisItem
        DelScisItem

        AddScisItemsToMARC
    );
}

=head1 NAME

C4::SCIS - Functions for manipulating SCIS content in Koha

=head1 FUNCTIONS

=cut

sub AddScisItem {
    my ( $scis_batch_id, $isbn, $itemtype, $branchcode, $barcode ) = @_;

    my $user_id = 1;
    my $dbh     = C4::Context->dbh;
    my $query   = qq|INSERT INTO scis_items SET
                       scis_batch_id    = ?,
                       isbn             = ?,
                       itemtype         = ?,
                       branchcode       = ?,
                       barcode          = ?  |;

    my $sth = $dbh->prepare($query);
    $sth->execute( $scis_batch_id, $isbn, $itemtype, $branchcode, $barcode );
}

sub DelScisItem {
    my ( $item_id)  = @_;
    my $dbh     = C4::Context->dbh;
    my $sth = $dbh->do("DELETE from scis_items WHERE id = $item_id");
}

sub AddRemoteScisOrder {
    my @isbns = @_;
    my $isbns_str;

    foreach (@isbns) {
        $isbns_str .= $_ . "\n";
    }

    my $mech = GetScisLogin();
    my $url = 'http://scis.curriculum.edu.au/scisweb/order.php';
    $mech->get($url);
    $mech->get($url);

    my $form = $mech->form_number(1);

    $mech->field( 'textorder', $isbns_str );
    $mech->submit();
    my $r = $mech->find_link( url_regex => qr/^getresultusmarc\.php/ );

    my $order_id = $r->url;
    $order_id =~ s/^.*\=//;
    ## $order_id

    return $order_id;
}

sub GetRemoteScisOrder {
    my ( $order_id, $batch_id ) = @_;
    my $mech = GetScisLogin();
    my $url  = 'http://scis.curriculum.edu.au/scisweb/getresultusmarc.php?orderid=' . "$order_id";
    $mech->get($url);
    $mech->get($url);

    my $marcrecord = $mech->content();

    my $dbh   = C4::Context->dbh;
    my $query = qq|UPDATE  scis_batches  SET
                        scis_order_id       = ?,
                        marc                = ?
                    WHERE scis_batch_id     = ?   |;
    my $sth = $dbh->prepare($query);
    $sth->execute( $order_id, $marcrecord, $batch_id );
    return $marcrecord;
}

sub GetRemoteScisIDs  {
    my ( $order_id, $batch_id ) = @_;
    my $mech = GetScisLogin();
    my $url  = 'http://scis.curriculum.edu.au/scisweb/getresult.php?orderid='  . "$order_id";
    $mech->get($url);
    $mech->get($url);

    my $page = $mech->content();
    my $h = HTML::TreeBuilder->new;
    $h->parse($page);
    my @rows = $h->look_down( "class", "bibtext" );

    my $dbh   = C4::Context->dbh;
    my $query = qq|UPDATE   scis_items
                        SET     scis_id         = ?,
                                title           = ?,
                                author          = ?
                        WHERE   isbn            = ?
                        AND     scis_batch_id   = ? |;
    my $sth = $dbh->prepare($query);

    foreach my $row_el (@rows) {
        my $td_el    = $row_el->parent();
        my $tr_el    = $td_el->parent();
        my $scis_id  = $row_el->as_text;
        my $isbn_el  = $tr_el->look_down( "class", "numbertext" );
        my $isbn     = $isbn_el->as_text();
        my $title_el = $tr_el->look_down( "class", "titletext" );
        my $title    = $title_el->as_text();
        my $author_el = $tr_el->look_down( "class", "authortext" );
        my $author    = $author_el->as_text();

        $isbn   =~ s/\s+$//;
        $title  =~ s/\s+$//;
        $author =~ s/\s+$//;

#        $sth->{TraceLevel} = 3;
        $sth->execute( $scis_id, $title, $author, $isbn, $batch_id );
    }
}


sub AddScisItemsToMARC {
    my ( $scis_batch_id, $marc, $items ) = @_;
    my @recs;

#    my @bb = values %$items;
    open( my $fh, "<", \$marc );
    my $batch = MARC::Batch->new( 'USMARC', $fh );
    $batch->warnings_off();
    $batch->strict_off();

  RECORD: while () {
        my $record;
        eval { $record = $batch->next() };
        if ($@) {
            print "Bad MARC record: skipped\n";
            next;
        }
        last unless ($record);
        my $scis_field  = $record->field( '001' );
        my $scis_id  =  $scis_field->data();

        my $callnum;
        if ( $record->subfield( '082', "a" ) eq 'F' ) {
            $callnum =   $record->subfield( '082', "b" ) ;
        } else   {
            $callnum =   $record->subfield( '082', "a" ) . ' ' . 
                         $record->subfield( '082', "b" );
        }


        my @items;
        # look for scis id to match againist
        foreach my $b (@$items)  {

            if (  $scis_id  ==  $b->{'scis_id'}  ) {
                # ## #match, insert item fields
                my $item_mrc = MARC::Field->new( 952, '', '', xxx => 'xxx' );
                $item_mrc->add_subfields( 'y' => $b->{'itemtype'} );
                $item_mrc->add_subfields( 'p' => $b->{'barcode'} );
                $item_mrc->add_subfields( 'a' => $b->{'branchcode'} );
                $item_mrc->add_subfields( 'b' => $b->{'branchcode'} );
                $item_mrc->add_subfields( 'o' => $callnum  );
                $item_mrc->delete_subfield( code => 'xxx' );

                push @items, $item_mrc;
            }
        }
        $record->insert_fields_ordered(@items);
        push @recs, $record;
    }
    my $newmarc;
    foreach my $a (@recs) {

        $newmarc .= $a->as_usmarc();
    }

    my $dbh   = C4::Context->dbh;
    my $query = qq|UPDATE   scis_batches
                        SET     marc            = ?
                        WHERE   scis_batch_id   = ? |;
    my $sth = $dbh->prepare($query);
    $sth->execute( $newmarc, $scis_batch_id );
    return $newmarc;
}


sub ModScisMARC {
    my ($order_id, $batch_id, $marcrecord) = @_;

    my $user_id = 1;
    my $dbh     = C4::Context->dbh;
    my $query   = qq|
                    UPDATE scis_batches
                    SET     scis_order_id       = ?,
                            marc                = ?
                    WHERE   scis_batches        = ?   |;
    my $sth = $dbh->prepare($query);
    $sth->execute( $order_id, $marcrecord, $batch_id  );
}

sub GetScisMARC {
    my ($batch_id) = @_;
    my $user_id = 1;
    my $dbh     = C4::Context->dbh;
    my $q       = qq|           SELECT marc FROM scis_batches
                                WHERE scis_batch_id  = ?     |;
    my $hash_ref = $dbh->selectrow_hashref( $q, undef, $batch_id );
    return;
}

sub AddScisBatchImport {
    my ($scis_batch_id, $scis_order_id, $marc) = @_;
    my $comments = 'moo';

    # save marc to tmp file
    my $filename = "scis-$scis_order_id.mrc";
    my ( $import_batch_id, $num_valid, $num_items, @import_errors ) 
        = BatchStageMarcRecords( 'MARC21', $marc, $filename, $comments, '', 1, 0,  );

    my $user_id = 1;
    my $dbh     = C4::Context->dbh;
    my $query   = qq|UPDATE  scis_batches  SET
                        import_batch_id  = ?
                    WHERE scis_batch_id  = ?  |;
    my $sth = $dbh->prepare($query);
#    $sth->{TraceLevel} = 3;
    $sth->execute( $import_batch_id ,$scis_batch_id    );

    # now add to koha import_batches
    return $import_batch_id;
}

sub GetScisLogin {
    my %creds = (
        user     => C4::Context->preference("ScisUsername"),
        password => C4::Context->preference("ScisPassword"),
        realm    => 'SCISweb',
        site     => 'scis.curriculum.edu.au:80',
    );

    my $mech = WWW::Mechanize->new();
    $mech->credentials( $creds{'site'},
                        $creds{'realm'},
                        $creds{'user'},
                        $creds{'password'} );
    return $mech;
}

sub GetScisBatches {
    my $dbh   = C4::Context->dbh;

    my $query = qq| SELECT scis_order_id,
                            scis_batch_id,
                            import_batch_id,
                            create_timestamp,
                            user_id,
                            comments
                    FROM scis_batches
                    ORDER by scis_order_id DESC|;
    my $sth = $dbh->prepare($query);
    $sth->execute();

    #get status
    my @rows;
    while ( my $row = $sth->fetchrow_hashref ) {
        $row->{status} = GetImportBatchStatus( $row->{import_batch_id} );
        ( undef, $row->{item_count} ) = GetScisBatchItems( $row->{scis_batch_id} );
        push @rows, $row;

    }
    $sth->finish;
    return \@rows;
}

sub GetScisBatch {
    my ($batch_id) = @_;
    my $query = qq| SELECT scis_order_id,
                            scis_batch_id,
                            import_batch_id,
                            create_timestamp,
                            user_id,
                            comments,
                            auto_barcode
                    FROM scis_batches
                    WHERE scis_batch_id = ? |;

    my $dbh     = C4::Context->dbh;
    my $sth = $dbh->prepare($query);
    $sth->execute( $batch_id  );

    my $batch  = $sth->fetchrow_hashref();
    $batch->{status} = GetImportBatchStatus( $batch->{import_batch_id} );
    return $batch
}

sub GetScisBatchItems {
    my ($scis_batch_id) = @_;
    my $query = qq| SELECT * from scis_items
                    WHERE scis_batch_id = ?
                    ORDER BY id DESC |;

    my $dbh = C4::Context->dbh;
    my $sth = $dbh->prepare($query);
    $sth->execute($scis_batch_id);

    my @batches;
    my $cnt;
    while ( my $batch = $sth->fetchrow_hashref ) {
        $batch->{status}       = GetImportBatchStatus( $batch->{import_batch_id} );
        $batch->{nomatcstatus} = GetImportBatchStatus( $batch->{import_batch_id} );
        push @batches, $batch;
        $cnt++;
    }
    $sth->finish;
    return \@batches, $cnt;

}

sub AddScisBatch {
    # save marc to tmp file
    my ( $comments, $user_id ) = @_;
    my $dbh   = C4::Context->dbh;
    my $query = qq|INSERT INTO scis_batches
                    SET     user_id     = ?,
                            comments    = ?    |;
    my $sth = $dbh->prepare($query);
    $sth->execute( $user_id, $comments );
    my $batch_id = $dbh->last_insert_id( undef, undef, 'scis_batches', 'scis_batch_id' );
    return $batch_id;
}

1;
__END__

=head1 NOTES

=head1 AUTHOR

KohaAloha  <mason@kohaaloha.com>

=cut

