#include <stdio.h>
#include "parsetools.h"
#include "boardvalidate.h"


int main(int argc, char *argv[]) {
	int sudokuBoard[9][9];
	ParseFile(sudokuBoard); // Parsefile stores result in sudokuboard
	bool result = ValidateBoard(sudokuBoard);
	if (!result){
		printf( "The input is not a valid Sudoku\n");
	}
	else{
		printf("You did it kiddo, you valid Sudoku\n");
	}
	return 0;
}
