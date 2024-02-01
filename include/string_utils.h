#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Internal DS headers
#include "./data_structures.h"

// Substring
char* substring(char* str, int start, int length);

// Trim whitespace
void trim(char* str);

// Split string into array of strings
char** split(char* str, char delim);

// Join array of strings into one string
char* join(char** arr, int count, char* delim);

// Check if string contains another string
bool contains_sub(char* str, char* match);

#endif
