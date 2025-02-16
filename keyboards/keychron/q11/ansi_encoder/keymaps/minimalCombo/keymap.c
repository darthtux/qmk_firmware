/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

enum layers{
    MAC_BASE,
    Mouse,
    Arrows,
    Symbols,
    Shortcuts,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,   KC_BRID,            KC_BRIU,  KC_MCTL,  KC_LPAD,  RM_VALD,   RM_VALU,  KC_MPRV,             KC_MPLY,             KC_MNXT,  KC_MUTE,     KC_VOLD,    KC_VOLU,  KC_INS,   KC_DEL,   KC_MUTE,
        RM_TOGG,  KC_GRV,   KC_1,               KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,                KC_8,                KC_9,     KC_0,        KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        RM_NEXT,  KC_ESC,   KC_Q,               KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,                KC_I,                KC_O,     KC_P,        KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        RM_PREV,  KC_TAB,   KC_A,               KC_S,     KC_Z,    KC_F,     KC_G,      KC_H,     LT(Symbols,KC_J),    LT(Shortcuts,KC_K),  KC_L,     KC_SCLN,     KC_QUOT,              KC_ENT,             KC_HOME,
        RM_VALU,  KC_LSFT,                      KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,                KC_M,                MT(MOD_LGUI, KC_COMM),  MT(MOD_LALT, KC_DOT),      MT(MOD_LCTL, KC_SLSH),              KC_RSFT,  KC_UP,
        RM_VALD,  KC_LCTL,  MO(Symbols),        KC_LOPT,  KC_LCMD,       MT(MOD_LSFT,KC_SPC),                           KC_ENT,              KC_RCMD,  MO(Symbols), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT),

    [Mouse] = LAYOUT_91_ansi(
        _______,  _______, KC_F1,       KC_F2,    KC_F3,    KC_F4,      KC_F5,       KC_F6,      KC_F7,      KC_F8,         KC_F9,           KC_F10,          KC_F11,     KC_F12,  _______,  _______,   _______,
        _______,  _______,  _______,  _______,  _______,    _______,    _______,     _______,    _______,    _______,    _______,   _______,   _______,    _______,  _______,             _______,
        _______,  _______,  _______,  _______,  _______,    _______,    _______,     _______,    MS_BTN1,    MS_UP,      MS_BTN2,   MS_ACL0,   _______,    _______,  _______,             _______,
        _______,  _______,  _______,  _______,  _______,    _______,    _______,     _______,    MS_LEFT,    MS_DOWN,    MS_RGHT,   MS_ACL1,   _______,              _______,             _______,
        _______,  _______,  _______,  _______,  _______,    _______,    _______,     _______,    MS_WHLD,    MS_WHLD,    MS_WHLU,   MS_ACL2,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,        _______,                         _______,             _______, _______, _______,  _______,  _______,  _______),

    [Arrows] = LAYOUT_91_ansi(
            _______,  _______,  _______,  _______,  _______,    _______,    _______,     _______,    _______,       _______,    _______,   _______,     _______,    _______,  _______,  _______,   _______,
            _______,  _______,  _______,  _______,  _______,    _______,    _______,     _______,    _______,       _______,    _______,   _______,     _______,    _______,  _______,             _______,
            _______,  _______,  _______,  _______,  _______,    _______,    _______,     _______,    KC_BSPC,       KC_UP,      _______,   _______,     _______,    _______,  _______,             _______,
            _______,  _______,  _______,  _______,  _______,    _______,    _______,     _______,    KC_LEFT,       KC_DOWN,    KC_RGHT,   KC_ESC,      _______,              _______,             _______,
            _______,  _______,  _______,  _______,  _______,    _______,    _______,     _______,    KC_DELETE,     KC_TAB,     _______,   _______,              _______,  _______,
            _______,  _______,  _______,  _______,  _______,        _______,                         _______,             _______, _______, _______,  _______,  _______,  _______),
    

    [Symbols] = LAYOUT_91_ansi(
        CG_TOGG,  _______,  _______,    _______,    _______,    _______,    _______,     _______,    _______,    _______,       _______,   _______,   _______,    _______,  _______,  _______,   _______,
        _______,  _______,  _______,    _______,    _______,    _______,    _______,     _______,    _______,    _______,       _______,   _______,   _______,    _______,  _______,             _______,
        _______,  _______,  KC_LBRC,    KC_RBRC,    KC_EQUAL,   KC_DQUO,    _______,     _______,    _______,    _______,       _______,   _______,   _______,    _______,  _______,             _______,
        _______,  _______,  KC_LCBR,    KC_RCBR,    KC_BSLS,    KC_PIPE,    _______,     _______,    _______,    _______,       _______,   _______,   _______,              _______,             _______,
        _______,  _______,  KC_LABK,    KC_RABK,    KC_PLUS,    KC_PMNS,    _______,     _______,    _______,    _______,       _______,   _______,              _______,  _______,
        _______,  _______,  _______,    _______,    _______,        _______,                         _______,             _______, _______, _______,  _______,  _______,  _______),

    [Shortcuts] = LAYOUT_91_ansi(
        CG_TOGG,  _______,  _______,  _______,     _______,      _______,      _______,     _______,    _______,    _______,    _______,   _______,   _______,    _______,  _______,  _______,   _______,
        _______,  _______,  _______,  _______,     _______,      _______,      _______,     _______,    _______,    _______,    _______,   _______,   _______,    _______,  _______,             _______,
        _______,  _______,  _______,  _______,     _______,     LALT(KC_BSPC), _______,     _______,    _______,    _______,    _______,   _______,   _______,    _______,  _______,             _______,
        _______,  _______,  _______,  LGUI(KC_X), LGUI(KC_V),   LGUI(KC_C),     _______,     _______,    _______,    _______,    _______,   _______,   _______,              _______,             _______,
        _______,  _______,  _______,  _______,     _______,     LGUI(KC_Z),    _______,     _______,    _______,    _______,   _______,   _______,              _______,  _______,
        _______,  _______,  _______,  _______,     _______,        _______,                         _______,             _______, _______, _______,  _______,  _______,  _______)
    
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [Mouse]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(RM_VALD, RM_VALU) },
    [Arrows]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(RM_VALD, RM_VALU) },
    [Symbols]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(RM_VALD, RM_VALU) },
    [Shortcuts]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(RM_VALD, RM_VALU) },
};
#endif // ENCODER_MAP_ENABLE

const uint16_t PROGMEM mouse_layer[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM arrows_layer[] = {KC_A, KC_S, COMBO_END};

combo_t key_combos[] = {
    COMBO(mouse_layer, MO(Mouse)),
    COMBO(arrows_layer, MO(Arrows)),
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);

    if (layer > 0) {     

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_GREEN);
                }
            }
        }
    }
    return false;
}