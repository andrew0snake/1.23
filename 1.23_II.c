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
	printf("---------------Non formatted text seems so:--------------------|\n%s\n---------------------------------------------------------------|\n",text);
//	form(l,text);
	decomment(l,text);
	printf("---------------Same text after formatting seems so:------------|\n%s\n---------------------------------------------------------------|\n",text);
	
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

    int i,j,k,p,p1,p2,ex,start,end,diff,st,et,count;
    
    i=j=k=p=p1=p2=ex=start=end=diff=st=et=count=0;
    
    for (i=1;i<=len;++i){
	if (text[i]=='/')
	    if (text[i-1]=='/'){
		j=(i);
		p=1;
		start=(i-1);
//		printf("before first check:text[%d]=%d;and in char =%c;p=%d;ex=%d\n",j,text[j],text[j],p,ex);
		p1=ex=0;
		while( (ex==0) && (p1==0) ){
		    if(text[j]=='"')
			p1=1;
		    if ( (j<=0) || (text[j]=='\n') )
			ex=1;
		    --j;
		};
		if(p1==1){
		    j=(i);
		    p2=ex=0;
//		    printf("second part of check\nbefore while p2=%d;ex=%d;j=%d\n",p2,ex,j);
		    while( (ex==0) && (p2==0) ){
			if(text[j]=='"')
			    p2=1;
			if( (text[j]=='\n') || (text[j]==EOF) || (j==len) )
			    ex=1;
			++j;
//			printf("2:text[%d]=%d;%c;p2=%d;ex=%d\n",j,text[j],text[j],p2,ex);
		    };
		};
//		printf("p1=%d;p2=%d=p=%d;\n",p1,p2,p);
//		if ( (p1==1) && (p2==1) )		//
//		    p=0;				//
//		else					//old logic of check)
//		    p=1;				//
//		if (p==1)				//
		if ( (p1!=1) || (p2!=1) ){
/*		    text[i]=text[i-1]=' ';
		    p=0;
		    k=(i-1);
		    while(p==0){
			++k;
			if( (text[k]=='\n') || (text[k]==EOF) )
			    p=1;
			if( (text[k]=='/') && (text[k+1]=='/') )
			    p=1;
		    }
		    i=k;
*/
		    p=0;
		    k=i;
		    while(p==0){
			if( (text[k]=='\n') || (text[k]==EOF) )
			    p=1;
			++k;
		    }
		    if(p==1)
			end=(k-1);
		    diff=end-start;
//		    printf("start=%d;end=%d;diff=%d\n",start,end,diff);
		    if(text[end]==EOF)
			printf("The end)\n");
//moving down "//" comments			
		    for(k=start;(k+diff)<=len;++k){
//			printf("k=%d;text[k]=%d;\n",k,text[k]);
			text[k]=text[k+diff];
		    
		    }
		    ex=0;
		}
	    }
    };
    
/*    for (i=1;i<len;++i){
	if (text[i]=='*')
	    if (text[i-1]=='/'){
		text[i]=text[i-1]=' ';
		for (j=i+1;j<len;++j){
		    if (text[j]=='*')
			if (text[j+1]=='/')
			    text[j]=text[j+1]=' ';
		}
	    
	    }
    
    
    };
//----------------old easy check rule
*/
//----------------reinitialise variables
    p1=p2=p=ex=start=end=0;
//----------------search for first part of commentary /* */
    for(i=1;i<len;++i){
	if (text[i]=='*')
	    if (text[i-1]=='/'){
		j=(i);
		p1=ex=start=end=st=et=0;
		while( (ex==0) && (p1==0) ){
		    if (text[j]=='"'){
			p1=1;
		    }
		    if ( (j<=0) || text[j]=='\n'){
			ex=1;
		    }
		    --j;
		}
		if(p1==1){
		    j=(i+1);
		    p2=ex=0;
		    while( (ex==0) && (p2==0) ){
			if(text[j]=='"')
			    p2=1;
			if(  (text[j]=='\n')  || (text[j]==EOF) ||(j==len) ){
			    ex=1;	
			}
			++j;
		    }
		}
		if( (p1!=1) || (p2!=1) ){
		    start=(i-1);
		    st=1;
		    printf("start=i=%d;len=%d\n",start,len);
//--------------looking for second part of comment
		    p1=p2=ex=et=count=0;
		    for(j=i;j<len;++j){
			if(text[j]=='*')
			    if(text[j+1]=='/'){
			        k=j;
			        p1=p=ex=0;
				while( (ex==0) && (p1==0) ){
				    if(text[k]=='"')
					p1=1;
				    if( (k<=0) || (text[k]=='\n') )
					ex=1;
				    --k;
				}
				k=j;
				p2=ex=0;
				if(p1==1){
				    while( (ex==0) && (p2==0) ){
					if(text[k]=='"')
					    p2=1;
					if( (text[k]=='\n') || (text[k]==EOF) || (k==len) )
					    ex=1;
					++k;
				    }
				}
				
			    if( (p1!=1) || (p2!=1) )
				end=j+1;
				et=1;
				diff=end-start;
				printf("end=(j-1)=%d;diff=%d\n",end,diff);
			    }
			    if( (st==1) && (et==1) ) {
				for(k=start;(k+diff)<len;++k){
				    text[k]=text[k+diff];
				    printf("text[k=%d]=%c;text[k+diff=%d]=%c\n",k,text[k],(k+diff),text[k+diff]);
				}
				len=len-diff;
				++count;
				printf("after moving len=%d;count=%d\n",len,count);
			    }

		    } // end of looking for second part of comment
		}//end of second check for ending part of second comment
	    }//end of first check for second comment
/*	    if( (st==1) && (et==1) ) {
		for(k=start;(k+diff)<=len;++k){
		text[k]=text[k+diff];
	    printf("text[k=%d]=%c;text[k+diff=%d]=%c\n",k,text[k],(k+diff),text[k+diff]);
	    }
	}*/
	
    };//end of cycle
}