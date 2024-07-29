# Criar Ficheiros
A função `create_file` utiliza a função [`open_file_asm`](../Assembly/Abrir-e-Criar-Ficheiros.md) para criar um novo arquivo com as permissões especificadas. Se o arquivo já existir, ele será aberto para escrita.

<br><br>

## Assinatura 
```C
int create_file(
    const char *path, 
    mode_t mode
);
```