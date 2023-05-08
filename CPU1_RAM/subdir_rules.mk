################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-456760065: ../c2000.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs1230/ccs/utils/sysconfig_1.16.1/sysconfig_cli.bat" -s "C:/ti/C2000Ware_4_03_00_00/.metadata/sdk.json" -d "F2837xD" --script "C:/Users/email/workspace_v12/MPU6050/c2000.syscfg" -o "syscfg" --package F2837xD_337ZWT --part F2837xD_337ZWT --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-456760065 ../c2000.syscfg
syscfg/board.h: build-456760065
syscfg/board.cmd.genlibs: build-456760065
syscfg/board.opt: build-456760065
syscfg/pinmux.csv: build-456760065
syscfg/c2000ware_libraries.cmd.genlibs: build-456760065
syscfg/c2000ware_libraries.opt: build-456760065
syscfg/c2000ware_libraries.c: build-456760065
syscfg/c2000ware_libraries.h: build-456760065
syscfg/clocktree.h: build-456760065
syscfg/: build-456760065

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="C:/Users/email/workspace_v12/MPU6050/inc" --include_path="C:/Users/email/workspace_v12/MPU6050/src" --include_path="C:/Users/email/workspace_v12/MPU6050" --include_path="C:/Users/email/workspace_v12/MPU6050/device" --include_path="C:/ti/C2000Ware_4_03_00_00/driverlib/f2837xd/driverlib" --include_path="C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=_LAUNCHXL_F28379D --define=DEBUG --define=CPU1 --cpp_default --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/email/workspace_v12/MPU6050/CPU1_RAM/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="C:/Users/email/workspace_v12/MPU6050/inc" --include_path="C:/Users/email/workspace_v12/MPU6050/src" --include_path="C:/Users/email/workspace_v12/MPU6050" --include_path="C:/Users/email/workspace_v12/MPU6050/device" --include_path="C:/ti/C2000Ware_4_03_00_00/driverlib/f2837xd/driverlib" --include_path="C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=_LAUNCHXL_F28379D --define=DEBUG --define=CPU1 --cpp_default --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/email/workspace_v12/MPU6050/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


