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

<br>

#### Parâmetros Esperados:
- **rdi:** Ponteiro para a string contendo o caminho do arquivo que será verificado.
- **rsi:** Flags de verificação de acessibilidade. Valores comuns incluem:
    - **0:** Verifica a existência do arquivo.
    - **1:** Verifica se o arquivo é executável.
    - **2:** Verifica se o arquivo é gravável.
    - **4:** Verifica se o arquivo é legível.

<br>

#### Valor de Retorno:
- **rax:** Se a syscall for bem-sucedida (ou seja, se o acesso for permitido), rax conterá 0. Em caso de erro (por exemplo, se o acesso for negado ou o arquivo não existir), rax conterá um valor negativo correspondente ao código de erro.

## Exemplos de Uso:

#### Verificar a Existência de um Arquivo
Este exemplo demonstra como usar _accessFile para verificar se um arquivo existe no sistema de arquivos.

```asm
section .data
    file_path db 'example.txt', 0



section .text
    global _start
    extern _accessFile


_start:
    mov rdi, file_path
    mov rsi, 0
    call _accessFile
    
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