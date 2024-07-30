# Escrever em Ficheiros
A função `write_file_asm` é uma implementação em assembly que realiza uma chamada de sistema para escrever dados em um descritor de arquivo. Ela escreve um número especificado de bytes de um buffer para um arquivo.

<br><br>

## Assinatura
```c
ssize_t write_file_asm(int fd, const void *buffer, size_t count);
```