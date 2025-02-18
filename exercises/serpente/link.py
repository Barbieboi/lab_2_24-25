
#!/usr/bin/env python3


import sys , os , os.path

def link_directory(src, dest):
	assert os.path.exists(src) and os.path.exists(dest)
	aggiunti = {}
	for base , directories , files in os.walk(src):
		print(files)
		for file in files: 
			sourcefile = os.path.join(base, file)
			if not os.access(sourcefile, os.F_OK):
				continue
			link_dir = os.path.join(dest, (file[0].lower()))
			if not os.path.exists(link_dir):
				os.mkdir(link_dir)
			
			if file not in aggiunti:
				aggiunti[file] = 1
				link = str(file)
			else :
				link = str(file) + "." + str(aggiunti[file])
				aggiunti[file] += 1

			link_name = os.path.join(link_dir, file)
			print(f"linkando {sourcefile} a {link_name}")
			os.link(sourcefile, link_name)
		





def main(src, dest):
	if os.path.exists(dest):
		sys.exit(1)
	os.mkdir(dest)

	link_directory(src, dest)



if len(sys.argv) != 3 :
	print("Uso python3 link.py src dest")
else:
	main(sys.argv[1], sys.argv[2])