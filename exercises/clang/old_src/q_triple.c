#define _GNU_SOURCE // avverte che usiamo le estensioni GNU
#include <assert.h> // permette di usare la funzione assert
#include <errno.h>
#include <stdbool.h> // gestisce tipo bool (variabili booleane)
#include <stdio.h>   // permette di usare scanf printf etc ...
#include <stdlib.h>  // conversioni stringa/numero exit() etc ...
#include <string.h>  // confronto/copia/etc di stringhe

void termina(char *messaggio) {
  if (errno != 0)
    perror(messaggio);
  else
    fprintf(stderr, "%s\n", messaggio);
  exit(1);
}

typedef struct {
  int primo;
  int secondo;
  int terzo;
} tripla;

void stampa_tripla(tripla *t, FILE *stream) {
  fprintf(stream, "%d %d %d\n", t->primo, t->secondo, t->terzo);
}

void stampa_all(tripla **t, int n, FILE *stream) {
  for (int i = 0; i < n; i++) {
    stampa_tripla(t[i], stream);
  }
}

void free_all(tripla **t, int n) {
  for (int i = 0; i < n; i++) {
    free(t[i]);
  }
  free(t);
}

tripla *make_tripla(int primo, int secondo, int terzo) {
  tripla *t = malloc(sizeof(tripla));
  if (t == NULL)
    termina("Errore malloc");
  t->primo = primo;
  t->secondo = secondo;
  t->terzo = terzo;
  return t;
}

tripla **leggi_triple(FILE *stream, int *num_triple) {
  if (stream == NULL)
    termina("stream null");
  int size = 10;
  tripla **triple = malloc(size * sizeof(tripla *));
  if (triple == NULL)
    termina("failed malloc");
  int primo, secondo, terzo;
  int i = 0;
  while (true) {
    int e = fscanf(stream, "%d %d %d", &primo, &secondo, &terzo);
    if (e == EOF)
      break;
    else if (e != 3) {
      termina("illegal content");
    }
    if (i >= size) {
      size *= 2;
      triple = realloc(triple, size * sizeof(tripla *));
      if (triple == NULL)
        termina("realloc fallita");
    }
    triple[i] = make_tripla(primo, secondo, terzo);
    i++;
  }
  triple = realloc(triple, (i + 1) * sizeof(tripla *));
  *num_triple = i;
  return triple;
}

int cmp_triple(tripla *t1, tripla *t2) {
  int val_1 = t1->primo + t1->secondo + t1->terzo;
  int val_2 = t2->primo + t2->secondo + t2->terzo;
  if (val_1 < val_2)
    return -1;
  else if (val_1 > val_2)
    return 1;
  else if (val_1 == val_2) {
    if (t1->primo < t2->primo)
      return -1;
    else if (t1->primo > t2->primo)
      return 1;
    else if (t1->primo == t2->primo) {
      if (t1->secondo < t2->secondo)
        return -1;
      else if (t1->secondo > t2->secondo)
        return 1;
      else if (t1->secondo == t2->secondo) {
        if (t1->terzo < t2->terzo)
          return -1;
        else if (t1->terzo > t2->terzo)
          return 1;
        else if (t1->terzo == t2->terzo)
          return 0;
      }
    }
  }
  return 0;
}

int cmp_p(tripla **a, tripla **b) { return cmp_triple(*a, *b); }

int main(int argc, char *argv[]) {
  if (argc != 3) {
    termina("uso: ./triple $file_lettura $file_scrittura");
  }
  FILE *f = fopen(argv[1], "r");
  if (f == NULL)
    termina("failed opening input file");
  int n_triple;
  tripla **triple = leggi_triple(f, &n_triple);

  qsort(triple, n_triple, sizeof(*triple), (__compar_fn_t)&cmp_p);

  FILE *out = fopen(argv[2], "w");
  if (out == NULL)
    termina("failed opeing output file");

  stampa_all(triple, n_triple, out);

  if (fclose(f) == EOF)
    termina("fclose failed");
  if (fclose(out) == EOF)
    termina("fclose failed");
  free_all(triple, n_triple);
  return 0;
}
