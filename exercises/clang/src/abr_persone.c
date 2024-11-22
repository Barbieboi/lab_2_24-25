#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h> 

#include"persone.h"


persona* crea_abr(char *fileName, int *num){
	*num = 0 ;
	FILE *f = fopen(fileName, "r") ;
	if(f == NULL)
		exit(EXIT_FAILURE);
	char *buffer = NULL ;
	size_t n = 0;
	persona* root = NULL ;
	while (true){
		ssize_t e = getline(&buffer, &n, f);
		if(e < 0){
			free(buffer) ;
			break; 
		}	
		char* nome =  strtok(buffer , ",\n") ;
		char* cognome =	strtok(NULL , ",\n") ;
		char* a = strtok(NULL, ",\n") ;
		char* paese = strtok(NULL, ",\n") ;
		persona* tmp = crea_persona(nome, cognome, atoi(a) , paese);
		root = inserisci_abr(root , tmp);
		*num += 1 ;
	}
	if(fclose(f) == EOF)
		exit(EXIT_FAILURE); 
	return root ;	
}

void abr_persona_preorder(const persona *root, FILE *f, int depth)
{
	// stampa depth spazi per mostrare la profondità del nodo
	for(int i=0;i<depth;i++) fprintf(f,". ");
	if(root!=NULL) {
	stampa_persona(root,f);
	abr_persona_preorder(root->left,f,depth+1);
	abr_persona_preorder(root->right,f,depth+1);
	}
	else fprintf(f,"X\n");
}


int abr_ricerca_range(persona *r, int range) {
    if (r == NULL) return 0;  // caso base: albero vuoto
    int visitati = 0;
    if (r->anni > range) {
        visitati += abr_ricerca_range(r->left, range);
    }
    else if (r->anni >= 1 && r->anni < range) {        
        visitati++;
    }
    else {
        visitati += abr_ricerca_range(r->right, range);
    }
    return visitati;
}




int main(int argc, char **argv){

	int n ;
	persona* root = crea_abr(argv[1], &n);
	abr_persona_preorder(root, stdout, 0);
	int range = atoi(argv[2]);
	int visitati = abr_ricerca_range(root , range) ;
	fprintf(stdout, "#nodi : %d\n#visitati con range di %d anni: %d\n", n, range , visitati);
	
	
	free_abr(root);
	return 0;
}