section .text
    global ft_list_remove_if
    extern free

    ft_list_remove_if:
        push r12
        push r13
        push r14
        push r15
        mov r12, rdi
        mov r13, [rdi]
        mov r14, 0

    .loop:
        cmp r13, 0
        je .done
        mov r15, [r13 + 8]
        push rsi
        push rdx
        push rcx
        mov rdi, [r13]
        call rdx
        pop rcx
        pop rdx
        pop rsi
        cmp eax, 0
        je .remove
        mov r14, r13

    .loop_2:
        mov r13, r15
        jmp .loop

    .remove:
        push rsi
        push rdx
        push rcx
        mov rdi, [r13]
        call rcx
        mov rdi, r13
        call free wrt ..plt
        pop rcx
        pop rdx
        pop rsi
        cmp r14, 0
        jne .replace_head
        mov [r12], r15
        jmp .loop_2

    .replace_head:
        mov [r14 + 8], r15
        jmp .loop_2

    .done:
        pop r15
        pop r14
        pop r13
        pop r12
        ret
