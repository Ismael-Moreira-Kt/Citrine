# _openFile
A função _openFile realiza a abertura de um arquivo no sistema Linux utilizando a syscall open. Se o arquivo especificado existir, a função o abre de acordo com as flags fornecidas. Se o arquivo não existir, a função o cria com as permissões especificadas.

<br><br>

## Detalhes da Implementação:
- **Syscall Número:** 2
- **Registradores Utilizados:**
    - `rax:` Armazena o número da syscall.
    - `rdi:` Endereço da string que representa o caminho do arquivo.
    - `rsi:` Flags que especificam o modo de abertura.
    - `rdx:` Permissões para o arquivo em caso de criação.

```asm
_openFile:
    mov rax, 2
    syscall
    ret
```

<br>

#### Parâmetros Esperados:
- **rdi:** Ponteiro para a string com o caminho do arquivo. A string deve ser terminada por NULL.
- **rsi:** Flags que definem o comportamento da abertura do arquivo. Exemplos comuns incluem:
    - `O_CREAT (0x40):` Cria o arquivo se ele não existir.
    - `O_WRONLY (0x01):` Abre o arquivo para escrita.
    - `O_RDONLY (0x00):` Abre o arquivo para leitura.
- **rdx:** Permissões de criação do arquivo (por exemplo, 0644), usadas apenas se o arquivo for criado.

<br>

#### Valor de Retorno:
- **rax:** Se a syscall for bem-sucedida, rax conterá o descritor de arquivo (file descriptor). Em caso de falha, rax conterá um valor negativo correspondente ao código de erro (ex.: -ENOENT se o caminho do arquivo não for encontrado).

<br><br>

## Exemplo de Uso:

#### Criar um Novo Arquivo:
O exemplo a seguir cria um novo arquivo chamado example.txt com permissões 0644 se o arquivo não existir.
```asm
section .data
    file_path db 'example.txt', 0



section .text
    global _start
    extern _openFile


_start:
    mov rdi, file_path
    mov rsi, 0x41
    mov rdx, 0644
    call _openFile
    
    test rax, rax
    js error


error:
    mov rax, 60
    xor rdi, rdi
    syscall
```

<br>

#### Abrir um Arquivo Existente:
O exemplo a seguir abre um arquivo existente chamado example.txt para leitura. Se o arquivo não existir, a chamada irá falhar.
```asm
section .data
    file_path db 'example.txt', 0



section .text
    global _start
    extern _openFile


_start:
    mov rdi, file_path
    mov rsi, 0x00
    xor rdx, rdx
    call _openFile

    test rax, rax
    js error


error:
    mov rax, 60
    xor rdi, rdi
    syscall
```

<br><br>

## Notas Adicionais:
- A flag O_CREAT deve ser combinada com rsi para definir o comportamento de criação e as permissões do arquivo.
- Se o arquivo já existir, as permissões fornecidas em rdx serão ignoradas.
- É responsabilidade do chamador configurar os registradores corretamente e tratar qualquer erro retornado.