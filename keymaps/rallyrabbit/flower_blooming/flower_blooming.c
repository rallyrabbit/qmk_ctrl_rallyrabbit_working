/*
   Copyright 2022 HorrorTroll <https://github.com/HorrorTroll>
   SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "flower_blooming/flower_blooming.h"

static HSV FLOWER_BLOOMING_math(HSV hsv, uint8_t i, uint8_t time) {
    if (g_led_config.point[i].y > k_rgb_matrix_center.y)
        hsv.h = g_led_config.point[i].x * 3 - g_led_config.point[i].y * 3 + time;
    else
        hsv.h = g_led_config.point[i].x * 3 - g_led_config.point[i].y * 3 - time;
    return hsv;
}

bool FLOWER_BLOOMING(effect_params_t* params) { return effect_runner_bloom(params, &FLOWER_BLOOMING_math); }
