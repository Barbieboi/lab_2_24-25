#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  

void stampa_array(int *a, int n) {
  assert(a != NULL);
  // stampo il contenuto dell'array
  for (int i = 0; i < n; i++){ 
    fprintf(stdout, "%8d", a[i]); } // stampo gli elementi in un campo di 8 caratteri
    fprintf(stdout, "\n") ;
}

void termina(char *messaggio)
{
  // se errno!=0 oltre al mio messaggio stampa il messaggio
  // associato alla variabile globale errno 
  // utilizzando la funzione di libreria perror()
  if(errno!=0) perror(messaggio);
  // altrimenti stampa solo il mio messaggio
  else fprintf(stderr,"%s\n", messaggio);
  exit(1);
}

int *leggi_file(FILE *f, int *num_elementi)
{
assert(f!=NULL); // il file deve essere valido
int size=10; // dimensione attuale dell'array
int messi=0; // numero di elementi attualmente nell'array
int *a = malloc(size*sizeof(int));
if(a==NULL)
  termina("Memoria insufficiente");
  
while(true) {
  int n;
  int e = fscanf(f,"%d",&n);
  if(e==EOF) break;
  if(e!=1) termina("Contenuto illegale nel file");
  if(messi==size) {
      size = size*2;
      a = realloc(a,size*sizeof(int));
      if(a==NULL)
        termina("realloc fallita");
  }
  assert(size>messi);
  a[messi] = n;
  messi += 1;
}
  size = messi;
  a = realloc(a,size*sizeof(int));
  if(a==NULL)
    termina("realloc fallita");  
  *num_elementi = messi;
  return a;  
} 

int *elabora(int a[], int n , int k, int *nuovon){
    int *res ;
    bool neg = false ;
    if(k == 0){
        *nuovon = n ;
        res = malloc(sizeof(int)*n);
        for(int i = 0; i < n ; i++){
            res[i] = 0 ;
        }
        return res ;
    }
    if(k < 0){
        k = abs(k) ;
        neg = true ;
    }
    res = malloc(sizeof(int)*(n*k)) ;
    int j = 0 ;
    int v ;
    for(int i = 0; i < n; i++){
        v = 1 ;
        while(v <= k && j < n*k){
            res[j] = a[i] ;
            v++ ;
            j++ ;
        }
    }
    *nuovon = n*k ;
    if(neg){ 
        int *tmp = malloc(sizeof(int)*(n*k)) ;
        for(int i = 0; i < n*k ; i++){
            tmp[i]=res[(n*k)-1 -i] ;
        }
        free(res) ;
        return tmp;
    }
    return res ;
}

int main(int argc, char *argv[]){
    FILE* f = fopen(argv[1], "r") ;
    if(f == NULL)
        exit(1) ;
    int n ;
    int m ;
    int *arr = leggi_file(f,&n) ;
    int *p_arr = NULL ; 
    for(int i = 2; i < argc ; i++){
        p_arr = elabora(arr, n ,atoi(argv[i]) , &m ) ;
        stampa_array(p_arr, m);
        free(p_arr);
    }
    free(arr);
    fclose(f) ;
    return 0;
}


    //Versione Bonk
    //Non usare %s così a buffo ,al massimo usa %11s 
    //int n ;
    //char s[12];
    //int e = scanf("%d %11s" ,&n , s ) ;
    //if(e!=2) exit(1);
    //printf("a=%d, s=%s\n", n , s ) ;
    //Meglio usare %ms
    //int a =1 ;
    //char s[12];
    //char *z = NULL; 
    //    //&z importante 
    //int e = scanf("%d %11s %ms" , &a , s ,  &z) ;
    //if(e != 3) exit(1) ;
    //printf("a = %d , s = %s , z = %s\n" , a, s ,z) ;
    //free(z);

    /*
    int n = 5;
    int k = -3;
    int m ;
    int *arr = malloc(sizeof(int)*n);
    for(int i = 0; i < n ; i++){
        arr[i] = i + 1 ;
    }
    stampa_array(arr, n );
    int *res = elabora(arr, n , k , &m) ;
    if(k == 0){k = 1 ;}
    else if(k < 0){ k = abs(k) ; }
    stampa_array(res, n*k ) ;
    */
   
