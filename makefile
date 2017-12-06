# Makefile for pipe test

all: sudoku.x

# $@ is make shorthand for the thing on the left side of the colon
#	(pipes.x in this case)
# $^ stands for everything on the right side of the colon (the .o files)

sudoku.x: main.o parsetools.o tablelookup.o itoa.o
	gcc -lpthread -lm -o $@ $^

# $< is the first item after the colon (main.c here)
main.o: main.c parsetools.h tablelookup.h itoa.h
	gcc -g -c -o $@ $<

parsetools.o: parsetools.c
	gcc -c -o $@ $<

tablelookup.o: tablelookup.c itoa.h
	gcc -c -o $@ $<

itoa.o: itoa.c
	gcc -c -o $@ $<

	
clean:
	rm -f *.x *.o *~

