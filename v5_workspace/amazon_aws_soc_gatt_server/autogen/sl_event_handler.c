#include "sl_event_handler.h"

#include "em_chip.h"
#include "sl_device_init_nvic.h"
#include "sl_board_init.h"
#include "sl_device_init_dcdc.h"
#include "sl_device_init_lfxo.h"
#include "sl_hfxo_manager.h"
#include "sl_device_init_hfxo.h"
#include "sl_device_init_lfrco.h"
#include "sl_device_init_clocks.h"
#include "sl_device_init_emu.h"
#include "pa_conversions_efr32.h"
#include "sl_rail_util_power_manager_init.h"
#include "btl_interface.h"
#include "sl_board_control.h"
#include "sl_bt_rtos_adaptation.h"
#include "sl_sleeptimer.h"
#include "sl_debug_swo.h"
#include "sl_iostream_init_usart_instances.h"
#include "sl_bt_hal_event_handler.h"
#include "sl_mbedtls.h"
#include "nvm3_default.h"
#include "psa/crypto.h"
#include "sli_protocol_crypto.h"
#include "cmsis_os2.h"
#include "sl_iostream_init_instances.h"
#include "sl_bluetooth.h"
#include "sl_power_manager.h"
#include "sl_cos.h"

void sl_platform_init(void)
{
  CHIP_Init();
  sl_device_init_nvic();
  sl_board_preinit();
  sl_device_init_dcdc();
  sl_device_init_lfxo();
  sl_hfxo_manager_init_hardware();
  sl_device_init_hfxo();
  sl_device_init_lfrco();
  sl_device_init_clocks();
  sl_device_init_emu();
  sl_board_init();
  bootloader_init();
  nvm3_initDefault();
  osKernelInitialize();
  sl_power_manager_init();
}

void sl_kernel_start(void)
{
  sli_bt_rtos_adaptation_kernel_start();
  sl_bt_hal_on_kernel_start();
  osKernelStart();
}

void sl_driver_init(void)
{
  sl_debug_swo_init();
  sl_cos_send_config();
}

void sl_service_init(void)
{
  sl_board_configure_vcom();
  sl_sleeptimer_init();
  sl_hfxo_manager_init();
  sl_mbedtls_init();
  psa_crypto_init();
  sli_aes_seed_mask();
  sl_iostream_init_instances();
}

void sl_stack_init(void)
{
  sl_rail_util_pa_init();
  sl_rail_util_power_manager_init();
  sl_bt_rtos_init();
}

void sl_internal_app_init(void)
{
}

void sl_iostream_init_instances(void)
{
  sl_iostream_usart_init_instances();
}

