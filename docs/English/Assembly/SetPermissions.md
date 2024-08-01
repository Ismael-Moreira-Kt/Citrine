# _setPermissions
The _setPermissions function changes the permissions of a file on the Linux system using the chmod syscall. The function assumes that necessary parameters, such as file path and permissions, are set in the appropriate registers before execution.

<br><br>

## Implementation Details:
- **Syscall Number:** 90
- **Registers Used:**
    - `rax:` Stores the syscall number.
    - `rdi:` Pointer to the path of the file whose permissions will be changed.
    - `rsi:` New set of permissions to be applied to the file (in octal format).

```asm
_setPermissions:
    mov rax, 90
    syscall
    ret
```

<br>

#### Expected Parameters:
- **rdi:** Pointer to the string containing the path of the file whose permission mode will be changed.
- **rsi:** New set of permissions in octal format (e.g. 0755 for read, write and execute by owner and read and execute for group and others).

<br>

#### Return Value:
- **rax:** If the syscall is successful, rax will contain 0. In case of error, rax will contain a negative value corresponding to the error code.

<br><br>

## Example of use:
This example demonstrates how to use _setPermissions to change the permissions of an existing file.

```asm
section .data
    file_path db 'example.txt', 0



section .text
    global _start
    extern _setPermissions


_start:
    mov rdi, file_path
    mov rsi, 0755
    call _setPermissions
    
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

<br><br>

## Additional Notes:
- The _setPermissions function should be used with caution, especially on multi-user systems, as inappropriate permissions can expose sensitive files to unauthorized access.
- The code above assumes that octal format is used to define permissions. Make sure permissions are correctly configured to avoid security issues.