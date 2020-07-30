# Keymap for xd75 from thetien2k2
Modified full layout, F-key layer, numpad and function layer. Uses backlight, RGB underglow, and tap or hold layer switching keys.

## ISP pinout
from top to bottom
GND, RST, B2(SCK), B1(MOSI), VCC, B3(MISO)

## ISP command
avrdude -p atmega32u4 -c stk500v1 -b 19200 -U flash:w:"bootloader_atmega32u4_1_0_0.hex":i -P /dev/cu.usbmodem141301 -U efuse:w:0xC3:m -U hfuse:w:0xD9:m -U lock:w:0x3F:m

## Refences
https://www.reddit.com/r/olkb/comments/9ctx37/qmk_burn_dfu_bootloader_into_keyboard_with/
https://github.com/colinta/Mechy
https://beta.docs.qmk.fm/for-makers-and-modders/isp_flashing_guide