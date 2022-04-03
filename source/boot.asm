
section .text
start:
	mov bx, 'd'
	mov ah, 0x0E
	mov al, 'bx'
	int 10h

name:
	dd "Hello, world!", 0

finish:
times 510+start-finish db 0
db 0x55, 0xAA
