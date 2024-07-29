# Reading Files
The `read_file` function uses [`read_file_asm`](../Assembly/Read-Files.md) to read data from a file descriptor into a buffer.

<br><br>

## Signature
```c
ssize_t read_file(int fd, void *buffer, size_t count);
```