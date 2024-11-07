## Esercizi


### Costruzione array dinamici (20/9/24)

Scrivere un programma C che legge un intero N e costruisce i seguenti due array di interi:

* l'array `a[]` contente i numeri tra 1 e N che sono multipli 3 ma non di 5: ``3, 6, 9, 12, 18, 21, 24, 27, 33, ...``

* l'array `b[]` contente i numeri tra 1 e N che sono multipli 5 ma non di 3:  ``5, 10, 20, 25, 35, 40, 50, ...``

Al termine della costruzione deve stampare lunghezza e la somma gli elementi degli array `a` e `b`, deve poi deallocarli e terminare. 

Ad esempio per N=100 i due array risultano

```
a = [3, 6, 9, 12, 18, 21, 24, 27, 33, 36, 39, 42, 48, 51, 54, 57, 63, 66, 69, 72, 78, 81, 84, 87, 93, 96, 99]

b = [5, 10, 20, 25, 35, 40, 50, 55, 65, 70, 80, 85, 95, 100]
```

e di conseguenza l'output dovrebbe essere 
```
lunghezza a[] = 27,  somma a[] = 1368
lunghezza b[] = 14,  somma b[] = 735
```

Per N=99999 l'output dovrebbe essere
```
lunghezza a[] = 26667,  somma a[] = 1333366668
lunghezza b[] = 13333,  somma b[] = 666633335
```
Eseguire il programma anche utilizzando `valgrind` verificando che non stampi nessun messaggio d'errore e al termine visualizzi il messaggio 
```
HEAP SUMMARY:
 in use at exit: 0 bytes in 0 blocks
```



### Reverse di stringhe (27/9/24)

Scrivere un programma `reverse` che stampa sullo schermo gli argomenti passati sulla linea di comando (escluso il nome del programma) con i caratteri in ordine inverso. Ad esempio, scrivendo
```
reverse sole azzurro 123
```
l'output dovrebbe essere
```
elos
orruzza
321
```
Si noti che per stampare i caratteri in ordine inverso potete 1. creare la stringa ribaltata e poi stamparla con `printf` con modificatore `%s`, oppure  2.  stampare i caratteri da destra a sinistra uno alla volta con il modificatore `%c`. 



### Concatena stringhe (27/9/24)

Scrivere un programma `concatena` che costruisce la stringa ottenuta concatenando tra loro le stringhe  passate sulla linea di comando. Ad esempio, scrivendo
```
concatena sole azzurro 123
```
l'output dovrebbe essere
```
Stringa concatenata: soleazzurro123
```
In dettaglio il vostro programma deve 

1. calcolare la lunghezza `lun` della stringa risultato, come somma delle lunghezze delle stringhe `argv[1]` ... `argv[argc-1]`
2.  allocare con `malloc` un blocco di `lun+1` byte (il `+1` serve per il byte 0 finale)
3. copiare i singoli caratteri dalle stringhe `argv[i]`   nella stringa appena allocata, seguiti dal terminatore 0
4. stampare la stringa ottenuta e deallocarla

Eseguire il programma anche utilizzando `valgrind` verificando che non stampi nessun messaggio d'errore e al termine visualizzi il messaggio 
```
HEAP SUMMARY:
 in use at exit: 0 bytes in 0 blocks
```



### Pari e dispari (1/10/24)

Scrivere un programma `paridispari` che legge gli interi dal file di testo `argv[1]` e copia quelli pari in un  file di nome `argv[2]` e quelli dispari in un file di nome `argv[3]`. In altre parole se il programma viene invocato scrivendo
```
paridispari interi.txt pari dispari
```
e il file `interi.txt` contiene
```
10
70
17
36
-23
```
al termine dell'esecuzione il file `pari` deve contenere
```
10
70
36
```
e il file `dispari`
```
17
-23
```
Si noti che non è necessario salvare gli interi in un array; il programma può aprire i tre file contemporaneamente, leggere dal primo con `fscanf` e scrivere sul secondo o terzo file con `fprintf`. Quando non ci sono altri interi da leggere (cioè `fscanf` restituisce `EOF`) si devono chiudere tutti i file e terminare,


### Somme distinte (4/10/24)

Scrivere una funzione C

    int *somme_distinte(int a[], int n, int *size)
che dato un array  di interi  `a[]` di lunghezza `n>0` alloca e restituisce un nuovo array `b[]` contenente tutti gli interi distinti che si possono ottenere sommando tra loro due elementi di `a` (compreso un elemento sommato a se stesso). Ad esempio

		input: 1 2
		output: 2 3 4   [infatti: 2=1+1, 3=1+2, 4=2+2] 
		input: 1 0 0 1 0 0 1 
		output: 2 1 0   [l'ordine nell'array di output non è importante]
		input: -2 3 1 10 
		output: -4 1 -1 8 6 4 13 2 11 20

Dato che non è possibile stabilire a priori quale sarà la lunghezza dell'array risultato, tale lunghezza deve essere passata per riferimento utilizzando il puntatore `*size`. Non vi preoccupate dell'efficienza della soluzione da voi proposta.  

Si scriva poi un programma che invoca `somme_distinte` passandogli l'array ottenuto convertendo in interi i valori forniti sulla linea di comando e successivamente stampa su `stderr` l'array restituito da `somme_distinte`. Infine il programma deve stampare su `stdout` la somma dei valori contenuti nell'array restituito da `somme_distinte`. (Nota: per stampare su `stdout` si può usare `fprintf(stdout,...)` oppure semplicemente `printf`). Il programma deve deallocare tutta la memoria utilizzata (verificare con valgrind). 




### Conversione da stringa a intero (4/10/24)

Scrivere una funzione 
```
int mioa2toi(const char *s, int *n)
```
che data una stringa `s` la interpreta come intero decimale (allo stesso modo di `atoi`). Se la conversione avviene con successo il valore ottenuto deve essere scritto in `*n` e la funzione deve restituire il valore 0; se invece la conversione non ha successo la variabile *n* non deve essere modificata e la funzione deve restituire un intero positivo che indica l'errore che si è verificato secondo il seguente schema:

1. se la stringa è vuota o contiene solamente spazi
2. se viene incontrato un carattere che non sia uno fra `+-0123456789` (esempio, la stringa `"234s7"`)
3. se il segno (`+` o `-`) compare più di una volta, o compare in posizione non corretta (esempio le stringhe `"+-34"`, `"-3-4"`, o `"-34+"`)
4. se compare esattamente un segno, ma nessuna cifra (ad esempio la stringa `"-"`)

La conversione deve ignorare eventuali spazi iniziali e deve terminare non appena viene incontrato uno spazio. Quindi l'input `"  +34 21"` deve restituire il valore `0` (conversione OK) e  scrivere in `*n` il valore 34, mentre l'input `"  + 34 21"`deve restituire il valore 4 (conversione fallita perché ha letto il segno e poi lo spazio ha fatto interrompere la conversione prima che incontrasse una qualsiasi cifra. 

Per quanto riguarda la parte di calcolo, a parte la gestione del segno e degli errori, osservate che se l'input è `"XYZ"` e  la stringa `"XY"` è stata convertita nel valore `t` allora `"XYZ"`vale  $10 t + z$ dove $z$ è il valore tra 0 e 9 rappresentato dal carattere `Z`.  Ricordo che i codice ascii di caratteri tra `0` e `9` sono gli interi tra 48 e 57.

La vostra funzione non può usare `atoi`, ma la potete usare nel `main` per verificare la correttezza della vostra funzione, Ad esempio scrivendo:
```
int main(int argc, char *argv[])
{
  for(int i=1;i<argc;i++) {
    int n, e;
    e = mioatoi(argv[i],&n);
    if(e!=0) printf("Errore conversione: %d\n",e);
    else printf("Mia funzione: %d, libreria: %d\n",n,atoi(argv[i]));
  }
  return 0;
} 
```
Fate il test con valori sia positivi che negativi! La riga di comando di default non mette gli spazi dentro gli `argv[]` ma potete inserirli scrivendo la stringa tra doppie virgolette. Quindi scrivendo
```
mioprog + 123
```
 si ha `argv[1]="+"` e `argv[2]=123`, mentre scrivendo
 ```
mioprog "+ 123"
 ```
 si ha `argv[1]="+ 123"` e non ci sono altri argomenti. 
 



### Ordina stringhe per lunghezza (8/10/24)

Scrivere una funzione 
```
void mergesort(char *a[], int n)
```
ch dato un array `a[]` di  `n` stringhe le ordina in ordine di lunghezza crescente. *Suggerimento* si modifichi le funzioni mergesort/merge viste a lezione in `mergeSort.c`, osservando che c'è un'unica istruzione nella quale gli elementi di `a[]` vengono confrontati. Dato che vogliamo ordinare le stringhe per lunghezza, per confrontare `a[i]` e `c[j]`  il confronto deve essere fatto tra i valori `strlen(a[i])` e `strlen(c[j])`  

Scrivere poi un programma `ostringhe` che ordina per lunghezza crescente gli elementi di `argv` e stampa le stringhe ordinate sul terminale. Ad esempio, scrivendo
```
ostringhe due ricorsione dieci casa Po
```
deve essere visualizzato l'elenco
```
Po
due
casa
dieci
ricorsione
```

Verificate con valgrind il corretto uso e deallocazione della memoria 




### Somma mancanti (8/10/24)

Scrivere un programma C, che legge dalla linea di comando il nome di un file di testo contenente interi e stampa su *stdout* la somma degli interi compresi tra 1 e 1000 che **non** compaiono nell'array. Ad esempio, se il file di input contiene tutti gli interi tra 1 e 1000 tranne il 13, il 17, e il 49 il valore che deve essere stampato è 79 (la somma 13+17+49). Si noti che tutti i valori nel file non compresi tra 1 e 1000 non influenzano il risultato, e che il fatto che un valore compaia più volte non influenza il risultato: a noi interessa la somma dei valori tra 1 e 1000 che non sono nel file di input. (*Suggerimento*: per svolgere l'esercizio non è necessario salvare gli interi del file in un array, è invece necessario utilizzare un array di 1000 elementi per tenere conto di quali valori tra 1 e 1000 sono presenti nel file).  




### Ribalta elenco (8/10/24)

Scrivere un programma che invocato dalla linea di comando scrivendo

    main infile outfile

legge tutte le stringhe dal file di testo *infile* e le riscrive su *outfile* **in ordine inverso**. Ad esempio, se *infile* contiene
```
Mattarella
Napolitano
Ciampi
Scalfaro
Cossiga
Pertini
```
il file *outfile* deve contenere
```
Pertini
Cossiga
Scalfaro
Ciampi
Napolitano
Mattarella
```
Potete assumere che le stringhe del file di input siano lunghe al max 40 caratteri. Dato però che non ci sono limitazioni al numero totale di stringhe, per poterle scrivere in ordine inverso dovete prima memorizzarle in un array di stringhe.  

Verificate con valgrind il corretto uso e deallocazione della memoria 




### Conversione in esadecimale (15/10/24)

Scrivere una funzione 
```c
char *converte16(int n)
```
che dato un intero positivo `n` alloca e restituisce una stringa contenente l'intero `n` scritto in base 16, utilizzando i caratteri da `a` a `f` per le cifre da 10 a 15.  (*Suggerimento:* non è difficile convertire un intero in esadecimale, ma questa funzione deve restituire una stringa che deve essere allocata. Per semplificare le cose potete usare funzione `asprintf` vista a lezione tenendo conto che nella `printf` come il modificatore `%d` visualizza un intero in decimale, il modificatore `%x` lo visualizza in base 16, vedere `man 3 printf` per i dettagli).

Scrivere poi un programma `esad` che per ogni intero passato sulla linea di comando, convertito in `int` con `atoi`, invoca la funzione `converte16` e stampa la stringa ottenuta su `stdout`. 

Ad esempio,  scrivendo
```
esad  26 73 1000 111
```
si deve ottenere l'output 
```
1a
49
3e8
6f
```
Verificate con valgrind il corretto uso e deallocazione della memoria 



### Smista primi (15/10/24)

Scrivere un programma `smista` che legge dalla linea di comando una stringa `nome` e un intero positivo `N` e crea i file `nome.d.primi` 
contenenti tutti i primi minori di `N` che terminano con la cifra `d`. Ad esempio il comando
```
smista elenco 35
```
deve creare il file `elenco.1.primi` contenente i valori `11` e `31`, il file  `elenco.2.primi` contenente il valore `2`,  il file  `elenco.3.primi` contenente i valori `3`, `13` e `23` e così via (all'interno dei file i valori potete scriverli uno per riga).

E' particolarmente importante verificare con valgrind il corretto uso e deallocazione della memoria: se non chiudete un file che avete aperto, valgrind segnalerà un blocco di memoria che non è stato deallocato. 


### Coppie (18/10/24)

Facendo riferimento alla struct `coppia` vista nell'esempio `array_coppie.c`, scrivere un programma che richiede sulla linea di comando un numero pari *2n* di interi, crea un array di *n* puntatori a coppie, le ordina per differenza di elementi crescente e stampa e dealloca l'array ordinato. Ad esempio, scrivendo
```
coppie 2 2 3 4 7 0 2 1
```
deve creare l'array di coppie `(2 2) (3 4) (7 0) (2 1)`, che ordinato per differenza crescente risulta 
`(3 4) (2 2) (2 1) (7 0)``, essendo le differenze -1, 0, 1, 7.



### Ordinamento di file (22/10/24)

Scrivere un programma che legge dalla riga di comando un elenco di file e stampa 
l'elenco di  questi file ordinati per dimensione decrescente, 
i file con la stessa dimensione devono essere ordinati lessicograficamente.

*Nota:* per eseguire dei test con molti file osserviamo che la linea di comando
linux ha un meccanismo di espansione dei pattern che viene effettuato prima
di invocare i comandi. Ad esempio, se scriviamo `ordina *.c *.txt` al programma 
`ordina` in `argc` e `argv` vengono passati tutti i file che hanno estensione `.c` e `.txt`

Questo esercizio è stato svolto in aula nel file `array_file.c` esclusa la parte di ordinamento, che 
potete svolgere modificando opportunaemnte il mergesort visto in `array_capitali_funz.c`



### Liste di interi (29/10/24)

Utilizzare la struct
```C
typedef struct _intero {
	int valore;
	struct _intero next;
} intero;
```
per rappresentare un elemento di una lista di interi. 

Scrivere un funzione 
```c
int confronta_lunghezza(intero *lis1, intero *lis2);
```
che date due liste di interi `lis1` e `lis2` (possibilemente anche vuote) restituisce `-1`
se `lis1` ha meno elementi di `lis2`, `1` se `lis1` ha più elementi di `lis2`, 0 se hanno lo stesso 
numero di elementi (le liste vuote si considerano avere 0 elementi).

Si scriva poi un `main` che legge dalla linea di comando un numero qualsiasi di interi e crea due liste contenenti 
rispettivamente gli interi pari e gli interi dispari passati sulla linea di comando (si noti che le liste possono essere vuote).

Successivamente il `main` deve invocare `confronta_lunghezza` e stampare la lista più lunga; se le liste hanno la stessa lughezza deve stampare quella la cui somma degli elementi è maggiore, se anche la somma degli elementi è la stessa non deve stampare nulla.

Il programma deve poi deallocare tutta la memoria utilizzata e terminare. 

### Ricerca su ABR (5/11/24)


Aggiungere al programma `abr_capitali` una funzione
```
int abr_ricerca_range(capitale *r, char *smin, char *smax)
```
che date due stringhe `smin` e `smax` visualizza su stdout tutte le città contenuto nell'abero di radice `r` il cui nome è compreso lessicograficamente tra `smin` e `smax`. La funzione deve visualizzare le città in 
ordine lessicografico e deve esplorare solamente le parti dell'albero che possono contenere città nel range assegnato. La funzione deve resituire il numero di nodi esplorati (cioè quelli il cui nome di città viene confrontato con `smin` e/o `smax`); questo serve per verificare che non vega visitato tutto l'abero.

Modificare poi la funzione `main` in modo che dopo la costruzione dell'albero venga invocata la funzione 
`abr_ricerca_range` con parametri `argv[2]` e `argv[3]`.   

