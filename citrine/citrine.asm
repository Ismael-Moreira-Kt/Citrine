section .note.GNU-stack noalloc noexec nowrite progbits



section .text
    global open_file_asm
    global read_file_asm
    global write_file_asm
    global close_file_asm
    global set_permissions_asm
    global unlink_file_asm
    global access_file_asm
    global fstat_file_asm


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


close_file_asm:
    mov rax, 3
    syscall
    ret


set_permissions_asm:
    mov rax, 90
    syscall
    ret


unlink_file_asm:
    mov rax, 87
    syscall
    ret


access_file_asm:
    mov rax, 21
    syscall
    ret


fstat_file_asm:
    mov rax, 5
    syscall
    ret