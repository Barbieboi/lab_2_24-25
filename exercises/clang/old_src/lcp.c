#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>

int lcp(char *s1 , char *s2){
    int i = 0 ;
    while (s1 && s2 && *s1 == *s2 ){
        s1++ ;
        s2++ ;
        i++ ;
    }
    return i ;
}

int main(int argc, char *argv[]){
    
    int n ; 
    int e = fscanf(stdin, "%d" ,&n) ;
    if(e != 1)
        exit(1);
    char **s = malloc(sizeof(char*)*n);
    for(int i = 0; i < n; i++ ){
        int e = fscanf(stdin, "%512ms" , &s[i]) ;
        if(e != 1)
            exit(1);
    }
    for(int i = 1; i < n; i++){
    fprintf(stdout, "%d\n", lcp(s[i - 1], s[i]));
    }
    for(int i = 0 ; i < n; i++){
        free(s[i]);
    }
    free(s);
    return 0;
}