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