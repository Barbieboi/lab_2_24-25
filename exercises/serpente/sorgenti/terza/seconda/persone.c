#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  

#include"persone.h"

persona* crea_persona(char* n, char *c, int a , char*p){
	persona* nodo = malloc(sizeof(*nodo));
	nodo->nome = strdup(n);
	nodo->cognome = strdup(c) ;
	nodo->anni = a ;
	nodo->paese = strdup(p);
	nodo->left = nodo->right = NULL ;
	return nodo ;
}

void free_nodo(persona* p){
	free(p->nome);
	free(p->cognome);
	free(p->paese);
	free(p);
}

persona* inserisci_abr(persona* root , persona* p){
	if(root == NULL)
		return p ;
	if(p->anni <= root->anni)
		root->left = inserisci_abr(root->left, p) ;
	else 
		root->right = inserisci_abr(root->right, p);

	return root ;
}

void free_abr(persona *root){
	if(root != NULL){
		free_abr(root->left) ;
		free_abr(root->right); 
		free_nodo(root) ;
	}
}

void stampa_persona(const persona* root, FILE* f){
	fprintf(f, "<%s> <%s> <%d> <%s>\n", root->nome , root->cognome , root->anni, root->paese);
}

void stampa_abr(const persona* root, FILE*f){
	if(root != NULL){
		stampa_persona(root, f);
		stampa_abr(root->left , f);
		stampa_abr(root->right , f);
	}
}