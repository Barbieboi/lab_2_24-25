#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
// gcc -std=c11 -Wall -O -g -o

/*
Testo Compito del 25/10
Aggregazione dei criteri
Esercizio 1 Scrivere un programma tabelline che invocato scrivendo

tabelline n1 n2 n2 ....
per ogni intero N sulla linea di comando crea il file N.tab contenente la tabellina (i multipli da 1 a 10) del numero N. Ad esempio scrivendo

tabelline 4 20
deve essere creato il file 4.tab contenente la sequenza

4
8
12
16
20
24
28
32
36
40
ed il file 20.tab contenente la sequenza

20
40
60
80
100
120
140
160
180
200
I file di output devono chiamarsi esattamente come indicato, e contenere esattamente i valori richiesti con un valore su ogni riga. Il programma deve accettare un qualsiasi numero di argomenti sulla linea di comando. Verificate con valgrind il corretto uso e deallocazione della memoria

*/


void termina(char *messaggio) {
  if (errno != 0)
    perror(messaggio);
  else
    fprintf(stderr, "%s\n", messaggio);
  exit(1);
}

int main(int argc, char **argv){
  if(argc == 1) termina("Uso: ./tabelline n1 n2 ...") ;
  for(int i = 1; i < argc ; i++){
      int n = atoi(argv[i]);
      char *nomefile = NULL ;
      int e = asprintf(&nomefile, "%d.tab", n);
      if(e == -1) termina("Errore asprintf");

      FILE *f = fopen(nomefile, "w");
      if(f == NULL) termina("Errore apertura file");

      for(int j = 1 ; j <=10; j++){
        fprintf(f, "%d\n", n*j);
        }

      if(fclose(f)==EOF) termina("Errore chiusura file");
  }
  

	return 0;
}
