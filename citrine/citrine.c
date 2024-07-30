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



int remove_directory(const char *path) {
    int result = rmdir_asm(path);
    
    if (result == -1) {
        perror("Error removing directory");
    }
    
    return result;
}



int sync_file(CitrineFile *file) {
    int result = fsync_file_asm(file->fd);
    
    if (result == -1) {
        perror("Error syncing file");
    }
    
    return result;
}



int create_nested_directory(const char *path, mode_t mode) {
    char *temp_path = strdup(path);
    if (temp_path == NULL) {
        perror("Erro ao duplicar caminho");
        return -1;
    }

    char *dir = strtok(temp_path, "/");
    int result = 0;
    char current_path[1024] = {0};

    while (dir != NULL) {
        strcat(current_path, dir);
        printf("Tentando criar o diretório '%s'...\n", current_path);
        result = mkdir_asm(current_path, mode);

        if (result == -1 && errno != EEXIST) {
            perror("Erro ao criar diretório");
            free(temp_path);
            return -1;
        }

        strcat(current_path, "/");
        dir = strtok(NULL, "/");
    }

    free(temp_path);
    return 0;
}