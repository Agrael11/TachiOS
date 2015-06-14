mkdir ../tmp
cd ../tmp
mkdir isodir
mkdir isodir/boot
mkdir isodir/boot/grub
cp ../src/boot/grub.cfg isodir/boot/grub/grub.cfg
cp ../src/Kernel/kernel.bin isodir/boot/kernel.bin
grub-mkrescue -o build.iso isodir
cp build.iso ../build/build.iso
cd ..
rm -r tmp
cd tools
