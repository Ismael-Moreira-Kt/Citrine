section .note.GNU-stack noalloc noexec nowrite progbits



section .text
    global open_file_asm
    global read_file_asm
    global write_file_asm


open_file_asm:
    mov rax, 2
    syscall
    ret


read_file_asm:
    mov rax, 0
    syscall
    ret


write_file_asm:
    mov rax, 1
    syscall
    ret