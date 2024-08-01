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

<br>

#### Parâmetros Esperados:
- **rdi:** Descritor do arquivo (file descriptor) obtido anteriormente, por exemplo, através da função _openFile.

<br>

#### Valor de Retorno:
- **rax:** Se a syscall for bem-sucedida, rax conterá 0. Em caso de erro, rax conterá um valor negativo correspondente ao código de erro.