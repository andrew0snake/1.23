#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void main(){

    int i,c,j,k,l;
    char string1[100],string2[200],string3[100];

    i=c=0;
    FILE *tmp1,*tmp2,*tmp3;

    char *name[] = {
            "/bin/tcsh",            
	    "-c",
            "cat tmp;",
                };
//    tmp1=fopen("tmp","w");
//    fclose(tmp1);

/*    tmp1=fopen("tmp","r");
    while( (c=fgetc(tmp1))!=EOF ){
	printf("symbol c=%c;\n",c);
    
    }    
    fclose(tmp1);


    tmp1=fopen("tmp","a");
    fputs("test string\n",tmp1);
    fclose(tmp1);

    tmp1=fopen("tmp","r");
    fgets(string1,100,tmp1);
    printf("putstring here:\n");
    puts(string1);
    printf("print string:%s;\n",string1);
    fclose(tmp1);
*/

    memset(string1,0,strlen(string1) );
    memset(string2,0,strlen(string2) );
    tmp1=fopen("ldap_ws","r");    
    for(i=0;i<2100;++i){
	fgets(string1,100,tmp1);
	if( (string1[0]=='c') && (string1[1]=='n') ){
	    j=5;
	    k=0;
//	    printf("string1:%s;\n",string1);
	    memset(string2,0,strlen(string2) );
	    while(string1[j]!='\n'){
//		printf("string1[%d]=%c;string2[%d]=%c;\n",j,string1[j],k,string2[k]);
		string2[k]=string1[j];
		++j;
		++k;
	    }
	    tmp2=fopen("tmp","w");
	    fputs(string2,tmp2);
	    fclose(tmp2);

	    system("cat tmp|base64 -d>>tmp_decoded;echo " ">>tmp_decoded;");
//	    c=getchar();
//	    system("echo \"encoded:\";cat tmp;echo " ";echo \"decoded:\";cat tmp_decoded");
//	    execvp(name[0],name);
//	    printf("string2:%s;\n",string2);
	    
	    
	}
	else{
	    tmp2=fopen("tmp_decoded","a+");
	    fputs(string1,tmp2);
	    fclose(tmp2);
	}

    }

/*    tmp1=fopen("tmp_cn2","r");
    fgets(string1,100,tmp1);
    fclose(tmp1);

    tmp1=fopen("tmp_cn1","r");
    fgets(string2,100,tmp1);
    fclose(tmp1);

    strcat(string2,string1);

    puts(string2);
*/

/*    tmp2=fopen("tmp_enc","a+");
    fgets(string2,80,tmp2);
    printf("encoded string:");
    puts(string2);
    fclose(tmp2);

    execvp(name[0],name);

    tmp3=fopen("tmp_decoded","a+");
    fgets(string3,80,tmp3);
//    puts(string3);
    printf("Decoded string:%s;\n",string3);
//    printf("test");
    fclose(tmp3);
*/
}