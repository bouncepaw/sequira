/*
Copyright 2019 Timur Ismagilov <bouncepaw2@ya.ru>

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

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xBEEF
#define DEVICE_VER      0x0003
#define MANUFACTURER    Bouncepaw
#define PRODUCT         Sequira
#define DESCRIPTION     Ergonomic semichorded split keyboard

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

#define TAPPING_TERM 300
#define MODTAP_TERM 300

// wiring of each half
#define MATRIX_ROW_PINS { F7, B1, B3, B2, C6, D7, E6, B4 }
#define MATRIX_COL_PINS { D4, D0, D1, F4, F5, F6 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


#define COMBO_COUNT 55

#endif
