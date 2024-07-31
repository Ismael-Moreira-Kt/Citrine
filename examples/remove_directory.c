#include "examples.h"



void __removeDirectory() {
    int result = removeDirectory("example_dir");
    
    if (result == 0) {
        printf("Directory removed successfully.\n");
    } else {
        perror("remove_directory failed");
    }
}