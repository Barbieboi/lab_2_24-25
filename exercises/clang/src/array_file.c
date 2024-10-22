#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // richiesto per usare errno

// Scopo del programma:
//   Mostrare come si definiscono e usano i puntatori a struct
//   in particolare gli array di puntatori a struct


// prototipi delle funzioni che appaiono dopo il main()
void termina(const char *messaggio);


// definizione struct che rappresenta
// una città con nome e coordinate 


typedef struct {
	char *nome ;
	long size;
} miofile ;



// crea oggetto miofile a partire dal nome
miofile* miofile_crea(char *s){
	assert(s != NULL);

	FILE* f = fopen(s, "r") ;
	if(f == NULL){
		return NULL ;
	}
	if(fseek(f, 0 ,SEEK_END) != 0){
		fclose(f) ;
		return NULL;
	}
	long pos = ftell(f) ;
	if(pos < 0){
		fclose(f);
		return NULL;
	}
	fclose(f) ;
	miofile* file = malloc(sizeof(*file));
	file->nome = strdup(s);
	file->size = pos ;
	return file ;
}

// distrugge (dealloca) un oggetto miofile 
void miofile_free(miofile *a)
{
  free(a->nome);
  free(a);
}


#if 0
// Nota: questa parte di codice fino a #endif non viene compilata

// Avendo definito il tipo miofile, ecco due 
// possibili definizione di array di 100 capitali:
// statico (dimensione immutabile)
miofile a[100];  // ogni a[i] = una miofile  = 24 byte
// dinamico
miofile *a = malloc(100*sizeof(*a));
// dopo aver creato a[] in questo modo, posso modificare gli elementi: 
a[0].lat = 34.2;

// In questo esercizio invece di un array di oggetti di tipo miofile
// lavoreremo invece con un array di puntatori a miofile:
// versione statica
miofile *b[100]; // ogni b[i] = un puntatore = 8 byte
// versione dinamica
miofile **b = malloc(100*sizeof(*b));
// ogni b[i] però è solo un puntatore, non esiste lo spazio
// per i tre campi nome, lat, lon è necessario allocarlo:
b[0] = malloc(sizeof(miofile));
// Dato che b[0] è un puntatore, per settare la latitudine devo scrivere: 
(*b[0]).lat = 43.2;  // corretta, ma non si usa
// oppure:
b[0]->lat = 43.2;    // useremo questa;
#endif



// stampa sul file *f i campi del file a
void miofile_stampa(const miofile *a, FILE *f) {
  fprintf(f,"nome file: %s dimensione: %ld\n", a->nome, a->size);
}


// --------------------------------------------------------
// ordinamento di un array di puntatori a miofile

// funzione di merge adattata dal merge di array di interi
void merge(miofile *a[], int na, 
           miofile *c[], int nc,
           miofile *b[])
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
    if( strcmp(a[i]->nome,c[j]->nome) < 0 ) { // ordinamento lessicografico per nome 
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
  assert(i==na);
  assert(j==nc);
  assert(k==na+nc); 
}



// funzione mergesort ricorsiva, adattata dal mergesort di interi
// è stato sufficiente modificare il tipo da int -> miofile * 
void mergesort(miofile *a[], int n)
{
  assert(a!=NULL);
  assert(n>0);
  
  // caso base
  if(n==1) return;
  
  int n1 = n/2;     // dimesione prima parte
  int n2 = n - n1;  // dimensione seconda parte
  
  mergesort(a,n1);
  mergesort(&a[n1],n2); // &a[n1] potevo scriverlo a+n1
  
  // ho le due metà ordinate devo fare il merge
  miofile **b = malloc(n*sizeof(*b));
  if(b==NULL) termina("malloc fallita nel merge");
  merge(a,n1,&a[n1],n2,b);  
  // copio il risultato da b[] ad a[]
  for(int i=0;i<n;i++)
    a[i] = b[i];  // sto copiando dei puntatori 
  
  free(b);
}

int main(int argc, char *argv[])
{
	if(argc<2) {
	printf("Uso: %s nomifile\n",argv[0]);
	exit(1);
	}

	miofile **palle = malloc(sizeof(*palle)*(argc-1));
	if(palle == NULL) termina("Memoria insufficente");

	int n = 0 ;
	for(int i = 1 ; i < argc-1; i++){
		miofile* tmp = miofile_crea(argv[i]);
		if(tmp != NULL) palle[n++] = tmp ;
	}

	for(int i = 0 ; i < n; i++){
		miofile_stampa(palle[i], stdout);
	}


	return 0;
}


// stampa su stderr il messaggio che gli passo e 
// e il messaggio associato all'ultimo errore e ternina
void termina(const char *messaggio)
{
  perror(messaggio);
  exit(1);
}

