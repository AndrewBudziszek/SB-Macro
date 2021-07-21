/*
Copyright 2021 Andrew Budziszek

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0xa455
#define PRODUCT_ID   0x01A4
#define DEVICE_VER   0x0001
#define MANUFACTURER SonBrooks
#define PRODUCT      sb_macro

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 6
#define DIRECT_PINS { { B5, D4, C6, D7, E6, B4 } }
/*
    RE, 1, 2, 3, 4, 5
*/


/* RGB configuration */
#define RGB_DI_PIN B6
#define RGBLED_NUM 5
#define RGBLIGHT_DEFAULT_HUE 201
#define RGBLIGHT_ANIMATIONS RGBLIGHT_MODE_RGB_TEST

/* Rotary Encoder */
#define ENCODERS_PAD_A { B2 }
#define ENCODERS_PAD_B { B3 }
#define ENCODER_RESOLUTION 4

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5