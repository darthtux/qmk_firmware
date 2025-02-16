/* Copyright 2023 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
//#include "sofle_choc.c"

// clang-format off

enum __layers {
    Base,
    Mouse,
    Arrows,
    SYMBOLS,
    MAC_SHORTS
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LGUI | LCMD | LALT | /Enter  /       \Space \  | RALT | RCMD | RGUI | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[Base] = LAYOUT(
    KC_GRV,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,     KC_7,                   KC_8,                   KC_9,                       KC_0,                   KC_MINUS,
    KC_ESC,   KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,     KC_U,                   KC_I,                   KC_O,                       KC_P,                   KC_BSPC,
    KC_TAB,   KC_A,     KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,     LT(SYMBOLS,KC_J),       LT(MAC_SHORTS,KC_K),    KC_L,                       KC_SCLN,                KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,       KC_MPLY, KC_MUTE,  KC_N,     KC_M,                   MT(MOD_LGUI, KC_COMM),  MT(MOD_LALT, KC_DOT),       MT(MOD_LCTL, KC_SLSH),  KC_RSFT,
    KC_LCTL,  KC_LALT,  KC_LGUI, KC_SPC,  KC_LSFT,                                KC_BSPC,  KC_ENT,                 KC_RCMD,                KC_RGUI,                    KC_RCTL
),
[Mouse] = LAYOUT(
    _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,       KC_F8,     KC_F9,      KC_F10,     _______,
    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    MS_BTN1,     MS_UP,     MS_BTN2,    MS_ACL0,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    MS_LEFT,     MS_DOWN,   MS_RGHT,    MS_ACL1,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    KC_MPLY, KC_MUTE,       _______,    MS_WHLU,     MS_WHLD,   MS_WHLD,    MS_ACL2,    _______,
    _______,    _______,    _______,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______
),
[Arrows] = LAYOUT(
    _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     _______,
    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    KC_BSPC,    KC_UP,      _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_ESC,     _______,
    _______,    _______,    _______,    _______,    _______,    _______,    KC_MPLY, KC_MUTE,       _______,    KC_DELETE,  KC_TAB,     _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______
),
[SYMBOLS] = LAYOUT(
    CG_TOGG,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                                  KC_F6,          KC_F7,      KC_F8,      KC_F9,      KC_F10,       _______,
    _______,    KC_LBRC,    KC_RBRC,    KC_EQUAL,   KC_DQUO,    _______,                                _______,        _______,    _______,    _______,    _______,      _______,
    _______,    KC_LCBR,    KC_RCBR,    KC_BSLS,    KC_PIPE,    _______,                                _______,        _______,    _______,    _______,    _______,      _______,
    _______,    KC_LABK,    KC_RABK,    KC_PLUS,    KC_PMNS,    _______,    KC_MPLY, KC_MUTE,           _______,        _______,    _______,    _______,    _______,      _______,
    _______,    _______,    _______,    _______,    _______,                                            _______,        _______,    _______,    _______,    _______
),
[MAC_SHORTS] = LAYOUT(
    CG_TOGG,    _______,    _______,    _______,        _______,           _______,                             _______,    _______,    _______,    _______,    _______,      _______,
    _______,    _______,    _______,    _______,        LALT(KC_BSPC),     _______,                             _______,    _______,    _______,    _______,    _______,      _______,
    _______,    _______,    LGUI(KC_X), LGUI(KC_V),     LGUI(KC_C),        _______,                             _______,    _______,    _______,    _______,    _______,      _______,
    _______,    _______,    _______,    _______,        LGUI(KC_Z),        _______,   KC_MPLY, KC_MUTE,         _______,    _______,    _______,    _______,    _______,      _______,
    _______,    _______,    _______,    _______,        _______,                                                _______,    _______,    _______,    _______,    _______
)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [Base] = {  ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [Mouse] = {  ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [Arrows] = {  ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [SYMBOLS] = {  ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_SHORTS] = {  ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif

const uint16_t PROGMEM mouse_layer[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM arrows_layer[] = {KC_A, KC_S, COMBO_END};

combo_t key_combos[] = {
    COMBO(mouse_layer, MO(Mouse)),
    COMBO(arrows_layer, MO(Arrows)),
};