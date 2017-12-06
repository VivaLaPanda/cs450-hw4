#include <stdio.h>
#include "parsetools.h"
#include "tablelookup.h"
#include "itoa.h"

int main(int argc, char *argv[]) {
	char* filename;
	if (argc != 2) {/* We print argv[0] assuming it is the program name */
		printf( "usage: %s filename\n", argv[0] );
		return 1;
	} else {
		filename = argv[1];
	}

	int** pageTable;
	int* offset =  malloc(sizeof(int));
	pageTable = ParseFile(pageTable, offset,filename); // Parsefile stores result in pageTable
	while (1)
	{
		printf("offset = %d \n", *offset);
		printf("please enter your input:");
		unsigned long input;
		scanf("%ld",&input);
		unsigned long offsetinput = input;
		offsetinput = offsetinput << (32 - *offset);
		offsetinput = offsetinput >> (32 - *offset);
		input = input >> *offset;
		

		unsigned long result = lookup(pageTable, input);
		result = result << *offset;
		result = result + offsetinput;

		printf("%lx\n", result);
		break;
	}

	return 0;
}
