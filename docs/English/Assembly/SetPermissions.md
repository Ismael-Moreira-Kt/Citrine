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