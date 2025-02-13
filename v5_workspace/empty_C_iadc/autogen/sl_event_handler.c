#include "sl_event_handler.h"

#include "em_chip.h"
#include "sl_device_init_nvic.h"
#include "sl_board_init.h"
#include "sl_device_init_dcdc.h"
#include "sl_device_init_lfxo.h"
#include "sl_device_init_hfxo.h"
#include "sl_device_init_clocks.h"
#include "sl_device_init_emu.h"
#include "sl_fem_util.h"
#include "pa_conversions_efr32.h"
#include "sl_rail_util_power_manager_init.h"
#include "sl_board_control.h"
#include "sl_bt_rtos_adaptation.h"
#include "sl_sleeptimer.h"
#include "app_log.h"
#include "sl_debug_swo.h"
#include "sl_gatt_service_aio.h"
#include "sl_iostream_debug.h"
#include "sl_iostream_stdlib_config.h"
#include "sl_mbedtls.h"
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
  sl_device_init_hfxo();
  sl_device_init_clocks();
  sl_device_init_emu();
  sl_board_init();
  osKernelInitialize();
  sl_power_manager_init();
}

void sl_kernel_start(void)
{
  sli_bt_rtos_adaptation_kernel_start();
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
  sl_iostream_stdlib_disable_buffering();
  sl_mbedtls_init();
  sl_iostream_init_instances();
}

void sl_stack_init(void)
{
  sl_fem_util_init();
  sl_rail_util_pa_init();
  sl_rail_util_power_manager_init();
  sl_bt_rtos_init();
}

void sl_internal_app_init(void)
{
  app_log_init();
}

void sl_iostream_init_instances(void)
{
  sl_iostream_debug_init();
}

