#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main (){

    int i,c,j,k;
    char str[200],str2[200],str3[300];
    i=' ';
    FILE *tmp1,*tmp2;
	
    char *name[]={
	"/bin/tcsh",
	"-c",
	"cat tmp|base64 -d>>tmp_decoded;cat tmp_decoded;",
	};
    
    tmp1=fopen("tmp_decoded","w");
    fclose(tmp1);
    tmp1=fopen("ldap_decoded","w");
    fclose(tmp1);
    system("echo \"tmp_decoded is:\";cat tmp_decoded;echo \" \";");

    memset(str,0,strlen(str));

    tmp1=fopen("ldap_wel","r");
    for(i=0;i<200;++i){
	fgets(str,100,tmp1);
	if( (str[0]=='c') && (str[1]=='n') ) {
	    printf("put string in tmp file.\n");
	    j=0;
	    k=4;
	    while(str[k]!='\n'){
		str3[j]=str[k];
		++j;
		++k;
	    }
	    tmp2=fopen("tmp","w");
	    fputs(str3,tmp2);
	    fclose(tmp2);
	    memset(str3,0,strlen(str3) );

	    system("cat tmp|base64 -d >> tmp_decoded;cat tmp_decoded;echo " ";");
	    
	    printf("getting decoded string\n");
	    tmp1=fopen("tmp_decoded","r");
	    fgets(str2,100,tmp1);
	    fclose(tmp1);

	    printf("putting decoded string to ldap_decoded.\n");
	    tmp2=fopen("ldap_decoded","a+");
	    fputs(str2,tmp2);
	    fclose(tmp2);
	    printf("string|%s| is in ldap_decoded.\n",str2);
	    
	    memset(str,0,strlen(str) );
	    memset(str2,0,strlen(str) );

	}
	else{
	    printf("begin of string is not cn.It is |%s|\nand str[0]=%c;str[1]=%c\n",str,str[0],str[1]);
	    tmp2=fopen("ldap_decoded","a+");
	    fputs(str,tmp2);
	    fclose(tmp2);	    
	}	
//	printf("trying step %d\n",i);	
    }
    fclose(tmp1);
}
