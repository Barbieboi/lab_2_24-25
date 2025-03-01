#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
// gcc -std=c11 -Wall -O -g -o


int mioatoi(const char *s, int *n){
	assert(s != NULL);
	int i = 0;
	while(s[i] == ' ' && i < strlen(s)){
		i++;
	}
	bool negativo = false ;
	bool numero = false;
	int segno = 0 ;
	if(s[i] == '\0')
		return 1;
	else if(s[i] == '-'){
		segno++;
		negativo = true ;
		i++;
		}
	int t = 0 ;
	int cifra = 0;
	while(i < strlen(s) && s[i] != ' ' ){
		if(s[i]<48 || s[i]>57){
			if(s[i] == '+'|| s[i] == '-'){
				segno++;
			}
			else {return 2;}
		}
		if(segno > 1)
			return 3;
		numero = true;
		cifra = s[i] - 48;
		t = 10*t + cifra;
		i++;
	}
	if(segno == 1 && !numero)
		return 4;
	*n = (negativo)? t*(-1):t ;
	return 0;
}

int main(int argc, char *argv[])
{
  for(int i=1;i<argc;i++) {
    int n, e;
    e = mioatoi(argv[i],&n);
    if(e!=0) printf("Errore conversione: %d\n",e);
    else printf("Mia funzione: %d, libreria: %d\n",n,atoi(argv[i]));
  }
  return 0;
}