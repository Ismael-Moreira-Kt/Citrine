#include "examples.h"



void __copyFile() {
    const char *source_path = "example.txt";
    const char *destination_path = "copy_of_example.txt";

    int result = copyFile(source_path, destination_path);
    
    if (result == 0) {
        printf("File copied successfully.\n");
        
        mode_t permissions = PERM_RW_OWNER;

        if (setPermissions(destination_path, permissions) == 0) {
            printf("Permissions set successfully on copied file.\n");
        } else {
            printf("Error setting permissions on copied file.\n");
        }
    } else {
        printf("Error copying file.\n");
    }
}