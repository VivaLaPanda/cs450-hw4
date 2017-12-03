#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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
	
void ParseFile(int sudokuBoard[9][9]) {
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
	
	// Break rows into chars by space
	char** rowsOfElements[9]; // array or arrays of character arrays
	for(int i=0; i < 9; i++) {
		rowsOfElements[i] = str_split(rowsAsStrings[i], ' ');
	}
	
	// rowsOfElements is now a 2D grid of char pointers, but we want those char pointers to be ints
	// Convert chars to ints
	for(int i=0; i < 9; i++) {
		for(int j=0; j < 9; j++) {
			// The 0 is to get the first character (which should be the only one except null term)
			// Minus 0 converts to int - https://stackoverflow.com/a/628778/4951118
			sudokuBoard[i][j] = rowsOfElements[i][j][0] - '0';
		}
	}
	
	free(file_contents);
}