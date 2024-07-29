# Opening and Creating Files
The `open_file_asm` function is an assembly implementation that performs a **system call** to open a file. It supports *opening files* in *read*, *write*, or *both modes*, and can also *create a file* if it does not already exist.

<br><br>

## Signature 
```C
int open_file_asm(
    const char *path, 
    int flags, 
    mode_t mode
);
```

<br>

#### Parameters
- `path: (const char*) -` The path to the file to be opened. This should be a ***null-terminated* string**.
- `flags: (int) -` Flags that specify how the file should be opened. Examples include **O_RDONLY**, **O_WRONLY**, **O_RDWR**, and **O_CREAT**.
- `mode: (mode_t) -` The permissions mode for the file, used only if the file is being created. Examples include **0666** for standard permissions.

<br>

#### Returns
- `Returns: (int) -` A file descriptor if the call is successful; **-1** if an error occurs.