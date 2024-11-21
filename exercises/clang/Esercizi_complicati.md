### ESERCIZI DI PREPARAZIONE AL COMPITINO DEL 22 11 2024 ###


Ecco una serie di esercizi di difficoltà crescente, basati sui temi di liste concatenate, alberi binari di ricerca (ABR) e lettura da file usando `getline()` e `strtok()`:

---

### 1. **Inserimento e stampa di una lista concatenata**
Scrivi un programma che utilizzi la seguente struttura per rappresentare una lista concatenata:
```c
typedef struct _node {
    int valore;
    struct _node *next;
} Node;
```
Il programma deve:
1. Leggere una sequenza di numeri interi dalla riga di comando.
2. Creare una lista concatenata aggiungendo ogni numero all'inizio della lista.
3. Stampare i valori della lista in ordine inverso rispetto a come sono stati inseriti.
4. Deallocare la memoria utilizzata.

---

### 2. **Somma degli elementi di un albero binario di ricerca**
Utilizzando la seguente struttura:
```c
typedef struct _node {
    int valore;
    struct _node *left, *right;
} Node;
```
Scrivi un programma che:
1. Legga una sequenza di numeri interi dalla riga di comando.
2. Costruisca un albero binario di ricerca (ABR) con i numeri inseriti.
3. Calcoli la somma degli elementi dell'albero usando una funzione ricorsiva.
4. Stampi il risultato e deallochi tutta la memoria utilizzata.

---

### 3. **Filtraggio di parole da un file con `getline()` e `strtok()`**
Scrivi un programma che:
1. Legga il nome di un file dalla riga di comando.
2. Legga il file riga per riga usando `getline()`.
3. Per ogni riga, utilizzi `strtok()` per estrarre parole separate da spazi.
4. Stampi tutte le parole che contengono più di 4 caratteri.
5. Gestisca eventuali errori nella lettura del file e deallochi eventuale memoria.

---

### 4. **Unione di due liste concatenate**
Utilizzando la struttura del primo esercizio, scrivi un programma che:
1. Legga due insiemi di numeri interi dalla riga di comando (separati da un carattere speciale come `|`, es.: `3 5 7 | 1 2 6`).
2. Crei due liste concatenate separate per i due insiemi.
3. Scriva una funzione che unisca le due liste concatenate in una nuova lista, mantenendo l'ordine degli elementi.
4. Stampi la lista unita e deallochi tutta la memoria utilizzata.

---

### 5. **Intervallo su ABR con lettura da file**
Scrivi un programma che:
1. Legga un file contenente una lista di numeri interi, un numero per riga.
2. Costruisca un ABR usando questi numeri.
3. Implementi una funzione che, dato un intervallo `[min, max]` passato dalla riga di comando, stampi tutti i valori dell'ABR che si trovano in questo intervallo, esplorando solo le parti dell'albero necessarie.
4. Conti e stampi il numero di nodi visitati durante la ricerca.
5. Deallochi tutta la memoria.

---

### 6. **Eliminazione di nodi da una lista concatenata**  
Scrivi un programma che:  
1. Crei una lista concatenata leggendo una sequenza di numeri interi dalla riga di comando.  
2. Chieda all'utente un valore da rimuovere dalla lista.  
3. Implementi una funzione che elimini tutti i nodi contenenti il valore specificato.  
4. Stampi la lista modificata e deallochi tutta la memoria.  

---

### 7. **Conteggio foglie in un ABR**  
Utilizzando la struttura per gli alberi binari:  
```c
typedef struct _node {
    int valore;
    struct _node *left, *right;
} Node;
```  
Scrivi un programma che:  
1. Costruisca un ABR con una sequenza di numeri letta dalla riga di comando.  
2. Implementi una funzione ricorsiva che conti il numero di nodi foglia (nodi senza figli).  
3. Stampi il numero di foglie e deallochi l'intero albero.  

---

### 8. **Conteggio parole da file con frequenze**  
Scrivi un programma che:  
1. Legga un file di testo riga per riga usando `getline()`.  
2. Utilizzi `strtok()` per dividere le righe in parole.  
3. Memorizzi le parole in una lista concatenata, mantenendo per ogni parola un contatore della sua frequenza.  
4. Stampi tutte le parole con le rispettive frequenze in ordine alfabetico.  
5. Deallochi tutta la memoria.  

---

### 9. **Profondità massima di un ABR**  
Scrivi un programma che:  
1. Costruisca un ABR leggendo una sequenza di numeri dalla riga di comando.  
2. Implementi una funzione ricorsiva per calcolare la profondità massima dell'albero.  
3. Stampi la profondità e deallochi l'albero.  

---

### 10. **Filtraggio complesso da file con token multipli**  
Scrivi un programma che:  
1. Legga un file dove ogni riga contiene un record con formato `<nome>,<cognome>,<età>,<città>` (es. `Mario,Rossi,30,Roma`).  
2. Utilizzi `getline()` e `strtok()` per leggere e dividere i record in campi.  
3. Filtri i record per età (ad esempio, solo persone con età > 25) e città (ad esempio, solo persone di "Roma").  
4. Stampi i record filtrati.  
5. Gestisca eventuali errori nella lettura e deallochi eventuale memoria.  

---

### 11. **Inserimento ordinato in una lista concatenata**  
Scrivi un programma che:  
1. Crei una lista concatenata leggendo una sequenza di numeri interi dalla riga di comando.  
2. Implementi una funzione che inserisca un nuovo numero nella lista, mantenendo l'ordine crescente dei valori.  
3. Stampi la lista aggiornata e deallochi tutta la memoria utilizzata.  

---

### 12. **Conta nodi in un intervallo su ABR**  
Utilizzando un ABR, scrivi un programma che:  
1. Crei un ABR leggendo una sequenza di numeri dalla riga di comando.  
2. Implementi una funzione ricorsiva che conti quanti nodi dell'albero hanno valori compresi in un intervallo `[min, max]` specificato dall'utente.  
3. Stampi il risultato e deallochi tutta la memoria.  

---

### 13. **Scrittura e lettura da file con liste concatenate**  
Scrivi un programma che:  
1. Legga una sequenza di numeri interi dalla riga di comando e li memorizzi in una lista concatenata.  
2. Scriva i valori della lista in un file di testo, uno per riga.  
3. Rilegga il file e ricrei una nuova lista concatenata con i valori letti.  
4. Stampi i valori della nuova lista per verificare che corrispondano a quelli originali.  
5. Gestisca la deallocazione della memoria e la gestione degli errori di lettura/scrittura.  

---

### 14. **Somma parziale dei nodi in un ABR**  
Scrivi un programma che:  
1. Crei un ABR leggendo una sequenza di numeri dalla riga di comando.  
2. Implementi una funzione ricorsiva che calcoli la somma dei valori dei nodi fino a una certa profondità `d` specificata dall'utente.  
3. Stampi il risultato della somma e deallochi tutta la memoria.  

---

### 15. **Filtraggio avanzato da file con strutture complesse**  
Scrivi un programma che:  
1. Legga un file di testo con righe nel formato `<ID>,<Nome>,<Dipartimento>,<Stipendio>` (es. `123,Marco,Ricerca,45000`).  
2. Utilizzi `getline()` e `strtok()` per separare i campi e memorizzarli in una lista concatenata di strutture:  
   ```c
   typedef struct _impiegato {
       int id;
       char nome[50];
       char dipartimento[50];
       float stipendio;
       struct _impiegato *next;
   } Impiegato;
   ```  
3. Filtri i dipendenti che lavorano in un dipartimento specifico (ad esempio, "Ricerca") e abbiano uno stipendio superiore a una certa soglia.  
4. Stampi i record filtrati e deallochi tutta la memoria utilizzata.  

---

### 16. **Divisione di una lista concatenata**  
Scrivi un programma che:  
1. Crei una lista concatenata leggendo una sequenza di numeri interi dalla riga di comando.  
2. Implementi una funzione che divida la lista in due nuove liste: una con numeri pari e l'altra con numeri dispari.  
3. Stampi entrambe le liste e deallochi tutta la memoria.  

---

### 17. **Rimozione nodi da un ABR**  
Scrivi un programma che:  
1. Crei un ABR leggendo una sequenza di numeri dalla riga di comando.  
2. Implementi una funzione che rimuova un nodo con un valore specificato dall'utente, mantenendo la struttura corretta dell'ABR.  
3. Stampi l'albero in ordine simmetrico (in-order) dopo ogni rimozione e deallochi tutta la memoria.  

---

### 18. **Ricerca del massimo e minimo da file**  
Scrivi un programma che:  
1. Legga un file contenente numeri interi, uno per riga, usando `getline()`.  
2. Inserisca i numeri letti in una lista concatenata.  
3. Implementi due funzioni che trovino il massimo e il minimo valore nella lista.  
4. Stampi i valori massimo e minimo e deallochi tutta la memoria utilizzata.  

---

### 19. **Livelli di un ABR**  
Scrivi un programma che:  
1. Crei un ABR leggendo una sequenza di numeri dalla riga di comando.  
2. Implementi una funzione che stampi i nodi dell'albero per livello, da sinistra a destra (attraversamento livello per livello, *level-order*).  
3. Gestisca la deallocazione della memoria alla fine.  

---

### 20. **Lettura e raggruppamento di dati da file**  
Scrivi un programma che:  
1. Legga un file con righe nel formato `<Città>,<Temperatura>` (es. `Milano,22.5`).  
2. Inserisca i dati in una lista concatenata di strutture:  
   ```c
   typedef struct _citta {
       char nome[50];
       float temperatura;
       struct _citta *next;
   } Citta;
   ```  
3. Raggruppi i dati per città, calcolando la temperatura media per ciascuna città.  
4. Stampi la temperatura media di ogni città in ordine alfabetico.  
5. Deallochi tutta la memoria e gestisca eventuali errori di lettura.  

---

### ESERCIZI DI SIMULAZIONE PROVA ###

Ecco due esercizi complessi che integrano liste concatenate, alberi binari di ricerca (ABR) e la lettura da file con `getline()` e `strtok()`:

---

### 1. **Database di studenti con analisi delle medie**  

#### Obiettivo  
Implementare un programma che gestisca un database di studenti, memorizzando i dati in una lista concatenata e analizzandoli utilizzando un ABR.

#### Specifiche  
1. **Lettura del file**  
   - Il programma legge un file di testo con righe nel formato:  
     ```plaintext
     <Matricola>,<Nome>,<Cognome>,<Corso>,<Media>
     ```  
     Esempio di contenuto del file:  
     ```plaintext
     12345,Anna,Rossi,Informatica,27.5  
     67890,Luca,Bianchi,Matematica,25.0  
     54321,Sara,Verdi,Fisica,29.0  
     ```  
   - Ogni riga deve essere elaborata con `getline()` e suddivisa in campi utilizzando `strtok()`.  

2. **Memorizzazione in una lista concatenata**  
   - I dati di ciascuno studente devono essere memorizzati in una lista concatenata con la seguente struttura:  
     ```c
     typedef struct _studente {
         int matricola;
         char nome[50];
         char cognome[50];
         char corso[50];
         float media;
         struct _studente *next;
     } Studente;
     ```  

3. **Costruzione dell'ABR**  
   - Gli studenti devono essere inseriti in un ABR in base alla loro media, con la seguente struttura:  
     ```c
     typedef struct _nodo {
         float media;
         struct _studente *studente;  // Puntatore allo studente nella lista concatenata
         struct _nodo *left, *right;
     } NodoABR;
     ```  

4. **Funzionalità richieste**  
   - **Stampa della lista**: Stampare tutti gli studenti dalla lista concatenata in ordine di inserimento.  
   - **Stampa per media**: Stampare gli studenti in ordine crescente di media utilizzando l’ABR.  
   - **Intervallo di medie**: Implementare una funzione che stampi gli studenti con una media compresa in un intervallo `[min, max]`.  
   - **Deallocazione**: Deallocare correttamente la memoria della lista e dell'ABR.  

---

### 2. **Analisi di prodotti e vendite da file**  

#### Obiettivo  
Gestire un elenco di prodotti e relative vendite, memorizzando i dati in una lista concatenata e utilizzando un ABR per analisi specifiche.  

#### Specifiche  
1. **Lettura del file**  
   - Il programma legge un file con righe nel formato:  
     ```plaintext
     <ID Prodotto>,<Nome>,<Categoria>,<Prezzo>,<Quantità Venduta>
     ```  
     Esempio di contenuto del file:  
     ```plaintext
     101,Smartphone,Elettronica,699.99,120  
     102,Lavatrice,Elettrodomestici,499.99,80  
     103,Notebook,Elettronica,999.99,50  
     ```  
   - Ogni riga deve essere letta con `getline()` e divisa in campi utilizzando `strtok()`.

2. **Memorizzazione in una lista concatenata**  
   - I prodotti devono essere memorizzati in una lista concatenata con la seguente struttura:  
     ```c
     typedef struct _prodotto {
         int id;
         char nome[50];
         char categoria[50];
         float prezzo;
         int quantita_venduta;
         struct _prodotto *next;
     } Prodotto;
     ```  

3. **Costruzione dell'ABR**  
   - Gli stessi prodotti devono essere inseriti in un ABR in base al fatturato totale (*prezzo × quantità venduta*), utilizzando la seguente struttura:  
     ```c
     typedef struct _nodo {
         float fatturato;
         struct _prodotto *prodotto;  // Puntatore al prodotto nella lista concatenata
         struct _nodo *left, *right;
     } NodoABR;
     ```  

4. **Funzionalità richieste**  
   - **Prodotti più venduti**: Stampare i prodotti con il maggiore fatturato utilizzando l’ABR (esplorazione in ordine decrescente).  
   - **Categorie**: Implementare una funzione che filtri i prodotti in base alla categoria (ad esempio, "Elettronica") e calcoli il totale del fatturato per quella categoria.  
   - **Intervallo di fatturati**: Implementare una funzione che stampi i prodotti con un fatturato compreso in un intervallo `[min, max]`.  
   - **Deallocazione**: Deallocare correttamente la memoria della lista e dell'ABR.  

---
