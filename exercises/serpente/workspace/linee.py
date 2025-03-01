#!/usr/bin/env python3

#e.barbin@studenti.unipi.it


import sys , os, os.path, functools

@functools.total_ordering
class Miofile:
	#parametri di classe
	pattern = []

	@staticmethod
	def aggiorna_pattern(p):
		Miofile.pattern = p 

	def __init__(self,path, max_righe):
		self.path = os.path.realpath(path)
		self.linee = []
		with open(self.path , "r") as f:
			count = 0
			for linea in f:
				if count >= max_righe:
					break
				self.linee.append(linea)
				count += 1


	def __lt__(self,other):
		for l in self.linee:
			if Miofile.pattern in l:
				for o in other.linee:
					if Miofile.pattern in o:
						return l < o


	def __str__(self):

		stringa = f"{os.path.abspath(self.path)}\n"
		
		for linea in self.linee:
			stringa += f"{linea}"
		 
		return stringa
	
	

def elenco_linee(dir, num):
	assert os.path.isdir(dir)
	real_path = os.path.realpath(dir)
	lista = []
	for base, dirs, files in os.walk(real_path):
			for file in files:
				nome_file = os.path.realpath(os.path.join(base, file))
				if not os.access(nome_file , os.F_OK):
					print(f"{nome_file} broken link",file=sys.stderr)
					continue
				lista.append(Miofile(nome_file, num))
	
	return lista 


def main(dir, num , pattern):
	Miofile.aggiorna_pattern(pattern) 
	tanti = elenco_linee(dir , num)
	pochi = []
	for f in tanti:
		for linea in f.linee:
			if pattern in linea:
				pochi.append(f)
	
	pochi.sort()
	for poco in pochi:
		# poco oggetto (path , lista_linee)
		print(poco)


if len(sys.argv) < 3:
	sys.exit(1)
else:
	main(sys.argv[1], int(sys.argv[2]), sys.argv[3]) 