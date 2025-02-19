#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
// gcc -std=c11 -Wall -O -g -o

void reverse_print(const char* s){
  for(int i = strlen(s); i >= 0 ; i--){
    printf("%c", s[i]);
  }
  puts(" ");
  return ;
}

int main(int argc, char *argv[]){

  int i = 1 ;
  while(i < argc){
    reverse_print(argv[i]);
    i++ ;
  }

  return 0;
}