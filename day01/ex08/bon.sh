ldapsearch -LLL -Q sn="*bon*" * | grep "^dn:" | wc -l | tr -d ' '
