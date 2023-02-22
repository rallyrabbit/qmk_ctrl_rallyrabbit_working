/*
   Copyright 2023 @rallyrabbit <https://github.com/rallyrabbit>
   SPDX-License-Identifier: GPL-2.0-or-later
*/

#include QMK_KEYBOARD_H

enum ctrl_keycodes {
    U_T_AUTO = SAFE_RANGE, /* USB Extra Port Toggle Auto Detect / Always Active */
    U_T_AGCR,              /* USB Toggle Automatic GCR control */
    DBG_TOG,               /* DEBUG Toggle On / Off */
    DBG_MTRX,              /* DEBUG Toggle Matrix Prints */
    DBG_KBD,               /* DEBUG Toggle Keyboard Prints */
    DBG_MOU,               /* DEBUG Toggle Mouse Prints */
    MD_BOOT,               /* Restart into bootloader after hold timeout */
    KC_A_AC,               /* A with acute accent */
    KC_E_AC,               /* E with acute accent */
    KC_I_AC,               /* I with acute accent */
    KC_O_AC,               /* O with acute accent */
    KC_U_AC,               /* U with acute accent */
    KC_NT_C,               /* N with tilda */
    KC_AE_C,               /* AE character */
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SCRL, KC_PAUS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                              KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(1),   KC_APP,  KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        KC_ESC,  MD_BOOT, NK_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            KC_MUTE, _______, _______,
        KC_NUM,  KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, _______, _______, _______,   KC_MPLY, KC_MSTP, KC_VOLU,
        _______, _______, _______, KC_E_AC, RGB_SPI, RGB_VAI, RGB_SAI, KC_U_AC, KC_I_AC, KC_O_AC, _______,U_T_AUTO,U_T_AGCR, _______,   KC_MPRV, KC_MNXT, KC_VOLD,
        _______, KC_A_AC, KC_AE_C, _______, RGB_SPD, RGB_VAD, RGB_SAD, _______, _______, _______, _______, _______, KC_ENT,
        KC_LSFT, RGB_TOG, _______, _______, _______, _______, KC_NT_C, _______, _______, _______, _______, KC_RSFT,                              RGB_HUI,
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,           RGB_RMOD, RGB_HUD, RGB_MOD
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______,                              _______,
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______
    ),
    */
};

#define MODS_SHIFT      (get_mods() & MOD_MASK_SHIFT)
#define MODS_CTRL       (get_mods() & MOD_MASK_CTRL)
#define MODS_ALT        (get_mods() & MOD_MASK_ALT)
#define MODS_RSHIFT     (MOD_BIT(KC_LSFT))
#define MODS_LSHIFT     (MOD_BIT(KC_RSFT))
//#define USE_UNICODE_ALT_LETTERS
#define USE_WINDOWS_ALT_CODES

void matrix_init_user(void) {
    /* Initialize for the Windows Unicode Set for Special Characters by default */
    set_unicode_input_mode(UNICODE_MODE_WINDOWS);
}

/* Used to save the Num Lock state from the LED */
bool g_bOsNumLockOn = false;
void led_set_user(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_NUM_LOCK)) {
        g_bOsNumLockOn = true;
    } 
    else {
        g_bOsNumLockOn = false;
    }
}

void send_windows_altcode_sequence(uint16_t altcode, uint8_t shift_mask, keyrecord_t *record) {
    /* Sends the "alt code" defined in altcode parameter.
       Clears Shifts
       Sets Num Lock
       Presses Left Alt
       While using Keypad Numbers for input value
       Release Left Alt
       Turns off Num Lock

       If the Windows Alt Code needs 0250 for example, the C
       code will strip off the 0, the algorithm will stick that back in 
       for the keypresses.
    */       

    /* If this is a capital letter for alt code, temporarily turn off the shift keys because it will */
    /* interfere with the use of the alt codes */
    unregister_code(KC_LSFT);
    unregister_code(KC_RSFT);
    send_keyboard_report();
    
    /* Save the current mod state */
    static uint8_t lalt_mask;
    lalt_mask = keyboard_report->mods & KC_LALT;

    /* Save the Num Lock state prior to sending windows Num Lock with key codes */
    bool bNumLockWasOn = g_bOsNumLockOn;
    
    /* Separate the altcode input into an array of the 4 numbers */
    static uint16_t altcodekeypress[4];
    for (int8_t i = 3; i >= 0; i--) {
        altcodekeypress[i] = altcode % 10;
        altcode = altcode / 10;
    }

    /* Convert each number from alt code array into key codes on numeric keypay */
    for (uint8_t i=0; i <= 3; i++) {
        switch(altcodekeypress[i]) {
            case 0:
                altcodekeypress[i] = KC_KP_0;
                break;

            case 1:
                altcodekeypress[i] = KC_KP_1;
                break;

            case 2:
                altcodekeypress[i] = KC_KP_2;
                break;

            case 3:
                altcodekeypress[i] = KC_KP_3;
                break;

            case 4:
                altcodekeypress[i] = KC_KP_4;
                break;

            case 5:
                altcodekeypress[i] = KC_KP_5;
                break;

            case 6:
                altcodekeypress[i] = KC_KP_6;
                break;

            case 7:
                altcodekeypress[i] = KC_KP_7;
                break;

            case 8:
                altcodekeypress[i] = KC_KP_8;
                break;

            case 9:
                altcodekeypress[i] = KC_KP_9;
                break;
        }
    }

    /* Force Send a Left Alt Keypress if not currently being pressed */
    if (!lalt_mask) {
        register_code(KC_LALT);
        send_keyboard_report();
    }
    
    /* Force send Num Lock Keypress if Num Lock is not currently ON */
    if (!bNumLockWasOn) {
        register_code(KC_LNUM);
        send_keyboard_report();
    }
    
    /* Send Each Keypress In Order */
    for (uint8_t i=0; i <= 3; i++) {
        add_key(altcodekeypress[i]);
        send_keyboard_report();
        del_key(altcodekeypress[i]);
        send_keyboard_report();
    }
    
    /* Force Release a Left Alt Keypress if not originally being pressed */
    if (!lalt_mask) {
        unregister_code(KC_LALT);
        send_keyboard_report();
    }
    
    /* Force send Num Lock Keypress if Num Lock to turn off if it was not originally turned on */
    if (!bNumLockWasOn) {
        unregister_code(KC_LNUM);
        send_keyboard_report();
    }

    /* Restore Left Shift to Previous State */
    if (shift_mask & MOD_BIT(KC_LSFT)) {
        register_code(KC_LSFT);
        send_keyboard_report();
    }

    /* Restore Right Shift to Previous State */
    if (shift_mask & MOD_BIT(KC_RSFT)) {
        register_code(KC_RSFT);
        send_keyboard_report();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;
#if defined(USE_WINDOWS_ALT_CODES)
	static uint8_t shift_mask;
    shift_mask = MODS_SHIFT;
#endif

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;

        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;

        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;

        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;

        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;

        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;

        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;

        case KC_A_AC:
            /* Á or á */
            if (record->event.pressed) {
#if defined(USE_UNICODE_ALT_LETTERS)
                if (MODS_SHIFT) {
                    send_unicode_string("Á");
                } else {
                    send_unicode_string("á");
                }
#elif defined(USE_WINDOWS_ALT_CODES)
                if (shift_mask) {
    				send_windows_altcode_sequence(193, shift_mask, record);
                }
                else {
		    		send_windows_altcode_sequence(225, shift_mask, record);
                }
#endif
            }
            return false;

        case KC_E_AC:
            /* É or é */
            if (record->event.pressed) {
#if defined(USE_UNICODE_ALT_LETTERS)
                if (MODS_SHIFT) {
                    send_unicode_string("É");
                } else {
                    send_unicode_string("é");
                }
#elif defined(USE_WINDOWS_ALT_CODES)
                if (shift_mask) {
    				send_windows_altcode_sequence(201, shift_mask, record);
                }
                else {
		    		send_windows_altcode_sequence(235, shift_mask, record);
                }
#endif
            }
            return false;

        case KC_I_AC:
            /* Í or í */
            if (record->event.pressed) {
#if defined(USE_UNICODE_ALT_LETTERS)
                if (MODS_SHIFT) {
                    send_unicode_string("Í");
                } else {
                    send_unicode_string("í");
                }
#elif defined(USE_WINDOWS_ALT_CODES)
                if (shift_mask) {
    				send_windows_altcode_sequence(205, shift_mask, record);
                }
                else {
		    		send_windows_altcode_sequence(237, shift_mask, record);
                }
#endif
            }
            return false;


        case KC_O_AC:
            /* Ó or ó */
            if (record->event.pressed) {
#if defined(USE_UNICODE_ALT_LETTERS)
                if (MODS_SHIFT) {
                    send_unicode_string("Ó");
                } else {
                    send_unicode_string("ó");
                }
#elif defined(USE_WINDOWS_ALT_CODES)
                if (shift_mask) {
    				send_windows_altcode_sequence(211, shift_mask, record);
                }
                else {
		    		send_windows_altcode_sequence(243, shift_mask, record);
                }
#endif
            }
            return false;


        case KC_U_AC:
            /* Ú or ú */
            if (record->event.pressed) {
#if defined(USE_UNICODE_ALT_LETTERS)
                if (MODS_SHIFT) {
                    send_unicode_string("Ú");
                } else {
                    send_unicode_string("ú");
                }
#elif defined(USE_WINDOWS_ALT_CODES)
                if (shift_mask) {
    				send_windows_altcode_sequence(218, shift_mask, record);
                }
                else {
		    		send_windows_altcode_sequence(250, shift_mask, record);
                }
#endif
            }
            return false;

        case KC_AE_C:
            /* Æ or æ */
            if (record->event.pressed) {
#if defined(USE_UNICODE_ALT_LETTERS)
                if (MODS_SHIFT) {
                    send_unicode_string("Æ");
                } else {
                    send_unicode_string("æ");
                }
#elif defined(USE_WINDOWS_ALT_CODES)
                if (shift_mask) {
    				send_windows_altcode_sequence(198, shift_mask, record);
                }
                else {
		    		send_windows_altcode_sequence(230, shift_mask, record);
                }
#endif
            }
            return false;

        case KC_NT_C:
            /* Ñ or ñ */
            if (record->event.pressed) {
#if defined(USE_UNICODE_ALT_LETTERS)
                if (MODS_SHIFT) {
                    send_unicode_string("Ñ");
                } else {
                    send_unicode_string("ñ");
                }
#elif defined(USE_WINDOWS_ALT_CODES)
                if (shift_mask) {
    				send_windows_altcode_sequence(209, shift_mask, record);
                }
                else {
		    		send_windows_altcode_sequence(241, shift_mask, record);
                }
#endif
            }
            return false;

        case RGB_TOG:
            if (record->event.pressed) {
                switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL:
                    {
                        rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR);
                        rgb_matrix_set_color_all(0, 0, 0);
                    }
                    break;

                    case (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR):
                    {
                        rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                        rgb_matrix_set_color_all(0, 0, 0);
                    }
                    break;

                    case LED_FLAG_UNDERGLOW:
                    {
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_disable_noeeprom();
                    }
                    break;

                    default:
                    {
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                        rgb_matrix_enable_noeeprom();
                    }
                    break;
                }
            }
            return false;

        default:
            return true; /* Process all other keycodes normally */
    }
}
