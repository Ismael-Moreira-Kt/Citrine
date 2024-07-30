#include "examples.h"



void writeToFile() {
    CitrineFile file = open_or_create_file("example.txt", O_WRONLY | O_CREAT | O_TRUNC, PERM_RW_OWNER);
    
    if (file.fd != -1) {
        const char *text = "Hello, world!";
        ssize_t bytesWritten = write_to_file(&file, text, strlen(text));
        
        if (bytesWritten > 0) {
            printf("Written %zd bytes.\n", bytesWritten);
        }
        
        close_file(&file);
    }
}