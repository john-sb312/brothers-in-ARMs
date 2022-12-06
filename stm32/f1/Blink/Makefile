
# DEFINES=

# OBJS =main.o
# OBJS+=startup.o

# TOOLCHAIN=arm-none-eabi-
# CC=$(TOOLCHAIN)gcc

# ARMFLAGS=-mcpu=cortex-m3 -mfloat-abi=soft -mthumb
# CFLAGS=-nostdlib -Wall $(DEFINES) $(ARMFLAGS)
# LFLAGS=-T linker.ld

include ../Makefile


# OpenOCD upload
FLASH_OCD =-c 'halt'
FLASH_OCD+=-c 'sleep 2'
FLASH_OCD+=-c 'reset'
FLASH_OCD+=-c 'sleep 2'
FLASH_OCD+=-c 'flash write_image erase $(PROJECT).bin 0x8000000'
FLASH_OCD+=-c 'sleep 2'
FLASH_OCD+=-c 'shutdown'


# Black Magic Probe upload




%.o: %.s
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

bin: $(PROJECT).bin
$(PROJECT).bin: $(PROJECT).elf
	$(TOOLCHAIN)objcopy -O binary $< $@

elf: $(PROJECT).elf
$(PROJECT).elf: $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^

flash: $(PROJECT).bin
	sudo openocd -f interface/picoprobe.cfg -f target/stm32f1x.cfg -c init $(FLASH)

.PHONY: clean
clean:
	rm -f *.o *.elf *.bin