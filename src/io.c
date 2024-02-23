#include <stdio.h>
#include <stdlib.h>

#include "../include/io.h"

struct Stream {
    FILE* file;
}; 

struct FileInputStream {
};

struct FileOutputStream {
};


struct Stream* create_stdin_stream() {
    Stream* stream = malloc(sizeof(Stream));
    stream->file = stdin;
    return stream;
} 

struct Stream* create_stdout_stream() {
    Stream* stream = malloc(sizeof(Stream));
    stream->file = stdout;
    return stream;
}

struct Stream* create_file_input_stream(const char* path) {
    Stream* stream = malloc(sizeof(Stream));
    stream->file = fopen(path,"r");
    return stream;
} 

struct Stream* create_file_output_stream(const char* path) {
    Stream* stream = malloc(sizeof(Stream));
    stream->file = fopen(path,"w");
    return stream;
} 

int read_stream(Stream *stream, void *buffer, int size) {
    return fread(buffer, 1, size, stream->file);
} 

int write_stream(Stream *stream, void *buffer, int size) {
    return fwrite(buffer, 1, size, stream->file);
} 

void destroy_stream(Stream *stream) {
    fclose(stream->file);
    free(stream);
} 


