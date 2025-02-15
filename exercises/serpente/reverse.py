#!/usr/bin/env python3

import sys 

def main(nomefile):
	with open(nomefile, "r") as f: 
		lines = []
		for line in f:
			lines.append(line)
	with open(nomefile+".rev", "w") as g:
		for i in range(len(lines) -1, -1, -1):
			print(lines[i], file=g)

main(sys.argv[1])