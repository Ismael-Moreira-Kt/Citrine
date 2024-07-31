#include "examples.h"



void __createNestedDirectory() {
    int result = createNestedDirectory("parent/child/grandchild", PERM_RWX_OWNER);
    
    if (result == 0) {
        printf("Nested directories created successfully.\n");
    }
}