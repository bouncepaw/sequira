#pragma once

#include "quantum.h"


/*
 * Synonyms for cyrillic letters. They are named by scheme K_C_smth where smth
 * is translitted letter.
 */
#define K_C_A KC_F
#define K_C_B KC_COMM
#define K_C_V KC_D
#define K_C_G KC_U
#define K_C_D KC_L
#define K_C_JE KC_T
#define K_C_JO KC_GRV
#define K_C_ZH KC_SCLN
#define K_C_Z KC_P
#define K_C_I KC_B
#define K_C_J KC_Q
#define K_C_K KC_R
#define K_C_L KC_K
#define K_C_M KC_V
#define K_C_N KC_Y
#define K_C_O KC_J
#define K_C_P KC_G
#define K_C_R KC_H
#define K_C_S KC_C
#define K_C_T KC_N
#define K_C_U KC_E
#define K_C_F KC_A
#define K_C_H KC_LBRC
#define K_C_TS KC_W
#define K_C_CH KC_X
#define K_C_SH KC_I
#define K_C_SHCH KC_O
#define K_C_HARD KC_RBRC
#define K_C_Y KC_S
#define K_C_SOFT KC_M
#define K_C_E KC_QUOT
#define K_C_JU KC_DOT
#define K_C_JA KC_Z
#define K_C_NUM KC_3
#define K_C_DQUO LSFT(KC_2)
#define K_C_DOT  KC_SLSH
#define K_C_COMM LSFT(KC_SLSH)
#define K_C_SCLN LSFT(KC_4)

/*
 * Layer names.
 */
#define LATIN              0
#define LATIN_FULL_MOON    1
#define CYRILLIC           2
#define CYRILLIC_FULL_MOON 3
#define NEW_MOON           4
#define SUN                5

/*
 * All custom keys. They are named by scheme MLY_SYM where MLY is a modifer or a
 * layer this key triggers when held, and SYM is a keycode that is sent when the
 * key is simply tapped.
 */
enum custom_key
  {
   FUL_C_x = SAFE_RANGE, // Ctrl+x
   CMD_C_q, // Ctrl+q
   ALT_TAB,
   SFT_BSP,
   CTL_SPC,
   CMD_ESC,
   ALT_DEL,
   NEW_M_x, // Alt+x
   NEW_LNG, // f19
   FUL_RET,
   SUN_BRA, // (
   SUN_KET, // )
  };
#define HYT_CTL KC_LCTL
#define HYT_SFT KC_RSFT
#define COMPOSE KC_F20

/*
 * These macros simplify specifying halves of layout. There is no need for macro
 * that defines the whole keyboard.
 */
#define HALF(k10, k11, k12, k13, k14, k15, \
             k20, k21, k22, k23, k24, k25, \
             k30, k31, k32, k33, k34, k35, \
             k40, k41, k42, k43, k44, k45) \
    { k10, k11, k12, k13, k14, k15 },      \
    { k20, k21, k22, k23, k24, k25 },      \
    { k30, k31, k32, k33, k34, k35 },      \
    { k40, k41, k42, k43, k44, k45 },

#define HALFL(k10, k11, k12, k13, k14, k15,                     \
              k20, k21, k22, k23, k24, k25,                     \
              k30, k31, k32, k33, k34, k35)                     \
HALF(k10, k11, k12, k13, k14, k15,                              \
     k20, k21, k22, k23, k24, k25,                              \
     k30, k31, k32, k33, k34, k35,                              \
     FUL_C_x, HYT_CTL, COMPOSE, CMD_C_q, ALT_TAB, SFT_BSP)

#define HALFR(k10, k11, k12, k13, k14, k15,             \
              k20, k21, k22, k23, k24, k25,             \
              k30, k31, k32, k33, k34, k35, k43)        \
HALF(k10, k11, k12, k13, k14, k15,                      \
     k20, k21, k22, k23, k24, k25,                      \
     k30, k31, k32, k33, k34, k35,                      \
     CTL_SPC, CMD_ESC, ALT_DEL, k43, HYT_SFT, NEW_M_x)
