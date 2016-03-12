CC=../cross/bin/i686-elf-g++
ASM=../cross/bin/i686-elf-as
CCFLAGS=-c -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
ASMFLAGS=
LDFLAGS=-T src/linker.ld -ffreestanding -O2 -nostdlib -lgcc
MKRESCUE=grub-mkrescue
QEMU=qemu-system-i386 

all: build

build:
	$(CC) src/Kernel/Kernel.cpp -o kernel.o $(CCFLAGS)
	$(CC) src/Kernel/Includes/Terminal.cpp -o terminal.o $(CCFLAGS)
	$(CC) src/Kernel/Includes/Keyboard.cpp -o keyboard.o $(CCFLAGS)
	$(CC) src/Kernel/Includes/Types.cpp -o types.o $(CCFLAGS)
	$(CC) src/Kernel/Includes/Memory.cpp -o memory.o $(CCFLAGS)
	$(ASM) src/Kernel/boot.s -o boot.o $(ASMFLAGS)
	$(CC) $(LDFLAGS) -o kernel.bin boot.o memory.o terminal.o keyboard.o types.o kernel.o
	cp src/boot/grub.cfg isodir/boot/grub/grub.cfg
	mv kernel.bin isodir/boot/kernel.bin
	rm boot.o
	rm memory.o
	rm terminal.o
	rm keyboard.o
	rm types.o
	rm kernel.o
	mv isodir/boot/kernel.bin bin/kernel.bin

test:
	$(QEMU) -kernel bin/kernel.bin

build_and_test: build
	$(QEMU) -kernel bin/kernel.bin


	
