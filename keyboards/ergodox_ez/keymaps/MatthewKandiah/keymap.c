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
[1] = LAYOUT_ergodox_pretty(
  // left hand
  KC_NO,         KC_F1,        KC_F2,          KC_F3,     KC_F4,        KC_F5,    KC_F11,                    KC_F12,      KC_F6,    KC_F7,    KC_F8,    KC_F9,              KC_F10,            KC_NO,
  KC_NO,         KC_Q,         KC_W,           KC_F,      KC_P,         KC_B,     KC_CAPS,                   KC_CAPS,     KC_J,     KC_L,     KC_U,     KC_Y,               KC_SCLN,           KC_NO,
  KC_NO,         LCTL_T(KC_A), LALT_T(KC_R),   LSFT(KC_S),LGUI_T(KC_T), KC_G,                                             KC_M,     RGUI_T(KC_N),RSFT_T(KC_E),RALT_T(KC_I), RCTL_T(KC_O),      KC_NO,
  KC_NO,         KC_Z,         KC_X,           KC_C,      KC_D,         KC_V,     KC_CAPS,                   KC_CAPS,     KC_K,     KC_H,     KC_COMM,  KC_DOT,             KC_SLSH,           KC_NO,
  TO(0),         KC_NO,        KC_NO,          KC_BSPC,   KC_DEL,                                                                   KC_TAB,   KC_NO,    KC_NO,              KC_NO,             KC_NO,
                                                                        KC_NO,    KC_NO,                     KC_NO,       KC_NO,
                                                                                  KC_NO,                     KC_NO,
                                                   LT(3, KC_BSPC), LT(4, KC_ESC), KC_NO,                     KC_NO, KC_ENT, LT(6, KC_SPC)
),
[2] = LAYOUT_ergodox_pretty(
  // left hand
  KC_NO,         KC_F1,        KC_F2,          KC_F3,     KC_F4,        KC_F5,    KC_F11,                    KC_F12,      KC_F6,    KC_F7,    KC_F8,    KC_F9,              KC_F10,            KC_NO,
  KC_NO,         KC_EXLM,      KC_DQUO,        KC_LCBR,   KC_RCBR,      KC_PIPE,  KC_CAPS,                   KC_CAPS,     KC_NUBS,  KC_LT,    KC_GT,    KC_EQL,             KC_PLUS,           KC_NO,
  KC_NO,         KC_PERC,      LSFT(KC_NUBS),  KC_LPRN,   KC_RPRN,      KC_GRV,                                           KC_SLSH,  KC_QUOT,  KC_AT,    KC_MINS,            KC_UNDS,           KC_NO,
  KC_NO,         KC_CIRC,      KC_DLR,         KC_LBRC,   KC_RBRC,      KC_LSFT(KC_3),KC_CAPS,               KC_CAPS,     KC_GRV,   KC_AMPR,  KC_NUHS,  KC_ASTR,            KC_QUES,           KC_NO,
  TO(0),         KC_TRNS,      KC_TRNS,        KC_TRNS,   KC_TRNS,                                                                  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,           TO(2),
                                                                      KC_TRNS,    KC_TRNS,                     KC_TRNS,       KC_TRNS,
                                                                                  KC_TRNS,                     KC_TRNS,
                                                                KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS
),
[3] = LAYOUT_ergodox_pretty(
  // left hand
  KC_NO,         KC_F1,        KC_F2,          KC_F3,     KC_F4,        KC_F5,    KC_F11,                    KC_F12,      KC_F6,    KC_F7,    KC_F8,    KC_F9,              KC_F10,            KC_NO,
  KC_NO,         KC_EXLM,      KC_AT,          KC_LCBR,   KC_RCBR,      KC_TILD,  KC_CAPS,                   KC_CAPS,     KC_NUHS,  KC_LT,    KC_GT,    KC_EQL,             KC_PLUS,           KC_NO,
  KC_NO,         KC_PERC,      KC_PIPE,        KC_LPRN,   KC_RPRN,      KC_GRV,                                           KC_SLSH,  KC_QUOT,  KC_DQUO,  KC_MINS,            KC_UNDS,           KC_NO,
  KC_NO,         KC_CIRC,      KC_DLR,         KC_LBRC,   KC_RBRC,      KC_HASH,  KC_CAPS,                   KC_CAPS,     KC_NUBS,  KC_AMPR,  LALT(KC_3),KC_ASTR,           KC_QUES,           KC_NO,
  TO(0),         KC_TRNS,      KC_TRNS,        KC_TRNS,   KC_TRNS,                                                                  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,           TO(2),
                                                                      KC_TRNS,    KC_TRNS,                     KC_TRNS,       KC_TRNS,
                                                                                  KC_TRNS,                     KC_TRNS,
                                                                KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS
),
[4] = LAYOUT_ergodox_pretty(
  // left hand
  KC_NO,         KC_NO,        KC_NO,          KC_NO,     KC_NO,        KC_NO,    KC_NO,                    KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,            KC_NO,           KC_NO,
  KC_NO,         KC_NO,        KC_NO,          KC_NO,    KC_NO,         KC_NO,    KC_NO,                    KC_NO,      KC_COMM,    KC_7,    KC_8,    KC_9,            KC_EQL,           KC_NO,
  KC_NO,         KC_NO,        KC_NO,          KC_NO,    KC_NO,         KC_NO,                                          KC_0,     KC_4,     KC_5,     KC_6,             KC_MINS,           KC_NO,
  KC_NO,         KC_NO,        KC_NO,          KC_NO,    KC_NO,         KC_NO,    KC_NO,                    KC_NO,      KC_DOT,    KC_1,     KC_2,     KC_3,             KC_PLUS,           KC_NO,
  TO(0),         KC_TRNS,      KC_TRNS,        KC_TRNS,   KC_TRNS,                                                            KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,           TO(2),
                                                                      KC_TRNS,    KC_TRNS,                     KC_TRNS,       KC_TRNS,
                                                                                  KC_TRNS,                     KC_TRNS,
                                                                KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS
),
[5] = LAYOUT_ergodox_pretty(
  // left hand
  KC_NO,         KC_NO,        KC_NO,          KC_NO,     KC_NO,        KC_NO,    KC_NO,                    KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,            KC_NO,           KC_NO,
  KC_NO,         KC_NO,        KC_NO,          KC_NO,    KC_NO,         KC_NO,    KC_NO,                    KC_NO,      KC_NO,    KC_PGUP,    KC_UP,    KC_PGDN,            KC_NO,           KC_NO,
  KC_NO,         KC_LGUI,        KC_LALT,          KC_LSFT,    KC_LCTL,         KC_NO,                                          KC_NO,     KC_LEFT,     KC_DOWN,     KC_RIGHT,             KC_NO,           KC_NO,
  KC_NO,         KC_NO,        KC_NO,          KC_NO,    KC_NO,         KC_NO,    KC_NO,                    KC_NO,      KC_NO,    KC_NO,     KC_NO,     KC_NO,             KC_NO,           KC_NO,
  TO(0),         KC_TRNS,      KC_TRNS,        KC_TRNS,   KC_TRNS,                                                            KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,           TO(2),
                                                                      KC_TRNS,    KC_TRNS,                     KC_TRNS,       KC_TRNS,
                                                                                  KC_TRNS,                     KC_TRNS,
                                                                KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS
),
[6] = LAYOUT_ergodox_pretty(
  // left hand
  KC_NO,         KC_NO,        KC_NO,          KC_NO,     KC_NO,        KC_NO,    KC_NO,                    KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,            KC_NO,           KC_NO,
  KC_NO,         KC_NO,        KC_NO,          KC_NO,    KC_NO,         KC_NO,    KC_NO,                    KC_NO,      KC_NO,    KC_PGUP,    KC_UP,    KC_PGDN,            KC_NO,           KC_NO,
  KC_NO,         KC_LCTL,        KC_LALT,          KC_LSFT,    KC_LGUI,         KC_NO,                                          KC_NO,     KC_LEFT,     KC_DOWN,     KC_RIGHT,             KC_NO,           KC_NO,
  KC_NO,         KC_NO,        KC_NO,          KC_NO,    KC_NO,         KC_NO,    KC_NO,                    KC_NO,      KC_NO,    KC_NO,     KC_NO,     KC_NO,             KC_NO,           KC_NO,
  TO(0),         KC_TRNS,      KC_TRNS,        KC_TRNS,   KC_TRNS,                                                            KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,           TO(2),
                                                                      KC_TRNS,    KC_TRNS,                     KC_TRNS,       KC_TRNS,
                                                                                  KC_TRNS,                     KC_TRNS,
                                                                KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS
),
};
// clang-format on
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A):
        case RGUI_T(KC_O):
        case LCTL_T(KC_A):
        case RCTL_T(KC_O):
            return false;
        default:
            return true;
    }
}

