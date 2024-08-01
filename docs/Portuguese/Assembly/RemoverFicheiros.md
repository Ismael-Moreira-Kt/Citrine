# _unlinkFile
A função _unlinkFile remove um arquivo do sistema de arquivos no Linux utilizando a syscall unlink. Ao ser chamada, a função desvincula o nome do arquivo especificado de seu inode, efetivamente deletando o arquivo do sistema se este for o último link para o inode.

<br><br>

## Detalhes da Implementação:
- **Syscall Número:** 87
- **Registradores Utilizados:**
    - `rax:` Armazena o número da syscall.
    - `rdi:` Ponteiro para a string contendo o caminho do arquivo a ser removido.

```asm
_unlinkFile:
    mov rax, 87
    syscall
    ret
```

<br>

#### Parâmetros Esperados:
- **rdi:** Ponteiro para a string contendo o caminho do arquivo que será removido.