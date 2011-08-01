<fieldset id="acqui_basket_add">
 <legend>Ajouter une ligne au panier</legend>
 <form action="/cgi-bin/koha/acqui/neworderbiblio.pl" method="post">
 <input type="hidden" name="booksellerid" value="[% booksellerid %]" />
 <input type="hidden" name="basketno" value="[% basketno %]" />
 <ul><li><label for="q">From an existing record: </label><input id="q" type="text"  size="25" name="q" />
 <input value="Rechercher" type="submit" class="submit" /></li>
 <li><a href="/cgi-bin/koha/acqui/newordersuggestion.pl?booksellerid=[% booksellerid %]&amp;basketno=[% basketno %]">A partir d'une suggestion</a></li>
 <li><a href="/cgi-bin/koha/acqui/neworderempty.pl?booksellerid=[% booksellerid %]&amp;basketno=[% basketno %]">A partir d'une nouvelle notice (vide) </a></li>
 <li><a href="/cgi-bin/koha/acqui/z3950_search.pl?booksellerid=[% booksellerid %]&amp;basketno=[% basketno %]">A partir d'une source externe</a></li>
 <li><a href="/cgi-bin/koha/acqui/addorderiso2709.pl?booksellerid=[% booksellerid %]&amp;basketno=[% basketno %]">A partir d'un fichier importé</a></li>
 </ul>
 </form>
</fieldset>