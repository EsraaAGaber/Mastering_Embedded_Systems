################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32f103C6_DRIVERS/KEYPAD_DRIVER/keypad.c 

OBJS += \
./STM32f103C6_DRIVERS/KEYPAD_DRIVER/keypad.o 

C_DEPS += \
./STM32f103C6_DRIVERS/KEYPAD_DRIVER/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
STM32f103C6_DRIVERS/KEYPAD_DRIVER/keypad.o: ../STM32f103C6_DRIVERS/KEYPAD_DRIVER/keypad.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Mastering_embeded_sytem/DRIVERS/STM32f103C6_DRIVERS/LCD_DRIVER" -I"E:/Mastering_embeded_sytem/DRIVERS/STM32f103C6_DRIVERS/KEYPAD_DRIVER" -I"E:/Mastering_embeded_sytem/DRIVERS/STM32f103C6_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32f103C6_DRIVERS/KEYPAD_DRIVER/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

