#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

// Generic list type 
typedef struct List List;

// Generic vector type 
typedef struct Vector Vector ;

// Generic hash map type 
typedef struct Map Map ;

// List functions
List* initList();
void destroyList(List** list);
void insertList(List* list, void* element);
void* getList(List* list, int index);

void* removeList(List* list, int index);
int indexOf(List* list, void* element);
int contains(List* list, void* element);
void clearList(List* list);
int isEmpty(List* list);

void destroyListElement(void* element);

// Vector functions
Vector* initVector();
void destroyVector(Vector* vector);
void insertVector(Vector* vector, void* element);
void* getVector(Vector* vector, int index);


// Map functions
Map* initMap(int capacity);
void destroyMap(Map* map);
void insertMap(Map* map, void* key, void* value);
void* getMap(Map* map, void* key);

#endif
