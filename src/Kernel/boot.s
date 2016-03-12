.set ALIGN,    1<<0             # Zarovnanie modulov na stránku
.set MEMINFO,  1<<1             # Mapa pamäte
.set FLAGS,    ALIGN | MEMINFO  # Vlajka pre "Multiboot"
.set MAGIC,    0x1BADB002       # Magicke cislo - na najdenie headeru
.set CHECKSUM, -(MAGIC + FLAGS) # Checksum prvých 4 riadkov


# Hlavička podla štandardu Multiboot, Sekcia "multiboot"
# označuje kde má program začať
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Tvorba vlastného stacku veľkosti 16KiB,

.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 16384 # 16384 B = 16KiB
stack_top:

.section .text
.global _start
.type _start, @function
_start:

	# Začiatok jadra napísaný.
	# Bootloader je schopný spustiť náš kód

	# Kód bude napísaný hlavne v jazyku C++
	# Tu ho pripravíme

	# Najprv nadstavím register na vrch stacku

	movl $stack_top, %esp

	# Teraz zavoláme funkciu kernelStartPoint zo súboru C
	call kernelStartPoint

	# Po ukončení funkcie zasekneme PC
	cli
	hlt

.Lhang:
	jmp .Lhang

# Nadstavenie velkosťi "start" sekcie
.size _start, . - _start
