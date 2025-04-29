# DROP CTRL Keyboard RallyRabbit Driver

This is the keymap and other items tied to the RallyRabbit customizations for the Massdrop CTRL

## Main Features

I really like the Drop CTRL keyboard, but I really dislike the Drop CTRL driver for it and feel like Drop really strayed from the benefits of QMK.  My goal was to take the Drop CTRL driver and make it much more standard to QMK.  My features include.

Features that are complete:
* Standard Windows and Mac OS X QWERTY keyboard layouts
* Added most of the standard QMK RGB Matrix Patterns.
* Added Rainbow Diaganol which is a small tweak of Cool Diaganol of HorrorTroll
* Added Flower Blooming of HorrorTroll
* Added Deep River (unchangeable blue with green saturation that moves)
* Added Deep River Reverse (unchangeable green with blue saturation that moves)
* Added Hella Rally Rabbit Theme (unchangeable blue with green saturation that moves)
* Added Hella Rally Rabbit Reverse (unchangeable green with blue saturation that moves)
* Added 30 minutes keybaord timeout inactivity to diable the RGB matrix
* Added a Windows Keyboard Layout (default) with bottom row as CTRL WIN ALT SPACE ALT FN MENU CTRL
* Added hotkey FN-W to set windows keyboard mode
* Added a Mac OS X Keybaord Layout with bottom row as CTRL OPT CMD SPACE CMD FN OPT CTRL
* Added hotkey FN-M to set windows keybaord mode
* Added FN-Z to toggle RGB Modes
* Added FN-X to toggle RGB timeout mode
* Added funciton key layout that cancels RGB Matrix and loads keymap (see function key layout)
* Added Keypad as FN-0 to FN-9 with keypad -/ and +* keys
* Added Audio controls and sound mute to FN hotkeys
* Added Sound volume to FN-Page Up and FN-Page Down
* Added Boot Loader hotkey as FN-F1
* Added FN-ESC for Windows and Mac sleep modes
* Added Spanish accent letters to FN-A, FN-E, FN-I, FN-O, FN-U (Á, É, Í, Ó, Ú)
* Added Spanish N with Tilda to FN-N
* Added British/Nordic AE to FN-S (Æ)
* Special characters work as Windows unicode, Windows Alt-Code, and Mac Special Sequence output
* Full RGB controls (see layout)
* Num Lock on the FN-` key
* Caps Word with Shift Double Tap, or Left/Right Shift at same time. Times out in 5 Seconds.

## Things Incomplete

Items that I still want to add to the driver:
* Special LED sequence when caps lock is pressed on caps lock key
* Special LED sequence when scroll lock is pressed on scroll lock key
* Figuring out why LED on Z key is not the correct color
* Matrix RGB Effect

## RGB Matrix Effects Included

Standard QMK RGB Matrix Effects Included

* RGB_MATRIX_ALPHAS_MODS - Static dual hue, speed is hue for secondary hue
* RGB_MATRIX_GRADIENT_UP_DOWN - Static gradient top to bottom, speed controls how much gradient changes
* RGB_MATRIX_GRADIENT_LEFT_RIGHT - Static gradient left to right, speed controls how much gradient changes
* RGB_MATRIX_BREATHING - Single hue brightness cycling animation
* RGB_MATRIX_BAND_SAT - Single hue band fading saturation scrolling left to right
* RGB_MATRIX_BAND_VAL - Single hue band fading brightness scrolling left to right
* RGB_MATRIX_BAND_SPIRAL_SAT - Single hue spinning spiral fades saturation
* RGB_MATRIX_BAND_SPIRAL_VAL - Single hue spinning spiral fades brightness
* RGB_MATRIX_CYCLE_ALL - Full keyboard solid hue cycling through full gradient
* RGB_MATRIX_CYCLE_LEFT_RIGHT - Full gradient scrolling left to right
* RGB_MATRIX_CYCLE_UP_DOWN - Full gradient scrolling top to bottom
* RGB_MATRIX_RAINBOW_MOVING_CHEVRON - Full gradient Chevron shapped scrolling left to right
* RGB_MATRIX_CYCLE_OUT_IN - Full gradient scrolling out to in
* RGB_MATRIX_CYCLE_OUT_IN_DUAL - Full dual gradients scrolling out to in
* RGB_MATRIX_CYCLE_SPIRAL - Full gradient spinning spiral around center of keyboard
* RGB_MATRIX_RAINDROPS - Randomly changes a single key's hue
* RGB_MATRIX_JELLYBEAN_RAINDROPS - Randomly changes a single key's hue and saturation
* RGB_MATRIX_HUE_BREATHING - Hue shifts up a slight ammount at the same time, then shifts back
* RGB_MATRIX_PIXEL_RAIN - Randomly light keys with random hues
* RGB_MATRIX_PIXEL_FLOW - Pulsing RGB flow along LED wiring with random hues
* RGB_MATRIX_PIXEL_FRACTAL - Single hue fractal filled keys pulsing horizontally out to edges
* RGB_MATRIX_DIGITAL_RAIN - That famous computer simulation
* RGB_MATRIX_SOLID_REACTIVE_SIMPLE - Pulses keys hit to hue & value then fades value out
* RGB_MATRIX_SPLASH - Full gradient & value pulse away from a single key hit then fades value out
* RGB_MATRIX_MULTISPLASH - Full gradient & value pulse away from multiple key hits then fades value out
* RGB_MATRIX_SOLID_SPLASH - Hue & value pulse away from a single key hit then fades value out

### Special to Rally Rabbit Driver

Special RGB Effects added to my driver that are not normal parts of QMK.

* FLOWER_BLOOMING - Flower Blooming of HorrorTroll
* RAINBOW_DIAGONAL - Small tweak of Cool Diaganol of HorrorTroll
* BAND_SAT_DEEP_RIVER - Deep River Lacrosse Blue with Neon Green Field Scroll
* BAND_SAT_DEEP_RIVER_REVERSE - Deep River Lacrosse Neon Green with Blue Field Scroll
* RALLYRABBIT_CYLON - Cylon effect on first three rows inspired by Battlestar Galactica 
* BAND_SAT_RALLYRABBIT_HELLA - Hella Rally Rabbit Blue with Yellow Field Scroll
* BAND_SAT_RALLYRABBIT_HELLA_REVERSE - Hella Rally Rabbit Yellow with Blue Field Scroll

## To Use

Follow the QMK directions isntalling QMK MSYS.
* Download the QMK firmware (this repository)
* config.h in the current directory is used to add to the massdrop/ctrl/config.h or remove things added in that file as it is included after that file.
* rules.mk is used in addition to the massdrop/ctrl/rules.mk and is used to add to or turn off items in the standard rules.mk file
* Build with "qmk compile -kb massdrop/ctrl -km rallyrabbit"

## Layers

### Windows Typing Layer

![Image](https://i.imgur.com/RS2nLDM.png)

### Mac OS X Typing Layer

![Image](https://i.imgur.com/SNfU9fI.png)

### "Function" Layer

![Image](https://i.imgur.com/KCZKmJT.png)


