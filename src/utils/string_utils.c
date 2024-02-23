#include "../../include/string_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* substring(char* str, int start, int length) {
    char* sub = malloc(length + 1);
    strncpy(sub, str + start, length);
    sub[length] = '\0';
    return sub;
} 

void trim(char* str) {
    int len = strlen(str);
    int i = 0;
    while (str[i] == ' ' && i < len) {
        i++;
    } 
    int j = len - 1;
    while (str[j] == ' ' && j >= 0) {
        j--;
    } 
    memmove(str, str + i, j - i + 1);
    str[j-i+1] = '\0';
} 

char** split(char* str, char delim) {
    int count = 1;
    int i; 
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == delim)
            count++;
    } 

    char** arr = malloc((count + 1) * sizeof(char*));

    i = 0;
    int idx = 0;
    int start = 0;
    while(str[i] != '\0') {
        if (str[i] == delim) {
            if (start == i) {
                arr[idx] = malloc(1);
                arr[idx][0] = '\0';
            } else {
                // extract sub string
                arr[idx] = substring(str, start, i - start);
            } 
            idx++;
            start = i + 1;
        } 
        i++;
    } 

    if (start == i) {
        arr[idx] = malloc(1);
        arr[idx][0] = '\0';
    } else {
        arr[idx] = substring(str, start, i - start);
    } 

    arr[idx+1] = NULL;

    return arr;
} 


char* join(char** arr, int count, char* delim) {
    int i;
    int len = 0;
    int dlen = strlen(delim);
    for (i = 0; i < count; i++) {
        len += strlen(arr[i]);
        if (i != count - 1)
                len += dlen;
    } 

    char* str = malloc(len + 1);
    *str = '\0';

    for (i = 0; i < count - 1; i++) {
        strcat(str, arr[i]);
        strcat(str, delim);
    } 

    strcat(str, arr[count - 1]);

    return str;
} 

int contains_sub(char *str, char *match) {
    /* return strstr(str, match) != NULL; */
    char *p = strstr(str, match);
    if (p) {
        return 1;
    } else {
        return 0;
    } 
} 

