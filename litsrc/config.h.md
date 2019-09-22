# Keyboard configuration

```c
#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"
```

## defconst USB Device

- `VENDOR_ID       0xFEED`
- `PRODUCT_ID      0xBEEF`
- `DEVICE_VER      0x0005`
  I increment this value after any serious change to the code.
- `MANUFACTURER    Bouncepaw`
- `PRODUCT         Sequira`
- `DESCRIPTION     Ergonomic semichorded split keyboard`

## defconst Matrix

See [Sparkfun docs](https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/hardware-overview-pro-micro) for Pro micro pinout.

- `MATRIX_ROWS 8`
- `MATRIX_COLS 6`
- `MATRIX_ROW_PINS { F7, B1, B3, B2, C6, D7, E6, B4 }`
- `MATRIX_COL_PINS { D4, D0, D1, F4, F5, F6 }`
- `DIODE_DIRECTION COL2ROW`
  Could have been `ROW2COL`.

## defconst Time delays

- `TAPPING_TERM 150`
- `MODTAP_TERM 150`
  Used with custom modifiers.
- `DEBOUNCING_DELAY 5`

## defconst Others

- `LOCKING_SUPPORT_ENABLE`
  Mechanical locking support. Use `KC_LCAP`, `KC_LNUM` or `KC_LSCR` instead in keymap.
- `LOCKING_RESYNC_ENABLE`
  Locking resynchronize hack.
- `COMBO_COUNT 26`
  Number of chords user. Check with `ruby chordgen.rb --count-chords`.

```c
#endif
```

