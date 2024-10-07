#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
#include"stack.h"

void push(stack_t** pila_ref, int n){
    stack_t *new_testa = malloc(sizeof(stack_t));
    if(new_testa == NULL)
        exit(1);
    new_testa->val = n ;
    if(*pila_ref == NULL){
        new_testa->next = NULL;
    }
    new_testa->next = *pila_ref;
    *pila_ref = new_testa ;
}
int pop(stack_t** pila_ref){
    if(*pila_ref == NULL)
        return 0;
    int res = (*pila_ref)->val ;
    stack_t* tmp = *pila_ref ;
    *pila_ref = (*pila_ref)->next;
    free(tmp) ;
    return res;
}
int peek(const stack_t* pila){
    if(pila == NULL)
        return 0;
    return pila->val ;
}
int length(const stack_t* pila){
    if(pila == NULL)
        return 0 ;
    return 1 + length(pila->next);
}
void print_stack(const stack_t* pila, FILE* stream){
    if(pila == NULL)
        return ;
    fprintf(stream, "%d " , pila->val);
    print_stack(pila->next, stream);
}