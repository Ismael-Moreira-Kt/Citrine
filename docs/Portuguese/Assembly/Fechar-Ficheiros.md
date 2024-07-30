# Fechar Ficheiros
A função `close_file_asm` é uma implementação em assembly que realiza uma chamada de sistema para fechar um descritor de arquivo. Fechar um arquivo libera os recursos associados ao descritor.

<br><br>

## Assinatura
```c
int close_file_asm(int fd);
```

<br>

#### Parâmetros
- `fd: (int) -` O descritor de arquivo a ser fechado. Deve ser um descritor de arquivo válido obtido de um arquivo aberto.

<br>

#### Retorno
- `Retorna: (int) -` Retorna 0 se a chamada for bem-sucedida; -1 se ocorrer um erro.