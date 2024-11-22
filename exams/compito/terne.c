#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione ass
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // richiesto per usare errno
#include <math.h>
#include "terne.h"


terna *terna_crea(int a, int b, int c)
{
  terna *t = malloc(sizeof(*t));
  if(t==NULL) termina("creazione terna");
  t->x=a;
  t->y=b;
  t->z=c;
  t->left = t->right = NULL;
  return t;
}

void terna_distruggi(terna *t)
{
  free(t);
}

void terna_stampa(const terna *t, FILE *f)
{
  fprintf(f,"%d %d %d\n",t->x,t->y,t->z);
}

int terna_confronta(terna *t, terna *v)
{
  if(t->z!=v->z) return t->z - v->z;
  if(t->y!=v->y) return t->y - v->y;
  return t->x - v->x;
}  

void termina(const char *messaggio)
{
  if(errno==0) 
     fprintf(stderr,"%s\n",messaggio);
  else 
    perror(messaggio);
  exit(1);
}
