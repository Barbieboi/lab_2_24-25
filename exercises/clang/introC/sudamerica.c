#define _GNU_SOURCE 
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include <assert.h> 
#include <string.h> 
#include <errno.h>  
// gcc -std=c11 -Wall -O -g -o

void termina(const char *messaggio);

typedef struct capit {
	char *nome;
	char *nazione ;
	int pop ;
		struct capit *left, *right;
} capitale;

void capitale_stampa(const capitale *a, FILE *f) {
	fprintf(f,"%-16s %-16s %10d\n",a->nome,a->nazione, a->pop);
}

capitale *capitale_crea(char *s, char *n ,int p){
	capitale *a  = malloc(sizeof(*a));
	a->nome = strdup(s);
	a->nazione = strdup(n);
	a->pop = p ;
	a->left = a->right = NULL;
	return a;
}

void capitale_distruggi(capitale *a){
	free(a->nome);
	free(a->nazione);
	free(a);
}

void abr_capitale_stampa(const capitale *root, FILE *f){
	if(root!=NULL) {
	abr_capitale_stampa(root->left,f);
	capitale_stampa(root,f);
	abr_capitale_stampa(root->right,f);
	}
}

void abr_capitale_stampa_preorder(const capitale *root, FILE *f, int depth)
{
	// stampa depth spazi per mostrare la profondità del nodo
	for(int i=0;i<depth;i++) fprintf(f,". ");
	if(root!=NULL) {
	capitale_stampa(root,f);
	abr_capitale_stampa_preorder(root->left,f,depth+1);
	abr_capitale_stampa_preorder(root->right,f,depth+1);
	}
	else fprintf(f,"X\n");
}

void abr_capitale_distruggi(capitale *root){
	if(root!=NULL) {
	abr_capitale_distruggi(root->left);
	abr_capitale_distruggi(root->right);
	capitale_distruggi(root);
	}
}

capitale *abr_inserisci(capitale *root, capitale *c){
  c->left=c->right=NULL;
  // caso base albero vuoto
  if(root==NULL) 
    return c;
  int ris = strcmp(c->nome,root->nome);
  if(ris==0) {// i nomi sono uguali
    fprintf(stderr, "Nodo duplicato: ");
    capitale_stampa(c,stderr);
    capitale_distruggi(c);
  }
  else if(ris<0) // c->nome < root->nome
    root->left = abr_inserisci(root->left,c);
  else // c->nome > root->nome
    root->right = abr_inserisci(root->right,c);
  return root;
}    

capitale *crea_abr(FILE *f){
	capitale *root=NULL;
	char *buffer = NULL ;
	size_t n = 0 ;
	while(true){
	//leggi linea dal file
	ssize_t e = getline(&buffer,&n,f);
	if(e<0) {        // se e<0 assumiamo sia finito il file
		free(buffer);  // dealloco il buffer usato per le linee 
		break;
	}
	char *n = strtok(buffer,";\n");
	char *p = strtok(NULL, ";\n");
	char *naz = strtok(NULL, ";\n");
	printf("letto: %s , %s , %s\n", n , p , naz);
	capitale *b = capitale_crea(n,naz,atoi(p));
	root = abr_inserisci(root, b);
	}
	fclose(f);  
	return root;
}

capitale *abr_ricerca(capitale *root, char *nome)
{
  if(root==NULL) return NULL;
  int cfr = strcmp(nome,root->nome);
  if(cfr==0) return root;
  else if(cfr<0) // ricerco a sinistra
    return abr_ricerca(root->left,nome);
  else // ricerca a destra
    return abr_ricerca(root->right,nome);
}

void abr_stampa_cond(capitale *r, FILE *f, 
                     bool (*funz)(capitale *))
{
  if(r==NULL) return;
  abr_stampa_cond(r->left,f,funz);
  if(funz(r))
    capitale_stampa(r,f);
  abr_stampa_cond(r->right,f,funz);
}


bool range_pop(capitale *c){
	return (c->pop<10000 && c->pop>3000)?true:false;
}

int main(int argc, char **argv){
	if(argc < 2) termina("Uso ./sudamerica sudAmerica.txt");
	FILE *f = fopen(argv[1],"r");
  	if(f==NULL) termina("Errore apertura file");
  // costruzione albero leggendo capitali dal file
  	capitale *root=crea_abr(f);

  	puts("--- inizio lista ---");
  
  	abr_capitale_stampa_preorder(root,stdout,0); 


  	puts("--- fine lista ---");
	
	abr_stampa_cond(root, stdout,range_pop);
	abr_capitale_distruggi(root);
	
	return 0;

}


void termina(const char *messaggio){
	if(errno!=0) perror(messaggio);
	else fprintf(stderr,"%s\n", messaggio); 
	exit(1); 
}