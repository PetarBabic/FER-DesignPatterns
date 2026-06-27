.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 2
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; ».0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	x0, #16                         ; =0x10
	bl	_operator new(unsigned long)
	str	x0, [sp]                        ; 8-byte Folded Spill
	bl	_CoolClass::CoolClass()
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	str	x0, [sp, #16]
	sub	x0, x29, #4
	mov	w1, #42                         ; =0x2a
	str	w1, [sp, #12]                   ; 4-byte Folded Spill
	bl	_PlainOldClass::set(int)
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
	.globl	_CoolClass::CoolClass()              ; -- Begin function CoolClass::CoolClass()
	.weak_def_can_be_hidden	_CoolClass::CoolClass()
	.p2align	2
_CoolClass::CoolClass():                     ; @CoolClass::CoolClass()
	.cfi_startproc
; ».0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	str	x0, [sp]                        ; 8-byte Folded Spill
	bl	_CoolClass::CoolClass()
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_PlainOldClass::set(int)       ; -- Begin function PlainOldClass::set(int)
	.weak_definition	_PlainOldClass::set(int)
	.p2align	2
_PlainOldClass::set(int):              ; @PlainOldClass::set(int)
	.cfi_startproc
; ».0:
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
	.globl	_CoolClass::CoolClass()              ; -- Begin function CoolClass::CoolClass()
	.weak_def_can_be_hidden	_CoolClass::CoolClass()
	.p2align	2
_CoolClass::CoolClass():                     ; @CoolClass::CoolClass()
	.cfi_startproc
; ».0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	str	x0, [sp]                        ; 8-byte Folded Spill
	bl	_Base::Base()
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
	.globl	_Base::Base()                   ; -- Begin function Base::Base()
	.weak_def_can_be_hidden	_Base::Base()
	.p2align	2
_Base::Base():                          ; @Base::Base()
	.cfi_startproc
; ».0:
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
	.globl	_CoolClass::set(int)            ; -- Begin function CoolClass::set(int)
	.weak_def_can_be_hidden	_CoolClass::set(int)
	.p2align	2
_CoolClass::set(int):                   ; @CoolClass::set(int)
	.cfi_startproc
; ».0:
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
	.globl	_CoolClass::get()            ; -- Begin function CoolClass::get()
	.weak_def_can_be_hidden	_CoolClass::get()
	.p2align	2
_CoolClass::get():                   ; @CoolClass::get()
	.cfi_startproc
; ».0:
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
	.globl	_vtable for CoolClass                 ; @vtable for CoolClass
	.weak_def_can_be_hidden	_vtable for CoolClass
	.p2align	3, 0x0
_vtable for CoolClass:
	.quad	0
	.quad	_typeinfo for CoolClass
	.quad	_CoolClass::set(int)
	.quad	_CoolClass::get()

	.private_extern	_typeinfo name for CoolClass         ; @typeinfo name for CoolClass
	.section	__TEXT,__const
	.globl	_typeinfo name for CoolClass
	.weak_definition	_typeinfo name for CoolClass
_typeinfo name for CoolClass:
	.asciz	"9CoolClass"

	.private_extern	_typeinfo name for Base              ; @typeinfo name for Base
	.globl	_typeinfo name for Base
	.weak_definition	_typeinfo name for Base
_typeinfo name for Base:
	.asciz	"4Base"

	.private_extern	_typeinfo for Base              ; @typeinfo for Base
	.section	__DATA,__const
	.globl	_typeinfo for Base
	.weak_definition	_typeinfo for Base
	.p2align	3, 0x0
_typeinfo for Base:
	.quad	_vtable for __cxxabiv1::__class_type_info 16
	.quad	_typeinfo name for Base-9223372036854775808

	.private_extern	_typeinfo for CoolClass         ; @typeinfo for CoolClass
	.globl	_typeinfo for CoolClass
	.weak_definition	_typeinfo for CoolClass
	.p2align	3, 0x0
_typeinfo for CoolClass:
	.quad	_vtable for __cxxabiv1::__si_class_type_info 16
	.quad	_typeinfo name for CoolClass-9223372036854775808
	.quad	_typeinfo for Base

	.globl	_vtable for Base                      ; @vtable for Base
	.weak_def_can_be_hidden	_vtable for Base
	.p2align	3, 0x0
_vtable for Base:
	.quad	0
	.quad	_typeinfo for Base
	.quad	___cxa_pure_virtual
	.quad	___cxa_pure_virtual

.subsections_via_symbols