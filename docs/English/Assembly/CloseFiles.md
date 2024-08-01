# _closeFile
The _closeFile function closes an open file on the Linux system using the close syscall. The function assumes that the descriptor of the file to be closed is set in the appropriate register before execution.

<br><br>

## Implementation Details:
- **Syscall Number:** 3
- **Registers Used:**
    - `rax:` Stores the syscall number.
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

#### Return Value:
- **rax:** If the syscall is successful, rax will contain 0. In case of error, rax will contain a negative value corresponding to the error code.

<br><br>

## Usage Examples:
This example demonstrates how to use _openFile to open a file, _writeFile to write data to the file, and _closeFile to close the file after writing.

```asm
section .data
    file_path db 'example.txt', 0
    data_to_write db 'Hello, World!', 0
    data_len equ $-data_to_write



section .text
    global _start
    extern _openFile
    extern _writeFile
    extern _closeFile


_start:
    ; Abrir o arquivo 
    mov rdi, file_path
    mov rsi, 0x41
    mov rdx, 0644
    call _openFile
    
    mov rdi, rax
    mov rsi, data_to_write
    mov rdx, data_len
    call _writeFile
    
    test rax, rax
    js error

    call _closeFile

    mov rax, 60
    xor rdi, rdi
    syscall


error:
    call _closeFile

    mov rax, 60
    xor rdi, rdi
    syscall
```

<br><br>

## Additional Notes:
- The _closeFile function should be called whenever a file is no longer needed to free the file descriptor and prevent resource leaks.
- Check the return value of _closeFile to ensure the file was closed correctly, especially in critical cases where failure to close a file could have consequences.