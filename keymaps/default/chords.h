#ifndef KLAVAROG_CHORDGEN
#define KLAVAROG_CHORDGEN
enum combo_events {
  combo_event_5050079980185702001, //tap_code16(KC_GRAVE);
  combo_event_5207665435960106103, //tap_code16(RU_HARD);
  combo_event_1455421941083259718, //tap_code16(RU_SH);
  combo_event_7365048312733466185, //tap_code16(RU_JO);
  combo_event_5891232897378775703, //tap_code16(RU_JU);
  combo_event_5297457948660899245, //tap_code16(RU_SHCH);
  combo_event_8239629211358725322, //tap_code16(KC_EQUAL);
  combo_event_7179295321440393410, //tap_code16(KC_BSLS);
  combo_event_5408920146317996621, //spr(1)
  combo_event_4500416766030399648, //spr(MINS)
  combo_event_3434397636143616320, //spr(7)
  combo_event_4790249845375039026, //spr(BSLS)
  combo_event_4644558689557967029, //spr(6)
  combo_event_3906396305788648682, //spr(COMM)
  combo_event_2955491903904253957, //tap_code16(KC_LBRC);
  combo_event_2184387431738839613, //spr(LBRC)
  combo_event_5421515569967876581, //spr(RBRC)
  combo_event_5370594532543012395, //tap_code16(KC_RBRC);
  combo_event_3512098963113247392, //spr(DOT)
  combo_event_4164697042911778040, //tap_code16(KC_SLSH);
  combo_event_5002074414186060562, //tap_code16(KC_BSLS);
  combo_event_4506673164378454485, //spr(SLSH)
  combo_event_2916715052614424084, //spr(1)
  combo_event_2167655803933437529, //spr(MINS)
  combo_event_6635358231027988049, //spr(SCOLON)
  combo_event_5712766024658087503, //tap_code16(KC_EQUAL);
  
};
const uint16_t PROGMEM combo_array_5050079980185702001[] = {
  RU_J, RU_D, COMBO_END
};
const uint16_t PROGMEM combo_array_5207665435960106103[] = {
  RU_CH, RU_K, COMBO_END
};
const uint16_t PROGMEM combo_array_1455421941083259718[] = {
  RU_CH, RU_D, COMBO_END
};
const uint16_t PROGMEM combo_array_7365048312733466185[] = {
  RU_SOFT, RU_H, COMBO_END
};
const uint16_t PROGMEM combo_array_5891232897378775703[] = {
  RU_JA, RU_U, COMBO_END
};
const uint16_t PROGMEM combo_array_5297457948660899245[] = {
  RU_JA, RU_SOFT, COMBO_END
};
const uint16_t PROGMEM combo_array_8239629211358725322[] = {
  RU_JE, RU_A, COMBO_END
};
const uint16_t PROGMEM combo_array_7179295321440393410[] = {
  RU_A, RU_G, COMBO_END
};
const uint16_t PROGMEM combo_array_5408920146317996621[] = {
  RU_B, RU_Y, COMBO_END
};
const uint16_t PROGMEM combo_array_4500416766030399648[] = {
  RU_JE, RU_O, RU_I, COMBO_END
};
const uint16_t PROGMEM combo_array_3434397636143616320[] = {
  RU_Z, RU_M, COMBO_END
};
const uint16_t PROGMEM combo_array_4790249845375039026[] = {
  RU_J, RU_K, COMBO_END
};
const uint16_t PROGMEM combo_array_4644558689557967029[] = {
  RU_N, RU_K, COMBO_END
};
const uint16_t PROGMEM combo_array_3906396305788648682[] = {
  KC_P, KC_S, COMBO_END
};
const uint16_t PROGMEM combo_array_2955491903904253957[] = {
  KC_R, KC_T, COMBO_END
};
const uint16_t PROGMEM combo_array_2184387431738839613[] = {
  KC_D, KC_N, COMBO_END
};
const uint16_t PROGMEM combo_array_5421515569967876581[] = {
  KC_F, KC_E, COMBO_END
};
const uint16_t PROGMEM combo_array_5370594532543012395[] = {
  KC_W, KC_O, COMBO_END
};
const uint16_t PROGMEM combo_array_3512098963113247392[] = {
  KC_U, KC_I, COMBO_END
};
const uint16_t PROGMEM combo_array_4164697042911778040[] = {
  KC_Y, KC_C, COMBO_END
};
const uint16_t PROGMEM combo_array_5002074414186060562[] = {
  KC_A, KC_G, COMBO_END
};
const uint16_t PROGMEM combo_array_4506673164378454485[] = {
  KC_K, KC_M, COMBO_END
};
const uint16_t PROGMEM combo_array_2916715052614424084[] = {
  KC_B, KC_V, COMBO_END
};
const uint16_t PROGMEM combo_array_2167655803933437529[] = {
  KC_E, KC_O, KC_I, COMBO_END
};
const uint16_t PROGMEM combo_array_6635358231027988049[] = {
  KC_N, KC_C, COMBO_END
};
const uint16_t PROGMEM combo_array_5712766024658087503[] = {
  KC_E, KC_A, COMBO_END
};
combo_t key_combos[COMBO_COUNT] = {
  [combo_event_5050079980185702001] = COMBO_ACTION(combo_array_5050079980185702001),
  [combo_event_5207665435960106103] = COMBO_ACTION(combo_array_5207665435960106103),
  [combo_event_1455421941083259718] = COMBO_ACTION(combo_array_1455421941083259718),
  [combo_event_7365048312733466185] = COMBO_ACTION(combo_array_7365048312733466185),
  [combo_event_5891232897378775703] = COMBO_ACTION(combo_array_5891232897378775703),
  [combo_event_5297457948660899245] = COMBO_ACTION(combo_array_5297457948660899245),
  [combo_event_8239629211358725322] = COMBO_ACTION(combo_array_8239629211358725322),
  [combo_event_7179295321440393410] = COMBO_ACTION(combo_array_7179295321440393410),
  [combo_event_5408920146317996621] = COMBO_ACTION(combo_array_5408920146317996621),
  [combo_event_4500416766030399648] = COMBO_ACTION(combo_array_4500416766030399648),
  [combo_event_3434397636143616320] = COMBO_ACTION(combo_array_3434397636143616320),
  [combo_event_4790249845375039026] = COMBO_ACTION(combo_array_4790249845375039026),
  [combo_event_4644558689557967029] = COMBO_ACTION(combo_array_4644558689557967029),
  [combo_event_3906396305788648682] = COMBO_ACTION(combo_array_3906396305788648682),
  [combo_event_2955491903904253957] = COMBO_ACTION(combo_array_2955491903904253957),
  [combo_event_2184387431738839613] = COMBO_ACTION(combo_array_2184387431738839613),
  [combo_event_5421515569967876581] = COMBO_ACTION(combo_array_5421515569967876581),
  [combo_event_5370594532543012395] = COMBO_ACTION(combo_array_5370594532543012395),
  [combo_event_3512098963113247392] = COMBO_ACTION(combo_array_3512098963113247392),
  [combo_event_4164697042911778040] = COMBO_ACTION(combo_array_4164697042911778040),
  [combo_event_5002074414186060562] = COMBO_ACTION(combo_array_5002074414186060562),
  [combo_event_4506673164378454485] = COMBO_ACTION(combo_array_4506673164378454485),
  [combo_event_2916715052614424084] = COMBO_ACTION(combo_array_2916715052614424084),
  [combo_event_2167655803933437529] = COMBO_ACTION(combo_array_2167655803933437529),
  [combo_event_6635358231027988049] = COMBO_ACTION(combo_array_6635358231027988049),
  [combo_event_5712766024658087503] = COMBO_ACTION(combo_array_5712766024658087503),
  
};
void process_combo_event(uint8_t combo_index, bool pressed) {
  if (layer_state & (1 << CYRILLIC)) {
    switch (combo_index) {
      case combo_event_5050079980185702001: {
        if (pressed) {
  tap_code16(KC_GRAVE);

}
return;
}
    case combo_event_5207665435960106103: {
        if (pressed) {
  tap_code16(RU_HARD);

}
return;
}
    case combo_event_1455421941083259718: {
        if (pressed) {
  tap_code16(RU_SH);

}
return;
}
    case combo_event_7365048312733466185: {
        if (pressed) {
  tap_code16(RU_JO);

}
return;
}
    case combo_event_5891232897378775703: {
        if (pressed) {
  tap_code16(RU_JU);

}
return;
}
    case combo_event_5297457948660899245: {
        if (pressed) {
  tap_code16(RU_SHCH);

}
return;
}
    case combo_event_8239629211358725322: {
        if (pressed) {
  tap_code16(KC_EQUAL);

}
return;
}
    case combo_event_7179295321440393410: {
        if (pressed) {
  tap_code16(KC_BSLS);

}
return;
}
    case combo_event_5408920146317996621: {
        if (pressed) {
  spr(1)
}
return;
}
    case combo_event_4500416766030399648: {
        if (pressed) {
  spr(MINS)
}
return;
}
    case combo_event_3434397636143616320: {
        if (pressed) {
  spr(7)
}
return;
}
    case combo_event_4790249845375039026: {
        if (pressed) {
  spr(BSLS)
}
return;
}
    case combo_event_4644558689557967029: {
        if (pressed) {
  spr(6)
}
return;
}

}

}
 else if (1) {
    switch (combo_index) {
      case combo_event_3906396305788648682: {
        if (pressed) {
  spr(COMM)
}
return;
}
    case combo_event_2955491903904253957: {
        if (pressed) {
  tap_code16(KC_LBRC);

}
return;
}
    case combo_event_2184387431738839613: {
        if (pressed) {
  spr(LBRC)
}
return;
}
    case combo_event_5421515569967876581: {
        if (pressed) {
  spr(RBRC)
}
return;
}
    case combo_event_5370594532543012395: {
        if (pressed) {
  tap_code16(KC_RBRC);

}
return;
}
    case combo_event_3512098963113247392: {
        if (pressed) {
  spr(DOT)
}
return;
}
    case combo_event_4164697042911778040: {
        if (pressed) {
  tap_code16(KC_SLSH);

}
return;
}
    case combo_event_5002074414186060562: {
        if (pressed) {
  tap_code16(KC_BSLS);

}
return;
}
    case combo_event_4506673164378454485: {
        if (pressed) {
  spr(SLSH)
}
return;
}
    case combo_event_2916715052614424084: {
        if (pressed) {
  spr(1)
}
return;
}
    case combo_event_2167655803933437529: {
        if (pressed) {
  spr(MINS)
}
return;
}
    case combo_event_6635358231027988049: {
        if (pressed) {
  spr(SCOLON)
}
return;
}
    case combo_event_5712766024658087503: {
        if (pressed) {
  tap_code16(KC_EQUAL);

}
return;
}

}

}

}
#endif
