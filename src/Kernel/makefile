CC=i686-elf-g++
ASM=i686-elf-as
CCFLAGS=-c -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
ASMFLAGS=
LDFLAGS=-T linker.ld -ffreestanding -O2 -nostdlib -lgcc
MKRESCUE=grub-mkrescue

all: build

build:
	$(CC) kernel.cpp -o kernel.o $(CCFLAGS)
	$(ASM) boot.s -o boot.o $(ASMFLAGS)
	$(ASM) real_mode.s -o real_mode.o $(ASMFLAGS)
	$(CC) $(LDFLAGS) -o kernel.bin boot.o kernel.o real_mode.o
	cp ../boot/grub.cfg ../../isodir/boot/grub/grub.cfg
	cp kernel.bin ../../isodir/boot/kernel.bin
	$(MKRESCUE) -o build.iso ../../isodir
	mv build.iso ../../build/build.iso

build_and_test: build
	qemu-system-i386 -cdrom ../../build/build.iso

push:
	cd ../..
	git add *
	git commit -m "$1"
	git push origin master

	