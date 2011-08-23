package C4::Ratings;

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

use strict;
use warnings;
use Carp;
use Exporter;
use POSIX;
use C4::Debug;
use C4::Context;
#use Smart::Comments '####';

use vars qw($VERSION @ISA @EXPORT @EXPORT_OK %EXPORT_TAGS);

BEGIN {
    $VERSION = 3.00;
    @ISA     = qw(Exporter);

    @EXPORT = qw(
      &get_rating
      &add_rating
      &mod_rating
      &del_rating
    );
}

sub get_rating {
    my ( $biblionumber, $borrowernumber ) = @_;
    my $query = qq| SELECT COUNT(rating_id) AS total, SUM(value) AS sum 
FROM ratings WHERE biblionumber = ? |;

    my $sth = C4::Context->dbh->prepare($query);
    $sth->execute($biblionumber);
    my $res = $sth->fetchrow_hashref();

    my $avg;
    eval { $avg = $res->{sum} / $res->{total} };
    my $avg_int = sprintf( "%.1f", $avg );
    my $avg = sprintf( "%.0f", $avg );

    my %rating_hash;
    $rating_hash{total}  = $res->{total};
    $rating_hash{avg}    = $avg;
    $rating_hash{avg_int} = $avg_int;

    if ($borrowernumber) {
        my $q2 = qq| SELECT value FROM ratings 
WHERE biblionumber = ? AND borrowernumber = ?|;
        my $sth1 = C4::Context->dbh->prepare($q2);
        $sth1->execute( $biblionumber, $borrowernumber );
        my $res1 = $sth1->fetchrow_hashref();
        $rating_hash{'my_rating'} = $res1->{"value"};
    }
    return \%rating_hash;
}

sub add_rating {
    my ( $biblionumber, $borrowernumber, $value ) = @_;
    my $query = qq| INSERT INTO ratings (borrowernumber,biblionumber,value)
        VALUES (?,?,?)|;
    my $sth = C4::Context->dbh->prepare($query);
    $sth->execute( $borrowernumber, $biblionumber, $value );
    my $rating = get_rating( $biblionumber, $borrowernumber );
    return $rating;
}

sub mod_rating {
    my ( $biblionumber, $borrowernumber, $value ) = @_;
    my $query = qq|UPDATE ratings SET value = ? WHERE borrowernumber = ? AND biblionumber = ?|;
    my $sth   = C4::Context->dbh->prepare($query);
    $sth->execute( $value, $borrowernumber, $biblionumber );
    my $rating = get_rating( $biblionumber, $borrowernumber );
    return $rating;
}

# del_rating is currently only used for passing the Ratings.t test
sub del_rating {
    my ( $biblionumber, $borrowernumber ) = @_;
    my $dbh = C4::Context->dbh;
    my $query = "delete from ratings where borrowernumber = ? and biblionumber = ?";
    my $sth   = C4::Context->dbh->prepare($query);
    my $rv = $sth->execute( $borrowernumber, $biblionumber );
    my $rating = get_rating( $biblionumber , undef );
    return $rating;
}

1;
__END__

=head1 NAME

C4::Ratings - creates, updates and fetches Koha ratings

=head1 SYNOPSIS

# get a rating for a bib
 my $rating = get_rating( $biblionumber, undef );
 my $rating = get_rating( $biblionumber, $borrowernumber );

# add a rating for a bib
 my $rating = add_rating( $biblionumber, $borrowernumber, $my_new_rating );

# mod a rating for a bib
 my $rating = mod_rating( $biblionumber, $borrowernumber, $my_new_rating );

# delete a rating for a bib
 my $rv = del_rating( $biblionumber, $borrowernumber );

=head1 DESCRIPTION

This module provides simple functionality for a user to 'rate' a biblio, and to return a biblio's rating infor

=head1 BUGS

Please use bugs.koha-community.org for tracking bugs.

=head1 SOURCE AVAILABILITY

The source is available from the koha-community.org git server
L<http://git.koha-community.org>

=head1 AUTHOR

Original code: Mason James <mtj@kohaaloha.com>

=head1 COPYRIGHT

Copyright (c) 2011 Mason James <mtj@kohaaloha.com>

=head1 LICENSE

C4::Ratings is free software. You can redistribute it and/or
modify it under the same terms as Koha itself.

=head1 CREDITS

 Mason James <mtj@kohaaloha.com>

=cut
