</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="generator" content="Koha [% Version %]" /> <!-- leave this for stats -->
<link rel="shortcut icon" href="[% IF ( OpacFavicon ) %][% OpacFavicon %][% ELSE %][% themelang %]/includes/favicon.ico[% END %]" type="image/x-icon" />[% IF ( opacstylesheet ) %]<link rel="stylesheet" type="text/css" href="[% opacstylesheet %]" />[% ELSE %] [% IF ( opaclayoutstylesheet ) %]<link rel="stylesheet" type="text/css" href="[% themelang %]/css/[% opaclayoutstylesheet %]" />[% ELSE %]<link rel="stylesheet" type="text/css" href="[% themelang %]/css/opac.css" />[% END %][% END %] [% IF ( opaccolorstylesheet ) %] <link rel="stylesheet" type="text/css" href="[% themelang %]/css/[% opaccolorstylesheet %]" />[% END %] [% IF ( opacexternalsheet ) %]<link rel="stylesheet" type="text/css" href="[% opacexternalsheet %]" />[% END %] [% IF ( opac_css_override ) %]<link rel="stylesheet" type="text/css" href="[% themelang %]/css/[% opac_css_override %]" />[% END %] <link rel="stylesheet" type="text/css" media="print" href="[% themelang %]/css/print.css" />
<link rel="stylesheet" type="text/css" href="[% themelang %]/lib/jquery/plugins/ui.tabs.css" />[% IF ( OPACUserCSS ) %]<style type="text/css">[% OPACUserCSS %]</style>[% END %]
<!-- yui js --> 
<script type="text/javascript" src="[% yuipath %]/utilities/utilities.js"></script> 
<script type="text/javascript" src="[% yuipath %]/container/container-min.js"></script> 
<script type="text/javascript" src="[% yuipath %]/menu/menu-min.js"></script> 
<script type="text/javascript" src="[% themelang %]/lib/jquery/jquery.js"></script>
<script type="text/javascript" src="[% themelang %]/lib/jquery/plugins/ui.tabs.js"></script>
<script type="text/javascript" src="[% themelang %]/lib/jquery/plugins/jquery.hoverIntent.minified.js"></script>
<script type="text/javascript" language="javascript" src="[% themelang %]/js/script.js"></script>[% IF ( OPACAmazonCoverImages ) %] <script type="text/javascript" language="javascript">//<![CDATA[
		var NO_AMAZON_IMAGE = _("Pas d'image disponible");
	//]]>
</script>
<script type="text/javascript" language="javascript" src="[% themelang %]/js/amazonimages.js"></script>[% END %] [% IF ( SyndeticsCoverImages ) %]<script type="text/javascript" language="javascript">//<![CDATA[
        var NO_AMAZON_IMAGE = _("Pas d'image disponible");
    //]]>
</script>
<script type="text/javascript" language="javascript" src="[% themelang %]/js/amazonimages.js"></script>[% END %] <script type="text/javascript" language="javascript"
[% IF ( opacbookbag ) %]src="[% themelang %]/js/basket.js">[% ELSIF ( virtualshelves ) %]src="[% themelang %]/js/basket.js">[% ELSE %]>var readCookie;[% END %]</script>
<script type="text/javascript" language="javascript">
	//<![CDATA[
    [% IF ( opacbookbag ) %]var MSG_BASKET_EMPTY = _("Votre panier est actuellement vide");
    var MSG_RECORD_IN_BASKET = _("Ce document est déjà dans mon panier");
    var MSG_RECORD_ADDED = _("Ce document a été ajouté à mon panier");
    var MSG_NRECORDS_ADDED = _(" item(s) added to your cart");
    var MSG_NRECORDS_IN_BASKET = _("Déjà dans mon panier");
    var MSG_NO_RECORD_SELECTED = _("Aucun document sélectionné");
    var MSG_NO_RECORD_ADDED = _("Aucun document ajouté dans votre panier");
    var MSG_CONFIRM_DEL_BASKET = _("Etes-vous sûr de vouloir vider votre panier ?");
    var MSG_CONFIRM_DEL_RECORDS = _("Etes-vous sûr de vouloir enlever les documents sélectionnés ?");
	$("#cartDetails").ready(function(){ $("#cmspan").html("<a href=\"#\" id=\"cartmenulink\" class=\"\"><i><\/i><span><i><\/i><span><\/span><span id=\"carticon\"></span> "+_("Panier")+"<span id=\"basketcount\"><\/span><\/span><\/a>"); }); [% ELSE %][% IF ( virtualshelves ) %]
    var MSG_NO_RECORD_SELECTED = _("Aucun document sélectionné");[% END %][% END %]
    [% IF ( opacuserlogin ) %][% IF ( TagsEnabled ) %]var MSG_TAGS_DISABLED = _("Désolé, les tags ne sont pas disponibles sur ce système.");
    var MSG_TAG_ALL_BAD = _("Error! Your tag was entirely markup code.  It was NOT added.  Please try again with plain text.");
    var MSG_ILLEGAL_PARAMETER = _("Error! Illegal parameter");
    var MSG_TAG_SCRUBBED = _("Note: your tag contained markup code that was removed. The tag was added as ");
    var MSG_ADD_TAG_FAILED = _("Error! The add_tag operation failed on");
    var MSG_ADD_TAG_FAILED_NOTE = _("Note: you can only tag an item with a given term once.  Check 'My Tags' to see your current tags.");
    var MSG_DELETE_TAG_FAILED = _("Error! You cannot delete the tag");
    var MSG_DELETE_TAG_FAILED_NOTE = _("Note&nbsp;: vous ne pouvez supprimer que vos propres tags.")
    var MSG_LOGIN_REQUIRED = _("You must be logged in to add tags.");
    var MSG_TAGS_ADDED = _("Tags added: ");
    var MSG_TAGS_DELETED = _("Tags added: ");
    var MSG_TAGS_ERRORS = _("Errors: ");
    var MSG_MULTI_ADD_TAG_FAILED = _("Unable to add one or more tags.");[% END %][% END %]
	[% IF ( OPACAmazonCoverImages ) %]$(window).load(function() {
		 	verify_images();
		 });[% END %]
	[% IF ( SyndeticsCoverImages ) %]$(window).load(function() {
            verify_images();
         });[% END %]
	[% IF ( opacuserjs ) %][% opacuserjs %][% END %]
	//]]>
</script><script type="text/javascript" language="javascript"
[% IF ( opacbookbag ) %]src="[% themelang %]/js/basket.js">[% ELSIF ( virtualshelves ) %]src="[% themelang %]/js/basket.js">[% ELSE %]>var readCookie;[% END %]</script>[% IF ( opacuserlogin ) %][% IF ( TagsEnabled ) %]<script type="text/javascript" language="javascript" src="[% themelang %]/js/tags.js"></script>[% END %][% ELSE %][% END %] [% IF ( GoogleJackets ) %] <script type="text/javascript" language="javascript" src="[% themelang %]/js/google-jackets.js"></script>
<script type="text/javascript" language="javascript">
	//<![CDATA[
	var NO_GOOGLE_JACKET = _("Pas d'image disponible");
	//]]>
</script>[% END %][% IF ( BakerTaylorEnabled ) %]<script type="text/javascript" language="javascript" src="[% themelang %]/js/bakertaylorimages.js"></script>
<script type="text/javascript" language="javascript">
	//<![CDATA[
	var NO_BAKERTAYLOR_IMAGE = _("Pas d'image disponible");
	$(window).load(function(){
		bt_verify_images();
	});
	//]]>
</script>[% END %] <link rel="unapi-server" type="application/xml" title="unAPI" href="[% OPACBaseurl %]/cgi-bin/koha/unapi" />[% IF ( GoogleIndicTransliteration ) %] <script type="text/javascript" src="http://www.google.com/jsapi"></script>
 <script type="text/javascript" language="javascript" src="[% themelang %]/js/googleindictransliteration.js"></script>[% END %] 