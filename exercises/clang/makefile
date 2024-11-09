CC=gcc
CFLAGS=-std=c11 -Wall -O -g
LDLIBS=-lm

VPATH= ./src


.PHONY: all clean purge

EXECS:= sudamerica



all:$(EXECS) 

ordina:array_file.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o

purge:
	rm -f $(EXECS)