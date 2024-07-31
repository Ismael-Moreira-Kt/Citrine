# _openFile
The _openFile function opens a file in the Linux system using the open syscall. If the specified file exists, the function opens it according to the provided flags. If the file does not exist, the function creates it with the specified permissions.

<br><br>

## Implementation Details:
- **Syscall Number:** 2
- **Registers Used:**
    - `rax:` Stores the syscall number.
    - `rdi:` String address that represents the file path.
    - `rsi:` Flags that specify the opening mode.
    - `rdx:` Permissions for the file in case of creation.