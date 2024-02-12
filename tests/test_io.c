#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h> // needed for cmocka
#include "/usr/local/Cellar/cmocka/1.1.7/include/cmocka.h"

#include "../include/io.h"

// Create stream stub 
struct Stream {
    // Add neded fields for testing
}; 

// Test create stdin stream
void test_create_stdin_stream(void **state) {
    struct Stream* stdin_stream = create_stdin_stream();
    assert_non_null(stdin_stream);
    assert_true(stdin_stream == Stream);
} 

