#include <stddef.h>
#include <stdint.h>
#include "terminal.cpp" 

#if defined(__linux__)
#error "You are not using a cross-compiler idiot"
#endif
 
#if !defined(__i386__)
#error "You have to use i386-elf-g++ to build.. or my automated script you bitch!"
#endif

 
#if defined(__cplusplus)
extern "C"
#endif
void kernel_main() {
	terminal_initialize();
	terminal_writestring("THIS!\nIS!\nKERNEEEEL!\n");
}	
