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
   _FN
 };

#define SPACE_FN LT(_SPACE_FN, KC_SPC)
#define FN MO(_FN)

#define ST_CAPS (SFT_T(KC_CAPS))
#define ST_ENT (SFT_T(KC_ENT))

#define CTL_ESC (CTL_T(KC_ESC))
#define CTL_DEL (CTL_T(KC_DEL))
#define CTL_GRV (CTL_T(KC_GRV))
#define CTL_QT (CTL_T(KC_QUOT))

#define CNTL_X LT(0,KC_X)
#define CNTL_C LT(0,KC_C)
#define CNTL_V LT(0,KC_V)
#define CNTL_A LT(0,KC_A)
#define CNTL_S LT(0,KC_S)
#define CNTL_Z LT(0,KC_Z)

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CNTL_X:
            return TAPPING_TERM + 200;
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
               tap_code16(C(KC_C)); // Intercept hold function to send Ctrl-C
               return false;
           }
           return true;             // Return true for normal processing of tap keycode
       case LT(0,KC_V):
           if (!record->tap.count && record->event.pressed) {
               tap_code16(C(KC_V)); // Intercept hold function to send Ctrl-V
               return false;
           }
           return true;             // Return true for normal processing of tap keycode
       case LT(0,KC_A):
           if (!record->tap.count && record->event.pressed) {
               tap_code16(C(KC_A)); // Intercept hold function to send Ctrl-A
               return false;
           }
           return true;             // Return true for normal processing of tap keycode
       case LT(0,KC_S):
           if (!record->tap.count && record->event.pressed) {
               tap_code16(C(KC_S)); // Intercept hold function to send Ctrl-S
               return false;
           }
           return true;             // Return true for normal processing of tap keycode
        case LT(0,KC_Z):
           if (!record->tap.count && record->event.pressed) {
               tap_code16(C(KC_Z)); // Intercept hold function to send Ctrl-Z
               return false;
           }
           return true;             // Return true for normal processing of tap keycode
   }
   return true;
}

/*
// Defines modified shifted state of Up button to ?
const key_override_t shift_up_question = ko_make_basic(MOD_MASK_SHIFT, KC_UP, KC_QUES);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&shift_up_question
};
*/

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
|   CNTL  |         |         |         |         |         |         |         |         |         |         |   CNTL  |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|   CAPS  |    Z    |    X    |    C    |    V    |    B    |    N    |    M    |    ,    |    .    |   UP    |  ENTER  |
|  SHIFT  |         |         |         |         |         |         |         |         |         |         |  SHIFT  |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
| VOL U/D |   RWD   |    FF   |         |         |                   |         |         |         |         |         |
| ENCODER |  VOL DN | VOL UP  |   ALT   |    -    |      SPACE_FN     |    =    |   GUI   |   LEFT  |   DN    |  RIGHT  |
|    FN   | KC_MRWD | KC_MFFD |         |         |                   |         |         |         |         |         |
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
*/
 [_QWERTY] = LAYOUT_planck_mit(
  KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,    KC_BSPC,
  CTL_ESC,  CNTL_A,   CNTL_S,    KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN,  CTL_DEL,
  ST_CAPS,  CNTL_Z,   CNTL_X,   CNTL_C,   CNTL_V,    KC_B,     KC_N,     KC_M,    KC_COMM,  KC_DOT,    KC_UP,   ST_ENT,
    FN,     KC_VOLD,  KC_VOLU,  KC_LALT,  KC_MINS,      SPACE_FN,       KC_EQL,   KC_LGUI,  KC_LEFT,  KC_DOWN,  KC_RGHT
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
|  CNTL   |         |         |         |         |         |         |         |         |         |         |   CNTL  |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|   CAPS  |         |         |         |    \    |    [    |    ]    |    /    |    ,    |    .    |  PG UP  |  ENTER  |
|  SHIFT  |         |         |         |         |         |         |         |         |         |         |  SHIFT  |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |                   |         |         |         |         |         |
|         |         |         |   ALT   |    -    |      SPACE_FN     |    =    |   GUI   |   HOME  |  PG DN  |  END    |
|         |         |         |         |         |                   |         |         |         |         |         |
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
*/
 [_SPACE_FN] = LAYOUT_planck_mit(
  KC_INS,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,  _______,
  CTL_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,    CTL_QT,
  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSLS,  KC_LBRC,  KC_RBRC,  KC_SLSH,  _______,  _______,  KC_PGUP,  _______,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,       _______,       _______,  _______,  KC_HOME,  KC_PGDN,   KC_END
 ),

/*
 ========================================================= FN ==========================================================
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
|         |         |         |         |         |         |         |         |         |         |         |         |
|  SLEEP  |         |         |         |         |         |         |         |         |         |         |  RESET  |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|  WAKE   |         |         |         |         |         |         |         |         |         |         |  DEBUG  |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |                   |         |         |         |         |         |
|   FN    |         |         |         |         |                   |         |         |         |         |         |
|         |         |         |         |         |                   |         |         |         |         |         |
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
*/
 [_FN] = LAYOUT_planck_mit(
  KC_SLEP,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  QK_BOOT,
  KC_WAKE,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  DB_TOGG,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    FN,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,       XXXXXXX,       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
 )

};
