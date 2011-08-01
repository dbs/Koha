 [% IF ( intranetbookbag ) %]<div id="cartDetails">Panier vide.</div>[% END %]

 <div id="header" class="clearfix">
 <div id="toplevelnav">
 <ul id="toplevelmenu">
 [% IF ( CAN_user_circulate ) %]<li><a href="/cgi-bin/koha/circ/circulation-home.pl">Circulation</a></li>[% END %]
 [% IF ( CAN_user_borrowers ) %]<li><a href="/cgi-bin/koha/members/members-home.pl">Adhérents</a></li>[% END %]
 [% IF ( CAN_user_catalogue ) %]<li><a href="/cgi-bin/koha/catalogue/search.pl">Rechercher</a></li>[% END %]
 [% IF ( intranetbookbag ) %]
 <li><a href="#" id="cartmenulink">Panier<span id="basketcount"></span></a></li>
 [% END %]
 [% IntranetNav %]
 <li class="more">
 <a id="showmore" href="/cgi-bin/koha/mainpage.pl">Plus</a>
 <div id="moremenu">
 <div class="bd">
 <ul>
 <li><a href="/cgi-bin/koha/virtualshelves/shelves.pl">Listes</a></li>
 [% IF ( CAN_user_editcatalogue_edit_catalogue ) %]
 <li><a href="/cgi-bin/koha/cataloguing/addbooks.pl">Catalogage</a></li>
 [% END %]
 [% IF ( CAN_user_acquisition ) %]
 <li><a href="/cgi-bin/koha/acqui/acqui-home.pl">Acquisitions</a></li>
 [% END %]
 [% IF ( CAN_user_editauthorities ) %]
 <li><a href="/cgi-bin/koha/authorities/authorities-home.pl">Autorités</a></li>
 [% END %]
 [% IF ( CAN_user_serials ) %]
 <li><a href="/cgi-bin/koha/serials/serials-home.pl">Périodiques</a></li>
 [% END %]
 [% IF ( CAN_user_reports ) %]
 <li><a href="/cgi-bin/koha/reports/reports-home.pl">Bilans et statistiques</a></li>
 [% END %]
 [% IF ( CAN_user_tools ) %]
 <li><a href="/cgi-bin/koha/tools/tools-home.pl">Outils</a></li>
 [% END %]
 [% IF ( CAN_user_parameters ) %]
 <li><a href="/cgi-bin/koha/admin/admin-home.pl">Administration</a></li>
 [% END %]
 <li><a href="/cgi-bin/koha/about.pl">A propos de Koha</a></li>
 </ul>
 </div>
 </div>
 </li>
 </ul>
 </div>
 <div id="login">
 [% IF ( AutoLocation ) %]
 <strong>
 [% LoginBranchname %]
 </strong>
 [% ELSE %]
 <strong>[% LoginBranchname %]</strong>
 [% IF ( IndependantBranches ) %]
 [% IF ( CAN_user_management ) %]
 (<a href="/cgi-bin/koha/circ/selectbranchprinter.pl">Set</a>)
 [% END %]
 [% ELSE %]
 (<a href="/cgi-bin/koha/circ/selectbranchprinter.pl">Set</a>)
 [% END %]
 |
 [% END %]
 [% IF ( loggedinusername ) %]
 <span class="loggedinusername">
 [% loggedinusername %]
 </span>
 (<a href="/cgi-bin/koha/mainpage.pl?logout.x=1"[% IF ( intranetbookbag ) %] onclick="delBasket(true);"[% END %]>Log Out</a>) |
 [% ELSE %]
 You are not logged in |
 [% END %]
 <a href="/cgi-bin/koha/help.pl" id="helper" onclick="window.open('/cgi-bin/koha/help.pl?url='+escape(document.url),'Koha_Help','width=600,height=600,toolbar=false,scrollbars=yes'); return false;">[ ? ]</a>
 </div>
</div> 
