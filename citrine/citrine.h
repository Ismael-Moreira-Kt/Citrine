#ifndef CITRINE_H
#define CITRINE_H


#include <sys/types.h>
#include <fcntl.h> 



int open_file_asm(const char *path, int flags, mode_t mode);
ssize_t read_file_asm(int fd, void *buffer, size_t count);



int create_file(const char *path, mode_t mode);
int open_file(const char *path, int flags);



#endif