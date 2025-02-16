#!/usr/bin/env python3


import sys, os , os.path , functools ,time

@functools.total_ordering
# classe per memorizzare le informazioni di un file
class Miofile:
	def __init__(self,path,depth):
		self.path = path
		self.mtime = os.path.getmtime(path)
		self.size = os.path.getsize(path)
		self.depth  = depth
	
	def get_depth(self):
		return self.depth

	def precedente_a(self,limite):
		"""Restituisce true se il tempo di modifica
		è precedente a limite espresso in secondi da Epoch"""
		return self.mtime < limite

	def __eq__(self,other):
		return self.path==other.path and self.size==other.size and self.mtime==other.mtime 

	def __str__(self):
		return f"{self.path}\n depth: {self.depth} size:{self.size} "

	def __repr__(self):
		return f"Miofile({self.path})"

	def __lt__(self, other):
		if type(self) != type(other):
			return False
		if self.depth < other.depth:
			return True
		elif self.depth > other.depth:
			return False
		else:
			if self.size < other.size:
				return True
			return False 

# funzione ricorsiva per cercare il file più grande
# nella directory corrente e in tutte le sue sottodirectory
def elenco_file(nome,dir_esplorate,depth):
	"""restituisce una lista con un oggetto Miofile per 
		ogni file dentro la directory nome e le sue
		sottodirectory"""

	assert os.path.isdir(nome), "Argomento deve essere una directory"
	# inizializzo la lsita di file trovati
	lista = []
	# ottiene il contenuto della directory 
	listafile = os.listdir(nome)
	for f in listafile:
		nomecompleto = os.path.join(nome,f)
		# verifica se il file è accessibile
		if not os.access(nomecompleto,os.F_OK):
			print("!! Broken link:", nomecompleto, file=sys.stderr)
			continue
			# distinguo tra file normali e directory
		if not os.path.isdir(nomecompleto):
			nuovadim = os.path.getsize(nomecompleto)
			nuovonome = nomecompleto
			# aggiungo alla lista risultato
			# il file appena incontrato
			# il file è rappresentato dalla t
			# classe Miofile
			lista.append(Miofile(nuovonome,depth))
		else:
			# nomecompleto è una directory: possibile chiamata ricorsiva
			# verifico che la directory sia esplorabile 
			if not os.access(nomecompleto, os.R_OK | os.X_OK):
				print(f"!! Directory {nomecompleto} non accessibile",file=sys.stderr)
				continue
			# verifica che la directory non sia già stata esplorata
			# va fatta con il realpath perchè la stessa dir può avere più nomi  
			nomereal = os.path.realpath(nomecompleto)
			if nomereal in dir_esplorate:
				print(f"!! Directory {nomecompleto} già esplorata",file=sys.stderr)
				print(f"!!  con nome {nomereal}",file=sys.stderr)
				continue
			dir_esplorate.add(nomereal)
			# directory nuova e accessibile: esegui ricorsione
			lista_dir = elenco_file(nomecompleto,dir_esplorate, depth+1)
			lista += lista_dir
		# fine ciclo for su i file di questa directory     
	return lista

def main(nomepath):
	elenco = elenco_file(nomepath,set(),0)
	elenco.sort(reverse=True)
	maxdepth = elenco[0].depth
	for f in elenco:
		if f.depth == maxdepth:
			print(f)
		else :
			break

main(sys.argv[1])