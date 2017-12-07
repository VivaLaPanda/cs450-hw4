#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "parsetools.h"

#define BUF_SIZE 512
#define BUF_MIN 128

// Splits a string by token
// https://stackoverflow.com/a/9210560/4951118
char** str_split(char* a_str, char a_delim) {
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}
	
int** ParseFile(int** pageTable, int* offset, char* filename) {
	// Read file into string - https://stackoverflow.com/a/7856790/4951118
	char *file_contents, *p;
    long input_file_size;

    FILE *input_file = fopen(filename, "rb");
    fseek(input_file, 0, SEEK_END);
    input_file_size = ftell(input_file);
    rewind(input_file);
    file_contents = malloc(input_file_size * (sizeof(char)));
    fread(file_contents, sizeof(char), input_file_size, input_file);
    fclose(input_file);
	
	// Break string into rows by newline
	char** rowsAsStrings = str_split(file_contents, '\n');
	char** rowsOfChars = str_split(rowsAsStrings[0], ' ');
	
	int numVAddrBits = atoi(rowsOfChars[0]);
	int numPAddrBits = atoi(rowsOfChars[1]);
	int bytesInPage = atoi(rowsOfChars[2]);
	int numEntries = 0;
	
	for (numEntries; rowsAsStrings[numEntries] != NULL; numEntries++){}
	
	// Break rows into chars by space
	int** rowsOfElements = malloc(numEntries*sizeof(int*));
	for(int i=1; i < numEntries; i++) {
		rowsOfChars = str_split(rowsAsStrings[i], ' ');
		rowsOfElements[i-1] = malloc(4*sizeof(int));
		for (int j=0; j < 4; j++) {
			rowsOfElements[i-1][j] = atoi(rowsOfChars[j]);
		}
	}
	
	*offset = calcOffset(bytesInPage);
	
	free(file_contents);
	return rowsOfElements;
}

int calcOffset(int bytesInPage) {
	return myLog(bytesInPage,2);
}

int myLog(int x, int base) { 
    return log(x) / log(base); 
} 