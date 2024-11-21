/*
Scrivere un programma che legge da standard input una stringa e 
che stampi in output il valore intero 1 se è palindroma 
(altrimenti stampi il valore intero 0).
Una stringa è palindroma se la sequenza di caratteri non cambia l
eggendola da sinistra verso destra o da destra verso sinistra.
La stringa vuota deve essere considerata palindroma.

Esempi di stringhe palindrome sono: osso, oro, afa, radar, anilina, ottetto, ingegni.
*/

#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
// gcc -std=c11 -Wall -O -g -o

int palindroma(char *s){
	int i = 0 ;
	int j = strlen(s) - 1 ;
	while(j > i){
		if(s[i] != s[j] ) return 0 ;
		i++ ; j-- ;
	}
	return 1 ;
}

int main(int argc, char **argv){

	printf("%s palidroma? %s\n", argv[1], palindroma(argv[1])==1?"Si":"No");

	return 0;
}