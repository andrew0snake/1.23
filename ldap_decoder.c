#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define TAB 50

int gett(char text[10000]);
void form(int len,char text[10000]);
void split(int l);

void main ()
{

    int i,c,l;
    char text[10000];
    l=0;

    printf("Enter text, what has to be formatted.\n");

/*    while( (l=gett(text) )>0 ){
	printf("Non formatted text seems so:\n%s\n-------------------------------------",text);
	form(l,text);
	printf("Same text after formatting seems so:\n%s",text);
//    for (i=0;i<l;++i)
//	printf("Symbol %i-th in char=%c; and in digit=%d\n",i,text[i],text[i]);

	
    }*/
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

//	    printf("i=%d;diff=%d;k=%d;t=%d;\n",i,diff,k,t);
//	    printf("----------------------------------------\n");

	    while( (k>=diff) && (t<0) ){
//		printf("step before testing k=%d;t=%d;text[k]=%c\n",k,t,text[k]);
		if ( (text[k]!=' ') && (text[k]!='\t') && (text[k]!='\n') )//&& (text[k]!=EOF) ) 
		    t=k;
		else
		    --k;
//		printf("step after testing  k=%d;t=%d;text[%d]=%c\n",k,t,k,text[k]);
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
	
//	printf("in char text[%d]=%c;in digit text[%d]=%d;i=%d,j=%d\n ",i,text[i],i,text[i],i,j);
    }
//    for (i=0;i<len;++i)
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
            "cat tmp|base64 -d>tmp_encoded;",
            NULL    };

    for(i=0;i<200;++i){
	str1[i]=str2[i]=str3[i]=0;
    }

    ldap_main=fopen("ldap_main","r");
    for(i=0;i<3000;i=i+100){
	printf("start of output\n");
        if (fgets(str1,i,ldap_main)!=NULL){
	    printf("string 1:");
	    puts(str1);
	    j=0;
	    if( (str1[0]=='c') && (str1[1]=='n') ){
		str1[0]='n';
		str1[1]='a';
		str1[2]='m';
		str1[3]='e';
//		str1[4]=':';	    
	    
		j=4;
		k=0;
		while(str1[j]!='\n'){
		    str2[k]=str1[j];
		    ++k;
		    ++j;
//		    printf("k=%d;j=%d;\n",k,j);
		}
		printf("string 2:");
		puts(str2);
		printf("And after encoding string seems so:");
		
		tmp=fopen("tmp","w");
		fputs(str2,tmp);
		fgets(str3,200,tmp);
		printf("string 3:%s",str3);
		execvp(name[0],name);
	    }
		printf("Count of output symbols is:%d;\n",i);
	}
    }
//    for(i=0;i<len;++i){
//    }
    fclose(ldap_main);
    fclose(tmp);
}