#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
// gcc -std=c11 -Wall -O -g -o

void termina(char *messaggio);


int main(int argc, char **argv){
	if(argc !=3)
		termina("Argomenti insufficienti");
	FILE *f = fopen(argv[1], "r");		 
	if(f == NULL) termina("Errore apertura file di lettura");
	int l = 20 ;
	int i = 0;
	char **a = malloc(l*sizeof(char*));
	if(a == NULL)
		termina("Memoria insufficente");
	int e = 0;
	while(e != EOF){
		if(i == l){
			l = l*2;
			a = realloc(a, l*sizeof(char*));
			if(a == NULL)
				termina("Realloc fallita");
			}
		e = fscanf(f, "%ms" , &a[i++]);
	}

	l = i - 1 ;
	a = realloc(a, l*sizeof(char*));
	if(fclose(f)==EOF)
		termina("Errore chiusura file di lettura");

	FILE* out = fopen(argv[2], "w+");
	if(out == NULL)	
		termina("Errore apertura file di scrittura");
	for(int i = l - 1; i >= 0; i--){
		fprintf(out, "%s\n", a[i]);
	}	
	if(fclose(out)==EOF)
		termina("Errore chiusura file di scrittura");
	for(int i = 0; i<l ; i++){
		free(a[i]);
	}
	free(a);

	return 0;
}






void termina(char *messaggio){
	perror(messaggio);
	exit(1);
};