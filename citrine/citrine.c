#include "citrine.h"



extern int open_file_asm(const char *path, int flags, mode_t mode);
extern ssize_t read_file_asm(int fd, void *buffer, size_t count);
extern ssize_t write_file_asm(int fd, const void *buffer, size_t count);
extern int close_file_asm(int fd);
extern int set_permissions_asm(const char *path, mode_t mode);



int create_file(const char *path, mode_t mode) {
    int fd = open_file_asm(path, O_CREAT | O_WRONLY, mode);

    if (fd == -1) {
        perror("Error creating file");
    }

    return fd;
}



int open_file(const char *path, int flags) {
    int fd = open_file_asm(path, flags, 0);

    if (fd == -1) {
        perror("Error opening file");
    }

    return fd;
}



ssize_t read_file(int fd, void *buffer, size_t count) {
    ssize_t bytesRead = read_file_asm(fd, buffer, count);

    if (bytesRead == -1) {
        perror("Error reading file");
    }

    return bytesRead;
}



ssize_t write_file(int fd, const void *buffer, size_t count) {
    ssize_t bytesWritten = write_file_asm(fd, buffer, count);

    if (bytesWritten == -1) {
        perror("Error writing file");
    }

    return bytesWritten;
}



int close_file(int fd) {
    int result = close_file_asm(fd);
 
    if (result == -1) {
        perror("Error closing file");
    }
 
    return result;
}



int set_permissions(const char *path, mode_t mode) {
    int result = set_permissions_asm(path, mode);
    
    if (result == -1) {
        perror("Error setting permissions");
    }
    
    return result;
}