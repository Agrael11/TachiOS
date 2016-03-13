
#if defined(__linux__)
#error "You are not using a cross-compiler!"
#endif
 
#if !defined(__i386__)
#error "You have to use i386-elf-g++ to build.. or my automated script!"
#endif

#include "Includes/Types.h"
#include "Includes/Ports.h"
#include "Includes/Terminal.h"
#include "Includes/Memory.h"
#include "Includes/Multiboot.h"

class Kernel
{
	Terminal terminal;

public:

	void main(multiboot_info_t* mbd, unsigned int magic) {
		terminal.writeLine("*******    ***     *****   *     *   *****             *****    ***** ");
		terminal.writeLine("   *      *   *   *     *  *     *     *              *     *  *     *");
		terminal.writeLine("   *     *     *  *        *     *     *              *     *   **    ");
		terminal.writeLine("   *     *     *  *        *******     *              *     *     *   ");
		terminal.writeLine("   *     *******  *        *     *     *              *     *      ** ");
		terminal.writeLine("   *     *     *  *     *  *     *     *              *     *  *     *");
		terminal.writeLine("   *     *     *   *****   *     *   *****             *****    ***** ");
		if (((mbd->flags)&1)==1)
		{
			memInfoAvailable=true;
			lowMem = mbd->mem_lower;
			uppMem = mbd->mem_upper;
			terminal.write("Available ");
			terminal.write(lowMem);
			terminal.writeLine("kb in lower memory.");
			terminal.write("Available ");
			terminal.write(uppMem);
			terminal.writeLine("kb in upper memory.");
		}
		if (((mbd->flags)&64)==64)
		{
			mapAvailable=true;
			mapAddress = mbd->mmap_addr;
			mapLength = mbd->mmap_length;
		}
		int last = 0;
		int i = 0;
		while (i != 1)
		{
			i = inb(0x60);
			if (last != i)
			{
				last = i;
				terminal.column = 0;
				terminal.write("Keyboard ScanCode:");
				terminal.write(i);
				terminal.writeLine("   ");
			}
		}
	}
};

#if defined(__cplusplus)
extern "C"
#endif
void kernelStartPoint(multiboot_info_t* mbd, unsigned int magic)
{
	Kernel kernel;
	kernel.main(mbd, magic);
}
