################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/portable/port.obj: /Users/alvinccc/Documents/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/portable/CCS/ARM_CM4F/port.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccs/ccs/ccs_base/arm/include" --include_path="/Applications/ti/ccs/ccs/ccs_base/arm/include/CMSIS" --include_path="/Applications/ti/ccs/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --include_path="/Users/alvinccc/Documents/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/include" --include_path="/Users/alvinccc/Documents/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="/Users/alvinccc/Documents/ECE353/code-FreeRTOS/Project" --include_path="/Users/alvinccc/Documents/ECE353/Library" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="FreeRTOS/portable/$(basename $(<F)).d_raw" --obj_directory="FreeRTOS/portable" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FreeRTOS/portable/portasm.obj: /Users/alvinccc/Documents/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/portable/CCS/ARM_CM4F/portasm.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccs/ccs/ccs_base/arm/include" --include_path="/Applications/ti/ccs/ccs/ccs_base/arm/include/CMSIS" --include_path="/Applications/ti/ccs/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --include_path="/Users/alvinccc/Documents/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/include" --include_path="/Users/alvinccc/Documents/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="/Users/alvinccc/Documents/ECE353/code-FreeRTOS/Project" --include_path="/Users/alvinccc/Documents/ECE353/Library" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="FreeRTOS/portable/$(basename $(<F)).d_raw" --obj_directory="FreeRTOS/portable" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


