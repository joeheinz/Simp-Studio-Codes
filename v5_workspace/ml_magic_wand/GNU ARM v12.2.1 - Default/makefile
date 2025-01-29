################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include gecko_sdk_4.4.2/util/third_party/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/subdir.mk
-include gecko_sdk_4.4.2/util/third_party/tensorflow_extra/src/subdir.mk
-include gecko_sdk_4.4.2/util/third_party/tensorflow_extra/siliconlabs/subdir.mk
-include gecko_sdk_4.4.2/platform/service/udelay/src/subdir.mk
-include gecko_sdk_4.4.2/platform/service/system/src/subdir.mk
-include gecko_sdk_4.4.2/platform/service/sleeptimer/src/subdir.mk
-include gecko_sdk_4.4.2/platform/service/iostream/src/subdir.mk
-include gecko_sdk_4.4.2/platform/service/device_init/src/subdir.mk
-include gecko_sdk_4.4.2/platform/peripheral/src/subdir.mk
-include gecko_sdk_4.4.2/platform/emlib/src/subdir.mk
-include gecko_sdk_4.4.2/platform/emdrv/gpiointerrupt/src/subdir.mk
-include gecko_sdk_4.4.2/platform/emdrv/dmadrv/src/subdir.mk
-include gecko_sdk_4.4.2/platform/driver/leddrv/src/subdir.mk
-include gecko_sdk_4.4.2/platform/driver/debug/src/subdir.mk
-include gecko_sdk_4.4.2/platform/compute/util/src/subdir.mk
-include gecko_sdk_4.4.2/platform/compute/nn/src/subdir.mk
-include gecko_sdk_4.4.2/platform/compute/nn/mvp/src/subdir.mk
-include gecko_sdk_4.4.2/platform/compute/math/src/subdir.mk
-include gecko_sdk_4.4.2/platform/compute/math/mvp/src/subdir.mk
-include gecko_sdk_4.4.2/platform/compute/driver/mvp/src/subdir.mk
-include gecko_sdk_4.4.2/platform/common/toolchain/src/subdir.mk
-include gecko_sdk_4.4.2/platform/common/src/subdir.mk
-include gecko_sdk_4.4.2/platform/Device/SiliconLabs/EFR32MG24/Source/subdir.mk
-include gecko_sdk_4.4.2/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/subdir.mk
-include gecko_sdk_4.4.2/hardware/driver/imu/src/subdir.mk
-include gecko_sdk_4.4.2/hardware/driver/icm20689/src/subdir.mk
-include gecko_sdk_4.4.2/hardware/driver/configuration_over_swo/src/subdir.mk
-include gecko_sdk_4.4.2/hardware/board/src/subdir.mk
-include autogen/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := ml_magic_wand
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: ml_magic_wand.axf

# Tool invocations
ml_magic_wand.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C++ Linker'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -T "/Users/joseheinz/SimplicityStudio/v5_workspace/ml_magic_wand/autogen/linkerfile.ld" -u _printf_float -Wl,--no-warn-rwx-segments --specs=nosys.specs -Xlinker --gc-sections -Xlinker -Map="ml_magic_wand.map" -mfpu=fpv5-sp-d16 -mfloat-abi=hard --specs=nano.specs -o ml_magic_wand.axf -Wl,--start-group "./accelerometer.o" "./app.o" "./magic_wand.o" "./main.o" "./predictor.o" "./autogen/sl_board_default_init.o" "./autogen/sl_device_init_clocks.o" "./autogen/sl_event_handler.o" "./autogen/sl_iostream_handles.o" "./autogen/sl_iostream_init_eusart_instances.o" "./autogen/sl_simple_led_instances.o" "./autogen/sl_tflite_micro_model.o" "./gecko_sdk_4.4.2/hardware/board/src/sl_board_control_gpio.o" "./gecko_sdk_4.4.2/hardware/board/src/sl_board_init.o" "./gecko_sdk_4.4.2/hardware/driver/configuration_over_swo/src/sl_cos.o" "./gecko_sdk_4.4.2/hardware/driver/icm20689/src/sl_icm20689.o" "./gecko_sdk_4.4.2/hardware/driver/imu/src/sl_imu_dcm.o" "./gecko_sdk_4.4.2/hardware/driver/imu/src/sl_imu_fuse.o" "./gecko_sdk_4.4.2/hardware/driver/imu/src/sl_imu_icm20689.o" "./gecko_sdk_4.4.2/hardware/driver/imu/src/sl_imu_math.o" "./gecko_sdk_4.4.2/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/sl_mx25_flash_shutdown.o" "./gecko_sdk_4.4.2/platform/Device/SiliconLabs/EFR32MG24/Source/startup_efr32mg24.o" "./gecko_sdk_4.4.2/platform/Device/SiliconLabs/EFR32MG24/Source/system_efr32mg24.o" "./gecko_sdk_4.4.2/platform/common/src/sl_assert.o" "./gecko_sdk_4.4.2/platform/common/src/sl_slist.o" "./gecko_sdk_4.4.2/platform/common/src/sl_string.o" "./gecko_sdk_4.4.2/platform/common/src/sl_syscalls.o" "./gecko_sdk_4.4.2/platform/common/toolchain/src/sl_memory.o" "./gecko_sdk_4.4.2/platform/compute/driver/mvp/src/sl_mvp.o" "./gecko_sdk_4.4.2/platform/compute/driver/mvp/src/sl_mvp_hal_efr32.o" "./gecko_sdk_4.4.2/platform/compute/driver/mvp/src/sl_mvp_program_area.o" "./gecko_sdk_4.4.2/platform/compute/driver/mvp/src/sl_mvp_util.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_complex_matrix_mult.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_complex_vector_conjugate.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_complex_vector_dot_product.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_complex_vector_magnitude_squared.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_complex_vector_mult.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_matrix_add.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_matrix_mult.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_matrix_scale.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_matrix_sub.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_matrix_transpose.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_matrix_vector_mult.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_util.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_vector_abs.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_vector_add.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_vector_clamp.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_vector_clip.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_vector_copy.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_vector_dot_product.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_vector_fill.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_vector_mult.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_vector_negate.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_vector_offset.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_vector_scale.o" "./gecko_sdk_4.4.2/platform/compute/math/mvp/src/sl_math_mvp_vector_sub.o" "./gecko_sdk_4.4.2/platform/compute/math/src/sl_math_matrix.o" "./gecko_sdk_4.4.2/platform/compute/nn/mvp/src/sl_mvp_ml_add.o" "./gecko_sdk_4.4.2/platform/compute/nn/mvp/src/sl_mvp_ml_conv2d.o" "./gecko_sdk_4.4.2/platform/compute/nn/mvp/src/sl_mvp_ml_depthwise_conv2d.o" "./gecko_sdk_4.4.2/platform/compute/nn/mvp/src/sl_mvp_ml_fully_connected.o" "./gecko_sdk_4.4.2/platform/compute/nn/mvp/src/sl_mvp_ml_mul.o" "./gecko_sdk_4.4.2/platform/compute/nn/mvp/src/sl_mvp_ml_pooling.o" "./gecko_sdk_4.4.2/platform/compute/nn/mvp/src/sl_mvp_ml_transpose_conv2d.o" "./gecko_sdk_4.4.2/platform/compute/nn/mvp/src/sli_mvp_ml_depthwise_conv2d.o" "./gecko_sdk_4.4.2/platform/compute/nn/mvp/src/sli_mvp_ml_depthwise_conv2d_opt.o" "./gecko_sdk_4.4.2/platform/compute/nn/src/sl_nn_util.o" "./gecko_sdk_4.4.2/platform/compute/util/src/sl_compute_util.o" "./gecko_sdk_4.4.2/platform/driver/debug/src/sl_debug_swo.o" "./gecko_sdk_4.4.2/platform/driver/leddrv/src/sl_led.o" "./gecko_sdk_4.4.2/platform/driver/leddrv/src/sl_simple_led.o" "./gecko_sdk_4.4.2/platform/emdrv/dmadrv/src/dmadrv.o" "./gecko_sdk_4.4.2/platform/emdrv/gpiointerrupt/src/gpiointerrupt.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_burtc.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_cmu.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_core.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_emu.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_eusart.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_gpio.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_ldma.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_msc.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_prs.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_system.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_timer.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_usart.o" "./gecko_sdk_4.4.2/platform/peripheral/src/peripheral_sysrtc.o" "./gecko_sdk_4.4.2/platform/service/device_init/src/sl_device_init_dcdc_s2.o" "./gecko_sdk_4.4.2/platform/service/device_init/src/sl_device_init_emu_s2.o" "./gecko_sdk_4.4.2/platform/service/device_init/src/sl_device_init_hfxo_s2.o" "./gecko_sdk_4.4.2/platform/service/device_init/src/sl_device_init_lfxo_s2.o" "./gecko_sdk_4.4.2/platform/service/device_init/src/sl_device_init_nvic.o" "./gecko_sdk_4.4.2/platform/service/iostream/src/sl_iostream.o" "./gecko_sdk_4.4.2/platform/service/iostream/src/sl_iostream_eusart.o" "./gecko_sdk_4.4.2/platform/service/iostream/src/sl_iostream_retarget_stdio.o" "./gecko_sdk_4.4.2/platform/service/iostream/src/sl_iostream_uart.o" "./gecko_sdk_4.4.2/platform/service/sleeptimer/src/sl_sleeptimer.o" "./gecko_sdk_4.4.2/platform/service/sleeptimer/src/sl_sleeptimer_hal_burtc.o" "./gecko_sdk_4.4.2/platform/service/sleeptimer/src/sl_sleeptimer_hal_sysrtc.o" "./gecko_sdk_4.4.2/platform/service/sleeptimer/src/sl_sleeptimer_hal_timer.o" "./gecko_sdk_4.4.2/platform/service/system/src/sl_system_init.o" "./gecko_sdk_4.4.2/platform/service/system/src/sl_system_process_action.o" "./gecko_sdk_4.4.2/platform/service/udelay/src/sl_udelay.o" "./gecko_sdk_4.4.2/platform/service/udelay/src/sl_udelay_armv6m_gcc.o" "./gecko_sdk_4.4.2/util/third_party/tensorflow_extra/siliconlabs/add.o" "./gecko_sdk_4.4.2/util/third_party/tensorflow_extra/siliconlabs/conv.o" "./gecko_sdk_4.4.2/util/third_party/tensorflow_extra/siliconlabs/debug_log.o" "./gecko_sdk_4.4.2/util/third_party/tensorflow_extra/siliconlabs/depthwise_conv.o" "./gecko_sdk_4.4.2/util/third_party/tensorflow_extra/siliconlabs/fully_connected.o" "./gecko_sdk_4.4.2/util/third_party/tensorflow_extra/siliconlabs/mul.o" "./gecko_sdk_4.4.2/util/third_party/tensorflow_extra/siliconlabs/pooling.o" "./gecko_sdk_4.4.2/util/third_party/tensorflow_extra/siliconlabs/transpose_conv.o" "./gecko_sdk_4.4.2/util/third_party/tensorflow_extra/src/sl_tflite_micro_init.o" "./gecko_sdk_4.4.2/util/third_party/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/softmax.o" "./gecko_sdk_4.4.2/util/third_party/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/svdf.o" "./gecko_sdk_4.4.2/util/third_party/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/unidirectional_sequence_lstm.o" "/Users/joseheinz/SimplicityStudio/SDKs/gecko_sdk_2//util/third_party/cmsis/lib/gcc/cortex-m33/libcmsis-nn.a" "/Users/joseheinz/SimplicityStudio/SDKs/gecko_sdk_2//util/third_party/tensorflow_extra/lib/gcc/cortex-m33/libtflm.a" -lstdc++ -lgcc -lc -lm -lnosys -Wl,--end-group -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building out file: ml_magic_wand.out'
	arm-none-eabi-objcopy "ml_magic_wand.axf" "ml_magic_wand.out"
	@echo ' '

	@echo 'Building hex file: ml_magic_wand.hex'
	arm-none-eabi-objcopy -O ihex "ml_magic_wand.axf" "ml_magic_wand.hex"
	@echo ' '

	@echo 'Building bin file: ml_magic_wand.bin'
	arm-none-eabi-objcopy -O binary "ml_magic_wand.axf" "ml_magic_wand.bin"
	@echo ' '

	@echo 'Building s37 file: ml_magic_wand.s37'
	arm-none-eabi-objcopy -O srec "ml_magic_wand.axf" "ml_magic_wand.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "ml_magic_wand.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(CC_DEPS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C++_DEPS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_UPPER_DEPS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(CXX_DEPS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(CPP_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) ml_magic_wand.axf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
