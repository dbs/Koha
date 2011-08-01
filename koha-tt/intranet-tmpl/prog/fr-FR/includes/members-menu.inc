[% IF ( borrowernumber ) %]
<div id="menu">
<ul> [% IF ( circview ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/circ/circulation.pl?borrowernumber=[% borrowernumber %]">Prêt</a></li>
 [% IF ( detailview ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/moremember.pl?borrowernumber=[% borrowernumber %]">Détails</a></li>
 [% IF ( CAN_user_updatecharges ) %]
 [% IF ( finesview ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/boraccount.pl?borrowernumber=[% borrowernumber %]">Amendes</a></li>
 [% END %]
 [% IF ( intranetreadinghistory ) %][% IF ( readingrecordview ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/readingrec.pl?borrowernumber=[% borrowernumber %]">Historique de prêts</a></li>[% END %]
 [% IF ( CAN_user_parameters ) %][% IF ( logview ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/tools/viewlog.pl?do_it=1&amp;modules=MEMBERS&amp;action=MODIFY&amp;object=[% borrowernumber %]">Log des modifications</a></li>[% END %]
 [% IF ( EnhancedMessagingPreferences ) %]
 [% IF ( messagingview ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/messaging.pl?borrowernumber=[% borrowernumber %]">Messages</a></li>
 [% END %]
 [% IF ( sentnotices ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/notices.pl?borrowernumber=[% borrowernumber %]">Messages</a></li>
</ul></div>
[% END %]
