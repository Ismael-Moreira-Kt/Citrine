# Ler Ficheiros
A função `read_file_asm` é uma implementação assembly que executa uma chamada de sistema para ler de um descritor de arquivo. Ela lê um número especificado de bytes de um arquivo para um buffer.

<br><br>

## Assinatura
```c
ssize_t read_file_asm(int fd, void *buffer, size_t count);
```

<br>

#### Parâmetros
- `fd: (int) -` O descritor de ficheiro a partir do qual se pretende ler. Este deve ser um descritor de arquivo válido obtido de um arquivo aberto.
- `buffer: (void*) -` Um ponteiro para o buffer onde os dados lidos serão armazenados. O buffer deve ser grande o suficiente para conter o número de bytes.
- `count: (size_t) -` O número de bytes a serem lidos do descritor de arquivo.

<br>

#### Retornos
- `Returns: (ssize_t) -` O número de bytes lidos se a chamada for bem sucedida; -1 se ocorrer um erro.