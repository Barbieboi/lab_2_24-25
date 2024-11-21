CC=gcc
CFLAGS=-std=c11 -Wall -O -g
LDLIBS=-lm

VPATH= ./src


.PHONY: all clean purge

EXECS:= abr_persone clean


all:$(EXECS) 

abr_persone : abr_persone.o persone.o
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@

abr_persone :



clean: 
	rm -f *.o

purge:
	rm -f $(EXECS)