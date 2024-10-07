// scrivere qui l'email istituzionale
// e.barbin@studenti.unipi.it

#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  

typedef struct stud{
  char *nome;
  int crediti;
} studente;

studente* crea_stud(char *riga){
    assert(riga != NULL);
    //studente* s = malloc(sizeof(*s));
    studente* s = malloc(sizeof(studente));
    //prima virgola ho il nome
    s->nome = strdup(strtok(riga, ","));
    s->crediti = 0 ;
    char* tok = strtok(NULL , ",");
    while(tok != NULL){
        s->crediti += atoi(tok);
        tok = strtok(NULL , ",");
    }
    free(tok);
    return s;
}

void free_s(studente* s){
    free(s->nome);
    free(s);
}

studente** leggi_stud(FILE *stream, int *n_stud){
    assert(stream != NULL);
    int el = 0 ;
    int size = 10 ;
    studente** studenti = malloc(sizeof(studente*)*size) ;
    if(studenti == NULL)
        exit(1);
    char *buffer = NULL;
    size_t n = 0 ;
    while(true){
        ssize_t e = getline(&buffer, &n ,stream) ;
        if(e < 0){
            free(buffer);
            break ;
        }
        if(el == size){
            size =  size *2 ;
            studenti = realloc(studenti , sizeof(studente*)*size);
            if(studenti == NULL)
                exit(EXIT_FAILURE);
        }
        studenti[el] = crea_stud(buffer);
        el++ ;
        }
    studenti = realloc(studenti , sizeof(studente*)*el);
    *n_stud = el ;
    return studenti ;
}

void free_all(studente** s , int n){
    for(int i = 0; i < n ; i++){
        free_s(s[i]);
    }
    free(s);
}

void print_s(FILE* stream , studente* s){
    fprintf(stream , "%s %d\n" , s->nome , s->crediti);
}

void print_studenti(FILE* stream,studente **s, int n){
    for(int i = 0; i < n ; i++){
        print_s(stream , s[i]);
    }
}

int s_cmp(const void** a , const void** b){
    studente** sa = (studente**) a ;
    studente** sb = (studente**) b ;
    if((*sa)->crediti > (*sb)->crediti)
        return 1 ;
    if((*sa)->crediti < (*sb)->crediti)
        return -1 ;
    if((*sa)->crediti == (*sb)->crediti){
    return strcmp((*sa)->nome , (*sb)->nome  ); 
    }
    return 0 ;
}


int main(int argc, char *argv[]){
    FILE* f = fopen( argv[1] , "r");
    int n ;
    studente** my_s = leggi_stud(f, &n);
    qsort(my_s , n , sizeof(studente*), (__compar_fn_t)&s_cmp );
    
    print_studenti(stdout, my_s, n ) ;
    free_all(my_s, n);

    if(fclose(f) == EOF)
        exit(EXIT_FAILURE);
    return 0;
}