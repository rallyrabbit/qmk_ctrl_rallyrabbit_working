/*
   Copyright 2023 @rallyrabbit <https://github.com/rallyrabbit>
   SPDX-License-Identifier: GPL-2.0-or-later
*/

#pragma once

#define MODS_SHIFT      (get_mods() & MOD_MASK_SHIFT)
#define MODS_CTRL       (get_mods() & MOD_MASK_CTRL)
#define MODS_ALT        (get_mods() & MOD_MASK_ALT)
#define MODS_RSHIFT     (MOD_BIT(KC_LSFT))
#define MODS_LSHIFT     (MOD_BIT(KC_RSFT))

// For Spanish Keycode Functions
//#define USE_UNICODE_ALT_LETTERS
#define USE_WINDOWS_ALT_CODES
#define USE_MAC_ALT_CODES

// RGB Matrix Animation modes. Explicitly disabled from the normal
// Massdrop Ctrl Configuration (massdrop/ctrl/config.h override)
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#undef ENABLE_RGB_MATRIX_DUAL_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#undef ENABLE_RGB_MATRIX_HUE_WAVE
#undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH