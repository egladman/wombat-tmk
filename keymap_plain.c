#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  //0: qwerty
  KEYMAP(
    TAB,    Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,LBRC,RBRC, \
    LGUI,   A,   S,   D,   F,   G,   H,   J,   K,   L,SCLN,      ENT, \
    LSFT,   Z,   X,   C,   V,   B,   N,   M,COMM, DOT,SLSH,       NO, \
    LCTL,  NO,LALT,          BSPC, SPC,              RALT,RSFT,  NO),

};

const uint16_t PROGMEM fn_actions[] = {
};
