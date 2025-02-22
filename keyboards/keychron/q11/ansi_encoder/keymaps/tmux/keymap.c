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
    TMUX
};

enum custom_keycodes {
    tmux_0 = SAFE_RANGE,
    tmux_1,
    tmux_2,
    tmux_3,
    tmux_4,
    tmux_5,
    tmux_rename,
    tmux_create,
    tmux_horizontal,
    tmux_vertical,
    tmux_pane_to_window,
    tmux_next_pane,
    tmux_close_window,
    tmux_copy,
    tmux_close_pane,
  };

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_91_ansi(
        KC_MPLY,  KC_ESC,   KC_BRID,            KC_BRIU,  KC_MCTL,  KC_LPAD,  RM_VALD,   RM_VALU,  KC_MPRV,             KC_MPLY,             KC_MNXT,       KC_MUTE,        KC_VOLD,                KC_VOLU,  KC_INS,   KC_DEL,   KC_MUTE,
        RM_TOGG,  KC_GRV,   KC_1,               KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,                KC_8,                KC_9,          KC_0,           KC_MINS,                KC_EQL,   KC_BSPC,            KC_PGUP,
        RM_NEXT,  KC_ESC,   KC_Q,               KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,                KC_I,                KC_O,          KC_P,           KC_LBRC,                KC_RBRC,  KC_BSLS,            KC_PGDN,
        RM_PREV,  KC_TAB,   KC_A,               KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     LT(Symbols,KC_J),    LT(Shortcuts,KC_K),  KC_L,          KC_SCLN,        KC_QUOT,                KC_ENT,             KC_HOME,
        RM_VALU,  KC_LSFT,                      KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,                KC_M,                MT(MOD_LGUI,   KC_COMM),       MT(MOD_LALT, KC_DOT),   MT(MOD_LCTL, KC_SLSH),              KC_RSFT,  KC_UP,
        RM_VALD,  KC_LCTL,  MO(Symbols),        KC_LOPT,  KC_LCMD,       LSFT_T(KC_SPC),                           KC_ENT,              LCTL(KC_TAB),  LGUI(KC_TAB),   LALT(KC_BSPC),           KC_LEFT,  KC_DOWN,  KC_RGHT),

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
        _______,  _______,  _______,  _______,  _______,    _______,    _______,     _______,    KC_BSPC,       KC_UP,      KC_PGUP,   _______,     _______,    _______,  _______,             _______,
        _______,  _______,  _______,  _______,  _______,    _______,    _______,     _______,    KC_LEFT,       KC_DOWN,    KC_RGHT,   KC_ESC,      _______,              _______,             _______,
        _______,  _______,  _______,  _______,  _______,    _______,    _______,     _______,    KC_DELETE,     KC_TAB,     KC_PGDN,   _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,        _______,                         _______,             _______, _______, _______,  _______,  _______,  _______),
    

    [Symbols] = LAYOUT_91_ansi(
        _______,  CG_TOGG,  _______,         _______,         _______,        _______,            _______,     _______,    _______,    _______,       _______,    _______,    _______,    _______,  _______,  _______,   _______,
        _______,  _______,  _______,         _______,         _______,        _______,            _______,     _______,    _______,    _______,       _______,    _______,    _______,    _______,  _______,  _______,
        _______,  _______,  KC_LBRC,         KC_RBRC,         KC_EQUAL,       KC_DQUO,            _______,     _______,    _______,    _______,       _______,    _______,    _______,    _______,  _______,  _______,
        _______,  _______,  KC_LCBR,         KC_RCBR,         KC_BSLS,        KC_PIPE,            _______,     _______,    _______,    _______,       _______,    _______,    _______,    _______,  _______,
        _______,  _______,  KC_LABK,         KC_RABK,         KC_PLUS,        KC_PMNS,            _______,     _______,    _______,    _______,       _______,    _______,    _______,    _______,
        _______,  _______,  _______,         _______,         _______,        _______,                                     _______,    _______,       _______,    _______,    _______,    _______,  _______),

    [Shortcuts] = LAYOUT_91_ansi(
        _______,  CG_TOGG,  _______,        _______,          _______,         _______,           _______,     _______,    _______,           _______,            _______,            _______,                _______,                _______,  _______,  _______,   _______,
        _______,  _______,  _______,        _______,          _______,         _______,           _______,     _______,    _______,           _______,            _______,            _______,                _______,                _______,  _______,  _______,
        _______,  _______,  LCTL(KC_C),     SGUI(KC_BSPC),    LSFT(KC_UP),     LGUI(KC_C),        _______,     _______,    _______,           _______,            _______,            _______,                _______,                _______,  _______,  _______,
        _______,  _______,  LCTL(KC_R),     LGUI(KC_LEFT),    LSFT(KC_DOWN),   LGUI(KC_RGHT),     _______,     _______,    _______,           _______,            _______,            _______,                _______,                _______,  _______,
        _______,  _______,  _______,        LGUI(KC_Z),       LGUI(KC_X),      LGUI(KC_V),        _______,     _______,    _______,           _______,            _______,            _______,                _______,                _______,
        _______,  _______,  _______,        _______,          _______,         _______,                                    _______,           _______,            _______,            _______,                _______,                _______,  _______),
    
    [TMUX] = LAYOUT_91_ansi(
        _______,  CG_TOGG,  _______,         _______,         _______,         _______,           _______,      _______,     _______,         _______,            _______,            _______,                _______,                _______,  _______,  _______,   _______,
        _______,  _______,  _______,         _______,         _______,         _______,           _______,      _______,     _______,         _______,            _______,            _______,                _______,                _______,   _______,  _______,
        _______,  _______,  _______,         _______,         _______,         _______,           _______,      tmux_0,      tmux_1,          tmux_2,             tmux_3,             tmux_4,                 tmux_5,                 _______,  _______,  _______,
        _______,  _______,  _______,         _______,         _______,         _______,           _______,      _______,     tmux_create,     tmux_copy,          tmux_rename,        _______,                tmux_close_window,      _______,  _______,
        _______,  _______,  _______,         _______,         _______,         _______,           _______,      _______,     tmux_next_pane,  tmux_vertical,      tmux_horizontal,    tmux_pane_to_window,    tmux_close_pane,        _______,
        _______,  _______,  _______,         _______,         _______,         _______,                                      _______,         _______,            _______,            _______,                _______,                _______,  _______)
    
    };

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [Mouse]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(RM_VALD, RM_VALU) },
    [Arrows]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(RM_VALD, RM_VALU) },
    [Symbols]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(RM_VALD, RM_VALU) },
    [Shortcuts]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(RM_VALD, RM_VALU) },
    [TMUX]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(RM_VALD, RM_VALU) },

};
#endif // ENCODER_MAP_ENABLE

const uint16_t PROGMEM mouse_layer[] = {LSFT_T(KC_SPC), KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM arrows_layer[] = {LSFT_T(KC_SPC), KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM TMUX_layer[] = {LSFT_T(KC_SPC), KC_W, KC_E, COMBO_END};

combo_t key_combos[] = {
    COMBO(mouse_layer, MO(Mouse)),
    COMBO(arrows_layer, MO(Arrows)),
    COMBO(TMUX_layer, MO(TMUX)),
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // These macros are speicif to the TMUX layer.  Ignore them if not on that layer.
    if(IS_LAYER_ON(TMUX)){
    
      switch (keycode) {
          case tmux_0:  // go to session 0
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("0");
              }
            return true;
          case tmux_1:  // go to session 1
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("1");
              }
            return true;
          case tmux_2: // go to session 2
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("2");
            }
            return true;
          case tmux_3:  // go to session 3
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("3");
            }
            return true;
          case tmux_4:  // go to session 4
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("4");
            }
            return true;
          case tmux_5:  // go to session 5
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("5");
            }
            return true;
          case tmux_rename: // rename tmux window
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING(",");
            }
            return true;
          case tmux_create:  // create new tmux window
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("c");
            }
            return true;
          case tmux_horizontal:  // split window into horizontal panals
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("\"");
            }
            return true;
          case tmux_vertical:  // split winmdow into vertical panels
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("%");
            }
            return true;
            // convert pane to window
          case tmux_pane_to_window:  // move pane to window
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("!");
            }
            return true;
            // next pane
          case tmux_next_pane:  // go to next pane
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("o");
            }
            return true;
            // close window
          case tmux_close_window:  // close current window
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("&");
            }
            return true;
          case tmux_close_pane: // enter copy mode  
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("x");
            }
            return true;
          case tmux_copy: // enter copy mode  
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("[");
            }
            return true;
      }
    }
      return true;
}

/*
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  //debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}
*/