# Abrir e Criar Ficheiros
A função `open_file_asm` é uma implementação assembly que executa uma **chamada de sistema** para abrir um arquivo. Suporta *abertura de ficheiros* em modo de *leitura*, *escrita*, ou *ambos os modos*, e pode também *criar um ficheiro* se este ainda não existir.

<br><br>

## Assinatura
```C
int open_file_asm(
    const char *path, 
    int flags, 
    mode_t mode
);
```

<br>

#### Parâmetros
- `path: (const char*) -` O caminho para o ficheiro a ser aberto. Deve ser uma string terminada em ***nulo***.
- `flags: (int) -` Flags que especificam como o arquivo deve ser aberto. Exemplos incluem **O_RDONLY**, **O_WRONLY**, **O_RDWR**, e **O_CREAT**.
- `mode: (mode_t) -` O modo de permissões para o ficheiro, usado apenas se o ficheiro estiver a ser criado. Exemplos incluem **0666** para permissões padrão.