section .text
	global ft_list_push_front
	extern malloc

	ft_list_push_front:
		push r12
		push r13
		push r14
		mov r12, rdi
		mov r13, rsi
		mov r14, [r12]
		xor rdi, rdi
		mov rdi, 16
		call malloc wrt ..plt
		cmp rax, 0
		je .done
		mov [rax], r13
		mov [rax + 8], r14
		mov [r12], rax

	.done:
		pop r14
		pop r13
		pop r12
		ret
