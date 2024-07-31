section .note.GNU-stack noalloc noexec nowrite progbits



section .text
    global _openFile
    global _readFile
    global _writeFile
    global _closeFile
    global _setPermissions
    global _unlinkFile
    global _accessFile
    global _fstatFile
    global _mkdir
    global _renameFile
    global _rmdir
    global _fsyncFile
    global _copyFile
    global _chownFile
    global _statfs


_openFile:
    mov rax, 2
    syscall
    ret


_readFile:
    mov rax, 0
    syscall
    ret


_writeFile:
    mov rax, 1
    syscall
    ret


_closeFile:
    mov rax, 3
    syscall
    ret


_setPermissions:
    mov rax, 90
    syscall
    ret


_unlinkFile:
    mov rax, 87
    syscall
    ret


_accessFile:
    mov rax, 21
    syscall
    ret


_fstatFile:
    mov rax, 5
    syscall
    ret


_mkdir:
    mov rax, 83
    syscall
    ret


_renameFile:
    mov rax, 82
    syscall
    ret


_rmdir:
    mov rax, 80
    mov rdi, rdi
    syscall
    ret


_fsyncFile:
    mov rax, 95
    mov rdi, rdi
    syscall
    ret


_copyFile:
    mov rax, 40
    syscall
    ret


_chownFile:
    mov rax, 92
    syscall
    ret


_statfs:
    mov rax, 137
    syscall
    ret