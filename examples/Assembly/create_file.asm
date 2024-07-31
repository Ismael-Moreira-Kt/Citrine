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