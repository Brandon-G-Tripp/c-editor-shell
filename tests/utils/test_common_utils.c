#include "../../include/utils/common_utils.h"
#include "../../src/utils/common_utils.c"


#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h> // needed for cmocka
#include <stdlib.h>
#include "/usr/local/Cellar/cmocka/1.1.7/include/cmocka.h"

// Test count 
void test_count_string(void **state) {
    char *arr[] = {"a", "b", "c", NULL};

    int len = count_string(arr);

    assert_int_equal(len, 3);
} 

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_count_string),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
} 
