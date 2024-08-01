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