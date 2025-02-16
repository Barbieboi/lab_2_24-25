## Esercizi sull'Esplorazione del File System

### Esercizio 1: Esplorazione solo di determinati tipi di file
Modifica il codice in modo che esplori e mostri solo file con una determinata estensione (ad esempio .txt, .jpg, ecc.). L'utente dovrebbe essere in grado di passare l'estensione come parametro opzionale al programma.
Suggerimento: Usa os.path.splitext() per ottenere l'estensione di ciascun file e confrontarla con quella fornita dall'utente.

### Master – Sincronizzazione di due cartelle

Scrivi uno script che sincronizzi due cartelle, in modo che la seconda diventi una copia esatta della prima.

Se un file è stato aggiunto o modificato nella prima cartella, deve essere copiato nella seconda.
Se un file è stato rimosso dalla prima cartella, deve essere eliminato dalla seconda.
Lo script deve stampare un log delle operazioni effettuate.
📌 Suggerimento: Usa `shutil.copy2()`, `os.walk()` per confrontare le directory e `os.remove()` per eliminare i file obsoleti.