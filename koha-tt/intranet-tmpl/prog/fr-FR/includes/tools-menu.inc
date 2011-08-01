<script type="text/javascript">//<![CDATA[
	$(document).ready(function() {
		var path = location.pathname.substring(1);
		var url = window.location.toString();
		url.match(/\?(.+)$/);
		var params = RegExp.$1;
		if (params) { params = "?" + params; }
		$('#navmenulist a[href$="/' + path + params + '"]').css('font-weight','bold');
	});
//]]>
</script>
<div id="navmenu">
<div id="navmenulist">
<ul>
 <li><a href="/cgi-bin/koha/tools/tools-home.pl">Accueil outils</a></li>
</ul>
<h5>Adhérents et circulation</h5>
<ul>
 [% IF ( CAN_user_tools_moderate_comments ) %]
 <li><a href="/cgi-bin/koha/reviews/reviewswaiting.pl">Commentaires</a></li>
 [% END %]
 [% IF ( CAN_user_tools_import_patrons ) %]
 <li><a href="/cgi-bin/koha/tools/import_borrowers.pl">Importation des données adhérents</a></li>
 [% END %]
 [% IF ( CAN_user_tools_edit_notices ) %]
 <li><a href="/cgi-bin/koha/tools/letter.pl">Messages</a></li>
 [% END %]
 [% IF ( CAN_user_tools_edit_notice_status_triggers ) %]
 <li><a href="/cgi-bin/koha/tools/overduerules.pl">Déclencheur de notification</a></li>
 [% END %]
 [% IF ( CAN_user_tools_label_creator ) %]
 <li><a href="/cgi-bin/koha/patroncards/home.pl">Créateur de cartes adhérent</a></li>
 [% END %]
 [% IF ( CAN_user_tools_delete_anonymize_patrons ) %]
 <li><a href="/cgi-bin/koha/tools/cleanborrowers.pl">Adhérent (anonymiser et supprimer)</a></li>
 [% END %]
 [% IF ( CAN_user_tools_moderate_tags ) %]
 <li><a href="/cgi-bin/koha/tags/review.pl">Modération des tags</a></li>
 [% END %]
 [% IF ( CAN_user_tools_batch_upload_patron_images ) %]
 <li><a href="/cgi-bin/koha/tools/picture-upload.pl">Chargement photos d'adhérents</a></li>
 [% END %]
</ul>
<h5>Catalogue</h5>
<ul>
 [% IF ( CAN_user_tools_items_batchdel ) %]
 <li><a href="/cgi-bin/koha/tools/batchMod.pl?del=1">Suppression d'exemplaires par lot</a></li>
 [% END %]
 [% IF ( CAN_user_tools_items_batchmod ) %]
 <li><a href="/cgi-bin/koha/tools/batchMod.pl">Modification d'exemplaires par lots</a></li>
 [% END %]
 [% IF ( CAN_user_tools_export_catalog ) %]
 <li><a href="/cgi-bin/koha/tools/export.pl">Export notices/exemplaires</a></li>
 [% END %]
 [% IF ( CAN_user_tools_inventory ) %]
 <li><a href="/cgi-bin/koha/tools/inventory.pl">Inventaire/récolement</a></li>
 [% END %]
 [% IF ( CAN_user_tools_label_creator ) %]
 <li><a href="/cgi-bin/koha/labels/label-home.pl">Créateur d'étiquettes</a></li>
 <li><a href="/cgi-bin/koha/labels/spinelabel-home.pl">Création d'étiquettes - rapide</a></li>
 [% END %]
<!--
 [% IF ( CAN_user_tools_rotating_collections ) %]
 <li><a href="/cgi-bin/koha/rotating_collections/rotatingCollections.pl">Rotating collections</a></li>
 [% END %]
-->
 [% IF ( CAN_user_tools_stage_marc_import ) %]
 <li><a href="/cgi-bin/koha/tools/stage-marc-import.pl">Traiter pour import</a></li>
 [% END %]
 [% IF ( CAN_user_tools_manage_staged_marc ) %]
 <li><a href="/cgi-bin/koha/tools/manage-marc-import.pl">Gestion des notices MARC traitées</a></li>
 [% END %]
</ul>
<h5>Outils supplémentaires</h5>
<ul>
 [% IF ( CAN_user_tools_edit_calendar ) %]
 <li><a href="/cgi-bin/koha/tools/holidays.pl">Calendrier</a></li>
 [% END %]
 [% IF ( CAN_user_tools_manage_csv_profiles ) %]
 <li><a href="/cgi-bin/koha/tools/csv-profiles.pl">Profils CSV</a></li>
 [% END %]
 [% IF ( CAN_user_tools_view_system_logs ) %]
 <li><a href="/cgi-bin/koha/tools/viewlog.pl">Visualiseur des logs</a></li>
 [% END %]
 [% IF ( CAN_user_tools_edit_news ) %]
 <li><a href="/cgi-bin/koha/tools/koha-news.pl">Nouvelles</a></li>
 [% END %]
 [% IF ( CAN_user_tools_schedule_tasks ) %]
 <li><a href="/cgi-bin/koha/tools/scheduler.pl">Planificateur de tâches</a></li>
 [% END %]
</ul></div></div>
