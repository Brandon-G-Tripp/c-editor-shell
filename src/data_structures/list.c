#include "../../include/data_structures.h"
#include <stdio.h>
#include <stdlib.h>


struct List {
    void** elements;
    int length; 
    int capacity;
}; 

List* initList() {
    List* list = (List*) malloc(sizeof(List));
    list->length = 0;
    list->capacity = 10;


    list->elements = malloc(list->capacity * sizeof(void*));
    return list;
} 

void destroyList(List **list) {
    printf("list = %p\n", list);
    if (*list != NULL) {
        List* l = *list;
        if(l->elements != NULL) {
            printf("list->elements = %p\n", l->elements);
            free(l->elements);
            printf("list->elements = %p\n",  l->elements);
        } 
        printf("list right before free = %p\n", list);
        free(*list);
        printf("list right after free = %p\n", list);
        *list = NULL;
        printf("list right after nulling = %p\n", list);
    }
} 

void insertList(List *list, void *element) {
    if(list->length >= list->capacity) {
        list->capacity = list->capacity == 0 ? 1 :list->capacity * 2;
        list->elements = realloc(list->elements, sizeof(void*) * list->capacity);
    } 
    list->elements[list->length++] = element;
} 

void* getList(List* list, int index) {
    if(index < 0 || index >= list->length) {
        return NULL;
    } 
    return list->elements[index];
} 

void* removeList(List* list, int index) {
    if (index < 0 || index >= list->length) {
        return NULL;
    } 

    void* element = list->elements[index];

    for (int i=index; i<list->length-1; i++) {
        list->elements[i] = list->elements[i+1];
    } 

    list->length--;
    return element;
} 

int indexOf(List *list, void *element) {
    for(int i=0; i < list->length; i++) {
        if (list->elements[i] == element) {
            return i;
        } 
    } 
    return -1;
} 

int contains(List *list, void *element) {
    return indexOf(list, element) != -1;
} 

void clearList(List *list) {
    list->length = 0;
} 

int isEmpty(List *list) {
    return list->length == 0;
}

void destroyListElement(void *element) {
    free(element);
} 
