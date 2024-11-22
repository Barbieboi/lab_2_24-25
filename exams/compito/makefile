# definizione del compilatore e dei flag di compilazione
# che vengono usati dalle regole implicite
CC=gcc
CFLAGS=-std=c11 -Wall -O -g
LDLIBS=-lm

pitagora : pitagora.o terne.o
	$(CC) $^ $(LDLIBS) -o $@

pitagora.o :pitagora.c terne.h
	$(CC) $< $(CFLAGS) -c -o $@ 

terne.o :terne.c terne.h
	$(CC) $< $(CFLAGS) -c -o $@ 
