section .text
	global ft_list_push_front
	extern malloc

	ft_list_push_front:
		mov r12, rdi
		mov r13, rsi
		mov r14, [r12]
		mov rdi, 16
		call malloc wrt ..plt
		test rax, rax
		jz .done
		mov [rax], r13
		mov [rax + 8], r14
		mov [r12], rax

	.done:
		ret
