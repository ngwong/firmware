/*
 * Copyright (c) 2018 Particle Industries, Inc.  All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "app_util_platform.h"

// This configuration overrides the defaults defined in the following files of the nRF SDK:
//
// modules/nrfx/templates/nRF52840/nrfx_config.h
// config/nrf52840/config/sdk_config.h

#define NRFX_GPIOTE_ENABLED                             1
#define GPIOTE_CONFIG_IRQ_PRIORITY                      APP_IRQ_PRIORITY_HIGH
#define NRFX_GPIOTE_CONFIG_NUM_OF_LOW_POWER_EVENTS      8

#define NRFX_RTC_ENABLED  0
#define NRFX_RTC0_ENABLED 0 // Used by SoftDevice
#define NRFX_RTC1_ENABLED 0 // Reserved for FreeRTOS
#define NRFX_RTC2_ENABLED 0 // FIXME: Used by OpenThread

#define NRFX_ADC_ENABLED 0

#define NRFX_SPIM_NRF52_ANOMALY_109_WORKAROUND_ENABLED 0
#define NRFX_PWM_NRF52_ANOMALY_109_WORKAROUND_ENABLED 0
#define NRFX_SPIS_NRF52_ANOMALY_109_WORKAROUND_ENABLED 0
#define NRFX_TWIM_NRF52_ANOMALY_109_WORKAROUND_ENABLED 0

#define CLOCK_ENABLED 1

#define POWER_ENABLED 1

#define RNG_ENABLED 1

#define USBD_ENABLED 1
#define NRF_DRV_USBD_ERRATA_ENABLE 1

#define NRF_SDH_ENABLED 1
#define NRF_SDH_SOC_ENABLED 1
#define NRF_SDH_BLE_ENABLED 1
#define NRF_SDH_BLE_VS_UUID_COUNT 2 // 1 base UUID is reserved for the system
#define NRF_SDH_BLE_PERIPHERAL_LINK_COUNT 1
#define NRF_SDH_BLE_GAP_DATA_LENGTH 251 // Requested BLE GAP data length to be negotiated
#define NRF_SDH_BLE_GATT_MAX_MTU_SIZE 247 // Static maximum MTU size

#define NRF_FSTORAGE_ENABLED 1
#define CRC32_ENABLED 1

#define NRF_BLE_GATT_ENABLED 1

#define BLE_ADVERTISING_ENABLED 1

#define APP_FIFO_ENABLED 1

#define NRF_QUEUE_ENABLED 1

// <4=> Read4IO
#define NRFX_QSPI_CONFIG_READOC 4

// <3=> PP4IO
#define NRFX_QSPI_CONFIG_WRITEOC 3

// <0=> 32MHz/1
// Ze fastest!
#define NRFX_QSPI_CONFIG_FREQUENCY 0

#ifdef DEBUG_BUILD
#define SEGGER_RTT_CONFIG_DEFAULT_MODE 1 // Do not block, output as much as fits
#define SEGGER_RTT_CONFIG_BUFFER_SIZE_UP 16384
#define SEGGER_RTT_CONFIG_MAX_NUM_UP_BUFFERS 2
#define SEGGER_RTT_CONFIG_BUFFER_SIZE_DOWN 16
#define SEGGER_RTT_CONFIG_MAX_NUM_DOWN_BUFFERS 2
#endif

#define NRFX_PRS_ENABLED        1
#define NRFX_UART_ENABLED       0
#define NRFX_UARTE_ENABLED      1
#define NRFX_LPCOMP_ENABLED     0
#define NRFX_TWI_ENABLED        0
#define NRFX_TWIM_ENABLED       0
#define NRFX_TWIS_ENABLED       0

#define NRFX_SPIM_ENABLED       1
#define NRFX_SPIM2_ENABLED      1
#define NRFX_SPIM3_ENABLED      1
#define NRFX_SPIM3_NRF52840_ANOMALY_198_WORKAROUND_ENABLED 1