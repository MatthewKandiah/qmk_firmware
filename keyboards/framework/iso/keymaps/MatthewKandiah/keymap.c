// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "framework.h"

// clang-format off
enum _layers {
  _BASE,
  _COLEMAK,
  _SYMBOLS,
  _NAVIGATION,
  _NUMPAD,
  _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_ESC,  KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_BRIU, KC_SCRN, XXXXXXX, KC_PSCR, KC_NO, KC_INS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,     KC_RSFT,
        KC_LCTL, MO(_FN), KC_LGUI, KC_LALT,          KC_SPC,                    KC_RALT, KC_RCTL, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),

    [_COLEMAK] = LAYOUT(
        KC_ESC,  KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_BRIU, KC_SCRN, XXXXXXX, KC_PSCR, KC_NO, KC_INS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, KC_CAPS,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_LBRC, KC_RBRC,
        LT(_NAVIGATION, KC_ESC), LGUI_T(KC_A),    LALT_T(KC_R),    LSFT_T(KC_S),    LCTL_T(KC_T),    KC_G,    KC_M,    RCTL_T(KC_N),    RSFT_T(KC_E),    RALT_T(KC_I),    RGUI_T(KC_O),    KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    MO(_NUMPAD),   KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,     KC_RSFT,
        KC_LCTL, MO(_FN), KC_LGUI, KC_BSPC,          LT(_SYMBOLS, KC_SPC),                    KC_ENT, KC_RCTL, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),

    [_SYMBOLS] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_CAPS,
        KC_TAB,  KC_EXLM,    KC_DQUO,    KC_LCBR,    KC_RCBR,    KC_PIPE,    KC_NUBS,    KC_LT,    KC_GT,    KC_EQL,    KC_PLUS,    KC_LBRC, KC_RBRC,
        KC_ESC, KC_PERC,    LSFT(KC_NUBS),    KC_LPRN,    KC_RPRN,    KC_GRV,    KC_SLSH,    KC_QUOT,    KC_AT,    KC_MINS,    KC_UNDS, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_CIRC, KC_DLR,    KC_LBRC,    KC_RBRC,    LSFT(KC_3),    KC_BSPC,    KC_GRV,    KC_AMPR,    KC_NUHS, KC_ASTR,  KC_QUES,     KC_RSFT,
        KC_LCTL, MO(_FN), KC_LGUI, KC_BSPC,          KC_SPC,                    KC_ENT, KC_RCTL, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),

    [_NAVIGATION] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_CAPS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_PGUP,    KC_UP,    KC_PGDN,    KC_P,    KC_LBRC, KC_RBRC,
        KC_ESC, KC_LGUI,    KC_LALT,    KC_LSFT,    KC_LCTL,    KC_G,    KC_H,    KC_LEFT,    KC_DOWN,    KC_RIGHT,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,     KC_RSFT,
        KC_LCTL, MO(_FN), KC_LGUI, KC_BSPC,          KC_SPC,                    KC_ENT, KC_RCTL, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),

    [_NUMPAD] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_CAPS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_COMM,    KC_7,    KC_8,    KC_9,    KC_P,    KC_LBRC, KC_RBRC,
        KC_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_0,    KC_4,    KC_5,    KC_6,    KC_MINS, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_DOT,    KC_1,    KC_2,    KC_3, KC_SLSH,     KC_RSFT,
        KC_LCTL, MO(_FN), KC_LGUI, KC_BSPC,          KC_SPC,                    KC_ENT, KC_RCTL, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),

    [_FN] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PAUS, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_SYRQ, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_SCRL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, BL_BRTG, KC_NO, KC_BRK,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO,
        TO(_BASE), KC_NO, KC_NO, KC_NO,          BL_STEP,                            KC_NO, TO(_COLEMAK), KC_HOME, KC_PGUP, KC_PGDN, KC_END
    ),
};
// clang-format on

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_SYMBOLS, KC_SPC):
            return 0;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A):
        case RGUI_T(KC_O):
        case LALT_T(KC_R):
        case RALT_T(KC_I):
        case LSFT_T(KC_S):
        case RSFT_T(KC_E):
        case LCTL_T(KC_T):
        case RCTL_T(KC_N):
            return false;
        default:
            return true;
    }
}

