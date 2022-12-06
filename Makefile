
TOOLCHAIN = arm-none-eabi-
CC = $(TOOLCHAIN)gcc
GDB = $(TOOLCHAIN)gdb
CPUFLAGS = -mcpu=cortex-m3 -mthumb
CFLAGS = -Wall -Wextra -g3 -O0 -MD $(CPUFLAGS)
LDFLAGS = $(CPUFLAGS)
LDLIBS = -lc -lno

PROJECT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
SCRIPT_DIR	:=$(PROJECT_DIR)/scripts


all:


%.flash: %.elf
	BMP_PORT ?= /dev/ttyACM0
	@printf "  BMP $(BMP_PORT) $(*).elf (flash)\n"
	$(GDB) -nx --batch \
	           -ex 'target extended-remote $(BMP_PORT)' \
	           -x bmp_flash.scr \
	           $(*).elf

burn_ocd: