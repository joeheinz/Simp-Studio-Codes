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
#include "sl_sensor_imu.h"          // IMU Sensor API
#include "sl_sleeptimer.h"
#include "sl_imu.h"

// The advertising set handle allocated from Bluetooth stack.
static uint8_t advertising_set_handle = 0xff;

static bool report_button_flag = false;

// Updates the Report Button characteristic.
static sl_status_t update_report_button_characteristic(void);
// Sends notification of the Report Button characteristic.
static sl_status_t send_report_button_notification(void);

//For the IMU:
static sl_status_t update_report_imu_characteristic(void);
static sl_status_t send_report_imu_notification(void);

static sl_status_t update_report_imu_characteristic_orient(void);
static sl_status_t send_report_imu_notification_orient(void);

/**************************************************************************//**
 * Application Init.
 *****************************************************************************/
SL_WEAK void app_init(void)
{
  // Make sure there will be no button events before the boot event.
  sl_button_disable(SL_SIMPLE_BUTTON_INSTANCE(0));

  /////////////////////////////////////////////////////////////////////////////
  // Put your additional application init code here!                         //
  // This is called once during start-up.                                    //
  /////////////////////////////////////////////////////////////////////////////#

  sl_sensor_imu_init();
  sl_imu_init();
  sl_imu_configure(10);
  sl_imu_calibrate_gyro();

  app_log_info("G2 electronics");
  app_log_info("Tensosense, IMU succesfully initialized.");
}

/**************************************************************************//**
 * Application Process Action.
 *****************************************************************************/
SL_WEAK void app_process_action(void)
{
  // Check if there was a report button interaction.
  if (report_button_flag) {
    sl_status_t sc;

    report_button_flag = false; // Reset flag

    sc = update_report_button_characteristic();
    app_log_status_error(sc);

    if (sc == SL_STATUS_OK) {
      sc = send_report_button_notification();
      app_log_status_error(sc);
    }
  }

  /////////////////////////////////////////////////////////////////////////////
  // Put your additional application code here!                              //
  // This is called infinitely.                                              //
  // Do not call blocking functions from here!                               //
  /////////////////////////////////////////////////////////////////////////////

  sl_imu_update();  //updates the sensor for the first time.
  int16_t avec[3];  //creates the variable for the three values of acceleration
  int16_t ovec[3];
  sl_imu_get_acceleration(avec); //gets the acceleration value to avec
  sl_imu_get_orientation(ovec);
  app_log_info("Acceleration (m/s^2): X: %d, Y: %d, Z: %d\n",
               avec[0], avec[1], avec[2]); //Logs the acceleration
  app_log_info("Orientation (): X: %d, Y: %d, Z: %d\n",
                 ovec[0], ovec[1], ovec[2]); //Logs the orientation
  static uint32_t last_read_time = 0; //For the timmer nigga
  uint32_t current_time = sl_sleeptimer_get_tick_count(); //Gets the current time

  if((current_time - last_read_time) >= sl_sleeptimer_ms_to_tick(10)) {
      last_read_time = current_time;
      sl_status_t floyd = update_report_imu_characteristic(); //update IMU data
      sl_status_t fentanyl = update_report_imu_characteristic_orient();
      app_log_status(floyd);
      app_log_status(fentanyl);
      if (floyd == SL_STATUS_OK) {
          floyd = send_report_imu_notification();
          fentanyl = send_report_imu_notification_orient();
          app_log_status(floyd);
          app_log_status(fentanyl);
      }
  }
}

/***
 * Functions for the report via Bluetooth of the IMU sensor.
 * ACCELERATION
 * @param evt
 */
static sl_status_t update_report_imu_characteristic(void) //FOR THE GATT!
{
  sl_status_t sc;
  int16_t avec[3]; // Acceleration data
  uint8_t data_send[6]; // 3 axes * 2 bytes each
  sl_imu_update();
  // Get the acceleration data
  sl_imu_get_acceleration(avec);

  // Pack data into bytes
  data_send[0] = avec[0];
  data_send[1] = (avec[0] >> 8) & 0xFF;
  data_send[2] = avec[1];
  data_send[3] = (avec[1] >> 8) & 0xFF;
  data_send[4] = avec[2];
  data_send[5] = (avec[2] >> 8) & 0xFF;

  // Write to GATT database
  sc = sl_bt_gatt_server_write_attribute_value(gattdb_imu_acceleration,
                                               0,
                                               sizeof(data_send),
                                               data_send);
  if (sc == SL_STATUS_OK) {
    app_log_info("IMU acceleration data written to GATT: X=%d, Y=%d, Z=%d\n",
                 avec[0], avec[1], avec[2]);
  } else {
    app_log_error("Failed to write IMU data to GATT. Status: %lu\n", sc);
  }
  return sc;
}

static sl_status_t send_report_imu_notification(void) //Actually sending BLE
{
  sl_status_t sc;
  int16_t avec[3];
  uint8_t data_send[6];
  sl_imu_update();
  // Get acceleration data
  sl_imu_get_acceleration(avec);

  // Pack data into bytes
  data_send[0] = avec[0] ;
  data_send[1] = (avec[0] >> 8) & 0xFF;
  data_send[2] = avec[1] ;
  data_send[3] = (avec[1] >> 8) & 0xFF;
  data_send[4] = avec[2] ;
  data_send[5] = (avec[2] >> 8) & 0xFF;

  // Send notification
  sc = sl_bt_gatt_server_notify_all(gattdb_imu_acceleration,
                                    sizeof(data_send),
                                    data_send);
  if (sc == SL_STATUS_OK) {
    app_log_info("IMU notification sent: X=%d, Y=%d, Z=%d\n",
                 avec[0], avec[1], avec[2]);
  } else {
    app_log_error("Failed to send IMU notification. Status: 0x%lu", sc);
  }
  return sc;
}

/***
 * FOR ORIENTATION:
 * @return
 */

static sl_status_t update_report_imu_characteristic_orient(void) //FOR THE GATT!
{
  sl_status_t sc;
  int16_t avec[3]; // Acceleration data
  uint8_t data_send[6]; // 3 axes * 2 bytes each
  sl_imu_update();
  // Get the acceleration data
  sl_imu_get_orientation(avec);

  // Pack data into bytes
  data_send[0] = avec[0];
  data_send[1] = (avec[0] >> 8) & 0xFF;
  data_send[2] = avec[1];
  data_send[3] = (avec[1] >> 8) & 0xFF;
  data_send[4] = avec[2];
  data_send[5] = (avec[2] >> 8) & 0xFF;

  // Write to GATT database
  sc = sl_bt_gatt_server_write_attribute_value(gattdb_imu_orientation,
                                               0,
                                               sizeof(data_send),
                                               data_send);
  if (sc == SL_STATUS_OK) {
    app_log_info("IMU Orientation data written to GATT: X=%d, Y=%d, Z=%d\n",
                 avec[0], avec[1], avec[2]);
  } else {
    app_log_error("Failed to write IMU data to GATT. Status: %lu\n", sc);
  }
  return sc;
}

static sl_status_t send_report_imu_notification_orient(void) //Actually sending BLE
{
  sl_status_t sc;
  int16_t avec[3];
  uint8_t data_send[6];
  sl_imu_update();
  // Get acceleration data
  sl_imu_get_orientation(avec);

  // Pack data into bytes
  data_send[0] = avec[0] ;
  data_send[1] = (avec[0] >> 8) & 0xFF;
  data_send[2] = avec[1] ;
  data_send[3] = (avec[1] >> 8) & 0xFF;
  data_send[4] = avec[2] ;
  data_send[5] = (avec[2] >> 8) & 0xFF;

  // Send notification
  sc = sl_bt_gatt_server_notify_all(gattdb_imu_orientation,
                                    sizeof(data_send),
                                    data_send);
  if (sc == SL_STATUS_OK) {
    app_log_info("IMU notification sent: X=%d, Y=%d, Z=%d\n",
                 avec[0], avec[1], avec[2]);
  } else {
    app_log_error("Failed to send IMU notification. Status: 0x%lu", sc);
  }
  return sc;
}





/**************************************************************************//**
 * Bluetooth stack event handler.
 * This overrides the dummy weak implementation.
 *
 * @param[in] evt Event coming from the Bluetooth stack.
 *****************************************************************************/
void sl_bt_on_event(sl_bt_msg_t *evt)
{
  sl_status_t sc;

  switch (SL_BT_MSG_ID(evt->header)) {
    // -------------------------------
    // This event indicates the device has started and the radio is ready.
    // Do not call any stack command before receiving this boot event!
    case sl_bt_evt_system_boot_id:
      // Create an advertising set.
      sc = sl_bt_advertiser_create_set(&advertising_set_handle);
      app_assert_status(sc);

      // Generate data for advertising
      sc = sl_bt_legacy_advertiser_generate_data(advertising_set_handle,
                                                 sl_bt_advertiser_general_discoverable);
      app_assert_status(sc);

      // Set advertising interval to 100ms.
      sc = sl_bt_advertiser_set_timing(
        advertising_set_handle,
        160, // min. adv. interval (milliseconds * 1.6)
        160, // max. adv. interval (milliseconds * 1.6)
        0,   // adv. duration
        0);  // max. num. adv. events
      app_assert_status(sc);

      // Start advertising and enable connections.
      sc = sl_bt_legacy_advertiser_start(advertising_set_handle,
                                         sl_bt_legacy_advertiser_connectable);
      app_assert_status(sc);

      // Button events can be received from now on.
      sl_button_enable(SL_SIMPLE_BUTTON_INSTANCE(0));

      // Check the report button state, then update the characteristic and
      // send notification.
      sc = update_report_button_characteristic();
      app_log_status_error(sc);

      if (sc == SL_STATUS_OK) {
        sc = send_report_button_notification();
        app_log_status_error(sc);
      }
      break;

    // -------------------------------
    // This event indicates that a new connection was opened.
    case sl_bt_evt_connection_opened_id:
      app_log_info("Connection opened.\n");
      break;

    // -------------------------------
    // This event indicates that a connection was closed.
    case sl_bt_evt_connection_closed_id:
      app_log_info("Connection closed.\n");

      // Generate data for advertising
      sc = sl_bt_legacy_advertiser_generate_data(advertising_set_handle,
                                                 sl_bt_advertiser_general_discoverable);
      app_assert_status(sc);

      // Restart advertising after client has disconnected.
      sc = sl_bt_legacy_advertiser_start(advertising_set_handle,
                                         sl_bt_legacy_advertiser_connectable);
      app_assert_status(sc);
      break;

    // -------------------------------
    // This event indicates that the value of an attribute in the local GATT
    // database was changed by a remote GATT client.
    case sl_bt_evt_gatt_server_attribute_value_id:
      // The value of the gattdb_led_control characteristic was changed.
      if (gattdb_led_control == evt->data.evt_gatt_server_attribute_value.attribute) {
        uint8_t data_recv;
        size_t data_recv_len;

        // Read characteristic value.
        sc = sl_bt_gatt_server_read_attribute_value(gattdb_led_control,
                                                    0,
                                                    sizeof(data_recv),
                                                    &data_recv_len,
                                                    &data_recv);
        (void)data_recv_len;
        app_log_status_error(sc);

        if (sc != SL_STATUS_OK) {
          break;
        }

        // Toggle LED.
        if (data_recv == 0x00) {
          sl_led_turn_off(SL_SIMPLE_LED_INSTANCE(0));
          app_log_info("LED off.\n");
        } else if (data_recv == 0x01) {
          sl_led_turn_on(SL_SIMPLE_LED_INSTANCE(0));
          app_log_info("LED on.\n");
        } else {
          app_log_error("Invalid attribute value: 0x%02x\n", (int)data_recv);
        }
      }
      break;

    // -------------------------------
    // This event occurs when the remote device enabled or disabled the
    // notification.
    case sl_bt_evt_gatt_server_characteristic_status_id:
      if (gattdb_report_button == evt->data.evt_gatt_server_characteristic_status.characteristic) {
        // A local Client Characteristic Configuration descriptor was changed in
        // the gattdb_report_button characteristic.
        if (evt->data.evt_gatt_server_characteristic_status.client_config_flags
            & sl_bt_gatt_notification) {
          // The client just enabled the notification. Send notification of the
          // current button state stored in the local GATT table.
          app_log_info("Notification enabled.");

          sc = send_report_button_notification();
          app_log_status_error(sc);
        } else {
          app_log_info("Notification disabled.\n");
        }
      }
      break;

    ///////////////////////////////////////////////////////////////////////////
    // Add additional event handlers here as your application requires!      //
    ///////////////////////////////////////////////////////////////////////////

    // -------------------------------
    // Default event handler.
    default:
      break;
  }
}

/***************************************************************************//**
 * Simple Button
 * Button state changed callback
 * @param[in] handle Button event handle
 ******************************************************************************/
void sl_button_on_change(const sl_button_t *handle)
{
  if (SL_SIMPLE_BUTTON_INSTANCE(0) == handle) {
    report_button_flag = true;
  }
}

/***************************************************************************//**
 * Updates the Report Button characteristic.
 *
 * Checks the current button state and then writes it into the local GATT table.
 ******************************************************************************/
static sl_status_t update_report_button_characteristic(void)
{
  sl_status_t sc;
  uint8_t data_send;

  switch (sl_button_get_state(SL_SIMPLE_BUTTON_INSTANCE(0))) {
    case SL_SIMPLE_BUTTON_PRESSED:
      data_send = (uint8_t)SL_SIMPLE_BUTTON_PRESSED;
      break;

    case SL_SIMPLE_BUTTON_RELEASED:
      data_send = (uint8_t)SL_SIMPLE_BUTTON_RELEASED;
      break;

    default:
      // Invalid button state
      return SL_STATUS_FAIL; // Invalid button state
  }

  // Write attribute in the local GATT database.
  sc = sl_bt_gatt_server_write_attribute_value(gattdb_report_button,
                                               0,
                                               sizeof(data_send),
                                               &data_send);
  if (sc == SL_STATUS_OK) {
    app_log_info("Attribute written: 0x%02x", (int)data_send);
  }

  return sc;
}

/***************************************************************************//**
 * Sends notification of the Report Button characteristic.
 *
 * Reads the current button state from the local GATT database and sends it as a
 * notification.
 ******************************************************************************/
static sl_status_t send_report_button_notification(void)
{
  sl_status_t sc;
  uint8_t data_send;
  size_t data_len;

  // Read report button characteristic stored in local GATT database.
  sc = sl_bt_gatt_server_read_attribute_value(gattdb_report_button,
                                              0,
                                              sizeof(data_send),
                                              &data_len,
                                              &data_send);
  if (sc != SL_STATUS_OK) {
    return sc;
  }

  // Send characteristic notification.
  sc = sl_bt_gatt_server_notify_all(gattdb_report_button,
                                    sizeof(data_send),
                                    &data_send);
  if (sc == SL_STATUS_OK) {
    app_log_append(" Notification sent: 0x%02x\n", (int)data_send);
  }
  return sc;
}
