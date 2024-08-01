# _fstatFile
The _fstatFile function obtains information about an open file, such as size, permissions, and timestamps, using the fstat syscall in Linux. This function is particularly useful when you already have a file descriptor and need to obtain detailed information about the corresponding file.

<br><br>

## Implementation Details:
- **Syscall Number:** 5
- **Registers Used:**
    - `rax:` Stores the syscall number.
    - `rdi:` File descriptor of the file to be inspected.
    - `rsi:` Pointer to a stat structure where file information will be stored.

```asm
_fstatFile:
    mov rax, 5
    syscall
    ret
```

<br>

#### Expected Parameters:
- **rdi:** File descriptor of the file you want to obtain information about.
- **rsi:** Pointer to the stat structure where the file information will be stored.

<br>

#### Return Value:
- **rax:** If the syscall is successful, rax will contain 0. In case of error, rax will contain a negative value corresponding to the error code.

<br>

#### Stat structure:
The stat structure is a standard structure in Linux that stores various information about the file. Some of the most common fields include:
- `st_dev:` ID of the device containing the file.
- `st_ino:` Inode number.
- `st_mode:` File type and permissions.
- `st_nlink:` Number of hard links.
- `st_uid:` Owner ID.
- `st_gid:` Group ID.
- `st_rdev:` Device ID (if it is a special device).
- `st_size:` Total file size in bytes.
- `st_blksize:` Preferred block size for file system I/O.
- `st_blocks:` Number of blocks allocated.
- `st_atime:` Last access time.
- `st_mtime:` Last modification time.
- `st_ctime:` Time of last status change.