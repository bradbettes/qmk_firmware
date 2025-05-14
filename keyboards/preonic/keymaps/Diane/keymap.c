/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
   _QWERTY,
   _SPACE_FN,
   _FN,
};

#define SPACE_FN LT(_SPACE_FN, KC_SPC)
#define FN MO(_FN)

#define ST_CAPS (SFT_T(KC_CAPS))
#define ST_ENT (SFT_T(KC_ENT))

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
|    `    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |    0    |   BKSP  |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|   TAB   |    Q    |    W    |    E    |    R    |    T    |    Y    |    U    |    I    |    O    |    P    |   DEL   |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|   ESC   |    A    |    S    |    D    |    F    |    G    |    H    |    J    |    K    |    L    |    ;    |    '    |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|   CAPS  |         |         |         |         |         |         |         |         |         |         |  ENTER  |
|         |    Z    |    X    |    C    |    V    |    B    |    N    |    M    |    ,    |    .    |   UP    |         |
|  SHIFT  |         |         |         |         |         |         |         |         |         |         |  SHIFT  |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
| VOL U/D |         |         |         |         |                   |         |         |         |         |         |
| ENCODER |   FN    |   CTRL  |   OPT   |   CMD   |      SPACE_FN     |    -    |    =    |   LEFT  |   DN    |  RIGHT  |
|   MUTE  |         |         |         |         |                   |         |         |         |         |         |
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
*/
 [_QWERTY] = LAYOUT_preonic_grid(
  KC_GRV,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,    KC_BSPC,
  KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,    KC_DEL,
  KC_ESC,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
  ST_CAPS,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,    KC_COMM,  KC_DOT,    KC_UP,   ST_ENT,
  KC_MUTE,    FN,     KC_LCTL,  KC_LALT,  KC_LGUI,      SPACE_FN,       KC_MINS,   KC_EQL,  KC_LEFT,  KC_DOWN,  KC_RGHT
 ),

/*
 ====================================================== SPACE_FN =======================================================
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
|         |         |         |         |         |         |         |         |         |         |         |         |
|   INS   |         |         |         |         |         |         |         |         |         |         |         |
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
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |         |         |         |    \    |    [    |    ]    |    /    |         |         |         |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |                   |         |         |         |         |         |
|         |         |         |         |         |                   |         |         |         |         |         |
|         |         |         |         |         |                   |         |         |         |         |         |
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
*/
 [_SPACE_FN] = LAYOUT_preonic_grid(
  KC_INS,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSLS,  KC_LBRC,  KC_RBRC,  KC_SLSH,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,      SPACE_FN,       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
 ),

/*
 ========================================================= FN ==========================================================
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
|         |         |         |         |         |         |         |         |         |         |         |         |
|  SLEEP  |    F1   |    F2   |    F3   |    F4   |    F5   |   F6    |   F7    |   F8    |   F9    |   F10   |  RESET  |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|  WAKE   |    F1   |    F2   |    F3   |    F4   |    F5   |   F6    |   F7    |   F8    |   F9    |   F10   |  DEBUG  |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |         |         |  PG UP  |         |
|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |                   |         |         |         |         |         |
|         |   FN    |         |         |         |                   |         |         |    HOME |  PG DN  | END     |
|         |         |         |         |         |                   |         |         |         |         |         |
 ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
*/
 [_FN] = LAYOUT_preonic_grid(
  KC_SLEP,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,  QK_BOOT,
  KC_WAKE,   KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,  DB_TOGG,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PGUP,  XXXXXXX,
  XXXXXXX,    FN,     XXXXXXX,  XXXXXXX,  XXXXXXX,       XXXXXXX,       XXXXXXX,  XXXXXXX,  KC_HOME,  KC_PGDN,  KC_END
 )

};

/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef RGBLIGHT_ENABLE
              rgblight_step();
            #endif
            #ifdef __AVR__
            gpio_write_pin_low(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            gpio_write_pin_high(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};
*/


/*
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_VOLU);
      unregister_code(KC_VOLU);
    } else {
      register_code(KC_VOLD);
      unregister_code(KC_VOLD);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
*/