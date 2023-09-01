################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/APP/water_out.c 

C_DEPS += \
./Core/Src/APP/water_out.d 

OBJS += \
./Core/Src/APP/water_out.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/APP/%.o Core/Src/APP/%.su Core/Src/APP/%.cyclo: ../Core/Src/APP/%.c Core/Src/APP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-APP

clean-Core-2f-Src-2f-APP:
	-$(RM) ./Core/Src/APP/water_out.cyclo ./Core/Src/APP/water_out.d ./Core/Src/APP/water_out.o ./Core/Src/APP/water_out.su

.PHONY: clean-Core-2f-Src-2f-APP

