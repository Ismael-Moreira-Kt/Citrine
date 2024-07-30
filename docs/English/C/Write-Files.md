# Writing Files
The `write_file` function uses [`write_file_asm`](../Assembly/Write-Files.md) to write data from a buffer to a file descriptor. It handles errors, printing an error message if the write operation fails.

<br><br>

## Signature
```c
ssize_t write_file(int fd, const void *buffer, size_t count);
```