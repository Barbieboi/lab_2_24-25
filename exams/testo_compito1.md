## Compito del 20/10/2023
### Argomenti
- Allocazione dinamica
- Passaggio di argomenti da riga di comando
- Lettura File
---
Scrivere una funzione `int somme(int a[], int n, int range)` che dato un array `a[]` di `n` interi e un parametro `range` calcola e restituisce la somma `s` nel seguente modo:

Se range è uguale a zero, `s` è la somma di tutti gli elementi dell'array `a[]`

altrimenti, `se range>0`, s è la somma dei primi range elementi dell'array `a[]` oppure la somma di tutti gli elementi di `a[]` se `range` è maggiore della lunghezza di `a[]`

altrimenti, se range<0, s è la somma degli ultimi `-range` elementi di `a[]` (si noti che `-range` è positivo), oppure la somma di tutti gli elementi di `a[]` se `-range` è maggiore della lunghezza di `a[]`.

Si scriva poi un programma main che 
1. verifica che sia `argc>2` 
2. legge, con `fscanf` gli interi contenuti nel file di nome `argv[1]` e li memorizza in un array a[] allocato dinamicamente 
3. calcola il massimo `m` dei valori `argv[2], argv[3], ..., argv[argc-1]` convertiti in interi con la funzione `atoi()` 
4. invoca la funzione somme sull'array `a[]` e passando il valore `m` come parametro range

Il valore restituito da somme deve essere stampato su `stdout`. Dopo la stampa il programma deve deallocare tutta la memoria utilizzata e chiudure tutti i file e terminare. Non stampate altre informazioni su `stdout`, stampate eventuali messaggi informativi di debug su `stderr`.

Esempi
Si supponga che file contenga `1 2 3 4 5 6 7 8 9 10`, allora

`main file1 -5 2 0`
deve restituire `3` in quanto il massimo è `2` quindi deve essere stampata la somma dei primi `2` elementi.

`main file1 -5 -3 -10`
deve restituire `27` in quanto il massimo è `-3` quindi deve essere stampata la somma degli ultimi `3` elementi.

`main file1 -5 -2 0`
deve restituire `55` in quanto il massimo è `0` quindi deve essere stampata la somma di tutti elementi.

`main file1 -5 20 4`
deve restituire `55` in quanto il massimo è `20` che è maggiore della lunghezza dell'array quindi deve essere stampata la somma di tutti elementi.

`main file1 -50 -11 -44`
deve restituire `55` in quanto il massimo è `-11`, dato che `11` è maggiore della lunghezza dell'array quindi deve essere stampata la somma di tutti elementi.