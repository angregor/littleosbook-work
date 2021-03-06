global loader				; the entry symbol for ELF

MAGIC_NUMBER equ 0x1BADB002		; define the magic number constant
FLAGS	     equ 0x0			; multiboot flags
CHECKSUM     equ -MAGIC_NUMBER		; calculate checksum
KERNEL_STACK_SIZE equ 8192		; size of stack in bytes

section .bss
align 4					; align at 4 bytes
kernel_stack:				; points to start of memory
	resb KERNEL_STACK_SIZE		; reserves the stack


section .text				; var
align 4					; var
    dd MAGIC_NUMBER			; var
    dd FLAGS				; var
    dd CHECKSUM				; var

loader:
    mov eax, 0xCAFEBABE			; puts cafebabe in the eax register
    mov esp, kernel_stack+KERNEL_STACK_SIZE	; sets the stack pointer
    
    extern print_hello_world		; function declaration
    call print_hello_world		; calls the function

.loop:
    jmp .loop				; loops forever
