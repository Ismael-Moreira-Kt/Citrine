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

<br>

#### Valor de Retorno:
- **rax:** Se a syscall for bem-sucedida, rax conterá 0. Em caso de erro, rax conterá um valor negativo correspondente ao código de erro.

<br><br>

## Exemplo de Uso:
Este exemplo demonstra como usar _unlinkFile para deletar um arquivo do sistema de arquivos.

```asm
section .data
    file_path db 'example.txt', 0



section .text
    global _start
    extern _unlinkFile


_start:
    mov rdi, file_path
    call _unlinkFile

    test rax, rax
    js error

    mov rax, 60
    xor rdi, rdi
    syscall


error:
    mov rax, 60
    xor rdi, rdi
    syscall
```