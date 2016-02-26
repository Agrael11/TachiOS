CC=../cross/bin/i686-elf-g++
ASM=../cross/bin/i686-elf-as
CCFLAGS=-c -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
ASMFLAGS=
LDFLAGS=-T src/linker.ld -ffreestanding -O2 -nostdlib -lgcc
MKRESCUE=grub-mkrescue
QEMU=qemu-system-i386 

all: build

build:
	$(CC) src/Kernel/kernel.cpp -o kernel.o $(CCFLAGS)
	$(CC) src/Kernel/Includes/terminal.cpp -o terminal.o $(CCFLAGS)
	$(ASM) src/Kernel/boot.s -o boot.o $(ASMFLAGS)
	$(CC) $(LDFLAGS) -o kernel.bin boot.o terminal.o kernel.o
	cp src/boot/grub.cfg isodir/boot/grub/grub.cfg
	mv kernel.bin isodir/boot/kernel.bin
	rm kernel.o
	rm boot.o
	rm terminal.o
	$(MKRESCUE) -o build.iso isodir
	mv build.iso bin/build.iso
	rm isodir/boot/kernel.bin

test:
	$(QEMU) -cdrom bin/build.iso

build_and_test: build
	$(QEMU) -cdrom bin/build.iso


	
