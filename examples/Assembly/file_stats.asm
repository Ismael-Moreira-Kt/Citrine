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