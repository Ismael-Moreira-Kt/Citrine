#include "examples.h"



void createDirectory() {
    int result = create_directory("example_dir", PERM_RW_OWNER);
    
    if (result == 0) {
        printf("Directory created successfully.\n");
    } else {
        perror("create_directory failed");
    }
}