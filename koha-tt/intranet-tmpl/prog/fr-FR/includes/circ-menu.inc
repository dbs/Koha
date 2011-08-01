[% IF ( borrowernumber ) %]
<div class="patroninfo"><h5>[% firstname %] [% surname %] ([% cardnumber %])</h5>
<!--[if IE 6]>
<style type="tex/css">img { width: expression(this.width > 140 ? 140: true);
}</style>
<![endif]-->
<ul>
[% IF ( patronimages ) %]
[% IF ( picture ) %]
<li><img src="/cgi-bin/koha/members/patronimage.pl?crdnum=[% cardnumber %]" id="patronimage" alt="[% firstname %] [% surname %] ([% cardnumber %])" border="0" style="max-width : 140px; margin: .3em 0 .3em .3em; padding: .2em; border: 1px solid #CCCCCC; width:auto !important; width:130px;" /></li>
[% ELSE %]
<li><img src="/intranet-tmpl/prog/img/patron-blank.png" alt="[% firstname %] [% surname %] ([% cardnumber %])" border="0" style="margin: .3em 0 .3em .3em; padding: .2em; border: 1px solid #CCCCCC;" /></li>
[% END %]
[% END %]
 <li>[% IF ( address ) %]
 [% address %]
 [% ELSE %]
 <span class="empty">Pas d'adresse enregistrée.</span>
 [% END %]</li>
 [% IF ( address2 ) %]
 <li>[% address2 %]</li>
 [% END %]<li> 
 [% IF ( city ) %]
 [% city %][% IF ( state ) %], [% state %][% END %]
 [% zipcode %][% IF ( country ) %], [% country %][% END %]
 [% ELSE %]
 <span class="empty">Pas de commune enregistrée.</span>
 [% END %]</li>
 <li>[% IF ( phone ) %]
 [% phone %]
 [% ELSE %]
 [% IF ( mobile ) %]
 [% mobile %]
 [% ELSE %]
 [% IF ( phonepro ) %]
 [% phonepro %]
 [% ELSE %]
 <span class="empty">Pas de téléphone enregistré.</span> 
 [% END %]
 [% END %]
 [% END %]</li>
 [% IF ( email ) %]
 <li class="email"> <a href="mailto:[% email %]" title="[% email %]">[% email %]</a></li>
 [% ELSE %]
 [% IF ( emailpro ) %]
 <li class="email"> <a href="mailto:[% emailpro %]" title="[% emailpro %]">[% emailpro %]</a></li>
 [% ELSE %]
 <li> <span class="empty">Pas de email enregistré</span> </li>
 [% END %]
 [% END %]
 <li>Catégorie&nbsp;: [% categoryname %] ([% categorycode %])</li>
 <li>Home Library: [% IF ( branchname ) %][% branchname %][% ELSE %][% branch %][% END %]</li>
</ul></div>
<div id="menu">
<ul>
 [% IF ( circview ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/circ/circulation.pl?borrowernumber=[% borrowernumber %]">Prêt</a></li>
 [% IF ( CAN_user_borrowers ) %]
 [% IF ( detailview ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/moremember.pl?borrowernumber=[% borrowernumber %]">Détails</a></li>
 [% END %]
 [% IF ( CAN_user_updatecharges ) %]
 [% IF ( finesview ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/boraccount.pl?borrowernumber=[% borrowernumber %]">Amendes</a></li>
 [% END %]
 [% IF ( intranetreadinghistory ) %][% IF ( readingrecordview ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/readingrec.pl?borrowernumber=[% borrowernumber %]">Historique de prêts</a></li>[% END %]
 [% IF ( CAN_user_parameters ) %][% IF ( logview ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/tools/viewlog.pl?do_it=1&amp;modules=MEMBERS&amp;modules=circulation&amp;object=[% borrowernumber %]&amp;src=circ">Log des modifications</a></li>[% END %]
 [% IF ( EnhancedMessagingPreferences ) %]
 [% IF ( messagingview ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/messaging.pl?borrowernumber=[% borrowernumber %]">Messages</a></li>
 [% END %] 
 [% IF ( sentnotices ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/notices.pl?borrowernumber=[% borrowernumber %]">Messages</a></li>
</ul></div>
[% END %]

