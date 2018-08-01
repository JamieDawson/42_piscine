ldapsearch -Q "(uid=jadawson)" | grep "dn" | sed s'/dn: //'
