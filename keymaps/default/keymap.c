#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
  {
   [LATIN] =
   {
    HALFL(KC_Y, KC_U, KC_R, KC_F,
          KC_H, KC_S, KC_T, KC_A,
          KC_Z, KC_K, KC_M, KC_C,
          KC_COMM),
    HALFR(KC_W, KC_L, KC_P, KC_J,
          KC_E, KC_O, KC_I, KC_N,
          KC_D, KC_B, KC_V, KC_G,
          KC_DOT, KC_SCLN)
   },
   [CYRILLIC] =
   {
    HALFL(RU_Y, RU_U,  RU_R, RU_SOFT,
          RU_V, RU_S,  RU_T, RU_A,
          RU_Z, RU_CH, RU_M, RU_K,
          RU_COMM),
    HALFR(RU_JA, RU_L, RU_P, RU_J,
          RU_JE, RU_J, RU_I, RU_N,
          RU_D,  RU_B, RU_H, RU_G,
          RU_DOT, RU_SCLN),
   },
   [MOON] =
   {
    HALFL(KC_F14,  KC_7, KC_8, KC_9,
          KC_0,    KC_4, KC_5, KC_6,
          KC_F15,  KC_1, KC_2, KC_3,
          KC_F17),
    HALFR(KC_HOME, KC_UP,   KC_END,  KC_PGUP,
          KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
          KC_MRWD, KC_MPLY, KC_MFFD, KC_INS,
          KC_F20,  KC_F22)
   },
   [SUN] =
   {
    HALFL(KC_F1,   KC_F2,   KC_F3,   KC_F4,
          KC_F5,   KC_F6,   KC_F7,   KC_F8,
          KC_F9,   KC_F10,  KC_F11,  KC_F12,
          KC_F18),
    HALFR(KC_BTN1,  KC_MS_U,KC_BTN2, KC_WH_U,
          KC_MS_L,  KC_MS_D,KC_MS_R, KC_WH_D,
          KC_VOLD,  KC_MUTE,KC_VOLU, KC_F16,
          KC_F21,   KC_F23)
   },
  };


void mod_router(bool registering, uint8_t modmask) {
  static bool any_mods_active = false;
  static bool was_cyrillic_active = false;

  if (registering) {
    // If it the first mod pressed.
    if (!any_mods_active) {
      any_mods_active = true;
      was_cyrillic_active = layer_state & (1 << CYRILLIC);
      layer_off(CYRILLIC);
    }
    // Anyway, the pressed mod shall be registered.
    register_code(modmask);
  }
  else {
    // Depress the mod.
    unregister_code(modmask);
    // If it was the last mod, rewind to previous state.
    if (!(get_mods() &~ (MOD_LSFT | MOD_RSFT))) {
      any_mods_active = false;
      if (was_cyrillic_active) layer_on(CYRILLIC);
    }
  }
}
#define KEYTIMER(name) static uint16_t timer_##name

void process_custom_mod(enum custom_key ck,
                        uint16_t *timer,
                        keyrecord_t *record,
                        uint8_t modmask_for_hold,
                        uint8_t modmask_for_kc,
                        uint8_t kc) {
  if (record->event.pressed) {
    *timer = timer_read();
    mod_router(true, modmask_for_hold);
  }
  else {
    mod_router(false, modmask_for_hold);
    if (timer_elapsed(*timer) < MODTAP_TERM) {
      register_code(modmask_for_kc);
      tap_code(kc);
      unregister_code(modmask_for_kc);
    }
  }
}
#define MOD__ 0
#define KC__ 0
#define KEYMOD(name, modhold, modpress, kc)                     \
  case name:                                                    \
  process_custom_mod(name, &timer_##name, record,              \
                     KC_##modhold, KC_##modpress, KC_##kc);   \
  return false

void process_custom_layer(enum custom_key ck,
                          uint16_t *timer,
                          keyrecord_t *record,
                          layer_state_t layer,
                          uint8_t modmask_for_kc,
                          uint16_t kc,
                          bool should_invert) {
  if (record->event.pressed) {
    *timer = timer_read();
    layer_on(layer);
  }
  else {
    layer_off(layer);
    if (timer_elapsed(*timer) < MODTAP_TERM) {
      register_code(modmask_for_kc);
      tap_code(kc);
      unregister_code(modmask_for_kc);
      if (should_invert)
        layer_invert(CYRILLIC);
    }
  }
}

#define KEYLAYER(name, layer, modpress, kc, si)         \
  case name: {                                               \
  process_custom_layer(name, &timer_##name, record,           \
                       layer, KC_##modpress, KC_##kc, si);       \
  }\
  return false

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /*KEYTIMER(FUL_C_x);
  KEYTIMER(CMD_C_q);
  KEYTIMER(ALT_TAB);
  KEYTIMER(CTL_SPC);
  KEYTIMER(CMD_ESC);
  KEYTIMER(ALT_DEL);
  KEYTIMER(NEW_M_x);
  KEYTIMER(FUL_RET);
  KEYTIMER(NEW_LNG);
  */
  switch (keycode) {

    /*
     * Simple double keys. They trigger the LATIN layer and a mod when
     * held, and send smth when tapped.
     *     key      mod   smth
     */
    //KEYMOD(CMD_C_q, LGUI, LCTL, Q);
    //KEYMOD(ALT_TAB, LALT, _   , TAB);
    //KEYMOD(CTL_SPC, RCTL, _   , SPC);
    //KEYMOD(CMD_ESC, RGUI, _   , ESC);
    //KEYMOD(ALT_DEL, RALT, _   , DEL);

    /*
     * New Moon double keys. They trigger NEW_MOON layer when held,
     * and send smth when tapped.
     */
    //KEYLAYER(NEW_M_x, NEW_MOON, LALT, X,   false);
    //KEYLAYER(NEW_LNG, NEW_MOON, _   , F19, true);

    /*
     * Full Moon double keys. They trigger a corresponding _FULL_MOON
     * layer when held, and send smth when tapped.
     */
    //KEYLAYER(FUL_C_x, get_full_moon(), LCTL, X,   false);
    //KEYLAYER(FUL_RET, get_full_moon(), _   , ENT, false);
  default:
    return true;
  }
  return true;
}
