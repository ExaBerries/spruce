	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90         ## -- Begin function __cxx_global_var_init
___cxx_global_var_init:                 ## @__cxx_global_var_init
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	callq	__ZN9benchmark8internal17InitializeStreamsEv
	movl	%eax, __ZN9benchmark8internalL18stream_init_anchorE(%rip)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function __cxx_global_var_init.1
___cxx_global_var_init.1:               ## @__cxx_global_var_init.1
Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception0
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$192, %eax
	movl	%eax, %edi
	callq	__Znwm
	movq	%rax, %rdi
	movq	%rax, %rcx
Ltmp0:
	leaq	L_.str(%rip), %rsi
	leaq	__ZL14vec3dConstructRN9benchmark5StateE(%rip), %rdx
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rcx, -32(%rbp)         ## 8-byte Spill
	callq	__ZN9benchmark8internal17FunctionBenchmarkC1EPKcPFvRNS_5StateEE
Ltmp1:
	jmp	LBB1_1
LBB1_1:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__ZN9benchmark8internal25RegisterBenchmarkInternalEPNS0_9BenchmarkE
	movq	%rax, __ZL26_benchmark_2vec3dConstruct(%rip)
	addq	$32, %rsp
	popq	%rbp
	retq
LBB1_2:
Ltmp2:
	movl	%edx, %ecx
	movq	%rax, -8(%rbp)
	movl	%ecx, -12(%rbp)
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	callq	__ZdlPv
## %bb.3:
	movq	-8(%rbp), %rdi
	callq	__Unwind_Resume
	ud2
Lfunc_end0:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table1:
Lexception0:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	255                     ## @TType Encoding = omit
	.byte	1                       ## Call site Encoding = uleb128
	.uleb128 Lcst_end0-Lcst_begin0
Lcst_begin0:
	.uleb128 Lfunc_begin0-Lfunc_begin0 ## >> Call Site 1 <<
	.uleb128 Ltmp0-Lfunc_begin0     ##   Call between Lfunc_begin0 and Ltmp0
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp0-Lfunc_begin0     ## >> Call Site 2 <<
	.uleb128 Ltmp1-Ltmp0            ##   Call between Ltmp0 and Ltmp1
	.uleb128 Ltmp2-Lfunc_begin0     ##     jumps to Ltmp2
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp1-Lfunc_begin0     ## >> Call Site 3 <<
	.uleb128 Lfunc_end0-Ltmp1       ##   Call between Ltmp1 and Lfunc_end0
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lcst_end0:
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.p2align	4, 0x90         ## -- Begin function _ZL14vec3dConstructRN9benchmark5StateE
__ZL14vec3dConstructRN9benchmark5StateE: ## @_ZL14vec3dConstructRN9benchmark5StateE
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	andq	$-32, %rsp
	subq	$288, %rsp              ## imm = 0x120
	movq	%rdi, 120(%rsp)
	movq	120(%rsp), %rdi
	movq	%rdi, 112(%rsp)
	movq	112(%rsp), %rdi
	movq	%rdi, 128(%rsp)
	movq	128(%rsp), %rdi
	leaq	136(%rsp), %rax
	movq	%rax, 160(%rsp)
	movq	%rdi, 152(%rsp)
	movq	160(%rsp), %rax
	movq	152(%rsp), %rdi
	movq	%rax, 176(%rsp)
	movq	%rdi, 168(%rsp)
	movq	176(%rsp), %rax
	movq	168(%rsp), %rdi
	testb	$1, 26(%rdi)
	movq	%rax, 24(%rsp)          ## 8-byte Spill
	je	LBB2_2
## %bb.1:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, 16(%rsp)          ## 8-byte Spill
	jmp	LBB2_3
LBB2_2:
	movq	168(%rsp), %rax
	movq	16(%rax), %rax
	movq	%rax, 16(%rsp)          ## 8-byte Spill
LBB2_3:
	movq	16(%rsp), %rax          ## 8-byte Reload
	movq	24(%rsp), %rcx          ## 8-byte Reload
	movq	%rax, (%rcx)
	movq	168(%rsp), %rax
	movq	%rax, 8(%rcx)
	movq	136(%rsp), %rax
	movq	144(%rsp), %rdx
	movq	%rax, 96(%rsp)
	movq	%rdx, 104(%rsp)
	movq	112(%rsp), %rax
	movq	%rax, 192(%rsp)
	movq	192(%rsp), %rdi
	callq	__ZN9benchmark5State16StartKeepRunningEv
	leaq	200(%rsp), %rax
	movq	%rax, 216(%rsp)
	movq	216(%rsp), %rax
	movq	%rax, 224(%rsp)
	movq	224(%rsp), %rax
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	200(%rsp), %rax
	movq	208(%rsp), %rcx
	movq	%rax, 80(%rsp)
	movq	%rcx, 88(%rsp)
LBB2_4:                                 ## =>This Inner Loop Header: Depth=1
	leaq	96(%rsp), %rax
	movq	%rax, 240(%rsp)
	leaq	80(%rsp), %rax
	movq	%rax, 232(%rsp)
	movq	240(%rsp), %rax
	cmpq	$0, (%rax)
	movq	%rax, 8(%rsp)           ## 8-byte Spill
	je	LBB2_6
## %bb.5:                               ##   in Loop: Header=BB2_4 Depth=1
	movb	$1, 255(%rsp)
	jmp	LBB2_7
LBB2_6:                                 ##   in Loop: Header=BB2_4 Depth=1
	movq	8(%rsp), %rax           ## 8-byte Reload
	movq	8(%rax), %rdi
	callq	__ZN9benchmark5State17FinishKeepRunningEv
	movb	$0, 255(%rsp)
LBB2_7:                                 ##   in Loop: Header=BB2_4 Depth=1
	testb	$1, 255(%rsp)
	jne	LBB2_8
	jmp	LBB2_12
LBB2_8:                                 ##   in Loop: Header=BB2_4 Depth=1
	leaq	96(%rsp), %rax
	movq	%rax, 256(%rsp)
	leaq	32(%rsp), %rdi
	callq	__ZN6spruce5vec3dC1Ev
	leaq	32(%rsp), %rax
	movq	%rax, 264(%rsp)
	movq	264(%rsp), %rax
	## InlineAsm Start
	## InlineAsm End
## %bb.9:                               ##   in Loop: Header=BB2_4 Depth=1
	leaq	96(%rsp), %rax
	movq	%rax, 184(%rsp)
	movq	184(%rsp), %rax
	cmpq	$0, (%rax)
	seta	%cl
	xorb	$-1, %cl
	testb	$1, %cl
	movq	%rax, (%rsp)            ## 8-byte Spill
	jne	LBB2_10
	jmp	LBB2_11
LBB2_10:
	leaq	L___func__._ZN9benchmark5State13StateIteratorppEv(%rip), %rdi
	leaq	L_.str.16(%rip), %rsi
	leaq	L_.str.17(%rip), %rcx
	movl	$697, %edx              ## imm = 0x2B9
	callq	___assert_rtn
LBB2_11:                                ##   in Loop: Header=BB2_4 Depth=1
	movq	(%rsp), %rax            ## 8-byte Reload
	movq	(%rax), %rcx
	addq	$-1, %rcx
	movq	%rcx, (%rax)
	jmp	LBB2_4
LBB2_12:
	movq	%rbp, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN9benchmark8internal17FunctionBenchmarkC1EPKcPFvRNS_5StateEE ## -- Begin function _ZN9benchmark8internal17FunctionBenchmarkC1EPKcPFvRNS_5StateEE
	.weak_def_can_be_hidden	__ZN9benchmark8internal17FunctionBenchmarkC1EPKcPFvRNS_5StateEE
	.p2align	4, 0x90
__ZN9benchmark8internal17FunctionBenchmarkC1EPKcPFvRNS_5StateEE: ## @_ZN9benchmark8internal17FunctionBenchmarkC1EPKcPFvRNS_5StateEE
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movq	-24(%rbp), %rdx
	callq	__ZN9benchmark8internal17FunctionBenchmarkC2EPKcPFvRNS_5StateEE
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90         ## -- Begin function __cxx_global_var_init.2
___cxx_global_var_init.2:               ## @__cxx_global_var_init.2
Lfunc_begin1:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception1
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$192, %eax
	movl	%eax, %edi
	callq	__Znwm
	movq	%rax, %rdi
	movq	%rax, %rcx
Ltmp3:
	leaq	L_.str.3(%rip), %rsi
	leaq	__ZL10vec3dScaleRN9benchmark5StateE(%rip), %rdx
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rcx, -32(%rbp)         ## 8-byte Spill
	callq	__ZN9benchmark8internal17FunctionBenchmarkC1EPKcPFvRNS_5StateEE
Ltmp4:
	jmp	LBB4_1
LBB4_1:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__ZN9benchmark8internal25RegisterBenchmarkInternalEPNS0_9BenchmarkE
	movq	%rax, __ZL22_benchmark_3vec3dScale(%rip)
	addq	$32, %rsp
	popq	%rbp
	retq
LBB4_2:
Ltmp5:
	movl	%edx, %ecx
	movq	%rax, -8(%rbp)
	movl	%ecx, -12(%rbp)
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	callq	__ZdlPv
## %bb.3:
	movq	-8(%rbp), %rdi
	callq	__Unwind_Resume
	ud2
Lfunc_end1:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table4:
Lexception1:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	255                     ## @TType Encoding = omit
	.byte	1                       ## Call site Encoding = uleb128
	.uleb128 Lcst_end1-Lcst_begin1
Lcst_begin1:
	.uleb128 Lfunc_begin1-Lfunc_begin1 ## >> Call Site 1 <<
	.uleb128 Ltmp3-Lfunc_begin1     ##   Call between Lfunc_begin1 and Ltmp3
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp3-Lfunc_begin1     ## >> Call Site 2 <<
	.uleb128 Ltmp4-Ltmp3            ##   Call between Ltmp3 and Ltmp4
	.uleb128 Ltmp5-Lfunc_begin1     ##     jumps to Ltmp5
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp4-Lfunc_begin1     ## >> Call Site 3 <<
	.uleb128 Lfunc_end1-Ltmp4       ##   Call between Ltmp4 and Lfunc_end1
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lcst_end1:
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__literal4,4byte_literals
	.p2align	2               ## -- Begin function _ZL10vec3dScaleRN9benchmark5StateE
LCPI5_0:
	.long	1073741824              ## float 2
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3
LCPI5_1:
	.quad	4616189618054758400     ## double 4
	.section	__TEXT,__text,regular,pure_instructions
	.p2align	4, 0x90
__ZL10vec3dScaleRN9benchmark5StateE:    ## @_ZL10vec3dScaleRN9benchmark5StateE
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	andq	$-32, %rsp
	subq	$384, %rsp              ## imm = 0x180
	vmovsd	LCPI5_1(%rip), %xmm0    ## xmm0 = mem[0],zero
	movq	%rdi, 216(%rsp)
	leaq	160(%rsp), %rdi
	vmovsd	%xmm0, 56(%rsp)         ## 8-byte Spill
	vmovsd	56(%rsp), %xmm1         ## 8-byte Reload
                                        ## xmm1 = mem[0],zero
	vmovsd	56(%rsp), %xmm2         ## 8-byte Reload
                                        ## xmm2 = mem[0],zero
	callq	__ZN6spruce5vec3dC1Eddd
	vmovss	LCPI5_0(%rip), %xmm0    ## xmm0 = mem[0],zero,zero,zero
	vmovss	%xmm0, 156(%rsp)
	movq	216(%rsp), %rdi
	movq	%rdi, 144(%rsp)
	movq	144(%rsp), %rdi
	movq	%rdi, 224(%rsp)
	movq	224(%rsp), %rdi
	leaq	232(%rsp), %rax
	movq	%rax, 256(%rsp)
	movq	%rdi, 248(%rsp)
	movq	256(%rsp), %rax
	movq	248(%rsp), %rdi
	movq	%rax, 272(%rsp)
	movq	%rdi, 264(%rsp)
	movq	272(%rsp), %rax
	movq	264(%rsp), %rdi
	testb	$1, 26(%rdi)
	movq	%rax, 48(%rsp)          ## 8-byte Spill
	je	LBB5_2
## %bb.1:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, 40(%rsp)          ## 8-byte Spill
	jmp	LBB5_3
LBB5_2:
	movq	264(%rsp), %rax
	movq	16(%rax), %rax
	movq	%rax, 40(%rsp)          ## 8-byte Spill
LBB5_3:
	movq	40(%rsp), %rax          ## 8-byte Reload
	movq	48(%rsp), %rcx          ## 8-byte Reload
	movq	%rax, (%rcx)
	movq	264(%rsp), %rax
	movq	%rax, 8(%rcx)
	movq	232(%rsp), %rax
	movq	240(%rsp), %rdx
	movq	%rax, 128(%rsp)
	movq	%rdx, 136(%rsp)
	movq	144(%rsp), %rax
	movq	%rax, 288(%rsp)
	movq	288(%rsp), %rdi
	callq	__ZN9benchmark5State16StartKeepRunningEv
	leaq	296(%rsp), %rax
	movq	%rax, 312(%rsp)
	movq	312(%rsp), %rax
	movq	%rax, 320(%rsp)
	movq	320(%rsp), %rax
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	296(%rsp), %rax
	movq	304(%rsp), %rcx
	movq	%rax, 112(%rsp)
	movq	%rcx, 120(%rsp)
LBB5_4:                                 ## =>This Inner Loop Header: Depth=1
	leaq	128(%rsp), %rax
	movq	%rax, 336(%rsp)
	leaq	112(%rsp), %rax
	movq	%rax, 328(%rsp)
	movq	336(%rsp), %rax
	cmpq	$0, (%rax)
	movq	%rax, 32(%rsp)          ## 8-byte Spill
	je	LBB5_6
## %bb.5:                               ##   in Loop: Header=BB5_4 Depth=1
	movb	$1, 351(%rsp)
	jmp	LBB5_7
LBB5_6:                                 ##   in Loop: Header=BB5_4 Depth=1
	movq	32(%rsp), %rax          ## 8-byte Reload
	movq	8(%rax), %rdi
	callq	__ZN9benchmark5State17FinishKeepRunningEv
	movb	$0, 351(%rsp)
LBB5_7:                                 ##   in Loop: Header=BB5_4 Depth=1
	testb	$1, 351(%rsp)
	jne	LBB5_8
	jmp	LBB5_12
LBB5_8:                                 ##   in Loop: Header=BB5_4 Depth=1
	leaq	128(%rsp), %rax
	movq	%rax, 352(%rsp)
	vmovss	156(%rsp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
                                        ## implicit-def: $xmm1
	vcvtss2sd	%xmm0, %xmm1, %xmm0
	leaq	64(%rsp), %rdi
	leaq	160(%rsp), %rsi
	callq	__ZN6sprucemlERKNS_5vec3dEd
	leaq	64(%rsp), %rax
	movq	%rax, 360(%rsp)
	movq	360(%rsp), %rax
	## InlineAsm Start
	## InlineAsm End
## %bb.9:                               ##   in Loop: Header=BB5_4 Depth=1
	leaq	128(%rsp), %rax
	movq	%rax, 280(%rsp)
	movq	280(%rsp), %rax
	cmpq	$0, (%rax)
	seta	%cl
	xorb	$-1, %cl
	testb	$1, %cl
	movq	%rax, 24(%rsp)          ## 8-byte Spill
	jne	LBB5_10
	jmp	LBB5_11
LBB5_10:
	leaq	L___func__._ZN9benchmark5State13StateIteratorppEv(%rip), %rdi
	leaq	L_.str.16(%rip), %rsi
	leaq	L_.str.17(%rip), %rcx
	movl	$697, %edx              ## imm = 0x2B9
	callq	___assert_rtn
LBB5_11:                                ##   in Loop: Header=BB5_4 Depth=1
	movq	24(%rsp), %rax          ## 8-byte Reload
	movq	(%rax), %rcx
	addq	$-1, %rcx
	movq	%rcx, (%rax)
	jmp	LBB5_4
LBB5_12:
	movq	%rbp, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90         ## -- Begin function __cxx_global_var_init.4
___cxx_global_var_init.4:               ## @__cxx_global_var_init.4
Lfunc_begin2:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception2
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$192, %eax
	movl	%eax, %edi
	callq	__Znwm
	movq	%rax, %rdi
	movq	%rax, %rcx
Ltmp6:
	leaq	L_.str.5(%rip), %rsi
	leaq	__ZL11vec3dAddVecRN9benchmark5StateE(%rip), %rdx
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rcx, -32(%rbp)         ## 8-byte Spill
	callq	__ZN9benchmark8internal17FunctionBenchmarkC1EPKcPFvRNS_5StateEE
Ltmp7:
	jmp	LBB6_1
LBB6_1:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__ZN9benchmark8internal25RegisterBenchmarkInternalEPNS0_9BenchmarkE
	movq	%rax, __ZL23_benchmark_4vec3dAddVec(%rip)
	addq	$32, %rsp
	popq	%rbp
	retq
LBB6_2:
Ltmp8:
	movl	%edx, %ecx
	movq	%rax, -8(%rbp)
	movl	%ecx, -12(%rbp)
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	callq	__ZdlPv
## %bb.3:
	movq	-8(%rbp), %rdi
	callq	__Unwind_Resume
	ud2
Lfunc_end2:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table6:
Lexception2:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	255                     ## @TType Encoding = omit
	.byte	1                       ## Call site Encoding = uleb128
	.uleb128 Lcst_end2-Lcst_begin2
Lcst_begin2:
	.uleb128 Lfunc_begin2-Lfunc_begin2 ## >> Call Site 1 <<
	.uleb128 Ltmp6-Lfunc_begin2     ##   Call between Lfunc_begin2 and Ltmp6
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp6-Lfunc_begin2     ## >> Call Site 2 <<
	.uleb128 Ltmp7-Ltmp6            ##   Call between Ltmp6 and Ltmp7
	.uleb128 Ltmp8-Lfunc_begin2     ##     jumps to Ltmp8
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp7-Lfunc_begin2     ## >> Call Site 3 <<
	.uleb128 Lfunc_end2-Ltmp7       ##   Call between Ltmp7 and Lfunc_end2
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lcst_end2:
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function _ZL11vec3dAddVecRN9benchmark5StateE
LCPI7_0:
	.quad	4607182418800017408     ## double 1
	.section	__TEXT,__text,regular,pure_instructions
	.p2align	4, 0x90
__ZL11vec3dAddVecRN9benchmark5StateE:   ## @_ZL11vec3dAddVecRN9benchmark5StateE
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	andq	$-32, %rsp
	subq	$416, %rsp              ## imm = 0x1A0
	vmovsd	LCPI7_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	movq	%rdi, 248(%rsp)
	leaq	192(%rsp), %rdi
	vxorps	%xmm1, %xmm1, %xmm1
	vmovsd	%xmm1, 56(%rsp)         ## 8-byte Spill
	vmovsd	56(%rsp), %xmm2         ## 8-byte Reload
                                        ## xmm2 = mem[0],zero
	callq	__ZN6spruce5vec3dC1Eddd
	vmovsd	LCPI7_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	leaq	160(%rsp), %rdi
	vxorps	%xmm1, %xmm1, %xmm1
	vmovsd	%xmm0, 48(%rsp)         ## 8-byte Spill
	vmovaps	%xmm1, %xmm0
	vmovsd	48(%rsp), %xmm1         ## 8-byte Reload
                                        ## xmm1 = mem[0],zero
	vmovsd	48(%rsp), %xmm2         ## 8-byte Reload
                                        ## xmm2 = mem[0],zero
	callq	__ZN6spruce5vec3dC1Eddd
	movq	248(%rsp), %rdi
	movq	%rdi, 152(%rsp)
	movq	152(%rsp), %rdi
	movq	%rdi, 256(%rsp)
	movq	256(%rsp), %rdi
	leaq	264(%rsp), %rax
	movq	%rax, 288(%rsp)
	movq	%rdi, 280(%rsp)
	movq	288(%rsp), %rax
	movq	280(%rsp), %rdi
	movq	%rax, 304(%rsp)
	movq	%rdi, 296(%rsp)
	movq	304(%rsp), %rax
	movq	296(%rsp), %rdi
	testb	$1, 26(%rdi)
	movq	%rax, 40(%rsp)          ## 8-byte Spill
	je	LBB7_2
## %bb.1:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, 32(%rsp)          ## 8-byte Spill
	jmp	LBB7_3
LBB7_2:
	movq	296(%rsp), %rax
	movq	16(%rax), %rax
	movq	%rax, 32(%rsp)          ## 8-byte Spill
LBB7_3:
	movq	32(%rsp), %rax          ## 8-byte Reload
	movq	40(%rsp), %rcx          ## 8-byte Reload
	movq	%rax, (%rcx)
	movq	296(%rsp), %rax
	movq	%rax, 8(%rcx)
	movq	264(%rsp), %rax
	movq	272(%rsp), %rdx
	movq	%rax, 136(%rsp)
	movq	%rdx, 144(%rsp)
	movq	152(%rsp), %rax
	movq	%rax, 320(%rsp)
	movq	320(%rsp), %rdi
	callq	__ZN9benchmark5State16StartKeepRunningEv
	leaq	328(%rsp), %rax
	movq	%rax, 344(%rsp)
	movq	344(%rsp), %rax
	movq	%rax, 352(%rsp)
	movq	352(%rsp), %rax
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	328(%rsp), %rax
	movq	336(%rsp), %rcx
	movq	%rax, 120(%rsp)
	movq	%rcx, 128(%rsp)
LBB7_4:                                 ## =>This Inner Loop Header: Depth=1
	leaq	136(%rsp), %rax
	movq	%rax, 368(%rsp)
	leaq	120(%rsp), %rax
	movq	%rax, 360(%rsp)
	movq	368(%rsp), %rax
	cmpq	$0, (%rax)
	movq	%rax, 24(%rsp)          ## 8-byte Spill
	je	LBB7_6
## %bb.5:                               ##   in Loop: Header=BB7_4 Depth=1
	movb	$1, 383(%rsp)
	jmp	LBB7_7
LBB7_6:                                 ##   in Loop: Header=BB7_4 Depth=1
	movq	24(%rsp), %rax          ## 8-byte Reload
	movq	8(%rax), %rdi
	callq	__ZN9benchmark5State17FinishKeepRunningEv
	movb	$0, 383(%rsp)
LBB7_7:                                 ##   in Loop: Header=BB7_4 Depth=1
	testb	$1, 383(%rsp)
	jne	LBB7_8
	jmp	LBB7_12
LBB7_8:                                 ##   in Loop: Header=BB7_4 Depth=1
	leaq	136(%rsp), %rax
	movq	%rax, 384(%rsp)
	leaq	64(%rsp), %rdi
	leaq	192(%rsp), %rsi
	leaq	160(%rsp), %rdx
	callq	__ZN6spruceplERKNS_5vec3dES2_
	leaq	64(%rsp), %rax
	movq	%rax, 392(%rsp)
	movq	392(%rsp), %rax
	## InlineAsm Start
	## InlineAsm End
## %bb.9:                               ##   in Loop: Header=BB7_4 Depth=1
	leaq	136(%rsp), %rax
	movq	%rax, 312(%rsp)
	movq	312(%rsp), %rax
	cmpq	$0, (%rax)
	seta	%cl
	xorb	$-1, %cl
	testb	$1, %cl
	movq	%rax, 16(%rsp)          ## 8-byte Spill
	jne	LBB7_10
	jmp	LBB7_11
LBB7_10:
	leaq	L___func__._ZN9benchmark5State13StateIteratorppEv(%rip), %rdi
	leaq	L_.str.16(%rip), %rsi
	leaq	L_.str.17(%rip), %rcx
	movl	$697, %edx              ## imm = 0x2B9
	callq	___assert_rtn
LBB7_11:                                ##   in Loop: Header=BB7_4 Depth=1
	movq	16(%rsp), %rax          ## 8-byte Reload
	movq	(%rax), %rcx
	addq	$-1, %rcx
	movq	%rcx, (%rax)
	jmp	LBB7_4
LBB7_12:
	movq	%rbp, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90         ## -- Begin function __cxx_global_var_init.6
___cxx_global_var_init.6:               ## @__cxx_global_var_init.6
Lfunc_begin3:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception3
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$192, %eax
	movl	%eax, %edi
	callq	__Znwm
	movq	%rax, %rdi
	movq	%rax, %rcx
Ltmp9:
	leaq	L_.str.7(%rip), %rsi
	leaq	__ZL15vec3dScaleMultiRN9benchmark5StateE(%rip), %rdx
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rcx, -32(%rbp)         ## 8-byte Spill
	callq	__ZN9benchmark8internal17FunctionBenchmarkC1EPKcPFvRNS_5StateEE
Ltmp10:
	jmp	LBB8_1
LBB8_1:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__ZN9benchmark8internal25RegisterBenchmarkInternalEPNS0_9BenchmarkE
	movq	%rax, __ZL27_benchmark_5vec3dScaleMulti(%rip)
	addq	$32, %rsp
	popq	%rbp
	retq
LBB8_2:
Ltmp11:
	movl	%edx, %ecx
	movq	%rax, -8(%rbp)
	movl	%ecx, -12(%rbp)
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	callq	__ZdlPv
## %bb.3:
	movq	-8(%rbp), %rdi
	callq	__Unwind_Resume
	ud2
Lfunc_end3:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table8:
Lexception3:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	255                     ## @TType Encoding = omit
	.byte	1                       ## Call site Encoding = uleb128
	.uleb128 Lcst_end3-Lcst_begin3
Lcst_begin3:
	.uleb128 Lfunc_begin3-Lfunc_begin3 ## >> Call Site 1 <<
	.uleb128 Ltmp9-Lfunc_begin3     ##   Call between Lfunc_begin3 and Ltmp9
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp9-Lfunc_begin3     ## >> Call Site 2 <<
	.uleb128 Ltmp10-Ltmp9           ##   Call between Ltmp9 and Ltmp10
	.uleb128 Ltmp11-Lfunc_begin3    ##     jumps to Ltmp11
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp10-Lfunc_begin3    ## >> Call Site 3 <<
	.uleb128 Lfunc_end3-Ltmp10      ##   Call between Ltmp10 and Lfunc_end3
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lcst_end3:
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__literal16,16byte_literals
	.p2align	4               ## -- Begin function _ZL15vec3dScaleMultiRN9benchmark5StateE
LCPI9_0:
	.long	1127219200              ## 0x43300000
	.long	1160773632              ## 0x45300000
	.long	0                       ## 0x0
	.long	0                       ## 0x0
LCPI9_1:
	.quad	4841369599423283200     ## double 4503599627370496
	.quad	4985484787499139072     ## double 1.9342813113834067E+25
	.section	__TEXT,__text,regular,pure_instructions
	.p2align	4, 0x90
__ZL15vec3dScaleMultiRN9benchmark5StateE: ## @_ZL15vec3dScaleMultiRN9benchmark5StateE
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	andq	$-32, %rsp
	subq	$6400512, %rsp          ## imm = 0x61AA00
	leaq	480(%rsp), %rax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, 6400488(%rsp)
	movq	%rdi, 264(%rsp)
	movq	$100000, 256(%rsp)      ## imm = 0x186A0
	movq	%rax, %rcx
	addq	$6400000, %rcx          ## imm = 0x61A800
	movq	%rcx, 120(%rsp)         ## 8-byte Spill
	movq	%rax, 112(%rsp)         ## 8-byte Spill
LBB9_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	112(%rsp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	movq	%rax, 104(%rsp)         ## 8-byte Spill
	callq	__ZZL15vec3dScaleMultiRN9benchmark5StateEEN8TestDataC1Ev
	movq	104(%rsp), %rax         ## 8-byte Reload
	addq	$64, %rax
	movq	120(%rsp), %rdi         ## 8-byte Reload
	cmpq	%rdi, %rax
	movq	%rax, 112(%rsp)         ## 8-byte Spill
	jne	LBB9_1
## %bb.2:
	movq	$0, 248(%rsp)
LBB9_3:                                 ## =>This Inner Loop Header: Depth=1
	cmpq	$100000, 248(%rsp)      ## imm = 0x186A0
	jae	LBB9_6
## %bb.4:                               ##   in Loop: Header=BB9_3 Depth=1
	movq	248(%rsp), %rax
	movq	%rax, %rcx
	shlq	$6, %rcx
	leaq	480(%rsp,%rcx), %rdi
	vmovq	%rax, %xmm0
	vmovdqa	LCPI9_0(%rip), %xmm1    ## xmm1 = [1127219200,1160773632,0,0]
	vpunpckldq	%xmm1, %xmm0, %xmm0 ## xmm0 = xmm0[0],xmm1[0],xmm0[1],xmm1[1]
	vmovapd	LCPI9_1(%rip), %xmm1    ## xmm1 = [4.503600e+15,1.934281e+25]
	vsubpd	%xmm1, %xmm0, %xmm0
	vhaddpd	%xmm0, %xmm0, %xmm0
	vmovsd	%xmm0, 96(%rsp)         ## 8-byte Spill
	vmovsd	96(%rsp), %xmm1         ## 8-byte Reload
                                        ## xmm1 = mem[0],zero
	vmovsd	96(%rsp), %xmm2         ## 8-byte Reload
                                        ## xmm2 = mem[0],zero
	callq	__ZN6spruce5vec3d3setEddd
	movq	248(%rsp), %rcx
                                        ## implicit-def: $xmm0
	vcvtsi2ssq	%rcx, %xmm0, %xmm0
	movq	%rcx, %rdi
	shrq	%rdi
	movl	%ecx, %edx
	andl	$1, %edx
	movl	%edx, %esi
	orq	%rdi, %rsi
                                        ## implicit-def: $xmm1
	vcvtsi2ssq	%rsi, %xmm1, %xmm1
	vaddss	%xmm1, %xmm1, %xmm1
	testq	%rcx, %rcx
	movq	%rax, 88(%rsp)          ## 8-byte Spill
	vmovss	%xmm0, 84(%rsp)         ## 4-byte Spill
	vmovss	%xmm1, 80(%rsp)         ## 4-byte Spill
	js	LBB9_32
## %bb.31:                              ##   in Loop: Header=BB9_3 Depth=1
	vmovss	84(%rsp), %xmm0         ## 4-byte Reload
                                        ## xmm0 = mem[0],zero,zero,zero
	vmovss	%xmm0, 80(%rsp)         ## 4-byte Spill
LBB9_32:                                ##   in Loop: Header=BB9_3 Depth=1
	vmovss	80(%rsp), %xmm0         ## 4-byte Reload
                                        ## xmm0 = mem[0],zero,zero,zero
	movq	248(%rsp), %rax
	shlq	$6, %rax
	leaq	480(%rsp), %rcx
	addq	%rax, %rcx
	vmovss	%xmm0, 32(%rcx)
## %bb.5:                               ##   in Loop: Header=BB9_3 Depth=1
	movq	248(%rsp), %rax
	addq	$1, %rax
	movq	%rax, 248(%rsp)
	jmp	LBB9_3
LBB9_6:
	movq	264(%rsp), %rax
	movq	%rax, 240(%rsp)
	movq	240(%rsp), %rax
	movq	%rax, 272(%rsp)
	movq	272(%rsp), %rax
	leaq	280(%rsp), %rcx
	movq	%rcx, 304(%rsp)
	movq	%rax, 296(%rsp)
	movq	304(%rsp), %rax
	movq	296(%rsp), %rcx
	movq	%rax, 320(%rsp)
	movq	%rcx, 312(%rsp)
	movq	320(%rsp), %rax
	movq	312(%rsp), %rcx
	testb	$1, 26(%rcx)
	movq	%rax, 72(%rsp)          ## 8-byte Spill
	je	LBB9_8
## %bb.7:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, 64(%rsp)          ## 8-byte Spill
	jmp	LBB9_9
LBB9_8:
	movq	312(%rsp), %rax
	movq	16(%rax), %rax
	movq	%rax, 64(%rsp)          ## 8-byte Spill
LBB9_9:
	movq	64(%rsp), %rax          ## 8-byte Reload
	movq	72(%rsp), %rcx          ## 8-byte Reload
	movq	%rax, (%rcx)
	movq	312(%rsp), %rax
	movq	%rax, 8(%rcx)
	movq	280(%rsp), %rax
	movq	288(%rsp), %rdx
	movq	%rax, 224(%rsp)
	movq	%rdx, 232(%rsp)
	movq	240(%rsp), %rax
	movq	%rax, 400(%rsp)
	movq	400(%rsp), %rdi
	callq	__ZN9benchmark5State16StartKeepRunningEv
	leaq	408(%rsp), %rax
	movq	%rax, 424(%rsp)
	movq	424(%rsp), %rax
	movq	%rax, 432(%rsp)
	movq	432(%rsp), %rax
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	408(%rsp), %rax
	movq	416(%rsp), %rcx
	movq	%rax, 208(%rsp)
	movq	%rcx, 216(%rsp)
LBB9_10:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB9_15 Depth 2
	leaq	224(%rsp), %rax
	movq	%rax, 448(%rsp)
	leaq	208(%rsp), %rax
	movq	%rax, 440(%rsp)
	movq	448(%rsp), %rax
	cmpq	$0, (%rax)
	movq	%rax, 56(%rsp)          ## 8-byte Spill
	je	LBB9_12
## %bb.11:                              ##   in Loop: Header=BB9_10 Depth=1
	movb	$1, 463(%rsp)
	jmp	LBB9_13
LBB9_12:                                ##   in Loop: Header=BB9_10 Depth=1
	movq	56(%rsp), %rax          ## 8-byte Reload
	movq	8(%rax), %rdi
	callq	__ZN9benchmark5State17FinishKeepRunningEv
	movb	$0, 463(%rsp)
LBB9_13:                                ##   in Loop: Header=BB9_10 Depth=1
	testb	$1, 463(%rsp)
	jne	LBB9_14
	jmp	LBB9_22
LBB9_14:                                ##   in Loop: Header=BB9_10 Depth=1
	leaq	224(%rsp), %rax
	movq	%rax, 464(%rsp)
	movq	$0, 184(%rsp)
LBB9_15:                                ##   Parent Loop BB9_10 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$100000, 184(%rsp)      ## imm = 0x186A0
	jae	LBB9_18
## %bb.16:                              ##   in Loop: Header=BB9_15 Depth=2
	movq	184(%rsp), %rax
	shlq	$6, %rax
	leaq	480(%rsp), %rcx
	movq	%rcx, %rdx
	addq	%rax, %rdx
	movq	184(%rsp), %rax
	shlq	$6, %rax
	addq	%rax, %rcx
	vmovss	32(%rcx), %xmm0         ## xmm0 = mem[0],zero,zero,zero
                                        ## implicit-def: $xmm1
	vcvtss2sd	%xmm0, %xmm1, %xmm0
	leaq	128(%rsp), %rdi
	movq	%rdx, %rsi
	callq	__ZN6sprucemlERKNS_5vec3dEd
	leaq	128(%rsp), %rax
	movq	%rax, 472(%rsp)
	movq	472(%rsp), %rax
	## InlineAsm Start
	## InlineAsm End
## %bb.17:                              ##   in Loop: Header=BB9_15 Depth=2
	movq	184(%rsp), %rax
	addq	$1, %rax
	movq	%rax, 184(%rsp)
	jmp	LBB9_15
LBB9_18:                                ##   in Loop: Header=BB9_10 Depth=1
	jmp	LBB9_19
LBB9_19:                                ##   in Loop: Header=BB9_10 Depth=1
	leaq	224(%rsp), %rax
	movq	%rax, 392(%rsp)
	movq	392(%rsp), %rax
	cmpq	$0, (%rax)
	seta	%cl
	xorb	$-1, %cl
	testb	$1, %cl
	movq	%rax, 48(%rsp)          ## 8-byte Spill
	jne	LBB9_20
	jmp	LBB9_21
LBB9_20:
	leaq	L___func__._ZN9benchmark5State13StateIteratorppEv(%rip), %rdi
	leaq	L_.str.16(%rip), %rsi
	leaq	L_.str.17(%rip), %rcx
	movl	$697, %edx              ## imm = 0x2B9
	callq	___assert_rtn
LBB9_21:                                ##   in Loop: Header=BB9_10 Depth=1
	movq	48(%rsp), %rax          ## 8-byte Reload
	movq	(%rax), %rcx
	addq	$-1, %rcx
	movq	%rcx, (%rax)
	jmp	LBB9_10
LBB9_22:
	movq	264(%rsp), %rax
	movq	264(%rsp), %rcx
	movq	%rcx, 376(%rsp)
	movq	376(%rsp), %rcx
	movb	24(%rcx), %dl
	xorb	$-1, %dl
	testb	$1, %dl
	movq	%rax, 40(%rsp)          ## 8-byte Spill
	movq	%rcx, 32(%rsp)          ## 8-byte Spill
	jne	LBB9_23
	jmp	LBB9_24
LBB9_23:
	movq	$0, 384(%rsp)
	jmp	LBB9_25
LBB9_24:
	movq	32(%rsp), %rax          ## 8-byte Reload
	movq	16(%rax), %rcx
	subq	(%rax), %rcx
	addq	8(%rax), %rcx
	movq	%rcx, 384(%rsp)
LBB9_25:
	imulq	$6400000, 384(%rsp), %rax ## imm = 0x61A800
	movq	40(%rsp), %rcx          ## 8-byte Reload
	movq	%rcx, 368(%rsp)
	movq	%rax, 360(%rsp)
	movq	368(%rsp), %rax
	movq	360(%rsp), %rdx
	movq	%rdx, 56(%rax)
	movq	264(%rsp), %rax
	movq	264(%rsp), %rdx
	movq	%rdx, 344(%rsp)
	movq	344(%rsp), %rdx
	movb	24(%rdx), %sil
	xorb	$-1, %sil
	testb	$1, %sil
	movq	%rax, 24(%rsp)          ## 8-byte Spill
	movq	%rdx, 16(%rsp)          ## 8-byte Spill
	jne	LBB9_26
	jmp	LBB9_27
LBB9_26:
	movq	$0, 352(%rsp)
	jmp	LBB9_28
LBB9_27:
	movq	16(%rsp), %rax          ## 8-byte Reload
	movq	16(%rax), %rcx
	subq	(%rax), %rcx
	addq	8(%rax), %rcx
	movq	%rcx, 352(%rsp)
LBB9_28:
	imulq	$100000, 352(%rsp), %rax ## imm = 0x186A0
	movq	24(%rsp), %rcx          ## 8-byte Reload
	movq	%rcx, 336(%rsp)
	movq	%rax, 328(%rsp)
	movq	336(%rsp), %rax
	movq	328(%rsp), %rdx
	movq	%rdx, 64(%rax)
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	6400488(%rsp), %rdx
	cmpq	%rdx, %rax
	jne	LBB9_30
## %bb.29:
	movq	%rbp, %rsp
	popq	%rbp
	retq
LBB9_30:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90         ## -- Begin function __cxx_global_var_init.8
___cxx_global_var_init.8:               ## @__cxx_global_var_init.8
Lfunc_begin4:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception4
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$192, %eax
	movl	%eax, %edi
	callq	__Znwm
	movq	%rax, %rdi
	movq	%rax, %rcx
Ltmp12:
	leaq	L_.str.9(%rip), %rsi
	leaq	__ZL13vec3dAddMultiRN9benchmark5StateE(%rip), %rdx
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rcx, -32(%rbp)         ## 8-byte Spill
	callq	__ZN9benchmark8internal17FunctionBenchmarkC1EPKcPFvRNS_5StateEE
Ltmp13:
	jmp	LBB10_1
LBB10_1:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__ZN9benchmark8internal25RegisterBenchmarkInternalEPNS0_9BenchmarkE
	movq	%rax, __ZL25_benchmark_6vec3dAddMulti(%rip)
	addq	$32, %rsp
	popq	%rbp
	retq
LBB10_2:
Ltmp14:
	movl	%edx, %ecx
	movq	%rax, -8(%rbp)
	movl	%ecx, -12(%rbp)
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	callq	__ZdlPv
## %bb.3:
	movq	-8(%rbp), %rdi
	callq	__Unwind_Resume
	ud2
Lfunc_end4:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table10:
Lexception4:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	255                     ## @TType Encoding = omit
	.byte	1                       ## Call site Encoding = uleb128
	.uleb128 Lcst_end4-Lcst_begin4
Lcst_begin4:
	.uleb128 Lfunc_begin4-Lfunc_begin4 ## >> Call Site 1 <<
	.uleb128 Ltmp12-Lfunc_begin4    ##   Call between Lfunc_begin4 and Ltmp12
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp12-Lfunc_begin4    ## >> Call Site 2 <<
	.uleb128 Ltmp13-Ltmp12          ##   Call between Ltmp12 and Ltmp13
	.uleb128 Ltmp14-Lfunc_begin4    ##     jumps to Ltmp14
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp13-Lfunc_begin4    ## >> Call Site 3 <<
	.uleb128 Lfunc_end4-Ltmp13      ##   Call between Ltmp13 and Lfunc_end4
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lcst_end4:
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__literal16,16byte_literals
	.p2align	4               ## -- Begin function _ZL13vec3dAddMultiRN9benchmark5StateE
LCPI11_0:
	.long	1127219200              ## 0x43300000
	.long	1160773632              ## 0x45300000
	.long	0                       ## 0x0
	.long	0                       ## 0x0
LCPI11_1:
	.quad	4841369599423283200     ## double 4503599627370496
	.quad	4985484787499139072     ## double 1.9342813113834067E+25
	.section	__TEXT,__text,regular,pure_instructions
	.p2align	4, 0x90
__ZL13vec3dAddMultiRN9benchmark5StateE: ## @_ZL13vec3dAddMultiRN9benchmark5StateE
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	andq	$-32, %rsp
	subq	$6400576, %rsp          ## imm = 0x61AA40
	leaq	544(%rsp), %rax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, 6400552(%rsp)
	movq	%rdi, 328(%rsp)
	movq	$100000, 320(%rsp)      ## imm = 0x186A0
	movq	%rax, %rcx
	addq	$6400000, %rcx          ## imm = 0x61A800
	movq	%rcx, 152(%rsp)         ## 8-byte Spill
	movq	%rax, 144(%rsp)         ## 8-byte Spill
LBB11_1:                                ## =>This Inner Loop Header: Depth=1
	movq	144(%rsp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	movq	%rax, 136(%rsp)         ## 8-byte Spill
	callq	__ZZL13vec3dAddMultiRN9benchmark5StateEEN8TestDataC1Ev
	movq	136(%rsp), %rax         ## 8-byte Reload
	addq	$64, %rax
	movq	152(%rsp), %rdi         ## 8-byte Reload
	cmpq	%rdi, %rax
	movq	%rax, 144(%rsp)         ## 8-byte Spill
	jne	LBB11_1
## %bb.2:
	movq	$0, 312(%rsp)
LBB11_3:                                ## =>This Inner Loop Header: Depth=1
	cmpq	$100000, 312(%rsp)      ## imm = 0x186A0
	jae	LBB11_6
## %bb.4:                               ##   in Loop: Header=BB11_3 Depth=1
	movq	312(%rsp), %rax
	movq	%rax, %rcx
	shlq	$6, %rcx
	leaq	544(%rsp,%rcx), %rdi
	vmovq	%rax, %xmm0
	vmovdqa	LCPI11_0(%rip), %xmm1   ## xmm1 = [1127219200,1160773632,0,0]
	vpunpckldq	%xmm1, %xmm0, %xmm0 ## xmm0 = xmm0[0],xmm1[0],xmm0[1],xmm1[1]
	vmovapd	LCPI11_1(%rip), %xmm2   ## xmm2 = [4.503600e+15,1.934281e+25]
	vsubpd	%xmm2, %xmm0, %xmm0
	vhaddpd	%xmm0, %xmm0, %xmm0
	vmovsd	%xmm0, 128(%rsp)        ## 8-byte Spill
	vmovsd	128(%rsp), %xmm3        ## 8-byte Reload
                                        ## xmm3 = mem[0],zero
	vmovaps	%xmm1, 112(%rsp)        ## 16-byte Spill
	vmovaps	%xmm3, %xmm1
	vmovaps	%xmm2, 96(%rsp)         ## 16-byte Spill
	vmovaps	%xmm3, %xmm2
	callq	__ZN6spruce5vec3d3setEddd
	vmovq	312(%rsp), %xmm0        ## xmm0 = mem[0],zero
	vmovaps	112(%rsp), %xmm1        ## 16-byte Reload
	vpunpckldq	%xmm1, %xmm0, %xmm0 ## xmm0 = xmm0[0],xmm1[0],xmm0[1],xmm1[1]
	vmovaps	96(%rsp), %xmm2         ## 16-byte Reload
	vsubpd	%xmm2, %xmm0, %xmm0
	vhaddpd	%xmm0, %xmm0, %xmm0
	leaq	256(%rsp), %rdi
	movq	%rax, 88(%rsp)          ## 8-byte Spill
	callq	__ZN6spruce5vec3dC1Ed
	movq	312(%rsp), %rax
	shlq	$6, %rax
	leaq	544(%rsp), %rcx
	addq	%rax, %rcx
	movq	256(%rsp), %rax
	movq	%rax, 32(%rcx)
	movq	264(%rsp), %rax
	movq	%rax, 40(%rcx)
	movq	272(%rsp), %rax
	movq	%rax, 48(%rcx)
	movq	280(%rsp), %rax
	movq	%rax, 56(%rcx)
## %bb.5:                               ##   in Loop: Header=BB11_3 Depth=1
	movq	312(%rsp), %rax
	addq	$1, %rax
	movq	%rax, 312(%rsp)
	jmp	LBB11_3
LBB11_6:
	movq	328(%rsp), %rax
	movq	%rax, 248(%rsp)
	movq	248(%rsp), %rax
	movq	%rax, 336(%rsp)
	movq	336(%rsp), %rax
	leaq	344(%rsp), %rcx
	movq	%rcx, 368(%rsp)
	movq	%rax, 360(%rsp)
	movq	368(%rsp), %rax
	movq	360(%rsp), %rcx
	movq	%rax, 384(%rsp)
	movq	%rcx, 376(%rsp)
	movq	384(%rsp), %rax
	movq	376(%rsp), %rcx
	testb	$1, 26(%rcx)
	movq	%rax, 80(%rsp)          ## 8-byte Spill
	je	LBB11_8
## %bb.7:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, 72(%rsp)          ## 8-byte Spill
	jmp	LBB11_9
LBB11_8:
	movq	376(%rsp), %rax
	movq	16(%rax), %rax
	movq	%rax, 72(%rsp)          ## 8-byte Spill
LBB11_9:
	movq	72(%rsp), %rax          ## 8-byte Reload
	movq	80(%rsp), %rcx          ## 8-byte Reload
	movq	%rax, (%rcx)
	movq	376(%rsp), %rax
	movq	%rax, 8(%rcx)
	movq	344(%rsp), %rax
	movq	352(%rsp), %rdx
	movq	%rax, 232(%rsp)
	movq	%rdx, 240(%rsp)
	movq	248(%rsp), %rax
	movq	%rax, 464(%rsp)
	movq	464(%rsp), %rdi
	callq	__ZN9benchmark5State16StartKeepRunningEv
	leaq	472(%rsp), %rax
	movq	%rax, 488(%rsp)
	movq	488(%rsp), %rax
	movq	%rax, 496(%rsp)
	movq	496(%rsp), %rax
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	472(%rsp), %rax
	movq	480(%rsp), %rcx
	movq	%rax, 216(%rsp)
	movq	%rcx, 224(%rsp)
LBB11_10:                               ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB11_15 Depth 2
	leaq	232(%rsp), %rax
	movq	%rax, 512(%rsp)
	leaq	216(%rsp), %rax
	movq	%rax, 504(%rsp)
	movq	512(%rsp), %rax
	cmpq	$0, (%rax)
	movq	%rax, 64(%rsp)          ## 8-byte Spill
	je	LBB11_12
## %bb.11:                              ##   in Loop: Header=BB11_10 Depth=1
	movb	$1, 527(%rsp)
	jmp	LBB11_13
LBB11_12:                               ##   in Loop: Header=BB11_10 Depth=1
	movq	64(%rsp), %rax          ## 8-byte Reload
	movq	8(%rax), %rdi
	callq	__ZN9benchmark5State17FinishKeepRunningEv
	movb	$0, 527(%rsp)
LBB11_13:                               ##   in Loop: Header=BB11_10 Depth=1
	testb	$1, 527(%rsp)
	jne	LBB11_14
	jmp	LBB11_22
LBB11_14:                               ##   in Loop: Header=BB11_10 Depth=1
	leaq	232(%rsp), %rax
	movq	%rax, 528(%rsp)
	movq	$0, 192(%rsp)
LBB11_15:                               ##   Parent Loop BB11_10 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$100000, 192(%rsp)      ## imm = 0x186A0
	jae	LBB11_18
## %bb.16:                              ##   in Loop: Header=BB11_15 Depth=2
	movq	192(%rsp), %rax
	shlq	$6, %rax
	leaq	544(%rsp), %rcx
	movq	%rcx, %rdx
	addq	%rax, %rdx
	movq	192(%rsp), %rax
	shlq	$6, %rax
	addq	%rax, %rcx
	addq	$32, %rcx
	leaq	160(%rsp), %rdi
	movq	%rdx, %rsi
	movq	%rcx, %rdx
	callq	__ZN6spruceplERKNS_5vec3dES2_
	leaq	160(%rsp), %rax
	movq	%rax, 536(%rsp)
	movq	536(%rsp), %rax
	## InlineAsm Start
	## InlineAsm End
## %bb.17:                              ##   in Loop: Header=BB11_15 Depth=2
	movq	192(%rsp), %rax
	addq	$1, %rax
	movq	%rax, 192(%rsp)
	jmp	LBB11_15
LBB11_18:                               ##   in Loop: Header=BB11_10 Depth=1
	jmp	LBB11_19
LBB11_19:                               ##   in Loop: Header=BB11_10 Depth=1
	leaq	232(%rsp), %rax
	movq	%rax, 456(%rsp)
	movq	456(%rsp), %rax
	cmpq	$0, (%rax)
	seta	%cl
	xorb	$-1, %cl
	testb	$1, %cl
	movq	%rax, 56(%rsp)          ## 8-byte Spill
	jne	LBB11_20
	jmp	LBB11_21
LBB11_20:
	leaq	L___func__._ZN9benchmark5State13StateIteratorppEv(%rip), %rdi
	leaq	L_.str.16(%rip), %rsi
	leaq	L_.str.17(%rip), %rcx
	movl	$697, %edx              ## imm = 0x2B9
	callq	___assert_rtn
LBB11_21:                               ##   in Loop: Header=BB11_10 Depth=1
	movq	56(%rsp), %rax          ## 8-byte Reload
	movq	(%rax), %rcx
	addq	$-1, %rcx
	movq	%rcx, (%rax)
	jmp	LBB11_10
LBB11_22:
	movq	328(%rsp), %rax
	movq	328(%rsp), %rcx
	movq	%rcx, 440(%rsp)
	movq	440(%rsp), %rcx
	movb	24(%rcx), %dl
	xorb	$-1, %dl
	testb	$1, %dl
	movq	%rax, 48(%rsp)          ## 8-byte Spill
	movq	%rcx, 40(%rsp)          ## 8-byte Spill
	jne	LBB11_23
	jmp	LBB11_24
LBB11_23:
	movq	$0, 448(%rsp)
	jmp	LBB11_25
LBB11_24:
	movq	40(%rsp), %rax          ## 8-byte Reload
	movq	16(%rax), %rcx
	subq	(%rax), %rcx
	addq	8(%rax), %rcx
	movq	%rcx, 448(%rsp)
LBB11_25:
	imulq	$6400000, 448(%rsp), %rax ## imm = 0x61A800
	movq	48(%rsp), %rcx          ## 8-byte Reload
	movq	%rcx, 432(%rsp)
	movq	%rax, 424(%rsp)
	movq	432(%rsp), %rax
	movq	424(%rsp), %rdx
	movq	%rdx, 56(%rax)
	movq	328(%rsp), %rax
	movq	328(%rsp), %rdx
	movq	%rdx, 408(%rsp)
	movq	408(%rsp), %rdx
	movb	24(%rdx), %sil
	xorb	$-1, %sil
	testb	$1, %sil
	movq	%rax, 32(%rsp)          ## 8-byte Spill
	movq	%rdx, 24(%rsp)          ## 8-byte Spill
	jne	LBB11_26
	jmp	LBB11_27
LBB11_26:
	movq	$0, 416(%rsp)
	jmp	LBB11_28
LBB11_27:
	movq	24(%rsp), %rax          ## 8-byte Reload
	movq	16(%rax), %rcx
	subq	(%rax), %rcx
	addq	8(%rax), %rcx
	movq	%rcx, 416(%rsp)
LBB11_28:
	imulq	$100000, 416(%rsp), %rax ## imm = 0x186A0
	movq	32(%rsp), %rcx          ## 8-byte Reload
	movq	%rcx, 400(%rsp)
	movq	%rax, 392(%rsp)
	movq	400(%rsp), %rax
	movq	392(%rsp), %rdx
	movq	%rdx, 64(%rax)
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	6400552(%rsp), %rdx
	cmpq	%rdx, %rax
	jne	LBB11_30
## %bb.29:
	movq	%rbp, %rsp
	popq	%rbp
	retq
LBB11_30:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90         ## -- Begin function __cxx_global_var_init.10
___cxx_global_var_init.10:              ## @__cxx_global_var_init.10
Lfunc_begin5:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception5
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$192, %eax
	movl	%eax, %edi
	callq	__Znwm
	movq	%rax, %rdi
	movq	%rax, %rcx
Ltmp15:
	leaq	L_.str.11(%rip), %rsi
	leaq	__ZL13vec3dSubMultiRN9benchmark5StateE(%rip), %rdx
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rcx, -32(%rbp)         ## 8-byte Spill
	callq	__ZN9benchmark8internal17FunctionBenchmarkC1EPKcPFvRNS_5StateEE
Ltmp16:
	jmp	LBB12_1
LBB12_1:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__ZN9benchmark8internal25RegisterBenchmarkInternalEPNS0_9BenchmarkE
	movq	%rax, __ZL25_benchmark_7vec3dSubMulti(%rip)
	addq	$32, %rsp
	popq	%rbp
	retq
LBB12_2:
Ltmp17:
	movl	%edx, %ecx
	movq	%rax, -8(%rbp)
	movl	%ecx, -12(%rbp)
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	callq	__ZdlPv
## %bb.3:
	movq	-8(%rbp), %rdi
	callq	__Unwind_Resume
	ud2
Lfunc_end5:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table12:
Lexception5:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	255                     ## @TType Encoding = omit
	.byte	1                       ## Call site Encoding = uleb128
	.uleb128 Lcst_end5-Lcst_begin5
Lcst_begin5:
	.uleb128 Lfunc_begin5-Lfunc_begin5 ## >> Call Site 1 <<
	.uleb128 Ltmp15-Lfunc_begin5    ##   Call between Lfunc_begin5 and Ltmp15
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp15-Lfunc_begin5    ## >> Call Site 2 <<
	.uleb128 Ltmp16-Ltmp15          ##   Call between Ltmp15 and Ltmp16
	.uleb128 Ltmp17-Lfunc_begin5    ##     jumps to Ltmp17
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp16-Lfunc_begin5    ## >> Call Site 3 <<
	.uleb128 Lfunc_end5-Ltmp16      ##   Call between Ltmp16 and Lfunc_end5
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lcst_end5:
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__literal16,16byte_literals
	.p2align	4               ## -- Begin function _ZL13vec3dSubMultiRN9benchmark5StateE
LCPI13_0:
	.long	1127219200              ## 0x43300000
	.long	1160773632              ## 0x45300000
	.long	0                       ## 0x0
	.long	0                       ## 0x0
LCPI13_1:
	.quad	4841369599423283200     ## double 4503599627370496
	.quad	4985484787499139072     ## double 1.9342813113834067E+25
	.section	__TEXT,__text,regular,pure_instructions
	.p2align	4, 0x90
__ZL13vec3dSubMultiRN9benchmark5StateE: ## @_ZL13vec3dSubMultiRN9benchmark5StateE
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	andq	$-32, %rsp
	subq	$6400576, %rsp          ## imm = 0x61AA40
	leaq	544(%rsp), %rax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, 6400552(%rsp)
	movq	%rdi, 328(%rsp)
	movq	$100000, 320(%rsp)      ## imm = 0x186A0
	movq	%rax, %rcx
	addq	$6400000, %rcx          ## imm = 0x61A800
	movq	%rcx, 152(%rsp)         ## 8-byte Spill
	movq	%rax, 144(%rsp)         ## 8-byte Spill
LBB13_1:                                ## =>This Inner Loop Header: Depth=1
	movq	144(%rsp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	movq	%rax, 136(%rsp)         ## 8-byte Spill
	callq	__ZZL13vec3dSubMultiRN9benchmark5StateEEN8TestDataC1Ev
	movq	136(%rsp), %rax         ## 8-byte Reload
	addq	$64, %rax
	movq	152(%rsp), %rdi         ## 8-byte Reload
	cmpq	%rdi, %rax
	movq	%rax, 144(%rsp)         ## 8-byte Spill
	jne	LBB13_1
## %bb.2:
	movq	$0, 312(%rsp)
LBB13_3:                                ## =>This Inner Loop Header: Depth=1
	cmpq	$100000, 312(%rsp)      ## imm = 0x186A0
	jae	LBB13_6
## %bb.4:                               ##   in Loop: Header=BB13_3 Depth=1
	movq	312(%rsp), %rax
	movq	%rax, %rcx
	shlq	$6, %rcx
	leaq	544(%rsp,%rcx), %rdi
	vmovq	%rax, %xmm0
	vmovdqa	LCPI13_0(%rip), %xmm1   ## xmm1 = [1127219200,1160773632,0,0]
	vpunpckldq	%xmm1, %xmm0, %xmm0 ## xmm0 = xmm0[0],xmm1[0],xmm0[1],xmm1[1]
	vmovapd	LCPI13_1(%rip), %xmm2   ## xmm2 = [4.503600e+15,1.934281e+25]
	vsubpd	%xmm2, %xmm0, %xmm0
	vhaddpd	%xmm0, %xmm0, %xmm0
	vmovsd	%xmm0, 128(%rsp)        ## 8-byte Spill
	vmovsd	128(%rsp), %xmm3        ## 8-byte Reload
                                        ## xmm3 = mem[0],zero
	vmovaps	%xmm1, 112(%rsp)        ## 16-byte Spill
	vmovaps	%xmm3, %xmm1
	vmovaps	%xmm2, 96(%rsp)         ## 16-byte Spill
	vmovaps	%xmm3, %xmm2
	callq	__ZN6spruce5vec3d3setEddd
	vmovq	312(%rsp), %xmm0        ## xmm0 = mem[0],zero
	vmovaps	112(%rsp), %xmm1        ## 16-byte Reload
	vpunpckldq	%xmm1, %xmm0, %xmm0 ## xmm0 = xmm0[0],xmm1[0],xmm0[1],xmm1[1]
	vmovaps	96(%rsp), %xmm2         ## 16-byte Reload
	vsubpd	%xmm2, %xmm0, %xmm0
	vhaddpd	%xmm0, %xmm0, %xmm0
	leaq	256(%rsp), %rdi
	movq	%rax, 88(%rsp)          ## 8-byte Spill
	callq	__ZN6spruce5vec3dC1Ed
	movq	312(%rsp), %rax
	shlq	$6, %rax
	leaq	544(%rsp), %rcx
	addq	%rax, %rcx
	movq	256(%rsp), %rax
	movq	%rax, 32(%rcx)
	movq	264(%rsp), %rax
	movq	%rax, 40(%rcx)
	movq	272(%rsp), %rax
	movq	%rax, 48(%rcx)
	movq	280(%rsp), %rax
	movq	%rax, 56(%rcx)
## %bb.5:                               ##   in Loop: Header=BB13_3 Depth=1
	movq	312(%rsp), %rax
	addq	$1, %rax
	movq	%rax, 312(%rsp)
	jmp	LBB13_3
LBB13_6:
	movq	328(%rsp), %rax
	movq	%rax, 248(%rsp)
	movq	248(%rsp), %rax
	movq	%rax, 336(%rsp)
	movq	336(%rsp), %rax
	leaq	344(%rsp), %rcx
	movq	%rcx, 368(%rsp)
	movq	%rax, 360(%rsp)
	movq	368(%rsp), %rax
	movq	360(%rsp), %rcx
	movq	%rax, 384(%rsp)
	movq	%rcx, 376(%rsp)
	movq	384(%rsp), %rax
	movq	376(%rsp), %rcx
	testb	$1, 26(%rcx)
	movq	%rax, 80(%rsp)          ## 8-byte Spill
	je	LBB13_8
## %bb.7:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, 72(%rsp)          ## 8-byte Spill
	jmp	LBB13_9
LBB13_8:
	movq	376(%rsp), %rax
	movq	16(%rax), %rax
	movq	%rax, 72(%rsp)          ## 8-byte Spill
LBB13_9:
	movq	72(%rsp), %rax          ## 8-byte Reload
	movq	80(%rsp), %rcx          ## 8-byte Reload
	movq	%rax, (%rcx)
	movq	376(%rsp), %rax
	movq	%rax, 8(%rcx)
	movq	344(%rsp), %rax
	movq	352(%rsp), %rdx
	movq	%rax, 232(%rsp)
	movq	%rdx, 240(%rsp)
	movq	248(%rsp), %rax
	movq	%rax, 464(%rsp)
	movq	464(%rsp), %rdi
	callq	__ZN9benchmark5State16StartKeepRunningEv
	leaq	472(%rsp), %rax
	movq	%rax, 488(%rsp)
	movq	488(%rsp), %rax
	movq	%rax, 496(%rsp)
	movq	496(%rsp), %rax
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	472(%rsp), %rax
	movq	480(%rsp), %rcx
	movq	%rax, 216(%rsp)
	movq	%rcx, 224(%rsp)
LBB13_10:                               ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB13_15 Depth 2
	leaq	232(%rsp), %rax
	movq	%rax, 512(%rsp)
	leaq	216(%rsp), %rax
	movq	%rax, 504(%rsp)
	movq	512(%rsp), %rax
	cmpq	$0, (%rax)
	movq	%rax, 64(%rsp)          ## 8-byte Spill
	je	LBB13_12
## %bb.11:                              ##   in Loop: Header=BB13_10 Depth=1
	movb	$1, 527(%rsp)
	jmp	LBB13_13
LBB13_12:                               ##   in Loop: Header=BB13_10 Depth=1
	movq	64(%rsp), %rax          ## 8-byte Reload
	movq	8(%rax), %rdi
	callq	__ZN9benchmark5State17FinishKeepRunningEv
	movb	$0, 527(%rsp)
LBB13_13:                               ##   in Loop: Header=BB13_10 Depth=1
	testb	$1, 527(%rsp)
	jne	LBB13_14
	jmp	LBB13_22
LBB13_14:                               ##   in Loop: Header=BB13_10 Depth=1
	leaq	232(%rsp), %rax
	movq	%rax, 528(%rsp)
	movq	$0, 192(%rsp)
LBB13_15:                               ##   Parent Loop BB13_10 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$100000, 192(%rsp)      ## imm = 0x186A0
	jae	LBB13_18
## %bb.16:                              ##   in Loop: Header=BB13_15 Depth=2
	movq	192(%rsp), %rax
	shlq	$6, %rax
	leaq	544(%rsp), %rcx
	movq	%rcx, %rdx
	addq	%rax, %rdx
	movq	192(%rsp), %rax
	shlq	$6, %rax
	addq	%rax, %rcx
	addq	$32, %rcx
	leaq	160(%rsp), %rdi
	movq	%rdx, %rsi
	movq	%rcx, %rdx
	callq	__ZN6sprucemiERKNS_5vec3dES2_
	leaq	160(%rsp), %rax
	movq	%rax, 536(%rsp)
	movq	536(%rsp), %rax
	## InlineAsm Start
	## InlineAsm End
## %bb.17:                              ##   in Loop: Header=BB13_15 Depth=2
	movq	192(%rsp), %rax
	addq	$1, %rax
	movq	%rax, 192(%rsp)
	jmp	LBB13_15
LBB13_18:                               ##   in Loop: Header=BB13_10 Depth=1
	jmp	LBB13_19
LBB13_19:                               ##   in Loop: Header=BB13_10 Depth=1
	leaq	232(%rsp), %rax
	movq	%rax, 456(%rsp)
	movq	456(%rsp), %rax
	cmpq	$0, (%rax)
	seta	%cl
	xorb	$-1, %cl
	testb	$1, %cl
	movq	%rax, 56(%rsp)          ## 8-byte Spill
	jne	LBB13_20
	jmp	LBB13_21
LBB13_20:
	leaq	L___func__._ZN9benchmark5State13StateIteratorppEv(%rip), %rdi
	leaq	L_.str.16(%rip), %rsi
	leaq	L_.str.17(%rip), %rcx
	movl	$697, %edx              ## imm = 0x2B9
	callq	___assert_rtn
LBB13_21:                               ##   in Loop: Header=BB13_10 Depth=1
	movq	56(%rsp), %rax          ## 8-byte Reload
	movq	(%rax), %rcx
	addq	$-1, %rcx
	movq	%rcx, (%rax)
	jmp	LBB13_10
LBB13_22:
	movq	328(%rsp), %rax
	movq	328(%rsp), %rcx
	movq	%rcx, 440(%rsp)
	movq	440(%rsp), %rcx
	movb	24(%rcx), %dl
	xorb	$-1, %dl
	testb	$1, %dl
	movq	%rax, 48(%rsp)          ## 8-byte Spill
	movq	%rcx, 40(%rsp)          ## 8-byte Spill
	jne	LBB13_23
	jmp	LBB13_24
LBB13_23:
	movq	$0, 448(%rsp)
	jmp	LBB13_25
LBB13_24:
	movq	40(%rsp), %rax          ## 8-byte Reload
	movq	16(%rax), %rcx
	subq	(%rax), %rcx
	addq	8(%rax), %rcx
	movq	%rcx, 448(%rsp)
LBB13_25:
	imulq	$6400000, 448(%rsp), %rax ## imm = 0x61A800
	movq	48(%rsp), %rcx          ## 8-byte Reload
	movq	%rcx, 432(%rsp)
	movq	%rax, 424(%rsp)
	movq	432(%rsp), %rax
	movq	424(%rsp), %rdx
	movq	%rdx, 56(%rax)
	movq	328(%rsp), %rax
	movq	328(%rsp), %rdx
	movq	%rdx, 408(%rsp)
	movq	408(%rsp), %rdx
	movb	24(%rdx), %sil
	xorb	$-1, %sil
	testb	$1, %sil
	movq	%rax, 32(%rsp)          ## 8-byte Spill
	movq	%rdx, 24(%rsp)          ## 8-byte Spill
	jne	LBB13_26
	jmp	LBB13_27
LBB13_26:
	movq	$0, 416(%rsp)
	jmp	LBB13_28
LBB13_27:
	movq	24(%rsp), %rax          ## 8-byte Reload
	movq	16(%rax), %rcx
	subq	(%rax), %rcx
	addq	8(%rax), %rcx
	movq	%rcx, 416(%rsp)
LBB13_28:
	imulq	$100000, 416(%rsp), %rax ## imm = 0x186A0
	movq	32(%rsp), %rcx          ## 8-byte Reload
	movq	%rcx, 400(%rsp)
	movq	%rax, 392(%rsp)
	movq	400(%rsp), %rax
	movq	392(%rsp), %rdx
	movq	%rdx, 64(%rax)
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	6400552(%rsp), %rdx
	cmpq	%rdx, %rax
	jne	LBB13_30
## %bb.29:
	movq	%rbp, %rsp
	popq	%rbp
	retq
LBB13_30:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90         ## -- Begin function __cxx_global_var_init.12
___cxx_global_var_init.12:              ## @__cxx_global_var_init.12
Lfunc_begin6:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception6
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$192, %eax
	movl	%eax, %edi
	callq	__Znwm
	movq	%rax, %rdi
	movq	%rax, %rcx
Ltmp18:
	leaq	L_.str.13(%rip), %rsi
	leaq	__ZL8vec3dCrsRN9benchmark5StateE(%rip), %rdx
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rcx, -32(%rbp)         ## 8-byte Spill
	callq	__ZN9benchmark8internal17FunctionBenchmarkC1EPKcPFvRNS_5StateEE
Ltmp19:
	jmp	LBB14_1
LBB14_1:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__ZN9benchmark8internal25RegisterBenchmarkInternalEPNS0_9BenchmarkE
	movq	%rax, __ZL20_benchmark_8vec3dCrs(%rip)
	addq	$32, %rsp
	popq	%rbp
	retq
LBB14_2:
Ltmp20:
	movl	%edx, %ecx
	movq	%rax, -8(%rbp)
	movl	%ecx, -12(%rbp)
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	callq	__ZdlPv
## %bb.3:
	movq	-8(%rbp), %rdi
	callq	__Unwind_Resume
	ud2
Lfunc_end6:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table14:
Lexception6:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	255                     ## @TType Encoding = omit
	.byte	1                       ## Call site Encoding = uleb128
	.uleb128 Lcst_end6-Lcst_begin6
Lcst_begin6:
	.uleb128 Lfunc_begin6-Lfunc_begin6 ## >> Call Site 1 <<
	.uleb128 Ltmp18-Lfunc_begin6    ##   Call between Lfunc_begin6 and Ltmp18
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp18-Lfunc_begin6    ## >> Call Site 2 <<
	.uleb128 Ltmp19-Ltmp18          ##   Call between Ltmp18 and Ltmp19
	.uleb128 Ltmp20-Lfunc_begin6    ##     jumps to Ltmp20
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp19-Lfunc_begin6    ## >> Call Site 3 <<
	.uleb128 Lfunc_end6-Ltmp19      ##   Call between Ltmp19 and Lfunc_end6
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lcst_end6:
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function _ZL8vec3dCrsRN9benchmark5StateE
LCPI15_0:
	.quad	4607182418800017408     ## double 1
	.section	__TEXT,__text,regular,pure_instructions
	.p2align	4, 0x90
__ZL8vec3dCrsRN9benchmark5StateE:       ## @_ZL8vec3dCrsRN9benchmark5StateE
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	andq	$-32, %rsp
	subq	$384, %rsp              ## imm = 0x180
	movq	%rdi, 224(%rsp)
	movq	224(%rsp), %rdi
	movq	%rdi, 216(%rsp)
	movq	216(%rsp), %rdi
	movq	%rdi, 232(%rsp)
	movq	232(%rsp), %rdi
	leaq	240(%rsp), %rax
	movq	%rax, 264(%rsp)
	movq	%rdi, 256(%rsp)
	movq	264(%rsp), %rax
	movq	256(%rsp), %rdi
	movq	%rax, 280(%rsp)
	movq	%rdi, 272(%rsp)
	movq	280(%rsp), %rax
	movq	272(%rsp), %rdi
	testb	$1, 26(%rdi)
	movq	%rax, 56(%rsp)          ## 8-byte Spill
	je	LBB15_2
## %bb.1:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, 48(%rsp)          ## 8-byte Spill
	jmp	LBB15_3
LBB15_2:
	movq	272(%rsp), %rax
	movq	16(%rax), %rax
	movq	%rax, 48(%rsp)          ## 8-byte Spill
LBB15_3:
	movq	48(%rsp), %rax          ## 8-byte Reload
	movq	56(%rsp), %rcx          ## 8-byte Reload
	movq	%rax, (%rcx)
	movq	272(%rsp), %rax
	movq	%rax, 8(%rcx)
	movq	240(%rsp), %rax
	movq	248(%rsp), %rdx
	movq	%rax, 200(%rsp)
	movq	%rdx, 208(%rsp)
	movq	216(%rsp), %rax
	movq	%rax, 296(%rsp)
	movq	296(%rsp), %rdi
	callq	__ZN9benchmark5State16StartKeepRunningEv
	leaq	304(%rsp), %rax
	movq	%rax, 320(%rsp)
	movq	320(%rsp), %rax
	movq	%rax, 328(%rsp)
	movq	328(%rsp), %rax
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	304(%rsp), %rax
	movq	312(%rsp), %rcx
	movq	%rax, 184(%rsp)
	movq	%rcx, 192(%rsp)
LBB15_4:                                ## =>This Inner Loop Header: Depth=1
	leaq	200(%rsp), %rax
	movq	%rax, 344(%rsp)
	leaq	184(%rsp), %rax
	movq	%rax, 336(%rsp)
	movq	344(%rsp), %rax
	cmpq	$0, (%rax)
	movq	%rax, 40(%rsp)          ## 8-byte Spill
	je	LBB15_6
## %bb.5:                               ##   in Loop: Header=BB15_4 Depth=1
	movb	$1, 359(%rsp)
	jmp	LBB15_7
LBB15_6:                                ##   in Loop: Header=BB15_4 Depth=1
	movq	40(%rsp), %rax          ## 8-byte Reload
	movq	8(%rax), %rdi
	callq	__ZN9benchmark5State17FinishKeepRunningEv
	movb	$0, 359(%rsp)
LBB15_7:                                ##   in Loop: Header=BB15_4 Depth=1
	testb	$1, 359(%rsp)
	jne	LBB15_8
	jmp	LBB15_12
LBB15_8:                                ##   in Loop: Header=BB15_4 Depth=1
	vmovsd	LCPI15_0(%rip), %xmm0   ## xmm0 = mem[0],zero
	leaq	200(%rsp), %rax
	movq	%rax, 360(%rsp)
	leaq	128(%rsp), %rdi
	vxorps	%xmm1, %xmm1, %xmm1
	vmovsd	%xmm1, 32(%rsp)         ## 8-byte Spill
	vmovsd	32(%rsp), %xmm2         ## 8-byte Reload
                                        ## xmm2 = mem[0],zero
	callq	__ZN6spruce5vec3dC1Eddd
	vmovsd	LCPI15_0(%rip), %xmm1   ## xmm1 = mem[0],zero
	leaq	64(%rsp), %rdi
	vxorps	%xmm0, %xmm0, %xmm0
	vmovsd	%xmm0, 24(%rsp)         ## 8-byte Spill
	vmovsd	24(%rsp), %xmm2         ## 8-byte Reload
                                        ## xmm2 = mem[0],zero
	callq	__ZN6spruce5vec3dC1Eddd
	leaq	128(%rsp), %rdi
	leaq	64(%rsp), %rsi
	callq	__ZN6spruce5vec3d3crsERKS0_
	movq	(%rax), %rsi
	movq	%rsi, 96(%rsp)
	movq	8(%rax), %rsi
	movq	%rsi, 104(%rsp)
	movq	16(%rax), %rsi
	movq	%rsi, 112(%rsp)
	movq	24(%rax), %rax
	movq	%rax, 120(%rsp)
## %bb.9:                               ##   in Loop: Header=BB15_4 Depth=1
	leaq	200(%rsp), %rax
	movq	%rax, 288(%rsp)
	movq	288(%rsp), %rax
	cmpq	$0, (%rax)
	seta	%cl
	xorb	$-1, %cl
	testb	$1, %cl
	movq	%rax, 16(%rsp)          ## 8-byte Spill
	jne	LBB15_10
	jmp	LBB15_11
LBB15_10:
	leaq	L___func__._ZN9benchmark5State13StateIteratorppEv(%rip), %rdi
	leaq	L_.str.16(%rip), %rsi
	leaq	L_.str.17(%rip), %rcx
	movl	$697, %edx              ## imm = 0x2B9
	callq	___assert_rtn
LBB15_11:                               ##   in Loop: Header=BB15_4 Depth=1
	movq	16(%rsp), %rax          ## 8-byte Reload
	movq	(%rax), %rcx
	addq	$-1, %rcx
	movq	%rcx, (%rax)
	jmp	LBB15_4
LBB15_12:
	movq	%rbp, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90         ## -- Begin function __cxx_global_var_init.14
___cxx_global_var_init.14:              ## @__cxx_global_var_init.14
Lfunc_begin7:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception7
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$192, %eax
	movl	%eax, %edi
	callq	__Znwm
	movq	%rax, %rdi
	movq	%rax, %rcx
Ltmp21:
	leaq	L_.str.15(%rip), %rsi
	leaq	__ZL17vec3dAddMultiSIMDRN9benchmark5StateE(%rip), %rdx
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rcx, -32(%rbp)         ## 8-byte Spill
	callq	__ZN9benchmark8internal17FunctionBenchmarkC1EPKcPFvRNS_5StateEE
Ltmp22:
	jmp	LBB16_1
LBB16_1:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__ZN9benchmark8internal25RegisterBenchmarkInternalEPNS0_9BenchmarkE
	movq	%rax, __ZL29_benchmark_9vec3dAddMultiSIMD(%rip)
	addq	$32, %rsp
	popq	%rbp
	retq
LBB16_2:
Ltmp23:
	movl	%edx, %ecx
	movq	%rax, -8(%rbp)
	movl	%ecx, -12(%rbp)
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	callq	__ZdlPv
## %bb.3:
	movq	-8(%rbp), %rdi
	callq	__Unwind_Resume
	ud2
Lfunc_end7:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table16:
Lexception7:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	255                     ## @TType Encoding = omit
	.byte	1                       ## Call site Encoding = uleb128
	.uleb128 Lcst_end7-Lcst_begin7
Lcst_begin7:
	.uleb128 Lfunc_begin7-Lfunc_begin7 ## >> Call Site 1 <<
	.uleb128 Ltmp21-Lfunc_begin7    ##   Call between Lfunc_begin7 and Ltmp21
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp21-Lfunc_begin7    ## >> Call Site 2 <<
	.uleb128 Ltmp22-Ltmp21          ##   Call between Ltmp21 and Ltmp22
	.uleb128 Ltmp23-Lfunc_begin7    ##     jumps to Ltmp23
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp22-Lfunc_begin7    ## >> Call Site 3 <<
	.uleb128 Lfunc_end7-Ltmp22      ##   Call between Ltmp22 and Lfunc_end7
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lcst_end7:
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.p2align	4, 0x90         ## -- Begin function _ZL17vec3dAddMultiSIMDRN9benchmark5StateE
__ZL17vec3dAddMultiSIMDRN9benchmark5StateE: ## @_ZL17vec3dAddMultiSIMDRN9benchmark5StateE
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	andq	$-32, %rsp
	subq	$6400448, %rsp          ## imm = 0x61A9C0
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, 6400424(%rsp)
	movq	%rdi, 208(%rsp)
	movq	$100000, 200(%rsp)      ## imm = 0x186A0
	movq	$0, 192(%rsp)
LBB17_1:                                ## =>This Inner Loop Header: Depth=1
	cmpq	$100000, 192(%rsp)      ## imm = 0x186A0
	jae	LBB17_4
## %bb.2:                               ##   in Loop: Header=BB17_1 Depth=1
	movq	192(%rsp), %rax
                                        ## implicit-def: $xmm0
	vcvtsi2ssq	%rax, %xmm0, %xmm0
	movq	%rax, %rcx
	shrq	%rcx
	movl	%eax, %edx
	andl	$1, %edx
	movl	%edx, %esi
	orq	%rcx, %rsi
                                        ## implicit-def: $xmm1
	vcvtsi2ssq	%rsi, %xmm1, %xmm1
	vaddss	%xmm1, %xmm1, %xmm1
	testq	%rax, %rax
	movq	%rax, 88(%rsp)          ## 8-byte Spill
	vmovss	%xmm0, 84(%rsp)         ## 4-byte Spill
	vmovss	%xmm1, 80(%rsp)         ## 4-byte Spill
	js	LBB17_30
## %bb.29:                              ##   in Loop: Header=BB17_1 Depth=1
	vmovss	84(%rsp), %xmm0         ## 4-byte Reload
                                        ## xmm0 = mem[0],zero,zero,zero
	vmovss	%xmm0, 80(%rsp)         ## 4-byte Spill
LBB17_30:                               ##   in Loop: Header=BB17_1 Depth=1
	vmovss	80(%rsp), %xmm0         ## 4-byte Reload
                                        ## xmm0 = mem[0],zero,zero,zero
                                        ## implicit-def: $xmm1
	vcvtss2sd	%xmm0, %xmm1, %xmm0
	movq	88(%rsp), %rax          ## 8-byte Reload
	shlq	$6, %rax
	vbroadcastsd	%xmm0, %ymm2
	vmovapd	%ymm2, 416(%rsp,%rax)
	movq	192(%rsp), %rax
                                        ## implicit-def: $xmm0
	vcvtsi2ssq	%rax, %xmm0, %xmm0
	movq	%rax, %rcx
	shrq	%rcx
	movl	%eax, %edx
	andl	$1, %edx
	movl	%edx, %esi
	orq	%rcx, %rsi
                                        ## implicit-def: $xmm1
	vcvtsi2ssq	%rsi, %xmm1, %xmm1
	vaddss	%xmm1, %xmm1, %xmm1
	testq	%rax, %rax
	movq	%rax, 72(%rsp)          ## 8-byte Spill
	vmovss	%xmm0, 68(%rsp)         ## 4-byte Spill
	vmovss	%xmm1, 64(%rsp)         ## 4-byte Spill
	js	LBB17_32
## %bb.31:                              ##   in Loop: Header=BB17_1 Depth=1
	vmovss	68(%rsp), %xmm0         ## 4-byte Reload
                                        ## xmm0 = mem[0],zero,zero,zero
	vmovss	%xmm0, 64(%rsp)         ## 4-byte Spill
LBB17_32:                               ##   in Loop: Header=BB17_1 Depth=1
	vmovss	64(%rsp), %xmm0         ## 4-byte Reload
                                        ## xmm0 = mem[0],zero,zero,zero
                                        ## implicit-def: $xmm1
	vcvtss2sd	%xmm0, %xmm1, %xmm0
	movq	72(%rsp), %rax          ## 8-byte Reload
	shlq	$6, %rax
	leaq	416(%rsp,%rax), %rax
	vbroadcastsd	%xmm0, %ymm2
	vmovapd	%ymm2, 32(%rax)
## %bb.3:                               ##   in Loop: Header=BB17_1 Depth=1
	movq	192(%rsp), %rax
	addq	$1, %rax
	movq	%rax, 192(%rsp)
	jmp	LBB17_1
LBB17_4:
	movq	208(%rsp), %rax
	movq	%rax, 184(%rsp)
	movq	184(%rsp), %rax
	movq	%rax, 216(%rsp)
	movq	216(%rsp), %rax
	leaq	224(%rsp), %rcx
	movq	%rcx, 248(%rsp)
	movq	%rax, 240(%rsp)
	movq	248(%rsp), %rax
	movq	240(%rsp), %rcx
	movq	%rax, 264(%rsp)
	movq	%rcx, 256(%rsp)
	movq	264(%rsp), %rax
	movq	256(%rsp), %rcx
	testb	$1, 26(%rcx)
	movq	%rax, 56(%rsp)          ## 8-byte Spill
	je	LBB17_6
## %bb.5:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, 48(%rsp)          ## 8-byte Spill
	jmp	LBB17_7
LBB17_6:
	movq	256(%rsp), %rax
	movq	16(%rax), %rax
	movq	%rax, 48(%rsp)          ## 8-byte Spill
LBB17_7:
	movq	48(%rsp), %rax          ## 8-byte Reload
	movq	56(%rsp), %rcx          ## 8-byte Reload
	movq	%rax, (%rcx)
	movq	256(%rsp), %rax
	movq	%rax, 8(%rcx)
	movq	224(%rsp), %rax
	movq	232(%rsp), %rdx
	movq	%rax, 168(%rsp)
	movq	%rdx, 176(%rsp)
	movq	184(%rsp), %rax
	movq	%rax, 344(%rsp)
	movq	344(%rsp), %rdi
	vzeroupper
	callq	__ZN9benchmark5State16StartKeepRunningEv
	leaq	352(%rsp), %rax
	movq	%rax, 368(%rsp)
	movq	368(%rsp), %rax
	movq	%rax, 376(%rsp)
	movq	376(%rsp), %rax
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	352(%rsp), %rax
	movq	360(%rsp), %rcx
	movq	%rax, 152(%rsp)
	movq	%rcx, 160(%rsp)
LBB17_8:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB17_13 Depth 2
	leaq	168(%rsp), %rax
	movq	%rax, 392(%rsp)
	leaq	152(%rsp), %rax
	movq	%rax, 384(%rsp)
	movq	392(%rsp), %rax
	cmpq	$0, (%rax)
	movq	%rax, 40(%rsp)          ## 8-byte Spill
	je	LBB17_10
## %bb.9:                               ##   in Loop: Header=BB17_8 Depth=1
	movb	$1, 407(%rsp)
	jmp	LBB17_11
LBB17_10:                               ##   in Loop: Header=BB17_8 Depth=1
	movq	40(%rsp), %rax          ## 8-byte Reload
	movq	8(%rax), %rdi
	vzeroupper
	callq	__ZN9benchmark5State17FinishKeepRunningEv
	movb	$0, 407(%rsp)
LBB17_11:                               ##   in Loop: Header=BB17_8 Depth=1
	testb	$1, 407(%rsp)
	jne	LBB17_12
	jmp	LBB17_20
LBB17_12:                               ##   in Loop: Header=BB17_8 Depth=1
	leaq	168(%rsp), %rax
	movq	%rax, 408(%rsp)
	movq	$0, 128(%rsp)
LBB17_13:                               ##   Parent Loop BB17_8 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$100000, 128(%rsp)      ## imm = 0x186A0
	jae	LBB17_16
## %bb.14:                              ##   in Loop: Header=BB17_13 Depth=2
	movq	128(%rsp), %rax
	shlq	$6, %rax
	vmovapd	416(%rsp,%rax), %ymm0
	vmovapd	448(%rsp,%rax), %ymm1
	vaddpd	%ymm1, %ymm0, %ymm0
	vmovapd	%ymm0, 96(%rsp)
## %bb.15:                              ##   in Loop: Header=BB17_13 Depth=2
	movq	128(%rsp), %rax
	addq	$1, %rax
	movq	%rax, 128(%rsp)
	jmp	LBB17_13
LBB17_16:                               ##   in Loop: Header=BB17_8 Depth=1
	jmp	LBB17_17
LBB17_17:                               ##   in Loop: Header=BB17_8 Depth=1
	leaq	168(%rsp), %rax
	movq	%rax, 336(%rsp)
	movq	336(%rsp), %rax
	cmpq	$0, (%rax)
	seta	%cl
	xorb	$-1, %cl
	testb	$1, %cl
	movq	%rax, 32(%rsp)          ## 8-byte Spill
	jne	LBB17_18
	jmp	LBB17_19
LBB17_18:
	leaq	L___func__._ZN9benchmark5State13StateIteratorppEv(%rip), %rdi
	leaq	L_.str.16(%rip), %rsi
	leaq	L_.str.17(%rip), %rcx
	movl	$697, %edx              ## imm = 0x2B9
	vzeroupper
	callq	___assert_rtn
LBB17_19:                               ##   in Loop: Header=BB17_8 Depth=1
	movq	32(%rsp), %rax          ## 8-byte Reload
	movq	(%rax), %rcx
	addq	$-1, %rcx
	movq	%rcx, (%rax)
	jmp	LBB17_8
LBB17_20:
	movq	208(%rsp), %rax
	movq	208(%rsp), %rcx
	movq	%rcx, 320(%rsp)
	movq	320(%rsp), %rcx
	movb	24(%rcx), %dl
	xorb	$-1, %dl
	testb	$1, %dl
	movq	%rax, 24(%rsp)          ## 8-byte Spill
	movq	%rcx, 16(%rsp)          ## 8-byte Spill
	jne	LBB17_21
	jmp	LBB17_22
LBB17_21:
	movq	$0, 328(%rsp)
	jmp	LBB17_23
LBB17_22:
	movq	16(%rsp), %rax          ## 8-byte Reload
	movq	16(%rax), %rcx
	subq	(%rax), %rcx
	addq	8(%rax), %rcx
	movq	%rcx, 328(%rsp)
LBB17_23:
	imulq	$6400000, 328(%rsp), %rax ## imm = 0x61A800
	movq	24(%rsp), %rcx          ## 8-byte Reload
	movq	%rcx, 312(%rsp)
	movq	%rax, 304(%rsp)
	movq	312(%rsp), %rax
	movq	304(%rsp), %rdx
	movq	%rdx, 56(%rax)
	movq	208(%rsp), %rax
	movq	208(%rsp), %rdx
	movq	%rdx, 288(%rsp)
	movq	288(%rsp), %rdx
	movb	24(%rdx), %sil
	xorb	$-1, %sil
	testb	$1, %sil
	movq	%rax, 8(%rsp)           ## 8-byte Spill
	movq	%rdx, (%rsp)            ## 8-byte Spill
	jne	LBB17_24
	jmp	LBB17_25
LBB17_24:
	movq	$0, 296(%rsp)
	jmp	LBB17_26
LBB17_25:
	movq	(%rsp), %rax            ## 8-byte Reload
	movq	16(%rax), %rcx
	subq	(%rax), %rcx
	addq	8(%rax), %rcx
	movq	%rcx, 296(%rsp)
LBB17_26:
	imulq	$100000, 296(%rsp), %rax ## imm = 0x186A0
	movq	8(%rsp), %rcx           ## 8-byte Reload
	movq	%rcx, 280(%rsp)
	movq	%rax, 272(%rsp)
	movq	280(%rsp), %rax
	movq	272(%rsp), %rdx
	movq	%rdx, 64(%rax)
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	6400424(%rsp), %rdx
	cmpq	%rdx, %rax
	jne	LBB17_28
## %bb.27:
	movq	%rbp, %rsp
	popq	%rbp
	vzeroupper
	retq
LBB17_28:
	vzeroupper
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN6spruce5vec3dC1Ev   ## -- Begin function _ZN6spruce5vec3dC1Ev
	.weak_def_can_be_hidden	__ZN6spruce5vec3dC1Ev
	.p2align	4, 0x90
__ZN6spruce5vec3dC1Ev:                  ## @_ZN6spruce5vec3dC1Ev
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZN6spruce5vec3dC2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN6spruce5vec3dC2Ev   ## -- Begin function _ZN6spruce5vec3dC2Ev
	.weak_def_can_be_hidden	__ZN6spruce5vec3dC2Ev
	.p2align	4, 0x90
__ZN6spruce5vec3dC2Ev:                  ## @_ZN6spruce5vec3dC2Ev
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	vxorps	%xmm0, %xmm0, %xmm0
	vmovsd	%xmm0, (%rdi)
	vmovsd	%xmm0, 8(%rdi)
	vmovsd	%xmm0, 16(%rdi)
	vmovsd	%xmm0, 24(%rdi)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN9benchmark8internal17FunctionBenchmarkC2EPKcPFvRNS_5StateEE ## -- Begin function _ZN9benchmark8internal17FunctionBenchmarkC2EPKcPFvRNS_5StateEE
	.weak_def_can_be_hidden	__ZN9benchmark8internal17FunctionBenchmarkC2EPKcPFvRNS_5StateEE
	.p2align	4, 0x90
__ZN9benchmark8internal17FunctionBenchmarkC2EPKcPFvRNS_5StateEE: ## @_ZN9benchmark8internal17FunctionBenchmarkC2EPKcPFvRNS_5StateEE
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rdx
	movq	%rdx, %rsi
	movq	-16(%rbp), %rdi
	movq	%rdi, -32(%rbp)         ## 8-byte Spill
	movq	%rsi, %rdi
	movq	-32(%rbp), %rsi         ## 8-byte Reload
	movq	%rdx, -40(%rbp)         ## 8-byte Spill
	callq	__ZN9benchmark8internal9BenchmarkC2EPKc
	movq	__ZTVN9benchmark8internal17FunctionBenchmarkE@GOTPCREL(%rip), %rdx
	addq	$16, %rdx
	movq	-40(%rbp), %rsi         ## 8-byte Reload
	movq	%rdx, (%rsi)
	movq	-24(%rbp), %rdx
	movq	%rdx, 184(%rsi)
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN6sprucemlERKNS_5vec3dEd ## -- Begin function _ZN6sprucemlERKNS_5vec3dEd
	.weak_definition	__ZN6sprucemlERKNS_5vec3dEd
	.p2align	4, 0x90
__ZN6sprucemlERKNS_5vec3dEd:            ## @_ZN6sprucemlERKNS_5vec3dEd
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	andq	$-32, %rsp
	subq	$160, %rsp
	movq	%rdi, %rax
	movq	%rsi, 136(%rsp)
	vmovsd	%xmm0, 128(%rsp)
	movq	136(%rsp), %rsi
	movq	%rdi, 24(%rsp)          ## 8-byte Spill
	movq	%rsi, %rdi
	movq	%rax, 16(%rsp)          ## 8-byte Spill
	callq	__ZN6spruce4simd6load4dERKd
	vmovapd	%ymm0, 96(%rsp)
	leaq	128(%rsp), %rdi
	callq	__ZN6spruce4simd6load1dERKd
	vmovapd	%ymm0, 64(%rsp)
	movq	24(%rsp), %rdi          ## 8-byte Reload
	vzeroupper
	callq	__ZN6spruce5vec3dC1Ev
	leaq	96(%rsp), %rdi
	leaq	64(%rsp), %rsi
	callq	__ZN6spruce4simd5mul4dERKDv4_dS3_
	vmovapd	%ymm0, 32(%rsp)
	movq	24(%rsp), %rdi          ## 8-byte Reload
	leaq	32(%rsp), %rsi
	vzeroupper
	callq	__ZN6spruce4simd7store4dERdRKDv4_d
	movq	16(%rsp), %rax          ## 8-byte Reload
	movq	%rbp, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN6spruce4simd6load4dERKd ## -- Begin function _ZN6spruce4simd6load4dERKd
	.weak_definition	__ZN6spruce4simd6load4dERKd
	.p2align	4, 0x90
__ZN6spruce4simd6load4dERKd:            ## @_ZN6spruce4simd6load4dERKd
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -16(%rbp)
	movq	-16(%rbp), %rdi
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	vmovupd	(%rdi), %ymm0
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN6spruce4simd6load1dERKd ## -- Begin function _ZN6spruce4simd6load1dERKd
	.weak_definition	__ZN6spruce4simd6load1dERKd
	.p2align	4, 0x90
__ZN6spruce4simd6load1dERKd:            ## @_ZN6spruce4simd6load1dERKd
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	andq	$-32, %rsp
	subq	$128, %rsp
	leaq	64(%rsp), %rax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, 104(%rsp)
	movq	%rdi, 48(%rsp)
	movq	48(%rsp), %rcx
	vmovsd	(%rcx), %xmm0           ## xmm0 = mem[0],zero
	vmovsd	%xmm0, 64(%rsp)
	movq	48(%rsp), %rcx
	vmovsd	(%rcx), %xmm0           ## xmm0 = mem[0],zero
	vmovsd	%xmm0, 72(%rsp)
	movq	48(%rsp), %rcx
	vmovsd	(%rcx), %xmm0           ## xmm0 = mem[0],zero
	vmovsd	%xmm0, 80(%rsp)
	movq	48(%rsp), %rcx
	vmovsd	(%rcx), %xmm0           ## xmm0 = mem[0],zero
	vmovsd	%xmm0, 88(%rsp)
	movq	%rax, 56(%rsp)
	movq	56(%rsp), %rax
	vmovupd	(%rax), %ymm0
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	104(%rsp), %rcx
	cmpq	%rcx, %rax
	vmovaps	%ymm0, (%rsp)           ## 32-byte Spill
	jne	LBB23_2
## %bb.1:
	vmovaps	(%rsp), %ymm0           ## 32-byte Reload
	movq	%rbp, %rsp
	popq	%rbp
	retq
LBB23_2:
	vzeroupper
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN6spruce4simd7store4dERdRKDv4_d ## -- Begin function _ZN6spruce4simd7store4dERdRKDv4_d
	.weak_definition	__ZN6spruce4simd7store4dERdRKDv4_d
	.p2align	4, 0x90
__ZN6spruce4simd7store4dERdRKDv4_d:     ## @_ZN6spruce4simd7store4dERdRKDv4_d
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	andq	$-32, %rsp
	subq	$96, %rsp
	movq	%rdi, 24(%rsp)
	movq	%rsi, 16(%rsp)
	movq	24(%rsp), %rsi
	movq	16(%rsp), %rdi
	vmovupd	(%rdi), %ymm0
	movq	%rsi, 72(%rsp)
	vmovapd	%ymm0, 32(%rsp)
	vmovapd	32(%rsp), %ymm0
	movq	72(%rsp), %rsi
	vmovupd	%ymm0, (%rsi)
	movq	%rbp, %rsp
	popq	%rbp
	vzeroupper
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN6spruce4simd5mul4dERKDv4_dS3_ ## -- Begin function _ZN6spruce4simd5mul4dERKDv4_dS3_
	.weak_definition	__ZN6spruce4simd5mul4dERKDv4_dS3_
	.p2align	4, 0x90
__ZN6spruce4simd5mul4dERKDv4_dS3_:      ## @_ZN6spruce4simd5mul4dERKDv4_dS3_
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	andq	$-32, %rsp
	subq	$128, %rsp
	movq	%rdi, 24(%rsp)
	movq	%rsi, 16(%rsp)
	movq	24(%rsp), %rsi
	vmovupd	(%rsi), %ymm0
	movq	16(%rsp), %rsi
	vmovupd	(%rsi), %ymm1
	vmovapd	%ymm0, 64(%rsp)
	vmovapd	%ymm1, 32(%rsp)
	vmovapd	64(%rsp), %ymm0
	vmulpd	32(%rsp), %ymm0, %ymm0
	movq	%rbp, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN6spruceplERKNS_5vec3dES2_ ## -- Begin function _ZN6spruceplERKNS_5vec3dES2_
	.weak_definition	__ZN6spruceplERKNS_5vec3dES2_
	.p2align	4, 0x90
__ZN6spruceplERKNS_5vec3dES2_:          ## @_ZN6spruceplERKNS_5vec3dES2_
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	andq	$-32, %rsp
	subq	$192, %rsp
	movq	%rdi, %rax
	movq	%rsi, 168(%rsp)
	movq	%rdx, 160(%rsp)
	movq	168(%rsp), %rdx
	movq	%rdi, 24(%rsp)          ## 8-byte Spill
	movq	%rdx, %rdi
	movq	%rax, 16(%rsp)          ## 8-byte Spill
	callq	__ZN6spruce4simd6load4dERKd
	vmovapd	%ymm0, 128(%rsp)
	movq	160(%rsp), %rdi
	callq	__ZN6spruce4simd6load4dERKd
	vmovapd	%ymm0, 96(%rsp)
	leaq	64(%rsp), %rdi
	vzeroupper
	callq	__ZN6spruce5vec3dC1Ev
	leaq	64(%rsp), %rdi
	leaq	128(%rsp), %rax
	movq	%rdi, 8(%rsp)           ## 8-byte Spill
	movq	%rax, %rdi
	leaq	96(%rsp), %rsi
	callq	__ZN6spruce4simd5sub4dERKDv4_dS3_
	vmovapd	%ymm0, 32(%rsp)
	movq	8(%rsp), %rdi           ## 8-byte Reload
	leaq	32(%rsp), %rsi
	vzeroupper
	callq	__ZN6spruce4simd7store4dERdRKDv4_d
	vmovsd	64(%rsp), %xmm0         ## xmm0 = mem[0],zero
	movq	24(%rsp), %rdi          ## 8-byte Reload
	callq	__ZN6spruce5vec3dC1Ed
	movq	16(%rsp), %rax          ## 8-byte Reload
	movq	%rbp, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN6spruce4simd5sub4dERKDv4_dS3_ ## -- Begin function _ZN6spruce4simd5sub4dERKDv4_dS3_
	.weak_definition	__ZN6spruce4simd5sub4dERKDv4_dS3_
	.p2align	4, 0x90
__ZN6spruce4simd5sub4dERKDv4_dS3_:      ## @_ZN6spruce4simd5sub4dERKDv4_dS3_
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	andq	$-32, %rsp
	subq	$128, %rsp
	movq	%rdi, 24(%rsp)
	movq	%rsi, 16(%rsp)
	movq	24(%rsp), %rsi
	vmovupd	(%rsi), %ymm0
	movq	16(%rsp), %rsi
	vmovupd	(%rsi), %ymm1
	vmovapd	%ymm0, 64(%rsp)
	vmovapd	%ymm1, 32(%rsp)
	vmovapd	64(%rsp), %ymm0
	vsubpd	32(%rsp), %ymm0, %ymm0
	movq	%rbp, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function _ZZL15vec3dScaleMultiRN9benchmark5StateEEN8TestDataC1Ev
__ZZL15vec3dScaleMultiRN9benchmark5StateEEN8TestDataC1Ev: ## @_ZZL15vec3dScaleMultiRN9benchmark5StateEEN8TestDataC1Ev
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZZL15vec3dScaleMultiRN9benchmark5StateEEN8TestDataC2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function _ZZL15vec3dScaleMultiRN9benchmark5StateEEN8TestDataC2Ev
__ZZL15vec3dScaleMultiRN9benchmark5StateEEN8TestDataC2Ev: ## @_ZZL15vec3dScaleMultiRN9benchmark5StateEEN8TestDataC2Ev
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZN6spruce5vec3dC1Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function _ZZL13vec3dAddMultiRN9benchmark5StateEEN8TestDataC1Ev
__ZZL13vec3dAddMultiRN9benchmark5StateEEN8TestDataC1Ev: ## @_ZZL13vec3dAddMultiRN9benchmark5StateEEN8TestDataC1Ev
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZZL13vec3dAddMultiRN9benchmark5StateEEN8TestDataC2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function _ZZL13vec3dAddMultiRN9benchmark5StateEEN8TestDataC2Ev
__ZZL13vec3dAddMultiRN9benchmark5StateEEN8TestDataC2Ev: ## @_ZZL13vec3dAddMultiRN9benchmark5StateEEN8TestDataC2Ev
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	%rdi, -16(%rbp)         ## 8-byte Spill
	callq	__ZN6spruce5vec3dC1Ev
	movq	-16(%rbp), %rdi         ## 8-byte Reload
	addq	$32, %rdi
	callq	__ZN6spruce5vec3dC1Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function _ZZL13vec3dSubMultiRN9benchmark5StateEEN8TestDataC1Ev
__ZZL13vec3dSubMultiRN9benchmark5StateEEN8TestDataC1Ev: ## @_ZZL13vec3dSubMultiRN9benchmark5StateEEN8TestDataC1Ev
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZZL13vec3dSubMultiRN9benchmark5StateEEN8TestDataC2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN6sprucemiERKNS_5vec3dES2_ ## -- Begin function _ZN6sprucemiERKNS_5vec3dES2_
	.weak_definition	__ZN6sprucemiERKNS_5vec3dES2_
	.p2align	4, 0x90
__ZN6sprucemiERKNS_5vec3dES2_:          ## @_ZN6sprucemiERKNS_5vec3dES2_
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	andq	$-32, %rsp
	subq	$160, %rsp
	movq	%rdi, %rax
	movq	%rsi, 136(%rsp)
	movq	%rdx, 128(%rsp)
	movq	136(%rsp), %rdx
	movq	%rdi, 24(%rsp)          ## 8-byte Spill
	movq	%rdx, %rdi
	movq	%rax, 16(%rsp)          ## 8-byte Spill
	callq	__ZN6spruce4simd6load4dERKd
	vmovapd	%ymm0, 96(%rsp)
	movq	128(%rsp), %rdi
	callq	__ZN6spruce4simd6load4dERKd
	vmovapd	%ymm0, 64(%rsp)
	movq	24(%rsp), %rdi          ## 8-byte Reload
	vzeroupper
	callq	__ZN6spruce5vec3dC1Ev
	leaq	96(%rsp), %rdi
	leaq	64(%rsp), %rsi
	callq	__ZN6spruce4simd5sub4dERKDv4_dS3_
	vmovapd	%ymm0, 32(%rsp)
	movq	24(%rsp), %rdi          ## 8-byte Reload
	leaq	32(%rsp), %rsi
	vzeroupper
	callq	__ZN6spruce4simd7store4dERdRKDv4_d
	movq	16(%rsp), %rax          ## 8-byte Reload
	movq	%rbp, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function _ZZL13vec3dSubMultiRN9benchmark5StateEEN8TestDataC2Ev
__ZZL13vec3dSubMultiRN9benchmark5StateEEN8TestDataC2Ev: ## @_ZZL13vec3dSubMultiRN9benchmark5StateEEN8TestDataC2Ev
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	%rdi, -16(%rbp)         ## 8-byte Spill
	callq	__ZN6spruce5vec3dC1Ev
	movq	-16(%rbp), %rdi         ## 8-byte Reload
	addq	$32, %rdi
	callq	__ZN6spruce5vec3dC1Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90         ## -- Begin function _GLOBAL__sub_I_vec3dbench.cpp
__GLOBAL__sub_I_vec3dbench.cpp:         ## @_GLOBAL__sub_I_vec3dbench.cpp
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	callq	___cxx_global_var_init
	callq	___cxx_global_var_init.1
	callq	___cxx_global_var_init.2
	callq	___cxx_global_var_init.4
	callq	___cxx_global_var_init.6
	callq	___cxx_global_var_init.8
	callq	___cxx_global_var_init.10
	callq	___cxx_global_var_init.12
	callq	___cxx_global_var_init.14
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.zerofill __DATA,__bss,__ZN9benchmark8internalL18stream_init_anchorE,4,2 ## @_ZN9benchmark8internalL18stream_init_anchorE
.zerofill __DATA,__bss,__ZL26_benchmark_2vec3dConstruct,8,3 ## @_ZL26_benchmark_2vec3dConstruct
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"vec3dConstruct"

.zerofill __DATA,__bss,__ZL22_benchmark_3vec3dScale,8,3 ## @_ZL22_benchmark_3vec3dScale
L_.str.3:                               ## @.str.3
	.asciz	"vec3dScale"

.zerofill __DATA,__bss,__ZL23_benchmark_4vec3dAddVec,8,3 ## @_ZL23_benchmark_4vec3dAddVec
L_.str.5:                               ## @.str.5
	.asciz	"vec3dAddVec"

.zerofill __DATA,__bss,__ZL27_benchmark_5vec3dScaleMulti,8,3 ## @_ZL27_benchmark_5vec3dScaleMulti
L_.str.7:                               ## @.str.7
	.asciz	"vec3dScaleMulti"

.zerofill __DATA,__bss,__ZL25_benchmark_6vec3dAddMulti,8,3 ## @_ZL25_benchmark_6vec3dAddMulti
L_.str.9:                               ## @.str.9
	.asciz	"vec3dAddMulti"

.zerofill __DATA,__bss,__ZL25_benchmark_7vec3dSubMulti,8,3 ## @_ZL25_benchmark_7vec3dSubMulti
L_.str.11:                              ## @.str.11
	.asciz	"vec3dSubMulti"

.zerofill __DATA,__bss,__ZL20_benchmark_8vec3dCrs,8,3 ## @_ZL20_benchmark_8vec3dCrs
L_.str.13:                              ## @.str.13
	.asciz	"vec3dCrs"

.zerofill __DATA,__bss,__ZL29_benchmark_9vec3dAddMultiSIMD,8,3 ## @_ZL29_benchmark_9vec3dAddMultiSIMD
L_.str.15:                              ## @.str.15
	.asciz	"vec3dAddMultiSIMD"

L___func__._ZN9benchmark5State13StateIteratorppEv: ## @__func__._ZN9benchmark5State13StateIteratorppEv
	.asciz	"operator++"

L_.str.16:                              ## @.str.16
	.asciz	"/usr/local/include/benchmark/benchmark.h"

L_.str.17:                              ## @.str.17
	.asciz	"cached_ > 0"

	.section	__DATA,__mod_init_func,mod_init_funcs
	.p2align	3
	.quad	__GLOBAL__sub_I_vec3dbench.cpp

.subsections_via_symbols
