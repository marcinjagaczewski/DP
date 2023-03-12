################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Drivers/dp_switch.c \
../Core/Src/Drivers/equalizer.c 

OBJS += \
./Core/Src/Drivers/dp_switch.o \
./Core/Src/Drivers/equalizer.o 

C_DEPS += \
./Core/Src/Drivers/dp_switch.d \
./Core/Src/Drivers/equalizer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Drivers/%.o Core/Src/Drivers/%.su Core/Src/Drivers/%.cyclo: ../Core/Src/Drivers/%.c Core/Src/Drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G030xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Drivers

clean-Core-2f-Src-2f-Drivers:
	-$(RM) ./Core/Src/Drivers/dp_switch.cyclo ./Core/Src/Drivers/dp_switch.d ./Core/Src/Drivers/dp_switch.o ./Core/Src/Drivers/dp_switch.su ./Core/Src/Drivers/equalizer.cyclo ./Core/Src/Drivers/equalizer.d ./Core/Src/Drivers/equalizer.o ./Core/Src/Drivers/equalizer.su

.PHONY: clean-Core-2f-Src-2f-Drivers

