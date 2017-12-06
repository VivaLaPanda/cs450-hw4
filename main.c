#include <stdio.h>
#include "parsetools.h"
#include "tablelookup.h"
#include "itoa.h"

int main(int argc, char *argv[]) {
	if (argc < 2)
	{
		printf("you need to provide all 2 files \n");
		return 1;
	}

	int** pageTable;
	int* offset =  malloc(sizeof(int));
	pageTable = ParseFile(pageTable, offset); // Parsefile stores result in pageTable
	char offsetStr[*offset];
	char input[256];
	int num_bits;
	while (1)
	{

		printf("please enter your input:");
		num_bits = scanf("%s",input);
		printf("\n");
		char offsetStr[*offset];
		if ((num_bits - *offset) > 0) {
			int j = 0;
			for (int i = num_bits - *offset; i < num_bits; i++)
			{
				offsetStr[j] += input[i];
				j++;
			}

			int result = lookup(pageTable, offsetStr, 1);
			printf("%x\n", result);
		} else
			break;
	}

	return 0;
}
