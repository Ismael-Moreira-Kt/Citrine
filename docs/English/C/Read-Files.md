# Reading Files
The `read_file` function uses [`read_file_asm`](../Assembly/Read-Files.md) to read data from a file descriptor into a buffer.

<br><br>

## Signature
```c
ssize_t read_file(int fd, void *buffer, size_t count);
```

<br>

#### Parameters
- `fd: (int) -` The file descriptor from which to read. This must be a valid file descriptor obtained from an open file.
- `buffer: (void*) -` A pointer to the buffer where the read data will be stored. The buffer should be allocated with sufficient size to hold the data being read.
- `count: (size_t) -` The number of bytes to read from the file descriptor.

<br>