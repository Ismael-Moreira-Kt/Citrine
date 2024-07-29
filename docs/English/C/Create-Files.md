# Creating Files
The `create_file` function uses the [`open_file_asm`](../Assembly/Open-and-Create-Files.md) function to create a new file with the specified permissions. If the file already exists, it will be opened for writing.

<br><br>

## Signature 
```C
int create_file(
    const char *path, 
    mode_t mode
);
```