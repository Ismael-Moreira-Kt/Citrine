#include "examples.h"



void __setFilePermissions() {
    int result = setPermissions("example.txt", PERM_RWX);
    
    if (result == 0) {
        printf("Permissions set successfully.\n");
    }
}