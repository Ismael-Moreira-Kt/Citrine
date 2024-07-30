#include "examples.h"



void checkPermissions() {
    if (check_permissions("example.txt", PERM_R) == 0) {
        printf("File has the specified permissions.\n");
    } else {
        printf("File does not have the specified permissions.\n");
    }   
}