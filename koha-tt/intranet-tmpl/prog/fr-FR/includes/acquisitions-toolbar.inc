<div id="toolbar"><script type="text/javascript">
    //<![CDATA[

    // prepare DOM for YUI Toolbar

    $(document).ready(function() {
        yuiToolbar();
    });

    // YUI Toolbar Functions

    function yuiToolbar() {   
    
        new YAHOO.widget.Button("newperiod");
        new YAHOO.widget.Button("newbudget");
        new YAHOO.widget.Button("newsupplier");
        new YAHOO.widget.Button("newbasket");
        new YAHOO.widget.Button("editsupplier");
        new YAHOO.widget.Button("receive");
        new YAHOO.widget.Button("newcontract");
        new YAHOO.widget.Button("editcontracts");

        var manageorders = [
            [% IF ( CAN_user_acquisition_order_manage ) %]
                { text: _("Ajouter panier"), url: "/cgi-bin/koha/acqui/basketheader.pl?booksellerid=[% id %]&op=add_form"},
                { text: _("Paniers de commande"), url: "/cgi-bin/koha/acqui/booksellers.pl?supplierid=[% id %]"},
                { text: _("Bordereaux de commande"), url: "/cgi-bin/koha/acqui/basketgroup.pl?booksellerid=[% id %]"},
            [% END %]
            { text: _("Réceptionner colis"), url: "/cgi-bin/koha/acqui/parcels.pl?supplierid=[% id %]" },
            [% IF ( basketno ) %]
                { text: _("Prix incertains"), url: "/cgi-bin/koha/acqui/uncertainprice.pl?booksellerid=[% id %]&basketno=[% basketno %]&owner=1"}
            [% ELSE %]
                { text: _("Prix incertains"), url: "/cgi-bin/koha/acqui/uncertainprice.pl?booksellerid=[% id %]&owner=1"}
            [% END %]
        ]
        [% IF ( id ) %]
            [% IF ( basketcount ) %]
                new YAHOO.widget.Button({type: "menu", label: _("Gestion des commandes"), name: "manageorders", menu: manageorders, container: "toolbar-list"});
            [% END %]
        [% END %]
    }

    //]]>
    </script>
 <ul id="toolbar-list" class="toolbar">
 [% IF ( id ) %]
 [% IF ( CAN_user_acquisition_vendors_manage ) %]
 <li><a id="editsupplier" href="/cgi-bin/koha/acqui/supplier.pl?supplierid=[% id %]&amp;op=enter">Modifier</a></li>
 <li><a id="newcontract" href="/cgi-bin/koha/admin/aqcontract.pl?op=add_form&booksellerid=[% id %]">Nouveau contrat</a></li>
 <li><a id="editcontracts" href="/cgi-bin/koha/admin/aqcontract.pl?booksellerid=[% id %]">Contrats</a></li>
 [% UNLESS ( basketcount ) %]
 <li><a id="newbasket" href="/cgi-bin/koha/acqui/basketheader.pl?booksellerid=[% id %]&op=add_form">Ajouter Panier</a></li>
 [% END %]
 [% END %]
 [% ELSE %]
 <li><a id="newbudget" href="/cgi-bin/koha/acqui/supplier.pl?op=enter">Ajouter fournisseur</a></li>
 [% END %]
 </ul>
</div>
