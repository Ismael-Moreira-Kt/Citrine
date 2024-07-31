#include "examples.h"



void __syncFile() {
    CitrineFile file = openFile("example.txt", O_WRONLY, 0);
    
    if (file.fd != -1) {
        int result = syncFile(&file);
    
        if (result == 0) {
            printf("File synced successfully.\n");
        } else {
            perror("sync_file failed");
        }
    
        if (closeFile(&file) != 0) {
            perror("close_file failed");
        }
    } else {
        perror("open_or_create_file failed");
    }
}