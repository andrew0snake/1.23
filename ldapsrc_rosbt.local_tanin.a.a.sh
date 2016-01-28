#! /bin/tcsh
echo "" >cn_b;
echo "">cns_dirty;
echo "">cns_clean;

#ou=users,dc=main_office,dc=rosbt,dc=com
set ldapurl="ldap://ldap.rosbt.com:389"
set basedn="OU=users,dc=main_office,DC=rosbt,DC=com"
set binddn="uid=username,ou=users,dc=main_office,dc=rosbt,dc=com"
set ldappas="password\!#"

##ldapsrc="ldapsearch -LLL -H $ldapurl -b $basedn -D $binddn -w $ldappas"
##ldapsearch -LLL -H $ldapurl -b $basedn -D $binddn -w $ldappas cn mail
##$ldapsrc | awk -F 'cn::' '{print $2}'> cn_b;

set ldapsrc="ldapsearch -LLL -H $ldapurl -b $basedn -D $binddn -w $ldappas cn mail "
#$ldapsrc >tmp1;
$ldapsrc;
#cat tmp1| awk -F 'cn::' '{print $2}'> cn_b;
#cat tmp1| awk -F 'dn:' '{print $0}'> mail_b;


#$ldapsrc > cn_b;
#cat cn_b|head -n 15;
#cat mail_b|head -n 15


##foreach i ( `$ldapsrc | awk -F 'cn::' '{print $2}'` )
#foreach i ( `cat cn_b` )
#    echo $i|base64 -d>> cns_dirty;
#    echo "" >> cns_dirty;
#end
#cat cns_dirty|grep -v "incomplete"> cns_clean;

#foreach n ( `cat mail_b|| awk -F 'dn: uid' '{print $0}'`)
#    cat mail_b|awk -F 'dn:' ' {print $0}'>>tmp2;
#    cat mail_b|awk -F 'dn:' 'NR=='$n' {print }';
#    echo $n;
#    set t1=echo $n;
#    echo ------------ #>> tmp2;
#end;


#echo ldapurl=$ldapurl;
#echo basedn=$basedn;
#echo binddn=$binddn;
#echo ldapsrc=$ldapsrc;
