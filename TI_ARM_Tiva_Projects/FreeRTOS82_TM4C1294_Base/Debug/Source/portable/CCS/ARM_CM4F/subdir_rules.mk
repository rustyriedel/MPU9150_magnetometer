################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Source/portable/CCS/ARM_CM4F/port.obj: C:/EECS\ workspace/EECS690\ -\ ADV\ embedded\ systems/Project02\ -\ 3Axis\ Magnetometer\ sensor/TI_ARM_Tiva_Projects/Source/portable/CCS/ARM_CM4F/port.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI_CodeComposer/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/EECS workspace/EECS690 - ADV embedded systems/Project02 - 3Axis Magnetometer sensor/TI_ARM_Tiva_Projects/FreeRTOS82_TM4C1294_Base" --include_path="C:/EECS workspace/EECS690 - ADV embedded systems/Project02 - 3Axis Magnetometer sensor/TI_ARM_Tiva_Projects/FreeRTOS82_TM4C1294_Base/Drivers" --include_path="C:/EECS workspace/EECS690 - ADV embedded systems/Project02 - 3Axis Magnetometer sensor/TI_ARM_Tiva_Projects/Source/portable/CCS/ARM_CM4F" --include_path="C:/EECS workspace/EECS690 - ADV embedded systems/Project02 - 3Axis Magnetometer sensor/TI_ARM_Tiva_Projects/Source/include" --include_path="C:/TI_CodeComposer/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/TI_CodeComposer/TivaWare" -g --gcc --define=ccs="ccs" --define=PART_TM4C1294NCPDT --super_quiet --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --printf_support=full -k --asm_listing --preproc_with_compile --preproc_dependency="Source/portable/CCS/ARM_CM4F/port.d" --obj_directory="Source/portable/CCS/ARM_CM4F" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/portable/CCS/ARM_CM4F/portasm.obj: C:/EECS\ workspace/EECS690\ -\ ADV\ embedded\ systems/Project02\ -\ 3Axis\ Magnetometer\ sensor/TI_ARM_Tiva_Projects/Source/portable/CCS/ARM_CM4F/portasm.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI_CodeComposer/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/EECS workspace/EECS690 - ADV embedded systems/Project02 - 3Axis Magnetometer sensor/TI_ARM_Tiva_Projects/FreeRTOS82_TM4C1294_Base" --include_path="C:/EECS workspace/EECS690 - ADV embedded systems/Project02 - 3Axis Magnetometer sensor/TI_ARM_Tiva_Projects/FreeRTOS82_TM4C1294_Base/Drivers" --include_path="C:/EECS workspace/EECS690 - ADV embedded systems/Project02 - 3Axis Magnetometer sensor/TI_ARM_Tiva_Projects/Source/portable/CCS/ARM_CM4F" --include_path="C:/EECS workspace/EECS690 - ADV embedded systems/Project02 - 3Axis Magnetometer sensor/TI_ARM_Tiva_Projects/Source/include" --include_path="C:/TI_CodeComposer/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/TI_CodeComposer/TivaWare" -g --gcc --define=ccs="ccs" --define=PART_TM4C1294NCPDT --super_quiet --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --printf_support=full -k --asm_listing --preproc_with_compile --preproc_dependency="Source/portable/CCS/ARM_CM4F/portasm.d" --obj_directory="Source/portable/CCS/ARM_CM4F" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


