#include "examples.h"



void renameFile() {
    int result = rename_file("example.txt", "new_name.txt");
    
    if (result == 0) {
        printf("File renamed successfully.\n");
    }
}