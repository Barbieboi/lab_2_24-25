CC=gcc
CFLAGS=-std=c11 -Wall -O -ggdb -pthread
LDLIBS=-lm -pthread


.PHONY: purge

EXECS = threadSort.out

all:$(EXECS) 

%.out: %.c xerrori.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)


%.o: %.c xerrori.h
	$(CC) $(CFLAGS) -c $<


clean: 
	rm -f *.o


purge:
	rm -f $(EXECS)