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