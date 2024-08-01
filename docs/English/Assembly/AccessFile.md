# _accessFile
The _accessFile function checks the accessibility of a file on the Linux file system using the access syscall. This function can be used to check whether a file exists and/or whether the process has the necessary permissions to perform specific operations (read, write, execute) on the file.

<br><br>

## Implementation Details:
- **Syscall Number:** 21
- **Registers Used:**
    - `rax:` Stores the syscall number.
    - `rdi:` Pointer to the string containing the file path.
    - `rsi:` Flags that indicate the type of access to be checked.

```asm
_accessFile:
    mov rax, 21
    syscall
    ret
```

<br>

#### Expected Parameters:
- **rdi:** Pointer to the string containing the path of the file to be checked.
- **rsi:** Accessibility check flags. Common values ​​include:
    - **0:** Checks the existence of the file.
    - **1:** Checks if the file is executable.
    - **2:** Checks if the file is writable.
    - **4:** Checks if the file is readable.

<br>

#### Return Value:
- **rax:** If the syscall is successful (i.e. if access is allowed), rax will contain 0. In case of error (e.g. if access is denied or the file does not exist), rax will contain a corresponding negative value to the error code.

<br><br>

## Example of use:

#### Check for the Existence of a File
This example demonstrates how to use _accessFile to check whether a file exists on the file system.

```asm
section .data
    file_path db 'example.txt', 0



section .text
    global _start
    extern _accessFile


_start:
    mov rdi, file_path
    mov rsi, 0
    call _accessFile
    
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

<br>

#### Check if the File is Readable
This example demonstrates how to use _accessFile to check whether a file is readable. 

```asm
section .data
    file_path db 'example.txt', 0



section .text
    global _start
    extern _accessFile


_start:
    mov rdi, file_path
    mov rsi, 4
    call _accessFile
    
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