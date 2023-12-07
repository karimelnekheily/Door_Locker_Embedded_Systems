################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CONTROL.c \
../DcMotor.c \
../UART_DRIVER.c \
../buzzer.c \
../external_eeprom.c \
../gpio.c \
../pwm.c \
../timer_1.c \
../twi.c 

OBJS += \
./CONTROL.o \
./DcMotor.o \
./UART_DRIVER.o \
./buzzer.o \
./external_eeprom.o \
./gpio.o \
./pwm.o \
./timer_1.o \
./twi.o 

C_DEPS += \
./CONTROL.d \
./DcMotor.d \
./UART_DRIVER.d \
./buzzer.d \
./external_eeprom.d \
./gpio.d \
./pwm.d \
./timer_1.d \
./twi.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


