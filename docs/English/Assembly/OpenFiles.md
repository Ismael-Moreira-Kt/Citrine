# _openFile
The _openFile function opens a file in the Linux system using the open syscall. If the specified file exists, the function opens it according to the provided flags. If the file does not exist, the function creates it with the specified permissions.

<br><br>

## Implementation Details:
- **Syscall Number:** 2
- **Registers Used:**
    - `rax:` Stores the syscall number.
    - `rdi:` String address that represents the file path.
    - `rsi:` Flags that specify the opening mode.
    - `rdx:` Permissions for the file in case of creation.

```asm
_openFile:
    mov rax, 2
    syscall
    ret
```

#### Expected Parameters:
- **rdi:** Pointer to the string with the file path. The string must be NULL terminated.
- **rsi:** Flags that define the file opening behavior. Common examples include:
    - `O_CREAT (0x40):` Creates the file if it does not exist.
    - `O_WRONLY (0x01):` Opens the file for writing.
    - `O_RDONLY (0x00):` Opens the file for reading.
- **rdx:** File creation permissions (e.g. 0644), only used if the file is created.