#pragma once

#include "quantum.h"
#define LATIN 0
#define CYRILLIC 1
#define MOON 2
#define SUN 3
enum custom_key {
    CYR_LAT = SAFE_RANGE,
    MUN_BRA,
    SUN_KET,
    LCMD,
    ALT_TAB,
    CTL_SPC,
    CMD_DEL,
    ROPT,
    PHOTO
} ;
#include "rusmap.h"
#define HALF(k10, k11, k12, k13, k14, k15, k20, k21, k22, k23, k24, k25, k30, k31, k32, k33, k34, k35, k40, k41, k42, k43, k44, k45)\
{ k10, k11, k12, k13, k14, k15 },\
{ k20, k21, k22, k23, k24, k25 },\
{ k30, k31, k32, k33, k34, k35 },\
{ k40, k41, k42, k43, k44, k45 }
#define HALFL(k10, k11, k12, k13, k14, k15, k21, k22, k23, k24, k25, k31, k32, k33, k34, k35)\
HALF(k10,     k11,     k12,     k13,  k14,     k15,\
     CYR_LAT, k21,     k22,     k23,  k24,     k25,\
     MUN_BRA, k31,     k32,     k33,  k34,     k35,\
     LT(SUN, KC_ESC), KC_LCTL, KC_SLCK, LCMD, ALT_TAB, MT(MOD_LSFT, KC_BSPC))
#define HALFR(k10, k11, k12, k13, k14, k15, k21, k22, k23, k24, k20, k31, k32, k33, k34, k30)\
HALF(k10,        k11,     k12,  k13,   k14,     k15,\
     k20,        k21,     k22,  k23,   k24,     KC_ENT,\
     k30,        k31,     k32,  k33,   k34,     SUN_KET,\
     CTL_SPC,    CMD_DEL, ROPT, PHOTO, KC_RSFT, MO(MOON))
