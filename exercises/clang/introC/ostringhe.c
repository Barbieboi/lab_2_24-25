#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
// gcc -std=c11 -Wall -O -g -o


void merge(char *a[], int na, char *c[], int nc, char *b[])
{
	assert(a!=NULL);
	assert(c!=NULL);
	assert(b!=NULL);
	assert(na>0);
	assert(nc>0);
	
	int i=0; 
	int j=0; 
	int k=0; 
	while(i<na && j<nc) {
	if(strlen(a[i]) < strlen(c[j])) {
		b[k] = a[i];
		i++;
	} else {
		b[k] = c[j];
		j++;
	}
	k++;
	}
	
	while(i<na) {
	b[k] = a[i];
	i++;
	k++;
	}
	
	while(j<nc) {
	b[k] = c[j];
	j++;
	k++;
	}
	assert(i==na);
	assert(j==nc);
	assert(k==na+nc); 
}

void mergesort(char *a[], int n)
{
	assert(a!=NULL);
	assert(n>0);
	
	
	if(n==1) return;
	
	int n1 = n/2;       
	int n2 = n - n1 ;   
	assert(n1+n2==n);   
	
	mergesort(a,n1);
	mergesort(&a[n1],n2); 
	char **b = malloc(n*sizeof(char*));
	if(b==NULL) 
		exit(EXIT_FAILURE);
	merge(a,n1,&a[n1],n2,b);  

	for(int i=0;i<n;i++)
		a[i] = b[i];
	
	free(b); 
}


int main(int argc, char **argv){
	if(argc < 2)
		exit(EXIT_FAILURE);
	int n = argc-1 ;
	char **arr = malloc(n*sizeof(*arr));
	for(int i = 0; i < n ; i++)
		arr[i] = strdup(argv[i + 1]);
	mergesort(arr, n);
	for(int i = 0; i < n ; i++)
		printf("%s\n", arr[i]);

	for(int i = 0; i < n ; i++)
		free(arr[i]);
	free(arr);

	return 0;
}