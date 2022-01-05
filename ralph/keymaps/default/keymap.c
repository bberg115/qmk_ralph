/* Copyright 2020 Matt3o
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN1,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        LCTL(LSFT(KC_M)), LCTL(LALT(KC_S)), TO(_FN1),  \
        LCTL(KC_F), LCTL(KC_Z), KC_AUDIO_MUTE,  \
        LCTL(LSFT(KC_S)), LCTL(LALT(KC_G)), LCTL(LALT(KC_D)),  \
        LCTL(KC_C), LCTL(KC_V), LCTL(KC_X)
    ),
    [_FN1] = LAYOUT(
        LCTL(LSFT(KC_M)), LCTL(LALT(KC_S)), TO(_BASE),  \
        KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK,  \
        KC_F10, KC_F11, KC_F12,  \
        KC_F7, KC_F8, KC_F9

    )
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    // INSERT CODE HERE: turn off all leds

    switch (layer) {
        case _BASE:
            // INSERT CODE HERE: turn on leds that correspond to YOUR_LAYER_1
            rgblight_enable_noeeprom(); // Enables RGB, without saving settings
            rgblight_sethsv_noeeprom(HSV_RED);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case _FN1:
            // INSERT CODE HERE: turn on leds that correspond to YOUR_LAYER_2
            rgblight_enable_noeeprom(); // Enables RGB, without saving settings
            rgblight_sethsv_noeeprom(RGB_AZURE);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        // add case for each layer
    }
};