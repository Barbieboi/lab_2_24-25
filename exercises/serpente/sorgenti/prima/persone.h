#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  

typedef struct pipol{
	char *nome , *cognome , *paese ;
	int anni ;
	struct pipol* left , *right;
}persona ;

persona* crea_persona(char* n, char *c, int a , char*p); 

void stampa_persona(const persona* p, FILE* f);

void free_nodo(persona* p);

void free_abr(persona *root);

persona* inserisci_abr(persona* root ,persona* p) ;

void stampa_abr(const persona* root, FILE* f) ;





