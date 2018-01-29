################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/boot.c \
../src/main.c \
../src/midi.c \
../src/serial.c \
../src/synth.c \
../src/synth_tables.c \
../src/syscalls.c \
../src/system_stm32f4xx.c \
../src/timer.c 

OBJS += \
./src/boot.o \
./src/main.o \
./src/midi.o \
./src/serial.o \
./src/synth.o \
./src/synth_tables.o \
./src/syscalls.o \
./src/system_stm32f4xx.o \
./src/timer.o 

C_DEPS += \
./src/boot.d \
./src/main.d \
./src/midi.d \
./src/serial.d \
./src/synth.d \
./src/synth_tables.d \
./src/syscalls.d \
./src/system_stm32f4xx.d \
./src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F407VGTx -DSTM32F4 -DSTM32F4DISCOVERY -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F40XX -DSTM32F40_41xxx -I"/home/franco/uni/Digitales 3/PROY FINAL/trankasynth/inc" -I"/home/franco/uni/Digitales 3/PROY FINAL/trankasynth/StdPeriph_Driver/inc" -I"/home/franco/uni/Digitales 3/PROY FINAL/trankasynth/Utilities" -I"/home/franco/uni/Digitales 3/PROY FINAL/trankasynth/CMSIS/core" -I"/home/franco/uni/Digitales 3/PROY FINAL/trankasynth/CMSIS/device" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


