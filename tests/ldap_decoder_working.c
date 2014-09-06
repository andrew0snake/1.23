#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void decode();
void decode_string(char str4[100]);

void main() {

decode_file();

}



void decode_file (){

    int i,c,j,k,l;
    char str1[100],str2[100],str3[100];
    i=' ';
    FILE *tmp1,*tmp2;
        
    
    tmp1=fopen("tmp_decoded","w");
    fclose(tmp1);
    tmp1=fopen("ldap_decoded","w");
    fclose(tmp1);
    system("touch ldap_decoded;");

    memset(str1,0,strlen(str1) );
    memset(str2,0,strlen(str2) );
    memset(str3,0,strlen(str3) );

    tmp1=fopen("ldap_main","r");
    for(i=0;i<2912;++i){
	fgets(str1,100,tmp1);
	//printf("str1=%s\n",str1);
	if( (str1[0]=='\n') ){
	//printf("string consist of spaces\n");
	tmp2=fopen("ldap_decoded","a+");
//	memset(str3,32,100);
	fputs(str1,tmp2);
	fclose(tmp2);
	memset(str1,0,strlen(str1) );
	}
	if( (str1[0]=='m') && (str1[1]=='a') && (str1[2]=='i') && (str1[3]=='l') ){
	    //printf("string started from mail;\n");
	    tmp2=fopen("ldap_decoded","a+");
	    fputs(str1,tmp2);
	    fclose(tmp2);
	    memset(str1,0,strlen(str1) );
	}
	if( (str1[0]=='c') && (str1[1]=='n') ){
	    //printf("found first part of cn=%s\n",str1);
	    fgets(str2,100,tmp1);
	    if( (str2[0]==' ') && (str2[1]!=' ') && (str2[2]!=' ') ){
		//printf("found second part of cn=%s;\n",str2);
		l=strlen(str1);
		memset(str3,0,strlen(str3));
		j=0;
		k=5;
		while(str1[k]!='\n'){
		    str3[j]=str1[k];
		    ++j;
		    ++k;
		}
		memset(str1,0,strlen(str1) );
		strcat(str1,str3);
		memset(str3,0,strlen(str3) );

		//printf("after moving str1 seems so:\n%s\n",str1);

		j=0;
		while(str2[j]!='\n'){
		    str3[j]=str2[j+1];
		    ++j;
		}

		memset(str2,0,strlen(str2) );
		strcat(str2,str3);
		memset(str3,0,strlen(str3) );

		strcat(str1,str2);
		//printf("concatenated string equal:\n%s\n",str1);

		decode_string(str1);
		//printf("decoded string equal:%s\n",str1);

		tmp2=fopen("ldap_decoded","a+");
		fputs(str1,tmp2);
		fclose(tmp2);
		memset(str1,0,strlen(str1) );
	    }
	    //end of check fo second part of string cn::
	    else {
		if( (str2[0]=='m') && (str2[1]=='a') && (str2[2]=='i') && (str2[3]=='l') ){
		//printf("string started from mail;\n");
		tmp2=fopen("ldap_decoded","a+");
		fputs(str2,tmp2);
		fclose(tmp2);
		memset(str2,0,strlen(str1) );
		}

		if( (str1[0]=='c') && (str1[1]=='n') ){
		    l=strlen(str1);
		    memset(str3,0,strlen(str3) );
		    j=0;
		    k=5;
		    while(str1[k]!='\n'){
			str3[j]=str1[k];
			++j;
			++k;
		    }
		    memset(str1,0,strlen(str1) );
		    strcat(str1,str3);
		    memset(str3,0,strlen(str3) );
		    //printf("second check. getted string=\n%s\n",str1);

		    decode_string(str1);

		    tmp2=fopen("ldap_decoded","a+");
		    fputs(str1,tmp2);
		    fclose(tmp2);
		    memset(str1,0,strlen(str1) );
		}
		else {
		    //printf("string eq:%s\n",str1);
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

void decode_string(char str4[100]){
    int i;
    FILE *tmp3;

    tmp3=fopen("tmp2","w");
    fputs(str4,tmp3);
    fclose(tmp3);
    system("cat tmp2|base64 -d>tmp_decoded;echo \" \">>tmp_decoded");

    memset(str4,0,strlen(str4) );

    tmp3=fopen("tmp_decoded","r");
    fgets(str4,100,tmp3);
    fclose(tmp3);
//    fputs(str4);
    //printf("getted after decoding of string eq:%s\n",str4);

}