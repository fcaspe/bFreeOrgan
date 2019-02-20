
TARGET=main
STMDIR=./src

###################################################

CC=arm-none-eabi-gcc
LD=arm-none-eabi-gcc
AR=arm-none-eabi-ar
AS=arm-none-eabi-as
CP=arm-none-eabi-objcopy
OD=arm-none-eabi-objdump
SE=arm-none-eabi-size
SF=st-flash

###################################################

SRCDIR = $(STMDIR)/StdPeriph_Driver/src \
		 $(STMDIR)/src/ \

vpath %.c $(SRCDIR)		 
vpath %.cpp $(SRCDIR)

STARTUPDIR = $(STMDIR)/startup
vpath %.S $(STARTUPDIR)

INC_DIRS = $(STMDIR)/StdPeriph_Driver/inc
INC_DIRS += $(STMDIR)/CMSIS/device
INC_DIRS += $(STMDIR)/CMSIS/core
INC_DIRS += $(STMDIR)/inc

INCLUDE = $(addprefix -I,$(INC_DIRS))

###################################################

CFLAGS  = -g -O0 -Wall -T$(STMDIR)/LinkerScript.ld
CFLAGS += -mthumb -march=armv7e-m
CFLAGS += -DUSE_STDPERIPH_DRIVER

###################################################

SRCS =  main.c \
		boot.c \
		midi.c \
		synth.c \
		syscalls.c \
		timer.c

SRCS += stm32f4xx_rcc.c \
	stm32f4xx_gpio.c \
	stm32f4xx_dma.c \
	stm32f4xx_tim.c \
	stm32f4xx_spi.c \
	stm32f4xx_usart.c \
	stm32f4xx_adc.c \
	stm32f4xx_exti.c \
	stm32f4xx_syscfg.c \
	misc.c \
	system_stm32f4xx.c \
	startup_stm32f4xx.S

###################################################

.PHONY: $(TARGET)

$(TARGET): $(TARGET).elf

$(TARGET).elf: $(SRCS)
	$(CC) $(INCLUDE) $(CFLAGS) $^ -o $@
	$(CP) -O ihex $(TARGET).elf $(TARGET).hex
	$(CP) -O binary $(TARGET).elf $(TARGET).bin

clean:
	rm -f *.o $(TARGET).elf $(TARGET).hex $(TARGET).bin

flash: 
	$(SF) write $(TARGET).bin 0x08000000
