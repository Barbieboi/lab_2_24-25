#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
// gcc -std=c11 -Wall -O -g -o
void termina(const char *messaggio);

typedef struct duetto {
  int primo;
  int secondo;
} coppia;

coppia* crea_coppia(int x, int y){
	coppia* pair = malloc(sizeof(pair));
	if(pair == NULL) termina("Memoria insufficente");
	pair->primo = x;
	pair->secondo = y ;
	return pair ;
}

void stampa_coppia(const coppia* c, FILE* f){
	fprintf(f, "(%d %d)\t" , c->primo, c->secondo);
}

void merge(coppia* a[], int na, 
		   coppia* c[], int nc, 
		   coppia* b[], int (*f)(coppia*, coppia*))
{
  assert(a!=NULL);
  assert(c!=NULL);
  assert(b!=NULL);
  assert(na>0);
  assert(nc>0);
  
  int i=0; // indice per a[]
  int j=0; // indice per c[]
  int k=0; // indice per b[]
  
  // scorro a[] e c[] e copio il minore in b[]
  while(i<na && j<nc) {
    if(f (a[i],c[j]) > 0) {
      b[k] = a[i];
      i++;
    } else {
      b[k] = c[j];
      j++;
    }
    k++;
  }
  
  // copio il resto di a[] in b[]
  while(i<na) {
    b[k] = a[i];
    i++;
    k++;
  }
  
  // copio il resto di c[] in b[]
  while(j<nc) {
    b[k] = c[j];
    j++;
    k++;
  }
  // asserzioni aggiunte da GM perché non si sa mai
  assert(i==na);
  assert(j==nc);
  assert(k==na+nc); 
}

// funzione mergesort ricorsiva
void mergesort(coppia** a, int n, int(*f)(coppia*, coppia*))
{
  assert(a!=NULL);
  assert(n>0);
  
  // caso base
  if(n==1) return;
  
  int n1 = n/2;       // dimensione prima parte
  int n2 = n - n1 ;   // dimensione seconda parte
  assert(n1+n2==n);   // verifico che sto considerando tutti gli elementi
  
  // ordino a[0...n1-1]
  mergesort(a,n1, f);
  // ordino a[n1...n-1]
  mergesort(&a[n1],n2,f); // &a[n1] potevo scriverlo a+n1
  
  // ora ho le due metà ordinate devo fare il merge
  coppia **b = malloc(n*sizeof(*b));
  if(b==NULL) termina("malloc fallita nel merge");
  merge(a,n1,&a[n1],n2,b,f);  
  // copio il risultato da b[] ad a[]
  for(int i=0;i<n;i++)
    a[i] = b[i];
  
  free(b); // dealloco array temporaneao b[]
}


int confronta_coppie(coppia* a, coppia* b){
	return a->primo-a->secondo<b->primo-b->secondo?1:-1;
}

int main(int argc, char **argv){
	if(argc%2==0)termina("Argomenti Dispari");
	int n = ((argc - 1)/2) ;
	coppia** pairs = malloc(sizeof(coppia*)*n);
	if(pairs==NULL) termina("memoria insufficente");
	int m = 0 ;
	for(int i = 1 ; i <= argc - 2 ; i += 2){
		pairs[m++] = crea_coppia(atoi(argv[i]), atoi(argv[i+1]));
	}
	assert(m==n);
	puts("Prima di Ordinare");
	for(int i = 0; i < n; i++)
		stampa_coppia(pairs[i], stdout);
	puts(" ");

	mergesort(pairs, n , confronta_coppie);

	puts("Dopo mergesort");
	for(int i = 0; i < n; i++)
		stampa_coppia(pairs[i], stdout);
	puts(" ");

	for(int i = 0; i < n; i++)
		free(pairs[i]);
	free(pairs);

	return 0;
}

void termina(const char *messaggio){
	if(errno != 0) perror(messaggio);
	else fprintf(stderr, "%s\n", messaggio);
	exit(EXIT_FAILURE);
}
