#include "examples.h"



void openOrCreateFile() {
    CitrineFile file = open_or_create_file("example.txt", O_RDWR | O_CREAT, PERM_RW_OWNER);
    
    if (file.fd != -1) {
        printf("File opened or created successfully.\n");
        close_file(&file);
    }
}