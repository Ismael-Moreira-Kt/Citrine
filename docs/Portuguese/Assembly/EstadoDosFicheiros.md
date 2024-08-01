# _fstatFile
A função _fstatFile obtém informações sobre um arquivo aberto, como tamanho, permissões, e timestamps, utilizando a syscall fstat no Linux. Essa função é particularmente útil quando você já tem um descritor de arquivo (file descriptor) e precisa obter informações detalhadas sobre o arquivo correspondente.

<br><br>

## Detalhes da Implementação:
- **Syscall Número:** 5
- **Registradores Utilizados:**
    - `rax:` Armazena o número da syscall.
    - `rdi:` Descritor de arquivo (file descriptor) do arquivo a ser inspecionado.
    - `rsi:` Ponteiro para uma estrutura stat onde as informações do arquivo serão armazenadas.

```asm
_fstatFile:
    mov rax, 5
    syscall
    ret
```

<br>

#### Parâmetros Esperados:
- **rdi:** Descritor de arquivo (file descriptor) do arquivo sobre o qual deseja obter informações.
- **rsi:** Ponteiro para a estrutura stat onde as informações do arquivo serão armazenadas.

<br>

#### Valor de Retorno:
- **rax:** Se a syscall for bem-sucedida, rax conterá 0. Em caso de erro, rax conterá um valor negativo correspondente ao código de erro.

<br>

#### Estrutura stat:
A estrutura stat é uma estrutura padrão no Linux que armazena várias informações sobre o arquivo. Alguns dos campos mais comuns incluem:
- `st_dev:` ID do dispositivo contendo o arquivo.
- `st_ino:` Número do inode.
- `st_mode:` Tipo de arquivo e permissões.
- `st_nlink:` Número de hard links.
- `st_uid:` ID do proprietário.
- `st_gid:` ID do grupo.
- `st_rdev:` ID do dispositivo (se for um dispositivo especial).
- `st_size:` Tamanho total do arquivo em bytes.
- `st_blksize:` Tamanho de bloco preferido para I/O do sistema de arquivos.
- `st_blocks:` Número de blocos alocados.
- `st_atime:` Hora do último acesso.
- `st_mtime:` Hora da última modificação.
- `st_ctime:` Hora da última alteração de status.

<br><br>

## Exemplo de Uso:
Este exemplo demonstra como usar _fstatFile para obter informações sobre um arquivo, utilizando um descritor de arquivo previamente obtido por _openFile.

```asm
section .data
    file_path db 'example.txt', 0
    stat_buf times 144 db 0



section .text
    global _start
    extern _openFile
    extern _fstatFile
    extern _closeFile


_start:
    mov rdi, file_path
    xor rsi, rsi
    call _openFile

    test rax, rax
    js error

    mov rdi, rax
    mov rsi, stat_buf
    call _fstatFile
    
    test rax, rax
    js error

    mov rax, [stat_buf + 48]
    mov rdi, rax
    call _closeFile

    mov rax, 60
    xor rdi, rdi
    syscall


error:
    mov rax, 60
    xor rdi, rdi
    syscall
```