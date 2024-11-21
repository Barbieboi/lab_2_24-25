#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
#include"abr_int.h"

nodo *crea_nodo(int n){
	nodo *p = malloc(sizeof(*p)) ;
	if(p == NULL)
		exit(EXIT_FAILURE);
	p->n = n ;
	p->left = p->right = NULL ;
	return p ;
}


nodo *inserisci_abr(nodo *root, nodo*c){
	c->left=c->right=NULL;
  	// caso base albero vuoto
  	if(root==NULL) 
    	return c;
  	if(c->n==root->n) { // Numeri duplicati    	
		fprintf(stderr, "Nodo duplicato: %d\n" , c->n);
    	free(c);
  	}
  	else if(c->n<root->n) 
    	root->left = inserisci_abr(root->left,c);
  	else 
    	root->right = inserisci_abr(root->right,c);
  	return root;
}

void free_abr(nodo* root){
	if(root != NULL){
		free_abr(root->left);
		free_abr(root->right);
		free(root);
	}
}


void stampa_abr(nodo *root, FILE* f){
	if(root!=NULL) {
    stampa_abr(root->left,f);
    fprintf(f, "(%d)\n" , root->n);
    stampa_abr(root->right,f);
  }
}
