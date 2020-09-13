.globl nCr
    .type   nCr, @function

nCr:
    .cfi_startproc
    ## BB#0:
    pushq	%rbp
    Ltmp3:
    .cfi_def_cfa_offset 16
    Ltmp4:
    .cfi_offset %rbp, -16
    movq	%rsp, %rbp
    Ltmp5:
    .cfi_def_cfa_register %rbp
    subq	$32, %rsp
    movl	%edi, -4(%rbp)
    movl	%esi, -8(%rbp)
    movl	-4(%rbp), %edi
    callq	Factorial
    movl	%eax, -12(%rbp)
    movl	-8(%rbp), %edi
    callq	Factorial
    movl	%eax, -16(%rbp)
    movl	-4(%rbp), %eax
    subl	-8(%rbp), %eax
    movl	%eax, -20(%rbp)
    movl	-20(%rbp), %edi
    callq	Factorial
    movl	%eax, -24(%rbp)
    movl	-12(%rbp), %eax
    movl	-16(%rbp), %esi
    imull	-24(%rbp), %esi
    cltd
    idivl	%esi
    movl	%eax, -28(%rbp)
    movl	-28(%rbp), %eax
    addq	$32, %rsp
    popq	%rbp
    retq
    .cfi_endproc

.globl Factorial
        .type   Factorial, @function

Factorial:

    .cfi_startproc
    ## BB#0:
    pushq	%rbp
    Ltmp0:
    .cfi_def_cfa_offset 16
    Ltmp1:
    .cfi_offset %rbp, -16
    movq	%rsp, %rbp
    Ltmp2:
    .cfi_def_cfa_register %rbp
    movl	%edi, -4(%rbp)
    movl	$1, -12(%rbp)
    movl	$1, -8(%rbp)
    LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
    movl	-8(%rbp), %eax
    cmpl	-4(%rbp), %eax
    jg	LBB0_4
    ## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
    movl	-12(%rbp), %eax
    imull	-8(%rbp), %eax
    movl	%eax, -12(%rbp)
    ## BB#3:                                ##   in Loop: Header=BB0_1 Depth=1
    movl	-8(%rbp), %eax
    addl	$1, %eax
    movl	%eax, -8(%rbp)
    jmp	LBB0_1
    LBB0_4:
    movl	-12(%rbp), %eax
    popq	%rbp
    retq
    .cfi_endproc
    .globl	nCr
    .align	4, 0x90





