#include "citrine.h"



CitrineFile open_or_create_file(const char *path, int flags, mode_t mode) {
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



int file_exists(const char *path) {
    return (access_file_asm(path, F_OK) != -1);
}



ssize_t get_file_size(CitrineFile *file) {
    struct stat st;

    if (fstat_file_asm(file->fd, &st) == 0)
        return st.st_size;

    perror("Error getting file size");
    
    return -1;
}



int create_directory(const char *path, mode_t mode) {
    int result = mkdir_asm(path, mode);

    if (result == -1) {
        perror("Error creating directory");
    }

    return result;
}



int remove_file(const char *path) {
    int result = unlink_file_asm(path);

    if (result == -1) {
        perror("Error removing file");
    }

    return result;
}



int rename_file(const char *oldpath, const char *newpath) {
    int result = rename_file_asm(oldpath, newpath);

    if (result == -1) {
        perror("Error renaming file");
    }

    return result;
}



int sync_file(CitrineFile *file) {
    int result = fsync_file_asm(file->fd);

    if (result == -1) {
        perror("Error syncing file");
        return -1;
    }

    return 0;
}



int remove_directory(const char *path) {
    int result = rmdir_asm(path);

    if (result == -1) {
        perror("Error removing directory");
        return -1;
    }

    return 0;
}



int create_nested_directory(const char *path, mode_t mode) {
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

        result = mkdir_asm(current_path, mode);

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



ssize_t read_file_to_buffer(const char *path, char **buffer) {
    CitrineFile file = open_or_create_file(path, O_RDONLY, 0);

    if (file.fd == -1) return -1;

    ssize_t size = get_file_size(&file);

    if (size == -1) {
        close_file(&file);

        return -1;
    }

    *buffer = (char *)malloc(size);

    if (*buffer == NULL) {
        perror("Error allocating buffer");
        close_file(&file);

        return -1;
    }

    ssize_t bytesRead = read_from_file(&file, *buffer, size);
    close_file(&file);

    return (bytesRead == size) ? size : -1;
}



int check_permissions(const char *path, mode_t mode) {
    struct stat st;

    if (access_file_asm(path, F_OK) != -1) {
        if (fstat_file_asm(open_file_asm(path, O_RDONLY, 0), &st) == 0) {
            if ((st.st_mode & mode) == mode) {
                return 1;
            }
        }
    }

    return 0;
}



char **list_files_in_directory(const char *path, size_t *file_count) {
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



int change_file_owner(const char *path, uid_t owner, gid_t group) {
    int result = chown_file_asm(path, owner, group);

    if (result == -1) {
        perror("Error changing file owner");
    }

    return result;
}



int copy_file(const char *source_path, const char *destination_path) {
    CitrineFile src_file = open_or_create_file(source_path, O_RDONLY, 0);
    if (src_file.fd == -1) return -1;

    CitrineFile dest_file = open_or_create_file(destination_path, O_WRONLY | O_CREAT | O_TRUNC, PERM_RW_OWNER);
    if (dest_file.fd == -1) {
        close_file(&src_file);
        return -1;
    }

    char buffer[4096];
    ssize_t bytes_read;
    while ((bytes_read = read_from_file(&src_file, buffer, sizeof(buffer))) > 0) {
        if (write_to_file(&dest_file, buffer, bytes_read) != bytes_read) {
            perror("Error writing to destination file");
            close_file(&src_file);
            close_file(&dest_file);
            return -1;
        }
    }

    if (bytes_read == -1) {
        perror("Error reading from source file");
    }

    close_file(&src_file);
    close_file(&dest_file);
    return (bytes_read == -1) ? -1 : 0;
}