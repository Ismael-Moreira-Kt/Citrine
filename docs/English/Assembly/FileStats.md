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

<br><br>

## Example of use:
This example demonstrates how to use _fstatFile to obtain information about a file, using a file descriptor previously obtained by _openFile.

```asm
section .data
    file_path db 'example.txt', 0
    stat_buf times 144 db 0



section .text
    global _start
    extern _openFile
    extern _fstatFile
    extern _closeFile


_start:
    mov rdi, file_path
    xor rsi, rsi
    call _openFile

    test rax, rax
    js error

    mov rdi, rax
    mov rsi, stat_buf
    call _fstatFile
    
    test rax, rax
    js error

    mov rax, [stat_buf + 48]
    mov rdi, rax
    call _closeFile

    mov rax, 60
    xor rdi, rdi
    syscall


error:
    mov rax, 60
    xor rdi, rdi
    syscall
```

<br><br>

## Additional Notes:
- The _fstatFile function is essential for collecting detailed information about an open file, without having to close and reopen the file.
- The example above only includes reading the file size, but you can access any other information available in the stat structure using the correct offsets.