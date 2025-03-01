#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
// gcc -std=c11 -Wall -O -g -o



int main(int argc, char **argv){
	
	if(argc != 2){
		perror("Argomento mancante");
		exit(EXIT_FAILURE);}
	int n = 1001;
	int* a = calloc(n, sizeof(int));
	if(a == NULL){
		perror("Errore allocazione");
		exit(EXIT_FAILURE);}
	FILE *f = fopen(argv[1], "r");
	if(f == NULL){
		perror("Errore apertura file");
		exit(EXIT_FAILURE);}
	int val; 
	int e = fscanf(f , "%d" ,&val);
	while(e != EOF){
		if(e != 1){
			perror("contenuto illegale nel file");
			exit(EXIT_FAILURE);}
		if(val >= 1 && val <= 1000)
			a[val] = 1 ;
		e = fscanf(f , "%d" ,&val);
	}
	if(fclose(f) == EOF){
		perror("Errore chiuusura file");
		exit(EXIT_FAILURE);
	}
	int res = 0;
	for(int i = 1; i < n; i++){
		res = res + (a[i]==0?i:0);}
	free(a);
	fprintf(stdout, "somma numeri mancanti: %d\n", res);

	return 0;
}