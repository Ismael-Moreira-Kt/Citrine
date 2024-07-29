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