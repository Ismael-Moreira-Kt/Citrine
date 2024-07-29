#ifndef CITRINE_H
#define CITRINE_H


#include <sys/types.h>



int open_file_asm(const char *path, int flags, mode_t mode);



int create_file(const char *path, mode_t mode);



#endif