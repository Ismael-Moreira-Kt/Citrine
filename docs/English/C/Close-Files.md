# Closing Files
The `close_file` function uses [`close_file_asm`](../Assembly/Close-Files.md) to close a file descriptor.

<br><br>

## Signature
```c
int close_file(int fd);
```

<br>

#### Parameters
- `fd: (int) -` The file descriptor to close. Must be a valid file descriptor obtained from an open file.

<br>

#### Returns
- `Returns: (int) -` Returns 0 if the operation is successful; -1 if an error occurs.