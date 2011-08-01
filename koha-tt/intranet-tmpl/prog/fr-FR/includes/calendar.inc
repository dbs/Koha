<link rel="stylesheet" type="text/css" href="[% themelang %]/lib/calendar/calendar-system.css"/>
<script type="text/javascript" src="[% themelang %]/lib/calendar/calendar.js"></script>
<script type="text/javascript">
// full day names
Calendar._DN = new Array(_("Dimanche"),_("Lundi"),_("Mardi"),_("Mercredi"),_("Jeudi"),_("Vendredi"),_("Samedi"),_("Dimanche"));
// short day names
Calendar._SDN = new Array(_("Dim"),_("Lun"),_("Jeu"),_("Mer"),_("Mar"),_("Ven"),_("Sam"),_("Dim"));
// First day of the week. "0" means display Sunday first, "1" means display
// Monday first, etc.
Calendar._FD = 1;
// full month names
Calendar._MN = new Array(_("Janvier"),_("Février"),_("Mars"),_("Avril"),_("Mai"),_("Juin"),_("Juillet"),_("Août"),_("Septembre"),_("Octobre"),_("Novembre"),_("Décembre"));
// short month names
Calendar._SMN = new Array(_("Jan"),_("Fév"),_("Mar"),_("Avr"),_("Mai"),_("Juin"),_("Juil"),_("Aoû"),_("Sep"),_("Oct"),_("Nov"),_("Déc"));
// tooltips
Calendar._TT = {};
Calendar._TT["INFO"] = _("A propos du calendrier");

Calendar._TT["ABOUT"] =
_("Dhtml Date/Time Selector")+"\n" +
"(c) dynarch.com 2002-2003\n" + // don't translate this this ;-)
_("For latest version visit: http://dynarch.com/mishoo/calendar.epl")+"\n" +
_("Distributed under GNU LGPL. See http://gnu.org/licenses/lgpl.html for details.") +
"\n\n" +
_("Date sélectionnée&nbsp;:")+"\n" +
_("- Utilisez les boutons \\xab, \\xbb pour sélectionner l'année")+"\n" +
_("- Use the " + String.fromCharCode(0x2039) + ", " + String.fromCharCode(0x203a) + " buttons to select month")+"\n" +
_("- Maintenez enfoncé le bouton de la souris sur tout bouton ci-dessus pour une sélection rapide");
Calendar._TT["ABOUT_TIME"] = "\n\n" +
_("Sélection d'une heure:")+"\n" +
_(" - Cliquez sur toute partie de l'heure pour l'augmenter")+"\n" +
_("- ou Maj-Clic pour la diminuer")+"\n" +
_("- ou clic et déplacement pour une sélection rapide.");

Calendar._TT["PREV_YEAR"] = _("Année précédente");
Calendar._TT["PREV_MONTH"] = _("Mois précédent");
Calendar._TT["GO_TODAY"] = _("Aller à aujourd'hui");
Calendar._TT["NEXT_MONTH"] = _("Mois suivant");
Calendar._TT["NEXT_YEAR"] = _("Année suivante");
Calendar._TT["SEL_DATE"] = _("Sélectionnez une date");
Calendar._TT["DRAG_TO_MOVE"] = _("Faites glisser pour déplacer");
Calendar._TT["PART_TODAY"] = _(" (today)");

// the following is to inform that "%s" is to be the first day of week
// %s will be replaced with the day name.
Calendar._TT["DAY_FIRST"] = _("Afficher %s en premier");

// This may be locale-dependent.  It specifies the week-end days, as an array
// of comma-separated numbers.  The numbers are from 0 to 6: 0 means Sunday, 1
// means Monday, etc.
Calendar._TT["WEEKEND"] = "0comma6";

Calendar._TT["CLOSE"] = _("Fermer");
Calendar._TT["TODAY"] = _("Aujourd'hui");
Calendar._TT["TIME_PART"] = _("(Maj-)Clique ou déplacer pour changer la valeur");

// date formats
Calendar._TT["DEF_DATE_FORMAT"] = "%Y-%m-%d";
Calendar._TT["TT_DATE_FORMAT"] = "%a, %b %e";

Calendar._TT["WK"] = _("sem");
Calendar._TT["TIME"] = _("Heure&nbsp;:");
</script>
<script type="text/javascript" src="[% themelang %]/lib/calendar/calendar-setup.js"></script>
<script type="text/javascript">
//<![CDATA[
var debug    = "[% debug %]";
var dformat  = "[% dateformat %]";
var sentmsg = 0;
if (debug > 1) {alert("dateformat: " + dformat + "\ndebug is on (level " + debug + ")");}

function Date_from_syspref(dstring) {
	var dateX = dstring.split(/[-/]/);
	if (debug > 1 && sentmsg < 1) {sentmsg++; alert("Date_from_syspref(" + dstring + ") splits to:\n" + dateX.join("\n"));}
	if (dformat === "iso") {
		return new Date(dateX[0], (dateX[1] - 1), dateX[2]);  // YYYY-MM-DD to (YYYY,m(0-11),d)
	} else if (dformat === "us") {
		return new Date(dateX[2], (dateX[0] - 1), dateX[1]);  // MM/DD/YYYY to (YYYY,m(0-11),d)
	} else if (dformat === "metric") {
		return new Date(dateX[2], (dateX[1] - 1), dateX[0]);  // DD/MM/YYYY to (YYYY,m(0-11),d)
	} else {
		if (debug > 0) {alert("KOHA ERROR - Unrecognized date format: " +dformat);}
		return 0;
	}
}

function get_Calendar_limit (date,did) {
	// this function could be moved to a static calendar-extras.js file
	var dvalue = document.getElementById(did).value;
	if (dvalue == "") { return false; }
	var limitDate = Date_from_syspref(dvalue);
	if (debug && debug > 5) {
		var month = date.getMonth() + 1;
		var dateString = date.getFullYear() + '-' + month + '-' + date.getDate();
		alert("Comparing incoming (" + dateString + ") vs "
			+ "'" + did + "' limit\n"
			+ "\n thisdate: " + date
			+ "\nlimitdate: " + limitDate
			+ "\nlimit > thisdate : " + (limitDate > date) 
			+ "\nlimit < thisdate : " + (limitDate < date) 
		);
	}
	return limitDate;
}
//]]>
</script>
