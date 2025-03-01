#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
// gcc -std=c11 -Wall -O -g -o


typedef struct pila {
	int n ;
	struct pila *next;
} stack ;

stack *push(int a, stack* s){
	stack* p = malloc(sizeof(*p));
	if(p == NULL) exit(1) ;
	p->n = a ;
	p->next = s;
	return p ;
}

int pop(stack **s){	
	if(*s == NULL) return 0 ;
	stack *tmp = *s ;
	(*s) = (*s)->next ;	
	int res = tmp->n ;
	free(tmp);
	return res ;
}

int peek(const stack *s){
	return s==NULL?0:s->n ;
}

int length(const stack *s){
	if(s == NULL) return 0 ;
	else return 1 + length(s->next);
}

void print(const stack *s, FILE *f){
	while(s != NULL){
		fprintf(f, "%d ", s->n);
		s = s->next;
	}
}

int main(int argc, char **argv){
	
	stack *p = NULL ;
	int n , prev , pprev ;
    n = prev = pprev = 1 ;
    while(true){
        int e = fscanf(stdin, "%d", &n) ;
        if(e != 1) 
            exit(1);
        if(n != 0){
            if(n%3==0){
                p = push(n/3 ,p); 
            }
            else  p = push( n,p) ;
        }
        if(n == 0){
			if(peek(p)%2 != 0 || length(p) > 3){
                pop(&p);
            }
            if(pprev == 0 && prev == 0){   
                break ; 
            }
        }
        pprev = prev ;
        prev = n ;
    }

	print(p , stdout);
	printf("%d\n", length(p));

	return 0;
}

/*
Utilizzando l'implementazione vista a lezione delle liste concatenate, si deve implementare una struttura dati rappresentante una pila ( struttura dati LIFO ) e una serie di funzioni che permettono le seguente operazioni:

-push - inserisce un elemento nella pila
-pop - rimuove il primo elemento dalla pila e lo ritorna. Deve tornare il valore 0 se la pila è vuota.
-peek - restituisce il valore del primo elemento della pila senza rimuoverlo. Deve tornare il valore 0 se la pila è vuota.
-length - calcola la lunghezza della pila in modo ricorsivo
-print - stampa gli elementi della pila , iniziando con l'elemento in testa (vedi esempio), in modo ricorsivo


Scrivere una funzione Main che legge da standard input una serie di numeri interi e, utilizzando le funzioni definite sopra, esegue le seguenti operazioni:

-Se il numero è diverso da zero ed è un multiplo di 3, viene inserito nella pila il numero diviso 3
-Se il numero è diverso da 0 e non è un multiplo di 3, viene inserito in pila
-Se il numero è 0, viene eliminato un elemento dalla pila , solo se l'elemento da eliminare è dispari o la pila attualmente contiene più di 3 elementi.
-Il programma si ferma quando si leggono tre valori 0 di seguito

Alla fine della funzione Main, deve essere stampato in stdout il contenuto della pila e la sua lunghezza, con tutti gli elementi della pila su un'unica riga, separati da uno spazio, e la lunghezza della pila come ultimo valore.



Esempio di input:
2
56
-3
5
897
432
0
19
-54
0
45
0
0
0

Esempio di output:

5 -1 56 2 4

*/
