#include "reg.h"
#include "uart.h"

#define VIDEOCORE_MBOX (0x3F00B880)
#define MAILBOX0_READ   ((volatile unsigned int*)(VIDEOCORE_MBOX + 0x00))
#define MAILBOX0_PEEK   ((volatile unsigned int*)(VIDEOCORE_MBOX + 0x10))
#define MAILBOX0_SENDER ((volatile unsigned int*)(VIDEOCORE_MBOX + 0x14))
#define MAILBOX0_STATUS ((volatile unsigned int*)(VIDEOCORE_MBOX + 0x18))
#define MAILBOX0_CONFIG ((volatile unsigned int*)(VIDEOCORE_MBOX + 0x1C))
#define MAILBOX1_WRITE  ((volatile unsigned int*)(VIDEOCORE_MBOX + 0x20))
#define MAILBOX1_PEEK   ((volatile unsigned int*)(VIDEOCORE_MBOX + 0x30))
#define MAILBOX1_SENDER ((volatile unsigned int*)(VIDEOCORE_MBOX + 0x34))
#define MAILBOX1_STATUS ((volatile unsigned int*)(VIDEOCORE_MBOX + 0x38))
#define MAILBOX1_CONFIG ((volatile unsigned int*)(VIDEOCORE_MBOX + 0x3C))
#define ARM_MS_FULL           BIT(31)
#define MBOX_RESPONSE         BIT(31)
#define ARM_MS_EMPTY          BIT(30)
#define ARM_MC_IHAVEDATAIRQEN BIT(0)

#define MBOX_REQUEST    0

/* channels */
#define MBOX_CH_POWER   0
#define MBOX_CH_FB      1
#define MBOX_CH_VUART   2
#define MBOX_CH_VCHIQ   3
#define MBOX_CH_LEDS    4
#define MBOX_CH_BTNS    5
#define MBOX_CH_TOUCH   6
#define MBOX_CH_COUNT   7
#define MBOX_CH_PROP    8

/* tags */
#define MBOX_TAG_GETSERIAL      0x10004
#define MBOX_TAG_LAST           0

#define ALIGN(n) __attribute__((aligned(n)))

/* mailbox message buffer */
volatile unsigned int mbox_buffer[64] ALIGN(16);

int mailbox_call(unsigned char channel)
{
	unsigned int address = (unsigned int)(((unsigned long)mbox_buffer & ~0xF) | (channel & 0xF));

	puts("mailbox_call check prewrite\n");
	while (*MAILBOX1_STATUS & ARM_MS_FULL);

	*MAILBOX1_WRITE = address;

	while (1) {
		puts("mailbox_call check preread\n");
		while (*MAILBOX0_STATUS & ARM_MS_EMPTY);

		puts("mailbox_call reading\n");
		if (address == *MAILBOX0_READ)
			return mbox_buffer[1] == MBOX_RESPONSE;
	}
	puts("mailbox_call error\n");
	return 0;
}

void get_serial(void)
{
	mbox_buffer[0] = 8 * 4;
	mbox_buffer[1] = MBOX_REQUEST;
	mbox_buffer[2] = MBOX_TAG_GETSERIAL; // tag identifier
	mbox_buffer[3] = 8; // buffer size
	mbox_buffer[4] = 8; // buffer size
	mbox_buffer[5] = 0; // clear buffer data
	mbox_buffer[6] = 0; // clear buffer data
	mailbox_call(MBOX_CH_PROP);
	puts("My serial number is\n");
	hex(mbox_buffer[6]);
	hex(mbox_buffer[5]);
}
