#pragma once
#include "quantum.h"

// Custom keycodes start marker (nothing added yet)
enum blackfeather_keycodes {
    BLACKFEATHER_SAFE_RANGE = SAFE_RANGE
    // Add new keycodes after this line
};

#define SFT_CAP (SFT_T(KC_CAPS))
#define CTL_ESC (CTL_T(KC_ESC))

#define CNTL_X  LT(0, KC_X)
#define CNTL_C  LT(0, KC_C)
#define CNTL_V  LT(0, KC_V)
#define CNTL_A  LT(0, KC_A)
#define CNTL_S  LT(0, KC_S)
#define CNTL_Z  LT(0, KC_Z)

// String macro keys
#define BETTES  LT(0, KC_1)
#define D_2020  LT(0, KC_2)
#define D_6449  LT(0, KC_3)
#define D_2890  LT(0, KC_4)

// Optional “shared” function prototypes
bool blackfeather_process_record(uint16_t keycode, keyrecord_t *record);
void blackfeather_layer_init(void);

// --- Userspace lighting hooks (keymap doesn’t need to implement anything) ---
uint8_t bf_get_base_layer(void);
uint8_t bf_get_fn_layer(void);
