<script type="text/javascript">//<![CDATA[
    $(document).ready(function() {
        var path = location.pathname.substring(1);
        var url = window.location.toString();
        url.match(/\?(.+)$/);
        var params = RegExp.$1;
        if (params) { params = "?" + params; }
        $('#navmenulist a[href$="/' + path + params + '"]').css('font-weight','bold');
    });
//]]>
</script>
<div id="navmenu">
<div id="navmenulist">
<h5>Préférences système</h5>
<ul>
 <li><a href="/cgi-bin/koha/admin/preferences.pl">Préférences système</a></li>
</ul>

<h5>Paramètres de base</h5>
<ul>
 <li><a href="/cgi-bin/koha/admin/branches.pl">Sites et groupes</a></li>
 <li><a href="/cgi-bin/koha/admin/itemtypes.pl">Types de document</a></li>
 <li><a href="/cgi-bin/koha/admin/authorised_values.pl">Valeurs autorisées</a></li>
</ul>

<h5>Adhérents et circulation</h5>
<ul>
 <li><a href="/cgi-bin/koha/admin/categorie.pl">Catégories adhérent</a></li>
 <li><a href="/cgi-bin/koha/admin/cities.pl">Villes et communes</a></li>
 <li><a href="/cgi-bin/koha/admin/roadtype.pl">Types de voie</a></li>
 <li><a href="/cgi-bin/koha/admin/patron-attr-types.pl">Attributs adhérent</a></li>
 <li><a href="/cgi-bin/koha/admin/smart-rules.pl">Règles de circulation</a></li>
 <li><a href="/cgi-bin/koha/admin/branch_transfer_limits.pl">Limites de transfert réseau</a></li>
 <li><a href="/cgi-bin/koha/admin/item_circulation_alerts.pl">Alertes de circulation</a></li>
</ul>

<h5>Catalogue</h5>
<ul>
 <li><a href="/cgi-bin/koha/admin/biblio_framework.pl">Grilles de catalogage MARC</a></li>
 <li><a href="/cgi-bin/koha/admin/koha2marclinks.pl">Liens Koha => MARC</a></li>
 <li><a href="/cgi-bin/koha/admin/fieldmapping.pl">Liens Mots-clés => MARC</a></li>
 <li><a href="/cgi-bin/koha/admin/checkmarc.pl">Validation grilles de catalogage</a></li>
 <li><a href="/cgi-bin/koha/admin/authtypes.pl">Grilles d'autorités</a></li>
 <li><a href="/cgi-bin/koha/admin/classsources.pl">Sources de classification</a></li>
 <li><a href="/cgi-bin/koha/admin/matching-rules.pl">Règles de concordance</a></li>
</ul>

<h5>Paramètres acquisitions</h5>

<ul>
 <li><a href="/cgi-bin/koha/admin/currency.pl">Devises et taux de change</a></li>
 <li><a href="/cgi-bin/koha/admin/aqbudgetperiods.pl">Budgets</a></li>
 <li><a href="/cgi-bin/koha/admin/aqbudgets.pl">Postes budgétaires</a></li>

</ul>

<h5>Paramètres divers</h5>

<ul>
 [% IF ( NoZebra ) %]<li><a href="/cgi-bin/koha/admin/stopwords.pl">Mots vides</a></li>[% END %]
 <!-- <li><a href="/cgi-bin/koha/admin/printers.pl">Network Printers</a></li> -->
 <li><a href="/cgi-bin/koha/admin/z3950servers.pl">Serveurs Z39.50</a></li>
</ul>
</div>
</div>
