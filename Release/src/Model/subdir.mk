################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Model/.cpp \
../src/Model/CrimeData.cpp \
../src/Model/IntNode.cpp \
../src/Model/IntNodeArray.cpp \
../src/Model/Meme.cpp \
../src/Model/Timer.cpp 

OBJS += \
./src/Model/Model.o \
./src/Model/CrimeData.o \
./src/Model/IntNode.o \
./src/Model/IntNodeArray.o \
./src/Model/Meme.o \
./src/Model/Timer.o 

CPP_DEPS += \
./src/Model.d \
./src/Model/CrimeData.d \
./src/Model/IntNode.d \
./src/Model/IntNodeArray.d \
./src/Model/Meme.d \
./src/Model/Timer.d 


# Each subdirectory must supply rules for building sources it contributes
src/Model/%.o: ../src/Model/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


