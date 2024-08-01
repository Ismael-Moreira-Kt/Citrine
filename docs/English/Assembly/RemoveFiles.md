# _unlinkFile
The _unlinkFile function removes a file from the file system in Linux using the unlink syscall. When called, the function unlinks the specified file name from its inode, effectively deleting the file from the system if this is the last link to the inode.

<br><br>

## Implementation Details:
- **Syscall Number:** 87
- **Registers Used:**
    - `rax:` Stores the syscall number.
    - `rdi:` Pointer to the string containing the path of the file to be removed.

```asm
_unlinkFile:
    mov rax, 87
    syscall
    ret
```

<br>

#### Expected Parameters:
- **rdi:** Pointer to the string containing the path of the file that will be removed.

<br>

#### Return Value:
- **rax:** If the syscall is successful, rax will contain 0. In case of error, rax will contain a negative value corresponding to the error code.

<br><br>

## Example of use:
This example demonstrates how to use _unlinkFile to delete a file from the file system.

```asm
section .data
    file_path db 'example.txt', 0



section .text
    global _start
    extern _unlinkFile


_start:
    mov rdi, file_path
    call _unlinkFile

    test rax, rax
    js error

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
- The _unlinkFile function removes the link to a file from the file system. If the file is the only link to the inode, disk space is freed.
- The code above assumes that the file to be removed exists and that you have the necessary permissions to delete it.
- On critical systems, it is recommended to perform additional checks before removing files, such as backups or user commits.