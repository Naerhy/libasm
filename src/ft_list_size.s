section .text
	global ft_list_size

	ft_list_size:
		xor rcx, rcx

	.loop:
		cmp rdi, 0
		je .done
		inc rcx
		mov rdi, [rdi + 8]
		jmp .loop

	.done:
		mov rax, rcx
		ret
