# Setting Permissions
The `set_permissions` function uses [`set_permissions_asm`](../Assembly/Set-File-Permissions.md) to set the permissions of a file.

<br><br>

## Signature
```c
int set_permissions(const char *path, mode_t mode);
```

<br>

#### Parameters
- `path: (const char *) -` The path to the file whose permissions will be changed. Must be a null-terminated string.
- `mode: (mode_t) -` The new permissions to be set for the file. Examples include 0666 for standard read and write permissions.