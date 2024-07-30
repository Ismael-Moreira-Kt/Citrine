#include "examples.h"



void readFileToBuffer() {
    char *buffer;
    ssize_t size = read_file_to_buffer("example.txt", &buffer);
    
    if (size > 0) {
        printf("Read %zd bytes: %s\n", size, buffer);
        free(buffer);
    }
}