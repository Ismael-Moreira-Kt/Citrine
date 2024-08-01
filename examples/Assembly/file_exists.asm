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