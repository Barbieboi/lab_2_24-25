#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h> 


int main(int argc, char *argv[]){
    int m, n ;
    int e = fscanf(  stdin , "%d\n%d" ,  &m , &n ) ;
    if(e != 2)
        exit(EXIT_FAILURE) ;
    assert(n < m) ;
    //Allocazione spazio m * m
    int** q = malloc(sizeof(int*)*m) ;
    if(q == NULL)
        exit(EXIT_FAILURE);
    for(int i = 0 ; i < m; i++){
            q[i] = malloc(sizeof(int)*m) ;
            if(q[i] == NULL)
                exit(EXIT_FAILURE);
    }
    //riempimento matrice
    for(int i = 0; i < m ; i++){
        for(int j = 0; j < m ; j++){
            int e = fscanf(stdin, "%d", &q[i][j]);
            if(e != 1)
                exit(EXIT_FAILURE);
        }
    }
    int sum = 0;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            sum += q[i][j];
        }
    }   
    printf("%d", sum) ;

    //free
    for(int i = 0; i < m; i++){
        free(q[i]);
    }
    free(q);
    return 0;
}