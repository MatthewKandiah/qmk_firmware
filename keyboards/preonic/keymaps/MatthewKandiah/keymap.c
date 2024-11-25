#include QMK_KEYBOARD_H

#define TO_BASE TO(_BASE)
#define TO_MAC TO(_BASE_MAC)
#define GUIA LGUI_T(KC_A)
#define GUIT LGUI_T(KC_T)
#define ALTR LALT_T(KC_R)
#define SFTS LSFT_T(KC_S)
#define CTLT LCTL_T(KC_T)
#define CTLA LCTL_T(KC_A)
#define CTLN RCTL_T(KC_N)
#define CTLO RCTL_T(KC_O)
#define SFTE RSFT_T(KC_E)
#define ALTI RALT_T(KC_I)
#define GUIO RGUI_T(KC_O)
#define GUIN RGUI_T(KC_N)
#define BSPSYM LT(_SYMBOLS, KC_BSPC)
#define BSPMSYM LT(_SYMBOLS_MAC, KC_BSPC)
#define ESCNUM LT(_NUMPAD, KC_ESC)
#define SPCNAV LT(_NAVIGATION, KC_SPC)
#define SPCMNAV LT(_NAVIGATION_MAC, KC_SPC)
#define GB_PIPE LSFT(KC_NUBS)
#define GB_PND LSFT(KC_3)
#define GB_PNDM LALT(KC_3)

enum layers {
    _BASE,
    _BASE_MAC,
    _SYMBOLS,
    _SYMBOLS_MAC,
    _NUMPAD,
    _NAVIGATION,
    _NAVIGATION_MAC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT_ortho_5x12(
        KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F11, KC_F12, KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,
        KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,   KC_NO,  KC_NO,  KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,
        GUIA,   ALTR,   SFTS,   CTLT,   KC_G,   KC_NO,  KC_NO,  KC_M,   CTLN,   SFTE,   ALTI,   GUIO,
        KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,   KC_NO,  KC_NO,  KC_K,   KC_H,   KC_COMM,KC_DOT, KC_SLSH,
        KC_NO,  KC_NO,  KC_NO,  KC_LSFT,BSPSYM, ESCNUM, KC_ENT, SPCNAV, KC_TAB, KC_NO,  KC_NO,  TO_MAC),

	[_BASE_MAC] = LAYOUT_ortho_5x12(
        KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F11, KC_F12, KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,
        KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,   KC_NO,  KC_NO,  KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,
        GUIA,   ALTR,   SFTS,   CTLT,   KC_G,   KC_NO,  KC_NO,  KC_M,   CTLN,   SFTE,   ALTI,   GUIO,
        KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,   KC_NO,  KC_NO,  KC_K,   KC_H,   KC_COMM,KC_DOT, KC_SLSH,
        TO_BASE,KC_NO,  KC_NO,  KC_LSFT,BSPMSYM,ESCNUM, KC_ENT, SPCMNAV,KC_TAB, KC_NO,  KC_NO,  KC_NO),

	[_SYMBOLS] = LAYOUT_ortho_5x12(
        KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F11, KC_F12, KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,
        KC_EXLM,KC_DQUO,KC_LCBR,KC_RCBR,KC_PIPE,KC_NO,  KC_NO,  KC_NUBS,KC_LT,  KC_GT,  KC_EQL, KC_PLUS,
        KC_PERC,GB_PIPE,KC_LPRN,KC_RPRN,KC_GRV, KC_NO,  KC_NO,  KC_SLSH,KC_QUOT,KC_AT,  KC_MINS,KC_UNDS,
        KC_CIRC,KC_DLR, KC_LBRC,KC_RBRC,GB_PND, KC_NO,  KC_NO,  KC_GRV, KC_AMPR,KC_NUHS,KC_ASTR,KC_QUES,
        TO_BASE,KC_NO,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_NO,  TO_MAC),

	[_SYMBOLS_MAC] = LAYOUT_ortho_5x12(
        KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F11, KC_F12, KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,
        KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_TILD,KC_NO,  KC_NO,  KC_NUHS,KC_LT,  KC_GT,  KC_EQL, KC_PLUS,
        KC_PERC,KC_PIPE,KC_LPRN,KC_RPRN,KC_GRV, KC_NO,  KC_NO,  KC_SLSH,KC_QUOT,KC_DQUO,KC_MINS,KC_UNDS,
        KC_CIRC,KC_DLR, KC_LBRC,KC_RBRC,KC_HASH,KC_NO,  KC_NO,  KC_NUBS,KC_AMPR,GB_PNDM,KC_ASTR,KC_QUES,
        TO_BASE,KC_NO,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_NO,  TO_MAC),

	[_NUMPAD] = LAYOUT_ortho_5x12(
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_COMM,KC_7,   KC_8,   KC_9,   KC_EQL,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_0,   KC_4,   KC_5,   KC_6,   KC_MINS,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_DOT, KC_1,   KC_2,   KC_3,   KC_PLUS,
        TO_BASE,KC_NO,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_NO,  TO_MAC),

	[_NAVIGATION] = LAYOUT_ortho_5x12(
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_PGUP,KC_UP,  KC_PGDN,KC_NO,
        KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_LEFT,KC_DOWN,KC_RGHT,KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        TO_BASE,KC_NO,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_NO,  TO_MAC),

	[_NAVIGATION_MAC] = LAYOUT_ortho_5x12(
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_PGUP,KC_UP,  KC_PGDN,KC_NO,
        KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_LEFT,KC_DOWN,KC_RGHT,KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        TO_BASE,KC_NO,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_NO,  TO_MAC)
};

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

