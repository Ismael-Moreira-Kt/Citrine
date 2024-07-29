# Ler Ficheiros
A função `read_file_asm` é uma implementação assembly que executa uma chamada de sistema para ler de um descritor de arquivo. Ela lê um número especificado de bytes de um arquivo para um buffer.

<br><br>

## Assinatura
```c
ssize_t read_file_asm(int fd, void *buffer, size_t count);
```