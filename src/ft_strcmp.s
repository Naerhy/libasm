section .text
	global ft_strcmp

	ft_strcmp:
		xor rcx, rcx

	.loop:
		mov r10b, [rdi + rcx]
		mov r11b, [rsi + rcx]
		cmp r10b, 0
		je .done
		cmp r11b, 0
		je .done
		cmp r10b, r11b
		jne .done
		inc rcx
		jmp .loop

	.done:
		movzx rax, r10b
		movzx r8, r11b
		sub rax, r8
		ret
