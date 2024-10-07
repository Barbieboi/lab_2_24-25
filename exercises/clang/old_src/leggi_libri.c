#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  

typedef struct libro{
    char *titolo ;
    char *autore ;
    int anno;
    int copie;
}libro_t ;

void print_libro(libro_t* libro){
    printf("%s di %s (%d)\n" , libro->titolo, libro->autore , libro->anno );
}

void print_libri(libro_t* libri, int size){
    for(int i = 0 ; i < size; i++){
        print_libro(&libri[i]);
    }
}

libro_t crea_libro(char *riga ){
    libro_t libro  ;
    char *token ;
    char delim[2] = "," ;
    token = strtok(riga, delim);
    libro.titolo = strdup(token) ;
    token = strtok(NULL, delim);
    libro.autore = strdup(token);
    token = strtok(NULL, delim);
    libro.anno = atoi(token);
    token = strtok(NULL, delim);
    libro.copie = atoi(token);
    return libro ;
}

//Crea array di libri, legge da stream
libro_t* libri(FILE *stream , int *nmeb){
    int el = 0 ;
    int size = 10 ;
    libro_t* libri = malloc(sizeof(libro_t)*size) ;
    if(libri == NULL)
        exit(1);
    char *buffer = NULL;
    size_t n = 0 ;
    libro_t* tmp = malloc(sizeof(libro_t)) ;
    while(true){
        ssize_t e = getline(&buffer, &n ,stream) ;
        if(e < 0){
            free(buffer);
            break ;
        }
        if(el == size){
            if(size >= 100){
                free(buffer);
                break ;
                }
            size += 10 ;
            libri = realloc(libri , sizeof(libro_t)*size);
            if(libri == NULL)
                exit(1);
        }
        *tmp = crea_libro(buffer);
        if(tmp->copie == 0){
            libri[el] = *tmp;
            el++ ;
        }else{
            free(tmp->titolo);
            free(tmp->autore);
        }
    }
    free(tmp);
    libri = realloc(libri , sizeof(libro_t)*el);
    *nmeb = el ;
    return libri ;
}

void free_libri(libro_t *libri, int size){
        for(int i = 0 ; i < size; i++){
        free(libri[i].titolo) ;
        free(libri[i].autore) ;
    }
    free(libri);
}

int libri_cmp(const void *a , const void *b){
    libro_t* lib_a = (libro_t*) a ;
    libro_t* lib_b = (libro_t*) b ;
    if(lib_a->anno > lib_b->anno)
        return -1 ;
    if(lib_a->anno < lib_b->anno)
        return 1 ;
    return 0 ;
}

int main(int argc, char *argv[]){
    FILE* f = fopen("libri.txt", "r") ;
    if(f == NULL)
        exit(1);
    int n_books; 
    libro_t* books = libri(f,  &n_books );
    qsort(books, n_books ,sizeof(libro_t), (__compar_fn_t) &libri_cmp) ;
    print_libri(books, n_books);
    free_libri(books, n_books);
    if(fclose(f) == EOF)
        exit(1);
    return 0;
}