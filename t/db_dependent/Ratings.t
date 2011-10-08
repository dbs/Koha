#!/usr/bin/perl
#
use strict;
use warnings;
use Test::More tests => 12;

# use Smart::Comments '####';

BEGIN {

    use FindBin;
    use C4::Ratings;
    use_ok('C4::Ratings');

    my $rating1 = add_rating( 1, 1, 3 );
    my $rating2 = add_rating( 1, 2, 4 );
    my $rating3 = mod_rating( 1, 1, 5 );
    my $rating4 = get_rating( 1, 1 );
    my $rating5 = get_rating( 1, undef );
    my $rating6 = del_rating( 1, 1 );
    my $rating7 = del_rating( 1, 2 );

    ok( defined $rating1, 'add a rating' );
    ok( defined $rating2, 'add another rating' );
    ok( defined $rating3, 'update a rating' );
    ok( defined $rating4, 'get a rating' );
    ok( defined $rating5, 'get a rating, passing no userid' );
    ok( $rating3->{'avg'} == '4',     "get a bib's average(float) rating" );
    ok( $rating3->{'avg_int'} == 4.5, "get a bib's average(int) rating" );
    ok( $rating3->{'total'} == 2,     "get a bib's total number of ratings" );
    ok( $rating3->{'my_rating'} == 5, "get a users rating for a bib" );
    ok( defined $rating6,             'delete a rating' );
    ok( defined $rating7,             'delete another rating' );
}

=c

$ perl  ./t/db_dependent/Ratings.t 
1..12
ok 1 - use C4::Ratings;
ok 2 - add a rating
ok 3 - add another rating
ok 4 - update a rating
ok 5 - get a rating
ok 6 - get a rating, passing no userid
ok 7 - get a bib's average(float) rating
ok 8 - get a bib's average(int) rating
ok 9 - get a bib's total number of ratings
ok 10 - get a users rating for a bib
ok 11 - delete a rating
ok 12 - delete another rating

=cut
