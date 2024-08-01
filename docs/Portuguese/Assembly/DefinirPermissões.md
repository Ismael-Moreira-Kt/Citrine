# _setPermissions
A função _setPermissions altera as permissões de um arquivo no sistema Linux utilizando a syscall chmod. A função assume que os parâmetros necessários, como o caminho do arquivo e as permissões, estão configurados nos registradores apropriados antes da execução.

<br><br>

## Detalhes da Implementação:
- Syscall Número: 90
- Registradores Utilizados:
    - `rax:` Armazena o número da syscall.
    - `rdi:` Ponteiro para o caminho do arquivo cujas permissões serão alteradas.
    - `rsi:` Novo conjunto de permissões a ser aplicado ao arquivo (em formato octal).

```asm
_setPermissions:
    mov rax, 90
    syscall
    ret
```