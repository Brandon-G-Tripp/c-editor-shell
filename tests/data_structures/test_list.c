#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h> 
#include <setjmp.h>
/* #include <cmocka.h> */
#include "../../include/data_structures.h"

static void setup() {  
}

static void teardown() {
}

void test_sample() {
    // Arrange 
    setup();

    // Act 

    /* Assert */
    bool success = true;

    if (!success) {
        printf("Sample test failed!\n");
    } else {
        printf("Sample test passed!\n");
    } 

    teardown();
}

int main(void) { 
    test_sample();

    return 0;
}
