#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h> 

void printarr(int *a, int l){
	for(int i = 0; i < l ; i++){
		printf("%d\t", a[i]);
	}
	puts("");
}
//commento
int main(int argc, char *argv[]){

	int N;
	printf("Inserisci N:");
	int e = scanf("%d" , &N);
	if(e != 1){ exit(1); }

	int *a = malloc(N/2 * sizeof(int));
	int *b = malloc(N/2 * sizeof(int));
	
	int n = 1 ; 
	int a_index= 0 ; int b_index = 0 ;
	while(n <= N){
		if(n % 3 == 0 && n % 5 != 0){
			a[a_index] = n ;
			a_index++ ;
		}
		else if(n % 3 != 0 && n % 5 == 0){
			b[b_index] = n ;
			b_index++;
		}
		n++;
	}
	
	int a_sum = 0 ;
	int b_sum = 0 ;
	for(int i = 0 ; i < a_index; i++){
		a_sum += a[i];
	}	
	for(int i = 0 ; i < b_index; i++){
		b_sum += b[i];
	}
	printf("lunghezza a[] = %d\tsomma a[] = %d\n", a_index, a_sum);
	printf("lunghezza b[] = %d\tsomma b[] = %d\n", b_index, b_sum);

	free(a);
	free(b);

	return 0;
}

