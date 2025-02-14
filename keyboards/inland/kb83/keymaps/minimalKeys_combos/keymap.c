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
    WIN_B,
    WIN_SHORTS,
	MAC_B,
    MAC_SHORTS,
    Mouse,
    Arrows,
	NUMBERS,
    SYMBOLS
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define KC_SIRI LALT(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [WIN_B] = LAYOUT( /* Base */
		KC_ESC,     KC_BRID,   KC_BRIU,   KC_MAIL,         KC_WSCH,             KC_CALC,   KC_MSEL,   KC_MPRV,              KC_MPLY,              KC_MNXT,    KC_MUTE,    KC_VOLD,  KC_VOLU,  KC_DEL,       KC_MUTE, 
		KC_GRV,     KC_1,      KC_2,      KC_3,            KC_4,                KC_5,      KC_6,      KC_7,                 KC_8,                 KC_9,       KC_0,       KC_MINS,  KC_EQL,   KC_BSPC,      KC_HOME, 
		KC_TAB,     KC_Q,      KC_W,      KC_E,            KC_R,                KC_T,      KC_Y,      KC_U,                 KC_I,                 KC_O,       KC_P,       KC_LBRC,  KC_RBRC,  KC_BSLS,      KC_PGUP, 
		KC_CAPS,    KC_A,      KC_S,      LT(Arrows,KC_D), LT(Mouse,KC_F),      KC_G,      KC_H,      LT(SYMBOLS, KC_J),    LT(WIN_SHORTS,KC_K),                 KC_L,       KC_SCLN,  KC_QUOT,  KC_ENT,       KC_PGDN, 
		KC_LSFT,    KC_Z,      KC_X,      KC_C,            KC_V,                KC_B,      KC_N,      KC_M,                 KC_COMM,              KC_DOT,     KC_SLSH,    KC_RSFT,  KC_UP,    KC_END, 
		KC_LALT,    KC_LGUI,   KC_LCTL,              LT(NUMBERS, KC_SPC),                         KC_RALT,              MO(SYMBOLS), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT),
    
    [WIN_SHORTS] = LAYOUT( /* FN */
        _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, 
        _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, 
        _______, KC_LBRC, KC_RBRC, KC_EQUAL, KC_BSLS, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, 
        _______, KC_LCBR, KC_RCBR, KC_GRAVE, KC_QUES, _______, _______, _______, _______, _______, _______, _______, _______,                _______, 
        _______, KC_LABK, KC_RABK, KC_PLUS,  KC_UNDS, _______, _______, _______, _______, _______, _______, _______,               _______,  _______, 
        _______, _______, _______,                   _______,                            _______, _______, _______,      _______, _______, _______),

    [MAC_B] = LAYOUT( /* FN */
		KC_ESC,     KC_BRID,       KC_BRIU, KC_MCTL, KC_LPAD,   KC_SIRI, KC_F6,   KC_MPRV,             KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD,   KC_VOLU,  KC_DEL,   KC_MUTE, 
		KC_GRV,     KC_1,          KC_2,    KC_3,    KC_4,      KC_5,    KC_6,    KC_7,                KC_8,       KC_9,       KC_0,       KC_MINS,   KC_EQL,   KC_BSPC,  KC_HOME, 
		KC_TAB,     KC_Q,          KC_W,    KC_E,    KC_R,      KC_T,    KC_Y,    KC_U,                KC_I,       KC_O,       KC_P,       KC_LBRC,   KC_RBRC,  KC_BSLS,  KC_PGUP, 
		KC_CAPS,    KC_A,          KC_S,    LT(Arrows,KC_D),    LT(Mouse,KC_F),      KC_G,    KC_H,    LT(SYMBOLS, KC_J),   LT(MAC_SHORTS,KC_K),       KC_L,       KC_SCLN,    KC_QUOT,   KC_ENT,             KC_PGDN, 
		KC_LSFT,    KC_Z,          KC_X,    KC_C,    KC_V,      KC_B,    KC_N,    KC_M,                KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,   KC_UP,    KC_END, 
		KC_LCTL,    KC_LALT,       KC_LGUI,          LT(NUMBERS, KC_SPC),                               KC_RGUI,    MO(SYMBOLS), KC_RCTL,    KC_LEFT,   KC_DOWN,  KC_RGHT),

    [Mouse] = LAYOUT( /* Base */
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,       _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, 
		_______, _______, _______, _______, _______, _______, _______, MS_BTN1, MS_UP,   MS_BTN2, MS_ACL0, _______, _______, _______,       _______, 
		_______, _______, _______, _______, _______, _______, _______, MS_LEFT, MS_DOWN, MS_RGHT, MS_ACL1, _______, _______,                RM_NEXT, 
		_______, _______, _______, _______, _______, _______, _______, MS_WHLU, MS_WHLD, MS_WHLD, MS_ACL2, _______,               RM_VALU,  RM_PREV, 
		_______, GU_TOGG, _______,                   _______,                            _______, _______, _______,      RM_SPDD, RM_VALD, RM_SPDU),

    [Arrows] = LAYOUT( /* Base */
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,       _______, 
        _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,       _______, 
        _______, _______, _______, _______, _______, _______, _______, KC_BSPC,   KC_UP,   _______, _______, _______, _______, _______,       _______, 
        _______, _______, _______, _______, _______, _______, _______, KC_LEFT,   KC_DOWN, KC_RGHT, KC_ESC, _______, _______,                RM_NEXT, 
        _______, _______, _______, _______, _______, _______, _______, KC_DELETE, KC_TAB, _______, _______, _______,               RM_VALU,  RM_PREV, 
        _______, GU_TOGG, _______,                   _______,                            _______, _______, _______,      RM_SPDD, RM_VALD, RM_SPDU),
    
    [NUMBERS] = LAYOUT( /* FN */
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       RM_TOGG, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, 
		_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______,       _______, 
		_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______,                _______, 
		_______, KC_PIPE, KC_PMNS, KC_TILD, KC_DQUO, KC_QUOTE, _______, _______, _______, _______, _______, _______,               _______,  _______, 
		_______, _______, _______,                   _______,                            _______, _______, _______,      _______, _______, _______),
        
    [SYMBOLS] = LAYOUT( /* FN */
		_______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, 
		_______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, 
		_______, KC_LBRC, KC_RBRC, KC_EQUAL, KC_BSLS, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, 
		_______, KC_LCBR, KC_RCBR, KC_GRAVE, KC_QUES, _______, _______, _______, _______, _______, _______, _______, _______,                _______, 
		_______, KC_LABK, KC_RABK, KC_PLUS,  KC_UNDS, _______, _______, _______, _______, _______, _______, _______,               _______,  _______, 
		_______, _______, _______,                   _______,                            _______, _______, _______,      _______, _______, _______),


    
    [MAC_SHORTS] = LAYOUT( /* FN */
        _______, _______, _______,    _______,    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, 
        _______, _______, _______,    _______,    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, 
        _______, _______, _______,    _______,    LCTL(KC_BSPC), _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, 
        _______, _______, LCTL(KC_Z), LCTL(KC_V), LCTL(KC_C), _______, _______, _______, _______, _______, _______, _______, _______,                _______, 
        _______, _______, _______,    _______,    LCTL(KC_X), _______, _______, _______, _______, _______, _______, _______,               _______,  _______, 
        _______, _______, _______,                   _______,                            _______, _______, _______,      _______, _______, _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [WIN_B] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [Arrows] = { ENCODER_CCW_CW(RM_SATD, RM_SATU) },
    [MAC_B] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [NUMBERS] = { ENCODER_CCW_CW(RM_SATD, RM_SATU) },
    [SYMBOLS] = { ENCODER_CCW_CW(RM_SATD, RM_SATU) },

};
#endif

const uint16_t PROGMEM mouse_layer[] = {KC_F, KC_D, COMBO_END};
combo_t key_combos[] = {
    COMBO(mouse_layer, MO(Mouse)),
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state|default_layer_state)) {

        //Windows shorts
        case 1:
            //turn it all off
            for (uint8_t i = led_min; i < led_max; i++) {
                rgb_matrix_set_color(i, RGB_OFF);
            }
            rgb_matrix_set_color(30, RGB_PURPLE);
            rgb_matrix_set_color(31, RGB_PURPLE);
            rgb_matrix_set_color(32, RGB_PURPLE);
            rgb_matrix_set_color(33, RGB_PURPLE);
    
            rgb_matrix_set_color(45, RGB_PURPLE);
            rgb_matrix_set_color(46, RGB_PURPLE);
            rgb_matrix_set_color(47, RGB_PURPLE);
            rgb_matrix_set_color(48, RGB_PURPLE);
    
            rgb_matrix_set_color(59, RGB_PURPLE);
            rgb_matrix_set_color(60, RGB_PURPLE);
            rgb_matrix_set_color(61, RGB_PURPLE);
            rgb_matrix_set_color(62, RGB_PURPLE);
        //Mac SHORTS
        case 3:
            //turn it all off
            for (uint8_t i = led_min; i < led_max; i++) {
                rgb_matrix_set_color(i, RGB_OFF);
            }
            rgb_matrix_set_color(30, RGB_RED);
            rgb_matrix_set_color(31, RGB_RED);
            rgb_matrix_set_color(32, RGB_RED);
            rgb_matrix_set_color(33, RGB_RED);
    
            rgb_matrix_set_color(45, RGB_RED);
            rgb_matrix_set_color(46, RGB_RED);
            rgb_matrix_set_color(47, RGB_RED);
            rgb_matrix_set_color(48, RGB_RED);
    
            rgb_matrix_set_color(59, RGB_RED);
            rgb_matrix_set_color(60, RGB_RED);
            rgb_matrix_set_color(61, RGB_RED);
            rgb_matrix_set_color(62, RGB_RED);

            break;
        //Mouse
        case 4:
            //turn it all off
            for (uint8_t i = led_min; i < led_max; i++) {
                rgb_matrix_set_color(i, RGB_OFF);
            }

            // function keys
            for (uint8_t i = 1; i < 13; i++ ){
                rgb_matrix_set_color(i, RGB_BLUE);
            }
            
            rgb_matrix_set_color(36, RGB_GREEN);
            rgb_matrix_set_color(37, RGB_PURPLE);
            rgb_matrix_set_color(38, RGB_GREEN);
            rgb_matrix_set_color(39, RGB_BLUE);
            
            rgb_matrix_set_color(51, RGB_PURPLE);
            rgb_matrix_set_color(52, RGB_PURPLE);
            rgb_matrix_set_color(53, RGB_PURPLE);
            rgb_matrix_set_color(54, RGB_BLUE);
            
            rgb_matrix_set_color(65, RGB_GREEN);
            rgb_matrix_set_color(66, RGB_GREEN);
            rgb_matrix_set_color(67, RGB_GREEN);
            rgb_matrix_set_color(68, RGB_BLUE);

            break;


        //Arrows 
        case 5:
            //turn it all off
            for (uint8_t i = led_min; i < led_max; i++) {
                rgb_matrix_set_color(i, RGB_OFF);
            }
            
            // function keys
            for (uint8_t i = 1; i < 13; i++ ){
                rgb_matrix_set_color(i, RGB_BLUE);
            }

            // arrows and modifiers           
            rgb_matrix_set_color(36, RGB_GREEN);
            rgb_matrix_set_color(37, RGB_PURPLE);
            
            rgb_matrix_set_color(51, RGB_PURPLE);
            rgb_matrix_set_color(52, RGB_PURPLE);
            rgb_matrix_set_color(53, RGB_PURPLE);
            rgb_matrix_set_color(54, RGB_GREEN);

            rgb_matrix_set_color(65, RGB_GREEN);
            rgb_matrix_set_color(66, RGB_GREEN);


            break;

        //Numbers
        case 6:
            //turn it all off
            for (uint8_t i = led_min; i < led_max; i++) {
                rgb_matrix_set_color(i, RGB_OFF);
            }
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


            rgb_matrix_set_color(59, RGB_GREEN);
            rgb_matrix_set_color(60, RGB_GREEN);
            rgb_matrix_set_color(61, RGB_GREEN);
            rgb_matrix_set_color(62, RGB_GREEN);

            break;



        //Symbols
        case 7:
            //turn it all off
            for (uint8_t i = led_min; i < led_max; i++) {
                rgb_matrix_set_color(i, RGB_OFF);
            }
            rgb_matrix_set_color(30, RGB_GREEN);
            rgb_matrix_set_color(31, RGB_GREEN);
            rgb_matrix_set_color(32, RGB_GREEN);
            rgb_matrix_set_color(33, RGB_GREEN);

            rgb_matrix_set_color(45, RGB_GREEN);
            rgb_matrix_set_color(46, RGB_GREEN);
            rgb_matrix_set_color(47, RGB_GREEN);
            rgb_matrix_set_color(48, RGB_GREEN);
            
            rgb_matrix_set_color(59, RGB_GREEN);
            rgb_matrix_set_color(60, RGB_GREEN);
            rgb_matrix_set_color(61, RGB_GREEN);
            rgb_matrix_set_color(62, RGB_GREEN);
            break;

        //shorts
        case 8:
            //turn it all off
            for (uint8_t i = led_min; i < led_max; i++) {
                rgb_matrix_set_color(i, RGB_OFF);
            }
            rgb_matrix_set_color(30, RGB_BLUE);
            rgb_matrix_set_color(31, RGB_BLUE);
            rgb_matrix_set_color(32, RGB_BLUE);
            rgb_matrix_set_color(33, RGB_BLUE);

            rgb_matrix_set_color(40, RGB_BLUE);
            rgb_matrix_set_color(41, RGB_BLUE);
            rgb_matrix_set_color(42, RGB_BLUE);
            rgb_matrix_set_color(43, RGB_BLUE);

            rgb_matrix_set_color(50, RGB_BLUE);
            rgb_matrix_set_color(51, RGB_BLUE);
            rgb_matrix_set_color(52, RGB_BLUE);
            rgb_matrix_set_color(53, RGB_BLUE);
            break;

        default:
            break;
    }
    return false;
}