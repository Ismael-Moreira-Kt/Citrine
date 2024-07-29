# Writing Files
The `write_file_asm` function is an assembly implementation that makes a system call to write data to a file descriptor. It writes a specified number of bytes from a buffer to a file.

<br><br>

## Signature
```c
ssize_t write_file_asm(int fd, const void *buffer, size_t count);
```

<br>