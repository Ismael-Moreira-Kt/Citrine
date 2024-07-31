#include "examples.h"



void __getFileSize() {
    const char *filePath = "example.txt";
    CitrineFile file = openFile(filePath, O_RDWR | O_CREAT, PERM_RW_OWNER);
    
    ssize_t size = getFileSize(&file);

    if (size == -1) {
        printf("Error: Could not get file size. Check file permissions or if the file is accessible.\n");
    } else {
        printf("File size: %zd bytes\n", size);
    }

    if (closeFile(&file) != 0) {
        printf("Error: Could not close the file.\n");
    }
}