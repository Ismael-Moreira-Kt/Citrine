#include "examples.h"



void _removeFile() {
    CitrineFile file = openFile("example.txt", O_RDWR | O_CREAT, PERM_RW_OWNER);
    int result = removeFile("example.txt");
    
    if (result == 0) {
        printf("File removed successfully.\n");
    }
}