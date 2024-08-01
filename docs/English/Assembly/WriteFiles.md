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

<br><br>

## Usage Examples:
This example illustrates how to use _openFile to open a file, _writeFile to write data to the file, and then check the number of bytes written.

```asm
section .data
    file_path db 'examples.txt', 0
    data_to_write db 'Hello, World!', 0
    data_len equ $-data_to_write



section .text
    global _start
    extern _openFile
    extern _writeFile


_start:
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

<br><br>

## Additional Notes:
- Make sure the buffer (rsi) contains the data to be written and that the number of bytes (rdx) is correct.
- The number of bytes written is returned in rax, and the value can be zero if there is no data to write or if the file descriptor is not valid.
- In a real application, you must include additional code to handle errors and ensure that the buffer and data are handled correctly.