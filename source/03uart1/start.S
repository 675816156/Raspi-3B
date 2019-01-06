.section ".text.boot"

.global _start

_start:
	// read cpuid, stop slave cores
	mrs x1, mpidr_el1
	and x1, x1, #3
	cbz x1, 2f
	// cpuid > 0, stop
1:
	wfe
	b 1b
	// cpuid == 0
2:
	// set stack before out code
	ldr x1, =_start
	mov sp, x1

	// clear bss
	ldr x1, =__bss_start
	ldr x2, =__bss_size
3:
	cbz x2, 4f
	str xzr, [x1]
	sub x2, x2, #1
	b 3b
4:
	bl main
	b 1b
