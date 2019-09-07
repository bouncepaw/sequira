#ifndef KLAVAROG_CHORDGEN
#define KLAVAROG_CHORDGEN
enum combo_events {
  combo_event_4886280981934280526, //tap_code16(KC_GRAVE);
  combo_event_4678148551841563910, //tap_code16(RU_HARD);
  combo_event_3980629046206009165, //tap_code16(KC_EQUAL);
  combo_event_3082675992752732392, //tap_code16(KC_BSLS);
  combo_event_3640760070255642587, //spr(1)
  combo_event_2393192347682739205, //spr(MINS)
  combo_event_4368505125123824490, //spr(7)
  combo_event_4209041346760971816, //spr(BSLS)
  combo_event_877552580124480159, //spr(6)
  combo_event_5446578598700948626, //spr(COMM)
  combo_event_3042870991305794438, //tap_code16(KC_LBRC);
  combo_event_2678724151867973931, //spr(LBRC)
  combo_event_2694702165251804787, //spr(RBRC)
  combo_event_4109595699390820231, //tap_code16(KC_RBRC);
  combo_event_5963413521366522991, //spr(DOT)
  combo_event_6216787418876074044, //tap_code16(KC_SLSH);
  combo_event_5747235127987564271, //tap_code16(KC_BSLS);
  combo_event_5596806440521891538, //spr(SLSH)
  combo_event_1532522939552220729, //spr(1)
  combo_event_3513143579933578960, //spr(MINS)
  combo_event_3194860722017782585, //spr(SCOLON)
  combo_event_4573286839567012705, //tap_code16(KC_EQUAL);
  
};
const uint16_t PROGMEM combo_array_4886280981934280526[] = {
  RU_J, RU_D, COMBO_END
};
const uint16_t PROGMEM combo_array_4678148551841563910[] = {
  RU_CH, RU_K, COMBO_END
};
const uint16_t PROGMEM combo_array_3980629046206009165[] = {
  RU_JE, RU_A, COMBO_END
};
const uint16_t PROGMEM combo_array_3082675992752732392[] = {
  RU_A, RU_G, COMBO_END
};
const uint16_t PROGMEM combo_array_3640760070255642587[] = {
  RU_B, RU_Y, COMBO_END
};
const uint16_t PROGMEM combo_array_2393192347682739205[] = {
  RU_JE, RU_O, RU_I, COMBO_END
};
const uint16_t PROGMEM combo_array_4368505125123824490[] = {
  RU_Z, RU_M, COMBO_END
};
const uint16_t PROGMEM combo_array_4209041346760971816[] = {
  RU_J, RU_K, COMBO_END
};
const uint16_t PROGMEM combo_array_877552580124480159[] = {
  RU_N, RU_K, COMBO_END
};
const uint16_t PROGMEM combo_array_5446578598700948626[] = {
  KC_P, KC_S, COMBO_END
};
const uint16_t PROGMEM combo_array_3042870991305794438[] = {
  KC_R, KC_T, COMBO_END
};
const uint16_t PROGMEM combo_array_2678724151867973931[] = {
  KC_D, KC_N, COMBO_END
};
const uint16_t PROGMEM combo_array_2694702165251804787[] = {
  KC_F, KC_E, COMBO_END
};
const uint16_t PROGMEM combo_array_4109595699390820231[] = {
  KC_W, KC_O, COMBO_END
};
const uint16_t PROGMEM combo_array_5963413521366522991[] = {
  KC_U, KC_I, COMBO_END
};
const uint16_t PROGMEM combo_array_6216787418876074044[] = {
  KC_Y, KC_C, COMBO_END
};
const uint16_t PROGMEM combo_array_5747235127987564271[] = {
  KC_A, KC_G, COMBO_END
};
const uint16_t PROGMEM combo_array_5596806440521891538[] = {
  KC_K, KC_M, COMBO_END
};
const uint16_t PROGMEM combo_array_1532522939552220729[] = {
  KC_B, KC_V, COMBO_END
};
const uint16_t PROGMEM combo_array_3513143579933578960[] = {
  KC_E, KC_O, KC_I, COMBO_END
};
const uint16_t PROGMEM combo_array_3194860722017782585[] = {
  KC_N, KC_C, COMBO_END
};
const uint16_t PROGMEM combo_array_4573286839567012705[] = {
  KC_E, KC_A, COMBO_END
};
combo_t key_combos[COMBO_COUNT] = {
  [combo_event_4886280981934280526] = COMBO_ACTION(combo_array_4886280981934280526),
  [combo_event_4678148551841563910] = COMBO_ACTION(combo_array_4678148551841563910),
  [combo_event_3980629046206009165] = COMBO_ACTION(combo_array_3980629046206009165),
  [combo_event_3082675992752732392] = COMBO_ACTION(combo_array_3082675992752732392),
  [combo_event_3640760070255642587] = COMBO_ACTION(combo_array_3640760070255642587),
  [combo_event_2393192347682739205] = COMBO_ACTION(combo_array_2393192347682739205),
  [combo_event_4368505125123824490] = COMBO_ACTION(combo_array_4368505125123824490),
  [combo_event_4209041346760971816] = COMBO_ACTION(combo_array_4209041346760971816),
  [combo_event_877552580124480159] = COMBO_ACTION(combo_array_877552580124480159),
  [combo_event_5446578598700948626] = COMBO_ACTION(combo_array_5446578598700948626),
  [combo_event_3042870991305794438] = COMBO_ACTION(combo_array_3042870991305794438),
  [combo_event_2678724151867973931] = COMBO_ACTION(combo_array_2678724151867973931),
  [combo_event_2694702165251804787] = COMBO_ACTION(combo_array_2694702165251804787),
  [combo_event_4109595699390820231] = COMBO_ACTION(combo_array_4109595699390820231),
  [combo_event_5963413521366522991] = COMBO_ACTION(combo_array_5963413521366522991),
  [combo_event_6216787418876074044] = COMBO_ACTION(combo_array_6216787418876074044),
  [combo_event_5747235127987564271] = COMBO_ACTION(combo_array_5747235127987564271),
  [combo_event_5596806440521891538] = COMBO_ACTION(combo_array_5596806440521891538),
  [combo_event_1532522939552220729] = COMBO_ACTION(combo_array_1532522939552220729),
  [combo_event_3513143579933578960] = COMBO_ACTION(combo_array_3513143579933578960),
  [combo_event_3194860722017782585] = COMBO_ACTION(combo_array_3194860722017782585),
  [combo_event_4573286839567012705] = COMBO_ACTION(combo_array_4573286839567012705),
  
};
void process_combo_event(uint8_t combo_index, bool pressed) {
  if (layer_state & (1 << CYRILLIC)) {
    switch (combo_index) {
      case combo_event_4886280981934280526: {
        if (pressed) {
  tap_code16(KC_GRAVE);

}
return;
}
    case combo_event_4678148551841563910: {
        if (pressed) {
  tap_code16(RU_HARD);

}
return;
}
    case combo_event_3980629046206009165: {
        if (pressed) {
  tap_code16(KC_EQUAL);

}
return;
}
    case combo_event_3082675992752732392: {
        if (pressed) {
  tap_code16(KC_BSLS);

}
return;
}
    case combo_event_3640760070255642587: {
        if (pressed) {
  spr(1)
}
return;
}
    case combo_event_2393192347682739205: {
        if (pressed) {
  spr(MINS)
}
return;
}
    case combo_event_4368505125123824490: {
        if (pressed) {
  spr(7)
}
return;
}
    case combo_event_4209041346760971816: {
        if (pressed) {
  spr(BSLS)
}
return;
}
    case combo_event_877552580124480159: {
        if (pressed) {
  spr(6)
}
return;
}

}

}
 else if (1) {
    switch (combo_index) {
      case combo_event_5446578598700948626: {
        if (pressed) {
  spr(COMM)
}
return;
}
    case combo_event_3042870991305794438: {
        if (pressed) {
  tap_code16(KC_LBRC);

}
return;
}
    case combo_event_2678724151867973931: {
        if (pressed) {
  spr(LBRC)
}
return;
}
    case combo_event_2694702165251804787: {
        if (pressed) {
  spr(RBRC)
}
return;
}
    case combo_event_4109595699390820231: {
        if (pressed) {
  tap_code16(KC_RBRC);

}
return;
}
    case combo_event_5963413521366522991: {
        if (pressed) {
  spr(DOT)
}
return;
}
    case combo_event_6216787418876074044: {
        if (pressed) {
  tap_code16(KC_SLSH);

}
return;
}
    case combo_event_5747235127987564271: {
        if (pressed) {
  tap_code16(KC_BSLS);

}
return;
}
    case combo_event_5596806440521891538: {
        if (pressed) {
  spr(SLSH)
}
return;
}
    case combo_event_1532522939552220729: {
        if (pressed) {
  spr(1)
}
return;
}
    case combo_event_3513143579933578960: {
        if (pressed) {
  spr(MINS)
}
return;
}
    case combo_event_3194860722017782585: {
        if (pressed) {
  spr(SCOLON)
}
return;
}
    case combo_event_4573286839567012705: {
        if (pressed) {
  tap_code16(KC_EQUAL);

}
return;
}

}

}

}
#endif
