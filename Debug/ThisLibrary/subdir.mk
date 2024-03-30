################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThisLibrary/timerDealy.c 

OBJS += \
./ThisLibrary/timerDealy.o 

C_DEPS += \
./ThisLibrary/timerDealy.d 


# Each subdirectory must supply rules for building sources it contributes
ThisLibrary/%.o ThisLibrary/%.su ThisLibrary/%.cyclo: ../ThisLibrary/%.c ThisLibrary/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"/home/pavel/Documents/cubeIDE-workspace/stm32Timer/ThisLibrary" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-ThisLibrary

clean-ThisLibrary:
	-$(RM) ./ThisLibrary/timerDealy.cyclo ./ThisLibrary/timerDealy.d ./ThisLibrary/timerDealy.o ./ThisLibrary/timerDealy.su

.PHONY: clean-ThisLibrary

