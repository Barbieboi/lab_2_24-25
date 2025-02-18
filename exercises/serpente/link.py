
#!/usr/bin/env python3


import sys , os , os.path

def link_directory(src, dest):
	assert os.path.exists(src) and os.path.exists(dest)

	for base , directories , files in os.walk(src):
		for file in files:
			