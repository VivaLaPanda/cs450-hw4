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
		scanf("%lx",&input);
		unsigned long offsetinput = input;
        int onset = 64 - *offset;
        printf("onset!:%d\n", onset);
		offsetinput = offsetinput << onset;
		offsetinput = offsetinput >> onset;
		input = input >> *offset;


		unsigned long result = lookup(pageTable, input);

        result = result << *offset;
		result = result + offsetinput;

		printf("%lx\n", result);
	}

	return 0;
}
