<div id="toolbar">
 
 <script type="text/javascript">
	//<![CDATA[
	[% IF ( CAN_user_editcatalogue_edit_catalogue ) %]
	/* this function open a popup to search on z3950 server.  */
	function PopupZ3950() {
		var strQuery = GetZ3950Terms();
		if(strQuery){
			window.open("/cgi-bin/koha/cataloguing/z3950_search.pl?biblionumber=[% biblionumber %]"+strQuery,"z3950search",'width=740,height=450,location=yes,toolbar=no,scrollbars=yes,resize=yes');
		} 
	}

	/* provide Z3950 search points */
	function GetZ3950Terms(){
		var strQuery="&frameworkcode=";
		[% FOREACH z3950_search_param IN z3950_search_params %]
			strQuery += "&" + "[% z3950_search_param.name |html %]" + "=" + "[% z3950_search_param.encvalue |html %]";
		[% END %]
		return strQuery;
	}
	[% END %]
	function addToCart() { addRecord('[% biblionumber %]'); }
	function addToShelf() {	window.open('/cgi-bin/koha/virtualshelves/addbybiblionumber.pl?biblionumber=[% biblionumber %]','Add_to_virtualshelf','width=500,height=400,toolbar=false,scrollbars=yes');
	}
	function printBiblio() {window.open('/cgi-bin/koha/catalogue/detailprint.pl?biblionumber=[% biblionumber %]','Print_Biblio','width=700,height=500,toolbar=false,scrollbars=yes');
	}
[% IF ( CAN_user_editcatalogue_edit_catalogue ) %]
function confirm_deletion() {
		var count = [% count %];
        var is_confirmed;
	if (count>0){
		    is_confirmed= alert(_('There are [ '+ count +' ] item(s) attached to this record \n You must delete all items before deleting this record.'));
		    } else{
		    is_confirmed= confirm(_('Êtes vous sûr de vouloir supprimer cette notice ?'));
	}

     if (is_confirmed) {
        if (count>0){
	// 	window.location="/cgi-bin/koha/catalogue/detail.pl?biblionumber=[% biblionumber %]";
		} else {
			window.location="/cgi-bin/koha/cataloguing/addbiblio.pl?op=delete&amp;biblionumber=[% biblionumber %]";
		}
	} else {
		return false;
	}
}
[% END %]
[% IF ( CAN_user_editcatalogue_edit_items ) %]
function confirm_items_deletion() {
        var count = [% count %];
        if(count > 0){
            if(confirm(_('Are you sure you want to delete the ' + count + ' attached items? '))){
                window.location="/cgi-bin/koha/cataloguing/additem.pl?op=delallitems&amp;biblionumber=[% biblionumber %]";
            }else{
                return false;
            }
		}
}
[% END %]
	// prepare DOM for YUI Toolbar

	 $(document).ready(function() {
	    [% IF ( CAN_user_editcatalogue_edit_items ) %]$("#edititems").parent().remove();
		$("#newitem").parent().remove();[% END %]
	    [% IF ( CAN_user_editcatalogue_edit_catalogue ) %]$("#duplicatebiblio").parent().remove();
		$("#deletebiblio").parent().remove();
		$("#z3950searchc").empty();[% END %]
		[% IF ( CAN_user_serials_create_subscription ) %]$("#newsub").parent().remove();[% END %]
	    $("#newbiblio").parent().remove();
		$("#editbiblio").parent().remove();
		$("#addtoshelf").parent().remove();
		$("#printbiblio").parent().remove();
		$("#placehold").parent().remove();
		$("#export").remove();
	 });

	YAHOO.util.Event.onContentReady("cattoolbar", function () {
		//	Menu for new record, new item, new subscription
		var newmenu = [
			[% IF ( CAN_user_editcatalogue_edit_catalogue ) %]{text: _("Ajouter notice"), url: "/cgi-bin/koha/cataloguing/addbiblio.pl" },[% END %]
			[% IF ( CAN_user_editcatalogue_edit_items ) %]{text: _("Nouvel exemplaire"), url: "/cgi-bin/koha/cataloguing/additem.pl?biblionumber=[% biblionumber %]#additema" },[% END %]
			[% IF ( CAN_user_serials_create_subscription ) %]
			{text: _("Ajouter abonnement"), url: "/cgi-bin/koha/serials/subscription-add.pl?biblionumber_for_new_subscription=[% biblionumber %]"},[% END %]
		];
		if(newmenu.length){
			new YAHOO.widget.Button({
				type: "menu",
				label: _("Ajouter"),
				id: "newmenuc",
				name: "newmenubutton",
				menu: newmenu,
				container: this
			 });
		 }
	    var editmenu = [
	        [% IF ( CAN_user_editcatalogue_edit_catalogue ) %]{ text: _("Modifier la notice"), url: "/cgi-bin/koha/cataloguing/addbiblio.pl?biblionumber=[% biblionumber %]&amp;frameworkcode=&amp;op=" },[% END %]
	        [% IF ( CAN_user_editcatalogue_edit_items ) %]{ text: _("Modifier les exemplaires"), url: "/cgi-bin/koha/cataloguing/additem.pl?biblionumber=[% biblionumber %]" },[% END %]
	        [% IF ( CAN_user_editcatalogue_edit_items ) %]{ text: _("Attacher des exemplaires"), url: "/cgi-bin/koha/cataloguing/moveitem.pl?biblionumber=[% biblionumber %]" },[% END %]
	        [% IF ( CAN_user_editcatalogue_edit_catalogue ) %]{ text: _("Dupliquer la notice"), url: "/cgi-bin/koha/cataloguing/addbiblio.pl?biblionumber=[% biblionumber %]&amp;frameworkcode=&amp;op=duplicate" },[% END %]
			[% IF ( CAN_user_editcatalogue_edit_catalogue ) %]{ text: _("Supprimer la notice"), onclick: {fn: confirm_deletion }[% IF ( count ) %],id:'disabled'[% END %] },[% END %]
	        [% IF ( CAN_user_editcatalogue_edit_items ) %]{ text: _("Supprimer tous les exemplaires"), onclick: {fn: confirm_items_deletion } }[% END %]
	    ];
		if(editmenu.length){
			new YAHOO.widget.Button({
				type: "menu",
				label: _("Modifier"),
				id: "editmenuc",
				name: "editmenubutton",
				menu: editmenu,
				container: this
			 });
		}
		var savemenu = [
			{ text: _("MODS (XML)"), url: "/cgi-bin/koha/catalogue/export.pl?format=mods&op=export&bib=[% biblionumber %]" },
			{ text: _("Dublin Core (XML)"), url: "/cgi-bin/koha/catalogue/export.pl?format=dc&op=export&bib=[% biblionumber %]" },
			{ text: _("MARCXML"), url: "/cgi-bin/koha/catalogue/export.pl?format=marcxml&op=export&bib=[% biblionumber %]" },
			{ text: _("MARC (non-Unicode/MARC-8)"), url: "/cgi-bin/koha/catalogue/export.pl?format=marc8&op=export&bib=[% biblionumber %]" },
			{ text: _("MARC (Unicode/UTF-8)"), url: "/cgi-bin/koha/catalogue/export.pl?format=utf8&op=export&bib=[% biblionumber %]" }
		];

	    new YAHOO.widget.Button({
	        type: "menu",
	        label: _("Enregistrer"),
	        id: "savemenuc",
	        name: "savemenubutton",
	        menu: savemenu,
	        container: this
	    });

	    var addtomenu = [
			{ text: _("Panier"), onclick: { fn: addToCart } },
			{ text: _("Liste"),  onclick: { fn: addToShelf } }
		];

		new YAHOO.widget.Button({
	        type: "menu",
	        label: _("Ajouter"),
	        name: "addtomenubutton",
	        menu: addtomenu,
	        container: this
	    });

		new YAHOO.widget.Button({
	        id: "printbiblio",
	        type: "button",
	        label: _("Imprimer"),
	        container: this,
			onclick: {fn: printBiblio }
		});
		[% IF ( CAN_user_reserveforothers ) %][% UNLESS ( norequests ) %]
		[% IF ( holdfor ) %]
		//	Create an array of YAHOO.widget.MenuItem configuration properties
		var onButtonClick = function () { 
			location.href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% biblionumber %]";
		}
		var HoldForButtonMenu = [
			{ text: "Place hold", url: "/cgi-bin/koha/reserve/request.pl?biblionumber=[% biblionumber %]" },
			{ text: "Place hold for [% holdfor_firstname %] [% holdfor_surname %] ([% holdfor_cardnumber %])", url: "/cgi-bin/koha/reserve/request.pl?biblionumber=[% biblionumber %]&findborrower=[% holdfor_cardnumber %]" }
		];

		//	Instantiate a Split Button using the array of YAHOO.widget.MenuItem 
		//	configuration properties as the value for the "menu" 
		//	configuration attribute.

		var HoldForButton = new YAHOO.widget.Button({
				id: "holdfor",
				type: "split",
				label: "Place hold",
				name: "holdfor",
				menu: HoldForButtonMenu,
				container: this,
				onclick: { fn: onButtonClick }
		});
	    [% ELSE %]
	    new YAHOO.widget.Button({
			id: "placehold",
			type: "link",
			label: _("Réserver"),
			container: this,
			href: "/cgi-bin/koha/reserve/request.pl?biblionumber=[% biblionumber %]"
	     });
	    [% END %]
	    [% END %][% END %]
	    [% IF ( CAN_user_editcatalogue_edit_catalogue ) %]
		new YAHOO.widget.Button({
			id: "z3950search",
			type: "button", 
			label: _("Recherche Z39.50"),
			container: this,
			onclick: {fn:function(){PopupZ3950()}}
		});
		[% END %]
	});
	//]]>
	</script>
 
<form method="post" name="f" id="f" action="/cgi-bin/koha/cataloguing/addbiblio.pl" onsubmit="return Check();">

<ul class="toolbar" id="cattoolbar">

 [% IF ( CAN_user_editcatalogue_edit_catalogue ) %]
 <li><a id="newbiblio" href="/cgi-bin/koha/cataloguing/addbiblio.pl">Ajouter notice</a></li>
 [% END %]
 [% IF ( CAN_user_editcatalogue_edit_items ) %]
 <li><a id="newitem" href="/cgi-bin/koha/cataloguing/additem.pl?biblionumber=[% biblionumber %]">Nouvel exemplaire</a></li>
 [% END %]
 [% IF ( CAN_user_serials_create_subscription ) %]
 <li><a id="newsub" href="/cgi-bin/koha/serials/subscription-add.pl?biblionumber_for_new_subscription=[% biblionumber %]">Ajouter abonnement</a></li>
 [% END %]

 [% IF ( CAN_user_editcatalogue_edit_catalogue ) %]
 <li><a id="editbiblio" href="/cgi-bin/koha/cataloguing/addbiblio.pl?biblionumber=[% biblionumber %]&amp;frameworkcode=[% current_framework %]&amp;op=">Modifier la notice</a></li>
 [% END %]
 [% IF ( CAN_user_editcatalogue_edit_items ) %]
 <li><a id="edititems" href="/cgi-bin/koha/cataloguing/additem.pl?biblionumber=[% biblionumber %]">Modifier les exemplaires</a></li>
 [% END %]
 [% IF ( CAN_user_editcatalogue_edit_catalogue ) %]
 <li><a id="duplicatebiblio" href="/cgi-bin/koha/cataloguing/addbiblio.pl?biblionumber=[% biblionumber %]&amp;frameworkcode=[% current_framework %]&amp;op=duplicate">Dupliquer notice</a></li>
 [% END %]
 [% IF ( CAN_user_editcatalogue_edit_catalogue ) %]
 <li><a id="deletebiblio" href="/cgi-bin/koha/cataloguing/addbiblio.pl?op=delete&amp;biblionumber=[% biblionumber %]">Supprimer</a></li>
 [% END %] 

 <li><a id="addtoshelf" href="/cgi-bin/koha/virtualshelves/addbybiblionumber.pl?biblionumber=[% biblionumber %]">Ajouter à une liste</a></li>
 <li><a id="printbiblio" href="/cgi-bin/koha/catalogue/detailprint.pl?biblionumber=[% biblionumber %]">Imprimer</a></li>
 [% IF ( CAN_user_reserveforothers ) %]
 [% UNLESS ( norequests ) %]<li><a id="placehold" href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% biblionumber %]">Réserver</a></li>[% END %]
 [% END %]
 [% IF ( CAN_user_editcatalogue_edit_catalogue ) %]<li id="z3950searchc"><input value="Recherche Z39.50" type="button" id="z3950search" onclick="PopupZ3950(); return false;" /></li>[% END %]
 </ul>
</form>
</div>

