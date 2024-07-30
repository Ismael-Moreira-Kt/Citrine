# Writing Files
The `write_file_asm` function is an assembly implementation that makes a system call to write data to a file descriptor. It writes a specified number of bytes from a buffer to a file.

<br><br>

## Signature
```c
ssize_t write_file_asm(int fd, const void *buffer, size_t count);
```

<br>

#### Parameters
- `fd: (int) -` The file descriptor to which the data will be written. It must be a valid file descriptor obtained from an open file.
- `buffer: (const void*) -` A pointer to the buffer from which the data will be read to be written to the file. The buffer must contain at least count bytes.
- `count: (size_t) -` The number of bytes to be written to the file descriptor.

<br>

#### Returns
- `Returns: (ssize_t) -` The number of bytes written if the call is successful; -1 if an error occurs.