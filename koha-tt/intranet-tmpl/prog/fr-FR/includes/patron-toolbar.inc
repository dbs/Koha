[% UNLESS ( no_add ) %]
<div id="toolbar">
 <script type="text/javascript">
	//<![CDATA[

	// prepare DOM for YUI Toolbar

	 $(document).ready(function() {
[% IF ( AddPatronLists_categorycode ) %]
[% ELSE %]
	 	$("#addchild").parent().remove();
		$("#addprofessional").parent().remove();
		$("#addorganisation").parent().remove();
		$("#addstaff").parent().remove();
		$("#addstatistical").parent().remove();
[% END %]
	    $("#newmenuc").empty();
	    yuiToolbar();
	 });

	// YUI Toolbar Functions

	function yuiToolbar() {

		var newmenu = [
[% IF ( AddPatronLists_categorycode ) %]
[% FOREACH categorie IN categories %]
{ text: "[% categorie.description %]",  url: "/cgi-bin/koha/members/memberentry.pl?op=add&amp;categorycode=[% categorie.categorycode %]" },
[% END %]
[% ELSE %]
			{ text: _("Adhérent adulte"),  url: "/cgi-bin/koha/members/memberentry.pl?op=add&amp;category_type=A" },
			{ text: _("Adhérent enfant"),  url: "/cgi-bin/koha/members/memberentry.pl?op=add&amp;category_type=C" },
			{ text: _("Adhérent professionnel"),  url: "/cgi-bin/koha/members/memberentry.pl?op=add&amp;category_type=P" },
			{ text: _("Collectivité"),  url: "/cgi-bin/koha/members/memberentry.pl?op=add&amp;category_type=I" },
			{ text: _("Bibliothécaire"),  url: "/cgi-bin/koha/members/memberentry.pl?op=add&amp;category_type=S" },
			{ text: _("Statistiques"),  url: "/cgi-bin/koha/members/memberentry.pl?op=add&amp;category_type=X" },
[% END %]
		]

	    new YAHOO.widget.Button({
	        type: "menu",
	        label: _("Ajouter"),
	        name: "newmenubutton",
	        menu: newmenu,
	        container: "newmenuc"
	    });

	}

	//]]>
	</script>
 <ul class="toolbar">
 <li id="newmenuc">
 <form action="/cgi-bin/koha/members/memberentry.pl" method="get">
 <input type="hidden" name="op" value="add" />
 <label for="newcategorycode">New Patron: </label><select name="categorycode" id="newcategorycode">
 [% IF ( AddPatronLists_categorycode ) %]
 [% FOREACH categorie IN categories %]<option value="[% categorie.categorycode %]">[% categorie.description %]</option>[% END %]
 [% ELSE %]
 <option value="A">Adhérent adulte</option>
 <option value="C">Adhérent enfant</option>
 <option value="P">Adhérent professionnel</option>
 <option value="I">Collectivité</option>
 <option value="S">Bibliothécaire</option>
 <option value="X">Statistiques</option>
 [% END %]
 </select>
 <input value="Valider" type="submit" class="submit" />
 </form>
 </li>
</ul>
</div>
[% END %]