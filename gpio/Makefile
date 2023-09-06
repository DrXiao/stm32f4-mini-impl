# User
INCLUDE_DIR=include
SRC_DIR=src

# Target
BUILD_DIR=build
EXECTUABLE=$(BUILD_DIR)/stm32_executable.elf
BIN_IMAGE=$(BUILD_DIR)/stm32_bin_image.bin
DISASM=$(BUILD_DIR)/stm32_disasm.list

# Cross Compiler
CROSS_CIMPILE=arm-none-eabi-
CC=$(CROSS_CIMPILE)gcc
OBJCOPY=$(CROSS_CIMPILE)objcopy
OBJDUMP=$(CROSS_CIMPILE)objdump

# Flags
CFLAGS=-g -mlittle-endian -mthumb -O0 \
	-mcpu=cortex-m4 \
	--specs=nano.specs \
	--specs=nosys.specs

# Libraries
CFLAGS+=-I./ -I./$(INCLUDE_DIR)

# stm32-flash
CFLAGS+=-Wl,-T,stm32_flash.ld


# Source code
SRC+=$(shell ls $(SRC_DIR)/*)


all: $(BUILD_DIR) $(BIN_IMAGE) $(DISASM)

$(BUILD_DIR):
	mkdir $@

$(BIN_IMAGE): $(EXECTUABLE)
	$(OBJCOPY) -O binary $^ $@

$(STARTUP_OBJ): $(STARTUP_ASM)
	$(CC) $(CFLAGS) $^ -c $(STARTUP_ASM)

$(EXECTUABLE): $(SRC) $(STARTUP_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(DISASM): $(EXECTUABLE)
	$(OBJDUMP) -S $^ > $@

clean:
	rm -rf $(BUILD_DIR)

flash:
	st-flash write $(BIN_IMAGE) 0x8000000

debug:
	screen -c config/screenrc


.PHONY:all clean flash
