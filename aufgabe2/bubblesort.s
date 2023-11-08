	.file	"bubblesort.c"
	.text
	.section	.rodata
.LC0:
	.string	"Aufruf: ./bubblesort <zahl>"
	.align 8
.LC1:
	.string	"Bitte %d ganze Zahlen eingeben: "
.LC2:
	.string	"%d"
.LC3:
	.string	"%d\n"
.LC4:
	.string	"Sortierte Zahlenfolge: "
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 3, -24
	movl	%edi, -84(%rbp)
	movq	%rsi, -96(%rbp)
	leaq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	time
	movl	%eax, %edi
	call	srand
	cmpl	$2, -84(%rbp)
	je	.L2
	movl	$.LC0, %edi
	call	perror
	movl	$22, %eax
	jmp	.L17
.L2:
	movq	-96(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -44(%rbp)
	movl	-44(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, -56(%rbp)
	cmpq	$0, -56(%rbp)
	jne	.L4
	movl	$12, %eax
	jmp	.L17
.L4:
	movl	-44(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -20(%rbp)
	movl	$0, -24(%rbp)
	jmp	.L5
.L7:
	movl	-24(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	cmpl	$1, %eax
	jne	.L6
	addl	$1, -20(%rbp)
.L6:
	addl	$1, -24(%rbp)
.L5:
	movl	-24(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.L7
	movl	-20(%rbp), %eax
	movl	%eax, -28(%rbp)
	jmp	.L8
.L9:
	movl	-28(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-56(%rbp), %rax
	leaq	(%rdx,%rax), %rbx
	call	rand
	movl	%eax, (%rbx)
	movl	-28(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -28(%rbp)
.L8:
	movl	-28(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.L9
	movl	-44(%rbp), %eax
	movl	%eax, -32(%rbp)
	jmp	.L10
.L14:
	movl	$0, -36(%rbp)
	jmp	.L11
.L13:
	movl	-36(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-36(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rcx
	movq	-56(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jle	.L12
	movl	-36(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -60(%rbp)
	movl	-36(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	-36(%rbp), %edx
	movslq	%edx, %rdx
	addq	$1, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	-56(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	movl	-36(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-56(%rbp), %rax
	addq	%rax, %rdx
	movl	-60(%rbp), %eax
	movl	%eax, (%rdx)
.L12:
	addl	$1, -36(%rbp)
.L11:
	movl	-32(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -36(%rbp)
	jl	.L13
	subl	$1, -32(%rbp)
.L10:
	cmpl	$1, -32(%rbp)
	jg	.L14
	movl	$.LC4, %edi
	call	puts
	movl	$0, -40(%rbp)
	jmp	.L15
.L16:
	movl	-40(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -40(%rbp)
.L15:
	movl	-40(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.L16
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	free
	movl	$0, %eax
.L17:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (GNU) 13.2.1 20231011 (Red Hat 13.2.1-4)"
	.section	.note.GNU-stack,"",@progbits
