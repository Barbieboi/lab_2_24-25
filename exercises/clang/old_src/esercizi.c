#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  





/*

char *product(char* str, int k){
    if(str == NULL)
        exit(1) ;
    char *res = malloc(sizeof(str)*k+1) ;
    res[0] = '\0' ;
    if(res == NULL)
        exit(1) ;
    for(int i = 0; i < k ; i++){
    strcat(res, str) ;
    }
    return res; 
}


int main(int argc, char *argv[]){
    char s[1000] ;
    int n ;
    if(scanf("%s", s) != 1 )
        exit(1) ;
    if(scanf("%d" , &n)!= 1 )
        exit(1)  ;
    char *res = product(s, n) ;
    printf("%s", res) ;
    free(res) ;
    return 0;
}

*/

/*

void tswap(int *x, int *y, int *z){
    int tmp = *z ;
    *z = *y ;
    *y = *x ;
    *x = tmp ;
}

int main(int argc, char *argv[]){
    int a , b , c ;
    a = b = c = 0 ;
    int e = scanf("%d %d %d", &a , &b, &c) ;
    if(e != 3){ exit(1) ; }
    tswap(&a , &b, &c) ;
    fprintf(stdout, "%d\n%d\n%d\n", a, b, c) ;
    return 0;
}

*/

//Ordinare stringhe alfabeticamente
/*

void sort(char** arr, int n){
    //char **res = malloc(sizeof(arr));
    if(arr == NULL) 
        exit(1) ;  
    char *tmp ;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++) {
            if(strcmp(arr[i], arr[j]) < 0) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main(int argc, char *argv[]){
    int n ;
    if(scanf("%d", &n) != 1 ){exit(1) ;} 
    char **val = malloc(n) ;
    if(val == NULL)
        exit(1) ;
    for(int i = 0 ; i < n ; i++){
        if(scanf("%ms", &val[i])!=1)
            exit(1) ;
    }
    
    sort(val , n) ;

    for(int i = 0 ; i < n ; i++){
        printf("%s\n", val[i]) ;
    }


    for(int i = 0 ; i < n ; i++){
        free(val[i]) ;
    }

    free(val);

    return 0;
}

*/

