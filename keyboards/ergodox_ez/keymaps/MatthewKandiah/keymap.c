#include QMK_KEYBOARD_H
#include "version.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_ergodox_pretty(
  // left hand
  KC_NO,         KC_F1,        KC_F2,          KC_F3,     KC_F4,        KC_F5,    KC_F11,                    KC_F12,      KC_F6,    KC_F7,    KC_F8,    KC_F9,              KC_F10,            KC_NO,
  KC_NO,         KC_Q,         KC_W,           KC_F,      KC_P,         KC_B,     KC_CAPS,                   KC_CAPS,     KC_J,     KC_L,     KC_U,     KC_Y,               KC_SCLN,           KC_NO,
  KC_NO,         LGUI_T(KC_A), LALT_T(KC_R),   LSFT(KC_S),LCTL_T(KC_T), KC_G,                                             KC_M,     RCTL_T(KC_N),RSFT_T(KC_E),RALT_T(KC_I), RGUI_T(KC_O),      KC_NO,
  KC_NO,         KC_Z,         KC_X,           KC_C,      KC_D,         KC_V,     KC_CAPS,                   KC_CAPS,     KC_K,     KC_H,     KC_COMM,  KC_DOT,             KC_SLSH,           KC_NO,
  KC_NO,         KC_NO,        KC_NO,          KC_BSPC,   KC_DEL,                                                                   KC_TAB,   KC_NO,    KC_NO,              KC_NO,             TO(1),
                                                                        KC_NO,    KC_NO,                     KC_NO,       KC_NO,
                                                                                  KC_NO,                     KC_NO,
                                                   LT(2, KC_BSPC), LT(4, KC_ESC), KC_NO,                     KC_NO, KC_ENT, LT(5, KC_SPC)
),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
