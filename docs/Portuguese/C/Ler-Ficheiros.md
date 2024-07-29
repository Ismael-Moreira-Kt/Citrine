# Ler Ficheiros
A função `read_file` utiliza [`read_file_asm`](../Assembly/Ler-Ficheiros.md) para ler dados de um descritor de ficheiro para uma memória intermédia.

<br><br>

## Assinatura
```c
ssize_t read_file(int fd, void *buffer, size_t count);
```

<br>

#### Parâmetros
- `fd: (int) -` O descritor de ficheiro a partir do qual se pretende ler. Este deve ser um descritor de arquivo válido obtido de um arquivo aberto.
- `buffer: (void*) -` Um ponteiro para o buffer onde os dados lidos serão armazenados. O buffer deve ser alocado com tamanho suficiente para conter os dados que estão sendo lidos.
- `count: (size_t) -` O número de bytes a serem lidos do descritor de arquivo.