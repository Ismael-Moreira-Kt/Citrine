# _closeFile
A função _closeFile fecha um arquivo aberto no sistema Linux utilizando a syscall close. A função assume que o descritor do arquivo a ser fechado está configurado no registrador apropriado antes da execução.

<br><br>

## Detalhes da Implementação:
- **Syscall Número:** 3
- **Registradores Utilizados:**
    - `rax:` Armazena o número da syscall.
    - `rdi:` Descritor do arquivo a ser fechado.

```asm
_closeFile:
    mov rax, 3
    syscall
    ret
```