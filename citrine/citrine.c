#include "citrine.h"



extern int open_file_asm(const char *path, int flags, mode_t mode);



int create_file(const char *path, mode_t mode) {
    int fd = open_file_asm(path, O_CREAT | O_WRONLY, mode);
    if (fd == -1) {
        perror("Error creating file");
    }
    return fd;
}