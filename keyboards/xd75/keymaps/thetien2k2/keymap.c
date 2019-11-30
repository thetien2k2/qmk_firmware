/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Layer shorthand
#define _QW 0
#define _S0 1
#define _S1 2

// Defines the keycodes used by our macros in process_record_user
// enum custom_keycodes {
//     CDUP = SAFE_RANGE,
//     LSLA,
//     SVI
// };
uint16_t lt12_timer;
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5,                  KC_MINS, KC_GRV, KC_EQL,    KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                   KC_LBRC, KC_BSLS, KC_RBRC,  KC_Y, KC_U, KC_I, KC_O, KC_P, KC_QUOT,
    KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G,                  KC_NO, KC_DEL, KC_NO,       KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
    KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B,                  KC_NO, KC_UP, KC_NO,        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,
    KC_LCTL, KC_LGUI, KC_LALT, MO(_S0), KC_SPC, KC_SPC,     KC_LEFT, KC_DOWN, KC_RGHT,  KC_SPC, KC_SPC, MO(_S1), KC_RALT, KC_RGUI, KC_RCTL
  ),
  [_S0] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_GESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,             KC_F6, KC_F7, KC_F8,        KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_NO, KC_BSPC,
    KC_TAB, KC_F9, KC_F10, KC_F11, KC_F12, KC_F13,          KC_F14, KC_F15, KC_F16,     KC_P7, KC_P8, KC_P9, KC_PPLS, KC_NO, KC_QUOT,
    KC_CAPS, KC_NO,KC_NO, KC_NO, KC_NO, KC_NO,              KC_PSCR, KC_NO, KC_PAUS,    KC_P4, KC_P5, KC_P6, KC_NO, KC_NO, KC_ENT,
    KC_LSPO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,             KC_WH_L, KC_PGUP, KC_WH_R,  KC_P1, KC_P2, KC_P3, KC_NO, KC_NO, KC_RSPC,
    KC_LCTL, KC_LGUI, KC_LALT, _______, KC_SPC, KC_SPC,     KC_HOME, KC_PGDN, KC_END,   KC_P0, KC_P0, KC_KP_DOT, KC_RALT, KC_RGUI, KC_RCTL
  ),
  [_S1] = LAYOUT_ortho_5x15( /* FUNCTION */
    BL_TOGG, BL_BRTG, BL_DEC, BL_INC, KC_NO, KC_NO,         KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET,
    RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUD, RGB_SAD, RGB_SAI,   RGB_VAD, RGB_VAI, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_NO, KC_NO,         KC_BTN4, KC_BTN3, KC_BTN5,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_MRWD, KC_MPLY, KC_MFFD, KC_NO, KC_NO, KC_NO,         KC_BTN1, KC_MS_U, KC_BTN2,        KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_U, KC_NO,
    CG_TOGG, KC_NO, AG_TOGG, KC_NO, KC_NO, KC_NO,           KC_MS_L, KC_MS_D, KC_MS_R,        KC_NO, KC_NO, _______, KC_WH_L, KC_WH_D, KC_WH_R
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // switch (keycode) {
  //   case CDUP:
  //     if (record->event.pressed) {
  //       // SEND_STRING("cd .." SS_TAP(X_ENTER));
  //       SEND_STRING("cd ..");
  //     } else {
  //       // when keycode QMKBEST is released
  //     }
  //     break;
  //   case LSLA:
  //     if (record->event.pressed) {
  //       SEND_STRING("ls -la");
  //     } else {
  //       // when keycode QMKURL is released
  //     }
  //     break;
  //   case SVI:
  //     if (record->event.pressed) {
  //       SEND_STRING("sudo vi ");
  //     } else {
  //       // when keycode QMKURL is released
  //     }
  //     break;
  // }
  return true;
}

void matrix_init_user(void) {
    // debug_enable=true;
}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        capslock_led_on();
    } else {
        capslock_led_off();
    }
}

