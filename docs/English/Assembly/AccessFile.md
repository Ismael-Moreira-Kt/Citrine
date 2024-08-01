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
- rdi: Pointer to the string containing the path of the file to be checked.
- rsi: Accessibility check flags. Common values ​​include:
    - **0:** Checks the existence of the file.
    - **1:** Checks if the file is executable.
    - **2:** Checks if the file is writable.
    - **4:** Checks if the file is readable.