#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main (){

    int i,c;
    char str[200],str2[200],str3[300];
    i=' ';
    FILE *tmp1,*tmp2;

/*    printf("i in char=%c; and in digit=%d;\n",i,i);
    
    for(i=0;i<100;++i){
	str[i]=i;
	printf("str[%d]=%d;\n",i,str[i]);
    }
    c=getchar();    

    str[0]=55;
    memset(str,0,strlen(str));

    for(i=0;i<100;++i){
	printf("str[%d]=%d\n",i,str[i]);
	if (i==30 || (i==55) || (i==85) )
	    c=getchar();
    }
*/
//    for(i=0;i<1;++i){
        tmp1=fopen("test1","r");
	fgets(str,100,tmp1);
	i=strlen(str);
	c='\n';
	printf("str1=%s;str len=%d;str[%d-1]=%c;and in dec =%d;c=\\n=%d;\n",str,i,i,str[i-1],str[i-1],c);
//	fclose(tmp1);
    
//        tmp2=fopen("test1","r");
	fgets(str2,100,tmp1);
        printf("str2=%s;",str2);
	str[i-1]=NULL;
	strcat(str,str2);
	printf("Concatenated strings seem so:%s;",str);
	fclose(tmp1);
//    }


}