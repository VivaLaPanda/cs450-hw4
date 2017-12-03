#include <stdio.h>
#include "parsetools.h"


int main(int argc, char *argv[]) {
	int pageTable[9][9];
	ParseFile(pageTable); // Parsefile stores result in pageTable
	bool result = ValidateBoard(pageTable);
	if (!result){
		printf( "The input is not a valid Sudoku\n");
	}
	else{
		printf("You did it kiddo, you valid Sudoku\n");
	}
	return 0;
}
