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

//#define CTL_QT  (CTL_T(KC_QUOT))
//#define CTL_ESC (CTL_T(KC_ESC))
//#define CTL_DEL (CTL_T(KC_DEL))

#define BETTES  LT(0,KC_Q)
#define D_2020  LT(0,KC_W)
#define D_6449  LT(0,KC_E)

// Defines modified shifted state of Up button to ?
const key_override_t shift_up_question = ko_make_basic(MOD_MASK_SHIFT, KC_UP, KC_QUES);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&shift_up_question
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 ======================================================= QWERTY ========================================================
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
|         |         |         |         |         |         |         |         |         |         |         |         |
|   TAB   |    Q    |    W    |    E    |    R    |    T    |    Y    |    U    |    I    |    O    |    P    |   BKSP  |
|         |bettebrp |  D2020  |  D6449  |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|   ESC   |    A    |    S    |    D    |    F    |    G    |    H    |    J    |    K    |    L    |    ;    |   DEL   |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|   CAPS  |    Z    |    X    |    C    |    V    |    B    |    N    |    M    |    ,    |    .    |   UP    |  ENTER  |
|  SHIFT  |         |         |         |         |         |         |         |         |         |         |  SHIFT  |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
| VOL U/D |         |         |         |         |                   |         |         |         |         |         |
| ENCODER |    FN   |   CTRL  |   ALT   |    -    |      SPACE_FN     |    =    |   GUI   |   LEFT  |   DN    |  RIGHT  |
| FN_MUTE |         |         |         |  MOUSE  |                   |         |         |         |         |         |
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
*/
 [_QWERTY] = LAYOUT_planck_mit(
  KC_TAB,   BETTES,   D_2020,   D_6449,    KC_R,     KC_T,      KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     KC_BSPC,
  KC_ESC,   CNTL_A,   CNTL_S,    KC_D,     KC_F,     KC_G,      KC_H,     KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_DEL,
  ST_CAPS,  CNTL_Z,   CNTL_X,   CNTL_C,   CNTL_V,    KC_B,      KC_N,     KC_M,   KC_COMM,   KC_DOT,   KC_UP,    ST_ENT,
  KC_MUTE,    FN,     KC_LCTL,  KC_LALT,   MOUSE,       SPACE_FN,        KC_EQL,  KC_LGUI,   KC_LEFT,  KC_DOWN,  KC_RGHT
 ),

/*
 ====================================================== SPACE_FN =======================================================
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
|         |         |         |         |         |         |         |         |         |         |         |         |
|   TAB   |         |         |         |         |         |         |         |         |         |         |   BKSP  |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|    `    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |    0    |    '    |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|   CAPS  |         |         |         |    \    |    [    |    ]    |    /    |    ,    |    .    |  PG UP  |  ENTER  |
|  SHIFT  |         |         |         |         |         |         |         |         |         |         |  SHIFT  |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |                   |         |         |         |         |         |
| ENCODER |         |   CTRL  |   ALT   |    -    |      SPACE_FN     |    =    |   GUI   |   HOME  |  PG DN  |   END   |
|         |         |         |         |         |                   |         |         |         |         |         |
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
*/
 [_SPACE_FN] = LAYOUT_planck_mit(
  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX   _______,
  KC_GRV,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,    KC_QUOT,
  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSLS,  KC_LBRC,  KC_RBRC,  KC_SLSH,  _______,  _______,  KC_PGUP,  _______,
  _______,  XXXXXXX,  _______,  _______,  KC_MINS,       _______,       _______,  _______,  KC_HOME,  KC_PGDN,  KC_END,
 ),

/*
 ========================================================= NAV =========================================================
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
|         |         |         |         |         |                   |   NAV   |         |         |         |         |
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
*/
/*
 [_NAV] = LAYOUT_planck_mit(
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,       XXXXXXX,         NAV,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
 ),
*/
/*
 ======================================================== MOUSE ========================================================
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |  RT_CK  |  MS_UP  |  LT_CK  |         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |  MS_LT  |  MS_DN  |  MS_RT  |         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |         |         |  SC_UP  |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |                   |         |         |         |         |         |
|         |         |         |         |  MOUSE  |                   |         |         |  SC_LT  |  SC_DN  |  SC_RT  |
|         |         |         |         |         |                   |         |         |         |         |         |
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
*/
 [_MOUSE] = LAYOUT_planck_mit(
  XXXXXXX,  MS_BTN2,   MS_UP,   MS_BTN1,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  MS_LEFT,  MS_DOWN,  MS_RGHT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  MS_WHLU,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   MOUSE,        XXXXXXX,       XXXXXXX,  XXXXXXX,  MS_WHLL,  MS_WHLD,  MS_WHLR
 ),

/*
 ========================================================= FN ==========================================================
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
|         |         |         |         |         |         |         |         |         |         |         |         |
|  SLEEP  |    F1   |    F2   |    F3   |    F4   |    F5   |   F6    |   F7    |   F8    |   F9    |   F10   |  RESET  |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|  WAKE   |   F11   |   F12   |   F13   |   F14   |   F15   |   F16   |   F17   |   F18   |   F19   |   F20   |  DEBUG  |
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
  KC_SLEP,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,  QK_BOOT,
  KC_WAKE,   KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,  DB_TOGG,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,    FN,     XXXXXXX,  XXXXXXX,  XXXXXXX,       XXXXXXX,       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
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
        case BETTES:
            return TAPPING_TERM + 200;
        case D_2020:
            return TAPPING_TERM + 200;
        case D_6449:
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
        case LT(0,KC_Q):
           if (!record->tap.count && record->event.pressed) {
                SEND_STRING("bettebrp");
                return false;
           }
           return true;
        case LT(0,KC_W):
           if (!record->tap.count && record->event.pressed) {
                SEND_STRING("Diane..2020");
                return false;
           }
           return true;
        case LT(0,KC_E):
           if (!record->tap.count && record->event.pressed) {
                SEND_STRING("Diane..6449");
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
//    case _NAV:
//        rgblight_setrgb (RGB_MAGENTA);
//       break;
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
