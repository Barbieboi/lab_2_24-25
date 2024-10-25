// scrivere qui l'email istituzionale

// e.barbin@studenti.unipi.it

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

int *leggi_file(FILE *f, int *num_elementi) {
  assert(f != NULL); // il file deve essere valido
  int size = 10;     // dimensione attuale dell'array
  int messi = 0;     // numero di elementi attualmente nell'array
  int *a = malloc(size * sizeof(int));
  if (a == NULL)
    termina("Memoria insufficiente");
  while (true) {
    int n;
    int e = fscanf(f, "%d", &n);
    if (e == EOF)
      break;
    if (e != 1)
      termina("Contenuto illegale nel file");
    // ho letto un intero dal file ed è stato messo in n
    if (messi == size) {
      // ingrandisco l'array
      size = size * 2;
      a = realloc(a, size * sizeof(int));
      if (a == NULL)
        termina("realloc fallita");
    }
    assert(size > messi);
    a[messi] = n;
    messi += 1;
  }
  // ho messo tutti gli elementi che mi interessavano
  size = messi;
  a = realloc(a, size * sizeof(int));
  if (a == NULL)
    termina("realloc fallita");
  // salvo il numero di elementi e restituisco l'array
  *num_elementi = messi;
  return a;
}

int find_max(int *a, int n) {
  int max = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > max)
      max = a[i];
  }
  return max;
}

int my_sum(int a[], int k) {
  int s = 0;
  for (int i = 0; i < k; i++) {
    s += a[i];
  }
  return s;
}

int somme(int a[], int n, int range) {
  int s = 0;
  if (range == 0) {
    return s = my_sum(a, n);
  } else if (abs(range) > n) {
    return s = my_sum(a, n);
  } else if (range > 0 && range < n) {
    return s = my_sum(a, range);
  } else if (range < 0 && abs(range) < n) {
    int i = n - 1;
    int d = 0;
    while (d < abs(range) && i >= 0) {
      s += a[i];
      i--;
      d++;
    }
    return s;
  }
  return s;
}

int main(int argc, char *argv[]) {
  if (argc <= 2)
    exit(1);
  FILE *f = fopen(argv[1], "r");
  if (f == NULL)
    exit(1);
  int n;
  int *a = leggi_file(f, &n);
  int *args = malloc(sizeof(int) * argc - 2);
  for (int i = 0; i < argc - 2; i++) {
    args[i] = atoi(argv[i + 2]);
  }
  int m = find_max(args, argc - 2);
  fprintf(stdout, "%d", somme(a, n, m));

  free(a);
  free(args);
  if (fclose(f) == EOF)
    exit(1);

  return 0;
}