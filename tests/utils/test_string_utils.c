#include "../../include/string_utils.h"

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h> // needed for cmocka
#include <stdlib.h>
#include "/usr/local/Cellar/cmocka/1.1.7/include/cmocka.h"

// Test substring function 
void test_substring(void **state) {
    char *str = "hello world";
    char *sub = substring(str, 0, 5);

    assert_string_equal(sub, "hello");
    free(sub);
} 

// Test trim function
void test_trim(void **state) {
    char str[] = " hello world ";
    trim(str);
    assert_string_equal(str, "hello world");
} 

// Test split function 
void test_split(void **state) {
    char *str = "a,b,c";
    char **arr = split(str, ',');

    assert_int_equal(count(arr), 3);
    assert_string_equal(arr[0], "a");
    assert_string_equal(arr[1], "b");
    assert_string_equal(arr[2], "c");

    free(arr);
} 

// Test join function
void test_join(void **state) {
    char *arr[] = {"a", "b", "c"};
    char *str = join(str, 3, "-");

    assert_string_equal(str, "a-b-c");
    free(str);
} 

// Test contains function
void test_contains(void **state) {
    char *str = "hello world";
    assert_true(contains(str, "world"));
    assert_false(contains(str, "universe"));
    free(str);
} 

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_substring),
        cmocka_unit_test(test_trim),
        cmocka_unit_test(test_split),
        cmocka_unit_test(test_join),
        cmocka_unit_test(test_contains),
    }; 

    return cmocka_run_group_tests(tests, NULL, NULL);
}


