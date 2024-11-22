#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
#include"terne.h"

#define Delim ":;\n"

terna* inserisci_terna(terna* root, terna* t){
	if(root == NULL)
		return t ;
	t->left = t->right = NULL ;
	int ris = terna_confronta(t,root);
  	if(ris==0) {    
	fprintf(stderr, "Nodo duplicato: ");
    terna_stampa(t,stderr);
    terna_distruggi(t);
  	}
  	else if(ris<0) 
    	root->left = inserisci_terna(root->left,t);
  	else 
    	root->right = inserisci_terna(root->right,t);
  	return root;
}

void abr_free(terna* root){
	if(root != NULL){
		abr_free(root->left) ;
		terna_distruggi(root);
		abr_free(root->right) ;
	}
}

bool linea_corretta(const char* s){
	int i = 0 ;
	while(s[i] != '\0'){
		if(s[i] != '-' || s[i] != ';' || s[i] != ':' || s[i] != '\n' )
			return false ;
		i++ ;
	}
	return true ;
}

terna* crea_abr(FILE *f, int *num){
	assert(f != NULL);
	char *buffer = NULL ;
	size_t n = 0 ;
	terna* root = NULL ;
	while (true){
		ssize_t e = getline(&buffer, &n , f);
		if(e < 0){
			free(buffer);
			break; 
		}
		char *s = strtok(buffer , Delim);
		while (s != NULL){
			if(!(linea_corretta(s))){
				break; 
			}
			printf("%s\n", s);
			int primo = strlen(s);
			int secondo = strlen(strtok(NULL, Delim)) ;
			int terzo = strlen(strtok(NULL, Delim)) ;
			if(strtok(NULL, Delim ) != NULL)
				break; 
			terna* tmp = terna_crea(primo , secondo ,terzo);
			fprintf(stdout,"creato nodo:") ;
			terna_stampa(tmp, stdout);
			root = inserisci_terna(root ,tmp) ;
			*num += 1 ;
		}
	}
	return root ;	
}

int conta_terne(const terna* root , int range){
	if(root == NULL)
		return 0 ;
	int tot = 0 ;
	tot += conta_terne(root->left, range) ;
	int sum = root->x + root->y + root->z ;
	tot += sum == range?sum:0 ;
	tot += conta_terne(root->right, range) ;
	
	return tot ;
}

int main(int argc, char const **argv){

	if(argc < 2)
		exit(EXIT_FAILURE); 

	FILE *f = fopen(argv[1], "r") ;
	if(f == NULL)
		exit(EXIT_FAILURE);
	int n = 0 ;
	terna* root = crea_abr(f, &n) ;
	fprintf(stdout, "%d\n", n) ;
	for(int i = 2 ; i < argc ; i++){
		fprintf(stdout, "%d\n" , conta_terne(root, atoi(argv[i]))) ;
	}

	fclose(f);
	abr_free(root);

	return 0;
}
