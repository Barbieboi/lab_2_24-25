#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  

void print_matrix(int **q , int r ,int c) ;
void free_matrix(int **q , int r ,int c ) ;

int main(int argc, char *argv[]){
    int n = 0 ;
    int e = fscanf(stdin ,"%d" , &n) ;
    if(e != 1)
        exit(1);    
    int **q = malloc(sizeof(int *) * n ) ;
    for(int i = 0; i < n ; i++){
        q[i] = malloc(sizeof(int)*n);
        for(int j = 0; j < n; j++){
            int e = fscanf(stdin, "%d", &q[i][j] );
                if(e != 1)
                    exit(1);
        }
    }

    for(int i = 0; i < n ; i++ ){
        for(int j = 0 ; j < n ; j++){
            fprintf(stdout, "\t%d", q[j][i]); 
        }
        puts("") ;
    }
    
    free_matrix(q ,n , n) ;
    return 0;
}

void free_matrix(int **q, int r, int c){
    for(int i = 0 ; i < r ; i++){
        free(q[i]); 
    }

    free(q);
}

void print_matrix(int **q, int r , int c){

    for(int i = 0; i < r ; i++ ){
        for(int j = 0 ; j < c ; j++){
            fprintf(stdout, "\t%d", q[i][j]); 
        }
        puts("") ;
    }
    return ;
}


//Versione che cambia segni nella diagonale
/*
    int p = 0 ;
    for(int i = 0; i < n ; i++){
        q[i][p] = q[i][p] * - 1 ;
        p++ ;
    }
*/

