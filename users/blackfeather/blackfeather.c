// Copyright 2026 Brad Bettes
// SPDX-License-Identifier: GPL-2.0-or-later

#include "blackfeather.h"

typedef struct {
    bool     interrupted;
    bool     second_tap;
    bool     first_tap_pending;
    uint16_t pressed_at;
    uint16_t first_tap_at;
} sft_caps_state_t;

static sft_caps_state_t sft_caps_state;

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode != SFT_CAP && record->event.pressed) {
        sft_caps_state.interrupted       = true;
        sft_caps_state.first_tap_pending = false;
    }

    switch (keycode) {
        case SFT_CAP:
            if (record->event.pressed) {
                sft_caps_state.interrupted       = false;
                sft_caps_state.second_tap        = sft_caps_state.first_tap_pending && timer_elapsed(sft_caps_state.first_tap_at) <= BF_SFT_CAP_DOUBLE_TAP_TERM;
                sft_caps_state.first_tap_pending = false;
                sft_caps_state.pressed_at        = timer_read();
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LSFT);

                bool tapped = !sft_caps_state.interrupted && timer_elapsed(sft_caps_state.pressed_at) <= BF_SFT_CAP_DOUBLE_TAP_TERM;

                if (sft_caps_state.second_tap) {
                    if (tapped) {
                        tap_code(KC_CAPS);
                    }
                } else if (tapped) {
                    sft_caps_state.first_tap_pending = true;
                    sft_caps_state.first_tap_at      = timer_read();
                }

                sft_caps_state.interrupted = false;
                sft_caps_state.second_tap  = false;
            }
            return false;
        case BF_CTL_A:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_A));
                return false;
            }
            break;
        case BF_CTL_S:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_S));
                return false;
            }
            break;
        case BF_CTL_Z:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_Z));
                return false;
            }
            break;
        case BF_CTL_X:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_X));
                return false;
            }
            break;
        case BF_CTL_C:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_C));
                return false;
            }
            break;
        case BF_CTL_V:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_V));
                return false;
            }
            break;
    }

    return process_record_keymap(keycode, record);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BF_CTL_A:
        case BF_CTL_S:
        case BF_CTL_Z:
        case BF_CTL_X:
        case BF_CTL_C:
        case BF_CTL_V:
        case BF_SFT_CAP_TAP_HOLD:
            return TAPPING_TERM + 200;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    return keycode == BF_SFT_CAP_TAP_HOLD;
}
