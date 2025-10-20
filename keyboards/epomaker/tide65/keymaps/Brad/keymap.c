// Copyright 2024 SDK (@sdk66)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum tide_layers {
   _QWERTY,
   _FN
 };

#define FN       MO(_FN)

#define ST_CAPS (SFT_T(KC_CAPS)) // need to change to tapdance

#define CNTL_X  LT(0,KC_X)
#define CNTL_C  LT(0,KC_C)
#define CNTL_V  LT(0,KC_V)
#define CNTL_A  LT(0,KC_A)
#define CNTL_S  LT(0,KC_S)
#define CNTL_Z  LT(0,KC_Z)

#define CTL_ESC (CTL_T(KC_ESC))

#define BETTES  LT(0,KC_1)
#define D_2020  LT(0,KC_2)
#define D_6449  LT(0,KC_3)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT( /* Base */
        KC_GRV,   BETTES,    D_2020,     D_6449,   KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,       KC_MINS,  KC_EQL,   KC_BSPC,   KC_MUTE,
        KC_TAB,   KC_Q,      KC_W,       KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,       KC_LBRC,  KC_RBRC,  KC_BSLS,   KC_DEL,
        CTL_ESC,  CNTL_A,    CNTL_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,    KC_QUOT,            KC_ENT,    _______,
        KC_LSFT,  CNTL_Z,    CNTL_X,     CNTL_C,   CNTL_V,   KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,               KC_SLSH,  KC_RSFT,  KC_UP,     _______,
        KC_LCTL,  KC_LALT,   KC_LGUI,    KC_SPC,   KC_SPC,   KC_SPC,   KC_SPC,                     KC_LGUI,                FN,     KC_LEFT,  KC_DOWN,   KC_RGHT
        ),

    [_FN] = LAYOUT( /* Base */
        KC_SLEP,  KC_F1,      KC_F2,      KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,   KC_F12,   _______,   QK_BOOT,
        KC_WAKE,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,   _______,
        _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,            _______,   _______,
        _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,  KC_PGUP,   _______,
        _______,  _______,    _______,    _______,  _______,  _______,  _______,                      _______,              FN,       KC_HOME,  KC_PGDN,   KC_END
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

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_CAPS):
            // Immediately select the hold action when another key is tapped.
            return true;
       // case SFT_T(KC_ENT):
            // Immediately select the hold action when another key is tapped.
            //return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
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
        case LT(0,KC_1):
           if (!record->tap.count && record->event.pressed) {
                SEND_STRING("bettebrp");
                return false;
           }
           return true;
        case LT(0,KC_2):
           if (!record->tap.count && record->event.pressed) {
                SEND_STRING("Diane..2020");
                return false;
           }
           return true;
        case LT(0,KC_3):
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
//    case _SPACE_FN:
//        rgblight_setrgb (RGB_GREEN);
//       break;
//    case _NAV:
//        rgblight_setrgb (RGB_MAGENTA);
//        break;
//    case _MOUSE:
//        rgblight_setrgb (RGB_ORANGE);
//        break;
    case _FN:
        rgblight_sethsv (HSV_RED);
        break;
    default: //  for any other layers, or the default layer
        rgblight_sethsv (HSV_BLUE);
        break;
    }
  return state;
}
// clang-format on
