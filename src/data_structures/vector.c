#include "../../include/data_structures.h"
#include <stdio.h>
#include <stdlib.h>

struct Vector {
    void** items;
    int capacity;
    int total;
}; 

Vector* initVector() {
    Vector* vec = (Vector*) malloc(sizeof(Vector));
    vec->capacity = 1;
    vec->total = 0;

    vec->items = malloc(sizeof(void*) * vec->capacity);
    if (!vec->items) {
        free(vec);
        return NULL;
    }; 

    return vec;
}; 

void insertVector(Vector *vec, void *element) {
    if(vec->capacity == vec->total) {
        vec->capacity *= 2;
        vec->items = realloc(vec->items, vec->capacity * sizeof(void*));
    } 
    vec->items[vec->total++] = element;
};

void* getVector(Vector* vec, int index) {
    if(!vec || !vec->items || index < 0 || index >= vec->total) {
        return NULL;
    } 

    /* index = vec->total - 1; */

    return vec->items[index];
} 

void destroyVector(Vector* vec) {
    if (vec) {
        free(vec->items);
        free(vec);
    }
} 
