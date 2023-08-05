################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Lib/RingBuffer/RingBuffer.c 

C_DEPS += \
./Core/Lib/RingBuffer/RingBuffer.d 

OBJS += \
./Core/Lib/RingBuffer/RingBuffer.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Lib/RingBuffer/%.o Core/Lib/RingBuffer/%.su Core/Lib/RingBuffer/%.cyclo: ../Core/Lib/RingBuffer/%.c Core/Lib/RingBuffer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Lib-2f-RingBuffer

clean-Core-2f-Lib-2f-RingBuffer:
	-$(RM) ./Core/Lib/RingBuffer/RingBuffer.cyclo ./Core/Lib/RingBuffer/RingBuffer.d ./Core/Lib/RingBuffer/RingBuffer.o ./Core/Lib/RingBuffer/RingBuffer.su

.PHONY: clean-Core-2f-Lib-2f-RingBuffer

