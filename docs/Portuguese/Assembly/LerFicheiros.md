# _readFile
A função _readFile realiza a leitura de dados de um arquivo no sistema Linux utilizando a syscall read. A função assume que os parâmetros necessários, como o descritor do arquivo, o buffer para os dados e o número de bytes a serem lidos, estão configurados nos registradores apropriados antes da execução.

<br><br>

## Detalhes da Implementação:
- **Syscall Número:** 0
- **Registradores Utilizados:**
    - `rax:` Armazena o número da syscall.
    - `rdi:` Descritor do arquivo a partir do qual os dados serão lidos.
    - `rsi:` Endereço do buffer onde os dados lidos serão armazenados.
    - `rdx:` Número de bytes a serem lidos.

```asm
_readFile:
    mov rax, 0
    syscall
    ret
```

<br>

#### Parâmetros Esperados:
- **rdi:** Descritor do arquivo (file descriptor) obtido anteriormente, por exemplo, através da função _openFile.
- **rsi:** Ponteiro para o buffer onde os dados lidos serão armazenados. O buffer deve ser alocado com tamanho suficiente para armazenar os dados.
- **rdx:** Número máximo de bytes a serem lidos do arquivo.

<br>

#### Valor de Retorno:
- **rax:** Se a syscall for bem-sucedida, rax conterá o número de bytes efetivamente lidos. Se o retorno for zero, isso indica que o fim do arquivo foi alcançado. Em caso de erro, rax conterá um valor negativo correspondente ao código de erro.

<br><br>

## Exemplos de Uso
Este exemplo mostra como usar _openFile para abrir um arquivo, _readFile para ler seu conteúdo e, em seguida, imprimir o conteúdo na tela.

```asm
section .data
    file_path db 'example.txt', 0 
    msg db 'Bytes read: ', 0
    msg_len equ $-msg



section .bss
    buffer resb 100



section .text
    global _start
    extern _openFile
    extern _readFile


_start:
    mov rdi, file_path 
    mov rsi, 0x00
    xor rdx, rdx 
    call _openFile
    mov rdi, rax 

    mov rsi, buffer
    mov rdx, 100
    call _readFile

    test rax, rax
    js error

    mov rbx, rax
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, msg_len
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, buffer
    mov rdx, rbx
    syscall

    mov rax, 3
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall


error:
    mov rax, 3
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall
```