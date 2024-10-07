#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
// gcc -std=c11 -Wall -O -g -o

int main(int argc, char *argv[]){
  int lun = 0 ;
  for(int i = 1 ; i< argc; i++){
    lun += strlen(argv[i]);
  }

  //valgrind si arrabbiava con una malloc classica, mystring non risultava inizializzata
  char *mystring = calloc(lun + 1,1);
  if(mystring == NULL){
    exit(3);
  }

  int z = 0 ;
  for(int i = 1 ; i < argc ;i++){
    for(int j = 0 ; j < strlen(argv[i]); j++){
      mystring[z] = argv[i][j] ;
      z++;
    }

  }

  printf("stringa concatena: %s\n",mystring);

  free(mystring);

  return 0;
}