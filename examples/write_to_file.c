#include "examples.h"



void __writeToFile() {
    CitrineFile file = openFile("example.txt", O_WRONLY | O_CREAT | O_TRUNC, PERM_RW_OWNER);
    
    if (file.fd != -1) {
        const char *text = "Hello, world!";
        ssize_t bytesWritten = writeFile(&file, text, strlen(text));
        
        if (bytesWritten > 0) {
            printf("Written %zd bytes.\n", bytesWritten);
        }
        
        closeFile(&file);
    }
}