# Reading Files
The `read_file_asm` function is an assembly implementation that performs a system call to read from a file descriptor. It reads a specified number of bytes from a file into a buffer.

<br><br>

## Signature
```c
ssize_t read_file_asm(int fd, void *buffer, size_t count);
```