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
    assert_true(stdin_stream != NULL);
} 

// Test create_stdout_stream()
void test_create_stdout_stream(void **state) {
    Stream* stdout_stream = create_stdout_stream();
    assert_non_null(stdout_stream);
    assert_true(stdout_stream != NULL);  
}

// Test file input stream creation
void test_create_file_input_stream(void **state) {

  Stream* stream = create_file_input_stream("test_file.txt");

  assert_non_null(stream);
  assert_true(stream != NULL);

}

// Test file output stream creation  
void test_create_file_output_stream(void **state) {

  Stream* stream = create_file_output_stream("test_output.txt");

  assert_non_null(stream); 
  assert_true(stream != NULL);

}

// Stub read implementation
int stub_read(Stream* stream, void* buffer, int size) {
  return size;
}

// Test reading from a stream  
void test_read_stream(void **state) {

  char buffer[10];

  void* mock = mock_type(void*);
  Stream* stream = (Stream*)mock;
  will_return(stream->read, stub_read);

  int nread = read_stream(stream, buffer, sizeof(buffer));

  assert_int_equal(nread, sizeof(buffer));

}

// Stub write implementation
int stub_write(Stream* stream, void* buffer, int size) {
  return size;  
}

void test_write_stream(void **state) {
  
  char buffer[10] = "test";
  
  void* mock = mock_type(void*);
  Stream* stream = (Stream*)mock;
  
  will_return(stream->write, stub_write);
  
  int nwritten = write_stream(stream, buffer, sizeof(buffer));
  
  assert_int_equal(nwritten, sizeof(buffer));

}

// Define test cases
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_create_stdin_stream),
        cmocka_unit_test(test_create_stdout_stream),
        // Add more tests here 
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
