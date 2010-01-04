#!/usr/bin/perl

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
#

use strict;

use CGI;
use C4::Output;
use C4::Auth;
use C4::AuthoritiesMarc;
use C4::Koha;
use C4::SCIS;
use C4::Barcodes;
use C4::Branch;
use C4::Debug;

# use Smart::Comments;

my $input = new CGI;
### $input

my ( $template, $loggedinuser, $cookie ) = get_template_and_user(
    {   template_name   => "/scis/scis-scan-isbns.tmpl",
        query           => $input,
        type            => "intranet",
        authnotrequired => 0,
        flagsrequired   => { catalogue => 1, },
    }
);

my $scis_batch_id  = $input->param('scis_batch_id');
my $auto_barcode   = $input->param('auto_barcode');
my $barcode        = $input->param('barcode');
my $op_add_isbn    = $input->param('op_add_isbn');
my $op_add_barcode = $input->param('op_add_barcode');
my $op_del_item    = $input->param('op_del_item');
my $item_id        = $input->param('item_id');
my $isbn           = $input->param('isbn');
my $itemtype       = $input->param('itemtype');
my $branchcode     = $input->param('branchcode');

$auto_barcode = 1 if $auto_barcode eq 'on';
my $bc_obj;

if ( $auto_barcode == 1 ) {

    $bc_obj  = C4::Barcodes->new();
    $barcode = $bc_obj->value;
    my $query = "SELECT max(abs(barcode)) FROM scis_items LIMIT 1";
    my $sth   = C4::Context->dbh->prepare($query);
    $sth->execute();
    my $max_bc = $sth->fetchrow_array;
    $barcode = $max_bc if $max_bc > $barcode;
    $barcode++;
}

my $branches = GetBranches();

my @branches_loop;
foreach my $brch ( sort keys %$branches ) {
    my $selected = 1 if $brch eq $branchcode;
    my %row = (
        value       => $brch,
        selected    => $selected,
        description => $branches->{$brch}->{'branchname'},
    );
    push @branches_loop, \%row;
}

my $itemtypes = GetItemTypes;
my @itemtypesloop;
foreach my $thisitemtype ( sort keys %$itemtypes ) {
    my $selected = 1 if $thisitemtype eq $itemtype;
    my %row = (
        value       => $thisitemtype,
        selected    => $selected,
        description => $itemtypes->{$thisitemtype}->{'description'},
    );
    push @itemtypesloop, \%row;
}

if ( ( $op_add_isbn and $auto_barcode == 1 ) or ($op_add_barcode) ) {
    AddScisItem( $scis_batch_id, $isbn, $itemtype, $branchcode, $barcode );
} elsif ( $op_add_isbn and $auto_barcode ne 1 ) {
    $template->param( op_scan_barcode => 1 );
    $template->param( isbn            => $isbn );
}

if ( $op_del_item == 1 ) {
    DelScisItem($item_id);
}

# display batches table;
my ( $items, $cnt ) = GetScisBatchItems($scis_batch_id);
my $batch = GetScisBatch($scis_batch_id);
### $batch

$template->param(
    items_loop      => $items,
    scis_batch_id   => $scis_batch_id,
    batch_status    => $batch->{status},
    auto_barcode    => $auto_barcode,
    import_batch_id => $batch->{import_batch_id},
    itemtypeloop    => \@itemtypesloop,
    branches_loop   => \@branches_loop,
);

output_html_with_http_headers $input, $cookie, $template->output;
