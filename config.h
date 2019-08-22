#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xBEEF
#define DEVICE_VER      0x0004
#define MANUFACTURER    Bouncepaw
#define PRODUCT         Sequira
#define DESCRIPTION     Ergonomic semichorded split keyboard
#define MATRIX_ROWS 8
#define MATRIX_COLS 6
#define MATRIX_ROW_PINS { F7, B1, B3, B2, C6, D7, E6, B4 }
#define MATRIX_COL_PINS { D4, D0, D1, F4, F5, F6 }
#define DIODE_DIRECTION COL2ROW
#define TAPPING_TERM 300
#define MODTAP_TERM 300
#define DEBOUNCING_DELAY 5
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE
#define COMBO_COUNT 40
#endif
