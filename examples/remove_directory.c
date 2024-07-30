#include "examples.h"



void removeDirectory() {
    int result = remove_directory("example_dir");
    
    if (result == 0) {
        printf("Directory removed successfully.\n");
    } else {
        perror("remove_directory failed");
    }
}