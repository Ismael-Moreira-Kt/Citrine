#include "examples.h"



void __checkPermissions() {
    if (checkPermissions("example.txt", PERM_R) == 0) {
        printf("File has the specified permissions.\n");
    } else {
        printf("File does not have the specified permissions.\n");
    }   
}