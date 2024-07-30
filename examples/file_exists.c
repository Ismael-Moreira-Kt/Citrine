#include "examples.h"



void fileExists() {
    if (file_exists("example.txt")) {
        printf("File exists.\n");
    } else {
        printf("File does not exist.\n");
    }
}