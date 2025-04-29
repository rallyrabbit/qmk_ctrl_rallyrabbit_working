/*
   Copyright 2023 @rallyrabbit <https://github.com/rallyrabbit>
   All code except for "Flower Blooming" animation
   SPDX-License-Identifier: GPL-2.0-or-later

   Flower Blooming Animation
   Copyright 2022 HorrorTroll <https://github.com/HorrorTroll>
   SPDX-License-Identifier: GPL-2.0-or-later
*/
 
/* !!! DO NOT ADD #pragma once !!! */

/* Step 1. */
/* Declare custom effects using the RGB_MATRIX_EFFECT macro */
/* (note the lack of semicolon after the macro!) */

RGB_MATRIX_EFFECT(FLOWER_BLOOMING)
RGB_MATRIX_EFFECT(RAINBOW_DIAGONAL)
RGB_MATRIX_EFFECT(BAND_SAT_DEEP_RIVER)
RGB_MATRIX_EFFECT(BAND_SAT_DEEP_RIVER_REVERSE)
RGB_MATRIX_EFFECT(RALLY_RABBIT_CYLON)
RGB_MATRIX_EFFECT(BAND_SAT_RALLYRABBIT_HELLA)
RGB_MATRIX_EFFECT(BAND_SAT_RALLYRABBIT_HELLA_REVERSE)

/* Step 2. */
/* Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block */
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

/*
 * DEEP RIVER CYCLON - Green and Blue mimicing BSG Cylon Robot Eye
 */

/* Support function for CYLON Animation */
static uint8_t time_to_led(uint8_t time, uint8_t ledBehind, uint8_t ledCount)
{
    uint16_t ledTime = ledCount * time;
    uint16_t step = ((2 * ledCount + (ledTime / 128)) - ledBehind) % (2 * ledCount);
    uint8_t led;

    if (step < ledCount)
    {
        led = step;
    }
    else
    {
        led = ledCount - 1 - (step - ledCount);
    }

    return led;
}

static HSV RALLY_RABBIT_CYLON_math(HSV hsv, uint8_t i, uint8_t time)
{
    /* Row 1 (Escape/Functions to Pause) */
    /* Row 2 (Number row to page up) */
    /* Row 3 (First row of letters to Page Down */
    uint8_t ledFirst[3] = {   0,  16,  33 };
    uint8_t ledCount[3] = {  16,  17,  17 };
    uint8_t hsv_h[3]    = { 191,  0,  191 };

    /* Row 1/3: Base Color as Purple */
    /* Row 2: Base Color as Red */
    /* The Red and Purple Color Targeting Share some of the HSV Hue and Value settings */
    hsv.s = 255;
    hsv.v = 255;

    bool effectLedFound = false;

    /* Traverse the possible LED Matches by desired positions in rows */
    for (uint8_t row=0; row < 3; row++)
    {
        if (i >= ledFirst[row] && i < ledFirst[row] + ledCount[row])
        {
            uint8_t j = i - ledFirst[row];

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
                /* Position not on, turn off (Black) */
                hsv.v = 0;
                effectLedFound = true;
                break;
            }
        }
    }

    /* No Match Found */
    if (effectLedFound == false)
    {
        /* Off (Black) */
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
 
    /* When value is 0, then override from black to desired backgroun color */
    if (v <= 0)
    {
        /* When algorithm would normally set up black (v == 0), let's go back to HSV_BLUE */
        hsv.s = 255;
        hsv.v = 255;
        hsv.h = 170;
    }
    else
    {
        if (g_isEffectDR == false)
        {
            /* Gradient of Green (HSV_YELLOW) when it isn't blue (HSV_BLUE) */
            hsv.s = 255;
            hsv.v = scale8(v < 0 ? 0 : v, hsv.v);
            hsv.h = 45;
        }
        else
        {
            /* Gradient of Green (HSV_GREEN) when it isn't blue (HSV_BLUE) */
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
 
    /* When value is 0, then override from black to desired backgroun color */
    if (v <= 0)
    {
        if (g_isEffectDR == false)
        {
            /* When algorithm would normally set up black (v == 0), let's go back to HSV_YELLOW */
            hsv.s = 255;
            hsv.v = 255;
            hsv.h = 43;
        }
        else
        {
            /* When algorithm would normally set up black (v == 0), let's go back to HSV_GREEN */
            hsv.s = 255;
            hsv.v = 255;
            hsv.h = 85;
        }
    }
    else 
    {
        /* Gradient of Blue (HSV_BLUE) when it isn't green (HSV_YELLOW) */
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

#endif
