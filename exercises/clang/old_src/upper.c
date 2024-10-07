#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>
#include <ctype.h>


//Converte in maiuscolo le stringhe passate sulla linea di comando

void termina(char *messaggio)
{
  if(errno!=0) perror(messaggio);
    else fprintf(stderr,"%s\n", messaggio);
  exit(1);
}

//Prende una stringa e ritorna la stessa in maiuscolo dentro buf
void upper_case(char* s, char* buf){
    char *res = malloc(strlen(s));
    res = strdup(s) ;
    int i = 0 ;
    while(i < strlen(res) && res[i] != '\0' ){
        res[i] = toupper(res[i]) ;
        i++ ;
    }
    strcpy(buf, res) ;
    free(res) ;
}

int main(int argc, char * argv[]){
    if(argc <2)
        termina("not enough args");
    
    char *file_name = argv[1] ;

    //Versione con "argv[1].txt"
    /*
    char *file_name = malloc(strlen(argv[1]) +5) ;
    strcpy(file_name, strcat(argv[1],".txt"));
    */ 
    FILE *f = fopen(file_name, "wt") ;
    if(f == NULL) termina("error opening file");
    char * my_str = malloc(20) ;
    for(int j = 2; j < argc ; j++){
        upper_case(argv[j], my_str);
        fprintf(f , "%s %s\n", argv[j], my_str ) ;
    }

    /*
    free(file_name) ;
    */
    
    free(my_str) ;
    if(fclose(f)==EOF)
        termina("Error closing file") ;
    return 0 ;
}
