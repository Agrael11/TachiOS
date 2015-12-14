.global add

add:
push %ebp
movl %esp, %ebp
movl 8(%ebp),%eax
movl 12(%ebp),%ecx
addl %ecx, %eax
movl %esp, %ebp
popl %ebp
ret
