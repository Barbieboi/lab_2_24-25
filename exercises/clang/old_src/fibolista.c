#define _GNU_SOURCE // avverte che usiamo le estensioni GNU
#include <assert.h> // permette di usare la funzione assert
#include <errno.h>
#include <stdbool.h> // gestisce tipo bool (variabili booleane)
#include <stdio.h>   // permette di usare scanf printf etc ...
#include <stdlib.h>  // conversioni stringa/numero exit() etc ...
#include <string.h>  // confronto/copia/etc di stringhe

typedef struct intero {
	long valore;
	struct intero *next;
} intero;

// prototipi
intero *fibonacci(int n);
intero *reverse(intero *lis);
long fibo(int n);
void fibo_free(intero *lis) ;
void termina(const char *messaggio);


int main(int argc, char *argv[]) {

	if (argc != 2)
	termina("Uso: main <intero maggiore di 1>");
	int n = atoi(argv[1]);
	assert(n > 1);
	intero *lis = fibonacci(n);
	assert(lis != NULL);
	intero *p = lis;
	while (p != NULL) {
	printf("%ld ", p->valore); // %ld indica che si vuole stampare un long
	p = p->next;
	}
	puts(""); // serve per andare a capo
	lis = reverse(lis) ;
	assert(lis != NULL);
	p = lis;
	while (p != NULL) {
	printf("%ld ", p->valore); // %ld indica che si vuole stampare un long
	p = p->next;
	}
	puts("");
	// deallocare lis e terminare
	fibo_free(lis);

	return 0;
}

// stampa un messaggio d'errore e termina il programma
void termina(const char *messaggio) {
	if (errno != 0)
	perror(messaggio);
	else
	fprintf(stderr, "%s\n", messaggio);
	exit(1);
}

long fibo(int n) {
	if(n <= 2)
		return 1;
	return fibo(n-1) + fibo(n-2) ;
}

intero *crea_intero(long val) {
	intero *el = malloc(sizeof(intero));
	if(el == NULL)
		exit(1);
	el->valore = val;
	el->next = NULL;
	return el;
}

intero *fibonacci(int n) {
	intero *lis = NULL;
	for (int i = 1; i <= n; i++) {
	intero *head = crea_intero(fibo(i));
	head->next = lis;
	lis = head;
	}
	return lis;
}

intero* reverse(intero* head){
	if(head == NULL)
		exit(1) ;	
	intero *prev = NULL ;
	intero *curr = head ;
	intero *prox =NULL ;	
	while(curr != NULL){
		prox = curr->next ;
		curr->next = prev ;
		prev = curr ;
		curr = prox ;
	}
	return head = prev ;
}

void fibo_free(intero* lis){
	while(lis != NULL){
		intero* tmp = lis->next ;
		free(lis);
		lis = tmp ;
	}
	return ;
}