#include "examples.h"



void _renameFile() {
    int result = renameFile("example.txt", "new_name.txt");
    
    if (result == 0) {
        printf("File renamed successfully.\n");
    }
}