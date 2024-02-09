section .text
	global ft_list_sort

	ft_list_sort:
		mov r8, [rdi]
		mov r11, rsi

	.first_loop:
		cmp	r8, 0
		je .done
		mov r9, [r8 + 8]

	.second_loop:
		cmp r9, 0
		je .second_loop_end
		mov rdi, [r8]
		mov rsi, [r9]
		call r11
		cmp rax, 0
		jg .swap

	.after_swap:
		mov r9, [r9 + 8]
		jmp .second_loop

	.second_loop_end:
		mov r8, [r8 + 8]
		jmp .first_loop

	.swap:
		mov r10, [r8]
		mov rdx, [r9]
		mov [r8], rdx
		mov [r9], r10
		jmp .after_swap

	.done
		ret
