#include "examples.h"



void setFilePermissions() {
    int result = set_file_permissions("example.txt", PERM_RWX);
    
    if (result == 0) {
        printf("Permissions set successfully.\n");
    }
}