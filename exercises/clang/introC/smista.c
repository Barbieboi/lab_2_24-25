#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
// gcc -std=c11 -Wall -O -g -o

void termina(const char *messaggio){
	if(errno != 0) perror(messaggio);
	else fprintf(stderr, "%s\n", messaggio);
	exit(EXIT_FAILURE);
}

bool primo(int k) {
  if(k%2==0 && k!=2) return false;
  for(int i=3; i*i<=k; i+=2) {
    if(k%i==0) return false;
  }
  return true;
}


int main(int argc, char **argv){
	if(argc != 3) termina("Argomenti Errati");
	char *nome = argv[1];
	int N = atoi(argv[2]);
	for(int i = 1; i < N; i++){
		if(primo(i)){
			char *s_primo = NULL;
			int e = asprintf(&s_primo, "%d" , i);
			if(e == -1) termina("Errore asprintf");

			char *nome_file = NULL ;
			e = asprintf(&nome_file , "%s.%c.primi", nome,s_primo[strlen(s_primo) - 1]);
			if(e == -1) termina("Errore asprintf");

			FILE *f = fopen(nome_file, "a");
			if(f == NULL) termina("Errore apertura file");
			fprintf(f, "%d\n", i);
			if(fclose(f)==EOF) termina("Errore chiusura file");
			
			free(s_primo);
			free(nome_file);
		}
	}

	return 0;
}