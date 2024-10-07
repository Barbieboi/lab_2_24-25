#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h> 

// stampa un messaggio d'errore su stderr e termina il programma
void termina(char *messaggio){
  if(errno!=0) perror(messaggio);
  else fprintf(stderr,"%s\n", messaggio);
  exit(1);
}

//Leggo interi da una stream f e ne memorizzo il numero
int *leggi_file(FILE *f, int *num_elementi){
    assert(f!=NULL); // il file deve essere valido
    int size=10; // dimensione attuale dell'array
    int messi=0; // numero di elementi attualmente nell'array
    int *a = malloc(size*sizeof(int));
    if(a==NULL)
        termina("Memoria insufficiente");
    
    while(true) {
        int n;
        int e = fscanf(f,"%d",&n);
        if(e==EOF) 
            break;
        if(e!=1) 
            termina("Contenuto illegale nel file");
        // ho letto un intero dal file ed è stato messo in n
        if(messi==size) {
            // ingrandisco l'array
            size = size*2;
            a = realloc(a,size*sizeof(int));
            if(a==NULL)
                termina("realloc fallita");
        }
        assert(size>messi);
        a[messi] = n;
        messi += 1;
    }
    // ho messo tutti gli elementi che mi interessavano
    size = messi;
    a = realloc(a,size*sizeof(int));
    if(a==NULL)
        termina("realloc fallita");  
    // salvo il numero di elementi e restituisco l'array  
    *num_elementi = messi;
    return a;  
} 

//stampa elementi di un qualsiasi array di int su di una stream f
void stampa_array(int *a, int n, FILE *f){
  assert(a!=NULL);
  for(int i=0;i<n;i++)
    fprintf(f,"%8d",a[i]);
}

void merge(int *a[], int na, 
           int *c[], int nc,
           int *b[], 
           int (*cmp)(int *x,int *y) )
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
    // guardo se il nome di a[i] è minore del nome c[j]
    // if( strcmp(a[i]->nome,c[j]->nome) < 0 ) { // oridnamento lessicografico per nome 
    if( cmp(a[i],c[j])<0  ) {  // unica istruzione da modificare per cambiare l'ordinamento
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


void mergesort(int *a[], int n,
               int (*cmp)(int *x,int *y))
{
  assert(a!=NULL);
  assert(n>0);
  
  // caso base
  if(n==1) return;
  
  int n1 = n/2;     // dimesione prima parte
  int n2 = n - n1;  // dimensione seconda parte
  
  mergesort(a,n1,cmp);
  mergesort(&a[n1],n2,cmp); // &a[n1] potevo scriverlo a+n1
  
  // ho le due metà ordinate devo fare il merge
  int **b = malloc(n*sizeof(*b));
  if(b==NULL) termina("malloc fallita nel merge");
  merge(a,n1,&a[n1],n2,b,cmp);  
  // copio il risultato da b[] ad a[]
  for(int i=0;i<n;i++)
    a[i] = b[i];  // sto copiando dei puntatori 
  
  free(b);
}


