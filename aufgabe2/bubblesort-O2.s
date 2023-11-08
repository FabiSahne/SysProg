	.file	"bubblesort.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Aufruf: ./bubblesort <zahl>"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC1:
	.string	"Bitte %d ganze Zahlen eingeben: "
	.section	.rodata.str1.1
.LC2:
	.string	"%d"
.LC3:
	.string	"%d\n"
.LC4:
	.string	"Sortierte Zahlenfolge: "
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB22:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	movq	%rsi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movl	%edi, %ebx
	subq	$40, %rsp
	.cfi_def_cfa_offset 96
	leaq	24(%rsp), %rdi
	call	time
	movl	%eax, %edi
	call	srand
	cmpl	$2, %ebx
	jne	.L25
	movq	8(%rbp), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	call	strtol
	movslq	%eax, %rdi
	movq	%rax, %r13
	salq	$2, %rdi
	call	malloc
	movq	%rax, %rbx
	testq	%rax, %rax
	je	.L15
	xorl	%eax, %eax
	movl	%r13d, %esi
	movl	$.LC1, %edi
	call	printf
	testl	%r13d, %r13d
	jle	.L4
	leal	-1(%r13), %eax
	leaq	4(%rbx), %rbp
	movq	%rbx, %r14
	xorl	%r12d, %r12d
	movl	%eax, 12(%rsp)
	leaq	0(%rbp,%rax,4), %r15
	.p2align 4,,10
	.p2align 3
.L6:
	movq	%r14, %rsi
	xorl	%eax, %eax
	movl	$.LC2, %edi
	call	__isoc99_scanf
	cmpl	$1, %eax
	sete	%al
	addq	$4, %r14
	movzbl	%al, %eax
	addl	%eax, %r12d
	cmpq	%r15, %r14
	jne	.L6
	cmpl	%r13d, %r12d
	jge	.L7
	movl	12(%rsp), %eax
	movslq	%r12d, %rcx
	leaq	(%rbx,%rcx,4), %r14
	subl	%r12d, %eax
	addq	%rcx, %rax
	leaq	0(%rbp,%rax,4), %r15
	.p2align 4,,10
	.p2align 3
.L8:
	call	rand
	addq	$4, %r14
	movl	$.LC3, %edi
	movl	%eax, -4(%r14)
	movl	%eax, %esi
	xorl	%eax, %eax
	call	printf
	cmpq	%r15, %r14
	jne	.L8
.L7:
	cmpl	$1, %r13d
	je	.L9
	subl	$2, %r13d
	.p2align 4,,10
	.p2align 3
.L10:
	movl	%r13d, %eax
	leaq	0(%rbp,%rax,4), %rsi
	movq	%rbx, %rax
	.p2align 4,,10
	.p2align 3
.L12:
	movq	(%rax), %xmm0
	pshufd	$0xe5, %xmm0, %xmm1
	movd	%xmm0, %ecx
	movd	%xmm1, %edx
	cmpl	%edx, %ecx
	jle	.L11
	pshufd	$225, %xmm0, %xmm0
	movq	%xmm0, (%rax)
.L11:
	addq	$4, %rax
	cmpq	%rsi, %rax
	jne	.L12
	subl	$1, %r13d
	jnb	.L10
.L9:
	movl	$.LC4, %edi
	movq	%rbx, %r13
	call	puts
	movl	12(%rsp), %r12d
	leaq	0(%rbp,%r12,4), %rbp
	.p2align 4,,10
	.p2align 3
.L13:
	movl	0(%r13), %esi
	movl	$.LC3, %edi
	xorl	%eax, %eax
	addq	$4, %r13
	call	printf
	cmpq	%rbp, %r13
	jne	.L13
.L14:
	movq	%rbx, %rdi
	call	free
	xorl	%eax, %eax
.L1:
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L25:
	.cfi_restore_state
	movl	$.LC0, %edi
	call	perror
	movl	$22, %eax
	jmp	.L1
.L4:
	movl	$.LC4, %edi
	call	puts
	jmp	.L14
.L15:
	movl	$12, %eax
	jmp	.L1
	.cfi_endproc
.LFE22:
	.size	main, .-main
	.ident	"GCC: (GNU) 13.2.1 20231011 (Red Hat 13.2.1-4)"
	.section	.note.GNU-stack,"",@progbits
