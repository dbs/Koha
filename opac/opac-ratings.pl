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

use strict;
use warnings;
use CGI;
use CGI::Cookie; # need to check cookies before having CGI parse the POST request

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

# use C4::Tags qw(add_tag get_approval_rows get_tag_rows remove_tag);


my %ratings = ();
my @deltags = ();
my %counts  = ();
my @errors  = ();


# The trick here is to support multiple tags added to multiple bilbios in one POST.
# The HTML might not use this, but it makes it more web-servicey from the start.
# So the name of param has to have biblionumber built in.
# For lack of anything more compelling, we just use "newtag[biblionumber]"
# We split the value into tags at comma and semicolon

my $is_ajax = is_ajax();
####  $is_ajax 


my $query = ($is_ajax) ? &ajax_auth_cgi({}) : CGI->new();
####  $query


my $biblionumber   = $query->param('biblionumber');
#my $borrowernumber   = $query->param('borrowernumber');
my $value ;

	foreach ($query->param) {
		if (/^rating(.*)/) {
			$value =  $query->param($_);
            last;
		}
	}

my ($template, $loggedinuser, $cookie);


if ($is_ajax) {
 # must occur AFTER auth
	$loggedinuser = C4::Context->userenv->{'number'}; 

} else {
	($template, $loggedinuser, $cookie) = get_template_and_user({
		template_name   => "opac-tags.tmpl",
		query           => $query,
		type            => "opac",
		authnotrequired => 0,	# auth required to add tags
		debug           => 1,
	});
}


#### $loggedinuser

#### aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
my $rating = 	add_rating(     $biblionumber ,  $loggedinuser ,  $value) ;


if ($is_ajax) {
	my $sum = 0;

#	my $js_reply = "($total), your rating $value added";
	my $js_reply = "{total: $rating->{'total'}, value: $rating->{'value'}}";


#my %json = ( "total" , 25,
#           "value" ,    10);
#           ;
        
#my  $js_reply= encode_json \%coins;
##u ##   $json


#### ooooooooooooooooooooooo
#### ooooooooooooooooooooooo
#### ooooooooooooooooooooooo
#### ooooooooooooooooooooooo
	#### $js_reply


	output_ajax_with_http_headers($query,$js_reply);
	exit;
}

my $results = [];
my $my_tags = [];

if ($loggedinuser and not $query->param('hidemytags')) {

}

$template->param(tagsview => 1);



(scalar @errors  ) and $template->param(ERRORS  => \@errors);
(scalar @$results) and $template->param(TAGLOOP => $results);
(scalar @$my_tags) and $template->param(MY_TAGS => $my_tags);

output_html_with_http_headers $query, $cookie, $template->output;








sub ajax_auth_cgi ($) {     # returns CGI object
    my $needed_flags = shift;
	my %cookies = fetch CGI::Cookie;
	my $input = CGI->new;
	my $sessid = $cookies{'CGISESSID'}->value || $input->param('CGISESSID');
	my ($auth_status, $auth_sessid) = check_cookie_auth($sessid, $needed_flags);
	$debug and
	print STDERR "($auth_status, $auth_sessid) = check_cookie_auth($sessid," . Dumper($needed_flags) . ")\n";
	if ($auth_status ne "ok") {
		output_ajax_with_http_headers $input,
		"window.alert('Your CGI session cookie ($sessid) is not current.  " .
		"Please refresh the page and try again.');\n";
		exit 0;
	}
	$debug and print STDERR "AJAX request: " . Dumper($input),
		"\n(\$auth_status,\$auth_sessid) = ($auth_status,$auth_sessid)\n";
	return $input;
}







__END__

=head1 EXAMPLE AJAX POST PARAMETERS

CGISESSID	7c6288263107beb320f70f78fd767f56
newtag396	fire,+<a+href="foobar.html">foobar</a>,+<img+src="foo.jpg"+/>

So this request is trying to add 3 tags to biblio #396.  The CGISESSID is the same as that the browser would
typically communicate using cookies.  If it is valid, the server will split the value of "newtag396" and
process the components for addition.  In this case the intended tags are:
	fire
	<a+href="foobar.html">foobar</a>
	<img src="foo.jpg" />

The first tag is acceptable.  The second will be scrubbed of markup, resulting in the tag "foobar".
The third tag is all markup, and will be rejected.

=head1 EXAMPLE AJAX JSON response

response = {
	added: 2,
	deleted: 0,
	errors: 2,
	alerts: [
		 KOHA.Tags.tag_message.scrubbed("foobar"),
 		 KOHA.Tags.tag_message.scrubbed_all_bad("1"),
 	],
};

=cut

