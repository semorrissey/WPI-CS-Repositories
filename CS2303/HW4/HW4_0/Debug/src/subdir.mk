################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Ant.cpp \
../src/AntsAndDoodles.cpp \
../src/Doodlebug.cpp \
../src/PA5.cpp \
../src/Organism.cpp \
../src/Production.cpp 

OBJS += \
./src/Ant.o \
./src/AntsAndDoodles.o \
./src/Doodlebug.o \
./src/PA5.o \
./src/Organism.o \
./src/Production.o 

CPP_DEPS += \
./src/Ant.d \
./src/AntsAndDoodles.d \
./src/Doodlebug.d \
./src/PA5.d \
./src/Organism.d \
./src/Production.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


