#define _GNU_SOURCE
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int cmp_triple(tripla *t_1, tripla *t_2) {
  int val_1 = t_1->primo + t_1->secondo + t_1->terzo;
  int val_2 = t_2->primo + t_2->secondo + t_2->terzo;
  if (val_1 < val_2)
    return -1;
  else if (val_1 > val_2)
    return 1;
  else if (val_1 == val_2) {
    if (t_1->primo < t_2->primo)
      return -1;
    else if (t_1->primo > t_2->primo)
      return 1;
    else if (t_1->primo == t_2->primo) {
      if (t_1->secondo < t_2->secondo)
        return -1;
      else if (t_1->secondo > t_2->secondo)
        return 1;
      else if (t_1->secondo == t_2->secondo) {
        if (t_1->terzo < t_2->terzo)
          return -1;
        else if (t_1->terzo > t_2->terzo)
          return 1;
        else if (t_1->terzo == t_2->terzo)
          return 0;
      }
    }
  }
  return 0;
}

void merge(tripla *a[], int na, tripla *c[], int nc, tripla *b[],
           int (*cmp)(tripla *x, tripla *y)) {
  assert(a != NULL);
  assert(c != NULL);
  assert(b != NULL);
  assert(na > 0);
  assert(nc > 0);

  int i = 0; // indice per a[]
  int j = 0; // indice per c[]
  int k = 0; // indice per b[]

  // scorro a[] e c[] e copio il minore in b[]
  while (i < na && j < nc) {
    // guardo se il nome di a[i] è minore del nome c[j]
    // if( strcmp(a[i]->nome,c[j]->nome) < 0 ) { // oridnamento lessicografico
    // per nome
    if (cmp(a[i], c[j]) <
        0) { // unica istruzione da modificare per cambiare l'ordinamento
      b[k] = a[i];
      i++;
    } else {
      b[k] = c[j];
      j++;
    }
    k++;
  }

  // copio il resto di a[] in b[]
  while (i < na) {
    b[k] = a[i];
    i++;
    k++;
  }

  // copio il resto di c[] in b[]
  while (j < nc) {
    b[k] = c[j];
    j++;
    k++;
  }
  // asserzioni aggiunte da GM perché non si sa mai
  assert(i == na);
  assert(j == nc);
  assert(k == na + nc);
}

void mergesort(tripla *a[], int n, int (*cmp)(tripla *x, tripla *y)) {
  assert(a != NULL);
  assert(n > 0);

  // caso base
  if (n == 1)
    return;

  int n1 = n / 2;  // dimesione prima parte
  int n2 = n - n1; // dimensione seconda parte

  mergesort(a, n1, cmp);
  mergesort(&a[n1], n2, cmp); // &a[n1] potevo scriverlo a+n1

  // ho le due metà ordinate devo fare il merge
  tripla **b = malloc(n * sizeof(*b));
  if (b == NULL)
    termina("malloc fallita nel merge");
  merge(a, n1, &a[n1], n2, b, cmp);
  // copio il risultato da b[] ad a[]
  for (int i = 0; i < n; i++)
    a[i] = b[i]; // sto copiando dei puntatori

  free(b);
}

int main(int argc, char *argv[]) {
  FILE *f = fopen(argv[1], "r");
  if (f == NULL)
    termina("failed opening input file");
  int n_triple;
  tripla **triple = leggi_triple(f, &n_triple);

  mergesort(triple, n_triple, &cmp_triple);

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