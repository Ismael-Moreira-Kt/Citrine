#ifndef CITRINE_H
#define CITRINE_H


#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>



int open_file_asm(const char *path, int flags, mode_t mode);
ssize_t read_file_asm(int fd, void *buffer, size_t count);
ssize_t write_file_asm(int fd, const void *buffer, size_t count);
int close_file_asm(int fd);
int set_permissions_asm(const char *path, mode_t mode);



int create_file(const char *path, mode_t mode);
int open_file(const char *path, int flags);
ssize_t read_file(int fd, void *buffer, size_t count);
ssize_t write_file(int fd, const void *buffer, size_t count);
int close_file(int fd);



#endif