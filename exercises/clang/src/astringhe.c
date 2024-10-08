#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
// gcc -std=c11 -Wall -O -g -o

char *copia_ribalta(const char *s);

int main(int argc, char **argv){
	
	if(argc < 2)
		exit(EXIT_FAILURE);
	char **a;
	int n = argc - 1;
	a = malloc(n*sizeof(char*));
	if( a==NULL)
		exit(EXIT_FAILURE);
	for(int i = 0 ; i < n ; i++)
		a[i] = copia_ribalta(argv[i+1]);
	puts("-----------------------");	
	for(int i = 0; i < n ; i++)
		puts(a[i]);
	puts("-----------------------");	
	for(int i = 0; i < n; i++)
		free(a[i]);

	free(a);

	return 0;
}


char *copia_ribalta(const char *s){
	assert(s!=NULL);
	char *res = malloc(strlen(s)+1);
	res[strlen(s)] = '\0';
	int j = 0;
	for(int i = strlen(s) - 1; i >= 0 ; i--)
		res[j++] = s[i];
	assert(strlen(s)==strlen(res));
	return res;
}