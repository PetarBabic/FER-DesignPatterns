	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 2
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	x0, #16                         ; =0x10
	bl	__Znwm
	str	x0, [sp]                        ; 8-byte Folded Spill
	bl	__ZN9CoolClassC1Ev
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	str	x0, [sp, #16]
	sub	x0, x29, #4
	mov	w1, #42                         ; =0x2a
	str	w1, [sp, #12]                   ; 4-byte Folded Spill
	bl	__ZN13PlainOldClass3setEi
	ldr	w1, [sp, #12]                   ; 4-byte Folded Reload
	ldr	x0, [sp, #16]
	ldr	x8, [x0]
	ldr	x8, [x8]
	blr	x8
	mov	w0, #0                          ; =0x0
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZN9CoolClassC1Ev              ; -- Begin function _ZN9CoolClassC1Ev
	.weak_def_can_be_hidden	__ZN9CoolClassC1Ev
	.p2align	2
__ZN9CoolClassC1Ev:                     ; @_ZN9CoolClassC1Ev
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
	bl	__ZN9CoolClassC2Ev
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZN13PlainOldClass3setEi       ; -- Begin function _ZN13PlainOldClass3setEi
	.weak_definition	__ZN13PlainOldClass3setEi
	.p2align	2
__ZN13PlainOldClass3setEi:              ; @_ZN13PlainOldClass3setEi
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	str	w1, [sp, #4]
	ldr	x9, [sp, #8]
	ldr	w8, [sp, #4]
	str	w8, [x9]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZN9CoolClassC2Ev              ; -- Begin function _ZN9CoolClassC2Ev
	.weak_def_can_be_hidden	__ZN9CoolClassC2Ev
	.p2align	2
__ZN9CoolClassC2Ev:                     ; @_ZN9CoolClassC2Ev
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
	adrp	x8, __ZTV9CoolClass@GOTPAGE
	ldr	x8, [x8, __ZTV9CoolClass@GOTPAGEOFF]
	add	x8, x8, #16
	str	x8, [x0]
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
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	adrp	x8, __ZTV4Base@GOTPAGE
	ldr	x8, [x8, __ZTV4Base@GOTPAGEOFF]
	add	x8, x8, #16
	str	x8, [x0]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZN9CoolClass3setEi            ; -- Begin function _ZN9CoolClass3setEi
	.weak_def_can_be_hidden	__ZN9CoolClass3setEi
	.p2align	2
__ZN9CoolClass3setEi:                   ; @_ZN9CoolClass3setEi
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	str	w1, [sp, #4]
	ldr	x9, [sp, #8]
	ldr	w8, [sp, #4]
	str	w8, [x9, #8]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZN9CoolClass3getEv            ; -- Begin function _ZN9CoolClass3getEv
	.weak_def_can_be_hidden	__ZN9CoolClass3getEv
	.p2align	2
__ZN9CoolClass3getEv:                   ; @_ZN9CoolClass3getEv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	ldr	x8, [sp, #8]
	ldr	w0, [x8, #8]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__DATA,__const
	.globl	__ZTV9CoolClass                 ; @_ZTV9CoolClass
	.weak_def_can_be_hidden	__ZTV9CoolClass
	.p2align	3, 0x0
__ZTV9CoolClass:
	.quad	0
	.quad	__ZTI9CoolClass
	.quad	__ZN9CoolClass3setEi
	.quad	__ZN9CoolClass3getEv

	.private_extern	__ZTS9CoolClass         ; @_ZTS9CoolClass
	.section	__TEXT,__const
	.globl	__ZTS9CoolClass
	.weak_definition	__ZTS9CoolClass
__ZTS9CoolClass:
	.asciz	"9CoolClass"

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

	.private_extern	__ZTI9CoolClass         ; @_ZTI9CoolClass
	.globl	__ZTI9CoolClass
	.weak_definition	__ZTI9CoolClass
	.p2align	3, 0x0
__ZTI9CoolClass:
	.quad	__ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	__ZTS9CoolClass-9223372036854775808
	.quad	__ZTI4Base

	.globl	__ZTV4Base                      ; @_ZTV4Base
	.weak_def_can_be_hidden	__ZTV4Base
	.p2align	3, 0x0
__ZTV4Base:
	.quad	0
	.quad	__ZTI4Base
	.quad	___cxa_pure_virtual
	.quad	___cxa_pure_virtual

.subsections_via_symbols
