// Copyright 2024-2025 Šimon Ondrašík

#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define _BL 0
#define _FL 1
#define _DL 2

int layer = 1;

enum custom_macros { CODE, FIREFOX, SL };
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [_BL] = LAYOUT
    (
        SL, KC_SLEP, LCTL(KC_C), LCTL(KC_P),
        LCTL(LSFT(KC_ESC)), FIREFOX, CODE, XXXXXXX
    ),
    [_FL] = LAYOUT
    (
        _______, KC_MUTE, _______, _______,
        _______, KC_SLEP, _______, _______
    ),
    [_DL] = LAYOUT
    (
        _______, QK_BOOT, DB_TOGG, EE_CLR,
        _______, _______, _______, QK_RBT
    )
};
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
        case SL:
            if (record->event.pressed)
            {
                switch (layer)
                {
                    case 1:
                        layer_on(_FL);
                        layer_off(_DL);

                        layer = 2;
                        break;
                    case 2:
                        layer_on(_DL);
                        layer_off(_FL);

                        layer = 3;
                        break;
                    case 3:
                        layer_off(_FL);
                        layer_off(_DL);

                        layer = 1;
                        break;
                    default:

                }
            }
            break;
        case CODE:
            if (record->event.pressed)
            {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_R) SS_UP(X_LGUI) SS_DELAY(50) "code" SS_TAP(X_ENTER));
            }
            break;
        case FIREFOX:
            if (record->event.pressed)
            {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_R) SS_UP(X_LGUI) SS_DELAY(50) "firefox" SS_TAP(X_ENTER));
            }
            break;
    }
    return true;
};
#if defined(ENCODER_ENABLE)
bool encoder_update_user(uint8_t index, bool clockwise)
{
    if (index == 0)
    {
        if (clockwise)
        {
            tap_code(KC_PGDN);
        }
        else
        {
            tap_code(KC_PGUP);
        }
    }
    return false;
};
#endif

#if defined(OLED_ENABLE)
static void render_logo(void) {
    static const char PROGMEM kirole_logo[] = {
        0,254,246, 98,118, 62, 30,  6,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  6, 30, 62,118, 98,246,254,  0,
        0,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  1,193,129,129,129,255,  1,  0,  0,  3,  1,  1,  1,  1,  1,255,  1,  0,  0,248,  6,  1,  1,  1,  1,  6,248,  0,  0,  1,  7, 25, 96,128,255,  1,  0,  0,  1,255,  1,  0,  0,  1,  3, 13, 48, 64,129,255,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,  0, 
        0,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,128,129,128,128,128,255,128,  0,  0,  0,  0,  0,  0,  0,128,255,128,  0,  0, 31, 96,128,128,128,128, 96, 31,  0,  0,  0, 60, 66,129,129,255,128,  0,  0,128,255,128,  0,  0,128,192,176, 12,  2,129,255,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,  0, 
        0,127,111, 70,110,124,120, 96, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 96,120,124,110, 70,111,127,  0,
    };
    oled_write_raw_P(kirole_logo, sizeof(kirole_logo));
}

bool oled_task_user(void) {
    render_logo();
    return false;
}
#endif

#if defined(OS_DETECTION_ENABLE)
bool process_detected_host_os_kb(os_variant_t detected_os)
{
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
            break;
        case OS_IOS:
            break;
        case OS_WINDOWS:
            break;
        case OS_LINUX:
            break;
        case OS_UNSURE:
            break;
        default:
            break;
    }
    return true;
};
#endif