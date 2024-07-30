# Setting Permissions
The `set_permissions` function uses [`set_permissions_asm`](../Assembly/Set-File-Permissions.md) to set the permissions of a file.

<br><br>

## Signature
```c
int set_permissions(const char *path, mode_t mode);
```