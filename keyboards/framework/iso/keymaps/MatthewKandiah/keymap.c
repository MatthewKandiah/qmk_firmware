// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "framework.h"

// clang-format off
enum _layers {
  _BASE,
  _FN,
  _FN_LOCK,
  _FM,
  _COLEMAK,
  _SYMBOLS,
  _NAVIGATION,
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state);

// Tap dance enums
enum {
    SPACE_TD,
};

// make fn+enter emit QK_BOOT - do on both _FN and _FM so it works whether you have fn lock on or not
// to test flashing works, just change caps lock to backspace and try flashing
// TODO - undo this when adding my actual layers!

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,     KC_RSFT,
        KC_LCTL, MO(_FN), KC_LGUI, KC_LALT,          KC_SPC,                    KC_RALT, TO(_COLEMAK), KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),

    [_FN] = LAYOUT(
        FN_LOCK, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_BRIU, KC_SCRN, XXXXXXX, KC_PSCR, KC_MSEL, KC_INS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PAUS, _______, _______,
        _______, _______, KC_SYRQ, _______, _______, _______, _______, _______, KC_SCRL, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, _______, BL_BRTG, _______, KC_BRK,  _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______,          BL_STEP,                            _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END
    ),

    [_FN_LOCK] = LAYOUT(
        _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_BRIU, KC_SCRN, XXXXXXX, KC_PSCR, KC_MSEL, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, MO(_FM), _______, _______,          _______,                            _______, _______, _______, _______, _______, _______
    ),

    [_FM] = LAYOUT(
        FN_LOCK, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PAUS, _______, _______,
        _______, _______, KC_SYRQ, _______, _______, _______, _______, _______, KC_SCRL, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, BL_BRTG, _______, KC_BRK,  _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______,          BL_STEP,                            _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END
    ),

    [_COLEMAK] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_LBRC, KC_RBRC,
        KC_CAPS, LGUI_T(KC_A),    LALT_T(KC_R),    LSFT_T(KC_S),    LCTL_T(KC_T),    KC_G,    KC_M,    RCTL_T(KC_N),    RSFT_T(KC_E),    RALT_T(KC_I),    RGUI_T(KC_O),    KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_TAB,   KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,     KC_RSFT,
        KC_LCTL, MO(_FN), KC_LGUI, KC_ESC,          TD(SPACE_TD),                    KC_ENT, TO(_BASE), KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),

    // TODO - undo tab -> 1 & add symbols
    [_SYMBOLS] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_1,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,     KC_RSFT,
        KC_LCTL, MO(_FN), KC_LGUI, KC_LALT,          KC_SPC,                    KC_RALT, KC_RCTL, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),

    // TODO - undo tab -> 2 & add nav keys
    [_NAVIGATION] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_2,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,     KC_RSFT,
        KC_LCTL, MO(_FN), KC_LGUI, KC_LALT,          KC_SPC,                    KC_RALT, KC_RCTL, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),
};
// clang-format on

// Make sure to keep FN Lock even after reset
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FN_LOCK:
            if (record->event.pressed) {
                if (layer_state_is(_FN)) {
                    set_single_persistent_default_layer(_FN_LOCK);
                }
                if (layer_state_is(_FM)) {
                    set_single_persistent_default_layer(_BASE);
                }
            }
            return false;
            break;
        default:
            break;
    }
    return true;
}

// copied from https://docs.qmk.fm/#/feature_tap_dance?id=example-5
/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t space_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void space_finished(tap_dance_state_t *state, void *user_data) {
    space_tap_state.state = cur_dance(state);
    switch (space_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_SPC); break;
        case TD_SINGLE_HOLD: layer_on(_SYMBOLS); break;
        case TD_DOUBLE_TAP: register_code(KC_SPC); break;
        case TD_DOUBLE_HOLD: layer_on(_NAVIGATION); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_SPC); register_code(KC_SPC); break;
        default: break;
    }
}

void space_reset(tap_dance_state_t *state, void *user_data) {
    switch (space_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_SPC); break;
        case TD_SINGLE_HOLD: layer_off(_SYMBOLS); break;
        case TD_DOUBLE_TAP: unregister_code(KC_SPC); break;
        case TD_DOUBLE_HOLD: layer_off(_NAVIGATION); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_SPC); break;
        default: break;
    }
    space_tap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [SPACE_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, space_finished, space_reset)
};
