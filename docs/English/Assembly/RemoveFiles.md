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