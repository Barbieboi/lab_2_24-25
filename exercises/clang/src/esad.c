#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
// gcc -std=c11 -Wall -O -g -o


void termina(char *messaggio){
	perror(messaggio);
	exit(EXIT_FAILURE);
}

char *converte16(int n){
	char *s = NULL ;
	int e  = asprintf(&s, "%x" , n);
	if(e == -1) termina("Errore asprintf");
	return s ;
}

int main(int argc, char **argv){
	if(argc < 2) termina("Argomenti insufficienti");
	for(int i = 1 ; i < argc ; i++){
		char *s = converte16(atoi(argv[i]));
		fprintf(stdout, "%s\n", s);
		free(s);
	}

	return 0;
}