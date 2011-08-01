
<h1 id="logo"><a href="/cgi-bin/koha/mainpage.pl">[% LibraryName %]</a></h1><!-- Begin Patrons Admin Resident Search Box -->
<div id="header_search">
 <div id="patron_category_search" class="residentsearch">
 <p class="tip">Recherche par catégorie d'adhérent&nbsp;:</p>
 <form action="[% script_name %]" method="post">
 <input type="text" name="description" size="40" value="[% searchfield %]" />
 <input value="Rechercher" name="search" type="submit" class="submit" />
 </form> 
 </div>
 [% INCLUDE 'patron-search-box.inc' %]
 [% IF ( CAN_user_catalogue ) %]
 <div id="catalog_search" class="residentsearch" style="display:none;">
 <p class="tip">Entrer les termes de recherche&nbsp;:</p>
 <form action="/cgi-bin/koha/catalogue/search.pl"  method="get" id="cat-search-block">
 <input value="" name="q" type="text" id="search-form" title="Détermine les serveurs Z3950 que vous voulez que Koha interroge." class="form-text" size="40" />
 <input value="Valider" type="submit" class="submit" />
 </form>
 </div>[% END %]
 <ul>
 <li><a href="/cgi-bin/koha/admin/categorie.pl#patron_category_search">Chercher catégories d'adhérent</a></li>
 [% IF ( CAN_user_circulate ) %]<li><a href="/cgi-bin/koha/circ/circulation.pl#circ_search">Prêt</a></li>[% END %]
 [% IF ( CAN_user_catalogue ) %]<li><a href="/cgi-bin/koha/catalogue/search.pl#catalog_search">Recherche catalogue</a></li>[% END %]
 </ul> 
</div>
<!-- End Patrons Admin Resident Search Box -->
