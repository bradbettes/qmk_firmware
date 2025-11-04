#include "blackfeather.h"

// Optional init hook you can call from keyboard_post_init_user
__attribute__((weak)) void blackfeather_layer_init(void) {}

// Central dispatcher for your shared keycodes.
// Returns true to continue default handling, false to consume.
bool blackfeather_process_record(uint16_t keycode, keyrecord_t *record) {
    //bool pressed = record->event.pressed;
    //bool is_hold = !record->tap.count && record->event.pressed;

   switch (keycode) {
        // ----- Ctrl shortcuts on HOLD ---------------------------------
        case CNTL_X:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_X));  // HOLD: Ctrl+X
                return false;
            }
            return true;              // TAP: let KC_X pass
        case CNTL_C:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_C));
                return false;
            }
            return true;
        case CNTL_V:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_V));
                return false;
            }
            return true;
        case CNTL_A:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_A));
                return false;
            }
            return true;
        case CNTL_S:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_S));
                return false;
            }
            return true;
        case CNTL_Z:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_Z));
                return false;
            }
            return true;

        // ----- String macros on HOLD ----------------------------------
        case BETTES:
            if (!record->tap.count && record->event.pressed) {
                SEND_STRING("bettebrp");
                return false;
            }
            return true;
        case D_2020:
            if (!record->tap.count && record->event.pressed) {
                SEND_STRING("Diane..2020");
                return false;
            }
            return true;
        case D_6449:
            if (!record->tap.count && record->event.pressed) {
                SEND_STRING("Diane..6449");
                return false;
            }
            return true;
        case D_2890:
            if (!record->tap.count && record->event.pressed) {
                SEND_STRING("Diane..2890");
                return false;
            }
            return true;
    }

    return true; // if not one of our special keys
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CNTL_X: case CNTL_C: case CNTL_V:
        case CNTL_A: case CNTL_S: case CNTL_Z:
        case BETTES: case D_2020: case D_6449: case D_2890:
        case SFT_CAP:
            return TAPPING_TERM + 200;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_CAP:
            return true;   // hold wins if another key is pressed
        default:
            return false;
    }
}

// ======== Userspace lighting (layer + caps) =============================

static bool bf_caps_on = false;

// Color policy (tweak HSV to taste)
#define BF_HSV_BASE  HSV_CYAN
#define BF_HSV_FN    HSV_GREEN
#define BF_HSV_CAPS  HSV_RED

// Layer IDs (keymap can override by defining non-weak versions)
__attribute__((weak)) uint8_t bf_get_base_layer(void) { return 0; }  // default layer 0
__attribute__((weak)) uint8_t bf_get_fn_layer(void)   { return 1; }  // default layer 1

// Backend-agnostic “set color (no EEPROM)”
static inline void bf_set_hsv(uint8_t h, uint8_t s, uint8_t v) {
#if defined(RGB_MATRIX_ENABLE)
    rgb_matrix_sethsv(h, s, v);
#elif defined(RGBLIGHT_ENABLE)
    rgblight_sethsv_noeeprom(h, s, v);
#else
    (void)h; (void)s; (void)v;
#endif
}

static void bf_apply_layer_color(uint8_t layer) {
    if (bf_caps_on) return;                  // caps overrides layer color
    if (layer == bf_get_fn_layer()) {
        bf_set_hsv(BF_HSV_FN);               // <-- was .h/.s/.v
    } else {
        bf_set_hsv(BF_HSV_BASE);             // <-- was .h/.s/.v
    }
}

static void bf_apply_caps_color(bool caps_on) {
    bf_caps_on = caps_on;
    if (bf_caps_on) {
        bf_set_hsv(BF_HSV_CAPS);             // <-- was .h/.s/.v
    } else {
        bf_apply_layer_color(get_highest_layer(layer_state));
    }
}

// QMK hook: layer changed → apply policy
layer_state_t layer_state_set_user(layer_state_t state) {
    bf_apply_layer_color(get_highest_layer(state));
    return state;
}

// QMK hook: LED state changed (e.g., Caps) → apply policy
bool led_update_user(led_t led_state) {
    bf_apply_caps_color(led_state.caps_lock);
    return true;                                // allow the USB LED report
}

// Provide a userspace-level process_record_user so every keymap gets it.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!blackfeather_process_record(keycode, record)) { return false; }
    return true;
}
