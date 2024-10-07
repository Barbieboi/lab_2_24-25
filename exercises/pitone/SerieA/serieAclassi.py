#! /usr/bin/env python3

import functools ,sys


@functools.total_ordering
class Squadra:

	def __init__(self, nome):
		self.nome = nome  # nome della squadra
		self.punti = 0  # punteggio iniziale
		self.golf = self.gols = 0  # gol fatti e subiti
	
	def __eq__(self, other):
		return self.nome == other.nome

	def __lt__(self, other):
		if self.punti < other.punti:
			return True
		if self.punti > other.punti:
			return False
		return (self.golf - self.gols) < (other.golf - other.gols)  

	def __str__(self):
		return f"{self.nome:<13} {self.punti:<4} {self.golf:<4} {self.gols:<4}" 

	def aggiorna(self, gf , gs , p):
		self.golf += gf
		self.gols += gs
		self.punti += p


def partita(g1, g2 , s1 , s2):
	if  g1 > g2:
		p1 = 3
		p2 = 0
	elif g1 < g2:
		p1 = 0
		p2 = 3
	else:
		p1 = p2 = 1
	s1.aggiorna(g1, g2 , p1)
	s2.aggiorna(g2, g1 , p2)

def crea_squadre(f):
	squadre = []
	for line in f:
		a = line.split()
		if len(a) == 0:
				continue
		s1 = Squadra(a[2]) 
		s2 = Squadra(a[3])
		if s1 not in squadre:
				squadre.append(s1)
		if s2 not in squadre:
				squadre.append(s2)
		partita(int(a[0]), int(a[1]), squadre[squadre.index(s1)], squadre[squadre.index(s2)])			

	return squadre


def main(file_name):
	with open(file_name, "r") as f:
		s = crea_squadre(f)
	
	sorted_s = sorted(s, reverse=True)
	print("Squadra      Pu  GF  GS")
	print("-----------------------")
	for i in sorted_s:
		print(i)

if len(sys.argv) != 2:
	print(f"Uso: {sys.argv[0]} nomefile.txt")
else:
	main(sys.argv[1])