CROSS_COMPILE:=aarch64-linux-gnu-
CFLAGS:= -Wall -O0 -nostdinc -nostdlib
LDFLAGS:= -nostdlib
CC:=${CROSS_COMPILE}gcc
LD:=${CROSS_COMPILE}ld
OBJCOPY:=${CROSS_COMPILE}objcopy

all: kernel8.img

start.o: start.S
	$(CC) $(CFLAGS) -c $< -o $@

kernel8.img: start.o
	$(LD) $(LDFLAGS) $^ -Tlink.ld -o kernel8.elf
	$(OBJCOPY) -O binary kernel8.elf $@

clean:
	rm -f kernel8.* *.o >/dev/null
