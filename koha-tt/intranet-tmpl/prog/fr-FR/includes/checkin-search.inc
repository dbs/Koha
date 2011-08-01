
<h1 id="logo"><a href="/cgi-bin/koha/mainpage.pl">[% LibraryName %]</a></h1><!-- Begin Checkin Resident Search Box -->
<div id="header_search">
[% INCLUDE 'patron-search-box.inc' %]
[% IF ( CAN_user_catalogue ) %]
<div id="catalog_search" class="residentsearch" style="display:none;">
 <p class="tip">Entrer les termes de recherche&nbsp;:</p>
 <form action="/cgi-bin/koha/catalogue/search.pl"  method="get" id="cat-search-block">
 <input type="text" name="q" id="search-form" size="40" />
 <input value="Valider" type="submit" class="submit" />
 </form>
</div>
[% END %]
<ul>
 [% IF ( CAN_user_circulate ) %]<li><a href="/cgi-bin/koha/circ/circulation.pl#circ_search">Prêt</a></li>[% END %]
 [% IF ( CAN_user_catalogue ) %]<li><a href="/cgi-bin/koha/catalogue/search.pl#catalog_search">Recherche catalogue</a></li>[% END %]
</ul> 

</div>

<!-- End Checkin Resident Search Box -->
