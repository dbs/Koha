
<h1 id="logo"><a href="/cgi-bin/koha/mainpage.pl">[% LibraryName %]</a></h1><!-- Begin Patrons Admin Resident Search Box -->
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
                "</small>",
                "</div>"];
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
 <div id="contract_description_search" class="residentsearch">
 <p class="tip">Rechercher par nom et/ou description du contrat</p>
 <form action="[% script_name %]" method="post">
 <input type="text" name="searchfield" size="40" value="[% searchfield %]" />
 <input value="Rechercher" name="search" type="submit" class="submit" />
 </form> 
 </div>
 [% IF ( CAN_user_circulate ) %]
 <div id="circ_search" class="residentsearch" style="display:none;">
 <p class="tip">Entrer le n° de carte d'adhérent ou une partie du nom&nbsp;: </p>
 <form action="/cgi-bin/koha/circ/circulation.pl" method="post">
 [% IF ( CircAutocompl ) %]
 <div class="autocomplete">
 <div id="borrowerautocomplete" class="autocomplete">
 <input autocomplete="off" id="findborrower" name="findborrower" class="focus" type="text" />
 <div id="yborrowercontainer"></div>
 <input value="Valider" id="ysearchsubmit" type="submit" class="submit" />
 <input name="branch" value="[% branch %]" type="hidden" />
 <input name="printer" value="" type="hidden" />
 </div>
 </div>
 [% ELSE %]
 <input id="findborrower" name="findborrower" size="40" class="focus" type="text" />
 <input name="branch" value="[% branch %]" type="hidden" />
 <input name="printer" value="" type="hidden" />
 <input value="Valider" class="submit" type="submit" />
 [% END %]
 </form>
 </div> [% END %]
 [% IF ( CAN_user_catalogue ) %]
 <div id="catalog_search" class="residentsearch" style="display:none;">
 <p class="tip">Entrer les termes de recherche&nbsp;:</p>
 <form action="/cgi-bin/koha/catalogue/search.pl"  method="get" id="cat-search-block">
 <input value="" name="q" type="text" id="search-form" title="Détermine les serveurs Z3950 que vous voulez que Koha interroge." class="form-text" size="40" />
 <input value="Valider" type="submit" class="submit" />
 </form>
 </div>[% END %]
 <ul>
 <li><a href="/cgi-bin/koha/admin/aqcontact.pl#contract_description_search">Rechercher des contrats</a></li>
 [% IF ( CAN_user_circulate ) %]<li><a href="/cgi-bin/koha/circ/circulation.pl#circ_search">Prêt</a></li>[% END %]
 [% IF ( CAN_user_catalogue ) %]<li><a href="/cgi-bin/koha/catalogue/search.pl#catalog_search">Recherche catalogue</a></li>[% END %]
 </ul> 
</div>
<!-- End Patrons Admin Resident Search Box -->
