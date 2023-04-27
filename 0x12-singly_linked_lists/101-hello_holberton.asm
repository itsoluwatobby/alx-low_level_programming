; Prints "Hello, Holberton" in assembly language.
; using a 64-bit system

extern printf

section .text
	global main

main:
	push rbp

	mov rdi,fmt
	mov rsi,msg
	mov rax,0
	call printf

	pop rbp

	mov rax,0
	ret

section .data		; data initialisation section
	msg: db "Hello, Holberton", 0		; message to print
	fmt: db "%s", 10, 0
	
