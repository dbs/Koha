  348  cd head
  349  cd etc/
  350  grep -ir '6=3' ./*
  351  cd zebradb/
  352  ls
  353  cd ..
  354  ls
  355  findd default*
  356  vi ./zebradb/etc/default.idx
  357  cd zebradb/
  358  vi ccl.properties 
  359  gs
  360  gd
  361  gl
  362  git reset --hard 18b1d5c30ffe3c01413e50a97ac9d90149621550
  363  gl
  364  gs
  365  git clean -fr
  366  git clean -nf
  367  git clean -ff
  368  git clean -fd
  369  grep -ir '6=3' ./*
  370  gl ./ccl.properties
  371  grep -ir '6=3' ./*
  372  grep -ir '6=2' ./*
  373  grep -ir '6=3' ./*
  374  vi ./ccl.properties
  375  grep -ir '6=3' ./*
  376  grep -ir '6=2' ./*
  377  ls
  378  grep -ir 6=3 ./*
  379  gs
  380  grep -ir 'title ./*
  381  grep -ir 'title' ./*
  382  grep -ir 'title' ./*|grep -i ext
  383  ls
  384  grep -ir 'ext' ./*
  385  grep -ir '6=3' ./*|grep -i ext
  386  grep -ir '6=3' ./*
  387  cd
  388  cd g
  389  cd clients
  390  cd kapiti
  391  cd  fix-issns
  392  ll
  393  gd  ./fix-issns2.pl 
  394  perl -d  ./fix-issns2.pl 
  395  cd 2011-02-03/
  396  perl -d  ./fix-issns2.pl 
  397  perl   ./fix-issns2.pl 
  398  perl -d  ./fix-issns2.pl 
  399  perl   ./fix-issns2.pl 
  400  time perl   ./fix-issns2.pl 
  401  time perl -d  ./fix-issns2.pl 
  402  time perl   ./fix-issns2.pl 
  403  time perl -d  ./fix-issns2.pl 
  404  time perl  ./fix-issns2.pl 
  405  ll
  406  perl -d rpt-issn-matched.pl 
  407  perl rpt-issn-matched.pl 
  408  perl rpt-issn-matched.pl | sort
  409  perl rpt-issn-matched.pl | sort|uniq
  410  perl rpt-issn-matched.pl | sort|uniq> kk
  411  vi kk
  412  perl rpt-issn-matched.pl | sort|uniq 
  413  perl rpt-issn-matched.pl | sort|uniq > ii
  414  vi ii
  415  mv  ii ii.txt
  416  cd
  417  cat ~/.vimc
  418  cat ~/.vimrc
  419  ex k3
  420  cd g
  421  cd clients
  422  cd kapiti
  423  cd rename-ccodes/
  424  ls
  425  perl d ./rename-MATAHI.pl 
  426  perl -d ./rename-MATAHI.pl 
  427  [B
  428  perl -d ./rename-MATAHI.pl 
  429  q
  430  n
  431  perl -d ./rename-MATAHI.pl 
  432  q
  433  ~/bin/rebuild_zebra.pl -b -z -v 
  434  perl  ./rename-MATAHI.pl 
  435  ~/bin/rebuild_zebra.pl -b -z -v 
  436  perl  ./rename-MATAHI.pl 
  437  ~/bin/rebuild_zebra.pl -b -z -v 
  438  ~/bin/rebuild_zebra.pl -b -r -v 
  439  ~/bin/rebuild_zebra.pl -b -z -v 
  440  cd
  441  c koha
  442  cd
  443  cd koha
  444  cd k3
  445  ls
  446  cd etc
  447  ls
  448  ll
  449  cd ..
  450  ls
  451  rm -rf ./zebradb/
  452  cd etc
  453  ll
  454  ~/bin/rebuild_zebra.pl -b -r -v
  455  export
  456  ex k3
  457  ~/bin/rebuild_zebra.pl -b -r -v
  458  cd /home/mason/koha/kap-k3-3/var/lib/zebradb/biblios
  459  ls
  460  du -m
  461  cd register/
  462  ls
  463  ll
  464  rm ./*
  465  cd ..
  466  ~/bin/rebuild_zebra.pl -b -r -v
  467  ls
  468  ll
  469  cd register/
  470  ll
  471  cd ..
  472  ls
  473  cd ..
  474  du -m
  475  ls
  476  ll
  477  du -m
  478  cd biblios/
  479  cd register/
  480  ll
  481   ~/g/k3/misc/migration_tools/rebuild_zebra.pl -b -r -v
  482  export
  483   ~/g/k3/misc/migration_tools/rebuild_zebra.pl -b -r -v
  484  ex k3
  485   ~/g/k3/misc/migration_tools/rebuild_zebra.pl -b -r -v
  486  cd
  487   ~/g/k3/misc/migration_tools/rebuild_zebra.pl -b -r -v
  488  ex k3
  489  ll /home/mason/koha/k3/etc/koha-conf.xml
  490   ~/g/k3/misc/migration_tools/rebuild_zebra.pl -b -r -v
  491   ~/g/head/misc/migration_tools/rebuild_zebra.pl -b -r -v
  492  cd
  493  cd t
  494  cd s
  495  ls
  496  ls -ltr
  497  mysql kap_k3_3 < kap-bib-full.sql
  498  cp  ~/g/head/misc/migration_tools/rebuild_zebra.pl  ~/bin
  499  rebuild_zebra.pl  -b -v -r
  500  bash
  501  top
  502  cd
  503  mv sss.png ka-text-180.png
  504  sb
  505  export k3
  506  cd g
  507  cd clients
  508  cd kapiti
  509  l
  510  perl -d  fix-magrefs2.pl
  511  ex k3
  512  perl -d  fix-magrefs2.pl
  513  perl -d  fix-magrefs2.pln
  514  perl -d  fix-magrefs2.pl
  515  q
  516  perl -d  fix-magrefs2.pl
  517  perl  fix-magrefs2.pl
  518  perl -d del-old-items-and-bibs.pl
  519  perl  del-old-items-and-bibs.pl
  520    
  521  cd tidyup
  522  perl -d ./rpt-find-canceled-items.pl 
  523  n
  524  perl -d ./rpt-find-canceled-items.pl 
  525  perl  ./rpt-find-canceled-items.pl 
  526  cd ..
  527  perl -d ./fix-mag-245b.pl 
  528  perl  ./fix-mag-245b.pl 
  529  perl  ./fix-mag-245b.pl  > ll
  530  vi ll
  531  perl  ./fix-mag-245b.pl  
  532  perl  ./fix-mag-245b.pl   > ll2
  533  vi ll2
  534  uniq  ll2 > ll3
  535  vi ll3
  536  perl  -d  ./fix-mag-245b.pl  
  537  cd ..
  538  cd k3
  539  ls
  540  findd cre*
  541  findd sync
  542  findd '*sync*'
  543  vi ./misc/maintenance/sync_items_in_marc_bib.pl
  544  perl -d  ./misc/maintenance/sync_items_in_marc_bib.pl 
  545  perl -d  ./misc/maintenance/sync_items_in_marc_bib.pl   --run-update   
  546  cd .
  547  cd
  548  cd g
  549  cd clients
  550  cd kapiti
  551  cd sync-items-script/
  552  ls
  553  perl -d sync_items_in_marc_bib.pl
  554  perl -d sync_items_in_marc_bib.pl  --run-update  
  555  cd ..
  556  perl ./find-bibs-with-no-holdings.pl
  557  perl  -d fix-mag-245b.pl 
  558  perl fix-mag-245b.pl 
  559  q
  560  perl fix-mag-245b.pl 
  561  q
  562  perl  -d fix-mag-245b.pl 
  563  perl  fix-mag-245b.pl 
  564  cd ..
  565  cd head
  566  git fetch
  567  cd ..
  568  cd clients
  569  cd kapiti
  570  ls
  571  cd fix-issns
  572  ls
  573  cd 2011-02-03/
  574  ls
  575  ex k3
  576  perl -d ./rpt-issn-notmatched.pl
  577  perl   ./rpt-issn-notmatched.pl
  578  ls
  579  c
  580  top
  581  cd
  582   cdg
  583  cd clients/
  584  cd kapiti/
  585  cd fix-issns
  586  cd
  587  cd g
  588  cd clients
  589  cd kapiti
  590  cd fix-issns
  591  ls
  592  c
  593  cd 2011-02-03/
  594  ls
  595  cd ..
  596  cd tidyup
  597  ex k3
  598  pelr -d ./rpt-find-missing-mag-items.pl
  599  perl  -d ./rpt-find-missing-mag-items.pl
  600  q
  601  perl  -d ./rpt-find-missing-mag-items.pl
  602  perl  ./rpt-find-missing-mag-items.pl
  603  perl -d  ./rpt-find-missing-mag-items.pl
  604  perl  ./rpt-find-missing-mag-items.pl
  605  cd ..
  606  cd fix-issns
  607  cd 2011-02-03/
  608  ll
  609  ls- ltr
  610  ls -ltr
  611  perl fix-issns2.pl 
  612  vi /tmp/MDyV103oPK/biblio/exported_records
  613  cd
  614  vi /tmp/Bs9EAPMTET
  615  vi /tmp/Bs9EAPMTET/biblio/exported_records 
  616  marclint  /tmp/Bs9EAPMTET/biblio/exported_records 
  617  marcdump  /tmp/Bs9EAPMTET/biblio/exported_records 
  618  marcdump  /tmp/Bs9EAPMTET/biblio/exported_records  > ll
  619  marcdump  /tmp/Bs9EAPMTET/biblio/exported_records  > aa
  620  marcdump  /tmp/Bs9EAPMTET/biblio/exported_records  > cc
  621* vi cc~
  622  grep -i error  cc
  623  man marcdump
  624  marc2xml   /tmp/Bs9EAPMTET/biblio/exported_records  
  625  marc2xml   /tmp/Bs9EAPMTET/biblio/exported_records   > oo
  626  vi 00
  627  vi oo
  628  cd g
  629  ls
  630  cd he
  631* cd headq
  632  ls
  633  gb
  634  gl
  635  gs ce5bf27254f405e622efa3283708b01892c28bdf
  636  git show ce5bf27254f405e622efa3283708b01892c28bdf
  637   
  638  git show ce5bf27254f405e622efa3283708b01892c28bdf
  639  gl
  640  mem
  641  ps -ef|grep mem
  642  apti memcached
  643  sudo apti memcached
  644  sudo apt-get install  memcached
  645  ps -ef|grep mem
  646  t
  647  cd
  648  sb
  649  cd
  650  cd g
  651  cd navitas/
  652  ls
  653  gb
  654  cd
  655  cd g
  656  cd clients
  657  cd kapiti
  658  ls
  659  vi fix-issns.pl
  660  cp fix-issns.pl ~/g/clients/calyx-navitas/
  661  grep -i moditem ./*
  662  vi ./fix-PAE.pl:
  663  vi ./fix-PAE.pl
  664  cd ..
  665  cd calyx-navitas/
  666  ex navitas
  667  perl ./rt90-fix-onloan.pl 
  668  perl -d ./rt90-fix-onloan.pl 
  669  n
  670  perl -d ./rt90-fix-onloan.pl 
  671  top
  672  cd ..
  673  cd navitas/
  674  gb
  675  gl
  676  git remote -v
  677  gb
  678  man git-branch
  679  gb 
  680  gb -M  3.02.05+OpacPublic-mod  3.02.05-mod
  681  gb
  682  gl
  683  cd ..
  684  cd eesi/
  685  gb
  686  cd
  687  ex af
  688  ex afa
  689  cd
  690  perl ~/bin/rebuild_zebra.pl  -r -b -x -v
  691  perl ~/bin/rebuild_zebra.pl  --help
  692  perl ~/bin/rebuild_zebra.pl  -r -b -x -v -k
  693  perl ~/bin/rebuild_zebra.pl  -r -b -x -v -k -d /tmp/wwww
  694  rm -rf /tmp/wwww ; perl ~/bin/rebuild_zebra.pl  -r -b  -v -k -d /tmp/wwww
  695    
  696  sb
  697  export
  698  perl ~/bin/rebuild_zebra.pl  -r -b -x -v -k -d /tmp/wwww1
  699  perl ~/bin/rebuild_zebra.pl  -r -b -x -v  -d /tmp/wwww1
  700  perl ~/bin/rebuild_zebra.pl  -r -b -x -v  -d /tmp/wwww2
  701  perl ~/bin/rebuild_zebra.pl  -r -b -v -k -d /tmp/wwww2
  702  perl ~/bin/rebuild_zebra.pl  -r -b -v -k -d /tmp/wwww3
  703  cd
  704  mysqldump ebc > ~/t/s/ebc-full.sql
  705  sb
  706  cd
  707  cd g
  708  cd ebc
  709  ls
  710  cd misc/
  711  cd translator/
  712  ls
  713  vi translator_doc.txt
  714  ll
  715  vi translate
  716  gl  translate
  717  vi translate
  718  cd
  719  cd g
  720  cd head
  721  ls
  722  gb
  723  git pull
  724  grem
  725  git pull o2 master
  726  gl
  727  c
  728  cd
  729  mysql stable > stable.sql
  730  mysql sdumptable > stable.sql
  731  mysqldump table > stable.sql
  732  mysqldump stable > stable.sql
  733  mysqldump head > head.sql
  734  mysql head <  stable.sql
  735  cd head
  736  git tags
  737  git tag
  738  cd he
  739  cd
  740  cd g
  741  cd he
  742  cd head
  743  git tag
  744  git fetch --tags
  745  git reset --hard bf98eabe50b477e0ed7c71d8b408fd1f710cbd07
  746  cd ..
  747  cd ebc
  748  cd gs
  749  gs
  750  git clean -f
  751  gs
  752  git reset --hard
  753  gs
  754  git clean -fd
  755  gs
  756  ga ./*
  757  gc
  758  gs
  759  ga ./*
  760  gc
  761  gs
  762  gl
  763  git reset --hard
  764  gl
  765  gs
  766  git clean -fd
  767  gs
  768  ga ./*
  769  gc
  770  vi ./.git/hooks/pre-commit 
  771  gc
  772  gs
  773  gs|more
  774  gs
  775  gc
  776  q
  777  vi koha-tmpl/intranet-tmpl/prog/ko-Kore-KP/lib/yui/plugins/bubbling-min.js
  778  gc
  779  gl
  780  gs
  781  gca
  782  gl
  783  q
  784  sb
  785  cd
  786  cd g
  787  cd clients
  788  cd calyx
  789  ls
  790  netstat
  791  netstat -an|grep :53
  792  netstat -an|grep '10.11.12.1:53'
  793  netstat -an|grep ':53'
  794  perl bind-check.pl 
  795  echo $?
  796  perl bind-check.pl 
  797  echo $?
  798  ls
  799  perl check_bind.pl 
  800  echo $?
  801  netstat -an|grep ':53 |grep LISTEN
  802  netstat -an|grep ':53' |grep LISTEN
  803  echo $?
  804  netstat -an|grep ':53' |grep LISTEN
  805  netstat -an|grep ':22' |grep LISTEN
  806  echo $?
  807  cd ..
  808  cd kapiti
  809  perl -d ./pp.pl
  810  perl -d ./aa.pl
  811  eex 3
  812  ex k3
  813  perl -d ./aa.pl
  814  ex head
  815  q
  816  perl -d ./aa.pl
  817  perl  ./aa.pl
  818  q
  819  cd
  820  cd g
  821  cd ebc
  822  gl
  823  vi koha-tmpl/ebsco/.htaccess
  824  gl
  825  cd ..
  826  ls
  827  cd head
  828  ls
  829  gb
  830  vi /etc/perl/XML/SAX/ParserDetails.ini
  831  fg
  832  sudo cpan XML::LibXML::SAX::Parser
  833  cd
  834  bzip2 -d /root/zzz.sql.bz2 
  835  sudo bzip2 -d /root/zzz.sql.bz2 
  836  mv /root/zzz.sql /home/mason
  837  sudo mv /root/zzz.sql /home/mason
  838  cd
  839  mysql kap_k3_3 < zzz.sql 
  840  cd g
  841  cd head
  842  git pull
  843  git pull master
  844  git pull origin
  845  git pull origin master
  846  gs
  847  history > ll
