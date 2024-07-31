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