#ifndef _REG_H
#define _REG_H

#define BCM2837_PERIPHERALS_BASE (0x3F000000U) // {Mapped to VC address 7E000000}

#define BCM2837_VCIO_ALIAS       (0x7E000000U) // {ARM Physical to VC IO Mapping (See: BCM2835-ARM-Peripherals.pdf)}

#define VC_TO_ARM_ADDRESS(a)     (a - BCM2837_VCIO_ALIAS + BCM2837_PERIPHERALS_BASE)

#define BIT(x) ((1U) << (x))
#define MASK(n) (BIT(n) - 1U)

#define REG(n) ((volatile unsigned int *)(n))

#endif
