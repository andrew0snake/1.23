#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main (){

    int i,c;
    char str[200],str2[200],str3[300];
    i=' ';
    FILE *tmp1,*tmp2;
	
    char *name[]={
	"/bin/tcsh",
	"-c",
	"cat tmp|base64 -d>>tmp_decoded;",
	};

    memset(str,0,strlen(str));

	execvp(name[0],name);
}
