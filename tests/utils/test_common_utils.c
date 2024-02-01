#include "../../include/utils/common_utils.h"

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h> // needed for cmocka
#include <stdlib.h>
#include "/usr/local/Cellar/cmocka/1.1.7/include/cmocka.h"

// Test count 
void test_count(void **state) {
    char* arr[] = {"a", "b", "c"};

    int len = count(arr);

    assert_int_equal(len, 3);
} 

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_count),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);


} 
