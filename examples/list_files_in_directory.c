#include "examples.h"



void listFilesInDirectory() {
    size_t file_count;
    char **files = list_files_in_directory(".", &file_count);
    
    if (files != NULL) {
        printf("Files in directory:\n");
    
        for (size_t i = 0; i < file_count; i++) {
            printf("%s\n", files[i]);
            free(files[i]);
        }
    
        free(files);
    } else {
        perror("list_files_in_directory failed");
    }
}