section .text
	global ft_strcmp

	ft_strcmp:
		xor rcx, rcx
		xor rax, rax

	.loop:
		mov al, [rdi + rcx]
		mov bl, [rsi + rcx]
		cmp al, 0
		je .done
		cmp bl, 0
		je .done
		cmp al, bl
		jne .done
		inc rcx
		jmp .loop

	.done:
		movzx rax, al
		movzx r8, bl
		sub rax, r8
		ret
