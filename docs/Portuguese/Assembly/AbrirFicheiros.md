# _openFile
A função _openFile realiza a abertura de um arquivo no sistema Linux utilizando a syscall open. Se o arquivo especificado existir, a função o abre de acordo com as flags fornecidas. Se o arquivo não existir, a função o cria com as permissões especificadas.

<br><br>

## Detalhes da Implementação:
- **Syscall Número:** 2
- **Registradores Utilizados:**
    - `rax:` Armazena o número da syscall.
    - `rdi:` Endereço da string que representa o caminho do arquivo.
    - `rsi:` Flags que especificam o modo de abertura.
    - `rdx:` Permissões para o arquivo em caso de criação.

```asm
_openFile:
    mov rax, 2
    syscall
    ret
```

<br>

#### Parâmetros Esperados:
- **rdi:** Ponteiro para a string com o caminho do arquivo. A string deve ser terminada por NULL.
- **rsi:** Flags que definem o comportamento da abertura do arquivo. Exemplos comuns incluem:
    - `O_CREAT (0x40):` Cria o arquivo se ele não existir.
    - `O_WRONLY (0x01):` Abre o arquivo para escrita.
    - `O_RDONLY (0x00):` Abre o arquivo para leitura.
- **rdx:** Permissões de criação do arquivo (por exemplo, 0644), usadas apenas se o arquivo for criado.