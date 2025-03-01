#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  


typedef struct Node_t {
	int n ;
	struct Node_t * left , * right ;
} nodo ; 

nodo *crea_nodo(int n) ;

nodo *inserisci_abr(nodo *root , nodo *c) ;

void free_abr(nodo* root);

void stampa_abr(nodo *root , FILE *f);