#include <stddef.h>
#include <stdint.h>
#include "terminal.cpp" 
#include "ports.cpp"

#if defined(__linux__)
#error "You are not using a cross-compiler!"
#endif
 
#if !defined(__i386__)
#error "You have to use i386-elf-g++ to build.. or my automated script!"
#endif

extern "C" {int add(int a, int b);}
//extern "C" {int sub(int a, int b);}
#if defined(__cplusplus)

extern "C"

#endif
void kernel_main() {
	terminal_initialize();
	int b = add(5,5);
	terminal_write(b);
	terminal_write("\nTHIS!\nIS!\nKERNEEEEL!\n");
	while (true)
	{
		int i = inb(0x60);
		terminal_write(i);
		terminal_column = 0;
		i++;
	}
}	
