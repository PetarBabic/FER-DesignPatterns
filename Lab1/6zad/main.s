	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 2
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception0
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	x0, #8                          ; =0x8
	bl	__Znwm
	str	x0, [sp]                        ; 8-byte Folded Spill
Ltmp0:
	bl	__ZN7DerivedC1Ev
Ltmp1:
	b	LBB0_1
LBB0_1:
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	stur	x8, [x29, #-8]
	ldur	x0, [x29, #-8]
	bl	__ZN4Base6metodaEv
	mov	w0, #0                          ; =0x0
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
LBB0_2:
Ltmp2:
	mov	x8, x0
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	str	x8, [sp, #16]
	mov	x8, x1
	str	w8, [sp, #12]
	bl	__ZdlPv
	b	LBB0_3
LBB0_3:
	ldr	x0, [sp, #16]
	bl	__Unwind_Resume
Lfunc_end0:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2, 0x0
GCC_except_table0:
Lexception0:
	.byte	255                             ; @LPStart Encoding = omit
	.byte	255                             ; @TType Encoding = omit
	.byte	1                               ; Call site Encoding = uleb128
	.uleb128 Lcst_end0-Lcst_begin0
Lcst_begin0:
	.uleb128 Lfunc_begin0-Lfunc_begin0      ; >> Call Site 1 <<
	.uleb128 Ltmp0-Lfunc_begin0             ;   Call between Lfunc_begin0 and Ltmp0
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp0-Lfunc_begin0             ; >> Call Site 2 <<
	.uleb128 Ltmp1-Ltmp0                    ;   Call between Ltmp0 and Ltmp1
	.uleb128 Ltmp2-Lfunc_begin0             ;     jumps to Ltmp2
	.byte	0                               ;   On action: cleanup
	.uleb128 Ltmp1-Lfunc_begin0             ; >> Call Site 3 <<
	.uleb128 Lfunc_end0-Ltmp1               ;   Call between Ltmp1 and Lfunc_end0
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
Lcst_end0:
	.p2align	2, 0x0
                                        ; -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN7DerivedC1Ev                ; -- Begin function _ZN7DerivedC1Ev
	.weak_def_can_be_hidden	__ZN7DerivedC1Ev
	.p2align	2
__ZN7DerivedC1Ev:                       ; @_ZN7DerivedC1Ev
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	str	x0, [sp]                        ; 8-byte Folded Spill
	bl	__ZN7DerivedC2Ev
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZN4Base6metodaEv              ; -- Begin function _ZN4Base6metodaEv
	.weak_definition	__ZN4Base6metodaEv
	.p2align	2
__ZN4Base6metodaEv:                     ; @_ZN4Base6metodaEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	ldr	x8, [sp, #8]
	str	x8, [sp]                        ; 8-byte Folded Spill
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	ldr	x8, [x0]
	ldr	x8, [x8]
	blr	x8
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZN7DerivedC2Ev                ; -- Begin function _ZN7DerivedC2Ev
	.weak_def_can_be_hidden	__ZN7DerivedC2Ev
	.p2align	2
__ZN7DerivedC2Ev:                       ; @_ZN7DerivedC2Ev
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	str	x0, [sp]                        ; 8-byte Folded Spill
	bl	__ZN4BaseC2Ev
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	adrp	x8, __ZTV7Derived@GOTPAGE
	ldr	x8, [x8, __ZTV7Derived@GOTPAGEOFF]
	add	x8, x8, #16
	str	x8, [x0]
	bl	__ZN4Base6metodaEv
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZN4BaseC2Ev                   ; -- Begin function _ZN4BaseC2Ev
	.weak_def_can_be_hidden	__ZN4BaseC2Ev
	.p2align	2
__ZN4BaseC2Ev:                          ; @_ZN4BaseC2Ev
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	str	x0, [sp]                        ; 8-byte Folded Spill
	adrp	x8, __ZTV4Base@GOTPAGE
	ldr	x8, [x8, __ZTV4Base@GOTPAGEOFF]
	add	x8, x8, #16
	str	x8, [x0]
	bl	__ZN4Base6metodaEv
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZN7Derived15virtualnaMetodaEv ; -- Begin function _ZN7Derived15virtualnaMetodaEv
	.weak_def_can_be_hidden	__ZN7Derived15virtualnaMetodaEv
	.p2align	2
__ZN7Derived15virtualnaMetodaEv:        ; @_ZN7Derived15virtualnaMetodaEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZN4Base15virtualnaMetodaEv    ; -- Begin function _ZN4Base15virtualnaMetodaEv
	.weak_def_can_be_hidden	__ZN4Base15virtualnaMetodaEv
	.p2align	2
__ZN4Base15virtualnaMetodaEv:           ; @_ZN4Base15virtualnaMetodaEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__DATA,__const
	.globl	__ZTV7Derived                   ; @_ZTV7Derived
	.weak_def_can_be_hidden	__ZTV7Derived
	.p2align	3, 0x0
__ZTV7Derived:
	.quad	0
	.quad	__ZTI7Derived
	.quad	__ZN7Derived15virtualnaMetodaEv

	.private_extern	__ZTS7Derived           ; @_ZTS7Derived
	.section	__TEXT,__const
	.globl	__ZTS7Derived
	.weak_definition	__ZTS7Derived
__ZTS7Derived:
	.asciz	"7Derived"

	.private_extern	__ZTS4Base              ; @_ZTS4Base
	.globl	__ZTS4Base
	.weak_definition	__ZTS4Base
__ZTS4Base:
	.asciz	"4Base"

	.private_extern	__ZTI4Base              ; @_ZTI4Base
	.section	__DATA,__const
	.globl	__ZTI4Base
	.weak_definition	__ZTI4Base
	.p2align	3, 0x0
__ZTI4Base:
	.quad	__ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	__ZTS4Base-9223372036854775808

	.private_extern	__ZTI7Derived           ; @_ZTI7Derived
	.globl	__ZTI7Derived
	.weak_definition	__ZTI7Derived
	.p2align	3, 0x0
__ZTI7Derived:
	.quad	__ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	__ZTS7Derived-9223372036854775808
	.quad	__ZTI4Base

	.globl	__ZTV4Base                      ; @_ZTV4Base
	.weak_def_can_be_hidden	__ZTV4Base
	.p2align	3, 0x0
__ZTV4Base:
	.quad	0
	.quad	__ZTI4Base
	.quad	__ZN4Base15virtualnaMetodaEv

	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"ja sam bazna implementacija!\n"

l_.str.1:                               ; @.str.1
	.asciz	"ja sam izvedena implementacija!\n"

l_.str.2:                               ; @.str.2
	.asciz	"Metoda kaze: "

.subsections_via_symbols
