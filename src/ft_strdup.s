section .text
	global ft_strdup
	extern malloc
	extern ft_strlen
	extern ft_strcpy

	ft_strdup:
		push rdi
		call ft_strlen
		mov rdi, rax
		inc rdi
		call malloc wrt ..plt
		pop rsi
		cmp rax, 0
		je .done
		mov rdi, rax
		call ft_strcpy

	.done:
		ret
