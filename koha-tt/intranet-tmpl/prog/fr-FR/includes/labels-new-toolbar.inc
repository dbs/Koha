<script type="text/javascript">
    //<![CDATA[
    // prepare DOM for YUI Toolbar
     $(document).ready(function() {
        yuiToolbar();
     });
    // YUI Toolbar Functions
    function yuiToolbar() {
        new YAHOO.widget.Button("newlabel");
        new YAHOO.widget.Button("newtemplate");
        new YAHOO.widget.Button("newprofile");
        new YAHOO.widget.Button("newbatch");
    }
    //]]>
</script>
<div id="toolbar">
 <ul class="toolbar">
 <li><a id="newlabel" href="/cgi-bin/koha/labels/label-edit-layout.pl?op=new">Ajouter format</a></li>
 <li><a id="newtemplate" href="/cgi-bin/koha/labels/label-edit-template.pl?op=new">Nouveau modèle</a></li>
 <li><a id="newprofile" href="/cgi-bin/koha/labels/label-edit-profile.pl?op=new">Nouveau Profil</a></li>
 <li><a id="newbatch" href="/cgi-bin/koha/labels/label-edit-batch.pl?op=new">Ajouter un lot de traitement</a></li>
 </ul>
</div>
