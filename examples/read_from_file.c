#include "examples.h"



void readFromFile() {
    CitrineFile file = open_or_create_file("example.txt", O_RDONLY, 0);
    
    if (file.fd != -1) {
        char buffer[256];
        ssize_t bytesRead = read_from_file(&file, buffer, sizeof(buffer) - 1);
    
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0'; // Null-terminate the buffer
            printf("Read %zd bytes: %s\n", bytesRead, buffer);
        }
    
        close_file(&file);
    }
}