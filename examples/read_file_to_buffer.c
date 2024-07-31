#include "examples.h"



void __readFileToBuffer() {
    char *buffer;
    ssize_t size = readToBuffer("example.txt", &buffer);
    
    if (size > 0) {
        printf("Read %zd bytes: %s\n", size, buffer);
        free(buffer);
    }
}