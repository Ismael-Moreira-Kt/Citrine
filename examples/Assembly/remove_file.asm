section .data
    file_path db 'example.txt', 0



section .text
    global _start
    extern _unlinkFile


_start:
    mov rdi, file_path
    call _unlinkFile

    test rax, rax
    js error

    mov rax, 60
    xor rdi, rdi
    syscall


error:
    mov rax, 60
    xor rdi, rdi
    syscall