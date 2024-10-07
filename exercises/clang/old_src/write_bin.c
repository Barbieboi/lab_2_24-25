#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  

int main(int argc, char *argv[]){
    
    FILE *f = fopen(argv[1], "w");
    if(f == NULL)
        exit(EXIT_FAILURE);

    int n ;
    while(true){
        int e = fscanf(stdin, "%d" ,&n);
        if(e != 1)
            exit(EXIT_FAILURE);
        if(n == 11111)
            break;
        fwrite(&n ,sizeof(int), 1, f) ;
    }

    if(fclose(f)==EOF)
        exit(1);
    return 0;
}