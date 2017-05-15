################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Controller/FileController.cpp \
../src/Controller/Runner.cpp \
../src/Controller/StructureController.cpp \
../src/Controller/StructureTester.cpp 

OBJS += \
./src/Controller/FileController.o \
./src/Controller/Runner.o \
./src/Controller/StructureController.o \
./src/Controller/StructureTester.o 

CPP_DEPS += \
./src/Controller/FileController.d \
./src/Controller/Runner.d \
./src/Controller/StructureController.d \
./src/Controller/StructureTester.d 


# Each subdirectory must supply rules for building sources it contributes
src/Controller/%.o: ../src/Controller/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


