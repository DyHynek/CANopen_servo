################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CANopenNode_STM32/CO_app_STM32.c \
../CANopenNode_STM32/CO_driver_STM32.c \
../CANopenNode_STM32/CO_storageBlank.c \
../CANopenNode_STM32/OD.c 

OBJS += \
./CANopenNode_STM32/CO_app_STM32.o \
./CANopenNode_STM32/CO_driver_STM32.o \
./CANopenNode_STM32/CO_storageBlank.o \
./CANopenNode_STM32/OD.o 

C_DEPS += \
./CANopenNode_STM32/CO_app_STM32.d \
./CANopenNode_STM32/CO_driver_STM32.d \
./CANopenNode_STM32/CO_storageBlank.d \
./CANopenNode_STM32/OD.d 


# Each subdirectory must supply rules for building sources it contributes
CANopenNode_STM32/%.o CANopenNode_STM32/%.su CANopenNode_STM32/%.cyclo: ../CANopenNode_STM32/%.c CANopenNode_STM32/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H742xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"E:/Loop_back/Loop_back/CANopenNode" -I"E:/Loop_back/Loop_back/CANopenNode_STM32" -I"E:/Loop_back/Loop_back/App" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CANopenNode_STM32

clean-CANopenNode_STM32:
	-$(RM) ./CANopenNode_STM32/CO_app_STM32.cyclo ./CANopenNode_STM32/CO_app_STM32.d ./CANopenNode_STM32/CO_app_STM32.o ./CANopenNode_STM32/CO_app_STM32.su ./CANopenNode_STM32/CO_driver_STM32.cyclo ./CANopenNode_STM32/CO_driver_STM32.d ./CANopenNode_STM32/CO_driver_STM32.o ./CANopenNode_STM32/CO_driver_STM32.su ./CANopenNode_STM32/CO_storageBlank.cyclo ./CANopenNode_STM32/CO_storageBlank.d ./CANopenNode_STM32/CO_storageBlank.o ./CANopenNode_STM32/CO_storageBlank.su ./CANopenNode_STM32/OD.cyclo ./CANopenNode_STM32/OD.d ./CANopenNode_STM32/OD.o ./CANopenNode_STM32/OD.su

.PHONY: clean-CANopenNode_STM32

