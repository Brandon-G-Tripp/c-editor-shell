#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h> 
#include <setjmp.h>
#include <stdlib.h>
/* #include "../../cmake/cmocka/include/cmocka.h" */
#include "/usr/local/Cellar/cmocka/1.1.7/include/cmocka.h"

#include "../../include/data_structures.h"
#include "../../src/data_structures/list.c"

static void setup() {  
}

static void teardown() {
}

// Test initializing an empty list 
void test_initList() {
    List* list = initList();
    // Assert was initialized
    assert_non_null(list);
    // Assert list is empty 
    assert_int_equal(list->length, 0);
}

// Test inserting an element 
void test_insertList() {
    List* list = initList();

    // Insert and element
    void* element = malloc(sizeof(int));
    *((int*)element) = 1;
    insertList(list, element);

    // Assert list length increased
    assert_int_equal(list->length, 1);

    // Assert element was added 
    assert_ptr_equal(getList(list, 0), element);
} 

void test_getList() {
    List* list = initList();

    void* element1 = malloc(sizeof(int));
    *((int*)element1) = 1;
    insertList(list, element1);

    void* element2 = malloc(sizeof(int));
    *((int*)element2) = 2;
    insertList(list, element2);

    // Get first element 
    assert_ptr_equal(getList(list, 0),element1);
    
    // Get second element 
    assert_ptr_equal(getList(list, 0),element1);
} 

void test_destroyList() {
    List* list = initList();
    assert_non_null(list);

    // Destroy list 
    destroyList(&list);

    // ASsert list was destroyed)
    printf("list = %p\n", list);
    assert_null(list);
} 

// Insert Get 
void testInsertGet() {
    List* list = initList();

    int* element1 = malloc(sizeof(int));
    *element1 = 10;
    insertList(list, element1);

    int* ret = getList(list, 0);
    assert_ptr_equal(ret, element1);
    assert_int_equal(*ret, 10);

    destroyList(&list);
}

// Remove 
void testRemove() {
    List* list = initList();

    int* element1 = malloc(sizeof(int));
    *element1 = 10;
    insertList(list, element1);

    int* ret = removeList(list, 0);

    assert_ptr_equal(getList(list, 0), NULL);

    destroyList(&list);
} 


// Index of 
void testIndexOf() {
    List* list = initList();

    int* element1 = malloc(sizeof(int));
    *element1 = 10;
    insertList(list, element1);

    assert_int_equal(indexOf(list, element1),  0);
    assert_int_equal(indexOf(list, NULL), -1);

    // ... other tests

    destroyList(&list);
}

// Contains
void testContains() {
    List* list = initList();

    int* element1 = malloc(sizeof(int));
    *element1 = 10;
    insertList(list, element1);

    assert_int_equal(contains(list, element1),  1);
    assert_int_equal(contains(list, NULL), 0);

    // ... other tests

    destroyList(&list); 
}

// Clear
void testClear() {
    List* list = initList();

    insertList(list, malloc(1));
    insertList(list, malloc(1));
    insertList(list, malloc(1));
    
    assert_int_equal(list->length, 3);

    clearList(list);

    assert_int_equal(list->length, 0);

    // ... other tests

    destroyList(&list);
}

// isEmpty
void testIsEmpty() {
    List* list = initList();
    
    assert_int_equal(isEmpty(list), 1);

    insertList(list, malloc(1));

    assert_int_equal(!isEmpty(list), 0);
    
    clearList(list);

    assert_int_equal(isEmpty(list), 1);

    // ... other tests
    
    destroyList(&list);
}

int main(void) { 
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_initList),
        cmocka_unit_test(test_insertList),
        cmocka_unit_test(test_getList),
        cmocka_unit_test(test_destroyList),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
