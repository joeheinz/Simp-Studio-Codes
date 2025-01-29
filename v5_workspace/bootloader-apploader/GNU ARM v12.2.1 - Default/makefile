################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include gecko_sdk_4.4.2/util/third_party/trusted-firmware-m/platform/ext/target/siliconlabs/hse/subdir.mk
-include gecko_sdk_4.4.2/util/third_party/trusted-firmware-m/lib/fih/src/subdir.mk
-include gecko_sdk_4.4.2/util/third_party/mbedtls/library/subdir.mk
-include gecko_sdk_4.4.2/util/silicon_labs/silabs_core/memory_manager/subdir.mk
-include gecko_sdk_4.4.2/platform/service/udelay/src/subdir.mk
-include gecko_sdk_4.4.2/platform/service/device_init/src/subdir.mk
-include gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/subdir.mk
-include gecko_sdk_4.4.2/platform/security/sl_component/sl_mbedtls_support/src/subdir.mk
-include gecko_sdk_4.4.2/platform/security/sl_component/se_manager/src/subdir.mk
-include gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/rail_util_sequencer/subdir.mk
-include gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/rail_util_built_in_phys/efr32xg24/subdir.mk
-include gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/rail_util_built_in_phys/subdir.mk
-include gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/pa-conversions/subdir.mk
-include gecko_sdk_4.4.2/platform/emlib/src/subdir.mk
-include gecko_sdk_4.4.2/platform/common/toolchain/src/subdir.mk
-include gecko_sdk_4.4.2/platform/common/src/subdir.mk
-include gecko_sdk_4.4.2/platform/bootloader/security/sha/subdir.mk
-include gecko_sdk_4.4.2/platform/bootloader/security/ecc/subdir.mk
-include gecko_sdk_4.4.2/platform/bootloader/security/subdir.mk
-include gecko_sdk_4.4.2/platform/bootloader/parser/gbl/subdir.mk
-include gecko_sdk_4.4.2/platform/bootloader/driver/subdir.mk
-include gecko_sdk_4.4.2/platform/bootloader/debug/subdir.mk
-include gecko_sdk_4.4.2/platform/bootloader/core/flash/subdir.mk
-include gecko_sdk_4.4.2/platform/bootloader/core/subdir.mk
-include gecko_sdk_4.4.2/platform/bootloader/communication/apploader/subdir.mk
-include gecko_sdk_4.4.2/platform/Device/SiliconLabs/EFR32MG24/Source/subdir.mk
-include gecko_sdk_4.4.2/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/subdir.mk
-include gecko_sdk_4.4.2/hardware/board/src/subdir.mk
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


BUILD_ARTIFACT_NAME := bootloader-apploader
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: bootloader-apploader.axf

# Tool invocations
bootloader-apploader.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -T "/Users/joseheinz/SimplicityStudio/v5_workspace/bootloader-apploader/autogen/linkerfile.ld" -Wl,--no-warn-rwx-segments -Xlinker --gc-sections -Xlinker -Map="bootloader-apploader.map" -mfpu=fpv5-sp-d16 -mfloat-abi=hard --specs=nano.specs -o bootloader-apploader.axf -Wl,--start-group "./autogen/sl_board_default_init.o" "./autogen/sl_device_init_clocks.o" "./gecko_sdk_4.4.2/hardware/board/src/sl_board_control_gpio.o" "./gecko_sdk_4.4.2/hardware/board/src/sl_board_init.o" "./gecko_sdk_4.4.2/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/sl_mx25_flash_shutdown.o" "./gecko_sdk_4.4.2/platform/Device/SiliconLabs/EFR32MG24/Source/startup_efr32mg24.o" "./gecko_sdk_4.4.2/platform/Device/SiliconLabs/EFR32MG24/Source/system_efr32mg24.o" "./gecko_sdk_4.4.2/platform/bootloader/communication/apploader/btl_apploader.o" "./gecko_sdk_4.4.2/platform/bootloader/communication/apploader/btl_apploader_common.o" "./gecko_sdk_4.4.2/platform/bootloader/core/btl_bootload.o" "./gecko_sdk_4.4.2/platform/bootloader/core/btl_core.o" "./gecko_sdk_4.4.2/platform/bootloader/core/btl_main.o" "./gecko_sdk_4.4.2/platform/bootloader/core/btl_parse.o" "./gecko_sdk_4.4.2/platform/bootloader/core/btl_reset.o" "./gecko_sdk_4.4.2/platform/bootloader/core/flash/btl_internal_flash.o" "./gecko_sdk_4.4.2/platform/bootloader/debug/btl_debug.o" "./gecko_sdk_4.4.2/platform/bootloader/debug/btl_debug_swo.o" "./gecko_sdk_4.4.2/platform/bootloader/driver/btl_driver_util.o" "./gecko_sdk_4.4.2/platform/bootloader/parser/gbl/btl_gbl_custom_tags.o" "./gecko_sdk_4.4.2/platform/bootloader/parser/gbl/btl_gbl_format.o" "./gecko_sdk_4.4.2/platform/bootloader/parser/gbl/btl_gbl_parser.o" "./gecko_sdk_4.4.2/platform/bootloader/security/btl_crc16.o" "./gecko_sdk_4.4.2/platform/bootloader/security/btl_crc32.o" "./gecko_sdk_4.4.2/platform/bootloader/security/btl_security_aes.o" "./gecko_sdk_4.4.2/platform/bootloader/security/btl_security_ecdsa.o" "./gecko_sdk_4.4.2/platform/bootloader/security/btl_security_sha256.o" "./gecko_sdk_4.4.2/platform/bootloader/security/btl_security_tokens.o" "./gecko_sdk_4.4.2/platform/bootloader/security/ecc/ecc.o" "./gecko_sdk_4.4.2/platform/bootloader/security/sha/btl_sha256.o" "./gecko_sdk_4.4.2/platform/bootloader/security/sha/crypto_sha.o" "./gecko_sdk_4.4.2/platform/bootloader/security/sha/cryptoacc_sha.o" "./gecko_sdk_4.4.2/platform/bootloader/security/sha/se_sha.o" "./gecko_sdk_4.4.2/platform/common/src/sl_assert.o" "./gecko_sdk_4.4.2/platform/common/src/sl_syscalls.o" "./gecko_sdk_4.4.2/platform/common/toolchain/src/sl_memory.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_acmp.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_burtc.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_cmu.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_core.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_dbg.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_emu.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_eusart.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_gpcrc.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_gpio.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_i2c.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_iadc.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_ldma.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_letimer.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_msc.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_opamp.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_pcnt.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_prs.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_rmu.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_se.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_system.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_timer.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_usart.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_vdac.o" "./gecko_sdk_4.4.2/platform/emlib/src/em_wdog.o" "./gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/pa-conversions/pa_conversions_efr32.o" "./gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/pa-conversions/pa_curves_efr32.o" "./gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/rail_util_built_in_phys/efr32xg24/sl_rail_ble_config_38M4Hz.o" "./gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/rail_util_built_in_phys/efr32xg24/sl_rail_ble_config_39MHz.o" "./gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/rail_util_built_in_phys/efr32xg24/sl_rail_ble_config_40MHz.o" "./gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/rail_util_built_in_phys/efr32xg24/sl_rail_ieee802154_config_38M4Hz.o" "./gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/rail_util_built_in_phys/efr32xg24/sl_rail_ieee802154_config_39MHz.o" "./gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/rail_util_built_in_phys/efr32xg24/sl_rail_ieee802154_config_40MHz.o" "./gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/rail_util_built_in_phys/efr32xg24/sl_rail_rfsense_ook_config_38M4Hz.o" "./gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/rail_util_built_in_phys/efr32xg24/sl_rail_rfsense_ook_config_39MHz.o" "./gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/rail_util_built_in_phys/efr32xg24/sl_rail_rfsense_ook_config_40MHz.o" "./gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/rail_util_built_in_phys/sl_rail_phy_overrides.o" "./gecko_sdk_4.4.2/platform/radio/rail_lib/plugin/rail_util_sequencer/sl_rail_util_sequencer.o" "./gecko_sdk_4.4.2/platform/security/sl_component/se_manager/src/sl_se_manager.o" "./gecko_sdk_4.4.2/platform/security/sl_component/se_manager/src/sl_se_manager_attestation.o" "./gecko_sdk_4.4.2/platform/security/sl_component/se_manager/src/sl_se_manager_cipher.o" "./gecko_sdk_4.4.2/platform/security/sl_component/se_manager/src/sl_se_manager_entropy.o" "./gecko_sdk_4.4.2/platform/security/sl_component/se_manager/src/sl_se_manager_hash.o" "./gecko_sdk_4.4.2/platform/security/sl_component/se_manager/src/sl_se_manager_key_derivation.o" "./gecko_sdk_4.4.2/platform/security/sl_component/se_manager/src/sl_se_manager_key_handling.o" "./gecko_sdk_4.4.2/platform/security/sl_component/se_manager/src/sl_se_manager_signature.o" "./gecko_sdk_4.4.2/platform/security/sl_component/se_manager/src/sl_se_manager_util.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_mbedtls_support/src/se_aes.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_mbedtls_support/src/sl_mbedtls.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_psa_driver_common.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_psa_driver_init.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_se_driver_aead.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_se_driver_builtin_keys.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_se_driver_cipher.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_se_driver_key_derivation.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_se_driver_key_management.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_se_driver_mac.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_se_driver_signature.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_se_opaque_driver_aead.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_se_opaque_driver_cipher.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_se_opaque_driver_mac.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_se_opaque_key_derivation.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_se_transparent_driver_aead.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_se_transparent_driver_cipher.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_se_transparent_driver_hash.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_se_transparent_driver_mac.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_se_transparent_key_derivation.o" "./gecko_sdk_4.4.2/platform/security/sl_component/sl_psa_driver/src/sli_se_version_dependencies.o" "./gecko_sdk_4.4.2/platform/service/device_init/src/sl_device_init_dcdc_s2.o" "./gecko_sdk_4.4.2/platform/service/device_init/src/sl_device_init_emu_s2.o" "./gecko_sdk_4.4.2/platform/service/device_init/src/sl_device_init_hfxo_s2.o" "./gecko_sdk_4.4.2/platform/service/device_init/src/sl_device_init_lfxo_s2.o" "./gecko_sdk_4.4.2/platform/service/device_init/src/sl_device_init_nvic.o" "./gecko_sdk_4.4.2/platform/service/udelay/src/sl_udelay.o" "./gecko_sdk_4.4.2/platform/service/udelay/src/sl_udelay_armv6m_gcc.o" "./gecko_sdk_4.4.2/util/silicon_labs/silabs_core/memory_manager/sl_malloc.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/aes.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/constant_time.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/platform.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/platform_util.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/psa_crypto_client.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/psa_util.o" "./gecko_sdk_4.4.2/util/third_party/mbedtls/library/threading.o" "./gecko_sdk_4.4.2/util/third_party/trusted-firmware-m/lib/fih/src/fih.o" "./gecko_sdk_4.4.2/util/third_party/trusted-firmware-m/platform/ext/target/siliconlabs/hse/sli_se.o" "/Users/joseheinz/SimplicityStudio/SDKs/gecko_sdk_2//protocol/bluetooth/lib/EFR32XG24/GCC/libapploader.a" "/Users/joseheinz/SimplicityStudio/SDKs/gecko_sdk_2//platform/radio/rail_lib/autogen/librail_release/librail_efr32xg24_gcc_release.a" -lgcc -lc -lm -lnosys -Wl,--end-group -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building out file: bootloader-apploader.out'
	arm-none-eabi-objcopy "bootloader-apploader.axf" "bootloader-apploader.out"
	@echo ' '

	@echo 'Building hex file: bootloader-apploader.hex'
	arm-none-eabi-objcopy -O ihex "bootloader-apploader.axf" "bootloader-apploader.hex"
	@echo ' '

	@echo 'Building bin file: bootloader-apploader.bin'
	arm-none-eabi-objcopy -O binary "bootloader-apploader.axf" "bootloader-apploader.bin"
	@echo ' '

	@echo 'Building s37 file: bootloader-apploader.s37'
	arm-none-eabi-objcopy -O srec "bootloader-apploader.axf" "bootloader-apploader.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "bootloader-apploader.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) bootloader-apploader.axf
	-@echo ' '

post-build:
	-"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/adapter_packs/commander/Commander.app/Contents/MacOS/commander" postbuild "/Users/joseheinz/SimplicityStudio/v5_workspace/bootloader-apploader/bootloader-apploader.slpb" --parameter build_dir:"/Users/joseheinz/SimplicityStudio/v5_workspace/bootloader-apploader/GNU ARM v12.2.1 - Default"
	-@echo ' '

.PHONY: all clean dependents main-build post-build

-include ../makefile.targets
