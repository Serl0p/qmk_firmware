/* Copyright 2025 Carlos Eduardo de Paula <carlosedp@gmail.com>
 * Copyright 2025 EPOMAKER <https://github.com/Epomaker>
 * Copyright 2023 LiWenLiu <https://github.com/LiuLiuQMK>
 * Copyright 2021 QMK <https://github.com/qmk/qmk_firmware>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define MATRIX_UNSELECT_DRIVE_HIGH
#define CORTEX_ENABLE_WFI_IDLE FALSE

/* Ensure we jump to bootloader if the RESET keycode was pressed */
#define EARLY_INIT_PERFORM_BOOTLOADER_JUMP TRUE

#ifndef NOP_FUDGE
#    define NOP_FUDGE 0.4
#endif

#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR  1151
#define EEPROM_SIZE 1152
#define FEE_PAGE_SIZE (0x200)
#define FEE_PAGE_COUNT (8)
#define FEE_PAGE_BASE_ADDRESS (0x1F000)
#define FEE_MCU_FLASH_SIZE (0x1000)
#define EECONFIG_USER_DATA_SIZE 4
#define EECONFIG_KB_DATA_SIZE 1
#define TRANSIENT_EEPROM_SIZE 4096

// BLE configuration for P65 (just replicating what I saw on the TH40)
// #define USER_BLE_ID (0X0065) // WHERE CAN I FIND THE ACTUAL P65 BLE ID? I'M JUST GUESSING HERE
// #define USER_BLE1_NAME "P65-1"
// #define USER_BLE2_NAME "P65-2"
// #define USER_BLE3_NAME "P65-3"

/* --- RGB / rdmctmzt_common keyboard_common requirements --- */

#define RGB_MATRIX_LED_COUNT 67
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_KEYRELEASES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_DISABLE_AFTER_TIMEOUT 0
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180
#define RGB_MATRIX_SLEEP

// Required by keyboard_common.h (placeholders for now; refine later)
#define LED_CONNECTION_INDEX 66
#define LED_CAP_INDEX        42
#define LED_WIN_L_INDEX      43
#define LED_BATT_INDEX       57

#define LED_BLE_1_INDEX      15
#define LED_BLE_2_INDEX      16
#define LED_BLE_3_INDEX      17
#define LED_2P4G_INDEX       18
#define LED_USB_INDEX        19


