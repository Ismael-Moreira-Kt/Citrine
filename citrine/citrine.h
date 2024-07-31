#ifndef CITRINE_H
#define CITRINE_H



#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/statfs.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>



#define PERM_RW_OWNER (S_IRUSR | S_IWUSR)
#define PERM_RWX_OWNER (S_IRUSR | S_IWUSR | S_IXUSR)
#define PERM_RW_OWNER_R_ALL (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define PERM_R (S_IRUSR | S_IRGRP | S_IROTH)
#define PERM_RW (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define PERM_RWX (S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)



typedef struct {
    int fd;
    const char *path;
} CitrineFile;



int _accessFile(const char *path, int mode);
int _chownFile(const char *path, uid_t owner, gid_t group);
int _closeFile(int fd);
int _copyFile(const char *source, const char *destination);
int _fstatFile(int fd, struct stat *statbuf);
int _fsyncFile(int fd);
int _mkdir(const char *pathname, mode_t mode);
int _openFile(const char *path, int flags, mode_t mode);
int _renameFile(const char *oldpath, const char *newpath);
int _rmdir(const char *pathname);
int _setPermissions(const char *path, mode_t mode);
int _statfs(const char *path, struct statfs *buf);
int _unlinkFile(const char *path);
ssize_t _readFile(int fd, void *buffer, size_t count);
ssize_t _writeFile(int fd, const void *buffer, size_t count);



char **listFiles(const char *path, size_t *file_count);
CitrineFile openFile(const char *path, int flags, mode_t mode);
int changeOwner(const char *path, uid_t owner, gid_t group);
int checkPermissions(const char *path, mode_t mode);
int closeFile(CitrineFile *file);
int copyFile(const char *source_path, const char *destination_path);
int createDirectory(const char *path, mode_t mode);
int createNestedDirectory(const char *path, mode_t mode);
int fileExists(const char *path);
int getFileStats(const char *path, struct statfs *buf);
int removeDirectory(const char *path);
int removeFile(const char *path);
int renameFile(const char *oldpath, const char *newpath);
int setPermissions(const char *path, mode_t mode);
int syncFile(CitrineFile *file);
ssize_t getFileSize(CitrineFile *file);
ssize_t readFile(CitrineFile *file, void *buffer, size_t count);
ssize_t readToBuffer(const char *path, char **buffer);
ssize_t writeFile(CitrineFile *file, const void *buffer, size_t count);



#endif