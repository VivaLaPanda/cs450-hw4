# Makefile for pipe test

all: sudoku.x

# $@ is make shorthand for the thing on the left side of the colon
#	(pipes.x in this case)
# $^ stands for everything on the right side of the colon (the .o files)

sudoku.x: sudoku.c
	gcc -lpthread -o $@ $^

# $< is the first item after the colon (main.c here)
main.o: main.c
	gcc -std=c11 -g -c -o $@ $<

parsetools.o: parsetools.c
	gcc -std=c11 -c -o $@ $<


clean:
	rm -f *.x *.o *~

