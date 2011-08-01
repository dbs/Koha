<h5>Construire et exécuter des rapports</h5>
<ul>
 [% IF ( CAN_user_reports_create_reports ) %]<li><a href="/cgi-bin/koha/reports/guided_reports.pl?phase=Build%20new">Construire nouveau</a></li>[% END %]
 [% IF ( CAN_user_reports_execute_reports ) %]<li><a href="/cgi-bin/koha/reports/guided_reports.pl?phase=Use%20saved">Rapports sauvegardés</a></li>[% END %]
 [% IF ( CAN_user_reports_create_reports ) %]<li><a href="/cgi-bin/koha/reports/guided_reports.pl?phase=Create%20report%20from%20SQL">Créer à partir de SQL</a></li>[% END %]
</ul>
<h5>Dictionnaire des rapports</h5>
<ul>
<li><a href="/cgi-bin/koha/reports/dictionary.pl?phase=View%20Dictionary">Voir dictionnaire</a></li>
</ul>
