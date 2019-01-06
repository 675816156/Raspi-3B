#include "gpio.h"

unsigned int gpio_function_select(unsigned char gpio, ALT_FUNCTION func)
{
	volatile unsigned int *reg = (volatile unsigned int *)(GPFSEL0);
	unsigned char pin = (unsigned char)(gpio / 10);
	unsigned int value = (*(reg + pin));

	if (gpio > MAX_GPIO) return 0;

	value &= (~(MASK(3) << (3 * (gpio % 10))));
	value |= ((func) << (3 * (gpio % 10)));
	(*(reg + pin)) = value;
	return value;
}

unsigned int gpio_common_set(unsigned long long BASE, unsigned char gpio, ONEBIT b)
{
	volatile unsigned int *reg = (volatile unsigned int *)(BASE);
	unsigned int value = (*(reg + (gpio / 32)));

	if (gpio > MAX_GPIO) return 0;

	value &= (~(BIT(gpio % 32)));
	value |= ((b) << (gpio % 32));
	(*(reg + (gpio / 32))) = value;
	return value;
}

ONEBIT gpio_common_get(unsigned long long BASE, unsigned char gpio)
{
	volatile unsigned int *reg = (volatile unsigned int *)(BASE);
	unsigned int value = (*(reg + (gpio / 32)));

	if (gpio > MAX_GPIO) return ZERO;

	value = (value >> (gpio % 32)) & BIT(1);
	return (value);
}
