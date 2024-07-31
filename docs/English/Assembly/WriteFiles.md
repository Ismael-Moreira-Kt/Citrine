# _writeFile
The _writeFile function writes data to a file on the Linux system using the write syscall. The function assumes that the necessary parameters, such as the file descriptor, the data buffer, and the number of bytes to be written, are set in the appropriate registers before execution.

<br><br>

## Implementation Details:
- **Syscall Number:** 1
- **Registers Used:**
    - `rax:` Stores the syscall number.
    - `rdi:` Descriptor of the file to which the data will be written.
    - `rsi:` Address of the buffer containing the data to be written.
    - `rdx:` Number of bytes to be written.

```asm
_writeFile:
    mov rax, 1
    syscall
    ret
```

<br>

#### Expected Parameters:
- **rdi:** File descriptor obtained previously, for example, through the _openFile function.
- **rsi:** Pointer to the buffer containing the data to be written to the file.
- **rdx:** Number of bytes to be written to the file.

<br>

#### Return Value:
- **rax:** If the syscall is successful, rax will contain the number of bytes actually written. In case of an error, rax will contain a negative value corresponding to the error code.