#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
// gcc -std=c11 -Wall -O -g -o

bool isIn(int* a , int size ,int el ){
	bool res = false;
	for(int i=0; i < size ; i++){
		if(a[i] == el){res = true;}
	}
	return res;
}


int *somme_distinte(int a[], int n , int *size){
	assert(a!=NULL);
	assert(n > 0);
	int l = n*2;
	int *b = malloc(l*sizeof(int));
	if(b == NULL){exit(EXIT_FAILURE);}
	int messi = 0 ;
	int val = 0;
	bool ZeroIn = false;
	for(int i = 0 ; i < n ; i++){
		if(messi >= l){ 
		l = l*2 ;
		b = realloc(b , l*sizeof(int));}
		for(int j = 0 ; j < n ; j++){
			val = a[i] + a[j];
			if(val == 0 && !ZeroIn){
				b[messi++] = val ;
				ZeroIn = true;
			}
			else if(!(isIn(b , l , val))){
				b[messi++] = val ;
			}
		}
	}
	b = realloc(b, messi*sizeof(int));
	*size = messi;
	return b ;
}

void stampa_array(int *a, int n);



int main(int argc, char *argv[]){

	if(argc == 1){
		perror("argomenti insufficienti");
		exit(EXIT_FAILURE);}

	int *arr = malloc((argc-1) * sizeof(int));	
	if(arr == NULL){exit(EXIT_FAILURE);}
	for(int i = 1 ; i < argc; i++){
		arr[i-1] = atoi(argv[i]);
	}

	int N ;
	int *res = somme_distinte(arr, argc-1, &N);
	
	int sum = 0 ;
	for(int i = 0; i < N; i++){
		sum+=res[i];}
	fprintf(stdout, "somma: %4d\n", sum);
	free(arr);
	free(res);
	return 0;

}


void stampa_array(int *a, int n){

  assert(a!=NULL);
  assert(n>=0);
  // stampo il contenuto dell'array
  for(int i=0;i<n;i++){
  	fprintf(stderr,"%8d",a[i]);}; // stampo gli elementi in un campo di 8 caratteri
	fprintf(stderr, "\n");
}  
