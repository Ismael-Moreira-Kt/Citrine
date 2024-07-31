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

<br>

#### Return Value:
- **rax:** If the syscall is successful, rax contains the number of bytes actually read. If the return is zero, this indicates that the end of the file has been reached. In case of an error, rax will contain a negative value corresponding to the error code.

<br><br>

## Example
This example shows how to use _openFile to open a file, _readFile to read its contents, and then print the contents to the screen.

```asm
section .data
    file_path db 'example.txt', 0 
    msg db 'Bytes read: ', 0
    msg_len equ $-msg



section .bss
    buffer resb 100



section .text
    global _start
    extern _openFile
    extern _readFile


_start:
    mov rdi, file_path 
    mov rsi, 0x00
    xor rdx, rdx 
    call _openFile
    mov rdi, rax 

    mov rsi, buffer
    mov rdx, 100
    call _readFile

    test rax, rax
    js error

    mov rbx, rax
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, msg_len
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, buffer
    mov rdx, rbx
    syscall

    mov rax, 3
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall


error:
    mov rax, 3
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall
```