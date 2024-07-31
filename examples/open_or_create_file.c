#include "examples.h"



void __openOrCreateFile() {
    CitrineFile file = openFile("example.txt", O_RDWR | O_CREAT, PERM_RW_OWNER);
    
    if (file.fd != -1) {
        printf("File opened or created successfully.\n");
        closeFile(&file);
    }
}