CROSS_COMPILE:=aarch64-linux-gnu-
CFLAGS:= -Wall -O0 -ffreestanding -nostdinc -nostdlib -nostartfiles
LDFLAGS:= -nostdinc -nostdlib
CC:=${CROSS_COMPILE}gcc
LD:=${CROSS_COMPILE}ld
OBJCOPY:=${CROSS_COMPILE}objcopy
OBJDUMP:=$(CROSS_COMPILE)objdump

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

TARGET := kernel8.img


all: $(TARGET)

start.o: start.S
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

kernel8.img: start.o $(OBJS)
	$(LD) $(LDFLAGS) $^ -Tlink.ld -o kernel8.elf
	$(OBJCOPY) -O binary kernel8.elf $@
	$(OBJDUMP) -D kernel8.elf >kernel8.dis

clean:
	rm -f kernel8.* *.o >/dev/null
