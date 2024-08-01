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