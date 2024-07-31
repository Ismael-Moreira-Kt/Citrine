#include "examples.h"



void __changeFileOwner() {
    int result = changeOwner("example.txt", getuid(), getgid());

    if (result == 0) {
        printf("File owner changed successfully.\n");
    }
}