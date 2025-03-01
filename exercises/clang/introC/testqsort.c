#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
// gcc -std=c11 -Wall -O -g -o


int mycmp(const void* a,const void *b){
	int *pa = (int*)a;
	int *pb = (int*)b; 
	return *pa>*pb?1:-1 ;

}

int main(int argc, char **argv){
	if(argc == 1)exit(1);
	int *a = malloc(sizeof(int)*argc-1);
	for(int i = 0; i < argc - 1; i++)
		a[i] = atoi(argv[i+1]);
	qsort(a, argc-1, sizeof(*a), (comparison_fn_t)mycmp );
	for(int i = 0 ; i < argc - 1; i++)
		printf("%d\n", a[i]);

	free(a);

	return 0;
}