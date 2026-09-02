// Copyright 2026 Brad Bettes
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

enum blackfeather_keycodes {
    SFT_CAP = SAFE_RANGE,
    BF_SAFE_RANGE,
};

#define BF_SFT_CAP_TAP_HOLD SFT_T(KC_CAPS)
#define BF_CTL_ESC CTL_T(KC_ESC)

#define BF_CTL_A LT(0, KC_A)
#define BF_CTL_S LT(0, KC_S)
#define BF_CTL_Z LT(0, KC_Z)
#define BF_CTL_X LT(0, KC_X)
#define BF_CTL_C LT(0, KC_C)
#define BF_CTL_V LT(0, KC_V)

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
