section .text
	global ft_strcpy

	ft_strcpy:
		xor rcx, rcx
	
	.loop:
		cmp byte [rsi + rcx], 0
		je .done
		mov byte al, [rsi + rcx]
		mov byte [rdi + rcx], al
		inc rcx
		jmp .loop

	.done:
		mov rax, rdi
		ret
