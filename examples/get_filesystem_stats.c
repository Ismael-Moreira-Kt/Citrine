#include "examples.h"



void getFileSystemStats() {
    struct statfs fs_stats;
    int result = get_filesystem_stats("/", &fs_stats);
    
    if (result == 0) {
        printf("Filesystem stats:\n");
        printf("Block size: %ld\n", fs_stats.f_bsize);
        printf("Blocks total: %ld\n", fs_stats.f_blocks);
        printf("Blocks free: %ld\n", fs_stats.f_bfree);
        printf("Inodes total: %ld\n", fs_stats.f_files);
        printf("Inodes free: %ld\n", fs_stats.f_ffree);
    }
}