/* Copyright 2015-2017 Jack Humbert
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

#include "planck.h"
#include "action_layer.h"
#include "keymap_runic.h"
#include "keymap_punctuation.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _DVORAK,
  _RUNIC,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  DVORAK = SAFE_RANGE,
  RUNIC,
  LOWER,
  RAISE,
  BACKLIT,
  SPACE_ONE,
  SPACE_TWO,
  SPACE_THREE,
  SPACE_FOUR,
  SPACE_FIVE,
  SPACE_SIX,
  SPACE_SEVEN,
  SPACE_EIGHT,
  SPACE_NINE,
  ZOOM_IN,
  ZOOM_OUT
};
/*
// Macros for GUI + Num
enum custom_keycodes {
    	SPACE_ONE = SAFE_RANGE,
	SPACE_TWO,
	SPACE_THREE,
	SPACE_FOUR,
	SPACE_FIVE,
	SPACE_SIX,
	SPACE_SEVEN,
	SPACE_EIGHT,
	SPACE_NINE
};
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | GUI  | Alt  |Lower |Space |Shift |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS},
  {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT },
  {BL_STEP, KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_RSFT, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |      |      |   ?  |   |  |   !  |   @  |   7  |   8  |   9  |   /  |   *  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  | Ctrl |  Alt |   ‽  |   \  |   #  |   $  |   4  |   5  |   6  |   -  | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |   ⸮  |      |   %  |   ^  |   1  |   2  |   3  |   +  |   |  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |   &  |   *  |      |   0  |   .  |   =  |   /  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, _______, _______, S(KC_SLSH), KC_PIPE, KC_EXLM, KC_AT,   KC_7,    KC_8,    KC_9,   KC_SLSH,   KC_ASTR},
  {KC_DEL,  KC_LCTL, KC_LALT, INBANG,     KC_BSLS, KC_HASH, KC_DLR,  KC_4,    KC_5,    KC_6,   KC_MINS,   KC_BSPC},
  {_______, _______, _______, PERCON,     _______, KC_PERC, KC_CIRC, KC_1,    KC_2,    KC_3,   S(KC_EQL), KC_PIPE},
  {_______, _______, _______, _______,    _______, KC_AMPR, KC_ASTR, _______, KC_0,    KC_DOT, KC_EQL,    KC_SLSH}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |   !  |   @  |   (  |   )  |   <  |   >  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F5  |  F6  |  F7  |  F8  |   #  |   $  |   [  |   ]  |Pg up |Pg Dn |   |  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Zoom +|  F9  | F10  | F11  |  F12 |   %  |   ^  |   {  |   }  | Vol- | Vol+ |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Zoom -|   ⸮  |   ‽  |   ?  |      |   &  |   *  |      |      | Next | Play |   \  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_EXLM, KC_AT,   KC_LPRN, KC_RPRN, KC_LABK, KC_RABK, KC_BSPC},
  {KC_DEL,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_HASH, KC_DLR,  KC_LBRC, KC_RBRC, KC_PGUP, KC_PGDN, KC_PIPE},
  {ZOOM_IN, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_VOLD, KC_VOLU, KC_SLSH},
  {ZOOM_OUT, PERCON, INBANG, S(KC_SLSH), _______, KC_AMPR, KC_ASTR, _______, _______, KC_MNXT, KC_MPLY, KC_BSLS}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Shift | Reset|      |      |      |      |      |Space7|Space8|Space9|Dvorak|  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Space4|Space5|Space6|Runic |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|Space1|Space2|Space3|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {KC_LSFT, RESET,   DEBUG,   _______, _______, _______, _______, SPACE_SEVEN, SPACE_EIGHT, SPACE_NINE,  DVORAK,  KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, SPACE_FOUR,  SPACE_FIVE,  SPACE_SIX,   RUNIC,   _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  SPACE_ONE,   SPACE_TWO,   SPACE_THREE, _______, TERM_ON},
  {_______, _______, _______, _______, _______, _______, _______, _______,     _______,     _______,     _______, TERM_OFF}
},

/* Runic
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   ᛈ  |   ᛇ  |   ᚠ  |   ᚷ  |   ᚲ  |   ᚱ  |   ᛚ  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   ᚨ  |   ᛟ  |   ᛖ  |   ᚢ  |   ᛁ  |   ᛞ  |   ᚺ  |   ᛏ  |   ᚾ  |   ᛊ  |  _   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   ᛜ  |   ᛃ  |   ᚲ  |   ᚦ  |   ᛒ  |   ᛗ  |   ᚹ  |   ᚹ  |   ᛉ  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_RUNIC] = {
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  RN_P,    RN_Y,    RN_F,    RN_G,    RN_KC,   RN_R,    RN_L,  KC_BSPC},
  {KC_ESC,  RN_A,    RN_O,    RN_E,    RN_U,    RN_I,    RN_D,    RN_H,    RN_T,    RN_N,    RN_S,  KC_UNDS},
  {KC_LSFT, KC_SCLN, RN_Q,    RN_J,    RN_KC,   RN_X,    RN_B,    RN_M,    RN_VW,   RN_VW,   RN_Z,  KC_ENT },
  {BACKLIT, KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP, KC_RGHT}
}

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        //print("mode just switched to dvorak and this is a huge string\n");
	set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case RUNIC:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_RUNIC);
	set_unicode_input_mode(UC_LNX);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
   // Workspace switching
   case SPACE_ONE:
      if (record->event.pressed) {
      SEND_STRING(SS_LGUI("1"));
      }
      return false;
      break;
   case SPACE_TWO:
      if (record->event.pressed) {
      SEND_STRING(SS_LGUI("2"));
      }
      return false;
      break;
   case SPACE_THREE:
      if (record->event.pressed) {
      SEND_STRING(SS_LGUI("3"));
      }
      return false;
      break;
   case SPACE_FOUR:
      if (record->event.pressed) {
      SEND_STRING(SS_LGUI("4"));
      }
      return false;
      break;
   case SPACE_FIVE:
      if (record->event.pressed) {
      SEND_STRING(SS_LGUI("5"));
      }
      return false;
      break;
      case SPACE_SIX:
      if (record->event.pressed) {
      SEND_STRING(SS_LGUI("6"));
      }
      return false;
      break;
   case SPACE_SEVEN:
      if (record->event.pressed) {
      SEND_STRING(SS_LGUI("7"));
      }
      return false;
      break;
   case SPACE_EIGHT:
      if (record->event.pressed) {
      SEND_STRING(SS_LGUI("8"));
      }
      return false;
      break;
   case SPACE_NINE:
      if (record->event.pressed) {
      SEND_STRING(SS_LGUI("9"));
      }
      return false;
      break;
   case ZOOM_IN:
      if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("+"));
      }
      return false;
      break;
   case ZOOM_OUT:
      if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("-"));
      }

  }
  return true;
}