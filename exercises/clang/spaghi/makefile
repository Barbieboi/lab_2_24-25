CC=gcc
CFLAGS=-std=c11 -Wall -O -g -pthread
LDLIBS=-lm -pthread


.PHONY: purge

EXECS = 

all:$(EXECS) 

%.out: %.c xerrori.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)


%.o: %.c xerrori.h
	$(CC) $(CFLAGS) -c $<


clean: 
	rm -f *.o


purge:
	rm -f $(EXECS)