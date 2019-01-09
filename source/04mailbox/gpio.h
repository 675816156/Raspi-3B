#ifndef _GPIO_H
#define _GPIO_H

#include "reg.h"

// GPIO
#define GPFSEL0   (VC_TO_ARM_ADDRESS(0x7E200000U))
#define GPSET0    (VC_TO_ARM_ADDRESS(0x7E20001CU))
#define GPCLR0    (VC_TO_ARM_ADDRESS(0x7E200028U))
#define GPLEV0    (VC_TO_ARM_ADDRESS(0x7E200034U))
#define GPEDS0    (VC_TO_ARM_ADDRESS(0x7E200040U))
#define GPREN0    (VC_TO_ARM_ADDRESS(0x7E20004CU))
#define GPFEN0    (VC_TO_ARM_ADDRESS(0x7E200058U))
#define GPHEN0    (VC_TO_ARM_ADDRESS(0x7E200064U))
#define GPLEN0    (VC_TO_ARM_ADDRESS(0x7E200070U))
#define GPAREN0   (VC_TO_ARM_ADDRESS(0x7E20007CU))
#define GPAFEN0   (VC_TO_ARM_ADDRESS(0x7E200088U))
#define GPPUD     (VC_TO_ARM_ADDRESS(0x7E200094U))
#define GPPUDCLK0 (VC_TO_ARM_ADDRESS(0x7E200098U))

#define MAX_GPIO (53)

typedef enum PUD {
	OFF = 0,
	PULL_DOWN = 1,
	PULL_UP   = 2,
	RESERVED  = 3,
} PUD;

typedef enum ALT_FUNCTION {
	INPUT     = 0,
	OUTPUT    = 1,
	FUNCTION0 = 4,
	FUNCTION1 = 5,
	FUNCTION2 = 6,
	FUNCTION3 = 7,
	FUNCTION4 = 3,
	FUNCTION5 = 2,
} ALT_FUNCTION;

typedef enum ONEBIT {
	ZERO = 0,
	ONE  = 1,
} ONEBIT;

extern unsigned int gpio_function_select(unsigned char, ALT_FUNCTION);
extern unsigned int gpio_common_set(unsigned long long, unsigned char, ONEBIT);
extern ONEBIT gpio_common_get(unsigned long long, unsigned char);

// output 1
#define GPIO_SET(gpio, v) do { gpio_common_set(GPSET0, gpio, v); } while(0)
// output 0
#define GPIO_CLR(gpio, v) do { gpio_common_set(GPCLR0, gpio, v); } while(0)
// input get pin value
#define GPIO_LEV(gpio) (gpio_common_get(GPLEV0, gpio))

#define GPIO_EDS_SET(gpio, v) do { gpio_common_set(GPEDS0, gpio, v); } while(0)
#define GPIO_EDS_GET(gpio, v)  (gpio_common_get(GPEDS0, gpio, v))

#define GPIO_REN_SET(gpio, v) do { gpio_common_set(GPREN0, gpio, v); } while(0)
#define GPIO_REN_GET(gpio, v)  (gpio_common_get(GPREN0, gpio, v))

#define GPIO_FEN_SET(gpio, v) do { gpio_common_set(GPFEN0, gpio, v); } while(0)
#define GPIO_FEN_GET(gpio, v)  (gpio_common_get(GPFEN0, gpio, v))

#define GPIO_HEN_SET(gpio, v) do { gpio_common_set(GPHEN0, gpio, v); } while(0)
#define GPIO_HEN_GET(gpio, v)  (gpio_common_get(GPHEN0, gpio, v))

#define GPIO_LEN_SET(gpio, v) do { gpio_common_set(GPLEN0, gpio, v); } while(0)
#define GPIO_LEN_GET(gpio, v)  (gpio_common_get(GPLEN0, gpio, v))

#define GPIO_AREN_SET(gpio, v) do { gpio_common_set(GPAREN0, gpio, v); } while(0)
#define GPIO_AREN_GET(gpio, v)  (gpio_common_get(GPAREN0, gpio, v))

#define GPIO_AFEN_SET(gpio, v) do { gpio_common_set(GPAFEN0, gpio, v); } while(0)
#define GPIO_AFEN_GET(gpio, v)  (gpio_common_get(GPAFEN0, gpio, v))

#define GPIO_PUD(v) do { *(volatile unsigned int *)GPPUD = v; } while(0)

#define GPIO_PUDCLK_SET(gpio, v) do { gpio_common_set(GPPUDCLK0, gpio, v); } while(0)
#define GPIO_PUDCLK_GET(gpio, v)  (gpio_common_get(GPPUDCLK0, gpio, v))

#endif
