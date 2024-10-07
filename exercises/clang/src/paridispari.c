#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
// gcc -std=c11 -Wall -O -g -o

int main(int argc, char *argv[]){
	
	if(argc < 4){
		perror("not enough arguments");
		exit(1);
	}
	FILE *f = fopen(argv[1], "r");
	FILE *pari = fopen(argv[2], "w");
	FILE *dispari = fopen(argv[3], "w");
	if(f == NULL || pari == NULL || dispari == NULL){
		perror("errore apertura file");
		exit(1);}
	int val ;
	int e = fscanf(f, "%d", &val);
	while(e != EOF){
		if(e != 1){exit(1);}
		if(val % 2 == 0)
			fprintf(pari, "%d\n", val);
		else
			fprintf(dispari, "%d\n", val);
		e = fscanf(f, "%d", &val);
	}
	
	if(fclose(f) == EOF || fclose(pari) == EOF || fclose(dispari) == EOF)
		exit(1);
	

	return 0;
}