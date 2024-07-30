# Definir Permissões
A função `set_permissions` utiliza [`set_permissions_asm`](../Assembly/Definir-Permissões.md) para definir as permissões de um arquivo.

<br><br>

## Assinatura
```c
int set_permissions(const char *path, mode_t mode);
```