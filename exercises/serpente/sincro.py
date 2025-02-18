#!/usr/bin/env python3


import sys ,os, os.path, shutil , time


def crea_dizionario(nome_dir):
	# dizionario per files {"nomefile": time }
	if not os.path.exists(nome_dir):
		return {} , []
	f = {}
	list_dir = []
	for base , dirs , files in os.walk(nome_dir):
		for file in files:
			nome_file = os.path.join(base, file)
			if not os.access(nome_file, os.F_OK):
				continue
			f[nome_file] = os.path.getmtime(nome_file)
			for d in dirs: 
				list_dir.append(os.path.join(base , d))
	return f,list_dir


"""

def main(master,slave):


if len(sys.argv) != 2:
	print("NOPE")
	sys.exit(2)
else:
	main(sys.argv[1], sys.argv[2])
"""