#ifndef IO_H
#define IO_H

#include <stdio.h>

// Abstract stream type 
typedef struct Stream Stream;

// Create stream for stdin
Stream* create_stdin_stream();

// Create stream for stdout
Stream* create_stdout_stream();

// Create file input stream
Stream* create_file_input_stream(const char* path);

// Create file output stream
Stream* create_file_output_stream(const char* path);

// Read data from stream
int read_stream(Stream* stream, void* buffer, int size);

// Destroy stream and free memory
void destroy_stream(Stream* stream);

#endif
