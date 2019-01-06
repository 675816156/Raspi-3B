#ifndef _UART_H
#define _UART_H

extern void uart_init(void);
extern void uart_putc(unsigned char);
extern unsigned char uart_getc(void);
extern void puts(char *);
extern void hex(unsigned int);
#endif
