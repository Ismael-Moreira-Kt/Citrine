#include "examples.h"



void __fileExists() {
    if (fileExists("example.txt")) {
        printf("File exists.\n");
    } else {
        printf("File does not exist.\n");
    }
}