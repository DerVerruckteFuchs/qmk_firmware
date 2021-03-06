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
//#include "keymap_runic.h"
//#include "keymap_punctuation.h"
//#include "keymap_fraktur.h"
#include "keymap_unicode.h"

//#define UNICODE_SONG_OSX  COIN_SOUND
//#define UNICODE_SONG_LNX  UNICODE_LINUX
//#define UNICODE_SONG_BSD  MARIO_GAMEOVER
//#define UNICODE_SONG_WIN  UNICODE_WINDOWS
//#define UNICODE_SONG_WINC UNICODE_WINDOWS

extern keymap_config_t keymap_config;

uint8_t OS_DETECT(void) {
	#ifdef _WIN32
		return UC_WINC; // requires WinCompose
	#elif __APPLE__
		return UC_OSX; // requires going to System Preferences -> Keyboard -> Input Sources, and enable Unicode Hex.
		//return UC_OSX_RALT;
	#elif __linux__
		return UC_LNX; // requires ibus
	#endif
		return EXIT_FAILURE;
}

void eeconfig_init_user(void) {
  set_unicode_input_mode(OS_DETECT());
}

enum planck_layers {
  _DVORAK,
  _RUNIC,
  //_FRAK,
  //_FRAKC,
  //_CURS,
  //_CURSC,
  _GAME,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  DVORAK = SAFE_RANGE,
  RUNIC,
  //FRAK,
  //FRAKC,
  //CURS,
  //CURSC,
  GAME,
  LOWER,
  RAISE,
  BACKLIT,
  TTY,
  /*SPACE_ONE,
  SPACE_TWO,
  SPACE_THREE,
  SPACE_FOUR,
  SPACE_FIVE,
  SPACE_SIX,
  SPACE_SEVEN,
  SPACE_EIGHT,
  SPACE_NINE,*/
  ZOOM_IN,
  ZOOM_OUT,
  //TERM
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
 * | Ctrl | TERM | Alt  | GUI  |Lower |Space |Shift |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS},
  {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT },
  {KC_LCTL, LCTL(LALT(KC_T)), KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_RSFT, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
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
  {KC_DEL,  KC_LCTL, KC_LALT, X(INBANG),     KC_BSLS, KC_HASH, KC_DLR,  KC_4,    KC_5,    KC_6,   KC_MINS,   KC_BSPC},
  {_______, _______, _______, X(PERCON),     _______, KC_PERC, KC_CIRC, KC_1,    KC_2,    KC_3,   S(KC_EQL), KC_PIPE},
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
 * |Zoom -| BLDEC| BLINC|  TTY |      |   &  |   *  |      |      | Next | Play |   \  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_EXLM, KC_AT,   KC_LPRN, KC_RPRN, KC_LABK, KC_RABK, KC_BSPC},
  {KC_DEL,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_HASH, KC_DLR,  KC_LBRC, KC_RBRC, KC_PGUP, KC_PGDN, KC_PIPE},
  {LCTL(S(KC_EQL)), KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_VOLD, KC_VOLU, KC_SLSH},
  {LCTL(KC_MINS), BL_DEC, BL_INC,  LCTL(KC_LALT),    _______, KC_AMPR, KC_ASTR, _______, _______, KC_MNXT, KC_MPLY, KC_BSLS}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Shift | Reset| Debug|      |      |      |      |Space7|Space8|Space9|Dvorak|  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Space4|Space5|Space6|Runic | Game |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|Space1|Space2|Space3| FRAK |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F13 |  F14 |  F15 |  F16 |      |             |      |  F17 | F18  | F19  | F20  |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {KC_LSFT, RESET,   DEBUG,   _______, _______, _______, _______, LGUI(KC_7), LGUI(KC_8), LGUI(KC_9),  DVORAK,  KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, LGUI(KC_4), LGUI(KC_5), LGUI(KC_6),   RUNIC,   GAME},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), _______,    _______},
  {KC_F13,  KC_F14,  KC_F15,  KC_F16,  _______, _______, _______, _______,     KC_F17,      KC_F18,      KC_F19,  KC_F20}
},

/* Runic
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   ᛈ  |   ᛇ  |   ᚠ  |   ᚷ  |   ᚲ  |   ᚱ  |   ᛚ  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   ᚨ  |   ᛟ  |   ᛖ  |   ᚢ  |   ᛁ  |   ᛞ  |   ᚺ  |   ᛏ  |   ᚾ  |   ᛋ  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   ᛜ  |   ᛃ  |   ᚲ  |   ᚦ  |   ᛒ  |   ᛗ  |   ᚹ  |   ᚹ  |   ᛉ  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | TERM | Alt  | GUI  |Lower |Space |Shift |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */

[_RUNIC] = {
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  X(RN_P), X(RN_Y), X(RN_F), X(RN_G), X(RN_KC),X(RN_R), X(RN_L),  KC_BSPC},
  {KC_ESC,  X(RN_A), X(RN_O), X(RN_E), X(RN_U), X(RN_I), X(RN_D), X(RN_H), X(RN_T), X(RN_N), X(RN_S),  KC_MINS},
  {KC_LSFT, KC_SCLN, X(RN_Q), X(RN_J), X(RN_KC),X(RN_X), X(RN_B), X(RN_M), X(RN_VW),X(RN_VW),X(RN_Z),  KC_ENT },
  {KC_LCTL, LCTL(LALT(KC_T)), KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_RSFT, RAISE,   KC_LEFT, KC_DOWN, KC_UP, KC_RGHT}
},
 /* Fraktur uppercase
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   𝕻  |   𝖄  |   𝕱  |   𝕲  |   𝕮  |   𝕽  |   𝕷  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   𝕬  |   𝕺  |   𝕰  |   𝖀  |   𝕴  |   𝕯  |   𝕳  |   𝕿  |   𝕹  |   𝕾  |  _   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | FRAC |   ;  |   𝕼  |   𝕵  |   𝕶  |   𝖃  |   𝕭  |   𝕸  |   𝖂  |   𝖁  |   𝖅  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | TERM | Alt  | GUI  |Lower |Space |FRAC |Raise  | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 *

[_FRAKC] = {
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  X(FR_P), X(FR_Y), X(FR_F), X(FR_G), X(FR_C), X(FR_R), X(FR_L),  KC_BSPC},
  {KC_ESC,  X(FR_A), X(FR_O), X(FR_E), X(FR_U), X(FR_I), X(FR_D), X(FR_H), X(FR_T), X(FR_N), X(FR_S),  KC_UNDS},
  {FRAKC,    KC_SCLN, X(FR_Q), X(FR_J), X(FR_K), X(FR_X), X(FR_B), X(FR_M), X(FR_W), X(FR_V), X(FR_Z),  KC_ENT },
  {KC_LCTL, TERM, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  FRAKC,    RAISE,   KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT}
},
*/
 /* Fraktur lowercase
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   𝖕  |   𝖞  |   𝖋  |   𝖌  |   𝖈  |   𝖗  |   𝖑  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   𝖆  |   𝖔  |   𝖊  |   𝖚  |   𝖎  |   𝖉  |   𝖍  |   𝖙  |   𝖓  |   𝖘  |  _   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |FRAKC |   ;  |   𝖖  |   𝖏  |   𝖐  |   𝖝  |   𝖇  |   𝖒  |   𝖜  |   𝖛  |   𝖟  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | TERM | Alt  | GUI  |Lower |Space |FRAKC |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 *

[_FRAK] = {
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  X(FR_p), X(FR_y), X(FR_f), X(FR_g), X(FR_c), X(FR_r), X(FR_l),  KC_BSPC},
  {KC_ESC,  X(FR_a), X(FR_o), X(FR_e), X(FR_u), X(FR_i), X(FR_d), X(FR_h), X(FR_t), X(FR_n), X(FR_s),  KC_UNDS},
  {FRAKC,   KC_SCLN, X(FR_q), X(FR_j), X(FR_k), X(FR_x), X(FR_b), X(FR_m), X(FR_w), X(FR_v), X(FR_z),  KC_ENT },
  {KC_LCTL, TERM, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  FRAKC,   RAISE,   KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT}
},
*/
/*
* Cursive
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   𝕻  |   𝖄  |   𝕱  |   𝕲  |   𝕮  |   𝕽  |   𝕷  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   𝕬  |   𝕺  |   𝕰  |   𝖀  |   𝕴  |   𝕯  |   𝕳  |   𝕿  |   𝕹  |   𝕾  |  _   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   𝕼  |   𝕵  |   𝕶  |   𝖃  |   𝕭  |   𝕸  |   𝖂  |   𝖁  |   𝖅  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | TERM | Alt  | GUI  |Lower |Space |Shift |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 *

[_CURS] = {
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  X(FR_P), X(FR_Y), X(FR_F), X(FR_G), X(FR_C), X(FR_R), X(FR_L),  KC_BSPC},
  {KC_ESC,  X(FR_A), X(FR_O), X(FR_E), X(FR_U), X(FR_I), X(FR_D), X(FR_H), X(FR_T), X(FR_N), X(FR_S),  KC_UNDS},
  {KC_LSFT, KC_SCLN, X(FR_Q), X(FR_J), X(FR_K), X(FR_X), X(FR_B), X(FR_M), X(FR_W), X(FR_V), X(FR_Z),  KC_ENT },
  {KC_LCTL, TERM, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_RSFT, RAISE,   KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT}
}*/

/* Game
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Shift |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Alt  |   4  |   3  |   2  | Lower|    Space    |Raise | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = {
	{KC_1,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,    KC_BSPC},
	{KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT},
  {KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH, _______},
  {KC_LALT,   KC_4,    KC_3,    KC_2,    LOWER,  KC_SPC,  KC_SPC,   RAISE,  KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT}
}
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
		set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    /*case FRAK:
      if(record->event.pressed) {
		set_single_persistent_default_layer(_FRAK);
      }
      return false;
      break;
    case FRAKC:
      if(record->event.pressed) {
		layer_on(_FRAKC);
      } else {
		layer_off(_FRAKC);
		//layer_on(_FRAK);
		//update_tri_layer(_FRAK, _FRAKC, _ADJUST);
      }
      return false;
      break;*/
    /*case CURS:
      if (record->event.pressed) {
	      set_single_persistent_default_layer(_CURS);
      }
      return false;
      break;*/
    /*case CURSC:
      if(record->event.pressed) {
	      layer_on(_CURSC);
      } else{
	layer_off(_CURSC);
      }
      return false;
      break;
      */
	case GAME:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAME);
      }
      return false;
      break;
    case RUNIC:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_RUNIC);
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
    /*case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;*/
   /*// TTY switching
   case TTY:
      if (record->event.pressed) {
      OSM(MOD_LCTL);
      }
      return false;
      break;*/
   // Workspace switching
   /*case SPACE_ONE:
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
      break;*/
   /*case ZOOM_IN:
      if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("+"));
      }
      return false;
      break;
   case ZOOM_OUT:
      if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("-"));
      }
	  return false;
	  break;*/
   /*case TERM:
	  if (record->event.pressed) {
		  SEND_STRING(SS_LCTRL(SS_LALT("t")));
	  }
	  return false;
	  break;*/
  }
  return true;
}
