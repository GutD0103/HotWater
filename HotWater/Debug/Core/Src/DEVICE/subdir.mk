################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/DEVICE/flow_meter.c \
../Core/Src/DEVICE/hotwater.c \
../Core/Src/DEVICE/ntc.c \
../Core/Src/DEVICE/port.c \
../Core/Src/DEVICE/water_level.c 

C_DEPS += \
./Core/Src/DEVICE/flow_meter.d \
./Core/Src/DEVICE/hotwater.d \
./Core/Src/DEVICE/ntc.d \
./Core/Src/DEVICE/port.d \
./Core/Src/DEVICE/water_level.d 

OBJS += \
./Core/Src/DEVICE/flow_meter.o \
./Core/Src/DEVICE/hotwater.o \
./Core/Src/DEVICE/ntc.o \
./Core/Src/DEVICE/port.o \
./Core/Src/DEVICE/water_level.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/DEVICE/%.o Core/Src/DEVICE/%.su Core/Src/DEVICE/%.cyclo: ../Core/Src/DEVICE/%.c Core/Src/DEVICE/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-DEVICE

clean-Core-2f-Src-2f-DEVICE:
	-$(RM) ./Core/Src/DEVICE/flow_meter.cyclo ./Core/Src/DEVICE/flow_meter.d ./Core/Src/DEVICE/flow_meter.o ./Core/Src/DEVICE/flow_meter.su ./Core/Src/DEVICE/hotwater.cyclo ./Core/Src/DEVICE/hotwater.d ./Core/Src/DEVICE/hotwater.o ./Core/Src/DEVICE/hotwater.su ./Core/Src/DEVICE/ntc.cyclo ./Core/Src/DEVICE/ntc.d ./Core/Src/DEVICE/ntc.o ./Core/Src/DEVICE/ntc.su ./Core/Src/DEVICE/port.cyclo ./Core/Src/DEVICE/port.d ./Core/Src/DEVICE/port.o ./Core/Src/DEVICE/port.su ./Core/Src/DEVICE/water_level.cyclo ./Core/Src/DEVICE/water_level.d ./Core/Src/DEVICE/water_level.o ./Core/Src/DEVICE/water_level.su

.PHONY: clean-Core-2f-Src-2f-DEVICE

