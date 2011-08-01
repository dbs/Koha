
<h1 id="logo"><a href="/cgi-bin/koha/mainpage.pl">[% LibraryName %]</a></h1><!-- Begin Patrons Resident Search Box -->
[% IF ( CAN_user_circulate ) %][% IF ( CircAutocompl ) %]<script type="text/javascript">
//<![CDATA[
YAHOO.util.Event.onContentReady("header_search", function() {
    new function() {
        // Define a custom formatter function
        this.fnCustomFormatter = function(oResultItem, sQuery) {
            var name        = oResultItem[0];
            var cardnumber  = oResultItem[1];
            var address     = oResultItem[2];
            var city        = oResultItem[3];
            var zip         = oResultItem[4];
            var aMarkup = [
                "<div class=\"sample-result\">",
                name,
                " (",
                cardnumber,
                ")<small> -- ",
                address,
                ", ",
                city,
                "<\/small>",
                "<\/div>"];
            return (aMarkup.join(""));
        };

        // Instantiate one XHR DataSource and define schema as an array:
        //     ["Record Delimiter",
        //     "Field Delimiter"]
        this.oACDS = new YAHOO.widget.DS_XHR("/cgi-bin/koha/circ/ysearch.pl", ["\n", "\t"]);
        this.oACDS.responseType = YAHOO.widget.DS_XHR.TYPE_FLAT;
        this.oACDS.maxCacheEntries = 60;
        this.oACDS.queryMatchSubset = true;

        // Instantiate first AutoComplete
        var myInput = document.getElementById('findborrower');
        var myContainer = document.getElementById('yborrowercontainer');
        this.oAutoComp = new YAHOO.widget.AutoComplete(myInput,myContainer,this.oACDS);
        //this.oAutoComp.delimChar = ";";
        //this.oAutoComp.queryDelay = 1;
        this.oAutoComp.formatResult = this.fnCustomFormatter;
}
});
//]]>
</script>[% END %][% END %]
<div id="header_search">
 <div id="patron_search" class="residentsearch">
 <p class="tip">Entrer le n° de carte d'adhérent ou une partie du nom&nbsp;: </p>
 <form action="/cgi-bin/koha/members/member.pl" method="post">
 <input id="searchmember" size="25" class="focus" name="member" type="text" value="[% member %]"/>
 [% IF ( branchloop ) %]
 <span class="filteraction" id="filteraction_off"> <a href="#" onclick="$('#filters').toggle();$('.filteraction').toggle();">[-]</a></span>
 <span class="filteraction" id="filteraction_on"> <a href="#" onclick="$('#filters').toggle();$('.filteraction').toggle();">[+]</a></span>
 [% END %]
 order by:
 <select name="orderby" id="searchorderby">
 <option value="surnamecomma0">Nom de famille</option>
 <option value="cardnumbercomma0">Numéro de carte</option>
 </select>
 <input value="Rechercher" class="submit" type="submit" />
 [% IF ( branchloop ) %]
 <p id="filters"> <label for="branchcode">Library: </label><select name="branchcode" id="branchcode">
 <option value="">Tous</option>[% FOREACH branchloo IN branchloop %]
 [% IF ( branchloo.selected ) %]
 <option value="[% branchloo.value %]" selected="selected">[% branchloo.branchname %]</option>[% ELSE %]
 <option value="[% branchloo.value %]">[% branchloo.branchname %]</option>[% END %]
 [% END %]</select>
 <label for="categorycode">Category: </label><select name="categorycode" id="categorycode">
 <option value="">Tous</option>[% FOREACH categorie IN categories %]
 [% IF ( categorie.selected ) %]
 <option value="[% categorie.categorycode %]" selected="selected">[% categorie.description %]</option>[% ELSE %]
 <option value="[% categorie.categorycode %]">[% categorie.description %]</option>[% END %]
 [% END %]</select>
 </p>
 [% END %]
</form>
 </div>
 [% IF ( CAN_user_circulate ) %]
 <div id="circ_search" class="residentsearch" style="display:none;">
 <p class="tip">Entrer le n° de carte d'adhérent ou une partie du nom&nbsp;: </p>
 <form action="/cgi-bin/koha/circ/circulation.pl" method="post">
 [% IF ( CircAutocompl ) %]
 <div class="autocomplete">
 <div id="borrowerautocomplete" class="autocomplete">
 <input autocomplete="off" id="findborrower" name="findborrower" type="text" />
 <div id="yborrowercontainer"></div>
 <input value="Valider" id="ysearchsubmit" type="submit" class="submit" />
 <input name="branch" value="[% branch %]" type="hidden" />
 <input name="printer" value="" type="hidden" />
 </div>
 </div>
 [% ELSE %]
 <input id="findborrower" name="findborrower" size="40" type="text" />
 <input name="branch" value="[% branch %]" type="hidden" />
 <input name="printer" value="" type="hidden" />
 <input value="Valider" class="submit" type="submit" />
 [% END %]
 </form>
 </div>[% END %]
 [% IF ( CAN_user_catalogue ) %]
 <div id="catalog_search" class="residentsearch" style="display:none;">
 <p class="tip">Entrer les termes de recherche&nbsp;:</p>
 <form action="/cgi-bin/koha/catalogue/search.pl"  method="get" id="cat-search-block">
 <input value="" name="q" type="text" id="search-form" title="Détermine les serveurs Z3950 que vous voulez que Koha interroge." class="form-text" size="40" />
 <input value="Valider" name="op" type="submit" id="opac-submit" class="submit" />
 </form>
 </div>[% END %]
 <ul>
 <li><a href="/cgi-bin/koha/members/members-home.pl#patron_search">Recherche adhérents</a></li>
 [% IF ( CAN_user_circulate ) %]<li><a href="/cgi-bin/koha/circ/circulation.pl#circ_search">Prêt</a></li>[% END %]
 [% IF ( CAN_user_catalogue ) %]<li><a href="/cgi-bin/koha/catalogue/search.pl#catalog_search">Recherche catalogue</a></li>[% END %]
 </ul>
</div>
<script type="text/javascript">//<![CDATA[
$(document).ready(function() {
    [% IF ( advsearch ) %]$("#filteraction_on").toggle();
    [% ELSE %]$("#filters").toggle();
    $("#filteraction_off").toggle();[% END %]
});
//]]>
</script>
<!-- End Patrons Resident Search Box -->
