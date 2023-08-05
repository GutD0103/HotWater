################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/HAL/adc.c \
../Core/Src/HAL/flash.c \
../Core/Src/HAL/gpio.c \
../Core/Src/HAL/timer.c \
../Core/Src/HAL/uart.c 

C_DEPS += \
./Core/Src/HAL/adc.d \
./Core/Src/HAL/flash.d \
./Core/Src/HAL/gpio.d \
./Core/Src/HAL/timer.d \
./Core/Src/HAL/uart.d 

OBJS += \
./Core/Src/HAL/adc.o \
./Core/Src/HAL/flash.o \
./Core/Src/HAL/gpio.o \
./Core/Src/HAL/timer.o \
./Core/Src/HAL/uart.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/HAL/%.o Core/Src/HAL/%.su Core/Src/HAL/%.cyclo: ../Core/Src/HAL/%.c Core/Src/HAL/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-HAL

clean-Core-2f-Src-2f-HAL:
	-$(RM) ./Core/Src/HAL/adc.cyclo ./Core/Src/HAL/adc.d ./Core/Src/HAL/adc.o ./Core/Src/HAL/adc.su ./Core/Src/HAL/flash.cyclo ./Core/Src/HAL/flash.d ./Core/Src/HAL/flash.o ./Core/Src/HAL/flash.su ./Core/Src/HAL/gpio.cyclo ./Core/Src/HAL/gpio.d ./Core/Src/HAL/gpio.o ./Core/Src/HAL/gpio.su ./Core/Src/HAL/timer.cyclo ./Core/Src/HAL/timer.d ./Core/Src/HAL/timer.o ./Core/Src/HAL/timer.su ./Core/Src/HAL/uart.cyclo ./Core/Src/HAL/uart.d ./Core/Src/HAL/uart.o ./Core/Src/HAL/uart.su

.PHONY: clean-Core-2f-Src-2f-HAL

