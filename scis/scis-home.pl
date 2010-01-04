#!/usr/bin/perl

# Copyright (C) 2009 KohaAloha
# <mason at kohaaloha dot com>
#
# This file is part of Koha.

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
#

use strict;

use CGI;
use C4::Output;
use C4::Auth;
use C4::AuthoritiesMarc;
use C4::Koha;
use C4::SCIS;
use C4::Debug ;

my $input = new CGI;
my ( $template, $loggedinuser, $cookie ) = get_template_and_user(
    {   template_name   => "/scis/scis-home.tmpl",
        query           => $input,
        type            => "intranet",
        authnotrequired => 0,
        flagsrequired   => { catalogue => 1, },
    }
);

my $op_add_batch    = $input->param('op_add_batch');
my $op_import_order = $input->param('op_import_order');
my $op_add_batch    = $input->param('op_add_batch');
my $op_show_batch   = $input->param('op_show_batch');
my $op_save_batch   = $input->param('op_save_batch');
my $scis_batch_id   = $input->param('scis_batch_id');
my $comments        = $input->param('comments');

my $user_id = $input->param('user_id');
my @batch_loop;

if ( $op_add_batch == 1 ) {
    $template->param( op_add_batch => 1 );
}

elsif ( $op_import_order == 1 ) {
    #get isbns for batch
    my ($items, $cnt) = GetScisBatchItems($scis_batch_id);
    my @isbns;

    foreach ( @$items) {
        push @isbns , $_->{'isbn'} ;
    }

    my $order_id = AddRemoteScisOrder(@isbns);
    my $marc = GetRemoteScisOrder( $order_id, $scis_batch_id );
    GetRemoteScisIDs( $order_id, $scis_batch_id );

    # RELOAD ITEMS TO GET NEWLY FETCHED SCIS_IDS
    my ( $items, $cnt ) = GetScisBatchItems($scis_batch_id);
    $marc = AddScisItemsToMARC( $scis_batch_id, $marc, $items );
    my $import_batch_id = AddScisBatchImport( $scis_batch_id, $order_id, $marc );

    print $input->redirect("/cgi-bin/koha/tools/manage-marc-import.pl?import_batch_id=$import_batch_id");

} else {    #DEFAULT SHOW BATCHES
    my $isbns;
    if ( $op_save_batch == 1 ) {
        my $scis_batch_id = AddScisBatch( $comments, $user_id );
        print $input->redirect("/cgi-bin/koha/scis/scis-scan-isbns.pl?scis_batch_id=$scis_batch_id");
    }
    my $batches = GetScisBatches();
    $template->param( batches_loop => $batches  );
}

output_html_with_http_headers $input, $cookie, $template->output;
