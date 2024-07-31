section .data
    file_path db 'example.txt', 0 
    msg db 'Bytes read: ', 0
    msg_len equ $-msg



section .bss
    buffer resb 100



section .text
    global _start
    extern _openFile
    extern _readFile


_start:
    mov rdi, file_path 
    mov rsi, 0x00
    xor rdx, rdx 
    call _openFile
    mov rdi, rax 

    mov rsi, buffer
    mov rdx, 100
    call _readFile

    test rax, rax
    js error

    mov rbx, rax
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, msg_len
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, buffer
    mov rdx, rbx
    syscall

    mov rax, 3
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall


error:
    mov rax, 3
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall