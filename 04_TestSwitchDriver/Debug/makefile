################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 2-HAL/SWITCH/subdir.mk
-include 2-HAL/LED/subdir.mk
-include 1-MCAL/1-DIO/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
04_TestSwitchDriver.lss \

FLASH_IMAGE += \
04_TestSwitchDriver.hex \

EEPROM_IMAGE += \
04_TestSwitchDriver.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: 04_TestSwitchDriver.elf secondary-outputs

# Tool invocations
04_TestSwitchDriver.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,04_TestSwitchDriver.map -mmcu=atmega32 -o "04_TestSwitchDriver.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

04_TestSwitchDriver.lss: 04_TestSwitchDriver.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 04_TestSwitchDriver.elf  >"04_TestSwitchDriver.lss"
	@echo 'Finished building: $@'
	@echo ' '

04_TestSwitchDriver.hex: 04_TestSwitchDriver.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 04_TestSwitchDriver.elf  "04_TestSwitchDriver.hex"
	@echo 'Finished building: $@'
	@echo ' '

04_TestSwitchDriver.eep: 04_TestSwitchDriver.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex 04_TestSwitchDriver.elf  "04_TestSwitchDriver.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 04_TestSwitchDriver.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 04_TestSwitchDriver.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 04_TestSwitchDriver.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
