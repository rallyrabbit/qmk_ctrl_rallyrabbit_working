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

## Things Incomplete

Items that I still want to add to the driver:
* Special LED sequence when caps lock is pressed on caps lock key
* Special LED sequence when scroll lock is pressed on scroll lock key
* Figuring out why LED on Z key is not the correct color
* Caps Word

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


