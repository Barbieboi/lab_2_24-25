#define _GNU_SOURCE 
#include <assert.h> 
#include <errno.h>
#include <stdbool.h> 
#include <stdio.h>   
#include <stdlib.h>  
#include <string.h>  

// stampa un messaggio d'errore e termina il programma
void termina(char *messaggio) {
  if (errno != 0)
    perror(messaggio);
  else
    fprintf(stderr, "%s\n", messaggio);
  exit(1);
}

void stampa_array(int *a, int n) {
  assert(a != NULL);
  // stampo il contenuto dell'array
  for (int i = 0; i < n; i++)
    fprintf(stdout, "%8d",
            a[i]); // stampo gli elementi in un campo di 8 caratteri
  fprintf(stdout, "\nIn totale l'array contiene %d interi\n", n);
  fprintf(stderr, "Ho finito!\n");
}

bool isIn(int *a, int v, int n) {
  bool flag = false;
  for (int i = 0; i < n; i++) {
    if (a[i] == v) {
      flag = true;
    }
  }
  return flag;
}

int *doppioni(int *a, int n, int *dup) {
  if (a == NULL)
    termina("No duplicates");
  int *res = calloc(n, sizeof(int));
  if (res == NULL)
    termina("Malloc Failed");
  int size = 0;
  bool done_zero = false;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[j] == a[i] && a[i] == 0 && !done_zero) {
        res[size] = a[i];
        size++;
        done_zero = true;
      } else if ((a[j] == a[i] && !isIn(res, a[i], n))) {
        res[size] = a[i];
        size++;
      }
    }
  }
  if (size <= 0) {
    termina("No duplicates");
  }
  res = realloc(res, sizeof(int) * size);
  *dup = size;
  return res;
}

int find_max(int *a, int n) {
  int max = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > max)
      max = a[i];
  }
  return max;
}

int main(int argc, char *argv[]) {
  if (argc < 2)
    termina("wrong use");
  int *a = malloc(sizeof(int) * (argc - 1));
  if (a == NULL)
    termina("Error malloc");
  for (int i = 1; i < argc; i++) {
    a[i - 1] = atoi(argv[i]);
  }
  int n_dups;
  int *doppi = doppioni(a, argc - 1, &n_dups);
  // stampa_array(doppi, n_dups) ;
  if (doppi == NULL)
    termina("doppi was NULL");
  fprintf(stdout, "%d\n", find_max(doppi, n_dups));
  free(doppi);
  free(a);

  return 0;
}