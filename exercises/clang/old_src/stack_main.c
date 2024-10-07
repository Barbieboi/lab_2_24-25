#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h> 
#include"stack.h"

int main(int argc, char *argv[]){

    stack_t *pila = NULL ;
    int n , prev , pprev ;
    n = prev = pprev = 1 ;
    while(true){
        int e = fscanf(stdin, "%d", &n) ;
        if(e != 1) 
            exit(1);
        if(n != 0){
            if(n%3==0){
                push(&pila, n/3); 
            }
            else push(&pila, n) ;
        }
        if(n == 0){
            if(prev == 0 && pprev == 0){   
                pop(&pila) ;
                break ; 
            }
            if(peek(pila)%2 != 0 || length(pila) > 3){
                pop(&pila);
            }
        }
        pprev = prev ;
        prev = n ;
    }
    
    print_stack(pila, stdout);
    fprintf(stdout, "%d\n" , length(pila));
    return 0;
}

