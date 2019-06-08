#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
  {
   [LATIN] =
   {
    HALFL(KC_SLSH, KC_D,    KC_U,    KC_R,    KC_F,    KC_DQUO,
          NEW_LNG, KC_H,    KC_S,    KC_T,    KC_E,    KC_COMM,
          SUN_BRA, KC_Z,    KC_K,    KC_M,    KC_C,    KC_MINS),

    HALFR(KC_QUOT, KC_W,    KC_L,    KC_J,    KC_P,    KC_BSLS,
          KC_DOT,  KC_A,    KC_O,    KC_I,    KC_N,    FUL_RET,
          K_C_SCLN,KC_Y,    KC_B,    KC_V,    KC_G,    SUN_KET,
          KC_PSCR),
   },

   [CYRILLIC] =
   {
    HALFL(KC_SLSH, K_C_D,   K_C_U,   K_C_R,   K_C_SOFT,K_C_DQUO,
          NEW_LNG, K_C_V,   K_C_S,   K_C_T,   K_C_JE,  K_C_COMM,
          SUN_BRA, K_C_Z,   K_C_CH,  K_C_M,   K_C_K,   KC_MINS),

    HALFR(K_C_NUM, K_C_JA,  K_C_L,   K_C_J,   K_C_P,   KC_BSLS,
          K_C_DOT, K_C_A,   K_C_O,   K_C_I,   K_C_N,   FUL_RET,
          KC_SCLN, K_C_Y,   K_C_B,   K_C_H,   K_C_G,   SUN_KET,
          KC_PSCR),
   },

   [NEW_MOON] =
   {
    HALFL(KC_F13,  KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_F15,
          KC_TRNS, KC_F10,  KC_F4,   KC_F5,   KC_F6,   KC_F16,
          KC_F14,  KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F17),

    HALFR(KC_TRNS, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_INS,
          LCTL(KC_C),  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_TRNS,
          LCTL(KC_S),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
          LSFT(KC_PSCR)),
   },

   [LATIN_FULL_MOON] =
   {
    HALFL(KC_TRNS, KC_CIRC, KC_7,    KC_8,    KC_9,    KC_GRV,
          KC_TRNS, KC_0,    KC_4,    KC_5,    KC_6,    KC_UNDS,
          KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_ASTR),

    HALFR(KC_PIPE, KC_LT,   KC_GT,   KC_DLR,  KC_PERC, KC_TRNS,
          KC_EQL,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_TRNS,
          KC_PLUS, KC_EXLM, KC_QUES, KC_AT,   KC_HASH, KC_TILD,
          LCTL(KC_PSCR))
   },

   [CYRILLIC_FULL_MOON] =
   {
    HALFL(KC_TRNS, KC_CIRC, KC_7,    KC_8,    KC_9,    KC_GRV,
          KC_TRNS, KC_0,    KC_4,    KC_5,    KC_6,    KC_UNDS,
          KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_ASTR),

    HALFR(KC_PIPE, KC_LT,   KC_GT,   KC_DLR,  KC_PERC, KC_TRNS,
          KC_EQL,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_TRNS,
          KC_PLUS, KC_EXLM, KC_AMPR, KC_AT,   KC_HASH, KC_TILD,
          LCTL(KC_PSCR))
   },
  };


layer_state_t get_full_moon(void) {
  return (layer_state & (1 << CYRILLIC))
    ? CYRILLIC_FULL_MOON
    : LATIN_FULL_MOON;
}

enum mod_router_directive
  {
   dREG,   // register
   dUNREG, // unregister
  };
void mod_router(enum mod_router_directive directive, uint8_t modmask) {
  static bool any_mods_active = false;
  static bool was_cyrillic_active = false;
  static bool was_cyrillic_full_moon_active = false;

  if (directive == dREG) {
    // If it the first mod pressed.
    if (!any_mods_active) {
      any_mods_active = true;
      was_cyrillic_active = layer_state & (1 << CYRILLIC);
      was_cyrillic_full_moon_active = layer_state & (1 << CYRILLIC_FULL_MOON);
      layer_off(CYRILLIC);
      layer_off(CYRILLIC_FULL_MOON);
    }
    // Anyway, the pressed mod shall be registered.
    register_mods(modmask);
  }
  else {
    // Depress the mod.
    unregister_mods(modmask);
    // If it was the last mod, rewind to previous state.
    if (!(get_mods() &~ (MOD_LSFT | MOD_RSFT))) {
      any_mods_active = false;
      if (was_cyrillic_active) layer_on(CYRILLIC);
      if (was_cyrillic_full_moon_active) layer_on(CYRILLIC_FULL_MOON);
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
    mod_router(dREG, modmask_for_hold);
  }
  else {
    mod_router(dUNREG, modmask_for_hold);
    if (timer_elapsed(*timer) < MODTAP_TERM) {
      register_mods(modmask_for_kc);
      tap_code(kc);
      unregister_mods(modmask_for_kc);
    }
  }
}
#define MOD__ 0
#define KEYMOD(name, modhold, modpress, kc)                     \
  case name:                                                    \
  process_custom_mod(name, &timer_##name, record,              \
                     MOD_##modhold, MOD_##modpress, KC_##kc);   \
  return false

void process_custom_layer(enum custom_key ck,
                          uint16_t *timer,
                          keyrecord_t *record,
                          layer_state_t layer,
                          uint8_t modmask_for_kc,
                          uint16_t kc) {
  if (record->event.pressed) {
    *timer = timer_read();
    layer_on(layer);
  }
  else {
    layer_off(layer);
    if (timer_elapsed(*timer) < MODTAP_TERM) {
      register_mods(modmask_for_kc);
      tap_code(kc);
      unregister_mods(modmask_for_kc);
    }
  }
}

#define KEYLAYER(name, layer, modpress, kc, act)    \
  case name:                                        \
  process_custom_layer(name, &timer_##name, record,           \
                       layer, MOD_##modpress, KC_##kc);        \
  act;                                              \
  return false

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  KEYTIMER(FUL_C_x);
  KEYTIMER(CMD_C_q);
  KEYTIMER(ALT_TAB);
  //KEYTIMER(SFT_BSP);
  KEYTIMER(CTL_SPC);
  KEYTIMER(CMD_ESC);
  KEYTIMER(ALT_DEL);
  KEYTIMER(NEW_M_x);
  KEYTIMER(FUL_RET);
  KEYTIMER(NEW_LNG);

  switch (keycode) {

    /*
     * Simple double keys. They trigger the LATIN layer and a mod when
     * held, and send smth when tapped.
     *     key      mod   smth
     */
    KEYMOD(CMD_C_q, LGUI, LCTL, Q);
    KEYMOD(ALT_TAB, LALT, _   , TAB);
    KEYMOD(CTL_SPC, RCTL, _   , SPC);
    KEYMOD(CMD_ESC, RGUI, _   , ESC);
    KEYMOD(ALT_DEL, RALT, _   , DEL);

    /*
     * New Moon double keys. They trigger NEW_MOON layer when held,
     * and send smth when tapped.
     */
    KEYLAYER(NEW_M_x, NEW_MOON, LALT, X,);
    KEYLAYER(NEW_LNG, NEW_MOON, _   , F19, layer_state ^= (1 << CYRILLIC));

    /*
     * Full Moon double keys. They trigger a corresponding _FULL_MOON
     * layer when held, and send smth when tapped.
     */
    KEYLAYER(FUL_C_x, get_full_moon(), LCTL, X,);
    KEYLAYER(FUL_RET, get_full_moon(), _   , ENT,);
  default:
    return true;
  }
}
