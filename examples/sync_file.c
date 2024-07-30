#include "examples.h"



void syncFile() {
    CitrineFile file = open_or_create_file("example.txt", O_WRONLY, 0);
    
    if (file.fd != -1) {
        int result = sync_file(&file);
    
        if (result == 0) {
            printf("File synced successfully.\n");
        } else {
            perror("sync_file failed");
        }
    
        if (close_file(&file) != 0) {
            perror("close_file failed");
        }
    } else {
        perror("open_or_create_file failed");
    }
}