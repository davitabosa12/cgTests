################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/demo.cpp \
../src/indexedmesh.cpp \
../src/mesh.cpp \
../src/rawmesh.cpp \
../src/toyparser.cpp 

OBJS += \
./src/demo.o \
./src/indexedmesh.o \
./src/mesh.o \
./src/rawmesh.o \
./src/toyparser.o 

CPP_DEPS += \
./src/demo.d \
./src/indexedmesh.d \
./src/mesh.d \
./src/rawmesh.d \
./src/toyparser.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/aluno/davi/cgTests/final cg/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


