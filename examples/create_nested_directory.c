#include "examples.h"



void createNestedDirectory() {
    int result = create_nested_directory("parent/child/grandchild", PERM_RWX_OWNER);
    
    if (result == 0) {
        printf("Nested directories created successfully.\n");
    }
}