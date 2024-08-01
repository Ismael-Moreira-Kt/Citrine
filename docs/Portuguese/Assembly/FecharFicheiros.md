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

<br><br>

## Exemplos de Uso:
Este exemplo demonstra como usar _openFile para abrir um arquivo, _writeFile para escrever dados no arquivo e _closeFile para fechar o arquivo após a escrita.

```asm
section .data
    file_path db 'example.txt', 0
    data_to_write db 'Hello, World!', 0
    data_len equ $-data_to_write



section .text
    global _start
    extern _openFile
    extern _writeFile
    extern _closeFile


_start:
    mov rdi, file_path
    mov rsi, 0x41
    mov rdx, 0644
    call _openFile
    
    mov rdi, rax
    mov rsi, data_to_write
    mov rdx, data_len
    call _writeFile
    
    test rax, rax
    js error

    call _closeFile

    mov rax, 60
    xor rdi, rdi
    syscall


error:
    call _closeFile

    mov rax, 60
    xor rdi, rdi
    syscall
```

<br><br>

## Notas Adicionais:
- A função _closeFile deve ser chamada sempre que um arquivo não for mais necessário para liberar o descritor de arquivo e evitar vazamentos de recursos.
- Verifique o valor de retorno de _closeFile para garantir que o arquivo foi fechado corretamente, especialmente em casos críticos onde a falha em fechar um arquivo pode ter consequências.