# Fechar Ficheiros
A função `close_file` utiliza [`close_file_asm`](../Assembly/Fechar-Ficheiros.md) para fechar um descritor de arquivo. Ela lida com erros, imprimindo uma mensagem de erro se a operação de fechamento falhar.

<br><br>

## Assinatura
```c
int close_file(int fd);
```

<br>

#### Parâmetros
- `fd: (int) -` O descritor de arquivo a ser fechado. Deve ser um descritor de arquivo válido obtido de um arquivo aberto.

<br>

#### Retorno
- `Retorna: (int) -` Retorna 0 se a operação for bem-sucedida; -1 se ocorrer um erro.