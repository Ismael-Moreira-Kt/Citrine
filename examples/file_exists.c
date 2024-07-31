#include "examples.h"



void _fileExists() {
    if (fileExists("example.txt")) {
        printf("File exists.\n");
    } else {
        printf("File does not exist.\n");
    }
}