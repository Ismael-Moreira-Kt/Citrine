#ifndef CITRINE_H
#define CITRINE_H



#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>



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
int unlink_file_asm(const char *path);
int access_file_asm(const char *path, int mode);
int fstat_file_asm(int fd, struct stat *statbuf);
int mkdir_asm(const char *pathname, mode_t mode);
int rename_file_asm(const char *oldpath, const char *newpath);
int rmdir_asm(const char *pathname);
int fsync_file_asm(int fd);



CitrineFile open_or_create_file(const char *path, int flags, mode_t mode);
ssize_t read_from_file(CitrineFile *file, void *buffer, size_t count);
ssize_t write_to_file(CitrineFile *file, const void *buffer, size_t count);
int close_file(CitrineFile *file);
int set_file_permissions(const char *path, mode_t mode);
int file_exists(const char *path);
ssize_t get_file_size(CitrineFile *file);
int create_directory(const char *path, mode_t mode);
int remove_file(const char *path);
int rename_file(const char *oldpath, const char *newpath);
int remove_directory(const char *path);
int sync_file(CitrineFile *file);
int create_nested_directory(const char *path, mode_t mode);
ssize_t read_file_to_buffer(const char *path, char **buffer);
int check_permissions(const char *path, mode_t mode);
char **list_files_in_directory(const char *path, size_t *file_count);



#endif