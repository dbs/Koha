<form name="f" method="get" action="auth_finder.pl">
 <input type="hidden" name="op" value="do_search" />
 <input type="hidden" name="type" value="intranet" />
 <input type="hidden" name="index" value="[% index %]" />
 <fieldset class="rows"><ol><li>
 <span class="label">Type d'autorité</span>
 [% authtypecode %]
 <input type="hidden" name="authtypecode" value="[% authtypecode %]" />
 </li>
 <li>
 <label for="mainmainentry">Vedette principale (seulement $a)</label>
 <input type="hidden" name="marclist" value="mainmainentry" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="mainmainentry">
 <option value="contains">contient</option>
 <option value="start">Commence par</option>
 <option value="is">est exactement</option>
 </select>
 <input type="text" name="value_mainstr" value="[% value_mainstr |html %]" />
 </li>
 <li>
 <label for="mainentry">Vedette principale</label>
 <input type="hidden" name="marclist" value="mainentry" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="mainentry">
 <option value="contains">contient</option>
 <option value="start">Commence par</option>
 <option value="is">est exactement</option>
 </select>
 <input type="text" name="value_main" value="[% value_main |html %]" />
 </li>
 <li>
 <label for="marclist">Partout</label>
 <input type="hidden" name="marclist" value="" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="marclist">
 <option value="contains">contient</option>
 <option value="start">Commence par</option>
 <option value="is">est exactement</option>
 </select>
 <input type="text" name="value_any" value="[% value_any |html %]" />
 </li>
 <li>
 <label for="orderby">Sort by </label>
 <select name="orderby" id="orderby">
 <option value="">Pas de commande</option>
 <option value="HeadingAsc" selected="selected">Vedette croissant</option>
 <option value="HeadingDsc">Vedette décroissant</option>
 </select>
 </li></ol></fieldset>
 <fieldset class="action"> <input value="Rechercher" type="submit" class="submit" /> <a class="cancel close" href="#">Annuler</a></fieldset>
</form>
