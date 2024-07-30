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
    openOrCreateFile();
    
    print_section("Write To File");
    writeToFile();
    
    print_section("Read From File");
    readFromFile();

    print_section("Read File To Buffer");
    readFileToBuffer();

    print_section("Get File Size");
    getFileSize();

    print_section("File Exists");
    fileExists();

    print_section("Sync File");
    syncFile();

    print_section("Set Permissions");
    setFilePermissions();

    print_section("Check Permissions");
    checkPermissions();

    print_section("Change File Owner");
    changeFileOwner();

    print_section("Copy File");
    copyFile();

    print_section("Rename File");
    renameFile();

    print_section("Remove File");
    removeFile();

    print_section("Create Directory");
    createDirectory();

    print_section("List Files In Directory");
    listFilesInDirectory();

    print_section("Get File System Stats");
    getFileSystemStats();

    print_section("Create Nested Directory");
    createNestedDirectory();

    print_section("Remove Directory");
    removeDirectory();
}