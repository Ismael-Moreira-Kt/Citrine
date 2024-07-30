# Escrever em Ficheiros
A função `write_file` utiliza [`write_file_asm`](../Assembly/Escrever-Ficheiros.md) para escrever dados de um buffer em um descritor de arquivo. Ela lida com erros, imprimindo uma mensagem de erro se a operação de escrita falhar.

<br><br>

## Assinatura
```c
ssize_t write_file(int fd, const void *buffer, size_t count);
```

<br>

#### Parâmetros
- `fd: (int) -` O descritor de arquivo no qual os dados serão escritos. Deve ser um descritor de arquivo válido obtido de um arquivo aberto.
- `buffer: (const void*) -` Um ponteiro para o buffer de onde os dados serão lidos para serem escritos no arquivo. O buffer deve conter pelo menos count bytes.
- `count: (size_t) -` O número de bytes a serem escritos no descritor de arquivo.

<br>

#### Retorno
- `Retorna: (ssize_t) -` O número de bytes escritos se a operação for bem-sucedida; -1 se ocorrer um erro.