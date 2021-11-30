################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/Ebook.c \
../src/LinkedList.c \
../src/Utn.c \
../src/main.c \
../src/parser.c 

OBJS += \
./src/Controller.o \
./src/Ebook.o \
./src/LinkedList.o \
./src/Utn.o \
./src/main.o \
./src/parser.o 

C_DEPS += \
./src/Controller.d \
./src/Ebook.d \
./src/LinkedList.d \
./src/Utn.d \
./src/main.d \
./src/parser.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


