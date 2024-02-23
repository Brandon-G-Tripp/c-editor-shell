#include "../../include/utils/common_utils.h"
#include <stdio.h>
#include <stdlib.h>

// Get length of char array
int count_string(char** arr) {
    int i = 0;
    while(arr[i] != NULL) {
        printf("arr[%d]: %s\n", i, arr[i]); 
        i++;
    } 

    return i;
} 
