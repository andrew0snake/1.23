#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void main(){

    int i,j,k,l,concat,prev_str;
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
    concat=prev_str=0;    

    ldap_wel=fopen("ldap_wel","r");
    for(i=0;i<2005;++i){
	memset(str1,0,strlen(str1) );
	fgets(str1,100,ldap_wel);
//        if( (str1[0]=='m') && (str1[1]=='a') && (str1[2]=='i') && (str1[3]=='l') )
//	    printf("123123123");
//	printf("We got string|%s|\n",str1);
	if( (str1[0]=='c') && (str1[1]=='n') && (str1[2]==':') && (str1[3]==':') ){
	    tmp1=fopen("tmp_str","w");
	    fputs(str1,tmp1);
	    fclose(tmp1);
	    
	    prev_str=0;
//	    printf("begin of string=cn;\n");
	    memset(str1,0,strlen(str1) );
	    memset(str2,0,strlen(str2) );
	}
	    
	if( (str1[0]==' ') && (str1[1]!=' ') && (str1[2]!=' ') ){
	    memset(str2,0,strlen(str2) );
	    tmp1=fopen("tmp_str","r");
	    fgets(str2,200,tmp1);
	    fclose(tmp1);
	    
	    l=strlen(str2);
	    str2[l-1]=NULL;
	    strcat(str2,str1);
	    
	    tmp1=fopen("ldap_ws","a+");
	    fputs(str2,tmp1);
	    fclose(tmp1);
//	    printf("Concatenated strings are:%s|str2\n%s|str1\n",str2,str1);	    
	    
	    prev_str=0;
//	    printf("string is second part;\n");
	    memset(str1,0,strlen(str1) );
	    memset(str2,0,strlen(str2) );


	}
	if( (str1[0]=='m') && (str1[1]=='a') && (str1[2]=='i') && (str1[3]=='l') ){
	    if(prev_str==0){
		tmp1=fopen("tmp_str","r");
		fgets(str2,200,tmp1);
		fclose(tmp1);
//		printf("in tmp_str is||%s||\n",str2);
	    
		tmp1=fopen("ldap_ws","a+");
		fputs(str2,tmp1);
		fputs(str1,tmp1);
		fclose(tmp1);
	    }
	    else {
		tmp1=fopen("ldap_ws","a+");
		fputs(str1,tmp1);
		fclose(tmp1);
	    }
	    
//	    printf("str1=%s;\nstr2=%s\n",str1,str2);
	    
	    prev_str=1;
	    tmp1=fopen("tmp_str","w");
	    fclose(tmp1);
	}
	
    }

    fclose(ldap_wel);


}