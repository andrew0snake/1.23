#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void main(){

    int i,c;
    char string1[100],string2[200],string3[100];

    i=c=0;
    FILE *tmp1,*tmp2,*tmp3;

    char *name[] = {
            "/bin/tcsh",            
	    "-c",
            "cat tmp_enc|base64 -d>tmp_decoded;",
                };
//    tmp1=fopen("tmp","w");
//    fclose(tmp1);

    tmp1=fopen("tmp","r");
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
    
    for(i=0;i<200;++i){
	if(i<100){
	    string1[i]=string2[i]=0;
	}
	else
	    string2[i]=0;
    }

    tmp1=fopen("tmp_cn2","r");
    fgets(string1,100,tmp1);
    fclose(tmp1);

    tmp1=fopen("tmp_cn1","r");
    fgets(string2,100,tmp1);
    fclose(tmp1);

    strcat(string2,string1);

    puts(string2);
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