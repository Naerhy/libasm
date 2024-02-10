section .text
	global ft_strcmp

	ft_strcmp:
		xor rcx, rcx

	.loop:
		mov r8b, [rdi + rcx]
		mov r9b, [rsi + rcx]
		cmp r8b, 0
		je .done
		cmp r9b, 0
		je .done
		cmp r8b, r9b
		jne .done
		inc rcx
		jmp .loop

	.done:
		movzx rax, r8b
		movzx r8, r9b
		sub rax, r8
		ret
