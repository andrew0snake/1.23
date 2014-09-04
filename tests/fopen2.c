#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void decode();

void main() {

decode();

}



void decode (){

    int i,c,j,k;
    char str[200],str2[200],str3[300];
    i=' ';
    FILE *tmp1,*tmp2;
        
    
    tmp1=fopen("tmp_decoded","w");
    fclose(tmp1);
    tmp1=fopen("ldap_decoded","w");
    fclose(tmp1);
//    system("echo \"tmp_decoded is:\";cat tmp_decoded;echo \" \";");

    memset(str,0,strlen(str));
    memset(str2,0,strlen(str));
    memset(str3,0,strlen(str));

    tmp1=fopen("ldap_main","r");
    for(i=0;i<3820;++i){
	fgets(str,100,tmp1);
	if( (str[0]=='c') && (str[1]=='n') ){
	    printf("found first part of cn=%s\n",str);
	    fgets(str2,100,tmp1);
	    if( (str2[0]==' ') && (str2[1]!=' ') && (str2[2]!=' ') ){
		printf("found second part of cn=%s;\n",str2);
	    }
	memset(str,0,strlen(str));
	memset(str2,0,strlen(str));
	}
    }
    fclose(tmp1);

/*    printf("getted string=\n%s;\n",str);
    
    i=0;
    j=5;
    while(str[j]!='\n'){
	str2[i]=str[j];
	++j;
	++i;
    }
    printf("getted string2=\n%s;\n",str2);
    
    tmp2=fopen("tmp","w");
    fputs(str2,tmp2);
    fclose(tmp2);
    memset(str,0,strlen(str3) );

    system("cat tmp|base64 -d >> tmp_decoded;cat tmp_decoded;echo " ";");
            
    printf("getting decoded string\n");
    tmp1=fopen("tmp_decoded","r");
    fgets(str,100,tmp1);
    fclose(tmp1);

    printf("decoded string=\n%s;\n",str);

    tmp1=fopen("ldap_decoded","a+");
    fputs(str,tmp1);
    fclose(tmp1);
    
    system("cat ldap_decoded;");
*/
}
