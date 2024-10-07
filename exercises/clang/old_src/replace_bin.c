#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  


int main(int argc, char *argv[]){ 
    FILE* f = fopen("f.dat", "r+") ;
    if(f == NULL)   
        exit(EXIT_FAILURE);

    int err = fseek(f , 0, SEEK_END);
    if(err != 0)
        exit(EXIT_FAILURE);
    long l_file = ftell(f);
    if(l_file < 0 || l_file%4 != 0)
        exit(EXIT_FAILURE);
    //numeri interi a 4 byte
    int n = l_file/4;
    
    rewind(f);
    int e ;
    size_t m ;
    for(int i = 1; i <= n; i++){
        m = fread(&e ,sizeof(int), 1 ,f);
        if(m != 1)
            exit(EXIT_FAILURE);
        if(i % 2 == 0 && e < 0){
            fseek(f, -4 , SEEK_CUR);
            e = -e ;
            fwrite(&e, sizeof(int), 1 ,f);
        }
    } 

    if(fclose(f)==EOF)
        exit(EXIT_FAILURE);

    return 0;
}
