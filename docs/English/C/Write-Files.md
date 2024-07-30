# Writing Files
The `write_file` function uses [`write_file_asm`](../Assembly/Write-Files.md) to write data from a buffer to a file descriptor. It handles errors, printing an error message if the write operation fails.

<br><br>

## Signature
```c
ssize_t write_file(int fd, const void *buffer, size_t count);
```

<br>

#### Parameters
- `fd: (int) -` The file descriptor to which the data will be written. It must be a valid file descriptor obtained from an open file.
- `buffer: (const void*) -` A pointer to the buffer from which the data will be read to be written to the file. The buffer must contain at least count bytes.
- `count: (size_t) -` The number of bytes to be written to the file descriptor.

<br>

#### Returns
- `Returns: (ssize_t) -` The number of bytes written if the operation is successful; -1 if an error occurs.