[% IF ( borrowernumber ) %]
<div class="patroninfo"><h5>[% borrowerfirstname %] [% borrowersurname %]</h5>
<ul>
 <li>[% IF ( borrowerstreetaddress ) %]
 [% borrowerstreetaddress %],
 [% ELSE %]
 <span class="problem">Pas d'adresse enregistrée pour cet adhérent.</span>
 [% END %]</li>
 <li> [% IF ( borrowercity ) %]
 [% borrowercity %]
 [% ELSE %]
 No city stored.
 [% END %]</li>
 <li> [% IF ( borrowerphone ) %]
 [% borrowerphone %]
 [% ELSE %]
 <span class="problem">Pas de téléphone enregistré.</span> 
 [% END %]</li>
 <li>[% borrowerphonepro %]</li>
 <li>[% borrowermobile %]</li>
 [% IF ( borroweremail ) %]
 <li> <a href="mailto:[% email %]">[% borroweremail %]</a></li>
 [% END %]
 [% IF ( borroweremailpro ) %]
 <li> <a href="mailto:[% emailpro %]">[% borroweremailpro %]</a></li>
 [% END %]
 <li>Catégorie&nbsp;: [% borrowercategorycode %]</li>
</ul></div>
<div class="patronviews">
<ul><li><a href="/cgi-bin/koha/members/moremember.pl?borrowernumber=[% borrowernumber %]">Détails</a></li>
 <li><a href="/cgi-bin/koha/members/boraccount.pl?borrowernumber=[% borrowernumber %]">Amendes</a></li>
 [% IF ( intranetreadinghistory ) %]<li><a href="/cgi-bin/koha/members/readingrec.pl?borrowernumber=[% borrowernumber %]">Liste des lectures</a></li>[% END %]
 [% IF ( CAN_user_parameters ) %]<li><a href="/cgi-bin/koha/tools/viewlog.pl?do_it=1&amp;modules=MEMBERS&amp;action=MODIFY&amp;object=[% borrowernumber %]">Log des modifications</a></li>[% END %]</ul>
</div>
[% END %]
