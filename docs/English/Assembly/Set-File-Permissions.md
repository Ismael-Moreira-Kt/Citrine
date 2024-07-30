# Setting Permissions
The `set_permissions_asm` function is an assembly implementation that makes a system call to set the permissions of a file. It changes the permissions of a file specified by its path.

<br><br>

## Signature
```c
int set_permissions_asm(const char *path, mode_t mode);
```