/* Copyright 2025 Epomaker
 * Copyright 2025 Epomaker <hhttps://github.com/Epomaker>
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

#include "../../../lib/rdr_lib/rdr_common.h"

/**********************系统函数***************************/
/*  键盘扫描按键延时 */
void matrix_io_delay(void) {
}

void matrix_output_select_delay(void) {
}

void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
}

led_config_t g_led_config = { {
    { 0        , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   },
	{ NO_LED   , 1        , 2        , 3        , 4        , 5        , 6        , 7        , 8        , 9        , 10       , 11       , 12       , 13       , NO_LED   , NO_LED   },
	{ 14       , 15       , 16       , 17       , 18       , 19       , 20       , 21       , 22       , 23       , 24       , 25       , 26       , 27       , 28       , NO_LED   },
	{ 29       , 31       , 32       , 33       , 34       , 35       , 36       , 37       , 38       , 39       , 40       , 41       , NO_LED   , 42       , 43       , 57       },
	{ 44       , NO_LED   , 45       , 46       , 47       , 48       , 49       , 50       , 51       , 52       , 53       , 54       , NO_LED   , 55       , 56       , NO_LED   },
	{ 58       , 59       , 60       , 30       , NO_LED   , 61       , NO_LED   , NO_LED   , NO_LED   , 62       , 63       , NO_LED   , NO_LED   , 64       , 65       , 66       }
},{
    { 0,  10},  { 15, 10}, { 30, 10}, { 45, 10}, { 60, 10}, { 75, 10}, { 90, 10}, {105, 10}, {120, 10}, { 135, 10}, { 150, 10}, { 165, 10}, { 180, 10},             { 202, 10},
    { 4,  20},  { 22, 20}, { 37, 20}, { 52, 20}, { 67, 20}, { 82, 20}, { 97, 20}, {112, 20}, {127, 20}, { 142, 20}, { 157, 20}, { 172, 20}, { 187, 20}, { 205, 20},             { 224, 20},
    { 0,  30},  {  7, 30}, { 25, 30}, { 40, 30}, { 55, 30}, { 70, 30}, { 85, 30}, {100, 30}, {115, 30}, { 130, 30}, { 145, 30}, { 160, 30}, { 175, 30},             { 202, 30}, { 224, 30},
    { 7,  40},             { 32, 40}, { 47, 40}, { 62, 40}, { 77, 40}, { 92, 40}, {107, 40}, {122, 40}, { 137, 40}, { 152, 40}, { 167, 40},             { 185, 40}, { 210, 40}, { 224, 40},
    { 0,  50},  { 18, 50}, { 37, 50},                                  { 92, 50},                                   { 150, 50}, { 168, 50},             { 195, 50}, { 210, 50}, { 224, 50}
}, {
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,  1,
    1,      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,  1,  1,
    1,  1,  1,              1,              1,  1,      1,  1,  1
} };

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    User_Point_Show();
    return false;
}

void notify_usb_device_state_change_user(enum usb_device_state usb_device_state)  {
    if (Keyboard_Info.Key_Mode == QMK_USB_MODE) {
        if(usb_device_state == USB_DEVICE_STATE_CONFIGURED) {
            Usb_If_Ok = true;//usb枚举完成
            Usb_If_Ok_Led = true;
            Usb_If_Ok_Delay = 0;
        } else {
            Usb_If_Ok = false;
		    Usb_If_Ok_Led = false;
        }
    } else {
        Usb_If_Ok = false;
	    Usb_If_Ok_Led = false;
    }
}

void housekeeping_task_user(void) {
    if(User_State_Fulfill_Flag){
        User_Keyboard_Reset();
        User_State_Fulfill_Flag = 0x00;
    }

    es_chibios_user_idle_loop_hook();
}

void board_init(void) {
    User_Keyboard_Init();
}

void keyboard_post_init_user(void) {
    User_Keyboard_Post_Init();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {   /*键盘只要有按键按下就会调用此函数*/
    Usb_Change_Mode_Delay = 0;                                      /*只要有按键就不会进入休眠*/
    Usb_Change_Mode_Wakeup = false;

    return Key_Value_Dispose(keycode, record);
}
