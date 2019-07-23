#pragma once

#include "quantum.h"
#include "rusmap.h"

/*
 * Layers.
 * - LATIN: the main layer. It is turned of when mods are pressed.
 * - CYRILLIC: the other layer.
 * - MOON and SUN: where the rest of keys are located.
 */
#define LATIN      0
#define CYRILLIC   1
#define MOON       2
#define SUN        3

/*
 * All custom keys that require custom processing.
 */
enum custom_key
  {
   CYR_LAT = SAFE_RANGE,
   MUN_BRA,
   SUN_KET,
   LCMD,
   ALT_TAB,
   CTL_SPC,
   CMD_DEL,
   ROPT,
   PHOTO,
  };

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

#define HALFL(k11, k12, k13, k14,                                     \
              k21, k22, k23, k24, k25,                                \
              k31, k32, k33, k34, k35)                                \
HALF(KC_F13,  k11,     k12,     k13,  k14,     KC_F14,            \
     CYR_LAT, k21,     k22,     k23,  k24,     k25,                   \
     MUN_BRA, k31,     k32,     k33,  k34,     k35,                   \
     LT(SUN, KC_ESC), KC_LCTL, KC_SLCK, LCMD, ALT_TAB, MT(MOD_LSFT, KC_BSPC))

#define HALFR(k11, k12, k13, k14,                                    \
              k21, k22, k23, k24, k20,                               \
              k31, k32, k33, k34, k30)                                      \
HALF(KC_F15,     k11,     k12,  k13,   k14,     KC_APP,         \
     k20,        k21,     k22,  k23,   k24,     KC_ENT,                 \
     k30,        k31,     k32,  k33,   k34,     SUN_KET,          \
     CTL_SPC,    CMD_DEL, ROPT, PHOTO, KC_RSFT, MO(MOON))
