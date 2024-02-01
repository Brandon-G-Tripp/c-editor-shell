#include "../../include/utils/common_utils.h"
#include <stdlib.h>

// Get length of char array
int count(char** arr) {
    int len = 0;
    while(arr[len] != NULL) {
        len++;
    } 

    return len;
} 
