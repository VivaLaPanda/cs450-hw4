#ifndef PARSE_H
#define PARSE_H

char** str_split(char* a_str, char a_delim);
int ParseFile(int pageTable[][]);
int calcOffset(bytesInPage);
int myLog(int x, int base);

#endif