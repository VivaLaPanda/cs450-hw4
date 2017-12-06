#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

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
	
int ParseFile(int pageTable[][], int* offset) {
	// Read file into string - https://stackoverflow.com/a/7856790/4951118
	char *file_contents, *p;
    int len, remain, n, size;

    size = BUF_SIZE;
    file_contents = malloc(size);
    len = 0;
    remain = size;
    while (!feof(stdin)) {
		if (remain <= BUF_MIN) {
			remain += size;
			size *= 2;
			p = realloc(file_contents, size);
			if (p == NULL) {
				free(file_contents);
				return;
			}
			file_contents = p;
		}

		fgets(file_contents + len, remain, stdin);
		n = strlen(file_contents + len);
		len += n;
		remain -= n;
	}
	
	// Break string into rows by newline
	char** rowsAsStrings = str_split(file_contents, '\n');
	
	int numVAddrBits = atoi(rowsAsStrings[0]);
	int numPAddrBits = atoi(rowsAsStrings[1]);
	int bytesInPage = atoi(rowsAsStrings[2]);
	int numEntries = (int) pow(2, numVAddrBits)
	
	// Break rows into chars by space
	int* rowsOfElements[numEntries];
	for(int i=1; i < numEntries-1; i++) {
		char** rowsOfChars = str_split(rowsAsStrings[i], ' ');
		for (int j=0; j < 4; j++) {
			rowsOfElements[i][j] = atoi(rowsOfChars[j]);
		}
	}
	
	pageTable = rowsOfElements;
	
	free(file_contents);
	
	return calcOffset(bytesInPage);
}

int calcOffset(bytesInPage) {
	return myLog(bytesInPage,2);
}

int myLog(int x, int base) { 
    return log(x) / log(base); 
} 