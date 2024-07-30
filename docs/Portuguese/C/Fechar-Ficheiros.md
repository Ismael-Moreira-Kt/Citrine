# Fechar Ficheiros
A função `close_file` utiliza [`close_file_asm`](../Assembly/Fechar-Ficheiros.md) para fechar um descritor de arquivo. Ela lida com erros, imprimindo uma mensagem de erro se a operação de fechamento falhar.

<br><br>

## Assinatura
```c
int close_file(int fd);
```