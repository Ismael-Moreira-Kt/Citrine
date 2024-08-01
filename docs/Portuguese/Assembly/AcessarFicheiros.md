# _accessFile
A função _accessFile verifica a acessibilidade de um arquivo no sistema de arquivos Linux usando a syscall access. Essa função pode ser utilizada para verificar se um arquivo existe e/ou se o processo tem as permissões necessárias para realizar operações específicas (leitura, escrita, execução) no arquivo.

<br><br>

## Detalhes da Implementação:
- **Syscall Número:** 21
- **Registradores Utilizados:**
    - `rax:` Armazena o número da syscall.
    - `rdi:` Ponteiro para a string contendo o caminho do arquivo.
    - `rsi:` Flags que indicam o tipo de acesso a ser verificado.

```asm
_accessFile:
    mov rax, 21
    syscall
    ret
```