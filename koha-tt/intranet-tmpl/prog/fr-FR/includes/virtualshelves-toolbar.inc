<div id="toolbar">
 <script type="text/javascript">
	//<![CDATA[

	// prepare DOM for YUI Toolbar

	 $(document).ready(function() {
	 	$("#editlistc").empty();
		$("#deletelistc").remove();
		$("#sendlistc").empty();
		$("#downloadlistc").empty();
		$("#printlistc").empty();
		$("#sendlistc").before("<li id=\"downloadmenuc\"><\/li>");
	    yuiToolbar();
	 });
	 
	[% IF ( viewshelf ) %] function sendList(){
		open(CGIBIN+'virtualshelves/sendshelf.pl?shelfid=[% shelfnumber %]','win_form','dependant=yes,scrollbars=no,resizable=no,height=300,width=450,top=50,left=100');
	 }
	 
	 function downloadList(){
		open(CGIBIN+'virtualshelves/downloadshelf.pl?shelfid=[% shelfnumber %]','win_form','dependant=yes,scrollbars=no,resizable=no,height=300,width=450,top=50,left=100');
	 }[% END %]

	// YUI Toolbar Functions

	function yuiToolbar() {
	   	    newshelfButton = new YAHOO.widget.Button("newshelf");
	   	    [% IF ( viewshelf ) %][% IF ( manageshelf ) %]editshelfButton = new YAHOO.widget.Button("editshelf");
			
	    var editmenu = [
	        { text: _("Modifier la liste"), url: "/cgi-bin/koha/virtualshelves/shelves.pl?shelfnumber=[% shelfnumber %]&amp;op=modif" },
			{ text: _("Supprimer la liste"), onclick: {fn:function(){confirmDelete(_("Êtes vous sûr de vouloir supprimer cette liste ?"))}}}
	    ];
		
		var downloadmenu = [
		{ text: _("iso2709"), url: "/cgi-bin/koha/virtualshelves/downloadshelf.pl?format=iso2709&shelfid=[% shelfnumber %]" },
		{ text: _("RIS"), url: "/cgi-bin/koha/virtualshelves/downloadshelf.pl?format=ris&shelfid=[% shelfnumber %]" },
		{ text: _("BibTex"), url: "/cgi-bin/koha/virtualshelves/downloadshelf.pl?format=bibtex&shelfid=[% shelfnumber %]" },
[% FOREACH csv_profile IN csv_profiles %]
		{ text: _("CSV - [% csv_profile.profile %]"), url: "/cgi-bin/koha/virtualshelves/downloadshelf.pl?format=[% csv_profile.export_format_id %]&shelfid=[% csv_profile.shelfnumber %]" },
[% END %]
		];

	    new YAHOO.widget.Button({
	        type: "menu",
	        label: _("Télécharger"),
	        name: "downloadmenubutton",
	        menu: downloadmenu,
	        container: "downloadmenuc"
	    });

		new YAHOO.widget.Button({
	        type: "menu",
	        label: _("Modifier"),
	        name: "editmenubutton",
	        menu: editmenu,
	        container: "editlistc"
	    });

[% END %]
			downloadlistButton = new YAHOO.widget.Button({
                                            id: "downloadlist", 
                                            type: "button", 
                                            label: _("Télécharger"), 
                                            container: "downloadlistc",
											onclick: {fn:downloadList}
                                        });
			sendlistButton = new YAHOO.widget.Button({
                                            id: "sendlist", 
                                            type: "button", 
                                            label: _("Envoyer la liste"), 
                                            container: "sendlistc",
											onclick: {fn:sendList}
                                        });
			printlistButton = new YAHOO.widget.Button({
                                            id: "printbiblio", 
                                            type: "button", 
                                            label: _("Imprimer la liste"), 
                                            container: "printlistc",
											onclick: {fn:function(){print();}}
                                        });[% END %]
	}

	//]]>
	</script>
 
<ul class="toolbar">
 <li><a id="newshelf" href="/cgi-bin/koha/virtualshelves/shelves.pl?shelves=1">Nouvelle liste</a></li>
 [% IF ( viewshelf ) %][% IF ( manageshelf ) %]
 <li id="editlistc"><a id="editshelf" href="/cgi-bin/koha/virtualshelves/shelves.pl?shelfnumber=[% shelfnumber %]&amp;op=modif">Modifier la liste</a></li>
 <li id="deletelistc">[% IF ( showprivateshelves ) %]<a id="deleteshelf" href="/cgi-bin/koha/virtualshelves/shelves.pl?display=privateshelves&amp;shelves=1&amp;DEL-[% shelfnumber %]=1">Supprimer la liste</a>[% ELSE %]<a id="deleteshelf" href="/cgi-bin/koha/virtualshelves/shelves.pl?shelves=1&amp;DEL-[% shelfnumber %]=1">Supprimer la liste</a>[% END %]</li>
 [% END %]
 <li id="sendlistc"><a href="#" id="sendlist">Envoyer la liste</a></li>
 <li id="printlistc"><a id="printbiblio" href="#">Imprimer la liste</a></li>
 [% END %]
</ul>
</div>
 