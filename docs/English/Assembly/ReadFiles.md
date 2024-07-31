# _readFile
The _readFile function reads data from a file on the Linux system using the read syscall. The function assumes that the necessary parameters, such as the file descriptor, the buffer for the data, and the number of bytes to be read, are set in the appropriate registers before execution.

<br><br>

## Implementation Details:
- **Syscall Number:** 0
- **Registers Used:**
    - `rax:` Stores the syscall number.
    - `rdi:` Descriptor of the file from which data will be read.
    - `rsi:` Address of the buffer where the read data will be stored.
    - `rdx:` Number of bytes to be read.

```asm
_readFile:
    mov rax, 0
    syscall
    ret
```

<br>

#### Expected Parameters:
- **rdi:** File descriptor obtained previously, for example, through the [_openFile](./OpenFiles.md) function.
- **rsi:** Pointer to the buffer where the read data will be stored. The buffer must be allocated large enough to store the data.
- **rdx:** Maximum number of bytes to be read from the file.