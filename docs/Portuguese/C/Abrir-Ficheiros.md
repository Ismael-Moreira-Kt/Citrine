# Abrir Ficheiros
A função `open_file` utiliza a função [`open_file_asm`](../Assembly/Abrir-e-Criar-Ficheiros.md) para abrir um arquivo existente com os sinalizadores especificados. Ela **não** cria o arquivo se ele não existir.

<br><br>

## Assinatura 
```C
int open_file(
    const char *path, 
    int flags
);
```

<br>

#### Parâmetros
- `path: (const char*) -` Caminho para o arquivo a ser aberto.
- `flags: (int) -` Flags que determinam como o arquivo é aberto, como **O_RDONLY** para *leitura* ou **O_WRONLY** para *escrita*.