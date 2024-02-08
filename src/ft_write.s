section .text
	global ft_write
	extern __errno_location

	ft_write:
		mov rax, 1
		syscall
		cmp rax, 0
		jge .done

	.error:
		mov rbx, rax
		call __errno_location wrt ..plt
		mov [rax], rbx
		mov rax, -1

	.done:
		ret
