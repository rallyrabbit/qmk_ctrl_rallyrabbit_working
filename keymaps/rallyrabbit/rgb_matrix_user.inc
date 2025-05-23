/*
   Copyright 2023 @rallyrabbit <https://github.com/rallyrabbit>
   All code except for "Flower Blooming" animation
   SPDX-License-Identifier: GPL-2.0-or-later

   Flower Blooming Animation
   Copyright 2022 HorrorTroll <https://github.com/HorrorTroll>
   SPDX-License-Identifier: GPL-2.0-or-later
*/
 
// !!! DO NOT ADD #pragma once !!!

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)

RGB_MATRIX_EFFECT(FLOWER_BLOOMING)
RGB_MATRIX_EFFECT(RAINBOW_DIAGONAL)
RGB_MATRIX_EFFECT(BAND_SAT_DEEP_RIVER)
RGB_MATRIX_EFFECT(BAND_SAT_DEEP_RIVER_REVERSE)
RGB_MATRIX_EFFECT(RALLY_RABBIT_CYLON)
RGB_MATRIX_EFFECT(BAND_SAT_RALLYRABBIT_HELLA)
RGB_MATRIX_EFFECT(BAND_SAT_RALLYRABBIT_HELLA_REVERSE)
RGB_MATRIX_EFFECT(RALLY_RABBIT_MATRIX_RAIDROPS)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

/*
 * DEEP RIVER CYCLON - Green and Blue mimicing BSG Cylon Robot Eye
 */

// Support function for CYLON Animation
uint8_t g_isBackward = false;
static uint8_t time_to_led(uint8_t time, uint8_t ledBehind, uint8_t ledCount)
{
    uint16_t ledTime = ledCount * time;
    uint16_t step = ((2 * ledCount + (ledTime / 128)) - ledBehind) % (2 * ledCount);
    uint8_t led;

    if (step < ledCount)
    {
        led = step;
        g_isBackward = false;
    }
    else
    {
        led = ledCount - 1 - (step - ledCount);
        g_isBackward = true;
    }

    return led;
}

static HSV RALLY_RABBIT_CYLON_math(HSV hsv, uint8_t i, uint8_t time)
{
    // Row 1 (Escape/Functions to Pause)
    // Row 2 (Number row to page up)
    // Row 3 (First row of letters to Page Down
    uint8_t ledFirst[3] = {   0,  16,  33 }; // LED Number of first LED on the row (row1, row2, row3)
    uint8_t ledCount[3] = {  16,  17,  17 }; // LEDs on the row (row1, row2, row3)
    uint8_t hsv_h[3]    = {  20,   0,  20 }; // HSV.h value override for each LED on each row (row1, row2, row3)

    // Row 1/3: Base Color as Orange
    // Row 2: Base Color as Red
    // The Red and Orange Color Targeting Share some of the HSV Hue and Value settings
    hsv.s = 255;
    hsv.v = 255;

    bool effectLedFound = false;

    // Traverse the possible LED Matches by desired positions in rows
    for (uint8_t row=0; row < 3; row++)
    {
        if ((i >= ledFirst[row]) && (i < ledFirst[row] + ledCount[row]))
        {
            uint8_t j = i - ledFirst[row];

            if (row == 1)
            {
                if (j == time_to_led(time, 0, ledCount[row]))
                {
    
                    hsv.h = hsv_h[row];
                    hsv.v = hsv.v;
                    effectLedFound = true;
                    break;
                }
                else if (j == time_to_led(time, 1, ledCount[row]))
                {
                    hsv.h = hsv_h[row];
                    hsv.v = hsv.v;
                    effectLedFound = true;
                    break;
                }
                else if (j == time_to_led(time, 2, ledCount[row]))
                {
                    hsv.h = hsv_h[row];
                    hsv.v = hsv.v / 2;
                    effectLedFound = true;
                    break;
                }
                else if (j == time_to_led(time, 3, ledCount[row]))
                {
                    hsv.h = hsv_h[row];
                    hsv.v = hsv.v / 4;
                    effectLedFound = true;
                    break;
                }
                else if (j == time_to_led(time, 4, ledCount[row]))
                {
                    hsv.h = hsv_h[row];
                    hsv.v = hsv.v / 8;
                    effectLedFound = true;
                    break;
                }
                else
                {
                    // Position not on, turn off (Black)
                    hsv.v = 0;
                    effectLedFound = true;
                    break;
                }    
            }
            else // if ((row == 0) || (row == 2))
            {
                if (g_isBackward == false)
                {
                    if (j == time_to_led(time, 1, ledCount[row]))
                    {
        
                        hsv.h = hsv_h[row];
                        hsv.v = hsv.v;
                        effectLedFound = true;
                        break;
                    }
                    else if (j == time_to_led(time, 2, ledCount[row]))
                    {
                        hsv.h = hsv_h[row];
                        hsv.v = hsv.v / 2;
                        effectLedFound = true;
                        break;
                    }
                    else if (j == time_to_led(time, 3, ledCount[row]))
                    {
                        hsv.h = hsv_h[row];
                        hsv.v = hsv.v / 4;
                        effectLedFound = true;
                        break;
                    }
                    else if (j == time_to_led(time, 4, ledCount[row]))
                    {
                        hsv.h = hsv_h[row];
                        hsv.v = hsv.v / 8;
                        effectLedFound = true;
                        break;
                    }
                    else
                    {
                        // Position not on, turn off (Black)
                        hsv.v = 0;
                        effectLedFound = true;
                        break;
                    }    
                }
                else
                {
                    if (j == time_to_led(time, 0, ledCount[row]))
                    {
        
                        hsv.h = hsv_h[row];
                        hsv.v = hsv.v;
                        effectLedFound = true;
                        break;
                    }
                    else if (j == time_to_led(time, 1, ledCount[row]))
                    {
                        hsv.h = hsv_h[row];
                        hsv.v = hsv.v / 2;
                        effectLedFound = true;
                        break;
                    }
                    else if (j == time_to_led(time, 2, ledCount[row]))
                    {
                        hsv.h = hsv_h[row];
                        hsv.v = hsv.v / 4;
                        effectLedFound = true;
                        break;
                    }
                    else if (j == time_to_led(time, 3, ledCount[row]))
                    {
                        hsv.h = hsv_h[row];
                        hsv.v = hsv.v / 8;
                        effectLedFound = true;
                        break;
                    }
                    else
                    {
                        // Position not on, turn off (Black)
                        hsv.v = 0;
                        effectLedFound = true;
                        break;
                    }    
                }
            }
        }
    }

    // No Match Found
    if (effectLedFound == false)
    {
        // Off (Black)
        hsv.v = 0;
    }

    return hsv;
}

bool RALLY_RABBIT_CYLON(effect_params_t* params)
{
    return effect_runner_i(params, &RALLY_RABBIT_CYLON_math);
}

/*
 * Blooming Flower was taken from HorrorTroll
 */
#include "flower_blooming.h"

static HSV FLOWER_BLOOMING_math(HSV hsv, uint8_t i, uint8_t time)
{
    if (g_led_config.point[i].y > k_rgb_matrix_center.y)
    {
        hsv.h = g_led_config.point[i].x * 3 - g_led_config.point[i].y * 3 + time;
    }
    else
    {
        hsv.h = g_led_config.point[i].x * 3 - g_led_config.point[i].y * 3 - time;
    }

    return hsv;
}

bool FLOWER_BLOOMING(effect_params_t* params)
{
    return effect_runner_bloom(params, &FLOWER_BLOOMING_math);
}

/*
 * RAINBOW_DIAGONOL is a variation on COOL_DIAGONAL also from HorrorTroll 
 */
static HSV RAINBOW_DIAGONAL_math(HSV hsv, uint8_t i, uint8_t time)
{
    hsv.h = (g_led_config.point[i].x / 4) - g_led_config.point[i].y - time;
    return hsv;
}

bool RAINBOW_DIAGONAL(effect_params_t* params)
{
    return effect_runner_i(params, &RAINBOW_DIAGONAL_math);
}

/*
 * RGB Matrix BAND SAT/VAL
 * Static Yellow rotation on Blue - Hella
 * Static Green rotation on Blue - Deep River
 */
static HSV BAND_SAT_dr_hella_math(HSV hsv, uint8_t i, uint8_t time)
{
    extern bool g_isEffectDR;
    int16_t v = hsv.v - abs(scale8(g_led_config.point[i].x, 228) + 28 - time) * 8;
 
    // When value is 0, then override from black to desired backgroun color
    if (v <= 0)
    {
        // When algorithm would normally set up black (v == 0), let's go back to HSV_BLUE
        hsv.s = 255;
        hsv.v = 255;
        hsv.h = 170;
    }
    else
    {
        if (g_isEffectDR == false)
        {
            // Gradient of Green (HSV_YELLOW) when it isn't blue (HSV_BLUE)
            hsv.s = 255;
            hsv.v = scale8(v < 0 ? 0 : v, hsv.v);
            hsv.h = 45;
        }
        else
        {
            // Gradient of Green (HSV_GREEN) when it isn't blue (HSV_BLUE)
            hsv.s = 255;
            hsv.v = scale8(v < 0 ? 0 : v, hsv.v);
            hsv.h = 85;
        }
    }

    return hsv;
}

bool BAND_SAT_DEEP_RIVER(effect_params_t *params)
{
    extern bool g_isEffectDR;

    g_isEffectDR = true;
    return effect_runner_i(params, &BAND_SAT_dr_hella_math);
}

bool BAND_SAT_RALLYRABBIT_HELLA(effect_params_t *params)
{
    extern bool g_isEffectDR;

    g_isEffectDR = false;
    return effect_runner_i(params, &BAND_SAT_dr_hella_math);
}

/*
 * RGB Matrix BAND SAT/VAL
 * Static Blue rotation on Yellow - Hella
 * Static Blue roration on Green - Deep River
 */
static HSV BAND_SAT_hella_dr_reverse_math(HSV hsv, uint8_t i, uint8_t time)
{
    extern bool g_isEffectDR;
    int16_t v = hsv.v - abs(scale8(g_led_config.point[i].x, 228) + 28 - time) * 8;
 
    // When value is 0, then override from black to desired backgroun color
    if (v <= 0)
    {
        if (g_isEffectDR == false)
        {
            // When algorithm would normally set up black (v == 0), let's go back to HSV_YELLOW
            hsv.s = 255;
            hsv.v = 255;
            hsv.h = 43;
        }
        else
        {
            // When algorithm would normally set up black (v == 0), let's go back to HSV_GREEN
            hsv.s = 255;
            hsv.v = 255;
            hsv.h = 85;
        }
    }
    else 
    {
        // Gradient of Blue (HSV_BLUE) when it isn't green (HSV_YELLOW)
        hsv.s = 255;
        hsv.v = scale8(v < 0 ? 0 : v, hsv.v);
        hsv.h = 170;
    }

    return hsv;
 }

bool BAND_SAT_DEEP_RIVER_REVERSE(effect_params_t *params)
{
    extern bool g_isEffectDR;

    g_isEffectDR = true;
    return effect_runner_i(params, &BAND_SAT_hella_dr_reverse_math);
}

bool BAND_SAT_RALLYRABBIT_HELLA_REVERSE(effect_params_t *params)
{
    extern bool g_isEffectDR;

    g_isEffectDR = false;
    return effect_runner_i(params, &BAND_SAT_hella_dr_reverse_math);
}

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#define RGB_DIGITAL_RAIN_DROPS 24
bool RALLY_RABBIT_MATRIX_RAIDROPS(effect_params_t* params) {
    // algorithm ported from https://github.com/tremby/Kaleidoscope-LEDEffect-DigitalRain
    const uint8_t drop_ticks           = 28;
    const uint8_t pure_green_intensity = (((uint16_t)rgb_matrix_config.hsv.v) * 3) >> 2;
 //    const uint8_t max_brightness_boost = (((uint16_t)rgb_matrix_config.hsv.v) * 3) >> 2;
    const uint8_t max_intensity        = rgb_matrix_config.hsv.v;
    const uint8_t decay_ticks          = 0xff / max_intensity;

    static uint8_t rrDrop  = 0;
    static uint8_t rrDecay = 0;

    if (params->init)
    {
        rgb_matrix_set_color_all(0, 0, 0);
        memset(g_rgb_frame_buffer, 0, sizeof(g_rgb_frame_buffer));
        rrDrop = 0;
    }

    rrDecay++;
    for (uint8_t col = 0; col < MATRIX_COLS; col++)
    {
        for (uint8_t row = 0; row < MATRIX_ROWS; row++)
        {
            if (row == 0 && rrDrop == 0 && rand() < RAND_MAX / RGB_DIGITAL_RAIN_DROPS)
            {
                // top row, pixels have just fallen and we're
                // making a new rain drop in this column
                g_rgb_frame_buffer[row][col] = max_intensity;
            }
            else if ((g_rgb_frame_buffer[row][col] > 0) && (g_rgb_frame_buffer[row][col] < max_intensity))
            {
                // neither fully bright nor dark, decay it
                if (rrDecay == decay_ticks)
                {
                    g_rgb_frame_buffer[row][col]--;
                }
            }
            // set the pixel colour
            uint8_t led[LED_HITS_TO_REMEMBER];
            uint8_t led_count = rgb_matrix_map_row_column_to_led(row, col, led);

            // TODO: multiple leds are supported mapped to the same row/column
            if (led_count > 0)
            {
                if (g_rgb_frame_buffer[row][col] > pure_green_intensity)
                {
//                    const uint8_t boost = (uint8_t)((uint16_t)max_brightness_boost * (g_rgb_frame_buffer[row][col] - pure_green_intensity) / (max_intensity - pure_green_intensity));
//                    rgb_matrix_set_color(led[0], boost, max_intensity, boost);
                }
                else
                {
                    // clears back to blank
                    const uint8_t green = (uint8_t)((uint16_t)max_intensity * g_rgb_frame_buffer[row][col] / pure_green_intensity);
                    rgb_matrix_set_color(led[0], 0, green, 0);
                }
            }
        }
    }

    if (rrDecay == decay_ticks)
    {
        rrDecay = 0;
    }

    if (++rrDrop > drop_ticks)
    {
        // reset drop timer
        rrDrop = 0;

        for (uint8_t row = MATRIX_ROWS - 1; row > 0; row--)
        {
            for (uint8_t col = 0; col < MATRIX_COLS; col++)
            {
                // if ths is on the bottom row and bright allow decay
                if (row == MATRIX_ROWS - 1 && g_rgb_frame_buffer[row][col] == max_intensity)
                {
                    g_rgb_frame_buffer[row][col]--;
                }

                // check if the pixel above is bright
                if (g_rgb_frame_buffer[row - 1][col] >= max_intensity)
                {
                    // Note: can be larger than max_intensity if val was recently decreased
                    // allow old bright pixel to decay
                    g_rgb_frame_buffer[row - 1][col] = max_intensity - 1;
                    // make this pixel bright
                    g_rgb_frame_buffer[row][col] = max_intensity;
                }
            }
        }
    }

    return false;
}
#endif

#endif
