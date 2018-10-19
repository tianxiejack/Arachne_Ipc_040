################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Arachne_IPC_Message.c \
../Serial_port.c \
../appmain.c 

OBJS += \
./Arachne_IPC_Message.o \
./Serial_port.o \
./appmain.o 

C_DEPS += \
./Arachne_IPC_Message.d \
./Serial_port.d \
./appmain.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: NVCC Compiler'
	/usr/local/cuda-8.0/bin/nvcc -G -g -O0 -ccbin aarch64-linux-gnu-g++ -gencode arch=compute_50,code=sm_50 -m64 -odir "." -M -o "$(@:%.o=%.d)" "$<"
	/usr/local/cuda-8.0/bin/nvcc -G -g -O0 --compile -m64 -ccbin aarch64-linux-gnu-g++  -x c -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


