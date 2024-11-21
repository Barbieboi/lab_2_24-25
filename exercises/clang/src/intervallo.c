#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
#include"abr_int.h"

nodo* crea_albero(char* nameFile){
	FILE* f = fopen(nameFile,"r");
	if(f == NULL)
		exit(EXIT_FAILURE) ;
	nodo *root = NULL ;
	char *buffer = NULL ;
	size_t n = 0 ;
	while(true){
		ssize_t e = getline(&buffer, &n, f);
		if(e < 0){ 
			free(buffer);
			break ; }
		char *s	 = strtok(buffer, " \n");
		while (s!=NULL){
			nodo *tmp = crea_nodo(atoi(s));
			root = inserisci_abr(root , tmp);
			s = strtok(NULL, " \n");
		}
	}
	if(fclose(f)==EOF)
		exit(EXIT_FAILURE);
	return root ;
}

int stampa_range(nodo* root , int min , int max , FILE *f){
	if(root != NULL){
		if(root->n < min)
			return 1 + stampa_range(root->right , min , max , f) ;
		else if(root->n > max)
			return 1 + stampa_range(root->left , min , max , f) ;
		else fprintf(f ,"(%d)\n", root->n) ;
			return 1 + stampa_range(root->left,min,max,f) + stampa_range(root->right,min,max,f) ;
	}
	return 0 ;
}



int main(int argc, char **argv){
	if(argc != 2)
		fprintf(stderr, "Uso errato");
	nodo *root = crea_albero(argv[1]);

	stampa_abr(root, stdout);
	puts("----------------------");
	stampa_range(root , 4 , 100, stdout);
	puts("----------------------");
	free_abr(root);

	return 0;
}