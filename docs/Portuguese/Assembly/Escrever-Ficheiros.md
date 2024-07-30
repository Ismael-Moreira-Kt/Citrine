# Escrever em Ficheiros
A função `write_file_asm` é uma implementação em assembly que realiza uma chamada de sistema para escrever dados em um descritor de arquivo. Ela escreve um número especificado de bytes de um buffer para um arquivo.

<br><br>

## Assinatura
```c
ssize_t write_file_asm(int fd, const void *buffer, size_t count);
```

<br>

#### Parâmetros
- `fd: (int) -` O descritor de arquivo no qual os dados serão escritos. Deve ser um descritor de arquivo válido obtido de um arquivo aberto.
- `buffer: (const void*) -` Um ponteiro para o buffer de onde os dados serão lidos para serem escritos no arquivo. O buffer deve conter pelo menos count bytes.
- `count: (size_t) -` O número de bytes a serem escritos no descritor de arquivo.

<br>