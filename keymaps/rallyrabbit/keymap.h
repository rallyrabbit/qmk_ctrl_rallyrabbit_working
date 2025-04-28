/*
   Copyright 2023 @rallyrabbit <https://github.com/rallyrabbit>
   SPDX-License-Identifier: GPL-2.0-or-later
*/

#pragma once

#include QMK_KEYBOARD_H

// Defines for the LED to Keybaord Overlay for Function Layer more readable in keypad.c
#define RED {HSV_RED}
#define CORAL {HSV_CORAL}
#define ORANGE {HSV_ORANGE}
#define GOLDEN {HSV_GOLDENROD}
#define GOLD {HSV_GOLD}
#define YELLOW {HSV_YELLOW}
#define CHART {HSV_CHARTREUSE}
#define GREEN {HSV_GREEN}
#define SPRING {HSV_SPRINGGREEN}
#define TURQ {HSV_TURQUOISE}
#define TEAL {HSV_TEAL}
#define CYAN {HSV_CYAN}
#define AZURE {HSV_AZURE}
#define BLUE {HSV_BLUE}
#define PURPLE {HSV_PURPLE}
#define MAGENT {HSV_MAGENTA}
#define PINK {HSV_PINK}

// Keyboard layers
enum ctrl_rallyrabbit_layers
{
  _WINDOWS,                // Windows main key layer
  _MACOS,                  // Mac main key layer
  _FUNCTION                // Function layer
};

// Special Key Codes for this driver
enum ctrl_keycodes {
    U_T_AUTO = SAFE_RANGE, // USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              // USB Toggle Automatic GCR control
    DBG_TOG,               // DEBUG Toggle On / Off
    DBG_MTRX,              // DEBUG Toggle Matrix Prints
    DBG_KBD,               // DEBUG Toggle Keyboard Prints
    DBG_MOU,               // DEBUG Toggle Mouse Prints
    MD_BOOT,               // Restart into bootloader after hold timeout
    KC_A_AC,               // A with acute accent
    KC_E_AC,               // E with acute accent
    KC_I_AC,               // I with acute accent
    KC_O_AC,               // O with acute accent
    KC_U_AC,               // U with acute accent
    KC_NT_C,               // N with tilda
    KC_AE_C,               // AE character
    KC_SLEEP,              // Sleep Key
    KC_WIN,                // Set to Windows Keyboard
    KC_MAC,                // Set to Macos Keyboard
    RGB_TO_TOG             // RGB Timeout toggle
};

// Special key codes for layer changes
#define SC_WIN DF(_WINDOWS)
#define SC_MAC DF(_MACOS)
#define SC_FUNC MO(_FUNCTION)

// Milliseconds in a Second
#define MS_TO_SECONDS 1000

// RGB Timeout (1800 seconds = 30 minutes)
#define DEFAULT_RGB_TIMEOUT_SECONDS 1800

