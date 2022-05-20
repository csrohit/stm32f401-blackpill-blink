# Author: Rohit Nimkar

# Name of your current project
PROJ_NAME = interrupt
# PROJ_NAME = $(shell basename $(CURDIR))

# Directory containing all CMSIS relevent source code
CMSIS_DIR = cmsis

OPENOCD_BASE = 

LINKER_SCRIPT = cmsis/src/STM32F401CCUX_FLASH.ld

##### Toolchain #####
TRIPLE  = 	arm-none-eabi
CC 		=	${TRIPLE}-gcc
LD 		= 	${TRIPLE}-ld
AS 		= 	${TRIPLE}-as
GDB 	= 	${TRIPLE}-gdb
OBJCOPY =  	${TRIPLE}-objcopy

##### Compiler options #####
CFLAGS = -g -Wall -T$(LINKER_SCRIPT)
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4
CFLAGS += -mfloat-abi=soft -mfpu=fpv4-sp-d16 --specs=nosys.specs

##### Project specific libraries #####
SRC_FILES += src/*.c cmsis/src/*.c cmsis/src/*.s
CFLAGS += -Iinc -Icmsis/inc


all:  $(PROJ_NAME).bin 

##### Flash code to board using OpenOCD #####
flash: $(PROJ_NAME).bin
	openocd -d2 -s $(OPENOCD_BASE)/scripts -f interface/stlink.cfg -c "transport select hla_swd" -f target/stm32f4x.cfg -c "program {build/$(PROJ_NAME).elf}  verify reset; shutdown;"


##### Erase all flash memory from board using OpenOCD #####
erase:
	openocd -f interface/stlink.cfg -c "transport select hla_swd" -f target/stm32f4x.cfg -c "init; reset halt; stm32f4x mass_erase 0; exit"

##### Print out disassembly of specified function using GDB #####
##### USAGE EXAMPLE: 	make disass FUNC=main 				#####
disass: $(PROJ_NAME).elf
	$(GDB) $^ -batch -ex 'disass /r $(FUNC)'

clean:
	rm -f build/$(PROJ_NAME).bin build/$(PROJ_NAME).elf

$(PROJ_NAME).elf: $(SRC_FILES)
	$(CC) $(CFLAGS) -o build/$@ $^

$(PROJ_NAME).bin: $(PROJ_NAME).elf
	$(OBJCOPY) -O binary build/$^ build/$@

