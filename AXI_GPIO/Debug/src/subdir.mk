################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

C_SRCS += \
../src/axi_gpio.c \
../src/axi_uart.c \
../src/led.c \
../src/main.c 

OBJS += \
./src/axi_gpio.o \
./src/axi_uart.o \
./src/led.o \
./src/main.o 

C_DEPS += \
./src/axi_gpio.d \
./src/axi_uart.d \
./src/led.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -I../../AXI_GPIO_bsp/ps7_cortexa9_0/include -I"F:\0.zynq\PS_FPGA\5_AXI_GPIO\AXI_GPIO\AXI_GPIO.sdk\AXI_GPIO\src" -I"F:\0.zynq\PS_FPGA\5_AXI_GPIO\AXI_GPIO\AXI_GPIO.sdk\AXI_GPIO_bsp_2_bsp_0\ps7_cortexa9_0" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


