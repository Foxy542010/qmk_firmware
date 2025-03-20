// Copyright 2024-2025 Šimon Ondrašík

#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define LAYER_SWITCH_START 0
#define LAYER_SWITCH_END 3

enum via_display_value {
    id_diplay_brightness = 1,
};
enum custom_macros { KC_SL = QK_USER, };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [0] = LAYOUT(
        KC_SL, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO
    ),
    [1] = LAYOUT(
        _______, _______, _______, _______,
        _______, _______, _______, _______
    ),
    [2] = LAYOUT(
        _______, _______, _______, _______,
        _______, _______, _______, _______
    ),
    [3] = LAYOUT(
        _______, _______, _______, _______,
        _______, _______, _______, _______
    )
};
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
        case KC_SL:
            if (record->event.pressed)
            {
                return false;
            }

            uint8_t current_layer = get_highest_layer(layer_state);

            if (current_layer > LAYER_SWITCH_END || current_layer < LAYER_SWITCH_START)
            {
                return false;
            }

            uint8_t next_layer = current_layer + 1;

            if (next_layer > LAYER_SWITCH_END)
            {
                next_layer = LAYER_SWITCH_START;
            }
            layer_move(next_layer);
            void render_layer_state(void);
            render_layer_state();
            return false;
    }
    return true;
};
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(_______, _______) },
    [2] = { ENCODER_CCW_CW(_______, _______) },
    [3] = { ENCODER_CCW_CW(_______, _______) },
};
#endif