
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h> 
#include <setjmp.h>
#include "/usr/local/Cellar/cmocka/1.1.7/include/cmocka.h"

#include "../../src/data_structures/vector.c"

void test_initMap() {
    Map* map = initMap(10);
    assert_non_null(map);
    destroyMap(map);
}; 

void test_insertMap(void **state) {
    Map* map = initMap(10);

    int key1 = 1;
    int value1 = 10;
    insertMap(map, &key1, &value1);

    int key2 = 2;
    int value2 = 20;
    insertMap(map, &key2, &value2);

    int* retrieved_value1 = getMap(map, &key1);
    assert_int_equal(*retrieved_value1, 10);


    int* retrieved_value2 = getMap(map, &key2);
    assert_int_equal(*retrieved_value2, 20);

    destroyMap(map);
} 

void test_getMap(void **state) {
    Map* map = initMap(10);

    int key1 = 1;
    int value1 = 10;
    insertMap(map, &key1, &value1);

    int key2 = 2;
    int value2 = 20;
    insertMap(map, &key2, &value2);

    int* retrieved_value1 = getMap(map, &key1);
    assert_int_equal(*retrieved_value1, 10);


    int* retrieved_value2 = getMap(map, &key2);
    assert_int_equal(*retrieved_value2, 20);

    destroyMap(map);
} 

void test_destroyMap(void **state) {
    Map* map = initMap(10);
    destroyMap(map);
    assert_null(map);
} 

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_initMap),
        cmocka_unit_test(test_insertMap),
        cmocka_unit_test(test_getMap),
        cmocka_unit_test(test_destroyMap),
    }; 

    return cmocka_run_group_tests(tests, NULL, NULL);
}


