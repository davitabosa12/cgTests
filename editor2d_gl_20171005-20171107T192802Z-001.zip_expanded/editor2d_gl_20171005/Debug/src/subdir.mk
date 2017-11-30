################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Point.cpp \
../src/demo.cpp \
../src/drawingTool.cpp \
../src/image2dx.cpp 

OBJS += \
./src/Point.o \
./src/demo.o \
./src/drawingTool.o \
./src/image2dx.o 

CPP_DEPS += \
./src/Point.d \
./src/demo.d \
./src/drawingTool.d \
./src/image2dx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/media/davi/Davi Tabosa/CG/editor2d_gl_20171005/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


