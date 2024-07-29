# Ler Ficheiros
A função `read_file` utiliza [`read_file_asm`](../Assembly/Ler-Ficheiros.md) para ler dados de um descritor de ficheiro para uma memória intermédia.

<br><br>

## Assinatura
```c
ssize_t read_file(int fd, void *buffer, size_t count);
```