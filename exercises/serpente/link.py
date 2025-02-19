
#!/usr/bin/env python3


import sys , os , os.path

def link_directory(src, dest):
	assert os.path.exists(src) and os.path.exists(dest)
	aggiunti = []
	for base , directories , files in os.walk(src):
		for file in files: 
			sourcefile = os.path.abspath(os.path.join(base, file))
			if not os.access(sourcefile, os.F_OK) or os.path.islink(sourcefile):
				continue
			link_dir = os.path.join(dest, (file[0].lower()))
			if not os.path.exists(link_dir):
				os.mkdir(link_dir)
			real_link = os.path.realpath(link_dir)
			link = f"{file}"
			if file in aggiunti:
				link = f"{file}.{aggiunti.count(file)}"
			aggiunti.append(file)
			link_name = os.path.join(real_link, link)
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