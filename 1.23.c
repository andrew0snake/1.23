#include <stdio.h>
#define TAB 50

int gett(char text[10000]);
void form(int len,char text[10000]);
void decomment(int len,char text[10000]);

void main ()
{

    int i,c,l;
    char text[10000];

    printf("Enter text, what has to be formatted.\n");

    while( (l=gett(text) )>0 ){
	printf("Non formatted text seems so:\n%s\n-------------------------------------",text);
//	form(l,text);
	decomment(l,text);
	printf("Same text after formatting seems so:\n%s",text);
	
    }
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
	
    }
}





void decomment(int len,char text[10000])
{

    int i,j,k;
    
    i=j=k=0;
    
    for (i=1;i<=len;++i){
	if (text[i]=='/')
	    if (text[i-1]=='/'){
		j=i;
		k=0;
		    while(text[j]!='\n'){
		    if(text[j]=='"')
			k=1;
		    --j;
		}
		if(k==1){
		    j=i;
		    while( (text[j]!='\n') || (text[j]!=EOF) ){
		    if(text[j]=='"')
			k=1;
		    else 
			k=0;
		    ++j;
		    };
		}
		if (k==1)
		    text[i]=text[i-1]=' ';
	    }
    };
    
    for (i=1;i<len;++i){
	if (text[i]=='*')
	    if (text[i-1]=='/'){
		text[i]=text[i-1]=' ';
		for (j=i+1;j<len;++j){
		    if (text[j]=='*')
			if (text[j+1]=='/')
			text[j]=text[j+1]=' ';
		}
	    
	    }
    
    
    }
    
    

}