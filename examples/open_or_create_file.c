#include "examples.h"



void _openOrCreateFile() {
    CitrineFile file = openFile("example.txt", O_RDWR | O_CREAT, PERM_RW_OWNER);
    
    if (file.fd != -1) {
        printf("File opened or created successfully.\n");
        close_file(&file);
    }
}