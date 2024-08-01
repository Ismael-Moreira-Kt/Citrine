# _writeFile
A função _writeFile realiza a escrita de dados em um arquivo no sistema Linux utilizando a syscall write. A função assume que os parâmetros necessários, como o descritor do arquivo, o buffer com os dados e o número de bytes a serem escritos, estão configurados nos registradores apropriados antes da execução.

<br><br>

## Detalhes da Implementação:
- **Syscall Número:** 1
- **Registradores Utilizados:**
    - `rax:` Armazena o número da syscall (1 para write).
    - `rdi:` Descritor do arquivo para o qual os dados serão escritos.
    - `rsi:` Endereço do buffer contendo os dados a serem escritos.
    - `rdx:` Número de bytes a serem escritos.

```asm
_writeFile:
    mov rax, 1
    syscall
    ret
```

<br>

#### Parâmetros Esperados:
- **rdi:** Descritor do arquivo (file descriptor) obtido anteriormente, por exemplo, através da função _openFile.
- **rsi:** Ponteiro para o buffer contendo os dados a serem escritos no arquivo.
- **rdx:** Número de bytes a serem escritos no arquivo.

<br>

#### Valor de Retorno:
- **rax:** Se a syscall for bem-sucedida, rax conterá o número de bytes efetivamente escritos. Em caso de erro, rax conterá um valor negativo correspondente ao código de erro.

<br><br>

## Exemplos de Uso:
Este exemplo ilustra como usar _openFile para abrir um arquivo, _writeFile para escrever dados no arquivo e, em seguida, verificar o número de bytes escritos.

```asm
section .data
    file_path db 'examples.txt', 0
    data_to_write db 'Hello, World!', 0
    data_len equ $-data_to_write



section .text
    global _start
    extern _openFile
    extern _writeFile


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

<br><br>

## Notas Adicionais:
- Certifique-se de que o buffer (rsi) contenha os dados a serem escritos e que o número de bytes (rdx) seja correto.
- O número de bytes escritos é retornado em rax, e o valor pode ser zero se não houver dados a serem escritos ou se o descritor do arquivo não for válido.
- Em uma aplicação real, você deve incluir código adicional para tratar erros e garantir que o buffer e os dados sejam manipulados corretamente.