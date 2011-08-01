
<h1 id="logo"><a href="/cgi-bin/koha/mainpage.pl">[% LibraryName %]</a></h1><!-- Begin Circulation Resident Search Box -->

<div id="header_search">
 [% INCLUDE 'patron-search-box.inc' %]
[% IF ( CAN_user_circulate ) %]
<div id="checkin_search" class="residentsearch" style="display:none;">
 <p class="tip">Scanner un code-barres pour le retour</p>
 <form method="post" action="/cgi-bin/koha/circ/returns.pl">
 <input name="barcode" id="ret_barcode" size="40" accesskey="r" />
 <input value="Valider" class="submit" type="submit" />
 </form>
</div>[% END %]
[% IF ( CAN_user_catalogue ) %]
<div id="catalog_search" class="residentsearch" style="display:none;">
 <p class="tip">Entrer les termes de recherche&nbsp;:</p>
 <form action="/cgi-bin/koha/catalogue/search.pl"  method="get" id="cat-search-block">
 <input type="text" name="q" id="search-form" size="40" accesskey="q" />
 <input value="Valider" type="submit" class="submit" />
 </form>
</div>[% END %]

<ul>
 [% IF ( CAN_user_circulate ) %]<li><a href="/cgi-bin/koha/circ/circulation.pl#circ_search">Prêt</a></li>[% END %]
 [% IF ( CAN_user_circulate ) %]<li><a href="/cgi-bin/koha/circ/returns.pl#checkin_search">Retour</a></li>[% END %]
 [% IF ( CAN_user_catalogue ) %]<li><a href="/cgi-bin/koha/catalogue/search.pl#catalog_search">Recherche catalogue</a></li>[% END %]
</ul> 

</div>

<!-- End Circulation Resident Search Box -->
