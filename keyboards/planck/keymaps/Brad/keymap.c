/* Copyright 2015-2023 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum planck_layers {
   _QWERTY,
   _SPACE_FN,
   _NAV,
   _MOUSE,
   _FN
 };

#define SPACE_FN LT(_SPACE_FN, KC_SPC)
#define FN       MO(_FN)
#define NAV      LT(_NAV, KC_EQL)
#define MOUSE    LT(_MOUSE, KC_MINS)

#define ST_CAPS (SFT_T(KC_CAPS))
#define ST_ENT  (SFT_T(KC_ENT))

#define CNTL_X  LT(0,KC_X)
#define CNTL_C  LT(0,KC_C)
#define CNTL_V  LT(0,KC_V)
#define CNTL_A  LT(0,KC_A)
#define CNTL_S  LT(0,KC_S)
#define CNTL_Z  LT(0,KC_Z)

#define CTL_RWD (CTL_T(KC_MRWD))
#define ALT_PL  (ALT_T(KC_MPLY))
#define GUI_FF  (GUI_T(KC_MFFD))

//#define CTL_QT  (CTL_T(KC_QUOT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 ======================================================= QWERTY ========================================================
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
|         |         |         |         |         |         |         |         |         |         |         |         |
|   TAB   |    Q    |    W    |    E    |    R    |    T    |    Y    |    U    |    I    |    O    |    P    |   BKSP  |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|   ESC   |    A    |    S    |    D    |    F    |    G    |    H    |    J    |    K    |    L    |    ;    |   DEL   |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|   CAPS  |    Z    |    X    |    C    |    V    |    B    |    N    |    M    |    ,    |    .    |    /    |  ENTER  |
|  SHIFT  |         |         |         |         |         |         |         |         |         |         |  SHIFT  |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
| VOL U/D |         |         |         |         |                   |         |         |         |         |         |
| ENCODER |    REW  |  PL/PS  |   FF    |    -    |      SPACE_FN     |    =    |   CTRL  |   ALT   |   GUI   |   FN    |
| KC_MUTE |   CTRL  |   ALT   |   GUI   |  MOUSE  |                   |   NAV   |         |         |         |         |
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
*/
 [_QWERTY] = LAYOUT_planck_mit(
  KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     KC_BSPC,
  KC_ESC,   CNTL_A,   CNTL_S,    KC_D,     KC_F,     KC_G,     KC_H,     KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_DEL,
  ST_CAPS,  CNTL_Z,   CNTL_X,   CNTL_C,   CNTL_V,    KC_B,     KC_N,     KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  ST_ENT,
  KC_MUTE,  CTL_RWD,  ALT_PL,   GUI_FF,    MOUSE,        SPACE_FN,        NAV,    KC_LCTL,  KC_LALT,  KC_LGUI,     FN
 ),

/*
 ====================================================== SPACE_FN =======================================================
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
|         |         |         |         |         |         |         |         |         |         |         |         |
|   INS   |    F1   |    F2   |    F3   |    F4   |    F5   |   F6    |   F7    |   F8    |   F9    |   F10   |   BKSP  |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|    `    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |    0    |    '    |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|   CAPS  |         |         |         |         |    [    |    ]    |         |    ,    |    .    |    \    |  ENTER  |
|  SHIFT  |         |         |         |         |         |         |         |         |         |         |  SHIFT  |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |                   |         |         |         |         |         |
| ENCODER |  CTRL   |   ALT   |   GUI   |    -    |      SPACE_FN     |    =    |   CTRL  |   ALT   |   GUI   |         |
|         |         |         |         |         |                   |         |         |         |         |         |
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
*/
 [_SPACE_FN] = LAYOUT_planck_mit(
  _______,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   _______,
  KC_GRV,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,    KC_QUOT,
  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LBRC,  KC_RBRC,  XXXXXXX,  _______,  _______,  KC_BSLS,  _______,
  _______,  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_MINS,       _______,       KC_EQL,   KC_LCTL,  KC_LALT,  KC_LGUI,  XXXXXXX
 ),

/*
 ========================================================= NAV =========================================================
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
|         |         |         |         |         |         |         |         |         |         |         |         |
|   TAB   |         |  PG UP  |         |         |         |         |         |         |    UP   |         |   BKSP  |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|   ESC   |   HOME  |  PG DN  |   END   |         |         |         |         |    LT   |    DN   |   RT    |   DEL   |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |                   |         |         |         |         |         |
|         |         |         |         |         |                   |         |         |         |         |         |
|         |         |         |         |         |                   |   NAV   |         |         |         |         |
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
*/
 [_NAV] = LAYOUT_planck_mit(
  _______,  XXXXXXX,  KC_PGUP,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   KC_UP,   XXXXXXX,  _______,
  KC_ESC,   KC_HOME,  KC_PGDN,  KC_END,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_DEL,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  KC_LCTL,  KC_LALT,  KC_LGUI,  XXXXXXX,       XXXXXXX,         NAV,    KC_LCTL,  KC_LALT,  KC_LGUI,  XXXXXXX
 ),

/*
 ======================================================== MOUSE ========================================================
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |         |  SC_UP  |         |         |         |         |         |  LT_CK  |  MS_UP  |  RT_CK  |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |  SC_LT  |  SC_DN  |  SC_RT  |         |         |         |         |  MS_LT  |  MS_DN  |  MS_RT  |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |                   |         |         |         |         |         |
|         |         |         |         |         |                   |         |         |         |         |         |
|         |         |         |         |  MOUSE  |                   |         |         |         |         |         |
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
*/
 [_MOUSE] = LAYOUT_planck_mit(
  XXXXXXX,  XXXXXXX,  MS_WHLU,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  MS_BTN1,   MS_UP,   MS_BTN2,  XXXXXXX,
  XXXXXXX,  MS_WHLL,  MS_WHLD,  MS_WHLR,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  MS_LEFT,  MS_DOWN,  MS_RGHT,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   MOUSE,        XXXXXXX,       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
 ),

/*
 ========================================================= FN ==========================================================
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
|         |         |         |         |         |         |         |         |         |         |         |         |
|  RESET  |         |         |         |         |         |         |         |         |         |         |  SLEEP  |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|  DEBUG  |         |         |         |         |         |         |         |         |         |         |  WAKE   |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |                   |         |         |         |         |         |
|         |         |         |         |         |                   |         |         |         |         |    FN   |
|         |         |         |         |         |                   |         |         |         |         |         |
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
*/
 [_FN] = LAYOUT_planck_mit(
  QK_BOOT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_SLEP,
  DB_TOGG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_WAKE,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,       XXXXXXX,       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     FN
 )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CNTL_X:
            return TAPPING_TERM + 200;  // Adding "+" value to TAPPING_TERM stated in config.h
        case CNTL_C:
            return TAPPING_TERM + 200;
        case CNTL_V:
            return TAPPING_TERM + 200;
        case CNTL_A:
            return TAPPING_TERM + 200;
        case CNTL_S:
            return TAPPING_TERM + 200;
        case CNTL_Z:
            return TAPPING_TERM + 200;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
       case LT(0,KC_X):
           if (!record->tap.count && record->event.pressed) {
               tap_code16(C(KC_X)); // Intercept hold function to send Ctrl-X
               return false;
           }
           return true;             // Return true for normal processing of tap keycode
       case LT(0,KC_C):
           if (!record->tap.count && record->event.pressed) {
               tap_code16(C(KC_C));
               return false;
           }
           return true;
       case LT(0,KC_V):
           if (!record->tap.count && record->event.pressed) {
               tap_code16(C(KC_V));
               return false;
           }
           return true;
       case LT(0,KC_A):
           if (!record->tap.count && record->event.pressed) {
               tap_code16(C(KC_A));
               return false;
           }
           return true;
       case LT(0,KC_S):
           if (!record->tap.count && record->event.pressed) {
               tap_code16(C(KC_S));
               return false;
           }
           return true;
        case LT(0,KC_Z):
           if (!record->tap.count && record->event.pressed) {
               tap_code16(C(KC_Z));
               return false;
           }
           return true;
   }
   return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _SPACE_FN:
        rgblight_setrgb (RGB_GREEN);
        break;
    case _NAV:
        rgblight_setrgb (RGB_MAGENTA);
        break;
    case _MOUSE:
        rgblight_setrgb (RGB_ORANGE);
        break;
    case _FN:
        rgblight_setrgb (RGB_RED);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (RGB_BLUE);
        break;
    }
  return state;
}

//===== HOLD ONTO STUFF HERE =====>>

/*
 ======================================================== BLANK ========================================================
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |                   |         |         |         |         |         |
|         |         |         |         |         |                   |         |         |         |         |         |
|         |         |         |         |         |                   |         |         |         |         |         |
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------

 [_BLANK] = LAYOUT_planck_mit(
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,       XXXXXXX,       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
 )
*/

/*
// Defines modified shifted state of Up button to ?
const key_override_t shift_up_question = ko_make_basic(MOD_MASK_SHIFT, KC_UP, KC_QUES);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&shift_up_question
};
*/

