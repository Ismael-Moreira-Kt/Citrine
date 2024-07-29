# Reading Files
The `read_file_asm` function is an assembly implementation that performs a system call to read from a file descriptor. It reads a specified number of bytes from a file into a buffer.

<br><br>

## Signature
```c
ssize_t read_file_asm(int fd, void *buffer, size_t count);
```

<br>

#### Parameters
- `fd: (int) -` The file descriptor from which to read. This must be a valid file descriptor obtained from an open file.
- `buffer: (void*) -` A pointer to the buffer where the read data will be stored. The buffer must be large enough to hold count bytes.
- `count: (size_t) -` The number of bytes to read from the file descriptor.