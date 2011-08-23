#!/usr/bin/perl

# Copyright 2011 KohaAloha, NZ
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
# You should have received a copy of the GNU General Public License along
# with Koha; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

=head1 DESCRIPTION

A script that takes an ajax json query, and then inserts or modifies a star-rating.

=cut

use strict;
use warnings;
use CGI;
use CGI::Cookie;    # need to check cookies before having CGI parse the POST request
#use JSON;

use C4::Auth qw(:DEFAULT check_cookie_auth);
use C4::Context;
use C4::Debug;
use C4::Output 3.02 qw(:html :ajax pagination_bar);
use C4::Dates qw(format_date);
use C4::Ratings;
use Data::Dumper;
use Smart::Comments '####';

my $is_ajax = is_ajax();
my $query = ($is_ajax) ? &ajax_auth_cgi( {} ) : CGI->new();
my $biblionumber = $query->param('biblionumber');
my $my_current_rating     = $query->param('my_current_rating');
my $my_new_rating = $query->param('my_new_rating');

my ( $template, $loggedinuser, $cookie );
if ($is_ajax) {

    # must occur AFTER auth
    $loggedinuser = C4::Context->userenv->{'number'};

} else {
    ( $template, $loggedinuser, $cookie ) = get_template_and_user(
        {   template_name   => "opac-tags.tmpl",
            query           => $query,
            type            => "opac",
            authnotrequired => 0,       # auth required to add tags
            debug           => 1,
        }
    );
}

my $rating;
if ( $my_new_rating and  $my_current_rating eq '' ) {
#### insert
    $rating = add_rating( $biblionumber, $loggedinuser, $my_new_rating );
} elsif  ($my_new_rating eq '') {
#### delete
    $rating = del_rating( $biblionumber, $loggedinuser );
} elsif ($my_new_rating ne $my_current_rating) {
#### update
    $rating = mod_rating( $biblionumber, $loggedinuser, $my_new_rating );
}

my %js_reply = (
    total         => $rating->{'total'},
    avg           => $rating->{'avg'},
    avg_int       => $rating->{'avg_int'},
    my_new_rating => $rating->{'my_rating'}

);




use JSON;
my $json_reply  = JSON->new->encode(\%js_reply);


#### $rating
#### %js_reply
#### $json_reply



output_ajax_with_http_headers( $query, $json_reply );
exit;

# TODO: move this sub() to C4:Auth...
sub ajax_auth_cgi ($) {    # returns CGI object
    my $needed_flags = shift;
    my %cookies      = fetch CGI::Cookie;
    my $input        = CGI->new;
    my $sessid       = $cookies{'CGISESSID'}->value || $input->param('CGISESSID');
    my ( $auth_status, $auth_sessid ) = check_cookie_auth( $sessid, $needed_flags );
    $debug
      and print STDERR "($auth_status, $auth_sessid) = check_cookie_auth($sessid," . Dumper($needed_flags) . ")\n";
    if ( $auth_status ne "ok" ) {
        output_ajax_with_http_headers $input, "window.alert('Your CGI session cookie ($sessid) is not current.  " . "Please refresh the page and try again.');\n";
        exit 0;
    }
    $debug and print STDERR "AJAX request: " . Dumper($input), "\n(\$auth_status,\$auth_sessid) = ($auth_status,$auth_sessid)\n";
    return $input;
}

