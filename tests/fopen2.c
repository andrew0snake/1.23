#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void decode();
char decode_string(char str[100]);

void main() {

decode_file();

}



void decode_file (){

    int i,c,j,k,l;
    char str[100],str2[100],str3[100];
    i=' ';
    FILE *tmp1,*tmp2;
        
    
    tmp1=fopen("tmp_decoded","w");
    fclose(tmp1);
    tmp1=fopen("ldap_decoded","w");
    fclose(tmp1);
    system("touch ldap_decoded;");

    memset(str,0,strlen(str) );
    memset(str2,0,strlen(str2) );
    memset(str3,0,strlen(str3) );

    tmp1=fopen("ldap_main","r");
    for(i=0;i<3822;++i){
	fgets(str,100,tmp1);
	if( (str[0]=='c') && (str[1]=='n') ){
	    printf("found first part of cn=%s\n",str);
	    fgets(str2,100,tmp1);
	    if( (str2[0]==' ') && (str2[1]!=' ') && (str2[2]!=' ') ){
		printf("found second part of cn=%s;\n",str2);
		l=strlen(str);
		memset(str3,0,strlen(str));
		j=0;
		k=5;
		while(str[k]!='\n'){
		    str3[j]=str[k];
		    ++j;
		    ++k;
		}
		memset(str,0,strlen(str) );
		strcat(str,str3);
		memset(str3,0,strlen(str3) );

		printf("after moving str seems so:\n%s\n",str);

		j=0;
		while(str2[j]!='\n'){
		    str3[j]=str2[j+1];
		    ++j;
		}

		memset(str2,0,strlen(str2) );
		strcat(str2,str3);
		memset(str3,0,strlen(str3) );

		strcat(str,str2);
		printf("concatenated string equal:\n%s\n",str);

		tmp2=fopen("tmp","w");
		fputs(str,tmp2);
		fclose(tmp2);
		system("cat tmp|base64 -d>tmp_decoded;echo " ">>tmp_decoded;cat tmp_decoded");
    
		tmp2=fopen("tmp_decoded","r");
		memset(str,0,strlen(str) );
		fgets(str,100,tmp2);
		fclose(tmp2);

		printf("decoded string equal:%s\n",str);

		tmp2=fopen("ldap_decoded","a+");
		fputs(str,tmp2);
		fclose(tmp2);
		memset(str,0,strlen(str) );
	    }
	    //end of check fo second part of string cn::
	    else {
		if( (str[0]=='c') && (str[1]=='n') ){
		    l=strlen(str);
		    memset(str3,0,strlen(str3) );
		    j=0;
		    k=5;
		    while(str[k]!='\n'){
			str3[j]=str[k];
			++j;
			++k;
		    }
		    memset(str,0,strlen(str) );
		    strcat(str,str3);
		    memset(str3,0,strlen(str3) );
		    printf("second check. getted string=\n%s\n",str)

		    tmp2=fopen("tmp","w");
		    fputs(str2,tmp2);
		    fclose(tmp2);
		    system("cat tmp|base64 -d>tmp_decoded;echo " ">>tmp_decoded;cat tmp_decoded;echo 123;");
    
		    tmp2=fopen("tmp_decoded","r");
		    memset(str,0,strlen(str) );
		    fgets(str,100,tmp2);
		    fclose(tmp2);

		    tmp2=fopen("ldap_decoded","a+");
		    fputs(str,tmp2);
		    fclose(tmp2);
		    memset(str,0,strlen(str) );
		}
		else {
		    printf("string eq:%s\n",str);
		    tmp2=fopen("ldap_decoded","a+");
		    fputs(str2,tmp2);
		    fclose(tmp2);
		    memset(str2,0,strlen(str2) );
		}
	    }
	    //end of other variant if string consist of one part
	}
	//end of check for string starts from cn
    }
    fclose(tmp1);

}

char decode_string(char str[100]){
    int i;
    FILE *tmp;

    tmp=fopen("tmp","w");
    fputs(str,tmp);
    system("cat tmp|base64 -d>tmp_decoded");
    fclose(tmp);

    memset(str,0,strlen(str) );

    tmp=fopen("tmp_decoded","r");
    fgets(str,100,tmp);
    fclose(tmp);

    return str;
}