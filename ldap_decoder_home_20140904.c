#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define TAB 50

int gett(char text[10000]);
void form(int len,char text[10000]);
void split(int l);

void main ()
{

    int i,c,l;
    char text[10000];
    l=0;

    split(l);
    printf("normal end of program\n");

}

int gett(char text[10000])
{

    int c,i;
    
    for (i=0;i<10000;++i)
	text[i]=0;

    for (i=0;(c=getchar() )!=EOF;++i)
	text[i]=c;

    return i;
}

void form(int len,char text[10000])
{

    int i,j,k,l,s,t,diff;

    i=j=k=l=s=t=diff=0;
    
    for (i=0;i<=len;++i){
    
	++j;
	if (j==(TAB+1) ){
	    ++s;
	    if (i>TAB)
		diff=i-TAB;
	    else 
		diff=0;

	    k=i;
	    t=(-1);

	    while( (k>=diff) && (t<0) ){
		if ( (text[k]!=' ') && (text[k]!='\t') && (text[k]!='\n') )//&& (text[k]!=EOF) ) 
		    t=k;
		else
		    --k;
	    } 
	        
	    if (t>=0)
		printf("We got it!) t=%d;\n\n",t);
	    if (t>0){
		for(l=len;l>=(t+1);--l)
		    text[l]=text[l-1];
		text[t]='\n';
		++len;
	    }
	j=0;
	}
	
    }
}

void split(int some)
{
    int i,j,k,l,len_str,ex1;
    char str1[200],str2[200],str3[200];
    
    i=j=k=l=0;
    FILE *ldap_main,*tmp,*ldap_decoded;
    
    char *name[] = {
            "/bin/tcsh",
            "-c",        
<<<<<<< HEAD
            "cat tmp|base64 -d>tmp_decoded;echo " "; echo tmp =;cat tmp|base64 -d;echo " ";",
        };
=======
            "cat tmp|base64 -d>tmp_decoded;",
            };
>>>>>>> 8cf80f4e7a4664f7d8e6ea53c9ead8e4ede7d694

    for(i=0;i<200;++i){
	str1[i]=str2[i]=str3[i]=0;
    }

    ldap_main=fopen("ldap_ws","r");
<<<<<<< HEAD
    for(i=0;i<10000;i=i+200){
=======
    for(i=0;i<2000;++i){
>>>>>>> 8cf80f4e7a4664f7d8e6ea53c9ead8e4ede7d694
	printf("start of output\n");
//        if (fgets(str1,100,ldap_main)!=NULL){
	  fgets(str1,100,ldap_main);
	  printf("string 1:");
	  puts(str1);
	  j=0;
	  printf("Check started;\n");
	  if( (str1[0]=='c') && (str1[1]=='n') ){
	  	str1[0]='n';
		str1[1]='a';
		str1[2]='m';
		str1[3]='e';
<<<<<<< HEAD
//		str1[4]=':';	    
		j=5;
		k=0;
		for(l=0;l<=100;++l){
		    str2[l]=0;
//		    printf("str[%d]=%d;\n",l,str2[l]);
		}
=======
	    
		j=4;
		k=0;
	    	memset(str2,0,strlen(str2));	


>>>>>>> 8cf80f4e7a4664f7d8e6ea53c9ead8e4ede7d694
		while( (str1[j]!='\n') ){
		    str2[k]=str1[j];
		    ++k;
		    ++j;
		}
		printf("string 2:");
		puts(str2);
<<<<<<< HEAD
		printf("And after encoding string seems so:%s\n\n",str2);

		tmp=fopen("tmp","w+");
		fputs(str2,tmp);
//		fgets(str3,200,tmp);
		printf("string 3:%s",str3);
		fclose(tmp);

		execvp(name[0],name);
=======
		printf("And after encoding string seems so:");
	 	
		tmp=fopen("tmp","w");
		fputs(str2,tmp);	
		//fclose(tmp);
	
//		execvp(name[0],name);
>>>>>>> 8cf80f4e7a4664f7d8e6ea53c9ead8e4ede7d694

		tmp=fopen("tmp_decoded","r");
		fgets(str2,100,tmp);
		fclose(tmp);
		printf("decoded_string=||%s||\n",str2);
	    }
		printf("Count of output symbols is:%d;\n",i);
	
    }
//    for(i=0;i<len;++i){
//    }
    fclose(ldap_main);
    fclose(tmp);
}