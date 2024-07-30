#include "citrine.h"



extern int open_file_asm(const char *path, int flags, mode_t mode);
extern ssize_t read_file_asm(int fd, void *buffer, size_t count);
extern ssize_t write_file_asm(int fd, const void *buffer, size_t count);
extern int close_file_asm(int fd);
extern int set_permissions_asm(const char *path, mode_t mode);



CitrineFile open_ile(const char *path, int flags, mode_t mode) {
    CitrineFile file;
    
    file.fd = open_file_asm(path, flags, mode);
    file.path = path;
    
    if (file.fd == -1) {
        perror("Error opening or creating file");
    }
    
    return file;
}



ssize_t read_from_file(CitrineFile *file, void *buffer, size_t count) {
    ssize_t bytesRead = read_file_asm(file->fd, buffer, count);
    
    if (bytesRead == -1) {
        perror("Error reading file");
    }
    
    return bytesRead;
}



ssize_t write_to_file(CitrineFile *file, const void *buffer, size_t count) {
    ssize_t bytesWritten = write_file_asm(file->fd, buffer, count);
    
    if (bytesWritten == -1) {
        perror("Error writing file");
    }
    
    return bytesWritten;
}



int close_file(CitrineFile *file) {
    int result = close_file_asm(file->fd);
    
    if (result == -1) {
        perror("Error closing file");
    }
    
    return result;
}



int set_file_permissions(const char *path, mode_t mode) {
    int result = set_permissions_asm(path, mode);
    
    if (result == -1) {
        perror("Error setting permissions");
    }
    
    return result;
}