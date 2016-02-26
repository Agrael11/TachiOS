#include "Includes/types.h"
#include "Includes/ports.h"
#include "Includes/terminal.h"

#if defined(__linux__)
#error "You are not using a cross-compiler!"
#endif
 
#if !defined(__i386__)
#error "You have to use i386-elf-g++ to build.. or my automated script!"
#endif

//extern "C" {int add(int a, int b);}
//extern "C" {int sub(int a, int b);}


#if defined(__cplusplus)

extern "C"

#endif
void kernel_main() {
	terminal_initialize();
	terminal_write("THIS!\nIS!\nKERNEEEEL!\n");
	while (true)
	{
		int i = inb(0x60);
		terminal_write(i);
		terminal_write("     ");
		terminal_column = 0;
		i++;
	}
}	



