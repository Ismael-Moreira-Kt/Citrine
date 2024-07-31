#include "examples.h"



void _createDirectory() {
    int result = createDirectory("example_dir", PERM_RW_OWNER);
    
    if (result == 0) {
        printf("Directory created successfully.\n");
    } else {
        perror("create_directory failed");
    }
}