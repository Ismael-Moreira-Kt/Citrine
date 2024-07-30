#include "examples.h"



void getFileSize() {
    const char *filePath = "example.txt";
    CitrineFile file = open_or_create_file(filePath, O_RDWR | O_CREAT, PERM_RW_OWNER);
    
    ssize_t size = get_file_size(&file);

    if (size == -1) {
        printf("Error: Could not get file size. Check file permissions or if the file is accessible.\n");
    } else {
        printf("File size: %zd bytes\n", size);
    }

    if (close_file(&file) != 0) {
        printf("Error: Could not close the file.\n");
    }
}