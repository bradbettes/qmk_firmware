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

const key_override_t delete_escape = ko_make_basic(MOD_MASK_SHIFT, KC_DEL, KC_ESC);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
   &delete_escape
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* 
 ======================================================= QWERTY ========================================================
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
|         |         |         |         |         |         |         |         |         |         |         |         |
|   TAB   |    Q    |    W    |    E    |    R    |    T    |    Y    |    U    |    I    |    O    |    P    |   BKSP  |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
| DEL ESC |    A    |    S    |    D    |    F    |    G    |    H    |    J    |    K    |    L    |    ;    |    '    |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
| CAP SHF |    Z    |    X    |    C    |    V    |    B    |    N    |    M    |    ,    |    .    |    /    | ENT SHF |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |                   |         |         |         |         |         |
|  CTRL ( |    FN   |   WIN   | ) ALT   |  VOL D  |      SPACE_FN     |  VOL U  |   LEFT  |    DN   |   UP    |  RIGHT  |
|         |         |         |         |         |                   |         |         |         |         |         |
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+--------- 
*/
 [_QWERTY] = LAYOUT_planck_mit(
  KC_DEL,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,    KC_BSPC,
  KC_TAB,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
  SFT_CPS,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  SHF_ENT,
  SC_LCPO,    FN,     KC_LGUI,  SC_RAPC,  KC_VOLD,      SPACE_FN,       KC_VOLU,  KC_LEFT,  KC_DOWN,   KC_UP,   KC_RGHT
 ),

/* 
 ====================================================== SPACE_FN =======================================================
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
|         |         |         |         |         |         |         |         |         |         |         |         |
|    `    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |    0    |   BKSP  |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|   INS   |    F1   |    F2   |    F3   |   F4    |   F5    |   F6    |    -    |    =    |    [    |    ]    |    \    |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
| CAP SHF |    F7   |    F8   |    F9   |   F10   |   F11   |   F12   |         |         |         |         | ENT SHF |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |                   |         |         |         |         |         |
|  CTRL ( |    FN   |   WIN   | ) ALT   |  VOL D  |  SPACE  SPACE_FN  |  VOL U  |   HOME  |  PG DN  |  PG UP  |  END    |
|         |         |         |         |         |                   |         |         |         |         |         |
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
*/
 [_SPACE_FN] = LAYOUT_planck_mit(
  KC_INS,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,    _______, 
  KC_GRV,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,   KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS, 
  _______,   KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______, 
  _______,  _______,  _______,  _______,  _______,       _______,       _______,  KC_HOME,  KC_PGDN,  KC_PGUP,   KC_END
 ),

/* 
 ========================================================= FN ==========================================================
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
|         |         |         |         |         |         |         |         |         |         |         |         |
|  RESET  |         |         |         |         |         |         |         |         |         |         |  SLEEP  |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|  DEBUG  |         |         |         |         |         |         |         |         |         |         |   WAKE  |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |  LT CLK |  WHL DN | WHL UP  | RT CLK  |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |                   |         |         |         |         |         |
|         |    FN   |         |         |  VOL D  |       SPACE       |  VOL U  |  MS LT  |  MS DN  |  MS UP  |  MS RT  |
|         |         |         |         |         |                   |         |         |         |         |         |
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
*/
 [_FN] = LAYOUT_planck_mit(
  QK_BOOT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_SLEP, 
  DB_TOGG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_WAKE, 
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  MS_BTN1,  MS_WHLD,  MS_WHLU,  MS_BTN2, 
  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  _______,        KC_SPC,       _______,  MS_LEFT,  MS_DOWN,   MS_UP,   MS_RGHT
 )

};
