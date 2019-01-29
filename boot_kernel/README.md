boot kernel from kernel.org mailine source code

How to Build Kernel

```shell
make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- defconfig -j8
make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- Image.gz broadcom/bcm2837-rpi-3-b.dtb modules -j8

cp arch/arm64/boot/Image kernel8.img
cp arch/arm64/boot/dts/broadcom/bcm2837-rpi-3-b.dtb .
```

The mini initramfs is ramdisk.img come from https://github.com/675816156/Qemu-Ramdisk
git clone the repository and cd to the Qemu-Ramdisk directory,
run gen_ramdisk.sh and will output a ramdisk.img in current directory.

Copy follow files to sdcard boot partition

```
bcm2837-rpi-3-b.dtb
bootcode.bin
cmdline.txt
config.txt
fixup.dat
kernel8.img
ramdisk.img
start.elf
```

Follow is log from uart1 console

```
Read File: start.elf, 2869028 (bytes)
Read File: fixup.dat, 6695 (bytes)
MESS:00:00:04.159821:0: brfs: File read: /mfs/sd/config.txt
MESS:00:00:04.164362:0: brfs: File read: 439 bytes
MESS:00:00:04.178455:0: HDMI:EDID error reading EDID block 0 attempt 0
MESS:00:00:04.184532:0: HDMI:EDID error reading EDID block 0 attempt 1
MESS:00:00:04.190776:0: HDMI:EDID error reading EDID block 0 attempt 2
MESS:00:00:04.197026:0: HDMI:EDID error reading EDID block 0 attempt 3
MESS:00:00:04.203277:0: HDMI:EDID error reading EDID block 0 attempt 4
MESS:00:00:04.209526:0: HDMI:EDID error reading EDID block 0 attempt 5
MESS:00:00:04.215776:0: HDMI:EDID error reading EDID block 0 attempt 6
MESS:00:00:04.222026:0: HDMI:EDID error reading EDID block 0 attempt 7
MESS:00:00:04.228276:0: HDMI:EDID error reading EDID block 0 attempt 8
MESS:00:00:04.234526:0: HDMI:EDID error reading EDID block 0 attempt 9
MESS:00:00:04.240539:0: HDMI:EDID giving up on reading EDID block 0
MESS:00:00:04.259153:0: brfs: File read: /mfs/sd/config.txt
MESS:00:00:07.263579:0: HDMI:Setting property pixel encoding to Default
MESS:00:00:07.268498:0: HDMI:Setting property pixel clock type to PAL
MESS:00:00:07.274661:0: HDMI:Setting property content type flag to No data
MESS:00:00:07.281258:0: HDMI:Setting property fuzzy format match to enabled
MESS:00:00:07.288035:0: gpioman: gpioman_get_pin_num: pin LEDS_PWR_OK not defined
MESS:00:00:07.490666:0: gpioman: gpioman_get_pin_num: pin DISPLAY_DSI_PORT not defined
MESS:00:00:07.498109:0: gpioman: gpioman_get_pin_num: pin LEDS_PWR_OK not defined
MESS:00:00:07.504386:0: hdmi: HDMI:hdmi_get_state is deprecated, use hdmi_get_display_state instead
MESS:00:00:07.512869:0: hdmi: HDMI:>>>>>>>>>>>>>Rx sensed, reading EDID<<<<<<<<<<<<<
MESS:00:00:07.520614:0: hdmi: HDMI:EDID error reading EDID block 0 attempt 0
MESS:00:00:07.528347:0: hdmi: HDMI:EDID error reading EDID block 0 attempt 1
MESS:00:00:07.535112:0: hdmi: HDMI:EDID error reading EDID block 0 attempt 2
MESS:00:00:07.541884:0: hdmi: HDMI:EDID error reading EDID block 0 attempt 3
MESS:00:00:07.548655:0: hdmi: HDMI:EDID error reading EDID block 0 attempt 4
MESS:00:00:07.555425:0: hdmi: HDMI:EDID error reading EDID block 0 attempt 5
MESS:00:00:07.562197:0: hdmi: HDMI:EDID error reading EDID block 0 attempt 6
MESS:00:00:07.568967:0: hdmi: HDMI:EDID error reading EDID block 0 attempt 7
MESS:00:00:07.575737:0: hdmi: HDMI:EDID error reading EDID block 0 attempt 8
MESS:00:00:07.582509:0: hdmi: HDMI:EDID error reading EDID block 0 attempt 9
MESS:00:00:07.589042:0: hdmi: HDMI:EDID giving up on reading EDID block 0
MESS:00:00:07.594557:0: hdmi: HDMI: No lookup table for resolution group 0
MESS:00:00:07.601142:0: hdmi: HDMI: hotplug attached with DVI support
MESS:00:00:07.607319:0: hdmi: HDMI:hdmi_get_state is deprecated, use hdmi_get_display_state instead
MESS:00:00:07.616354:0: hdmi: HDMI:EDID error reading EDID block 0 attempt 0
MESS:00:00:07.624089:0: hdmi: HDMI:EDID error reading EDID block 0 attempt 1
MESS:00:00:07.630859:0: hdmi: HDMI:EDID error reading EDID block 0 attempt 2
MESS:00:00:07.637630:0: hdmi: HDMI:EDID error reading EDID block 0 attempt 3
MESS:00:00:07.644402:0: hdmi: HDMI:EDID error reading EDID block 0 attempt 4
MESS:00:00:07.651172:0: hdmi: HDMI:EDID error reading EDID block 0 attempt 5
MESS:00:00:07.657943:0: hdmi: HDMI:EDID error reading EDID block 0 attempt 6
MESS:00:00:07.664714:0: hdmi: HDMI:EDID error reading EDID block 0 attempt 7
MESS:00:00:07.671485:0: hdmi: HDMI:EDID error reading EDID block 0 attempt 8
MESS:00:00:07.678255:0: hdmi: HDMI:EDID error reading EDID block 0 attempt 9
MESS:00:00:07.684790:0: hdmi: HDMI:EDID giving up on reading EDID block 0
MESS:00:00:07.690563:0: hdmi: HDMI: hotplug deassert
MESS:00:00:07.694976:0: hdmi: HDMI: HDMI is currently off
MESS:00:00:07.700097:0: hdmi: HDMI: changing mode to unplugged
MESS:00:00:07.705663:0: hdmi: HDMI:hdmi_get_state is deprecated, use hdmi_get_display_state instead
MESS:00:00:07.715091:0: *** Restart logging
MESS:00:00:07.718337:0: brfs: File read: 439 bytes
MESS:00:00:07.724125:0: brfs: File read: /mfs/sd/cmdline.txt
MESS:00:00:07.728243:0: Read command line from file 'cmdline.txt':
MESS:00:00:07.734125:0: 'rdinit=/linuxrc earlycon=uart8250,mmio32,0x3f215040'
MESS:00:00:07.741212:0: brfs: File read: 51 bytes
MESS:00:00:08.918850:0: brfs: File read: /mfs/sd/kernel8.img
MESS:00:00:08.922812:0: Loading 'kernel8.img' to 0x80000 size 0x12f1200
MESS:00:00:08.929162:0: brfs: File read: 19862016 bytes
MESS:00:00:09.345465:0: brfs: File read: /mfs/sd/ramdisk.img
MESS:00:00:09.349425:0: Loading 'ramdisk.img' to 0x1371200 size 0x69a79e
MESS:00:00:10.158597:0: No kernel trailer - assuming DT-capable
MESS:00:00:10.162820:0: Trying Device Tree file 'bcm2837-rpi-3-b.dtb'
MESS:00:00:10.168983:0: brfs: File read: 6924190 bytes
MESS:00:00:10.176490:0: brfs: File read: /mfs/sd/bcm2837-rpi-3-b.dtb
MESS:00:00:10.181147:0: Loading 'bcm2837-rpi-3-b.dtb' to 0x1371200 size 0x3499
MESS:00:00:10.202930:0: dtdebug: delete_node(/__local_fixups__)
MESS:00:00:10.260787:0: dtparam: uart0_clkrate=48000000
MESS:00:00:10.268418:0: dtdebug: /__overrides__ node not found
MESS:00:00:10.272806:0: Unknown dtparam 'uart0_clkrate' - ignored
MESS:00:00:10.278370:0: brfs: File read: 13465 bytes
MESS:00:00:10.283616:0: brfs: File read: /mfs/sd/config.txt
MESS:00:00:10.293003:0: dterror: No symbols found
MESS:00:00:10.300388:0: dterror: No symbols found
MESS:00:00:11.144576:0: dterror: No symbols found
MESS:00:00:11.224623:0: dterror: No symbols found
MESS:00:00:11.227631:0: dtparam: cam0-pwdn=5
MESS:00:00:11.235846:0: dtdebug: /__overrides__ node not found
MESS:00:00:11.239982:0: Unknown dtparam 'cam0-pwdn' - ignored
MESS:00:00:11.249831:0: dterror: No symbols found
MESS:00:00:11.252851:0: dtparam: cam0-led=6
MESS:00:00:11.260966:0: dtdebug: /__overrides__ node not found
MESS:00:00:11.265116:0: Unknown dtparam 'cam0-led' - ignored
MESS:00:00:11.270484:0: gpioman: gpioman_get_pin_num: pin EMMC_ENABLE not defined
MESS:00:00:11.277714:0: dtparam: arm_freq=1200000000
MESS:00:00:11.286619:0: dtdebug: /__overrides__ node not found
MESS:00:00:11.290744:0: Unknown dtparam 'arm_freq' - ignored
MESS:00:00:11.296160:0: dtparam: core_freq=250000000
MESS:00:00:11.305040:0: dtdebug: /__overrides__ node not found
MESS:00:00:11.309186:0: Unknown dtparam 'core_freq' - ignored
MESS:00:00:11.322837:0: dtdebug: delete_node(/hat)
MESS:00:00:11.334562:0: Device tree loaded to 0x2e961700 (size 0x3882)
MESS:00:00:11.341167:0: uart: Set PL011 baud rate to 103448.300000 Hz
MESS:00:00:11.347453:0: uart: Baud rate change done...
MESS:00:00:11.350885:0: uart: Baud rate[    0.000000] Booting Linux on physical CPU 0x0000000000 [0x410fd034]
[    0.000000] Linux version 5.0.0-rc4-28376-gf17b5f06cb92 (jun@ubuntu) (gcc version 7.3.0 (Ubuntu/Linaro 7.3.0-27ubuntu1~18.04)) #1 SMP PREEMPT Mon Jan 28 07:16:06 PST 2019
[    0.000000] Machine model: Raspberry Pi 3 Model B Rev 1.2
[    0.000000] earlycon: uart8250 at MMIO32 0x000000003f215040 (options '')
[    0.000000] printk: bootconsole [uart8250] enabled
[    0.000000] efi: Getting EFI parameters from FDT:
[    0.000000] efi: UEFI not found.
[    0.000000] cma: Reserved 32 MiB at 0x0000000039400000
[    0.000000] NUMA: No NUMA configuration found
[    0.000000] NUMA: Faking a node at [mem 0x0000000000000000-0x000000003b3fffff]
[    0.000000] NUMA: NODE_DATA [mem 0x3920f840-0x39210fff]
[    0.000000] Zone ranges:
[    0.000000]   DMA32    [mem 0x0000000000000000-0x000000003b3fffff]
[    0.000000]   Normal   empty
[    0.000000] Movable zone start for each node
[    0.000000] Early memory node ranges
[    0.000000]   node   0: [mem 0x0000000000000000-0x000000003b3fffff]
[    0.000000] Initmem setup node 0 [mem 0x0000000000000000-0x000000003b3fffff]
[    0.000000] random: get_random_bytes called from start_kernel+0xa8/0x408 with crng_init=0
[    0.000000] percpu: Embedded 23 pages/cpu @(____ptrval____) s55960 r8192 d30056 u94208
[    0.000000] Detected VIPT I-cache on CPU0
[    0.000000] CPU features: detected: ARM erratum 845719
[    0.000000] CPU features: detected: ARM erratum 843419
[    0.000000] Built 1 zonelists, mobility grouping on.  Total pages: 238896
[    0.000000] Policy zone: DMA32
[    0.000000] Kernel command line: bcm2708_fb.fbwidth=656 bcm2708_fb.fbheight=416 bcm2708_fb.fbswap=1 dma.dmachans=0x7f35 bcm2709.boardrev=0x2a02082 bcm2709.serial=0xf2c396f2 bcm2709.uart_clock=48000000 smsc95xx.macaddr=B8:27:EB:C3:96:F2 vc_mem.mem_base=0x3ec00000 vc_mem.mem_size=0x40000000  rdinit=/linuxrc earlycon=uart8250,mmio32,0x3f215040
[    0.000000] Memory: 890656K/970752K available (11004K kernel code, 1604K rwdata, 5332K rodata, 1408K init, 383K bss, 47328K reserved, 32768K cma-reserved)
[    0.000000] SLUB: HWalign=64, Order=0-3, MinObjects=0, CPUs=4, Nodes=1
[    0.000000] rcu: Preemptible hierarchical RCU implementation.
[    0.000000] rcu:     RCU restricting CPUs from NR_CPUS=64 to nr_cpu_ids=4.
[    0.000000]  Tasks RCU enabled.
[    0.000000] rcu: RCU calculated value of scheduler-enlistment delay is 25 jiffies.
[    0.000000] rcu: Adjusting geometry for rcu_fanout_leaf=16, nr_cpu_ids=4
[    0.000000] NR_IRQS: 64, nr_irqs: 64, preallocated irqs: 0
[    0.000000] arch_timer: cp15 timer(s) running at 19.20MHz (phys).
[    0.000000] clocksource: arch_sys_counter: mask: 0xffffffffffffff max_cycles: 0x46d987e47, max_idle_ns: 440795202767 ns
[    0.000003] sched_clock: 56 bits at 19MHz, resolution 52ns, wraps every 4398046511078ns
[    0.008233] Console: colour dummy device 80x25
[    0.012723] printk: console [tty0] enabled
[    0.016865] printk: bootconsole [uart8250] disabled
[    0.000000] Booting Linux on physical CPU 0x0000000000 [0x410fd034]
[    0.000000] Linux version 5.0.0-rc4-28376-gf17b5f06cb92 (jun@ubuntu) (gcc version 7.3.0 (Ubuntu/Linaro 7.3.0-27ubuntu1~18.04)) #1 SMP PREEMPT Mon Jan 28 07:16:06 PST 2019
[    0.000000] Machine model: Raspberry Pi 3 Model B Rev 1.2
[    0.000000] earlycon: uart8250 at MMIO32 0x000000003f215040 (options '')
[    0.000000] printk: bootconsole [uart8250] enabled
[    0.000000] efi: Getting EFI parameters from FDT:
[    0.000000] efi: UEFI not found.
[    0.000000] cma: Reserved 32 MiB at 0x0000000039400000
[    0.000000] NUMA: No NUMA configuration found
[    0.000000] NUMA: Faking a node at [mem 0x0000000000000000-0x000000003b3fffff]
[    0.000000] NUMA: NODE_DATA [mem 0x3920f840-0x39210fff]
[    0.000000] Zone ranges:
[    0.000000]   DMA32    [mem 0x0000000000000000-0x000000003b3fffff]
[    0.000000]   Normal   empty
[    0.000000] Movable zone start for each node
[    0.000000] Early memory node ranges
[    0.000000]   node   0: [mem 0x0000000000000000-0x000000003b3fffff]
[    0.000000] Initmem setup node 0 [mem 0x0000000000000000-0x000000003b3fffff]
[    0.000000] random: get_random_bytes called from start_kernel+0xa8/0x408 with crng_init=0
[    0.000000] percpu: Embedded 23 pages/cpu @(____ptrval____) s55960 r8192 d30056 u94208
[    0.000000] Detected VIPT I-cache on CPU0
[    0.000000] CPU features: detected: ARM erratum 845719
[    0.000000] CPU features: detected: ARM erratum 843419
[    0.000000] Built 1 zonelists, mobility grouping on.  Total pages: 238896
[    0.000000] Policy zone: DMA32
[    0.000000] Kernel command line: bcm2708_fb.fbwidth=656 bcm2708_fb.fbheight=416 bcm2708_fb.fbswap=1 dma.dmachans=0x7f35 bcm2709.boardrev=0x2a02082 bcm2709.serial=0xf2c396f2 bcm2709.uart_clock=48000000 smsc95xx.macaddr=B8:27:EB:C3:96:F2 vc_mem.mem_base=0x3ec00000 vc_mem.mem_size=0x40000000  rdinit=/linuxrc earlycon=uart8250,mmio32,0x3f215040
[    0.000000] Memory: 890656K/970752K available (11004K kernel code, 1604K rwdata, 5332K rodata, 1408K init, 383K bss, 47328K reserved, 32768K cma-reserved)
[    0.000000] SLUB: HWalign=64, Order=0-3, MinObjects=0, CPUs=4, Nodes=1
[    0.000000] rcu: Preemptible hierarchical RCU implementation.
[    0.000000] rcu:     RCU restricting CPUs from NR_CPUS=64 to nr_cpu_ids=4.
[    0.000000]  Tasks RCU enabled.
[    0.000000] rcu: RCU calculated value of scheduler-enlistment delay is 25 jiffies.
[    0.000000] rcu: Adjusting geometry for rcu_fanout_leaf=16, nr_cpu_ids=4
[    0.000000] NR_IRQS: 64, nr_irqs: 64, preallocated irqs: 0
[    0.000000] arch_timer: cp15 timer(s) running at 19.20MHz (phys).
[    0.000000] clocksource: arch_sys_counter: mask: 0xffffffffffffff max_cycles: 0x46d987e47, max_idle_ns: 440795202767 ns
[    0.000003] sched_clock: 56 bits at 19MHz, resolution 52ns, wraps every 4398046511078ns
[    0.008233] Console: colour dummy device 80x25
[    0.012723] printk: console [tty0] enabled
[    0.016865] printk: bootconsole [uart8250] disabled
[    0.021872] Calibrating delay loop (skipped), value calculated using timer frequency.. 38.40 BogoMIPS (lpj=76800)
[    0.021890] pid_max: default: 32768 minimum: 301
[    0.021960] LSM: Security Framework initializing
[    0.022852] Dentry cache hash table entries: 131072 (order: 8, 1048576 bytes)
[    0.023296] Inode-cache hash table entries: 65536 (order: 7, 524288 bytes)
[    0.023335] Mount-cache hash table entries: 2048 (order: 2, 16384 bytes)
[    0.023360] Mountpoint-cache hash table entries: 2048 (order: 2, 16384 bytes)
[    0.045872] ASID allocator initialised with 32768 entries
[    0.053864] rcu: Hierarchical SRCU implementation.
[    0.062814] EFI services will not be available.
[    0.069888] smp: Bringing up secondary CPUs ...
[    0.101970] Detected VIPT I-cache on CPU1
[    0.102009] CPU1: Booted secondary processor 0x0000000001 [0x410fd034]
[    0.134006] Detected VIPT I-cache on CPU2
[    0.134028] CPU2: Booted secondary processor 0x0000000002 [0x410fd034]
[    0.166054] Detected VIPT I-cache on CPU3
[    0.166074] CPU3: Booted secondary processor 0x0000000003 [0x410fd034]
[    0.166137] smp: Brought up 1 node, 4 CPUs
[    0.166185] SMP: Total of 4 processors activated.
[    0.166195] CPU features: detected: 32-bit EL0 Support
[    0.166205] CPU features: detected: CRC32 instructions
[    0.166497] CPU: All CPU(s) started at EL2
[    0.166519] alternatives: patching kernel code
[    0.167496] devtmpfs: initialized
[    0.171287] clocksource: jiffies: mask: 0xffffffff max_cycles: 0xffffffff, max_idle_ns: 7645041785100000 ns
[    0.171339] futex hash table entries: 1024 (order: 4, 65536 bytes)
[    0.172451] pinctrl core: initialized pinctrl subsystem
[    0.173975] DMI not present or invalid.
[    0.174481] NET: Registered protocol family 16
[    0.175840] audit: initializing netlink subsys (disabled)
[    0.175962] audit: type=2000 audit(0.168:1): state=initialized audit_enabled=0 res=1
[    0.177318] cpuidle: using governor menu
[    0.177810] vdso: 2 pages (1 code @ (____ptrval____), 1 data @ (____ptrval____))
[    0.177831] hw-breakpoint: found 6 breakpoint and 4 watchpoint registers.
[    0.178837] DMA: preallocated 256 KiB pool for atomic allocations
[    0.180064] Serial: AMBA PL011 UART driver
[    0.199839] HugeTLB registered 1.00 GiB page size, pre-allocated 0 pages
[    0.199865] HugeTLB registered 32.0 MiB page size, pre-allocated 0 pages
[    0.199878] HugeTLB registered 2.00 MiB page size, pre-allocated 0 pages
[    0.199890] HugeTLB registered 64.0 KiB page size, pre-allocated 0 pages
[    0.200305] cryptd: max_cpu_qlen set to 1000
[    0.201034] ACPI: Interpreter disabled.
[    0.202228] vgaarb: loaded
[    0.202734] SCSI subsystem initialized
[    0.203256] usbcore: registered new interface driver usbfs
[    0.203310] usbcore: registered new interface driver hub
[    0.203373] usbcore: registered new device driver usb
[    0.203581] usb_phy_generic phy: phy supply vcc not found, using dummy regulator
[    0.203637] usb_phy_generic phy: Linked as a consumer to regulator.0
[    0.204423] pps_core: LinuxPPS API ver. 1 registered
[    0.204441] pps_core: Software ver. 5.3.6 - Copyright 2005-2007 Rodolfo Giometti <giometti@linux.it>
[    0.204477] PTP clock support registered
[    0.204629] EDAC MC: Ver: 3.0.0
[    0.205701] Advanced Linux Sound Architecture Driver Initialized.
[    0.206609] clocksource: Switched to clocksource arch_sys_counter
[    0.206776] VFS: Disk quotas dquot_6.6.0
[    0.206828] VFS: Dquot-cache hash table entries: 512 (order 0, 4096 bytes)
[    0.207018] pnp: PnP ACPI: disabled
[    0.213111] NET: Registered protocol family 2
[    0.213581] tcp_listen_portaddr_hash hash table entries: 512 (order: 1, 8192 bytes)
[    0.213699] TCP established hash table entries: 8192 (order: 4, 65536 bytes)
[    0.213776] TCP bind hash table entries: 8192 (order: 5, 131072 bytes)
[    0.213888] TCP: Hash tables configured (established 8192 bind 8192)
[    0.214061] UDP hash table entries: 512 (order: 2, 16384 bytes)
[    0.214095] UDP-Lite hash table entries: 512 (order: 2, 16384 bytes)
[    0.214219] NET: Registered protocol family 1
[    0.214579] RPC: Registered named UNIX socket transport module.
[    0.214591] RPC: Registered udp transport module.
[    0.214658] RPC: Registered tcp transport module.
[    0.214668] RPC: Registered tcp NFSv4.1 backchannel transport module.
[    0.214831] Unpacking initramfs...
[    0.478052] Freeing initrd memory: 6760K
[    0.478968] hw perfevents: enabled with armv8_cortex_a53 PMU driver, 7 counters available
[    0.479099] kvm [1]: 8-bit VMID
[    0.479113] kvm [1]: IPA Size Limit: 40bits
[    0.479713] kvm [1]: Hyp mode initialized successfully
[    0.492679] Initialise system trusted keyrings
[    0.492858] workingset: timestamp_bits=44 max_order=18 bucket_order=0
[    0.499210] squashfs: version 4.0 (2009/01/31) Phillip Lougher
[    0.499876] NFS: Registering the id_resolver key type
[    0.499908] Key type id_resolver registered
[    0.499918] Key type id_legacy registered
[    0.499933] nfs4filelayout_init: NFSv4 File Layout Driver Registering...
[    0.500104] 9p: Installing v9fs 9p2000 file system support
[    0.544753] Key type asymmetric registered
[    0.544777] Asymmetric key parser 'x509' registered
[    0.544846] Block layer SCSI generic (bsg) driver version 0.4 loaded (major 245)
[    0.544864] io scheduler mq-deadline registered
[    0.544874] io scheduler kyber registered
[    0.553053] EINJ: ACPI disabled.
[    0.562970] Serial: 8250/16550 driver, 4 ports, IRQ sharing enabled
[    0.564853] 3f215040.serial: ttyS1 at MMIO 0x0 (irq = 61, base_baud = 31250000) is a 16550
[    1.343326] printk: console [ttyS1] enabled
[    1.348799] SuperH (H)SCI(F) driver initialized
[    1.353784] msm_serial: driver initialized
[    1.358802] cacheinfo: Unable to detect cache hierarchy for CPU 0
[    1.372371] loop: module loaded
[    1.379540] libphy: Fixed MDIO Bus: probed
[    1.384244] tun: Universal TUN/TAP device driver, 1.6
[    1.390294] thunder_xcv, ver 1.0
[    1.393637] thunder_bgx, ver 1.0
[    1.396964] nicpf, ver 1.0
[    1.400171] hclge is initializing
[    1.403548] hns3: Hisilicon Ethernet Network Driver for Hip08 Family - version
[    1.410883] hns3: Copyright (c) 2017 Huawei Corporation.
[    1.416336] e1000e: Intel(R) PRO/1000 Network Driver - 3.2.6-k
[    1.422264] e1000e: Copyright(c) 1999 - 2015 Intel Corporation.
[    1.428315] igb: Intel(R) Gigabit Ethernet Network Driver - version 5.4.0-k
[    1.435388] igb: Copyright (c) 2007-2014 Intel Corporation.
[    1.441078] igbvf: Intel(R) Gigabit Virtual Function Network Driver - version 2.4.0-k
[    1.449035] igbvf: Copyright (c) 2009 - 2012 Intel Corporation.
[    1.455358] sky2: driver version 1.30
[    1.459737] VFIO - User Level meta-driver version: 0.3
[    1.466284] ehci_hcd: USB 2.0 'Enhanced' Host Controller (EHCI) Driver
[    1.472942] ehci-pci: EHCI PCI platform driver
[    1.477497] ehci-platform: EHCI generic platform driver
[    1.482927] ehci-orion: EHCI orion driver
[    1.487083] ehci-exynos: EHCI EXYNOS driver
[    1.491400] ohci_hcd: USB 1.1 'Open' Host Controller (OHCI) Driver
[    1.497698] ohci-pci: OHCI PCI platform driver
[    1.502262] ohci-platform: OHCI generic platform driver
[    1.507662] ohci-exynos: OHCI EXYNOS driver
[    1.512330] usbcore: registered new interface driver usb-storage
[    1.521044] i2c /dev entries driver
[    1.527852] bcm2835-wdt 3f100000.watchdog: Broadcom BCM2835 watchdog timer
[    1.535953] sdhci: Secure Digital Host Controller Interface driver
[    1.542251] sdhci: Copyright(c) Pierre Ossman
[    1.547119] Synopsys Designware Multimedia Card Interface Driver
[    1.554175] sdhost-bcm2835 3f202000.mmc: unable to initialise DMA channel. Falling back to PIO
[    1.644100] sdhost-bcm2835 3f202000.mmc: loaded - DMA disabled
[    1.650178] sdhci-pltfm: SDHCI platform and OF driver helper
[    1.657495] ledtrig-cpu: registered to indicate activity on CPUs
[    1.664899] usbcore: registered new interface driver usbhid
[    1.670584] usbhid: USB HID core driver
[    1.674977] bcm2835-mbox 3f00b880.mailbox: mailbox enabled
[    1.683341] NET: Registered protocol family 17
[    1.688040] 9pnet: Installing 9P2000 support
[    1.692436] Key type dns_resolver registered
[    1.697494] registered taskstats version 1
[    1.701668] Loading compiled-in X.509 certificates
[    1.710776] 3f201000.serial: ttyAMA0 at MMIO 0x3f201000 (irq = 66, base_baud = 0) is a PL011 rev2
[    1.719988] serial serial0: tty port ttyAMA0 registered
[    1.734324] raspberrypi-firmware soc:firmware: Attached to firmware from 2019-01-10 14:58
[    1.773027] dwc2 3f980000.usb: 3f980000.usb supply vusb_d not found, using dummy regulator
[    1.781650] dwc2 3f980000.usb: Linked as a consumer to regulator.0
[    1.787969] dwc2 3f980000.usb: 3f980000.usb supply vusb_a not found, using dummy regulator
[    1.803183] mmc0: host does not support reading read-only switch, assuming write-enable
[    1.814020] mmc0: new high speed SDHC card at address aaaa
[    1.820711] mmcblk0: mmc0:aaaa SL08G 7.40 GiB
[    1.830774]  mmcblk0: p1 p2
[    1.847688] dwc2 3f980000.usb: dwc2_check_params: Invalid parameter lpm=1
[    1.854604] dwc2 3f980000.usb: dwc2_check_params: Invalid parameter lpm_clock_gating=1
[    1.862650] dwc2 3f980000.usb: dwc2_check_params: Invalid parameter besl=1
[    1.869633] dwc2 3f980000.usb: dwc2_check_params: Invalid parameter hird_threshold_en=1
[    1.878507] dwc2 3f980000.usb: DWC OTG Controller
[    1.883307] dwc2 3f980000.usb: new USB bus registered, assigned bus number 1
[    1.890498] dwc2 3f980000.usb: irq 41, io mem 0x3f980000
[    1.896403] hub 1-0:1.0: USB hub found
[    1.900233] hub 1-0:1.0: 1 port detected
[    1.907643] sdhci-iproc 3f300000.sdhci: allocated mmc-pwrseq
[    1.945070] mmc1: SDHCI controller on 3f300000.sdhci [3f300000.sdhci] using PIO
[    1.955650] hctosys: unable to open rtc device (rtc0)
[    1.961059] ALSA device list:
[    1.964231]   No soundcards found.
[    1.969491] Freeing unused kernel memory: 1408K
[    1.982553] mmc1: queuing unknown CIS tuple 0x80 (2 bytes)
[    1.989764] mmc1: queuing unknown CIS tuple 0x80 (3 bytes)
[    1.995370] Run /linuxrc as init process
[    1.996988] mmc1: queuing unknown CIS tuple 0x80 (3 bytes)
[    2.008060] mmc1: queuing unknown CIS tuple 0x80 (7 bytes)
[    2.068424] random: fast init done
[root@chenjun]#[    2.112207] mmc1: new high speed SDIO card at address 0001
[    2.298626] usb 1-1: new high-speed USB device number 2 using dwc2
[    2.511198] hub 1-1:1.0: USB hub found
[    2.515117] hub 1-1:1.0: 5 ports detected
[    2.806648] usb 1-1.1: new high-speed USB device number 3 using dwc2
[    4.324633] random: crng init done

[root@chenjun]#
[root@chenjun]#
[root@chenjun]#
[root@chenjun]#uname -a
Linux chenjun 5.0.0-rc4-28376-gf17b5f06cb92 #1 SMP PREEMPT Mon Jan 28 07:16:06 PST 2019 aarch64 GNU/Linux
[root@chenjun]#ls
bin      etc      lib      mnt      root     sys      usr
dev      init     linuxrc  proc     sbin     tmp      var
```
