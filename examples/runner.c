#include "examples.h"
#define WIDTH 75



void print_section(const char *title) {
    int title_length = strlen(title);
    int padding = (WIDTH - title_length) / 2;
    
    printf("\n");
    for (int i = 0; i < WIDTH; i++) {
        printf("-");
    }

    printf("\n");
    for (int i = 0; i < padding; i++) {
        printf("-");
    }

    printf("%s", title);
    for (int i = 0; i < padding; i++) {
        printf("-");
    }

    printf("\n");
    for (int i = 0; i < WIDTH; i++) {
        printf("-");
    }

    printf("\n");
}



int main() {
    print_section("Open or Create File");
    __openOrCreateFile();
    
    print_section("Write To File");
    __writeToFile();
    
    print_section("Read From File");
    __readFromFile();

    print_section("Read File To Buffer");
    __readFileToBuffer();

    print_section("Get File Size");
    __getFileSize();

    print_section("File Exists");
    __fileExists();

    print_section("Sync File");
    __syncFile();

    print_section("Set Permissions");
    __setFilePermissions();

    print_section("Check Permissions");
    __checkPermissions();

    print_section("Change File Owner");
    __changeFileOwner();

    print_section("Copy File");
    __copyFile();

    print_section("Rename File");
    __renameFile();

    print_section("Remove File");
    __removeFile();

    print_section("Create Directory");
    __createDirectory();

    print_section("List Files In Directory");
    __listFilesInDirectory();

    print_section("Get File System Stats");
    __getFileSystemStats();

    print_section("Create Nested Directory");
    __createNestedDirectory();

    print_section("Remove Directory");
    __removeDirectory();
}