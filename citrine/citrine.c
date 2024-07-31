#include "citrine.h"



CitrineFile openFile(const char *path, int flags, mode_t mode) {
    CitrineFile file;
    
    file.fd = _openFile(path, flags, mode);
    file.path = path;

    if (file.fd == -1) {
        perror("Error opening or creating file");
    }

    return file;
}



ssize_t readFile(CitrineFile *file, void *buffer, size_t count) {
    ssize_t bytesRead = _readFile(file->fd, buffer, count);

    if (bytesRead == -1) {
        perror("Error reading file");
    }

    return bytesRead;
}



ssize_t writeFile(CitrineFile *file, const void *buffer, size_t count) {
    ssize_t bytesWritten = _writeFile(file->fd, buffer, count);

    if (bytesWritten == -1) {
        perror("Error writing file");
    }

    return bytesWritten;
}



int closeFile(CitrineFile *file) {
    int result = _closeFile(file->fd);

    if (result == -1) {
        perror("Error closing file");
    }

    return result;
}



int setPermissions(const char *path, mode_t mode) {
    int result = _setPermissions(path, mode);

    if (result == -1) {
        perror("Error setting permissions");
    }

    return result;
}



int fileExists(const char *path) {
    return (_accessFile(path, F_OK) != -1);
}



ssize_t getFileSize(CitrineFile *file) {
    struct stat st;

    if (_fstatFile(file->fd, &st) == 0)
        return st.st_size;

    perror("Error getting file size");
    
    return -1;
}



int createDirectory(const char *path, mode_t mode) {
    int result = _mkdir(path, mode);

    if (result == -1) {
        perror("Error creating directory");
    }

    return result;
}



int removeFile(const char *path) {
    int result = _unlinkFile(path);

    if (result == -1) {
        perror("Error removing file");
    }

    return result;
}



int renameFile(const char *oldpath, const char *newpath) {
    int result = _renameFile(oldpath, newpath);

    if (result == -1) {
        perror("Error renaming file");
    }

    return result;
}



int syncFile(CitrineFile *file) {
    int result = _fsyncFile(file->fd);

    if (result == -1) {
        perror("Error syncing file");
        return -1;
    }

    return 0;
}



int removeDirectory(const char *path) {
    int result = _rmdir(path);

    if (result == -1) {
        perror("Error removing directory");
        return -1;
    }

    return 0;
}



int createNestedDirectory(const char *path, mode_t mode) {
    char *temp_path = strdup(path);
    if (temp_path == NULL) {
        perror("Error duplicating path");

        return -1;
    }

    char *dir = strtok(temp_path, "/");
    int result = 0;
    char current_path[1024] = {0};

    while (dir != NULL) {
        strcat(current_path, dir);

        result = _mkdir(current_path, mode);

        if (result == -1 && errno != EEXIST) {
            perror("Error creating directory");
            free(temp_path);

            return -1;
        }

        strcat(current_path, "/");
        dir = strtok(NULL, "/");
    }

    free(temp_path);

    return 0;
}



ssize_t readToBuffer(const char *path, char **buffer) {
    CitrineFile file = openFile(path, O_RDONLY, 0);

    if (file.fd == -1) return -1;

    ssize_t size = getFileSize(&file);

    if (size == -1) {
        closeFile(&file);

        return -1;
    }

    *buffer = (char *)malloc(size);

    if (*buffer == NULL) {
        perror("Error allocating buffer");
        closeFile(&file);

        return -1;
    }

    ssize_t bytesRead = readFile(&file, *buffer, size);
    closeFile(&file);

    return (bytesRead == size) ? size : -1;
}



int checkPermissions(const char *path, mode_t mode) {
    struct stat st;

    if (_accessFile(path, F_OK) != -1) {
        if (_fstatFile(_openFile(path, O_RDONLY, 0), &st) == 0) {
            if ((st.st_mode & mode) == mode) {
                return 1;
            }
        }
    }

    return 0;
}



char **listFiles(const char *path, size_t *file_count) {
    DIR *dir;
    struct dirent *entry;
    char **file_list = NULL;
    size_t count = 0;

    dir = opendir(path);

    if (dir == NULL) {
        perror("Error opening directory");

        return NULL;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            file_list = (char **)realloc(file_list, sizeof(char *) * (count + 1));
            file_list[count] = strdup(entry->d_name);

            count++;
        }
    }

    closedir(dir);

    *file_count = count;

    return file_list;
}



int changeOwner(const char *path, uid_t owner, gid_t group) {
    int result = _chownFile(path, owner, group);

    if (result == -1) {
        perror("Error changing file owner");
    }

    return result;
}



int copyFile(const char *source_path, const char *destination_path) {
    CitrineFile src_file = openFile(source_path, O_RDONLY, 0);
    if (src_file.fd == -1) return -1;

    CitrineFile dest_file = openFile(destination_path, O_WRONLY | O_CREAT | O_TRUNC, PERM_RW_OWNER);
    if (dest_file.fd == -1) {
        closeFile(&src_file);
        return -1;
    }

    char buffer[4096];
    ssize_t bytes_read;
    while ((bytes_read = readFile(&src_file, buffer, sizeof(buffer))) > 0) {
        if (writeFile(&dest_file, buffer, bytes_read) != bytes_read) {
            perror("Error writing to destination file");
            closeFile(&src_file);
            closeFile(&dest_file);
            return -1;
        }
    }

    if (bytes_read == -1) {
        perror("Error reading from source file");
    }

    closeFile(&src_file);
    closeFile(&dest_file);
    return (bytes_read == -1) ? -1 : 0;
}



int getFileStats(const char *path, struct statfs *buf) {
    int result = _statfs(path, buf);

    if (result == -1) {
        perror("Error getting filesystem statistics");
    }

    return result;
}