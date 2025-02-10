/* Copyright (C) 2022 jonylee@hfd
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
// clang-format off
enum __layers {
	MAC_B,
	WIN_B,
    MOVE,
	NUMBERS,
    SYMBOLS
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define KC_SIRI LALT(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [WIN_B] = LAYOUT( /* Base */
		KC_ESC,     KC_BRID,   KC_BRIU,   KC_MAIL,   KC_WSCH,   KC_CALC,   KC_MSEL,   KC_MPRV,   KC_MPLY,              KC_MNXT,    KC_MUTE,    KC_VOLD,  KC_VOLU,  KC_DEL,       KC_MUTE, 
		KC_GRV,     KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,                 KC_9,       KC_0,       KC_MINS,  KC_EQL,   KC_BSPC,      KC_HOME, 
		KC_TAB,     KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,                 KC_O,       KC_P,       KC_LBRC,  KC_RBRC,  KC_BSLS,      KC_PGUP, 
		KC_CAPS,    LT(MOVE,KC_A),        KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      LT(SYMBOLS, KC_J),    KC_K,       KC_L,       KC_SCLN,  KC_QUOT,  KC_ENT,       KC_PGDN, 
		KC_LSFT,    KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,              KC_DOT,     KC_SLSH,    KC_RSFT,  KC_UP,    KC_END, 
		KC_LALT,    KC_LGUI,   KC_LCTL,              LT(MAC_FN, KC_SPC),                         KC_RALT,              MO(MAC_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_B] = LAYOUT( /* FN */
		KC_ESC,     KC_BRID,       KC_BRIU, KC_MCTL, KC_LPAD,   KC_SIRI, KC_F6,   KC_MPRV,             KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD,   KC_VOLU,  KC_DEL,   KC_MUTE, 
		KC_GRV,     KC_1,          KC_2,    KC_3,    KC_4,      KC_5,    KC_6,    KC_7,                KC_8,       KC_9,       KC_0,       KC_MINS,   KC_EQL,   KC_BSPC,  KC_HOME, 
		KC_TAB,     KC_Q,          KC_W,    KC_E,    KC_R,      KC_T,    KC_Y,    KC_U,                KC_I,       KC_O,       KC_P,       KC_LBRC,   KC_RBRC,  KC_BSLS,  KC_PGUP, 
		KC_CAPS,   LT(MOVE,KC_A),  KC_S,    KC_D,    KC_F,      KC_G,    KC_H,    LT(SYMBOLS, KC_J),   KC_K,       KC_L,       KC_SCLN,    KC_QUOT,   KC_ENT,             KC_PGDN, 
		KC_LSFT,    KC_Z,          KC_X,    KC_C,    KC_V,      KC_B,    KC_N,    KC_M,                KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,   KC_UP,    KC_END, 
		KC_LCTL,    KC_LALT,       KC_LGUI,          LT(MAC_FN, KC_SPC),                               KC_RGUI,    MO(MAC_FN), KC_RCTL,    KC_LEFT,   KC_DOWN,  KC_RGHT),

    [MOVE] = LAYOUT( /* Base */
		PDF(MAC_B), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,       RM_TOGG, 
		_______, _______, _______, _______, _______, _______, _______, MS_ACL0, MS_ACL1, MS_ACL2, _______, _______, _______, _______,       _______, 
		_______, _______, KC_BSPC, KC_UP,   KC_DEL,  _______, _______, MS_BTN1, MS_UP,   MS_BTN2, _______, _______, _______, _______,       _______, 
		_______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, MS_LEFT, MS_DOWN, MS_RGHT, _______, _______, _______,                RM_NEXT, 
		_______, _______, KC_TAB,  KC_ESC,  _______, _______, _______, MS_WHLU, _______, MS_WHLD, _______, _______,               RM_VALU,  RM_PREV, 
		_______, GU_TOGG, _______,                   _______,                            _______, _______, _______,      RM_SPDD, RM_VALD, RM_SPDU),

    [NUMBERS] = LAYOUT( /* FN */
		PDF(WIN_B), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       RM_TOGG, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, 
		_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______,       _______, 
		_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______,                _______, 
		_______, KC_PIPE, KC_PMNS, KC_TILD, KC_DQUO, KC_QUOTE, _______, _______, _______, _______, _______, _______,               _______,  _______, 
		_______, _______, _______,                   _______,                            _______, _______, _______,      _______, _______, _______),
        
    [SYMBOLS] = LAYOUT( /* FN */
		_______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,       RM_TOGG, 
		_______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, 
		_______, KC_LBRC, KC_RBRC, KC_EQUAL, KC_BSLS, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, 
		_______, KC_LCBR, KC_RCBR, KC_GRAVE, KC_QUES, _______, _______, _______, _______, _______, _______, _______, _______,                _______, 
		_______, KC_LABK, KC_RABK, KC_PLUS,  KC_UNDS, _______, _______, _______, _______, _______, _______, _______,               _______,  _______, 
		_______, _______, _______,                   _______,                            _______, _______, _______,      _______, _______, _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [WIN_B] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN] = { ENCODER_CCW_CW(RM_SATD, RM_SATU) },
    [MAC_B] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN] = { ENCODER_CCW_CW(RM_SATD, RM_SATU) },
};
#endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case 1:
            for (uint8_t i = led_min; i < led_max; i++) {
                rgb_matrix_set_color(i, RGB_RED);
            }
            break;
        case 2:
            //turn it all off
            for (uint8_t i = led_min; i < led_max; i++) {
                rgb_matrix_set_color(i, RGB_OFF);
            }
            
            // pdf change to windows layer
            rgb_matrix_set_color(0, RGB_RED);

            //characters
            rgb_matrix_set_color(30, RGB_GREEN);
            rgb_matrix_set_color(31, RGB_GREEN);
            rgb_matrix_set_color(32, RGB_GREEN);
            rgb_matrix_set_color(33, RGB_GREEN);
            rgb_matrix_set_color(34, RGB_GREEN);
            rgb_matrix_set_color(35, RGB_GREEN);
            rgb_matrix_set_color(36, RGB_GREEN);
            rgb_matrix_set_color(37, RGB_GREEN);
            rgb_matrix_set_color(38, RGB_GREEN);
            rgb_matrix_set_color(39, RGB_GREEN);

            // numbers
            rgb_matrix_set_color(45, RGB_BLUE);
            rgb_matrix_set_color(46, RGB_BLUE);
            rgb_matrix_set_color(47, RGB_BLUE);
            rgb_matrix_set_color(48, RGB_BLUE);
            rgb_matrix_set_color(49, RGB_BLUE);
            rgb_matrix_set_color(50, RGB_BLUE);
            rgb_matrix_set_color(51, RGB_BLUE);
            rgb_matrix_set_color(52, RGB_BLUE);
            rgb_matrix_set_color(53, RGB_BLUE);
            rgb_matrix_set_color(54, RGB_BLUE);

            // specials
            rgb_matrix_set_color(59, RGB_GREEN);
            rgb_matrix_set_color(60, RGB_GREEN);
            rgb_matrix_set_color(61, RGB_GREEN);
            rgb_matrix_set_color(62, RGB_GREEN);
            rgb_matrix_set_color(63, RGB_GREEN);


            break;
        case 3:
            //turn it all off
            for (uint8_t i = led_min; i < led_max; i++) {
                rgb_matrix_set_color(i, RGB_OFF);
            }
            
            // pdf change to windows layer
            rgb_matrix_set_color(0, RGB_RED);
            

            // function keys
            for (uint8_t i = 1; i < 13; i++ ){
                rgb_matrix_set_color(i, RGB_BLUE);
            }
            
            // mouse acceleration
            rgb_matrix_set_color(21, RGB_GREEN);
            rgb_matrix_set_color(22, RGB_GREEN);
            rgb_matrix_set_color(23, RGB_GREEN);
            rgb_matrix_set_color(36, RGB_GREEN);
            rgb_matrix_set_color(37, RGB_GREEN);
            rgb_matrix_set_color(38, RGB_GREEN);
            rgb_matrix_set_color(51, RGB_GREEN);
            rgb_matrix_set_color(52, RGB_GREEN);
            rgb_matrix_set_color(53, RGB_GREEN);
            rgb_matrix_set_color(65, RGB_GREEN);
            rgb_matrix_set_color(67, RGB_GREEN);

            // Move
            rgb_matrix_set_color(31, RGB_TEAL);
            rgb_matrix_set_color(32, RGB_TEAL);
            rgb_matrix_set_color(33, RGB_TEAL);
            rgb_matrix_set_color(46, RGB_TEAL);
            rgb_matrix_set_color(47, RGB_TEAL);
            rgb_matrix_set_color(48, RGB_TEAL);
            rgb_matrix_set_color(60, RGB_TEAL);
            rgb_matrix_set_color(61, RGB_TEAL);

            // RGB
            rgb_matrix_set_color(57, RGB_YELLOW);
            rgb_matrix_set_color(70, RGB_YELLOW);
            rgb_matrix_set_color(71, RGB_YELLOW);
            rgb_matrix_set_color(79, RGB_YELLOW);
            rgb_matrix_set_color(80, RGB_YELLOW);
            rgb_matrix_set_color(81, RGB_YELLOW);
            
            // Misc
            rgb_matrix_set_color(73, RGB_RED);
            

            break;
        default:
            break;
    }
    return false;
}