<script type="text/javascript">
    //<![CDATA[
    // prepare DOM for YUI Toolbar
    $(document).ready(function() {
        $("#layoutsc").empty();
        $("#templatesc").empty();
        $("#profilesc").empty();
        $("#batches").empty();
        yuiToolbar();
     });

    // YUI Toolbar Functions
    function yuiToolbar() {
        var layouts = [
                {text: _("Gérer les formats"), url: "/cgi-bin/koha/labels/label-manage.pl?label_element=layout" },
                {text: _("Ajouter format"), url: "/cgi-bin/koha/labels/label-edit-layout.pl?op=new" }
        ];

        var templates = [
                {text: _("Gérer les modèles"), url: "/cgi-bin/koha/labels/label-manage.pl?label_element=template" },
                {text: _("Nouveau modèle"), url: "/cgi-bin/koha/labels/label-edit-template.pl?op=new" }
        ];

        var profiles = [
                {text: _("Gérer les profils"), url: "/cgi-bin/koha/labels/label-manage.pl?label_element=profile" },
                {text: _("Nouveau Profil"), url: "/cgi-bin/koha/labels/label-edit-profile.pl?op=new" }
        ];

        var batches = [
                {text: _("Gérer les lots de traitement"), url: "/cgi-bin/koha/labels/label-manage.pl?label_element=batch" },
                {text: _("Ajouter un lot de traitement"), url: "/cgi-bin/koha/labels/label-edit-batch.pl?op=new" }
        ];

        new YAHOO.widget.Button({
            type: "menu",
            label: _("Format"),
            name: "layouts",
            menu: layouts,
            container: "layoutsc"
        });

        new YAHOO.widget.Button({
            type: "menu",
            label: _("Modèles"),
            name: "templates",
            menu: templates,
            container: "templatesc"
        });

        new YAHOO.widget.Button({
            type: "menu",
            label: _("Profils"),
            name: "profiles",
            menu: profiles,
            container: "profilesc"
        });

        new YAHOO.widget.Button({
            type: "menu",
            label: _("Lots"),
            name: "batches",
            menu: batches,
            container: "batchesc"
        });
    }
//]]>
</script>
<div id="toolbar">
 <ul class="toolbar">
 <li id="layoutsc"><a id="layouts" href="#">Format</a></li>
 <li id="templatesc"><a id="templates" href="#">Modèles</a></li>
 <li id="profilesc"><a id="profiles" href="#">Profils</a></li>
 <li id="batchesc"><a id="batches" href="#">Lots</a></li>
 </ul>
</div>
