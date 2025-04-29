#
# Copyright 2023 @rallyrabbit <https://github.com/rallyrabbit>
# SPDX-License-Identifier: GPL-2.0-or-later
#

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
VIRTSER_ENABLE = no         # USB Serial Driver
RAW_ENABLE = no             # Raw device
AUTO_SHIFT_ENABLE = no      # Auto Shift
CAPS_WORD_ENABLE = yes      # Caps Word

# Custom RGB matrix handling
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = custom

# Allow Unicode for RallyRabbit Keymap
UNICODE_ENABLE = yes        # Enable Unicode Characters/Strings

#Custom RGB
RGB_MATRIX_CUSTOM_USER = yes

SRC += config_led.c

