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



def main(master,slave):
	diz , master_dirs = crea_dizionario(master)
	slave_diz, slave_dirs = crea_dizionario(slave)
	if not os.path.exists(slave):
		os.mkdir(slave)
		for d in master_dirs:
			target = slave + d[d.find("/"):]
			if not os.path.exists(target):
				os.mkdir(target)
		for k in diz:
			target =  slave + k[k.find('/'):]
			print(target)
			shutil.copy2(k,target)
	else:
		for k in slave_diz:
			target =  master + k[k.find('/'):]
			if target not in diz:
				os.remove(k) 
			elif  diz[target] != slave_diz[k]:
				
				shutil.copy2(target,k)
			


main(sys.argv[1], sys.argv[2])