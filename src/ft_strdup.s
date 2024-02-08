section .text
	global ft_strdup
	extern malloc
	extern ft_strlen
	extern ft_strcpy

	ft_strdup:
		mov r8, rdi
		call ft_strlen
		mov rdi, rax
		inc rdi
		call malloc wrt ..plt
		test rax, rax
		jz .done
		mov rdi, rax
		mov rsi, r8
		call ft_strcpy

	.done:
		ret
