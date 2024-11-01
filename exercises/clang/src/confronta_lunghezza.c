#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
// gcc -std=c11 -Wall -O -g -o
void termina(const char *messaggio){
	if(errno!=0) perror(messaggio);
	else fprintf(stderr,"%s\n", messaggio); 
	exit(1); 
}

typedef struct _intero {
	int valore;
	struct _intero* next ;
} intero ;

int confronta_lunghezza(intero* lis1, intero* lis2){
	int n1 = 0;
	int n2 = 0;
	while (lis1 != NULL){
		n1++ ;
		lis1 = lis1->next ;
	}
	while (lis2 != NULL){
		n2++ ;
		lis2 = lis2->next ;
	}
	if(n1 == n2) return 0;
	else if(n1>n2) return 1;
	else return -1 ;
}

intero* insert(intero* lis ,int n){
	intero* nodo = malloc(sizeof(*nodo));
	if(nodo == NULL) termina("Memoria Insuffciente") ;
	nodo->valore = n;
	nodo->next = lis ;
	return nodo ;
}

int somma_lis(intero* lis){
	int sum = 0;
	while (lis!=NULL){
		sum += lis->valore;
		lis = lis->next;
	}
	return sum ;
}

void print_lis(intero* lis){
	while (lis != NULL){
		printf("%d -> ", lis->valore) ;
		lis = lis->next;
	}
	printf("NULL\n");
}

void free_lis(intero *lis){
	intero* tmp ;
	while(lis != NULL){
		tmp = lis ;
		lis = lis->next ;
		free(tmp);
	}
}

int main(int argc, char **argv){

	if(argc == 1) termina("argomenti insufficienti");
	intero* pari = NULL;
	intero* dispari = NULL;
	int n ;
	for(int i=1; i < argc; i++){
		n = atoi(argv[i]);
		if(n%2==0) {pari = insert(pari, n);}
		else {dispari = insert(dispari, n);}
	}
	int l = confronta_lunghezza(pari, dispari);
	if(l == 1) print_lis(pari);
	else if(l == -1) print_lis(dispari);
	else if(l == 0){
		if(somma_lis(pari)>somma_lis(dispari))
			print_lis(pari);
		else if(somma_lis(pari)<somma_lis(dispari))
			print_lis(dispari);
	}

	free_lis(pari);
	free_lis(dispari);

	return 0;
}