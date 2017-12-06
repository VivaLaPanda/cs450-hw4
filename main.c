#include <stdio.h>
#include "parsetools.h"
#include "tablelookup.h"
#include "itoa.h"

int main(int argc, char *argv[]) {
	int** pageTable;
	int* offset =  malloc(sizeof(int));
	pageTable = ParseFile(pageTable, offset); // Parsefile stores result in pageTable
	char* offsetStr;
	offsetStr = itoa(*offset, 2);
	int result = lookup(pageTable, "00000", 1);
	printf("%x\n", result);
	
	return 0;
}
