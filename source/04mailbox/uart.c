#include "reg.h"
#include "gpio.h"

#define AUX_IRQ         REG(VC_TO_ARM_ADDRESS(0x7E215000))
#define AUX_ENABLES     REG(VC_TO_ARM_ADDRESS(0x7E215004))
#define AUX_MU_IO_REG   REG(VC_TO_ARM_ADDRESS(0x7E215040))
#define AUX_MU_IER_REG  REG(VC_TO_ARM_ADDRESS(0x7E215044))
#define AUX_MU_IIR_REG  REG(VC_TO_ARM_ADDRESS(0x7E215048))
#define AUX_MU_LCR_REG  REG(VC_TO_ARM_ADDRESS(0x7E21504C))
#define AUX_MU_MCR_REG  REG(VC_TO_ARM_ADDRESS(0x7E215050))
#define AUX_MU_LSR_REG  REG(VC_TO_ARM_ADDRESS(0x7E215054))
#define AUX_MU_MSR_REG  REG(VC_TO_ARM_ADDRESS(0x7E215058))
#define AUX_MU_SCRATCH  REG(VC_TO_ARM_ADDRESS(0x7E21505C))
#define AUX_MU_CNTL_REG REG(VC_TO_ARM_ADDRESS(0x7E215060))
#define AUX_MU_STAT_REG REG(VC_TO_ARM_ADDRESS(0x7E215064))
#define AUX_MU_BAUD_REG REG(VC_TO_ARM_ADDRESS(0x7E215068))

void uart_init(void)
{
	volatile int i;

	*AUX_ENABLES |= BIT(0); // UART register accessable
	*AUX_MU_CNTL_REG = 0;
	*AUX_MU_LCR_REG |= BIT(0); // 8bit
	*AUX_MU_MCR_REG = 0;
	*AUX_MU_IER_REG = 0;
	*AUX_MU_IIR_REG = 0xC6; // disable interrupts
	/* baudrate = system_clock_freq / (8 * (baudrate_reg + 1))
	   baudrate_reg = system_clock_freq / (baudrate * 8) - 1
	   baudrate_reg = 250Mhz / (115200 * 8) - 1 = 270
	*/
	*AUX_MU_BAUD_REG = 270;
	gpio_function_select(14, FUNCTION5); // GPIO14 as ALT5, TXD1
	gpio_function_select(15, FUNCTION5); // GPIO15 as ALT5, RXD1

	GPIO_PUD(OFF);

	for (i = 0; i < 150; ++i);
	GPIO_PUDCLK_SET(14, ONE);
	GPIO_PUDCLK_SET(15, ONE);
	for (i = 0; i < 150; ++i);
	GPIO_PUDCLK_SET(14, ZERO);
	GPIO_PUDCLK_SET(15, ZERO);
	*AUX_MU_CNTL_REG |= (BIT(1) | BIT(0)); // enable TX and RX
}

void uart_putc(unsigned char c)
{
	while (!(BIT(5) & (*AUX_MU_LSR_REG)));
	*AUX_MU_IO_REG = c;
}

unsigned char uart_getc(void)
{
	while (!(BIT(0) & (*AUX_MU_LSR_REG)));
	return (unsigned char)(*AUX_MU_IO_REG);
}

void puts(char *s)
{
	static char prev = 0;

	while (*s) {
		if (prev == '\n' && prev != '\r') uart_putc('\r');
		uart_putc(*s);
		s++;
		prev = *s;
	}
}

void hex(unsigned int d) {
	unsigned int n;
	int c;
	uart_putc('0');
	uart_putc('x');
	for (c = 28; c >= 0; c -= 4) {
		n = (d >> c) & 0xF;
		n += n > 9 ? 0x37 : 0x30;
		uart_putc(n);
	}
	uart_putc('\r');
	uart_putc('\n');
}

void outbyte(int c)
{
	unsigned char ch = c;
        static unsigned char prev = 0;

        if (ch == '\n' && prev != '\r') uart_putc('\r');
        uart_putc(ch);
        prev = ch;
}
