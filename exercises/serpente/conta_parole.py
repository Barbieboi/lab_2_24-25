#!/usr/bin/env python3

import sys, os, os.path as path , subprocess

def sorgenti(src, esplorate):
	assert path.isdir(src)
	estensioni = [".c", ".h"]
	src = path.realpath(src)
	files = os.listdir(src)
	files.sort()
	count = 0
	for f in files:
		nome_file = path.join(src, f)
		if not os.access(nome_file, os.F_OK):
			continue
		if not path.isdir(nome_file):
			_ , ext = path.splitext(nome_file)
			if ext in estensioni:
				output = subprocess.run(['wc', nome_file], capture_output=True, encoding='utf-8')
				count += int(output.stdout.split()[0])
		else :
			if not os.access(nome_file, os.R_OK | os.X_OK):
				continue
			esplorate.add(nome_file)
			sorgenti(nome_file, esplorate)
	src = path.basename(src)
	print(f"{src} {count}") 



def main(nomedir):
  sorgenti(nomedir, set())


# invoca main 
if len(sys.argv) == 2:
    main(sys.argv[1])
else:
    print("Uso:", sys.argv[0], "nomedir")
    exit(1)