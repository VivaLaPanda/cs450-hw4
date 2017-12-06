# Makefile for pipe test

all: pagesim.x

# $@ is make shorthand for the thing on the left side of the colon
#	(pipes.x in this case)
# $^ stands for everything on the right side of the colon (the .o files)

pagesim.x: main.o parsetools.o tablelookup.o itoa.o
	gcc -lm -o $@ $^

# $< is the first item after the colon (main.c here)
main.o: main.c parsetools.h tablelookup.h itoa.h
	gcc -g -c -o $@ $<

parsetools.o: parsetools.c
	gcc -g -c -o $@ $<

tablelookup.o: tablelookup.c itoa.h
	gcc -g -c -o $@ $<

itoa.o: itoa.c
	gcc -g -c -o $@ $<

	
clean:
	rm -f *.x *.o *~

