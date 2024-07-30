# Definir Permissões
A função `set_permissions` utiliza [`set_permissions_asm`](../Assembly/Definir-Permissões.md) para definir as permissões de um arquivo.

<br><br>

## Assinatura
```c
int set_permissions(const char *path, mode_t mode);
```

<br>

#### Parâmetros
- `path: (const char *) -` O caminho para o arquivo cujas permissões serão alteradas. Deve ser uma string terminada em nulo.
- `mode: (mode_t) -` As novas permissões a serem definidas para o arquivo. Exemplos incluem 0666 para permissões padrão de leitura e escrita.