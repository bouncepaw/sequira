#pragma once

#include "quantum.h"


/*
 * Synonyms for cyrillic letters. They are named by scheme RU_smth where smth
 * is translitted letter.
 */
#define RU_A KC_F
#define RU_B KC_COMM
#define RU_V KC_D
#define RU_G KC_U
#define RU_D KC_L
#define RU_JE KC_T
#define RU_JO KC_NUBS
#define RU_ZH KC_SCLN
#define RU_Z KC_P
#define RU_I KC_B
#define RU_J KC_Q
#define RU_K KC_R
#define RU_L KC_K
#define RU_M KC_V
#define RU_N KC_Y
#define RU_O KC_J
#define RU_P KC_G
#define RU_R KC_H
#define RU_S KC_C
#define RU_T KC_N
#define RU_U KC_E
#define RU_F KC_A
#define RU_H KC_LBRC
#define RU_TS KC_W
#define RU_CH KC_X
#define RU_SH KC_I
#define RU_SHCH KC_O
#define RU_HARD KC_RBRC
#define RU_Y KC_S
#define RU_SOFT KC_M
#define RU_E KC_QUOT
#define RU_JU KC_DOT
#define RU_JA KC_Z
#define RU_NUM KC_3
#define RU_DQUO LSFT(KC_2)
#define RU_DOT  KC_SLSH
#define RU_COMM LSFT(KC_SLSH)
#define RU_SCLN LSFT(KC_4)

/*
 * Layers.
 * - LATIN: the main layer.
 * - CYRILLIC: the other layer. It is turned of when mods are pressed.
 * - FULL_MOON: the layer where classic function keys such as UP, DOWN, PGUP
 * are located.
 * - NEW_MOON: the layer where more modern function keys such as REWIND, MOUSE
 * UP, PREV DT are located.
 */
#define LATIN              0
#define CYRILLIC           1
#define FULL_MOON          2
#define NEW_MOON           3

/*
 * All custom keys. They are named by scheme MLY_SYM where MLY is a modifer or a
 * layer this key triggers when held, and SYM is a keycode that is sent when the
 * key is simply tapped.
 *
 * [1] Which mod or layer is triggered on hold. If it is a mod, it is meant to
 * trigger LATIN layer.
 * [2] Which key is sent on tap.
 * [3] Notes.
 * [4] Does key have to be implemented in code.
 *
 * |key    |[1]      |[2]    |[3]           |[4]|
 * |-------|---------|-------|--------------|---|
 * |NEW_BRA|NEW_MOON |(      |Bra-          |√  |
 * |FUL_KET|FULL_MOON|)      |   cket       |√  |
 * |CYR_LAT|         |KC_F19 |Inverts layout|√  |
 * |LCMD   |LGUI     |       |              |√  |
 * |ALT_TAB|LALT     |KC_TAB |              |√  |
 * |SFT_BSP|LSFT     |KC_BSPC|No LATIN      |   |
 * |CTL_SPC|RCTL     |KC_SPC |              |√  |
 * |CMD_DEL|RGUI     |KC_DEL |              |√  |
 * |ROPT   |RALT     |       |              |√  |
 * |PHOTO  |LGUI,LSFT|       |Also, NEW_MOON|√  |
 * |FUL_MUN|FULL_MOON|       |              |   |
 * |NEW_MUN|NEW_MOON |       |              |   |
 * |HYT_CTL|LCTL     |       |              |   |
 * |HYT_SFT|RSFT     |       |              |   |
 * |COMPOSE|         |KC_F20 |              |   |
 */
enum custom_key
  {
   NEW_BRA = SAFE_RANGE, FUL_KET,
   CYR_LAT,
   LCMD, ALT_TAB, SFT_BSP,
   CTL_SPC, CMD_DEL, ROPT, PHOTO,
  };
#define FUL_MUN MO(FULL_MOON)
#define NEW_MUN MO(NEW_MOON)
#define HYT_CTL KC_LCTL
#define HYT_SFT KC_RSFT
#define COMPOSE KC_F20
#define SFT_BSP MT(MOD_LSFT, KC_BSPC)

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
    { k40, k41, k42, k43, k44, k45 }

#define HALFL(k11, k12, k13, k14                                      \
              k21, k22, k23, k24,                                     \
              k31, k32, k33, k34, k25)                                \
HALF(KC_ESC,  k11,     k12,     k13,  k14,     LCTL(KC_Q),            \
     CYR_LAT, k21,     k22,     k23,  k24,     k25,                   \
     NEW_BRA, k31,     k32,     k33,  k34,     KC_MINS,               \
     FUL_MUN, HYT_CTL, COMPOSE, LCMD, ALT_TAB, SFT_BSP)

#define HALFR(k11, k12, k13, k14,                                    \
              k21, k22, k23, k24,                                    \
              k31, k32, k33, k34, k20, k30)                          \
HALF(LALT(KC_X), k11,     k12,  k13,   k14,     LCTL(KC_X),          \
     k20,        k21,     k22,  k23,   k24,     k25,                 \
     k30,        k31,     k32,  k33,   k34,     k35,                 \
     CTL_SPC,    CMD_DEL, ROPT, PHOTO, HYT_SFT, NEW_MUN)
