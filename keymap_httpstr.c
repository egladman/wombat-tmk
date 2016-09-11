#include <avr/wdt.h>
#include "keymap_common.h"

// the following snippet modified from
// https://github.com/ahtn/tmk_keyboard/blob/773d609bd87d15bb48b3176209c2e2db0b2db178/keyboard/split_keyboard/actionmap_plain.c

enum function_id {
    PROMICRO_PROGRAM,
};

void promicro_bootloader_jmp(bool program) {
  uint16_t *const bootKeyPtr = (uint16_t *)0x0800;

  // Value used by Caterina bootloader use to determine whether to run the
  // sketch or the bootloader programmer.
  uint16_t bootKey = program ? 0x7777 : 0;

  *bootKeyPtr = bootKey;

  // setup watchdog timeout
  wdt_enable(WDTO_60MS);

  while(1) {} // wait for watchdog timer to trigger
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch (id) {
    case PROMICRO_PROGRAM:
      promicro_bootloader_jmp(true);
      break;
    default:
      break;
  }
}

// end of snippet


const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // 0: Qwerty
  KEYMAP(
    TAB,    Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,LBRC,FN10, \
    LGUI,   A,   S,   D,   F,   G,   H,   J,   K,   L,SCLN,      ENT, \
    LSFT,   Z,   X,   C,   V,   B,   N,   M,COMM, DOT,SLSH,      FN0, \
    FN11, FN1,LALT,        BSPC,FN8,                   RALT,FN9,FN2),

  // 1: Colemak
  KEYMAP(
    TAB,    Q,   W,   F,   P,   G,   J,   L,   U,   Y,SCLN,LBRC,FN10, \
    LGUI,   A,   R,   S,   T,   D,   H,   N,   E,   I,   O,      ENT, \
    LSFT,   Z,   X,   C,   V,   B,   K,   M,COMM, DOT,SLSH,      FN0, \
    FN11, FN1,LALT,        BSPC,FN8,                   RALT,FN9,FN2),

  // 2: Fn 1
  KEYMAP(
    CAPS,   1,   2,   3,   4,   5,   6,MPRV,MNXT,MPLY,  UP,BSLS,TRNS, \
    TRNS,   7,   8,   9,   0,MINS, EQL,HOME,PGUP,LEFT,RGHT,     TRNS, \
    TRNS,VOLD,VOLU,MUTE, SPC,TRNS, INS, END,PGDN,DOWN,QUOT,     TRNS, \
    TRNS, FN3,TRNS,        TRNS,TRNS,              DELETE,TRNS,TRNS),

  // 3: Fn 2
  KEYMAP(
    TRNS,FN15,FN16,FN17,FN18,FN19,FN20,TRNS,WH_L,WH_R,MS_U,FN27,TRNS, \
    TRNS,FN21,FN22,FN23,FN24,FN25,FN26,TRNS,WH_U,MS_L,MS_R,     BSPC, \
    TRNS,TRNS,BTN1,BTN2,TRNS,TRNS,WBAK,WFWD,WH_D,MS_D,FN28,      FN3, \
    TRNS,TRNS,TRNS,        TRNS,TRNS,              DELETE,TRNS,TRNS),

  // 4: Lock Layer
  KEYMAP(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  F1,  F2,  F3,  F4,TRNS,TRNS, \
    ESC, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  F5,  F6,  F7,  F8,     TRNS, \
    TRNS,   1,   2,   3,   4,   5,   6,  F9, F10, F11, F12,     TRNS, \
    LCTL,TRNS,TRNS,      SPC,BSPC,                   TRNS,FN31,TRNS),

  // 5: Config Layer
  KEYMAP(
    FN12, FN4, FN5,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
    TRNS,ACL0,ACL1,ACL2,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
    TRNS,TRNS,TRNS,        TRNS,TRNS,                TRNS,TRNS,TRNS),

};

enum macro_id {
  EXLM,
  AT,
  HASH,
  DLR,
  PERC,
  CIRC,
  AMPR,
  ASTR,
  LPRN,
  RPRN,
  UNDS,
  PLUS,
  PIPE,
  QUOT,
  DOTS,
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(2),      // to Fn 1
  [1] = ACTION_LAYER_MOMENTARY(3),      // to Fn 2
  [2] = ACTION_LAYER_TAP_TOGGLE(4),     // to Lock layer
  [3] = ACTION_LAYER_MOMENTARY(5),      // to Config Layer

  [4] = ACTION_DEFAULT_LAYER_SET(0),    // set qwerty layout
  [5] = ACTION_DEFAULT_LAYER_SET(1),    // set colemak layout

  [8] = ACTION_LAYER_TAP_KEY(2, KC_SPC),
  [9] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_GRV),
  [10] = ACTION_LAYER_TAP_KEY(3, KC_RBRC),
  [11] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
  [12] = ACTION_FUNCTION(PROMICRO_PROGRAM),

  [15] = ACTION_MACRO(EXLM),
  [16] = ACTION_MACRO(AT),
  [17] = ACTION_MACRO(HASH),
  [18] = ACTION_MACRO(DLR),
  [19] = ACTION_MACRO(PERC),
  [20] = ACTION_MACRO(CIRC),
  [21] = ACTION_MACRO(AMPR),
  [22] = ACTION_MACRO(ASTR),
  [23] = ACTION_MACRO(LPRN),
  [24] = ACTION_MACRO(RPRN),
  [25] = ACTION_MACRO(UNDS),
  [26] = ACTION_MACRO(PLUS),
  [27] = ACTION_MACRO(PIPE),
  [28] = ACTION_MACRO(QUOT),

  [31] = ACTION_MACRO(DOTS),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch (id) {
    case EXLM:
      return (record->event.pressed ?
        MACRO( D(LSHIFT), T(1), END ) :
        MACRO_NONE );

    case AT:
      return (record->event.pressed ?
        MACRO( D(LSHIFT), T(2), END ) :
        MACRO_NONE );

    case HASH:
      return (record->event.pressed ?
        MACRO( D(LSHIFT), T(3), END ) :
        MACRO_NONE );

    case DLR:
      return (record->event.pressed ?
        MACRO( D(LSHIFT), T(4), END ) :
        MACRO_NONE );

    case PERC:
      return (record->event.pressed ?
        MACRO( D(LSHIFT), T(5), END ) :
        MACRO_NONE );

    case CIRC:
      return (record->event.pressed ?
        MACRO( D(LSHIFT), T(6), END ) :
        MACRO_NONE );

    case AMPR:
      return (record->event.pressed ?
        MACRO( D(LSHIFT), T(7), END ) :
        MACRO_NONE );

    case ASTR:
      return (record->event.pressed ?
        MACRO( D(LSHIFT), T(8), END ) :
        MACRO_NONE );

    case LPRN:
      return (record->event.pressed ?
        MACRO( D(LSHIFT), T(9), END ) :
        MACRO_NONE );

    case RPRN:
      return (record->event.pressed ?
        MACRO( D(LSHIFT), T(0), END ) :
        MACRO_NONE );

    case UNDS:
      return (record->event.pressed ?
        MACRO( D(LSHIFT), T(MINS), END ) :
        MACRO_NONE );

    case PLUS:
      return (record->event.pressed ?
        MACRO( D(LSHIFT), T(EQL), END ) :
        MACRO_NONE );

    case PIPE:
      return (record->event.pressed ?
        MACRO( D(LSHIFT), T(BSLS), END ) :
        MACRO_NONE );

    case QUOT:
      return (record->event.pressed ?
        MACRO( D(LSHIFT), T(QUOT), END ) :
        MACRO_NONE );

    case DOTS:
      return (record->event.pressed ?
        MACRO( T(DOT), T(SPC), T(DOT), T(SPC), T(DOT), END ) :
        MACRO_NONE );
  }
  return MACRO_NONE;
}
