# _closeFile
The _closeFile function closes an open file on the Linux system using the close syscall. The function assumes that the descriptor of the file to be closed is set in the appropriate register before execution.

<br><br>

## Implementation Details:
- **Syscall Number:** 3
- **Registers Used:**
    - `rax:` Stores the syscall number (3 for close).
    - `rdi:` Descriptor of the file to be closed.

```asm
_closeFile:
    mov rax, 3
    syscall
    ret
```

<br>

#### Expected Parameters:
- **rdi:** File descriptor obtained previously, for example, through the _openFile function.

<br>