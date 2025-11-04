#pragma once

// Conservative, safe defaults you can tweak later:
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY

// === RGB Matrix minimal (static color only) ===
#if defined(RGB_MATRIX_ENABLE)
// Compile ONLY this one effect:
#    define ENABLE_RGB_MATRIX_SOLID_COLOR

// (Do NOT define any other ENABLE_RGB_MATRIX_* macros.)
// When you define at least one ENABLE_RGB_MATRIX_* macro,
// QMK will include ONLY those, excluding everything else.

// Make static color the default at boot:
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR

// Optional space/power savers:
//#    define RGB_DISABLE_WHEN_USB_SUSPENDED true   // turn off when sleeping
//#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180     // cap max brightness (0–255)
#endif

// === RGBlight minimal (static color only) ===
#if defined(RGBLIGHT_ENABLE)
// Compile ONLY static light:
#    define RGBLIGHT_EFFECT_STATIC_LIGHT

// (Do NOT define any other RGBLIGHT_EFFECT_* macros.)

// Make static light the default at boot:
#    define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT

// Optional space/power savers:
//#    define RGB_DISABLE_WHEN_USB_SUSPENDED true
//#    define RGBLIGHT_LIMIT_VAL 180           // cap brightness (0–255)
#endif


