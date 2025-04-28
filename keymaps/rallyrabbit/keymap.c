/*
   Copyright 2023 @rallyrabbit <https://github.com/rallyrabbit>
   SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "keymap.h"

//KC_F1
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WINDOWS] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                     KC_PSCR, KC_SCRL, KC_PAUS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,           KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,           KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                                      KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, SC_FUNC, KC_APP,  KC_RCTL,                    KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_MACOS] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                     KC_PSCR, KC_SCRL, KC_PAUS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,           KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,           KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                                      KC_UP,
        KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                             KC_RGUI, SC_FUNC, KC_LALT, KC_RCTL,                    KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_FUNCTION] = LAYOUT(
        KC_SLEEP,MD_BOOT, _______, _______, _______, _______, _______, _______, _______, KC_MPLY,KC_MSTP, KC_MPRV, KC_MNXT,                     KC_MUTE, _______, _______,
        KC_NUM,  KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, KC_KP_MINUS, KC_KP_PLUS, _______,    _______, KC_BRIU, KC_VOLU,
        _______, _______, KC_WIN,  KC_E_AC, _______, _______, _______, KC_U_AC, KC_I_AC, KC_O_AC, _______,U_T_AUTO,U_T_AGCR, _______,           _______, KC_BRID, KC_VOLD,
        _______, KC_A_AC, KC_AE_C, RGB_SPI, RGB_VAI, RGB_SAI, _______, _______, _______, _______, _______, _______, KC_ENT,
        KC_LSFT, RGB_TOG, RGB_TO_TOG, RGB_SPD, RGB_VAD, RGB_SAD, KC_NT_C, KC_MAC,  _______, _______, _______, KC_RSFT,                                       RGB_HUI,
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,                    RGB_RMOD, RGB_HUD, RGB_MOD
    ),
};

#ifdef _______
#undef _______
#endif
#define _______ {0, 0, 0}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [_FUNCTION] = {
        YELLOW,  RED,     _______, _______, _______, _______, _______, _______, _______, YELLOW, YELLOW, YELLOW, YELLOW,                        YELLOW,  _______, _______,
        BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,   _______,            _______, YELLOW,  YELLOW,
        _______, _______, YELLOW,  GREEN,   _______, _______, _______, GREEN,   GREEN,   GREEN,   _______, ORANGE,  ORANGE, _______,            _______, YELLOW,  YELLOW,
        _______, GREEN,   GREEN,   PINK,    PINK,    PINK,    _______, _______, _______, _______, _______, _______, _______,
        GREEN,   PINK,    PINK,    PINK,    PINK,    PINK,     GREEN,   YELLOW,  _______, _______, _______, GREEN,                                       PINK,
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,                    PINK,    PINK,    PINK
    },
};

#undef _______
#define _______ KC_TRNS

// External reference to the keymap config and matrix
extern keymap_config_t keymap_config;
extern rgb_config_t rgb_matrix_config;

// idleTimer = LED Timeout Timer; idleCounterSeconds=Counter in Seconds; keyEventCounter = key event counter
static uint16_t idleTimer;
static uint8_t idleCounterSeconds;
static uint8_t keyEventCounter;
static uint16_t rgbTimeoutSeconds;

// Caps and Num Lock State
static bool g_bOsNumLockOn = false;
static bool g_bOsCapsLockOn = false;

// boolean used for my Hella and Deep River Matrix Effects
bool g_isEffectDR = false;

// RGB control flags for the driver
bool disable_layer_color;
bool rgbEnabled;
bool rgbTimeoutEnabled;
led_flags_t rgbTimeoutSaveMatrixFlags;

// Runs one time at keyboard initialization
void matrix_init_user(void)
{
    // Initialize for the Windows Unicode Set for Special Characters by default
    set_unicode_input_mode(UNICODE_MODE_WINDOWS);

    // Counter in seconds: keyboard idle (no key pressed)
    idleCounterSeconds = 0;

    // Counter of Key Events Pressed
    keyEventCounter = 0;

    // RGB timeout initialized
    rgbTimeoutSeconds = DEFAULT_RGB_TIMEOUT_SECONDS;

    // RGB Timeout enable/disable
    rgbTimeoutEnabled = true;

    // RGB enable/disable
    rgbEnabled = true;

    // RGB Matrix state (to go back to after idle)
    rgbTimeoutSaveMatrixFlags = rgb_matrix_get_flags();
};

// Called after initialization
void keyboard_post_init_user(void)
{
    rgb_matrix_enable();
}

// Called from the driver run loop constantly
void matrix_scan_user(void)
{
    if ((rgbTimeoutEnabled == true) && (rgbEnabled == true))
    {
        // As long as a key is pressed (>0) then a key is pressed so do not increemnt timer
        if (keyEventCounter > 0)
        {
            idleCounterSeconds = 0;
        }
        else if (timer_elapsed(idleTimer) > MS_TO_SECONDS)
        {
            idleCounterSeconds++;
            idleTimer = timer_read();
        }

        if (idleCounterSeconds >= rgbTimeoutSeconds) {
            rgbTimeoutSaveMatrixFlags = rgb_matrix_get_flags();
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
            rgbEnabled = false;
            idleCounterSeconds = 0;
        }
    }
}

// Used to save the Num & Caps Lock state from the LED
void led_set_user(uint8_t usb_led)
{
    g_bOsNumLockOn = IS_LED_ON(usb_led, USB_LED_NUM_LOCK);
    g_bOsCapsLockOn = IS_LED_ON(usb_led, USB_LED_CAPS_LOCK);
}

#if defined(USE_MACOS_ALT_CODES)
// Handle keypresses to perform MAC OS X special keys
void send_macos_altcode_sequence(uint16_t keyCode, uint16_t overrideKeycode, uint8_t shiftMask, keyrecord_t *record)
{
    /* Sends the "alt code" defined in altcode parameter.
       Clears Shifts
       Clears caps lock
       Sends required character sequence
       Restores caps lock
    */

    /* If this is a capital letter for alt code, temporarily turn off the shift keys because it will */
    /* interfere with the use of the alt codes */
    unregister_code(KC_LSFT);
    unregister_code(KC_RSFT);
    send_keyboard_report();
    
    /* Save the CAPS Lock state prior to sending windows CAPS Lock with key codes */
    bool bCapsLockWasOn = g_bOsCapsLockOn;
       
    /* Force send CAPS Lock Keypress if CAPS Lock is ON */
    if (bCapsLockWasOn)
    {
        tap_code(KC_CAPS_LOCK);
    }

    /* Send the Alt Code */
    switch(keyCode)
    {
        case KC_A_AC:
        case KC_E_AC:
        case KC_I_AC:
        case KC_O_AC:
        case KC_U_AC:
            /* Send ALT + A/E/I/O/U */
            tap_code16(LALT(KC_E));

            /* Send key code */
            tap_code16(overrideKeycode);
            break;

        case KC_NT_C:
            /* Send ALT + N */
            tap_code16(LALT(KC_N));

            /* Send key code */
            tap_code16(overrideKeycode);
            break;

        case KC_AE_C:
            /* Send ALT + ' */
            tap_code16(LALT(KC_QUOT));
            break;

        default:
            break;
    }

    /* Force send CAPS Lock Keypress if CAPS Lock to turn on if it was originally turned on */
    if (bCapsLockWasOn)
    {
        tap_code(KC_CAPS_LOCK);
    }

    /* Restore Left Shift to Previous State */
    if (shiftMask & MOD_BIT(KC_LSFT))
    {
        register_code(KC_LSFT);
        send_keyboard_report();
    }

    /* Restore Right Shift to Previous State */
    if (shiftMask & MOD_BIT(KC_RSFT))
    {
        register_code(KC_RSFT);
        send_keyboard_report();
    }
}
#endif

#if defined(USE_WINDOWS_ALT_CODES)
// Handle keypresses to perform Windows Alt Codes special keys
void send_windows_altcode_sequence(uint16_t altCode, uint8_t shiftMask, keyrecord_t *record)
{
    /* Sends the "alt code" defined in altCode parameter.
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
    
    /* Separate the altCode input into an array of the 4 numbers */
    static uint16_t altCodekeypress[4];
    for (int8_t i = 3; i >= 0; i--)
    {
        altCodekeypress[i] = altCode % 10;
        altCode = altCode / 10;
    }

    /* Convert each number from alt code array into key codes on numeric keypay */
    for (uint8_t i=0; i <= 3; i++)
    {
        switch(altCodekeypress[i])
        {
            case 0:
                altCodekeypress[i] = KC_KP_0;
                break;

            case 1:
                altCodekeypress[i] = KC_KP_1;
                break;

            case 2:
                altCodekeypress[i] = KC_KP_2;
                break;

            case 3:
                altCodekeypress[i] = KC_KP_3;
                break;

            case 4:
                altCodekeypress[i] = KC_KP_4;
                break;

            case 5:
                altCodekeypress[i] = KC_KP_5;
                break;

            case 6:
                altCodekeypress[i] = KC_KP_6;
                break;

            case 7:
                altCodekeypress[i] = KC_KP_7;
                break;

            case 8:
                altCodekeypress[i] = KC_KP_8;
                break;

            case 9:
                altCodekeypress[i] = KC_KP_9;
                break;
        }
    }

    /* Force Send a Left Alt Keypress if not currently being pressed */
    if (!lalt_mask)
    {
        register_code(KC_LALT);
        send_keyboard_report();
    }
    
    /* Force send Num Lock Keypress if Num Lock is not currently ON */
    if (!bNumLockWasOn)
    {
        tap_code(KC_NUM_LOCK);
    }
    
    /* Send Each Keypress In Order */
    for (uint8_t i=0; i <= 3; i++)
    {
        add_key(altCodekeypress[i]);
        send_keyboard_report();
        del_key(altCodekeypress[i]);
        send_keyboard_report();
    }
    
    /* Force Release a Left Alt Keypress if not originally being pressed */
    if (!lalt_mask) {
        unregister_code(KC_LALT);
        send_keyboard_report();
    }
    
    /* Force send Num Lock Keypress if Num Lock to turn off if it was not originally turned on */
    if (!bNumLockWasOn)
    {
        tap_code(KC_NUM_LOCK);
    }

    /* Restore Left Shift to Previous State */
    if (shiftMask & MOD_BIT(KC_LSFT))
    {
        register_code(KC_LSFT);
        send_keyboard_report();
    }

    /* Restore Right Shift to Previous State */
    if (shiftMask & MOD_BIT(KC_RSFT))
    {
        register_code(KC_RSFT);
        send_keyboard_report();
    }
}
#endif

void set_layer_color(int layer)
{
    if ((layer == _WINDOWS) || (layer == _MACOS))
    { 
        return;
    }

    // Go through the Drop CTRL Maxtrix Count for every LED
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++)
    {
        HSV hsv =
        {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };

        if (hsv.h || hsv.s || hsv.v)
        {
            RGB rgb = hsv_to_rgb(hsv);
            float f = (float) rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
        else if (layer != 1)
        {
            // Only deactivate non-defined key LEDs at layers other than FN. Because at FN we have RGB adjustments and need to see them live.
            // If the values are all false then it's a transparent key and deactivate LED at this layer
            rgb_matrix_set_color(i, 0, 0, 0);
        }
    }
}

bool rgb_matrix_indicators_user(void)
{
    if (disable_layer_color || rgb_matrix_get_flags() == LED_FLAG_NONE || rgb_matrix_get_flags() == LED_FLAG_UNDERGLOW)
    {
        return true;
    }

    set_layer_color(get_highest_layer(layer_state));

    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    static uint32_t sKeyTimer;
    static bool sIsMacAsleep = false;
#if defined(USE_WINDOWS_ALT_CODES) || defined(USE_MACOS_ALT_CODES) || defined(USE_UNICODE_ALT_LETTERS)
	static uint8_t sShiftMask;
    sShiftMask = MODS_SHIFT;
#endif
    /* Default to WIndows now */
    static bool bIsWindowsKeyboard = true;

    /* If in Mac Mode, special handling for sleep mode and wakeup */
    if (bIsWindowsKeyboard == false)
    {
        if (sIsMacAsleep && record->event.pressed)
        {
            sIsMacAsleep = false;
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_enable_noeeprom();
        }    
    }

//adamo - special handling for sleep mode

    // Increment counter of key events when key is pressed, decrement when released
    if (record->event.pressed)
    {
        keyEventCounter++;
    }
    else
    {
        keyEventCounter--;
    }

    if (rgbTimeoutEnabled == true)
    {
        idleTimer = timer_read();

        // Key press clears the counters and re-enables the last used RGB mode
        idleCounterSeconds = 0;
        if (rgbEnabled == false)
        {
            rgb_matrix_enable_noeeprom();
            rgb_matrix_set_flags(rgbTimeoutSaveMatrixFlags);
            rgbEnabled = true;
        }
    }

    /* Main Key Code Handling for this keymap */
    switch (keycode)
    {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL)
            {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;

        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL)
            {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;

        case MD_BOOT:
            if (record->event.pressed)
            {
                sKeyTimer = timer_read32();
            }
            else
            {
                if (timer_elapsed32(sKeyTimer) >= 500)
                {
                    reset_keyboard();
                }
            }
            return false;

        case KC_A_AC:
            /* Á or á */
            if (record->event.pressed)
            {
                // If Macos
                if (bIsWindowsKeyboard == false)
                {
#if defined(USE_MACOS_ALT_CODES)
                    if (sShiftMask)
                    {
                        send_macos_altcode_sequence(keycode, LSFT(KC_A), sShiftMask, record);
                    }
                    else
                    {
                        send_macos_altcode_sequence(keycode, KC_A, sShiftMask, record);
                    }
#endif
                }
                else
                {
#if defined(USE_UNICODE_ALT_LETTERS)
                    if (sShiftMask)
                    {
                        send_unicode_string("Á");
                    }
                    else
                    {
                        send_unicode_string("á");
                    }
#elif defined(USE_WINDOWS_ALT_CODES)
                    if (sShiftMask)
                    {
                        send_windows_altcode_sequence(193, sShiftMask, record);
                    }
                    else
                    {
                        send_windows_altcode_sequence(225, sShiftMask, record);
                    }
#endif    
                }
            }
            return false;

        case KC_E_AC:
            /* É or é */
            if (record->event.pressed)
            {
                // If Macos
                if (bIsWindowsKeyboard == false)
                {
#if defined(USE_MACOS_ALT_CODES)
                    if (sShiftMask)
                    {
                        send_macos_altcode_sequence(keycode, LSFT(KC_E), sShiftMask, record);
                    }
                    else
                    {
                        send_macos_altcode_sequence(keycode, KC_E, sShiftMask, record);
                    }
#endif
                }
                else
                {
#if defined(USE_UNICODE_ALT_LETTERS)
                    if (sShiftMask)
                    {
                        send_unicode_string("É");
                    }
                    else
                    {
                        send_unicode_string("é");
                    }
#elif defined(USE_WINDOWS_ALT_CODES)
                    if (sShiftMask)
                    {
    				    send_windows_altcode_sequence(201, sShiftMask, record);
                    }
                    else
                    {
		    		    send_windows_altcode_sequence(235, sShiftMask, record);
                    }
#endif
                }
            }
            return false;

        case KC_I_AC:
            /* Í or í */
            if (record->event.pressed)
            {
                // If Macos
                if (bIsWindowsKeyboard == false)
                {
#if defined(USE_MACOS_ALT_CODES)
                    if (sShiftMask)
                    {
                        send_macos_altcode_sequence(keycode, LSFT(KC_I), sShiftMask, record);
                    }
                    else
                    {
                        send_macos_altcode_sequence(keycode, KC_I, sShiftMask, record);
                    }
#endif
                }
                else
                {
#if defined(USE_UNICODE_ALT_LETTERS)
                    if (sShiftMask)
                    {
                        send_unicode_string("Í");
                    }
                    else
                    {
                        send_unicode_string("í");
                    }
#elif defined(USE_WINDOWS_ALT_CODES)
                    if (sShiftMask)
                    {
        				send_windows_altcode_sequence(205, sShiftMask, record);
                    }
                    else
                    {
		    		    send_windows_altcode_sequence(237, sShiftMask, record);
                    }
#endif
                }
            }
            return false;


        case KC_O_AC:
            /* Ó or ó */
            if (record->event.pressed)
            {
                // If Macos
                if (bIsWindowsKeyboard == false)
                {
#if defined(USE_MACOS_ALT_CODES)
                    if (sShiftMask)
                    {
                        send_macos_altcode_sequence(keycode, LSFT(KC_O), sShiftMask, record);
                    }
                    else
                    {
                        send_macos_altcode_sequence(keycode, KC_O, sShiftMask, record);
                    }
#endif
                }
                else
                {
#if defined(USE_UNICODE_ALT_LETTERS)
                    if (sShiftMask)
                    {
                        send_unicode_string("Ó");
                    }
                    else
                    {
                    send_unicode_string("ó");
                    }
#elif defined(USE_WINDOWS_ALT_CODES)
                    if (sShiftMask)
                    {
    	    			send_windows_altcode_sequence(211, sShiftMask, record);
                    }
                    else
                    {
	    	    		send_windows_altcode_sequence(243, sShiftMask, record);
                    }
#endif
                }
            }
            return false;


        case KC_U_AC:
            /* Ú or ú */
            if (record->event.pressed)
            {
                // If Macos
                if (bIsWindowsKeyboard == false)
                {
#if defined(USE_MACOS_ALT_CODES)
                    if (sShiftMask)
                    {
                        send_macos_altcode_sequence(keycode, LSFT(KC_U), sShiftMask, record);
                    }
                    else
                    {
                        send_macos_altcode_sequence(keycode, KC_U, sShiftMask, record);
                    }
#endif
                }
                else
                {
#if defined(USE_UNICODE_ALT_LETTERS)
                    if (sShiftMask)
                    {
                        send_unicode_string("Ú");
                    }
                    else
                    {
                        send_unicode_string("ú");
                    }
#elif defined(USE_WINDOWS_ALT_CODES)
                    if (sShiftMask)
                    {
    	    			send_windows_altcode_sequence(218, sShiftMask, record);
                    }
                    else
                    {
		    		    send_windows_altcode_sequence(250, sShiftMask, record);
                    }
#endif
                }
            }
            return false;

        case KC_AE_C:
            /* Æ or æ */
            if (record->event.pressed)
            {
                // If Macos
                if (bIsWindowsKeyboard == false)
                {
#if defined(USE_MACOS_ALT_CODES)
                    if (sShiftMask)
                    {
                        send_macos_altcode_sequence(keycode, LSFT(KC_QUOT), sShiftMask, record);
                    }
                    else
                    {
                        send_macos_altcode_sequence(keycode, KC_QUOT, sShiftMask, record);
                    }
#endif
                }
                else
                {
#if defined(USE_UNICODE_ALT_LETTERS)
                    if (sShiftMask)
                    {
                        send_unicode_string("Æ");
                    }
                    else
                    {
                        send_unicode_string("æ");
                    }
#elif defined(USE_WINDOWS_ALT_CODES)
                    if (sShiftMask)
                    {
    				    send_windows_altcode_sequence(198, sShiftMask, record);
                    }
                    else
                    {
		        		send_windows_altcode_sequence(230, sShiftMask, record);
                    }
#endif
                }
            }
            return false;

        case KC_NT_C:
            /* Ñ or ñ */
            if (record->event.pressed)
            {
                // If Macos
                if (bIsWindowsKeyboard == false)
                {
#if defined(USE_MACOS_ALT_CODES)
                    if (sShiftMask)
                    {
                        send_macos_altcode_sequence(keycode, LSFT(KC_N), sShiftMask, record);
                    }
                    else
                    {
                        send_macos_altcode_sequence(keycode, KC_N, sShiftMask, record);
                    }
#endif
                }
                else
                {
#if defined(USE_UNICODE_ALT_LETTERS)
                    if (sShiftMask)
                    {
                        send_unicode_string("Ñ");
                    }
                    else
                    {
                        send_unicode_string("ñ");
                    }
#elif defined(USE_WINDOWS_ALT_CODES)
                    if (sShiftMask)
                    {
    	    			send_windows_altcode_sequence(209, sShiftMask, record);
                    }
                    else
                    {
		    		    send_windows_altcode_sequence(241, sShiftMask, record);
                    }
#endif
                }
            }
            return false;

        case RGB_TOG:
            if (record->event.pressed)
            {
                switch (rgb_matrix_get_flags())
                {
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
                        rgbTimeoutEnabled = false;
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                        rgb_matrix_enable_noeeprom();
                    }
                    break;
                }
            }
            return false;

        case RGB_TO_TOG:
            // Turns teh RGB timeout option on or off based on default timeout
            if (rgbTimeoutEnabled == true)
            {
                rgbTimeoutEnabled = false;
            }
            else
            {
                rgbTimeoutEnabled = true;
            }
            return false;
        
        case KC_MAC:
            bIsWindowsKeyboard = false;
            tap_code16(DF(_MACOS));
            return false;

        case KC_WIN:
            bIsWindowsKeyboard = true;
            tap_code16(DF(_WINDOWS));
            return false;

        case KC_SLEEP:
            /* If not set to Mac Mode, then ignore the sleep button */
            if (bIsWindowsKeyboard == false)
            {
                if (record->event.pressed)
                {
                    /* Command + ALT + EJECT was sporatic, used this insyead */
                    tap_code16(LCTL(LGUI(KC_Q)));
                    sIsMacAsleep = true;
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                }
                else if (IS_RELEASED(record->event))
                {
                    tap_code(KC_ESCAPE);
                }    
            }
            return false;

        case KC_KP_MINUS:
            if (sShiftMask)
            {
                /* Keypad Divide */
                tap_code16(KC_KP_SLASH);
            }
            else
            {
                /* Keypad Minus */
                tap_code16(KC_KP_MINUS);
            }
            return false;
            
        case KC_KP_PLUS:
            if (sShiftMask)
            {
                /* Keypad Multiply */
                tap_code16(KC_KP_ASTERISK);
            }
            else
            {
                /* Keypad Plus */
                tap_code16(KC_KP_PLUS);
            }
            return false;

        default:
            return true; /* Process all other keycodes normally */
    }

    return true; /* Process all other keycodes normally */
}
