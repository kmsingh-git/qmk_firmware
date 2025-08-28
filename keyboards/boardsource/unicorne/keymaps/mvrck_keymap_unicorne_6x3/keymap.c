#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

#include "rgb_matrix.h"
#include "timer.h"
#include "caps_word.h"
#include "print.h"
#include "rgb_matrix.h"

enum layer_names {
    _BASE,
    _NAV,
    _NUM,
    _MEDIA
};

enum led_states {
    LAYER_BASE,
    LAYER_NAV,
    LAYER_NUM,
    ACTION_CAPS_WORD
};

uint8_t DEFAULT_HUE = 200;
uint8_t DEFAULT_SAT = 200;
uint8_t DEFAULT_VAL = 100;

void set_led_colors(enum led_states led_state) {
    switch (led_state) {
        case ACTION_CAPS_WORD:
            rgb_matrix_sethsv_noeeprom(HSV_RED);
            return;
        default:
            rgb_matrix_sethsv_noeeprom(DEFAULT_HUE, DEFAULT_SAT, DEFAULT_VAL);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            return;
    }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                           KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_ESC, LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), KC_G,           KC_H, RSFT_T(KC_J), RGUI_T(KC_K), LALT_T(KC_L), LCTL_T(KC_SCLN), KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                                          KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MO(_MEDIA),
                                KC_LCTL, MO(_NAV), KC_LGUI,                    KC_ENT, LT(_NUM, KC_SPACE), KC_RALT
    ),
    [_NAV] = LAYOUT_split_3x6_3(
        LGUI(KC_GRV), LGUI(KC_Q), LGUI(KC_W), LCTL(KC_TAB), LGUI(KC_R), LGUI(KC_T),     LGUI(KC_LEFT), KC_NO, KC_UP, KC_NO, LGUI(KC_RIGHT), KC_BSPC,
        KC_WWW_BACK, LGUI(KC_A), LGUI(KC_S), LCTL(LSFT(KC_TAB)), LGUI(KC_F), KC_NO,           LALT(KC_LEFT), KC_LEFT, KC_DOWN, KC_RIGHT, LALT(KC_RIGHT), KC_NO,
        KC_LSFT, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), KC_NO,                 LGUI(KC_LEFT_BRACKET), LGUI(KC_RIGHT_BRACKET), LGUI(LSFT(KC_COMM)), LGUI(LSFT(KC_DOT)), LGUI(KC_SLASH), KC_NO,
                                KC_NO, _______, KC_NO,                      LGUI(KC_ENT), KC_SPACE, KC_RALT
    ),
    [_NUM] = LAYOUT_split_3x6_3(
        KC_NO, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                                KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5,                                            KC_6, KC_7, KC_8, KC_9, KC_0, KC_QUOT,
        KC_NO, KC_GRV, KC_SCLN, KC_MINUS, KC_EQUAL, KC_BACKSLASH,                       KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
                                KC_NO, KC_NO, KC_LGUI,                      KC_NO, _______, KC_NO
    ),
    [_MEDIA] = LAYOUT_split_3x6_3(
        QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                       KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                KC_NO, KC_NO, KC_NO,                        KC_NO, KC_NO, KC_NO
    )
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
                       '*', '*', '*',  '*', '*', '*'
    );

bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        // case KC_SPC: // Removing space since I want the hold function of space to not be affected by flow tap
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}


// RGB stuff
void keyboard_post_init_user(void) {
    set_led_colors(LAYER_BASE);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    set_led_colors(get_highest_layer(state));
    return state;
}

void caps_word_set_user(bool active) {
    if (active) {
        set_led_colors(ACTION_CAPS_WORD);
    } else {
        set_led_colors(get_highest_layer(layer_state));
    }
}