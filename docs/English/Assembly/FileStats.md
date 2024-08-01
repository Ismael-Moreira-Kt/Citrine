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