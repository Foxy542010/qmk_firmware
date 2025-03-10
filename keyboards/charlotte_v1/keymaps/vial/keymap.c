#include QMK_KEYBOARD_H

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [0] = LAYOUT
    (
        KC_F1, KC_F2, KC_F3, KC_F4,
        KC_F5, KC_F6, KC_F7, KC_F8
    ),
    [1] = LAYOUT
    (
        _______, _______, _______, _______,
        _______, _______, _______, _______
    ),
    [2] = LAYOUT
    (
        _______, _______, _______, _______,
        _______, _______, _______, _______
    )
    [3] = LAYOUT
    (
        _______, _______, _______, _______,
        _______, _______, _______, _______
    )
};