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
#include "../../src/data_structures/vector.c"

static void test_init_vector() {
    Vector* vector = initVector();
    assert_non_null(vector);
} 

static void test_destroy_vector() {
    Vector* vector = initVector();
    destroyVector(vector);
} 

static void test_insert_vector() {
    Vector* vector = initVector();
    int element = 10;
    insertVector(vector, &element);
    assert_int_equal(*(int *)getVector(vector, 0), 10);
    destroyVector(vector);
} 

static void test_get_vector() {
    Vector* vector = initVector();
    int element = 20;
    insertVector(vector, &element);
    int* result = getVector(vector, 0);
    assert_int_equal(*result, 20);
    destroyVector(vector);
} 

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_init_vector),
        cmocka_unit_test(test_destroy_vector),
        cmocka_unit_test(test_insert_vector),
        cmocka_unit_test(test_get_vector),
    }; 

    return cmocka_run_group_tests(tests, NULL, NULL);
} 
