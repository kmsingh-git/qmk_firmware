/* Copyright 2023 Cyboard LLC (@Cyboard-DigitalTailor)
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**************************/
/*       CYBOARD          */
/**************************/

#include QMK_KEYBOARD_H
#include <cyboard.h>
#include "caps_word.h"
#include "rgb_matrix.h"

enum layer_names {
    _BASE,
    _NAV,
    _NUM,
    _MEDIA
};

enum combos {
    // RT_LPRN, // ( // This has a few misfires
    // YU_RPRN, // )
    MCOMM_LBRC, // [
    COMMDOT_RBRC, // ]

    XC_HYPHEN, // -
    CV_UNDERSCORE, // _
};

// const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
// const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM mcomm_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};

const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};

combo_t key_combos[] = {
    // [RT_LPRN] = COMBO(rt_combo, KC_LPRN),
    // [YU_RPRN] = COMBO(yu_combo, KC_RPRN),
    [MCOMM_LBRC] = COMBO(mcomm_combo, KC_LEFT_BRACKET),
    [COMMDOT_RBRC] = COMBO(commdot_combo, KC_RIGHT_BRACKET),

    [CV_UNDERSCORE] = COMBO(cv_combo, LSFT(KC_MINUS)),
    [XC_HYPHEN] = COMBO(xc_combo, KC_MINUS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_let(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                                                           KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_ESC, LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), KC_G,                                           KC_H, RSFT_T(KC_J), RGUI_T(KC_K), LALT_T(KC_L), LCTL_T(KC_SCLN), KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                                                                          KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MO(_MEDIA),
                RM_VALD, RM_VALU,           KC_LSFT, KC_NO, LCTL(LGUI(KC_Q)),                                   MS_BTN1, KC_ENT, KC_SPACE,      KC_VOLD, KC_VOLU,
                                            LT(_NAV, KC_BSPC), KC_LSFT, LGUI(KC_LEFT_BRACKET),                  MS_BTN2, KC_NO, MO(_NUM)
    ),

    [_NAV] = LAYOUT_let(
        LGUI(KC_GRV), LGUI(KC_Q), LGUI(KC_W), LCTL(KC_TAB), LGUI(KC_R), LGUI(KC_T),     LGUI(KC_LEFT), KC_NO, KC_UP, KC_NO, LGUI(KC_RIGHT), KC_BSPC,
        KC_WWW_BACK, LGUI(KC_A), LGUI(KC_S), LCTL(LSFT(KC_TAB)), LGUI(KC_F), KC_NO,     LALT(KC_LEFT), KC_LEFT, KC_DOWN, KC_RIGHT, LALT(KC_RIGHT), KC_NO,
        KC_LSFT, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), KC_NO,                 LGUI(KC_LEFT_BRACKET), LGUI(KC_RIGHT_BRACKET), LGUI(LSFT(KC_COMM)), LGUI(LSFT(KC_DOT)), LGUI(KC_SLASH), KC_NO,
                _______, _______,       _______, _______, _______,                  _______, _______, _______,      _______, _______,
                                        _______, _______, _______,                  _______, _______, _______
    ),

    [_NUM] = LAYOUT_let(
        KC_NO, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                                KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5,                                            KC_6, KC_7, KC_8, KC_9, KC_0, KC_QUOT,
        KC_NO, KC_GRV, KC_SCLN, KC_MINUS, KC_EQUAL, KC_BACKSLASH,                       KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
                _______, _______,       _______, _______, _______,                  _______, _______, _______,       _______, _______,
                                        _______, _______, _______,                   _______, _______, _______
    ),

    [_MEDIA] = LAYOUT_let(
        QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                     KC_NO, KC_NO, KC_NO, RM_TOGG, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                       KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                _______, _______,       _______, _______, _______,         _______, _______, _______,       _______, _______,
                                        _______, _______, _______,         _______, _______, _______
    )
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_let(
        'L', 'L', 'L', 'L', 'L', 'L',                       'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',                       'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',                       'R', 'R', 'R', 'R', 'R', 'R', 
                '*', '*',       '*', '*', '*',      '*', '*', '*',          '*','*',
                                '*', '*', '*',      '*', '*', '*'
    );

bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        // case KC_SPC: // Removing space since I want the hold function of space to not be affected by flow tap
        case KC_SPC: // Adding it back
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true; // These keys will not trigger their hold function until after flow tap term
    }
    return false;
}

/*************************************************/
/*               RGB stuff                       */
/*************************************************/

enum led_states {
    LAYER_BASE,
    LAYER_NAV,
    LAYER_NUM,
    LAYER_MEDIA,
    ACTION_CAPS_WORD
};

uint8_t DEFAULT_HUE = 234;
uint8_t DEFAULT_SAT = 128;
uint8_t DEFAULT_VAL = 128;

void set_led_colors(enum led_states led_state) {
    switch (led_state) {
        case ACTION_CAPS_WORD:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_RED);
            return;
        default:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
            rgb_matrix_sethsv_noeeprom(DEFAULT_HUE, DEFAULT_SAT, DEFAULT_VAL);
            return;
    }
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
    set_led_colors(LAYER_BASE);
}

void caps_word_set_user(bool active) {
    if (active) {
        set_led_colors(ACTION_CAPS_WORD);
    } else {
        set_led_colors(get_highest_layer(layer_state));
    }
}