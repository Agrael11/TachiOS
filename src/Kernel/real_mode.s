.global add

add:
push %ebp
movl %esp, %ebp
movl 8(%ebp),%eax
movl 12(%ebp),%ecx
add %ecx, %eax
//movl $0, %eax Vysledok je v EAX
movl %ebp, %esp
popl %ebp
ret
