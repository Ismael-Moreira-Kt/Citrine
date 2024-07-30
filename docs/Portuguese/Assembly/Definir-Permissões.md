# Definir Permissões
A função `set_permissions_asm` é uma implementação em assembly que realiza uma chamada de sistema para definir as permissões de um arquivo. Ela altera as permissões de um arquivo especificado por seu caminho.

<br><br>

## Assinatura
```c
int set_permissions_asm(const char *path, mode_t mode);
```

<br>

#### Parâmetros
- `path: (const char *) -` O caminho para o arquivo cujas permissões serão alteradas. Deve ser uma string terminada em nulo.
- `mode: (mode_t) -` As novas permissões a serem definidas para o arquivo. Exemplos incluem 0666 para permissões padrão de leitura e escrita.