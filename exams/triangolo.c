#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
// gcc -std=c11 -Wall -O -g -o

/*

Esercizio 2 Scrivere un programma triangolo che invocato scrivendo:

triangolo nomefile
legge da nomefile le stringhe contenute in esso e le salva in un array. Successivamente crea un file nomefile.triangolo contenente nella riga i-esima le parole dalla i-esima alla prima in ordine inverso. Ad esempio, se il file di input si chiama moria e contiene le parole dite amici ed entrate il file di output deve chiamarsi moria.triangolo e contentere le 4 righe:

dite
amici dite
ed amici dite
entrate ed amici dite

L'esercizio verrà considerato corretto solamente se la memoria verrà gestita in maniera dinamica e correttamente deallocata (verrà utilizzato valgrind per la verifica).

*/

void termina(char *messaggio) {
  if (errno != 0)
    perror(messaggio);
  else
    fprintf(stderr, "%s\n", messaggio);
  exit(1);
}

char **leggi_file(FILE *f, int *num_elementi)
{
  assert(f!=NULL); // il file deve essere valido
  int size=10; // dimensione attuale dell'array
  int messi=0; // numero di elementi attualmente nell'array
  char** a = malloc(size*sizeof(char*));
  if(a==NULL)
    termina("Memoria insufficiente");
    
  while(true) {
    char* s = NULL ;
    int e = fscanf(f,"%ms",&s);
    if(e==EOF) break;
    if(e!=1) termina("Contenuto illegale nel file");
    // ho letto un intero dal file ed è stato messo in n
    if(messi==size) {
        // ingrandisco l'array
        size = size*2;
        a = realloc(a,size*sizeof(char*));
        if(a==NULL)
          termina("realloc fallita");
    }
    assert(size>messi);
    a[messi] = s;
    messi += 1;
  }
  // ho messo tutti gli elementi che mi interessavano
  size = messi;
  a = realloc(a,size*sizeof(char*));
  if(a==NULL)
    termina("realloc fallita");  
  // salvo il numero di elementi e restituisco l'array  
  *num_elementi = messi;
  return a;  
} 

void freestr(char **s, int n){
	for(int i = 0; i < n ; i++)
		free(s[i]);
}

int main(int argc, char **argv){
	if(argc == 1) termina("Uso: triangolo nomefile");	
	
	FILE *f = fopen(argv[1], "r");
	if(f == NULL) termina("Errore apertura file di lettura");
	int n;
	
	char **str = leggi_file(f,&n);
	if(fclose(f)== EOF) termina("Errore chiusura file di lettura");

	char *target = NULL;
	int e = asprintf(&target , "%s.triangolo", argv[1]);
	if(e == -1) termina("Errore asprintf");

	FILE* out = fopen(target, "w");
	if(out == NULL) termina("Errore apertura file di scrittura");

	for(int i = 0; i < n ; i++){
		for(int j = i; j >= 0; j-- ){
			fprintf(out, "%s ", str[j]);
		}
		fprintf(out, "\n");
	}
	free(target);
	freestr(str, n);
	free(str);

	if(fclose(out) == EOF) termina("Errore chiusura file di scrittura");

	return 0;
}
