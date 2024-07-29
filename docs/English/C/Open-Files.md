# Opening Files
The `open_file` function uses the [`open_file_asm`](../Assembly/Open-and-Create-Files.md) function to open an existing file with the specified flags. It **does not** create the file if it does not exist.

<br><br>

## Signature 
```C
int open_file(
    const char *path, 
    int flags
);
```