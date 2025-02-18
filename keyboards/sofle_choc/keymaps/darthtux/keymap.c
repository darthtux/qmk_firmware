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
    MAC_SHORTS,
    TMUX
};

enum custom_keycodes {
    tmux_0,
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
    tmux_cursor_up,
    tmux_cursor_down,
    tmux_history_top
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
    KC_LCTL,  KC_LALT,  KC_LGUI, MT(MOD_LSFT,KC_SPC),  KC_LSFT,                                KC_BSPC,  KC_ENT,                 LALT(KC_BSPC),                KC_RGUI,                    KC_RCTL
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
    CG_TOGG,    _______,      _______,        _______,        _______,           _______,                             _______,    _______,    _______,    _______,    _______,      _______,
    _______,    _______,      SGUI(KC_BSPC),  LGUI(KC_LEFT),  LGUI(KC_RGHT),     _______,                             _______,    _______,    _______,    _______,    _______,      _______,
    _______,    _______,      LGUI(KC_X),     LGUI(KC_V),     LGUI(KC_C),        _______,                             _______,    _______,    _______,    _______,    _______,      _______,
    _______,    _______,      _______,        _______,        LGUI(KC_Z),        _______,   KC_MPLY, KC_MUTE,         _______,    _______,    _______,    _______,    _______,      _______,
    _______,    _______,      _______,        _______,        _______,                                                _______,    _______,    _______,    _______,    _______
),
[TMUX] = LAYOUT(
    _______,    _______,      _______,        _______,        _______,     _______,                             _______,            _______,        _______,          _______,              _______,            _______,
    _______,    _______,      _______,        _______,        _______,     _______,                             tmux_0,             tmux_1,         tmux_2,           tmux_3,               tmux_4,             tmux_5,
    _______,    _______,      _______,        _______,        _______,     _______,                             tmux_horizontal,    tmux_create,    tmux_rename,      tmux_pane_to_window,  tmux_next_pane,     tmux_vertical,
    _______,    _______,      _______,        _______,        _______,     _______,   KC_MPLY, KC_MUTE,         tmux_history_top,   tmux_copy,      tmux_cursor_up,   tmux_cursor_down,     _______,            tmux_close_window,
    _______,    _______,      _______,        _______,        _______,                                                _______,    _______,    _______,    _______,    _______
)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [Base] = {  ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [Mouse] = {  ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [Arrows] = {  ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [SYMBOLS] = {  ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_SHORTS] = {  ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [TMUX] = {  ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif


const uint16_t PROGMEM mouse_layer[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM arrows_layer[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM TMUX_layer[] = {KC_W, KC_E, COMBO_END};


combo_t key_combos[] = {
    COMBO(mouse_layer, MO(Mouse)),
    COMBO(arrows_layer, MO(Arrows)),
    COMBO(TMUX_layer, MO(TMUX)),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // These macros are speicif to the TMUX layer.  Ignore them if not on that layer.
    if(IS_LAYER_ON(TMUX)){
    
      switch (keycode) {
          case tmux_0:  // go to session 0
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("0");
              }
            return false;
          case tmux_1:  // go to session 1 not workihng for some reason
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("1");
              }
            return false;
          case tmux_2: // go to session 2
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("2");
            }
            return false;
          case tmux_3:  // go to session 3
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("3");
            }
            return false;
          case tmux_4:  
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("4");
            }
            return false;
          case tmux_5:  
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("5");
            }
            return false;
          case tmux_rename: 
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING(",");
            }
            return false;
          case tmux_create:  
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("c");
            }
            return false;
          case tmux_horizontal:  
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("\"");
            }
            return false;
          case tmux_vertical:  
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("%");
            }
            return false;
            // convert pane to window
          case tmux_pane_to_window:  
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("!");
            }
            return false;
            // next pane
          case tmux_next_pane:  
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("o");
            }
            return false;
            // close window
          case tmux_close_window:  
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("&");
            }
            return false;
            // enter copy mode
          case tmux_copy:  
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("[");
            }
            return false;
            // curor up
          case tmux_cursor_up:  
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("k");
            }
            return false;
            // cursor down
          case tmux_cursor_down:  
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("j");
            }
            return false;
            // top of history
          case tmux_history_top:  
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b") SS_DELAY(20));
              SEND_STRING("g");
            }
            return false;
      }
    }
      return true;
}