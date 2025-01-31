################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include gecko_sdk_4.4.2/util/third_party/mbedtls/library/subdir.mk
-include gecko_sdk_4.4.2/util/third_party/freertos/kernel/portable/SiliconLabs/subdir.mk
-include gecko_sdk_4.4.2/util/third_party/freertos/kernel/portable/MemMang/subdir.mk
-include gecko_sdk_4.4.2/util/third_party/freertos/kernel/portable/GCC/ARM_CM4F/subdir.mk
-include gecko_sdk_4.4.2/util/third_party/freertos/kernel/subdir.mk
-include gecko_sdk_4.4.2/util/third_party/freertos/cmsis/Source/subdir.mk
-include gecko_sdk_4.4.2/util/third_party/coremark/subdir.mk
-include gecko_sdk_4.4.2/util/silicon_labs/silabs_core/memory_manager/subdir.mk
-include gecko_sdk_4.4.2/protocol/bluetooth/src/subdir.mk
-include gecko_sdk_4.4.2/protocol/bluetooth/bgcommon/src/subdir.mk
-include gecko_sdk_4.4.2/platform/service/system/src/subdir.mk
-include gecko_sdk_4.4.2/platform/service/sleeptimer/src/subdir.mk
-include gecko_sdk_4.4.2/platform/service/power_manager/src/subdir.mk
-include gecko_sdk_4.4.2/platform/service/iostream/src/subdir.mk
-include gecko_sdk_4.4.2/platform/service/device_init/src/subdir.mk
-include gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/subdir.mk
-include gecko_sdk_4.4.2/platform/security/sl_component/sl_protocol_crypto/src/subdir.mk
-include gecko_sdk_4.4.2/platform/security/sl_component/sl_mbedtls_support/src/subdir.mk
-include gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/rail_util_power_manager_init/subdir.mk
-include gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/pa-conversions/subdir.mk
-include gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/fem_util/subdir.mk
-include gecko_sdk_4.4.2/platform/emlib/src/subdir.mk
-include gecko_sdk_4.4.2/platform/driver/debug/src/subdir.mk
-include gecko_sdk_4.4.2/platform/common/toolchain/src/subdir.mk
-include gecko_sdk_4.4.2/platform/common/src/subdir.mk
-include gecko_sdk_4.4.2/platform/Device/SiliconLabs/BGM1/Source/subdir.mk
-include gecko_sdk_4.4.2/platform/CMSIS/RTOS2/Source/subdir.mk
-include gecko_sdk_4.4.2/hardware/driver/configuration_over_swo/src/subdir.mk
-include gecko_sdk_4.4.2/hardware/board/src/subdir.mk
-include gecko_sdk_4.4.2/app/common/util/app_timer_freertos_static/subdir.mk
-include gecko_sdk_4.4.2/app/common/util/app_log/subdir.mk
-include gecko_sdk_4.4.2/app/bluetooth/common/ncp_gatt/subdir.mk
-include gecko_sdk_4.4.2/app/bluetooth/common/ibeacon/subdir.mk
-include gecko_sdk_4.4.2/app/bluetooth/common/gatt_service_battery/subdir.mk
-include gecko_sdk_4.4.2/app/bluetooth/common/gatt_service_aio/subdir.mk
-include autogen/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := empty_C_iadc
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: empty_C_iadc.axf

# Tool invocations
empty_C_iadc.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "/Users/joseheinz/Documents/GitHub/Simp-Studio-Codes/v5_workspace/empty_C_iadc/autogen/linkerfile.ld" -Wl,--no-warn-rwx-segments -Xlinker --gc-sections -Xlinker -Map="empty_C_iadc.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o empty_C_iadc.axf -Wl,--start-group "./app.o" "./main.o" "./sl_gatt_service_device_information.o" "./autogen/gatt_db.o" "./autogen/sl_bluetooth.o" "./autogen/sl_board_default_init.o" "./autogen/sl_device_init_clocks.o" "./autogen/sl_event_handler.o" "./autogen/sl_iostream_handles.o" "./gecko_sdk_4.4.2/app/bluetooth/common/gatt_service_aio/sl_gatt_service_aio.o" "./gecko_sdk_4.4.2/app/bluetooth/common/gatt_service_battery/sl_gatt_service_battery.o" "./gecko_sdk_4.4.2/app/bluetooth/common/ibeacon/sl_bt_ibeacon.o" "./gecko_sdk_4.4.2/app/bluetooth/common/ncp_gatt/sl_ncp_gatt.o" "./gecko_sdk_4.4.2/app/common/util/app_log/app_log.o" "./gecko_sdk_4.4.2/app/common/util/app_timer_freertos_static/app_timer_freertos_static.o" "./gecko_sdk_4.4.2/hardware/board/src/sl_board_control_gpio.o" "./gecko_sdk_4.4.2/hardware/board/src/sl_board_init.o" "./gecko_sdk_4.4.2/hardware/driver/configuration_over_swo/src/sl_cos.o" "./gecko_sdk_4.4.2/platform/CMSIS/RTOS2/Source/os_systick.o" "./gecko_sdk_4.4.2/platform/Device/SiliconLabs/BGM1/Source/startup_bgm1.o" "./gecko_sdk_4.4.2/platform/Device/SiliconLabs/BGM1/Source/system_bgm1.o" "./gecko_sdk_4.4.2/platform/common/src/sl_assert.o" "./gecko_sdk_4.4.2/platform/common/src/sl_slist.o" "./gecko_sdk_4.4.2/platform/common/src/sl_syscalls.o" "./gecko_sdk_4.4.2/platform/common/src/sli_cmsis_os2_ext_task_register.o" "./gecko_sdk_4.4.2/platform/common/toolchain/src/sl_memory.o" "./gecko_sdk_4.4.2/platform/driver/debug/src/sl_debug_swo.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_acmp.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_adc.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_cmu.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_core.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_cryotimer.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_crypto.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_dbg.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_emu.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_gpcrc.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_gpio.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_i2c.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_idac.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_ldma.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_letimer.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_leuart.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_msc.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_pcnt.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_prs.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_rmu.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_rtcc.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_system.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_timer.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_usart.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_wdog.o" "./gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/fem_util/sl_fem_util.o" "./gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/pa-conversions/pa_conversions_efr32.o" "./gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/rail_util_power_manager_init/sl_rail_util_power_manager_init.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_mbedtls_support/src/crypto_aes.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_mbedtls_support/src/crypto_ecp.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_mbedtls_support/src/mbedtls_cmac.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_mbedtls_support/src/mbedtls_sha.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_mbedtls_support/src/sl_entropy_hardware.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_mbedtls_support/src/sl_mbedtls.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_protocol_crypto/src/sli_protocol_crypto_crypto.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/crypto_management.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_crypto_transparent_driver_aead.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_crypto_transparent_driver_cipher.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_crypto_transparent_driver_hash.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_crypto_transparent_driver_mac.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_psa_driver_common.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_psa_driver_init.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_se_version_dependencies.o" "./gecko_sdk_4.4.2/platform/service/device_init/src/sl_device_init_dcdc_s1.o" "./gecko_sdk_4.4.2/platform/service/device_init/src/sl_device_init_emu_s1.o" "./gecko_sdk_4.4.2/platform/service/device_init/src/sl_device_init_hfxo_s1.o" "./gecko_sdk_4.4.2/platform/service/device_init/src/sl_device_init_lfxo_s1.o" "./gecko_sdk_4.4.2/platform/service/device_init/src/sl_device_init_nvic.o" "./gecko_sdk_4.4.2/platform/service/iostream/src/sl_iostream.o" "./gecko_sdk_4.4.2/platform/service/iostream/src/sl_iostream_debug.o" "./gecko_sdk_4.4.2/platform/service/iostream/src/sl_iostream_retarget_stdio.o" "./gecko_sdk_4.4.2/platform/service/iostream/src/sl_iostream_stdlib_config.o" "./gecko_sdk_4.4.2/platform/service/iostream/src/sl_iostream_swo_itm_8.o" "./gecko_sdk_4.4.2/platform/service/power_manager/src/sl_power_manager.o" "./gecko_sdk_4.4.2/platform/service/power_manager/src/sl_power_manager_debug.o" "./gecko_sdk_4.4.2/platform/service/power_manager/src/sl_power_manager_hal_s0_s1.o" "./gecko_sdk_4.4.2/platform/service/sleeptimer/src/sl_sleeptimer.o" "./gecko_sdk_4.4.2/platform/service/sleeptimer/src/sl_sleeptimer_hal_rtcc.o" "./gecko_sdk_4.4.2/platform/service/sleeptimer/src/sl_sleeptimer_hal_timer.o" "./gecko_sdk_4.4.2/platform/service/system/src/sl_system_init.o" "./gecko_sdk_4.4.2/platform/service/system/src/sl_system_kernel.o" "./gecko_sdk_4.4.2/protocol/bluetooth/bgcommon/src/sl_bt_mbedtls_context.o" "./gecko_sdk_4.4.2/protocol/bluetooth/src/sl_bt_rtos_adaptation.o" "./gecko_sdk_4.4.2/protocol/bluetooth/src/sl_bt_stack_init.o" "./gecko_sdk_4.4.2/protocol/bluetooth/src/sli_bt_accept_list_config.o" "./gecko_sdk_4.4.2/protocol/bluetooth/src/sli_bt_advertiser_config.o" "./gecko_sdk_4.4.2/protocol/bluetooth/src/sli_bt_connection_config.o" "./gecko_sdk_4.4.2/protocol/bluetooth/src/sli_bt_dynamic_gattdb_config.o" "./gecko_sdk_4.4.2/protocol/bluetooth/src/sli_bt_l2cap_config.o" "./gecko_sdk_4.4.2/protocol/bluetooth/src/sli_bt_pawr_advertiser_config.o" "./gecko_sdk_4.4.2/protocol/bluetooth/src/sli_bt_periodic_adv_config.o" "./gecko_sdk_4.4.2/protocol/bluetooth/src/sli_bt_periodic_advertiser_config.o" "./gecko_sdk_4.4.2/protocol/bluetooth/src/sli_bt_sync_config.o" "./gecko_sdk_4.4.2/util/silicon_labs/silabs_core/memory_manager/sl_malloc.o" "./gecko_sdk_4.4.2/util/third_party/coremark/core_list_join.o" "./gecko_sdk_4.4.2/util/third_party/coremark/core_main.o" "./gecko_sdk_4.4.2/util/third_party/coremark/core_matrix.o" "./gecko_sdk_4.4.2/util/third_party/coremark/core_portme.o" "./gecko_sdk_4.4.2/util/third_party/coremark/core_state.o" "./gecko_sdk_4.4.2/util/third_party/coremark/core_util.o" "./gecko_sdk_4.4.2/util/third_party/freertos/cmsis/Source/cmsis_os2.o" "./gecko_sdk_4.4.2/util/third_party/freertos/kernel/croutine.o" "./gecko_sdk_4.4.2/util/third_party/freertos/kernel/event_groups.o" "./gecko_sdk_4.4.2/util/third_party/freertos/kernel/list.o" "./gecko_sdk_4.4.2/util/third_party/freertos/kernel/queue.o" "./gecko_sdk_4.4.2/util/third_party/freertos/kernel/stream_buffer.o" "./gecko_sdk_4.4.2/util/third_party/freertos/kernel/tasks.o" "./gecko_sdk_4.4.2/util/third_party/freertos/kernel/timers.o" "./gecko_sdk_4.4.2/util/third_party/freertos/kernel/portable/GCC/ARM_CM4F/port.o" "./gecko_sdk_4.4.2/util/third_party/freertos/kernel/portable/MemMang/heap_4.o" "./gecko_sdk_4.4.2/util/third_party/freertos/kernel/portable/SiliconLabs/tick_power_manager.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/aes.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/bignum.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/bignum_core.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/bignum_mod.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/bignum_mod_raw.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/cipher.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/cipher_wrap.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/cmac.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/constant_time.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/ctr_drbg.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/ecdh.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/ecp.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/ecp_curves.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/ecp_curves_new.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/entropy.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/entropy_poll.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/hmac_drbg.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/md.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/platform.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/platform_util.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/psa_crypto_client.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/psa_util.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/sha256.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/threading.o" "/Users/joseheinz/SimplicityStudio/SDKs/gecko_sdk_2//protocol/bluetooth/bgcommon/lib/libbgcommon_efr32xg1_gcc_release.a" "/Users/joseheinz/SimplicityStudio/SDKs/gecko_sdk_2//protocol/bluetooth/bgstack/ll/lib/libbluetooth_controller_efr32xg1_gcc_release.a" "/Users/joseheinz/SimplicityStudio/SDKs/gecko_sdk_2//protocol/bluetooth/lib/libbluetooth_host_efr32xg1_gcc_release.a" "/Users/joseheinz/SimplicityStudio/SDKs/gecko_sdk_2//protocol/bluetooth/lib/EFR32XG1/GCC/libpsstore.a" "/Users/joseheinz/SimplicityStudio/SDKs/gecko_sdk_2//platform/radio/rail_lib/autogen/librail_release/librail_config_bgm111a256v2_gcc.a" "/Users/joseheinz/SimplicityStudio/SDKs/gecko_sdk_2//platform/radio/rail_lib/autogen/librail_release/librail_module_efr32xg1_gcc_release.a" -lgcc -lc -lm -lnosys -Wl,--end-group -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building out file: empty_C_iadc.out'
	arm-none-eabi-objcopy "empty_C_iadc.axf" "empty_C_iadc.out"
	@echo ' '

	@echo 'Building hex file: empty_C_iadc.hex'
	arm-none-eabi-objcopy -O ihex "empty_C_iadc.axf" "empty_C_iadc.hex"
	@echo ' '

	@echo 'Building bin file: empty_C_iadc.bin'
	arm-none-eabi-objcopy -O binary "empty_C_iadc.axf" "empty_C_iadc.bin"
	@echo ' '

	@echo 'Building s37 file: empty_C_iadc.s37'
	arm-none-eabi-objcopy -O srec "empty_C_iadc.axf" "empty_C_iadc.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "empty_C_iadc.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) empty_C_iadc.axf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
