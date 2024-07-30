#include "examples.h"



void changeFileOwner() {
    int result = change_file_owner("example.txt", getuid(), getgid());
    
    if (result == 0) {
        printf("File owner changed successfully.\n");
    }
}