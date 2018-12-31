fllowing files are getting from https://github.com/raspberrypi/firmware/tree/master/boot

1.bootcode.bin
2.fixup.dat
3.start.elf

Handle bootcode.bin to enable UART:
```shell
sed -i -e "s/BOOT_UART=0/BOOT_UART=1/" bootcode.bin && strings bootcode.bin | grep BOOT_UART
```
