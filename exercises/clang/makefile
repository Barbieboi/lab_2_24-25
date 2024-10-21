CC=gcc
CFLAGS=-std=c11 -Wall -O -g
LDLIBS=-lm

VPATH= ./src

.SILENT: 

.PHONY: all clean purge

EXECS:=	astringhe concatena mioatoi ostringhe paridispari \
		reverse ribalta_elenco somma_arr somma_mancanti somme_distinte \
		esad smista

all:$(EXECS) 

clean:
	rm -f *.o

purge:
	rm -f $(EXECS)