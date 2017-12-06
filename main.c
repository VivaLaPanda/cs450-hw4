#include <stdio.h>
#include "parsetools.h"
#include "pagelookup.h"


int main(int argc, char *argv[]) {
	int pageTable[][];
	int offset = ParseFile(pageTable); // Parsefile stores result in pageTable
	bool result = P(pageTable);
	if (!result){
		printf( "The input is not a valid Sudoku\n");
	}
	else{
		printf("You did it kiddo, you valid Sudoku\n");
	}
	return 0;
}
