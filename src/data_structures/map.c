#include "../../include/data_structures.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct MapEntry {
    void* key;
    void* value;
    struct MapEntry* next;
} MapEntry; 

struct Map {
    int capacity;
    int size;
    MapEntry** entries;
}; 

Map* initMap(int capacity) {
    Map* map = malloc(sizeof(Map));
    map->capacity = capacity;
    map->size = 0;
    map->entries = calloc(capacity, sizeof(MapEntry*));
    return map;
} 

void destroyMap(Map** map) {
    Map* innerMap = *map;
    for (int i = 0; i < innerMap->capacity; i++) {
        MapEntry* entry = innerMap->entries[i];
        while (entry != NULL) {
            MapEntry* next = entry->next;
            free(entry);
            entry = next;
        }
    }
    free(innerMap->entries);
    free(innerMap);

    *map = NULL;
} 

void insertMap(Map* map, void* key, void* value) {
    uintptr_t hash = (uintptr_t)key % map->capacity;
    MapEntry* entry = map->entries[hash];

    // Check if the key already exists
    while (entry != NULL) {
        if (entry->key == key) {
            entry->value = value;
            return;
        } 
        entry = entry->next;
    } 

    // Insert new entry 
    entry = malloc(sizeof(MapEntry));
    entry->key = key;
    entry->value = value;
    entry->next = map->entries[hash];
    map->entries[hash] = entry;
    map->size++;
} 

void* getMap(Map* map, void* key) {
    uintptr_t hash = (uintptr_t)key % map->capacity;
    MapEntry* entry = map->entries[hash];

    while (entry != NULL) {
        if (entry->key == key) {
            return entry->value;
        } 
        entry = entry->next;
    } 
    return NULL;
} 
