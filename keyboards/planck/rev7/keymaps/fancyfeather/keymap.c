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
#define SFT_CPS (LSFT_T(KC_CAPS))
#define SHF_ENT (LSFT_T(KC_ENT))
#define FN MO(_FN)

const key_override_t slash_backslash = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_BSLS);
const key_override_t dot_exclamation = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXLM);
const key_override_t comma_question = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_QUES);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&slash_backslash,
   &dot_exclamation,
   &comma_question
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* <------------------------------------------------- QWERTY -------------------------------------------------->
  * ,-----------------------------------------------------------------------------------------------------------.
  * |  ESC   |    Q   |    W   |    E   |    R   |    T   |    Y   |    U   |    I   |    O   |    P   |  BKSP  |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * |  TAB   |    A   |    S   |    D   |    F   |    G   |    H   |    J   |    K   |    L   |    ;   |    '   |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * |SH/CAPS |    Z   |    X   |    C   |    V   |    B   |    N   |    M   |    ,   |    .   |    /   |SH/ENTER|
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * |   FN   | VOL DN | VOL UP |   GUI  |  CTRL  |    SPACE_FN     |   ALT  |  LEFT  |   DOWN |   UP   | RIGHT  |
  * `-----------------------------------------------------------------------------------------------------------'
 */
 [_QWERTY] = LAYOUT_planck_mit(
     QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
     SFT_CPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, SHF_ENT,
     KC_TAB,  KC_UP,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_Z,    KC_COMM, KC_QUOT, KC_LGUI,
     KC_LEFT, KC_DOWN, KC_RGHT, KC_SLSH, SC_LCPO,     SPACE_FN,     SC_RAPC, KC_DOT,  KC_VOLD, KC_VOLU, KC_DEL
 ),

 /* <------------------------------------------------ SPACE_FN ------------------------------------------------->
  * ,-----------------------------------------------------------------------------------------------------------.
  * |    `   |    1   |    2   |    3   |    4   |    5   |    6   |    7   |    8   |    9   |    0   |   DEL  |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * |        |        |        |        |        |    [   |    ]   |        |        |        |        |        |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * |SH/CAPS |        |        |        |        |    -   |    =   |        |        |        |    \   |SH/ENTER|
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * |   FN   | VOL DN | VOL UP |   GUI  |  CTRL  |=================|   ALT  |  HOME  |  PG DN | PG UP  |  END   |
  * `-----------------------------------------------------------------------------------------------------------'
 */
 [_SPACE_FN] = LAYOUT_planck_mit(
     KC_INS,  MS_WHLU, MS_BTN1, MS_UP,   MS_BTN2, KC_UNDS, KC_PIPE, KC_7,    KC_8,    KC_9,    KC_PPLS, _______, 
     _______, MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, KC_LT,   KC_GT,   KC_4,    KC_5,    KC_6,    KC_PMNS, _______, 
     _______, KC_PGUP, KC_DLR,  KC_AMPR, KC_HASH, KC_LBRC, KC_RBRC, KC_1,    KC_2,    KC_3,    KC_PAST, FN, 
     KC_HOME, KC_PGDN, KC_END,  KC_CIRC, KC_AT,        _______,     KC_0,    KC_PDOT, KC_PEQL, KC_PSLS, KC_END
 ),

 /* <--------------------------------------------------- FN ---------------------------------------------------->
  * ,-----------------------------------------------------------------------------------------------------------.
  * |  RESET |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |   F7   |   F8   |   F9   |   F10  | SLEEP  |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * |  DEBUG |   F11  |   F12  |        |        |        |        |        |        |        |        |  WAKE  |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * |        |        |        |        |        |        |        |        | M BN 1 | M SC DN|M SC UP | M BN 2 |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * |========| BL DN  | BL UP  |   GUI  |  CTRL  |      SPACE      |   ALT  |   M LT |   M DN | M UP   | M RT   |
  * `-----------------------------------------------------------------------------------------------------------'
 */
 [_FN] = LAYOUT_planck_mit(
     QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_SLEP, 
     DB_TOGG, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WAKE, 
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, 
     XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,      _______,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
 )

};