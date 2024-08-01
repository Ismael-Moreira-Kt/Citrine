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