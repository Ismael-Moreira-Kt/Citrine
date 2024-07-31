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