#ifndef CITRINE_H
#define CITRINE_H


#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>


typedef struct {
    int fd;
    const char *path;
} CitrineFile;



#define PERM_RW_OWNER (S_IRUSR | S_IWUSR)
#define PERM_RWX_OWNER (S_IRUSR | S_IWUSR | S_IXUSR)
#define PERM_RW_OWNER_R_ALL (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define PERM_R (S_IRUSR | S_IRGRP | S_IROTH)
#define PERM_RW (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define PERM_RWX (S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)



int open_file_asm(const char *path, int flags, mode_t mode);
ssize_t read_file_asm(int fd, void *buffer, size_t count);
ssize_t write_file_asm(int fd, const void *buffer, size_t count);
int close_file_asm(int fd);
int set_permissions_asm(const char *path, mode_t mode);



CitrineFile open_or_create_file(const char *path, int flags, mode_t mode);
ssize_t read_from_file(CitrineFile *file, void *buffer, size_t count);
ssize_t write_to_file(CitrineFile *file, const void *buffer, size_t count);
int close_file(CitrineFile *file);
int set_file_permissions(const char *path, mode_t mode);



#endif