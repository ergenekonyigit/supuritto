/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2021 Ergenekon Yigit <@ergenekonyigit>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Layers
enum {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* qwerty
 * ,-----------------------------------------------,       ,-----------------------------------------------,
 * |  tab  |   q   |   w   |   e   |   r   |   t   |       |   y   |   u   |   i   |   o   |   p   | bkspc |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * | ctrl  |   a   |   s   |   d   |   f   |   g   |       |   h   |   j   |   k   |   l   |   ;   |   "   |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * | shift |   z   |   x   |   c   |   v   |   b   |       |   n   |   m   |   ,   |   .   |   /   | enter |
 * '-----------------------------------------------'       '-----------------------------------------------'
 *                         ,-----------------------,       ,-----------------------,
 *                         |  cmd  | lower | space |       | space | raise |  alt  |
 *                         '-----------------------'       '-----------------------'
 */
  [_QWERTY] = LAYOUT_split_3x6_3(
    KC_TAB,           KC_Q,  KC_W,  KC_E,     KC_R,        KC_T,       KC_Y,    KC_U,        KC_I,     KC_O,    KC_P,     KC_BSPC,
    CTL_T(KC_ESC),    KC_A,  KC_S,  KC_D,     KC_F,        KC_G,       KC_H,    KC_J,        KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
    KC_LSFT,          KC_Z,  KC_X,  KC_C,     KC_V,        KC_B,       KC_N,    KC_M,        KC_COMM,  KC_DOT,  KC_SLSH,  KC_ENT,
                                    KC_LGUI,  MO(_LOWER),  KC_SPC,     KC_SPC,  MO(_RAISE),  KC_RALT
  ),

/* lower
 * ,-----------------------------------------------,       ,-----------------------------------------------,
 * |       |   '   |   "   |   ^   |   ?   |   `   |       |   [   |   <   |   =   |   >   |   ]   |       |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * | ctrl  |   !   |   @   |   #   |   $   |   %   |       |   {   |   (   |   :   |   )   |   }   |       |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * | shift |   \   |   ~   |   |   |   &   |   ;   |       |   /   |   *   |   -   |   +   |   _   |       |
 * '-----------------------------------------------'       '-----------------------------------------------'
 *                         ,-----------------------,       ,-----------------------,
 *                         |  cmd  |       | space |       | space |       |  alt  |
 *                         '-----------------------'       '-----------------------'
 */
  [_LOWER] = LAYOUT_split_3x6_3(
      _______,  KC_QUOT,  KC_DQUO,  KC_CIRC,  KC_QUES,  KC_GRV,      KC_LBRC,  KC_LT,    KC_EQL,   KC_GT,    KC_RBRC,  _______,
      KC_LCTL,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,     KC_LCBR,  KC_LPRN,  KC_COLN,  KC_RPRN,  KC_RCBR,  _______,
      KC_LSFT,  KC_BSLS,  KC_TILD,  KC_PIPE,  KC_AMPR,  KC_SCLN,     KC_PSLS,  KC_PAST,  KC_PMNS,  KC_PPLS,  KC_UNDS,  _______,
                                    KC_LGUI,  _______,  KC_SPC,      KC_SPC,   _______,  KC_RALT
  ),

/* raise
 * ,-----------------------------------------------,       ,-----------------------------------------------,
 * |  tab  |       |       |   1   |   2   |   3   |       | shift | shift | shift | shift |       |       |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * | ctrl  |       |       |   4   |   5   |   6   |       | left  | down  |  up   | right |       |       |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * | shift |  alt  |  cmd  |   7   |   8   |   9   |       | prev  | vol - | vol + | next  |       | play  |
 * '-----------------------------------------------'       '-----------------------------------------------'
 *                         ,-----------------------,       ,-----------------------,
 *                         |   0   |       | space |       | space |       |  alt  |
 *                         '-----------------------'       '-----------------------'

 */
  [_RAISE] = LAYOUT_split_3x6_3(
      KC_TAB,   _______,  _______,  KC_1,  KC_2,     KC_3,       KC_RSFT,  KC_RSFT,  KC_RSFT,  KC_RSFT,  _______,  _______,
      KC_LCTL,  _______,  _______,  KC_4,  KC_5,     KC_6,       KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,
      KC_LSFT,  KC_LALT,  KC_LGUI,  KC_7,  KC_8,     KC_9,       KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  _______,  KC_MPLY,
                                    KC_0,  _______,  KC_SPC,     KC_SPC,   _______,  KC_RALT
  ),

/* adjust (lower + raise)
 * ,-----------------------------------------------,       ,-----------------------------------------------,
 * |       |  F1   |  F2   |  F3   |  F4   |       |       |   1   |   2   |   3   |       |       |       |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * |       |  F5   |  F6   |  F7   |  F8   |       |       |   4   |   5   |   6   |       |       | reset |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * |       |  F9   |  F10  |  F11  |  F12  |       |       |   7   |   8   |   9   |       |       |eep rst|
 * '-----------------------------------------------'       '-----------------------------------------------'
 *                         ,-----------------------,       ,-----------------------,
 *                         |       |       |       |       |       |       |   0   |
 *                         '-----------------------'       '-----------------------'
 */
  [_ADJUST] = LAYOUT_split_3x6_3(
      _______,  KC_F1,  KC_F2,   KC_F3,   KC_F4,    _______,     KC_1,     KC_2,     KC_3,  _______,  _______,  _______,
      _______,  KC_F5,  KC_F6,   KC_F7,   KC_F8,    _______,     KC_4,     KC_5,     KC_6,  _______,  _______,  RESET,
      _______,  KC_F9,  KC_F10,  KC_F11,  KC_F12,   _______,     KC_7,     KC_8,     KC_9,  _______,  _______,  EEP_RST,
                                 _______,  _______, _______,     _______,  _______,  KC_0
  )
};

// Enable the adjust layer when both lower and raise
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
