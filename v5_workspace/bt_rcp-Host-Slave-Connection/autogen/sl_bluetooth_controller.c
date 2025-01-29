

#include <assert.h>
#include <stdbool.h>
#include <em_common.h>
#include "sl_rail_util_pa_config.h"
#include "sl_btctrl_linklayer.h"
#include "sl_btctrl_config.h"

#ifdef SL_COMPONENT_CATALOG_PRESENT
#include "sl_component_catalog.h"
#endif // SL_COMPONENT_CATALOG_PRESENT
#include "sl_bluetooth_advertiser_config.h"
#include "sl_bluetooth_connection_config.h"
#include "sl_btctrl_linklayer.h"
#include "sl_bt_periodic_advertiser_config.h"

#if defined(SL_CATALOG_BLUETOOTH_FEATURE_PHY_SUPPORT_CONFIG_PRESENT)
#include "sl_btctrl_phy_support_config.h"
#endif

#if defined(SL_CATALOG_BLUETOOTH_FEATURE_RESOLVING_LIST_PRESENT)
#include "sl_bt_resolving_list_config.h"
#endif

#if defined(SL_CATALOG_BLUETOOTH_FEATURE_ACCEPT_LIST_PRESENT)
#include "sl_bt_accept_list_config.h"
#endif

#if defined(SL_CATALOG_BLUETOOTH_FEATURE_CS_PRESENT) || defined(SL_CATALOG_BLUETOOTH_FEATURE_CS_TEST_PRESENT)
#include "sl_bluetooth_cs_config.h"
#endif

#ifndef SL_BT_CONFIG_MAX_CONNECTIONS
#define SL_BT_CONFIG_MAX_CONNECTIONS 0
#endif
#ifndef SL_BT_CONFIG_USER_ADVERTISERS
#define SL_BT_CONFIG_USER_ADVERTISERS 0
#endif
#ifndef SL_BT_CONFIG_ACCEPT_LIST_SIZE
#define SL_BT_CONFIG_ACCEPT_LIST_SIZE 0
#endif
#ifndef SL_BT_ACTIVATE_POWER_CONTROL
#define SL_BT_ACTIVATE_POWER_CONTROL 0
#endif
#ifndef SL_BT_CONFIG_RESOLVING_LIST_SIZE
#define SL_BT_CONFIG_RESOLVING_LIST_SIZE 0
#endif

void sl_bt_controller_init(void)
{
  if(sl_btctrl_is_initialized() == true)
  {
    return;
  }

#if defined(SL_CATALOG_BLUETOOTH_FEATURE_PHY_SUPPORT_CONFIG_PRESENT)
#if SL_BT_CONTROLLER_2M_PHY_SUPPORT == 0
  sl_btctrl_disable_2m_phy();
#endif
#if SL_BT_CONTROLLER_CODED_PHY_SUPPORT == 0
  sl_btctrl_disable_coded_phy();
#endif
#endif // SL_CATALOG_BLUETOOTH_FEATURE_PHY_SUPPORT_CONFIG_PRESENT

  sl_btctrl_init_mem(SL_BT_CONTROLLER_BUFFER_MEMORY);
  sl_btctrl_configure_le_buffer_size(SL_BT_CONTROLLER_LE_BUFFER_SIZE_MAX);

#if !defined(SL_CATALOG_KERNEL_PRESENT)
  sli_btctrl_events_init();
#endif // SL_CATALOG_KERNEL_PRESENT

  sl_btctrl_init_ll();
  sl_btctrl_init_adv();
  sl_btctrl_init_scan();
  sl_btctrl_init_conn();
  sl_btctrl_init_phy();
  sl_btctrl_init_adv_ext();
  sl_btctrl_init_scan_ext();
  sl_btctrl_alloc_periodic_adv(SL_BT_CONFIG_MAX_PERIODIC_ADVERTISERS);sl_btctrl_init_periodic_adv();

#if defined(SL_CATALOG_BLUETOOTH_FEATURE_CS_PRESENT) || defined(SL_CATALOG_BLUETOOTH_FEATURE_CS_TEST_PRESENT)
  struct sl_btctrl_cs_config cs_config = { 0 };
  cs_config.configs_per_connection = SL_BT_CONFIG_MAX_CS_CONFIGS_PER_CONNECTION;
  cs_config.procedures = SL_BT_CONFIG_MAX_CS_PROCEDURES;
  sl_btctrl_init_cs(&cs_config);
#endif // SL_CATALOG_BLUETOOTH_FEATURE_CS_PRESENT or SL_CATALOG_BLUETOOTH_FEATURE_CS_TEST_PRESENT

  sl_btctrl_init_basic(SL_BT_CONFIG_MAX_CONNECTIONS, SL_BT_CONFIG_USER_ADVERTISERS, SL_BT_CONFIG_ACCEPT_LIST_SIZE);

#if defined(SL_CATALOG_BLUETOOTH_FEATURE_RESOLVING_LIST_PRESENT)
  sl_btctrl_init_privacy();
  sl_status_t status = sl_btctrl_allocate_resolving_list_memory(SL_BT_CONFIG_RESOLVING_LIST_SIZE);
  assert(status == SL_STATUS_OK);
#endif

#if defined(SL_CATALOG_BLUETOOTH_FEATURE_AFH_PRESENT)
  sl_btctrl_init_afh(1);
#endif // SL_CATALOG_BLUETOOTH_FEATURE_AFH_PRESENT

#if defined(SL_CATALOG_BLUETOOTH_FEATURE_HIGH_POWER_PRESENT)
  sl_btctrl_init_highpower();
#endif // SL_CATALOG_BLUETOOTH_FEATURE_HIGH_POWER_PRESENT

#if defined(SL_CATALOG_BLUETOOTH_FEATURE_CONNECTION_PRESENT)
  sl_btctrl_configure_completed_packets_reporting(SL_BT_CONTROLLER_COMPLETED_PACKETS_THRESHOLD,
                                                  SL_BT_CONTROLLER_COMPLETED_PACKETS_EVENTS_TIMEOUT);
#endif // SL_CATALOG_BLUETOOTH_FEATURE_CONNECTION_PRESENT

#if defined(SL_CATALOG_BLUETOOTH_FEATURE_SCANNER_PRESENT)
  sl_btctrl_configure_max_queued_adv_reports(SL_BT_CONFIG_MAX_QUEUED_ADV_REPORTS);
#endif // SL_CATALOG_BLUETOOTH_FEATURE_SCANNER_PRESENT
}

sl_status_t sl_bt_ll_deinit();

void sl_bt_controller_deinit(void)
{
  if(sl_btctrl_is_initialized() == false){
    return;
  }

#if defined(SL_CATALOG_BLUETOOTH_FEATURE_RESOLVING_LIST_PRESENT)
  sl_btctrl_allocate_resolving_list_memory(0);
#endif

  sl_bt_ll_deinit();

  sl_btctrl_alloc_periodic_adv(0);

  sli_btctrl_deinit_mem();
}

