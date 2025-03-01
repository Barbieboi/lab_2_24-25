CC=gcc
CFLAGS=-std=c11 -Wall -O -g
LDLIBS=-lm



.PHONY: all clean purge

EXECS:= abr_persone clean


all:$(EXECS) 

abr_persone : abr_persone.o persone.o
	$(CC) $^ $(LDLIBS) -o $@

abr_persone.o : abr_persone.c persone.h
	$(CC) $< $(CFLAGS) -c -o $@ 

persone.o : persone.c persone.h
	$(CC) $< $(CFLAGS)  -c -o $@ 


clean: 
	rm -f *.o

purge:
	rm -f $(EXECS)