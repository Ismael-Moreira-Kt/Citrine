# _writeFile
A função _writeFile realiza a escrita de dados em um arquivo no sistema Linux utilizando a syscall write. A função assume que os parâmetros necessários, como o descritor do arquivo, o buffer com os dados e o número de bytes a serem escritos, estão configurados nos registradores apropriados antes da execução.

<br><br>

## Detalhes da Implementação:
- **Syscall Número:** 1
- **Registradores Utilizados:**
    - `rax:` Armazena o número da syscall (1 para write).
    - `rdi:` Descritor do arquivo para o qual os dados serão escritos.
    - `rsi:` Endereço do buffer contendo os dados a serem escritos.
    - `rdx:` Número de bytes a serem escritos.

```asm
_writeFile:
    mov rax, 1
    syscall
    ret
```

<br>

#### Parâmetros Esperados:
- **rdi:** Descritor do arquivo (file descriptor) obtido anteriormente, por exemplo, através da função _openFile.
- **rsi:** Ponteiro para o buffer contendo os dados a serem escritos no arquivo.
- **rdx:** Número de bytes a serem escritos no arquivo.