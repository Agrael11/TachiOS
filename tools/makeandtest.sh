../../tools/buildassembly.sh boot.s boot.o
../../tools/buildcpp.sh kernel.cpp kernel.o
../../tools/link.sh
cd ../../tools
./makeiso.sh
cd ../build
qemu-system-i386 -cdrom build.iso
