# Keymap

```c
#include QMK_KEYBOARD_H
#include "layermode.h"

// TODO. Get rid of this.
#define RC8(mod) register_code(KC_##mod)
#define UC8(mod) unregister_code(KC_##mod)
#define TC8(kc) tap_code(KC_##kc)
#define FLX(mod, kc) RC8(mod); TC8(kc); UC8(mod);
// Shift PRess
#define spr(kc) FLX(LSFT, kc);
// Alt PRess
#define apr(kc) FLX(RALT, kc);
```

```c
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
  {
   [LATIN] =
   {
    HALFL(KC_DQUO, KC_Z, KC_P, KC_R, KC_D, KC_Q,
          KC_H,    KC_S, KC_T, KC_N, LT(ASTRA, KC_COMM),
          KC_Y,    KC_K, KC_M, KC_C, KC_MINS),
    HALFR(KC_X,    KC_F, KC_W, KC_U, KC_J, KC_QUOT,
          KC_E,    KC_O, KC_I, KC_L, KC_DOT,
          KC_A,    KC_V, KC_B, KC_G, KC_SCLN)
   },
   [CYRILLIC] =
   {
    HALFL(RU_ZH, RU_CH, RU_P,  RU_R, RU_D, RU_F,
          RU_V, RU_S,  RU_T, RU_N, ASTRARUS,
          RU_J, RU_Z, RU_M, RU_K, RU_MINUS),
    HALFR(RU_TS, RU_SOFT, RU_JA, RU_U, RU_H, RU_E,
          RU_JE, RU_O, RU_I, RU_L, RU_DOT,
          RU_A,  RU_Y, RU_B, RU_G, RU_SCLN)
   },
   [MOON] =
   {
    HALFL(KC_F13,  KC_7,    KC_6, KC_5, KC_4, KC_F14,
          KC_3,    KC_2,    KC_1, KC_0, LCTL(LSFT(KC_TAB)),
          KC_PAUS, KC_PSCR, KC_8, KC_9, KC_INS),
    HALFR(KC_F15,  KC_HOME, KC_UP,   KC_END,  KC_APP, KC_F16,
          KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, LCTL(KC_TAB),
          KC_MPRV, KC_MPLY, KC_MNXT, KC_PGDN, KC_F19)
   },
   [SUN] =
   {
    HALFL(RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   LCTL(KC_X),
          KC_F5,   KC_F6,   KC_F7,   KC_F8,   LCTL(KC_INS),
          KC_F9,   KC_F10,  KC_F11,  KC_F12,  LSFT(KC_INS)),
    HALFR(KC_MS_BTN3, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_L, KC_WH_R,
          KC_MS_L,    KC_MS_D, KC_MS_R, KC_WH_U, LCTL(KC_Z),
          KC_VOLD,    KC_MUTE, KC_VOLU, KC_WH_D, LSFT(KC_Y))
   },
   [ASTRA] =
   {
     HALFL(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	   APIPE,   KC_TRNS, AMDASH,  AGRAVE,  ASTRA,
	   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, AATDOG),
     HALFR(KC_TRNS, AAMP,    KC_PLUS, KC_TRNS, KC_TRNS, KC_TRNS,
	   AHASH,   ATILDE,  ADOLLAR, ACIRC,   KC_ASTR,
	   AGUILL,  AEMOT,   KC_PERC, KC_TRNS, KC_TRNS)
   }
  };
```

## Language switching

In the future it will be possible to select a way of switching layouts: with Ctrl+Shift, with Alt+Shift, with Ctrl+Space, with CapsLock. For now only CapsLock is supported.

```c
// Will be used later. For now, it does barely nothing.
enum LanguageSwitchType {
  LS_CTRL_SHIFT,
  LS_ALT_SHIFT,
  LS_CTRL_SPACE,
  LS_CAPS_LOCK,
} language_switch_type = LS_CAPS_LOCK;
```

### fn toggle_language
> void

- `void`

Cycle between QWERTY and ЙЦУКЕН.

```c
layer_invert(CYRILLIC);
switch (language_switch_type) {
  case LS_CTRL_SHIFT:
  case LS_ALT_SHIFT:
  case LS_CTRL_SPACE:
  case LS_CAPS_LOCK:
    tap_code(KC_CAPS);
}
```

### defmacro ASTRAMATCH

- `ck`
- `typed_on_qwerty`
- `kc`

```c
case ck:
  if (record->event.pressed) {
    bool should_toggle_back = false;
    if (layer_state & _BV(CYRILLIC) && typed_on_qwerty) {
      toggle_language();
      should_toggle_back = true;
    }
    tap_code16(kc);
    if (should_toggle_back) toggle_language();
  }
return false;
```

## Record processing

### fn process_record_user
> bool

- `uint16_t keycode, keyrecord_t *record`

```c
KEYTIMER(MUN_BRA);
KEYTIMER(SUN_KET);
KEYTIMER(LCMD);
KEYTIMER(ALT_TAB);
KEYTIMER(CTL_SPC);
KEYTIMER(CMD_DEL);
KEYTIMER(ROPT);
KEYTIMER(PHOTO);
KEYTIMER(ASTRARUS);

switch (keycode) {
  KEYMATCH(PHOTO,   _BV(MOON),     false, PHOTOMOD, KC_NO);
  KEYMATCH(MUN_BRA, _BV(MOON),     false, 0,        LSFT(KC_9));
  KEYMATCH(SUN_KET, _BV(SUN),      false, 0,        LSFT(KC_0));
  KEYMATCH(LCMD,    _BV(CYRILLIC), true,  KC_LGUI,  KC_NO);
  KEYMATCH(ROPT,    _BV(CYRILLIC), true,  KC_RALT,  KC_NO);
  KEYMATCH(ALT_TAB, _BV(CYRILLIC), true,  KC_LALT,  KC_TAB);
  KEYMATCH(CTL_SPC, _BV(CYRILLIC), true,  KC_RCTL,  KC_SPC);
  KEYMATCH(CMD_DEL, _BV(CYRILLIC), true,  KC_RGUI,  KC_DEL);

  /* CYR_LAT toggles CYRILLIC layer on tap. */
case CYR_LAT:
  if (record->event.pressed) toggle_language();
  return false;

  /* This is like KC_LGUI and KC_LSFT, but in one key */
case PHOTOMOD:
  if (record->event.pressed) {
    register_code(KC_LGUI);
    register_code(KC_LSFT);
  }
  else {
    unregister_code(KC_LGUI);
    unregister_code(KC_LSFT);
  }
  return false;

  /* ЙЦУКЕН Astra key */
  KEYMATCH(ASTRARUS, _BV(ASTRA), false, 0, RU_COMM);

  /* Astra keys that depend on installed layouts */
  ASTRAMATCH(APIPE, true, KC_PIPE);
  ASTRAMATCH(ACIRC, true, KC_CIRC);
  ASTRAMATCH(AGRAVE, true, KC_GRAVE);
  ASTRAMATCH(AATDOG, true, KC_AT);
  ASTRAMATCH(AHASH, true, KC_HASH);
  ASTRAMATCH(ATILDE, true, KC_TILDE);
  ASTRAMATCH(ADOLLAR, true, KC_DOLLAR);
  ASTRAMATCH(AAMP, true, KC_AMPR);
  ASTRAMATCH(ASHCH, false, RU_SHCH);
  ASTRAMATCH(AJU, false, RU_JU);
  ASTRAMATCH(AJO, false, RU_JO);
  ASTRAMATCH(ASH, false, RU_SH);

  /* Astra keys that depend on Compose key */
case AGUILL:
  if (record->event.pressed) {
    tap_code16(KC_SLCK);
    tap_code16(KC_LT);
    tap_code16(KC_LT);
  }
  return false;
case AEMOT:
  if (record->event.pressed) {
    tap_code16(KC_SLCK);
    tap_code16(KC_GT);
    tap_code16(KC_GT);
  }
  return false;
case AMDASH:
  if (record->event.pressed) {
    tap_code16(KC_SLCK);
    tap_code16(KC_MINS);
    tap_code16(KC_MINS);
    tap_code16(KC_MINS);
  }
}
return true;
```

## P.S.

```c
#include "chords.h"
```

