
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

class Kernel
{
	Terminal terminal;

public:
	void main() {
		terminal.write("\n\n\n");
		terminal.write("*******    ***     *****   *     *   *****             *****    ***** \n");
		terminal.write("   *      *   *   *     *  *     *     *              *     *  *     *\n");
		terminal.write("   *     *     *  *        *     *     *              *     *   **    \n");
		terminal.write("   *     *     *  *        *******     *              *     *     *   \n");
		terminal.write("   *     *******  *        *     *     *              *     *      ** \n");
		terminal.write("   *     *     *  *     *  *     *     *              *     *  *     *\n");
		terminal.write("   *     *     *   *****   *     *   *****             *****    ***** \n");
		terminal.write("\n\n\n");
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
				terminal.write("   \n");
			}
		}
	}
};

#if defined(__cplusplus)
extern "C"
#endif
void kernelStartPoint()
{
	Kernel kernel;
	kernel.main();
}
