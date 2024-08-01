# _fstatFile
A função _fstatFile obtém informações sobre um arquivo aberto, como tamanho, permissões, e timestamps, utilizando a syscall fstat no Linux. Essa função é particularmente útil quando você já tem um descritor de arquivo (file descriptor) e precisa obter informações detalhadas sobre o arquivo correspondente.

<br><br>

## Detalhes da Implementação:
- **Syscall Número:** 5
- **Registradores Utilizados:**
    - `rax:` Armazena o número da syscall.
    - `rdi:` Descritor de arquivo (file descriptor) do arquivo a ser inspecionado.
    - `rsi:` Ponteiro para uma estrutura stat onde as informações do arquivo serão armazenadas.

```asm
_fstatFile:
    mov rax, 5
    syscall
    ret
```