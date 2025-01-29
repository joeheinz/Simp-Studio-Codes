/***************************************************************************//**
 * @file
 * @brief Core application logic.
 *******************************************************************************
 * # License
 * <b>Copyright 2021 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#include "em_common.h"
#include "app_assert.h"
#include "app_log.h"
#include "sl_bluetooth.h"
#include "gatt_db.h"
#include "app.h"
#include "sl_simple_button_instances.h"
#include "sl_simple_led_instances.h"
#include "sl_sensor_imu.h"
#include "sl_sleeptimer.h"
#include "sl_imu.h"
#include "em_gpio.h"

//__________________New IADC 25.01.2025____________________________________
#include "em_iadc.h"
#include "em_cmu.h"
static void initIADC(void);

static void readIADC_and_notify(void);

//__



#define IMU_UPDATE_INTERVAL_MS 10
#define ADV_INTERVAL_MS        100

static uint8_t advertising_set_handle = 0xff;
static bool report_button_flag = false;

// Estructura unificada para datos IMU
typedef struct {
    int16_t accel[3];
    int16_t orient[3];
} imu_data_t;

// Prototipos optimizados
static void update_and_notify(uint16_t characteristic, const int16_t *data);
static void handle_imu_data(void);
static void start_advertising(void);


// ======== [INICIALIZACIÓN] ========
SL_WEAK void app_init(void) {
    sl_button_disable(SL_SIMPLE_BUTTON_INSTANCE(0));

    sl_sensor_imu_init();
    sl_imu_init();
    sl_imu_configure(IMU_UPDATE_INTERVAL_MS);
    sl_imu_calibrate_gyro();

    app_log_info("Sistema IMU inicializado");

    // new
    initIADC();
}

// ======== [BUCLE PRINCIPAL] ========
SL_WEAK void app_process_action(void) {
    static uint32_t last_update = 0;

    // Manejo de botón
    if (report_button_flag) {
        report_button_flag = false;
        uint8_t state = sl_button_get_state(SL_SIMPLE_BUTTON_INSTANCE(0));
        update_and_notify(gattdb_report_button, &state);
    }

    // Actualización IMU cada 10ms
    if ((sl_sleeptimer_get_tick_count() - last_update) >= sl_sleeptimer_ms_to_tick(IMU_UPDATE_INTERVAL_MS)) {
        last_update = sl_sleeptimer_get_tick_count();
        handle_imu_data();
        readIADC_and_notify(); //new
    }

}

// ======== [MANEJO IMU] ========
static void handle_imu_data(void) {
    imu_data_t data;
    sl_imu_update();

    sl_imu_get_acceleration(data.accel);
    sl_imu_get_orientation(data.orient);

    // Logging unificado
    app_log_info("Accel: X:%-5d Y:%-5d Z:%-5d | Orient: X:%-5d Y:%-5d Z:%-5d",
                data.accel[0], data.accel[1], data.accel[2],
                data.orient[0], data.orient[1], data.orient[2]);

    // Actualizar y notificar
    update_and_notify(gattdb_imu_acceleration, data.accel);
    update_and_notify(gattdb_imu_orientation, data.orient);
}

// ======== [FUNCIÓN BLE UNIFICADA] ========
static void update_and_notify(uint16_t characteristic, const int16_t *data) {
    uint8_t packet[6];
    for (int i = 0; i < 3; i++) {
        packet[i*2] = data[i];
        packet[(i*2)+1] = (data[i] >> 8) & 0xFF;
    }

    sl_status_t sc = sl_bt_gatt_server_write_attribute_value(characteristic, 0, sizeof(packet), packet);
    if (sc == SL_STATUS_OK) {
        sc = sl_bt_gatt_server_notify_all(characteristic, sizeof(packet), packet);
    }
    app_log_status(sc);
}

// ======== [EVENTOS BLE] ========
void sl_bt_on_event(sl_bt_msg_t *evt) {
    sl_status_t sc;

    switch (SL_BT_MSG_ID(evt->header)) {
        // Evento de arranque del sistema BLE
        case sl_bt_evt_system_boot_id:
            app_log_info("Sistema arrancado. Iniciando advertising...\n");
            // Crear y configurar advertising
            sc = sl_bt_advertiser_create_set(&advertising_set_handle);
            app_assert_status(sc);

            sc = sl_bt_legacy_advertiser_generate_data(advertising_set_handle,
                                                       sl_bt_advertiser_general_discoverable);
            app_assert_status(sc);

            sc = sl_bt_advertiser_set_timing(advertising_set_handle,
                                             (ADV_INTERVAL_MS * 16) / 10,
                                             (ADV_INTERVAL_MS * 16) / 10,
                                             0,
                                             0);
            app_assert_status(sc);

            // Iniciar advertising
            sc = sl_bt_legacy_advertiser_start(advertising_set_handle,
                                               sl_bt_legacy_advertiser_connectable);
            app_assert_status(sc);

            // Activar botón
            sl_button_enable(SL_SIMPLE_BUTTON_INSTANCE(0));
            break;

        // Evento de desconexión
        case sl_bt_evt_connection_closed_id:
            app_log_info("Conexión cerrada. Reiniciando advertising...\n");

            // Generar nuevos datos de advertising antes de reiniciar
            sc = sl_bt_legacy_advertiser_generate_data(advertising_set_handle,
                                                       sl_bt_advertiser_general_discoverable);
            app_assert_status(sc);

            // Reiniciar advertising
            sc = sl_bt_legacy_advertiser_start(advertising_set_handle,
                                               sl_bt_legacy_advertiser_connectable);
            app_assert_status(sc);
            break;

        // Evento de cambio en un atributo GATT
        case sl_bt_evt_gatt_server_attribute_value_id:
            if (evt->data.evt_gatt_server_attribute_value.attribute == gattdb_led_control) {
                uint8_t state;
                size_t len;

                sc = sl_bt_gatt_server_read_attribute_value(gattdb_led_control, 0, 1, &len, &state);
                app_assert_status(sc);

                if (state) {
                    sl_led_turn_on(SL_SIMPLE_LED_INSTANCE(0));
                    app_log_info("LED encendido.\n");
                } else {
                    sl_led_turn_off(SL_SIMPLE_LED_INSTANCE(0));
                    app_log_info("LED apagado.\n");
                }
            }
            break;

        // Otros eventos BLE
        default:
            break;
    }
}


// ======== [CONFIGURACIÓN ADVERTISING] ========

static void start_advertising(void) {
    sl_bt_advertiser_create_set(&advertising_set_handle);
    sl_bt_legacy_advertiser_generate_data(advertising_set_handle, sl_bt_advertiser_general_discoverable);
    sl_bt_advertiser_set_timing(advertising_set_handle,
                               (ADV_INTERVAL_MS * 16)/10,
                               (ADV_INTERVAL_MS * 16)/10, 0, 0);
    sl_bt_legacy_advertiser_start(advertising_set_handle, sl_bt_legacy_advertiser_connectable);
}



// ======== [MANEJO DE BOTÓN] ========
void sl_button_on_change(const sl_button_t *handle) {
    if (SL_SIMPLE_BUTTON_INSTANCE(0) == handle) {
        report_button_flag = true;
    }
}



//__________________Working for ONE port IADC 25.01.2025____________________________________
/*
// How many samples to capture
#define NUM_SAMPLES         1024

// Set CLK_ADC to 10 MHz
#define CLK_SRC_ADC_FREQ    20000000  // CLK_SRC_ADC
#define CLK_ADC_FREQ        10000000  // CLK_ADC - 10 MHz max in normal mode


//#define IADC_INPUT_0_PORT_PIN     iadcPosInputPortBPin0;
#define IADC_INPUT_0_PORT_PIN     iadcPosInputPadAna2; //ORIGINAL! PIN AIN2, 7 ON BOARD
//26.01.2025:
#define IADC_INPUT_1_PORT_PIN     iadcNegInputPadAna3;

void initIADC(void)
{
  // Declare initialization structures
  IADC_Init_t init = IADC_INIT_DEFAULT;
  IADC_AllConfigs_t initAllConfigs = IADC_ALLCONFIGS_DEFAULT;
  IADC_InitScan_t initScan = IADC_INITSCAN_DEFAULT;

  // Scan table structure
  IADC_ScanTable_t scanTable = IADC_SCANTABLE_DEFAULT;

  CMU_ClockEnable(cmuClock_IADC0, true);

  // Use the FSRC0 as the IADC clock so it can run in EM2
  CMU_ClockSelectSet(cmuClock_IADCCLK, cmuSelect_FSRCO);

  // Shutdown between conversions to reduce current
  init.warmup = iadcWarmupNormal;

  // Set the HFSCLK prescale value here
  init.srcClkPrescale = IADC_calcSrcClkPrescale(IADC0, CLK_SRC_ADC_FREQ, 0);


  initAllConfigs.configs[0].reference = iadcCfgReferenceInt1V2; //ORIGINAL DO NOT CHANGE
  initAllConfigs.configs[0].vRef = 3300;
  initAllConfigs.configs[0].osrHighSpeed = iadcCfgOsrHighSpeed2x;
  initAllConfigs.configs[0].analogGain = iadcCfgAnalogGain1x;  // Ganancia
  //initAllConfigs.configs[0].twosComplement = iadcCfgTwosCompBipolar;


  initAllConfigs.configs[0].adcClkPrescale = IADC_calcAdcClkPrescale(IADC0,
                                                                     CLK_ADC_FREQ,
                                                                     0,
                                                                     iadcCfgModeNormal,
                                                                     init.srcClkPrescale);


  initScan.triggerAction = iadcTriggerActionContinuous;
  initScan.dataValidLevel = iadcFifoCfgDvl2;
  initScan.fifoDmaWakeup = true;

  //26.01.2025:
  scanTable.entries[0].posInput = IADC_INPUT_0_PORT_PIN;
  scanTable.entries[0].negInput = iadcNegInputGnd;
  scanTable.entries[0].includeInScan = true;


  IADC_init(IADC0, &init, &initAllConfigs);

  uint32_t status = IADC0->STATUS;
  app_log_info("IADC STATUS: 0x%08X", status);

  // Initialize scan
  IADC_initScan(IADC0, &initScan, &scanTable);

  IADC_command(IADC0, iadcCmdStartScan);
  uint32_t postStartStatus = IADC0->STATUS;
  app_log_info("Post Start IADC STATUS: 0x%08X", postStartStatus);

}

// ======== [MANEJO IADC Y BLE] ========
// NUEVA FUNCIÓN: Leer y notificar el valor del ADC por BLE
static void readIADC_and_notify(void) {
    uint32_t iadcResult = IADC_pullScanFifoResult(IADC0).data; // Leer resultado del IADC
    app_log_info("FIFO: 0x%08X", iadcResult);
    uint8_t adcValue[2];
    adcValue[0] = iadcResult & 0xFF;
    adcValue[1] = (iadcResult >> 8) & 0xFF;

    app_log_info("IADC Value: %u", iadcResult);

    sl_status_t sc = sl_bt_gatt_server_write_attribute_value(gattdb_analog, 0, sizeof(adcValue), adcValue);
    if (sc == SL_STATUS_OK) {
        sc = sl_bt_gatt_server_notify_all(gattdb_analog, sizeof(adcValue), adcValue);
    }
    app_log_status(sc);
}
*/

//__________________Test for two port IADC 25.01.2025____________________________________

// How many samples to capture
#define NUM_SAMPLES         1024

// Set CLK_ADC to 10 MHz
#define CLK_SRC_ADC_FREQ    20000000  // CLK_SRC_ADC
#define CLK_ADC_FREQ        10000000  // CLK_ADC - 10 MHz max in normal mode

#define IADC_INPUT_0_PORT_PIN     iadcPosInputPortBPin0 // THIS WORKS!
#define IADC_INPUT_1_PORT_PIN     iadcNegInputGnd    // Ground reference

#define IADC_INPUT_2_PORT_PIN     iadcNegInputPortBPin3

#define IADC_INPUT_0_BUS          BBUSALLOC
#define IADC_INPUT_0_BUSALLOC     GPIO_BBUSALLOC_BEVEN0_ADC0
#define IADC_INPUT_1_BUS          BBUSALLOC
#define IADC_INPUT_1_BUSALLOC     GPIO_BBUSALLOC_BODD0_ADC0

/**************************************************************************//**
 * @brief IADC initialization
 *****************************************************************************/
void initIADC(void)
{
  GPIO_PinModeSet(gpioPortD, 2, gpioModePushPull, 0);
  GPIO_PinOutClear(gpioPortD, 2);

  GPIO_PinModeSet(gpioPortB, 0, gpioModePushPull, 0);
  GPIO_PinOutClear(gpioPortB, 0);

  GPIO_PinModeSet(gpioPortB, 3, gpioModePushPull, 0);
  GPIO_PinOutClear(gpioPortB, 3);

  GPIO_PinModeSet(gpioPortA, 0, gpioModePushPull, 0);
  GPIO_PinOutClear(gpioPortA, 0);

  GPIO_PinModeSet(gpioPortA, 4, gpioModePushPull, 0);
  GPIO_PinOutClear(gpioPortA, 4);

  GPIO_PinModeSet(gpioPortD, 2, gpioModePushPull, 0);
  GPIO_PinOutClear(gpioPortD, 2);

  GPIO_PinModeSet(gpioPortB, 2, gpioModePushPull, 0);
  GPIO_PinOutClear(gpioPortB, 2);

  // Declare initialization structures
  IADC_Init_t init = IADC_INIT_DEFAULT;
  IADC_AllConfigs_t initAllConfigs = IADC_ALLCONFIGS_DEFAULT;
  IADC_InitScan_t initScan = IADC_INITSCAN_DEFAULT;

  // Scan table structure
  IADC_ScanTable_t scanTable = IADC_SCANTABLE_DEFAULT;

  CMU_ClockEnable(cmuClock_IADC0, true);
  CMU_ClockEnable(cmuClock_GPIO, true);

  IADC_reset(IADC0);

  // Use FSRC0 as the IADC clock to allow operation in EM2
  CMU_ClockSelectSet(cmuClock_IADCCLK, cmuSelect_FSRCO);

  // Shutdown between conversions to reduce current
  init.warmup = iadcWarmupNormal;

  // Set HFSCLK prescale
  init.srcClkPrescale = IADC_calcSrcClkPrescale(IADC0, CLK_SRC_ADC_FREQ, 0);

  // Configure reference voltage and gain
  initAllConfigs.configs[0].reference = iadcCfgReferenceInt1V2; // Internal reference (1.2V)
  initAllConfigs.configs[0].vRef = 300;                        // Reference voltage in mV
  initAllConfigs.configs[0].analogGain = iadcCfgAnalogGain4x;   // Gain of 1x

  // Configure CLK_ADC prescale
  initAllConfigs.configs[0].adcClkPrescale = IADC_calcAdcClkPrescale(IADC0,
                                                                     CLK_ADC_FREQ,
                                                                     0,
                                                                     iadcCfgModeNormal,
                                                                     init.srcClkPrescale);

  // Configure scan mode
  initScan.triggerAction = iadcTriggerActionContinuous; // Continuous scan mode
  initScan.dataValidLevel = iadcFifoCfgDvl2;            // FIFO generates an interrupt after 2 entries
  initScan.fifoDmaWakeup = true;                        // Enable DMA wakeup on FIFO

  // Configure scan table for input channels
  scanTable.entries[0].posInput = IADC_INPUT_0_PORT_PIN; // POSITIVE
  scanTable.entries[0].negInput = IADC_INPUT_2_PORT_PIN; // NEGATIVE
  scanTable.entries[0].includeInScan = true;            // Include this channel in scan

  // Initialize IADC
  IADC_init(IADC0, &init, &initAllConfigs);
  IADC_initScan(IADC0, &initScan, &scanTable);

  // Configure GPIO analog bus for ADC inputs
  GPIO->IADC_INPUT_0_BUS |= IADC_INPUT_0_BUSALLOC;
  GPIO->IADC_INPUT_1_BUS |= IADC_INPUT_1_BUSALLOC;

  // Start scan conversion
  IADC_command(IADC0, iadcCmdStartScan);

  uint32_t status = IADC0->STATUS;
  app_log_info("IADC STATUS: 0x%08X", status);
}

/**************************************************************************//**
 * @brief Read and notify IADC value via BLE
 *****************************************************************************/
static void readIADC_and_notify(void)
{
  // Check if there is valid data in the FIFO
  if (IADC0->STATUS & IADC_STATUS_SCANFIFODV) {
    uint32_t iadcResult = IADC_pullScanFifoResult(IADC0).data; // Read result
    app_log_info("FIFO: 0x%08X", iadcResult);

    uint8_t adcValue[2];
    adcValue[0] = iadcResult & 0xFF;         // Lower byte
    adcValue[1] = (iadcResult >> 8) & 0xFF; // Upper byte

    app_log_info("IADC Value: %u", iadcResult);

    // Write ADC value to GATT characteristic
    sl_status_t sc = sl_bt_gatt_server_write_attribute_value(gattdb_analog, 0, sizeof(adcValue), adcValue);
    if (sc == SL_STATUS_OK) {
      sc = sl_bt_gatt_server_notify_all(gattdb_analog, sizeof(adcValue), adcValue);
    }
    app_log_status(sc);
  } else {
    app_log_warning("No valid data in FIFO.");
  }
}

