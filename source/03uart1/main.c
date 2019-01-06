#include "uart.h"
#include "printf.h"

int main(void)
{
	volatile int i;
	char *ptr = "Hello world!\n";

	uart_init();

	hex(0x12345678);
	hex(0x01234567);
	hex(0x01234560);
	while (1) {
		for (i = 0; i < 250 * 1000 * 10; ++i);
		puts(ptr);
		for (i = 0; i < 250 * 1000 * 10; ++i);
	}

	return 0;
}
