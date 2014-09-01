#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void main(){

    int i,j,k,l,concat;
    char str1[200],str2[400],str3[200];
    FILE *tmp1,*tmp2,*ldap_main,*ldap_wel,*ldap_ws;

    tmp1=fopen("ldap_wel","w");
    fclose(tmp1);

    tmp1=fopen("ldap_ws","w");
    fclose(tmp1);

    tmp1=fopen("tmp_str","w");
    fclose(tmp1);


    ldap_main=fopen("ldap_main","r");
    for(i=0;i<10000;++i){
	fgets(str1,100,ldap_main);
	if( (str1[0]!=0) && (str1[1]!=0) && (str1[2]!=0) ){
//	    printf("getted on step %d string:%s;",i,str1);
	    ldap_wel=fopen("ldap_wel","a+");
	    fputs(str1,ldap_wel);
	    fclose(ldap_wel);
	}

    }

    fclose(ldap_main);

    for(i=0;i<=200;++i){
	str1[i]=str2[i]=0;
    }
    concat=0;    

    ldap_wel=fopen("ldap_wel","r");
    for(i=0;i<1000;++i){
	memset(str1,0,strlen(str1) );
	fgets(str1,100,ldap_wel);
	if( (str1[0]=='m') && (str1[1]=='a') && (str1[2]=='i') && (str1[3]=='l') ){
//	    if(concat==1){
		tmp1=fopen("tmp_str","r");
		fgets(str2,200,tmp1);
		fclose(tmp1);
		
		tmp1=fopen("ldap_ws","a+");
		fputs(str2,tmp1);
		fputs(str1,tmp1);
		fclose(tmp1);
		concat=0;
		memset(str1,0,strlen(str1) );
		memset(str2,0,strlen(str2) );

//		printf("begin of string=\"main\";concat=1;\nstring str1=%s;string2=%s;",str1,str2);
/*	    }
	    else {
		tmp1=fopen("ldap_ws","a+");
		fputs(str1,tmp1);
		fclose(tmp1);
		printf("begin of string=\"main\";concat=0;\nstring1=%s;",str1);
	    }
*/	}
	    
	if( (str1[0]=='c') && (str1[1]=='n') && (str1[2]==':') && (str1[3]==':') ){
	    tmp1=fopen("tmp_str","w");
	    fputs(str1,tmp1);
	    fclose(tmp1);
	    concat=0;
	    memset(str1,0,strlen(str1) );
//	    printf("begin of string=cn:: ;concat=0;\nstring1=%s;",str1);

	}
	else {
	    memset(str2,0,strlen(str2) );
	    tmp1=fopen("tmp_str","r");
	    fgets(str2,200,tmp1);
	    fclose(tmp1);
	    
	    l=strlen(str2);
	    str2[l-1]=NULL;
	    strcat(str2,str1);
	    
	    tmp1=fopen("tmp_str","w+");
	    fputs(str2,tmp1);
	    fclose(tmp1);
	    printf("Concatenated strings are:%s\n",str2);	    
	    concat=1;
	    memset(str1,0,strlen(str1) );
	    memset(str2,0,strlen(str2) );
	}
	
    }

    fclose(ldap_wel);


}