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

<br>

#### Parameters
- `path: (const char*) -` Path to the file to be created.
- `mode: (mode_t) -` Permissions to be assigned to the new file. Example: 0666 for read and write permissions for everyone.

<br>

#### Returns
- `Returns: (int) -` File descriptor if creation is successful; **-1** if an error occurs.