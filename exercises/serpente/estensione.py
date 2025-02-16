#!/usr/bin/env python3

import sys , os, os.path ,time , functools

@functools.total_ordering
# classe per memorizzare le informazioni di un file
class Miofile:
	def __init__(self,path):
		self.path = path
		self.mtime = os.path.getmtime(path)
		self.size = os.path.getsize(path)
	

	def precedente_a(self,limite):
		"""Restituisce true se il tempo di modifica
		è precedente a limite espresso in secondi da Epoch"""
		return self.mtime < limite

	def __eq__(self,other):
		return self.path==other.path and self.size==other.size and self.mtime==other.mtime 

	def __str__(self):
		return f"{self.path}\n  size:{self.size} "

	def __repr__(self):
		return f"Miofile({self.path})"

	def __lt__(self, other):
		if self.size < other.size:
			return True
		return False 


def elenco_file_ext(base_dir, ext):
	
	assert os.path.exists(base_dir)
	files = []
	explored = set()
	ls = os.listdir(base_dir)
	for f in ls:
		full_path = os.path.join(base_dir, f)
		if not os.access(full_path, os.F_OK ):
			continue
		if not os.path.isdir(full_path):
			if ext:
				nome , new_ext = os.path.splitext(full_path)
				if new_ext == ext:
					files.append(Miofile(full_path))
			else :
				files.append(Miofile(full_path))
		else:
			if not os.access(full_path, os.R_OK | os.X_OK) or os.path.realpath(full_path) in explored :
				continue
			rec_ls = elenco_file_ext(full_path, ext)
			explored.add(os.path.realpath(full_path))
			files += rec_ls
	return files

def main(path, regex = None):
	listona = elenco_file_ext(path, regex)
	listona.sort(reverse=True)
	for f in listona:
		print(f)


if len(sys.argv) < 2:
	main(sys.argv[1])
else:
	main(sys.argv[1], sys.argv[2])