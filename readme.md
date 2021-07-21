# SonBrooks Macropad 
This work in progress macropad is a simple macropad with 5 hot-swappable keys(with RGB of course), a rotary encoder, and an 128x32 OLED display. This firmware contains the following coded layers:
* Layer Select
* Application Launch Layer
* RGB Show Layer
* Discord Control Layer (WIP)
* Programming Layer

![SonBrooks Macropad](macropad_img.JPG "SB")

This is built on a custom PCB ran by an Arduino Pro Micro.


5 Keys, 1 Rotary Encoder, an OLED, and a Pro Micro is all you need!

* Keyboard Maintainer: [Andrew Budziszek](https://github.com/SonnyBrooks)
* Hardware Supported: Pro Micro (ATMEGA32U4)
* Hardware Availability: All hardware can be found on Amazon.

Make example for this keyboard (after setting up your build environment):

    make sb_macro:default

Flashing example for this keyboard:

    make sb_macro:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
