#!/usr/bin/perl

# Copyright 2000-2002 Katipo Communications
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

=head1

TODO :: Description here

C4::Scrubber is used to remove all markup content from the sumitted text.

=cut

#use strict;
use warnings;
use CGI;
use CGI::Cookie;    # need to check cookies before having CGI parse the POST request

use JSON;

use C4::Auth qw(:DEFAULT check_cookie_auth);
use C4::Context;
use C4::Debug;
use C4::Output 3.02 qw(:html :ajax pagination_bar);
use C4::Dates qw(format_date);
use C4::Scrubber;
use C4::Biblio;
use C4::Ratings;

use Data::Dumper;
use Smart::Comments '####';

my $query = CGI->new();
####  $query
my ( $template, $loggedinuser, $cookie ) = get_template_and_user(
    {   template_name   => "",
        query           => $query,
        type            => "opac",
        authnotrequired => 0,        # auth required to add tags
        debug           => 1,
    }
);

my $biblionumber = $query->param('biblionumber');
my $value;

my $my_rating     = $query->param('my_rating');
my $my_new_rating = $query->param('rating');

my $rating;

####  $my_rating

#### $loggedinuser
if ( $my_rating == '' ) {
####insert
    $rating = add_rating( $biblionumber, $loggedinuser, $my_new_rating );

#### do nothing.
} elsif ( $my_new_rating ne $my_rating ) {

#### update
    $rating = mod_rating( $biblionumber, $loggedinuser, $my_new_rating );

}
print $query->redirect("/cgi-bin/koha/opac-detail.pl?biblionumber=$biblionumber");

