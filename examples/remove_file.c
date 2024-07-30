#include "examples.h"



void removeFile() {
    CitrineFile file = open_or_create_file("example.txt", O_RDWR | O_CREAT, PERM_RW_OWNER);
    int result = remove_file("example.txt");
    
    if (result == 0) {
        printf("File removed successfully.\n");
    }
}