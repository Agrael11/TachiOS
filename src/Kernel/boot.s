.set ALIGN,    1<<0             # Zarovnanie modulov na stranku
.set MEMINFO,  1<<1             # Mapa pamate
.set FLAGS,    ALIGN | MEMINFO  # Vlajka pre "Multiboot"
.set MAGIC,    0x1BADB002       # Magicke cislo - na najdenie headeru
.set CHECKSUM, -(MAGIC + FLAGS) # Checksum prvych 4 riadkov


.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 16384 # 16384 B = 16KiB
stack_top:

movl %esp, %ebp

.section .text
.global _start
.type _start, @function
_start:
	movl $stack_top, %esp
	push %eax
	push %ebx

	call kernelStartPoint


	cli
	hlt

.Lhang:
	jmp .Lhang

.size _start, . - _start
