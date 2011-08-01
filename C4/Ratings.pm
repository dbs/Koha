package C4::Ratings;
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
use Carp;
use Exporter;
use POSIX;

use C4::Debug;
use C4::Context;

use Smart::Comments '####';

use vars qw($VERSION @ISA @EXPORT @EXPORT_OK %EXPORT_TAGS);

BEGIN {
	$VERSION = 3.00;
	@ISA = qw(Exporter);

=c
	@EXPORT_OK = qw(
		&get_rating &get_ratings
		&add_rating &add_ratings
	);
=cut

	@EXPORT = qw(
		&get_rating &get_ratings
		&add_rating &add_ratings
		&mod_rating
        &get_rating_by_review
	);


#	%EXPORT_TAGS = ();
}


# ---------------------------------------------------------------------

sub get_rating {
#### @_
    my ( $biblionumber, $borrowernumber ) = @_;

    my $query = "
    SELECT    count(rating_id) as total, sum(value) as sum  from ratings
    WHERE       biblionumber = ?";

    my $sth = C4::Context->dbh->prepare($query);
    $sth->execute($biblionumber);
    my $res = $sth->fetchrow_hashref();

    my $avg;
    eval { $avg = $res->{sum} / $res->{total} };
    my $avgint = sprintf( "%.0f", $avg );
    warn $avgint;

    my %rating_hash;
    $rating_hash{total}  = $res->{total};
    $rating_hash{avg}    = $avg;
    $rating_hash{avgint} = $avgint;
    $rating_hash{stats}  = "foo";

    if ($borrowernumber) {

####  $res
        my $q2 = "
    SELECT    value  from ratings
    WHERE       biblionumber = ? and borrowernumber = ?";

        my $sth1 = C4::Context->dbh->prepare($q2);

        #    $sth1->{TraceLevel} = 3;
        $sth1->execute( $biblionumber, $borrowernumber );
        my $res1 = $sth1->fetchrow_hashref();
        $rating_hash{'my_rating'}  = $res1->{"value"};
        $rating_hash{'value'}  = $res1->{"value"};

    }



    #### %rating_hash
    return \%rating_hash;
}


=c
sub get_rating_by_review {
    my ( $reviewid, $biblionumber, $borrowernumber ) = @_;

    my $q = "SELECT value from ratings where reviewid = ?";

    my $sth = C4::Context->dbh->prepare($q);
    $sth->execute( $reviewid );
    my $res  = $sth->fetchrow_hashref();

####  $res
    my $q2 = "
	SELECT    value as v  from ratings
    WHERE       biblionumber = ? and borrowernumber = ?";

    my $sth1 = C4::Context->dbh->prepare($q2 );
#    $sth1->{TraceLevel} = 3;
    $sth1->execute( $biblionumber, $borrowernumber );
    my $res1  = $sth1->fetchrow_hashref();

    my $avg;
    eval {   $avg = $res->{sum} / $res->{total}  }; warn $@ if $@;
    my $avgint  = sprintf("%.0f", $avg ); 
    my %rating_hash;
    $rating_hash{total} =  $res->{total};
    $rating_hash{avg} =  $avg;
    $rating_hash{avgint} = $avgint;
    $rating_hash{stats} = "foo";
    $rating_hash{value} = $res1->{"v"};
    #### %rating_hash

    return $res->{'value'} ;
}
=cut





sub add_rating  {
	my ($biblionumber , $borrowernumber,  $value) = @_;

#	my $query = "delete from ratings where borrowernumber = ? and biblionumber = ? limit 1";
#	my $sth = C4::Context->dbh->prepare($query);
#	$sth->execute($borrowernumber,$biblionumber );

	my $query = "INSERT INTO ratings (borrowernumber,biblionumber,value)
	VALUES (?,?,?)";
	my $sth = C4::Context->dbh->prepare($query);
	$sth->execute($borrowernumber,$biblionumber,$value);

	my $rating  =  get_rating (  $biblionumber, $borrowernumber );
#    $rating->{value} = $value;

    ####  $rating;

    return $rating;
}


sub mod_rating {
    my ( $biblionumber, $borrowernumber, $value ) = @_;

    my $query = "update ratings set value = ? where borrowernumber = ? and biblionumber = ?";
    my $sth   = C4::Context->dbh->prepare($query);
    $sth->trace(3);
    $sth->execute( $value, $borrowernumber, $biblionumber  );

    my $rating = get_rating( $biblionumber, $borrowernumber );
    return $rating;
}








1;
