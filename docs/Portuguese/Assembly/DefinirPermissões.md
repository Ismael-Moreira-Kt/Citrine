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

<br>

#### Parâmetros Esperados:
- **rdi:** Ponteiro para a string contendo o caminho do arquivo cujo modo de permissão será alterado.
- **rsi:** Novo conjunto de permissões em formato octal (por exemplo, 0755 para leitura, escrita e execução pelo proprietário e leitura e execução para o grupo e outros).

<br>

#### Valor de Retorno:
- **rax:** Se a syscall for bem-sucedida, rax conterá 0. Em caso de erro, rax conterá um valor negativo correspondente ao código de erro.

<br><br>

## Exemplo de Uso:
Este exemplo demonstra como usar _setPermissions para alterar as permissões de um arquivo existente.

```asm
section .data
    file_path db 'example.txt', 0



section .text
    global _start
    extern _setPermissions


_start:
    mov rdi, file_path
    mov rsi, 0755
    call _setPermissions
    
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