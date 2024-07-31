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
    _openOrCreateFile();
    
    print_section("Write To File");
    _writeToFile();
    
    print_section("Read From File");
    _readFromFile();

    print_section("Read File To Buffer");
    _readFileToBuffer();

    print_section("Get File Size");
    _getFileSize();

    print_section("File Exists");
    _fileExists();

    print_section("Sync File");
    _syncFile();

    print_section("Set Permissions");
    _setFilePermissions();

    print_section("Check Permissions");
    _checkPermissions();

    print_section("Change File Owner");
    _changeFileOwner();

    print_section("Copy File");
    _copyFile();

    print_section("Rename File");
    _renameFile();

    print_section("Remove File");
    _removeFile();

    print_section("Create Directory");
    _createDirectory();

    print_section("List Files In Directory");
    _listFilesInDirectory();

    print_section("Get File System Stats");
    _getFileSystemStats();

    print_section("Create Nested Directory");
    _createNestedDirectory();

    print_section("Remove Directory");
    _removeDirectory();
}