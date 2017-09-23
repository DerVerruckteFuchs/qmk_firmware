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
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS},
  {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT },
  {BL_STEP, KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   7  |   8  |   9  |   /  |   *  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   4  |   5  |   6  |   -  | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   &  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   1  |   2  |   3  |   +  |ISO | |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   0  |   .  |   =  |ISO ~ |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_7,    KC_8,    KC_9,    KC_PSLS,  KC_PAST},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_4,    KC_5,    KC_6,    KC_PMNS,  KC_BSPC},
  {KC_AMPR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_1,    KC_2,    KC_3,    KC_PPLS, S(KC_NUBS)},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_PDOT, KC_PEQL,  S(KC_NUHS)}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |   !  |   @  |   (  |   )  |   <  |   >  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F5  |  F6  |  F7  |  F8  |   #  |   $  |   [  |   ]  |Pg up |Pg Dn |   |  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F9  | F10  | F11  |  F12 |   %  |   ^  |   {  |   }  | Vol- | Vol+ |ISO \ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |   &  |   *  |      |      | Next | Play |ISO # |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_EXLM, KC_AT,   KC_LPRN, KC_RPRN, KC_LABK, KC_RABK, KC_BSPC},
  {KC_DEL,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_HASH, KC_DLR,  KC_LBRC, KC_RBRC, KC_PGUP, KC_PGDN, KC_PIPE},
  {_______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_VOLD, KC_VOLU, KC_NUBS},
  {_______, _______, _______, _______, _______, KC_AMPR, KC_ASTR, _______, _______, KC_MNXT, KC_MPLY, KC_NUHS}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Dvorak|Runic |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, DVORAK,  RUNIC,   _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
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
  }
  return true;
}
