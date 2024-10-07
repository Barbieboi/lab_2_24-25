#!/usr/bin/env python3

import os, os.path as path , sys

def main(dir_name):
	os.mkdir(dir_name)



if len(sys.argv) != 2:
	print("error", file=sys.stderr)
else:
	main(sys.argv[1])