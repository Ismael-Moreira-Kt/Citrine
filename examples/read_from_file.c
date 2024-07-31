#include "examples.h"



void _readFromFile() {
    CitrineFile file = openFile("example.txt", O_RDONLY, 0);
    
    if (file.fd != -1) {
        char buffer[256];
        ssize_t bytesRead = readFile(&file, buffer, sizeof(buffer) - 1);
    
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';
            printf("Read %zd bytes: %s\n", bytesRead, buffer);
        }
    
        close_file(&file);
    }
}