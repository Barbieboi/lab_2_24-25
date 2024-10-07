#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
#include"intlis.h"

void termina(char *messaggio);
bool pari(int n){
    return n%2==0;
}
bool mul_3(int n){
    return n%3==0 ;
}

int main(int argc, char *argv[]){
    if(argc != 2)
        termina("Uso: ./int_list n");
    int_list *mylist = create_list(atoi(argv[1]));
    print_list(mylist);
    puts("-------------------");
    
    delete_lis(&mylist, &pari );
    
    print_list(mylist);
    free_list(mylist);
    return 0;
}

void termina(char *messaggio){
  if(errno!=0) perror(messaggio);
  else fprintf(stderr,"%s\n", messaggio);
  exit(EXIT_FAILURE);
}
