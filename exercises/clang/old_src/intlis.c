#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>     

#include"intlis.h"


int_list* create_node(int val){
    int_list* res = malloc(sizeof(int_list));
    if(res == NULL)
        exit(EXIT_FAILURE);
    res->val = val ;
    res->next = NULL ;
    return res ;
}

//Ascending order
void ins_list(int_list **head_ref, int_list *in){
    
    if(*head_ref == NULL){
        *head_ref = in ;
        return ;
    }
    //inserimento in testa?
    if(in->val <= (*head_ref)->val){
        in->next = *head_ref ;
        *head_ref = in ;
        return ;
    }

    int_list* curr = *head_ref;
    
    //in mezzo?
    while(curr->next != NULL){
        if(in->val > curr->val && in->val <= curr->next->val){
            in->next = curr->next;
            curr->next = in ;
            break; 
        }
        curr = curr->next ;
    }
    //in coda?
    if(curr->next == NULL){
        curr->next = in ;
        in->next = NULL;
    }
    return ;
}

int_list* create_list(int len){
    int_list* head = NULL ;
    int_list *tmp ;
    for(int i = 0 ; i < len ; i++){
        tmp = create_node(random() % MAX );
        ins_list(&head ,tmp);
    } 
    return head; 
}

void reverse_list(int_list** head_ref){
    int_list* prev = NULL;
    int_list* current = *head_ref;
    int_list* prox = NULL;
    while (current != NULL) {
        prox = current->next;
        current->next = prev;
        prev = current;
        current = prox;
    }
    *head_ref = prev;
}

//Elimina tutti i numeri che soddisfano f
void delete_lis(int_list**head , bool(*f)(int)){ 
    if (*head == NULL)
        return ;  
    // Until the head data is equal to the key move the head 
    // pointer 
    while(*head != NULL  && f((*head)->val)){
        int_list *tmp = *head ;
        *head = (*head)->next ;
        free(tmp);
    } 
    int_list *c = *head, *prev = NULL; 
    while(c){ 
        int_list* prox = c->next ;
        if(f(c->val)){
            assert(prev != NULL); 
            prev->next = prox;
            free(c);
        }
        else{
            prev = c; 
        }
        c = prox; 
    } 
}


void free_list(int_list* list){
    int_list* p = list ;
    while(p != NULL){
        int_list* tmp = p ;
        p = p->next ;
        free(tmp);
    }
}

void print_list(int_list* list){
    if(list == NULL){
        puts("");
        return;}
    printf("%d ", list->val);
    print_list(list->next);
}

