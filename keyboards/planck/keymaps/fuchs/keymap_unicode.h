#ifndef KEYMAP_UNICODE
#define KEYMAP_UNICODE

#include "keymap.h"

enum unicode_name {
RN_F,
RN_U,
RN_X,
RN_A,
RN_R,
RN_KC,
RN_G,
RN_VW,
RN_H,
RN_N,
RN_I,
RN_J,
RN_Y,
RN_P,
RN_Z,
RN_S,
RN_T,
RN_B,
RN_E,
RN_M,
RN_L,
RN_Q,
RN_D,
RN_O,
// punctuation
INBANG,
PERCON,
/*
// Fraktur uppercase
FR_A,
FR_B,
FR_C,
FR_D,
FR_E,
FR_F,
FR_G,
FR_H,
FR_I,
FR_J,
FR_K,
FR_L,
FR_M,
FR_N,
FR_O,
FR_P,
FR_Q,
FR_R,
FR_S,
FR_T,
FR_U,
FR_V,
FR_W,
FR_X,
FR_Y,
FR_Z,
// Fraktur lowercase
FR_a,
FR_b,
FR_c,
FR_d,
FR_e,
FR_f,
FR_g,
FR_h,
FR_i,
FR_j,
FR_k,
FR_l,
FR_m,
FR_n,
FR_o,
FR_p,
FR_q,
FR_r,
FR_s,
FR_t,
FR_u,
FR_v,
FR_w,
FR_x,
FR_y,
FR_z
*/
};

// Default Runes for Dieter Rams Canvas keycaps
const uint32_t PROGMEM unicode_map[] = {
// Runes
[RN_F] = 0x16A0, // ᚠ
//[ᚡ] = 0x16A1,
[RN_U] = 0x16A2,// ᚢ
//[ᚣ] = 0x16A3,
//[ᚤ] = 0x16A4,
//[ᚥ] = 0x16A5,
[RN_X] = 0x16A6, // ᚦ
//[ᚧ] = 0x16A7,
[RN_A] = 0x16A8,// ᚨ
//[ᚩ] = 0x16A9,
//[ᚪ] = 0x16AA,
//[ᚫ] = 0x16AB,
//[ᚬ] = 0x16AC,
//[ᚭ] = 0x16AD,
//[ᚮ] = 0x16AE,
//[ᚯ] = 0x16AF,
//[ᚰ] = 0x16B0,
[RN_R] = 0x16B1, // ᚱ
[RN_KC] = 0x16B2, // ᚲ
//[ᚳ] = 0x16B3,
//[ᚴ] = 0x16B4,
//[ᚵ] = 0x16B5,
//[ᚶ] = 0x16B6,
[RN_G] = 0x16B7, // ᚷ
//[ᚸ] = 0x16B8,
[RN_VW] = 0x16B9, // ᚹ
[RN_H] = 0x16BA, // ᚺ
//[ᚻ] = 0x16BB,
//[ᚼ] = 0x16BC,
//[ᚽ] = 0x16BD,
[RN_N] = 0x16BE, // ᚾ
//[ᚿ] = 0x16BF,
//[ᛀ] = 0x16C0,
[RN_I] = 0x16C1, // ᛁ
//[ᛂ] = 0x16C2,
[RN_J] = 0x16C3, // ᛃ
//[ᛄ] = 0x16C4,
//[ᛅ] = 0x16C5,
//[ᛆ] = 0x16C6,
[RN_Y] = 0x16C7, // ᛇ
[RN_P] = 0x16C8, // ᛈ
[RN_Z] = 0x16C9, // ᛉ
//[ᛊ] = 0x16CA,
[RN_S] = 0x16CB, // ᛋ
//[ᛌ] = 0x16CC,
//[ᛍ] = 0x16CD,
//[ᛎ] = 0x16CE,
[RN_T] = 0x16CF, // ᛏ
//[ᛐ] = 0x16D0,
//[ᛑ] = 0x16D1,
[RN_B] = 0x16D2, // ᛒ
//[ᛓ] = 0x16D3,
//[ᛔ] = 0x16D4,
//[ᛕ] = 0x16D5,
[RN_E] = 0x16D6, // ᛖ
[RN_M] = 0x16D7, // ᛗ
//[ᛘ] = 0x16D8,
//[ᛙ] = 0x16D9,
[RN_L] = 0x16DA, // ᛚ
//[ᛛ] = 0x16DB,
[RN_Q] = 0x16DC, // ᛜ
//[ᛝ] = 0x16DD,
[RN_D] = 0x16DE, // ᛞ
[RN_O] = 0x16DF, // ᛟ
//[ᛠ] = 0x16E0,
//[ᛡ] = 0x16E1,
//[ᛢ] = 0x16E2,
//[ᛣ] = 0x16E3,
//[ᛤ] = 0x16E4,
//[ᛥ] = 0x16E5,
//[ᛦ] = 0x16E6,
//[ᛧ] = 0x16E7,
//[ᛨ] = 0x16E8,
//[ᛩ] = 0x16E9,
//[ᛪ] = 0x16EA,
//[᛫] = 0x16EB,
//[᛬] = 0x16EC,
//[᛭] = 0x16ED,
//[ᛮ] = 0x16EE,
//[ᛯ] = 0x16EF,
//[ᛰ] = 0x16F0,
//[ᛱ] = 0x16F1,
//[ᛲ] = 0x16F2,
//[ᛳ] = 0x16F3,
//[ᛴ] = 0x16F4,
//[ᛵ] = 0x16F5,
//[ᛶ] = 0x16F6,
//[ᛷ] = 0x16F7,
//[ᛸ] = 0x16F8,
// punctuation
[INBANG] = 0x203D, // ‽, interrobang
[PERCON] = 0x2E2E, // ⸮, percontation mark, irony mark, sarcasm mark
/*
// Fraktur uppercase
[FR_A] = 0x1D504,
[FR_B] = 0x1D505,
[FR_C] = 0x1D506,
[FR_D] = 0x1D507,
[FR_E] = 0x1D508,
[FR_F] = 0x1D509,
[FR_G] = 0x1D50A,
[FR_H] = 0x1D50B,
[FR_I] = 0x1D50C,
[FR_J] = 0x1D50D,
[FR_K] = 0x1D50E,
[FR_L] = 0x1D50F,
[FR_M] = 0x1D510,
[FR_N] = 0x1D511,
[FR_O] = 0x1D512,
[FR_P] = 0x1D513,
[FR_Q] = 0x1D514,
[FR_R] = 0x1D515,
[FR_S] = 0x1D516,
[FR_T] = 0x1D517,
[FR_U] = 0x1D518,
[FR_V] = 0x1D519,
[FR_W] = 0x1D51A,
[FR_X] = 0x1D51B,
[FR_Y] = 0x1D51C,
[FR_Z] = 0x1D51D,
// Fraktur lowercase
[FR_a] = 0x1D51E,
[FR_b] = 0x1D51F,
[FR_c] = 0x1D520,
[FR_d] = 0x1D521,
[FR_e] = 0x1D522,
[FR_f] = 0x1D523,
[FR_g] = 0x1D524,
[FR_h] = 0x1D525,
[FR_i] = 0x1D526,
[FR_j] = 0x1D527,
[FR_k] = 0x1D528,
[FR_l] = 0x1D529,
[FR_m] = 0x1D52A,
[FR_n] = 0x1D52B,
[FR_o] = 0x1D52C,
[FR_p] = 0x1D52D,
[FR_q] = 0x1D52E,
[FR_r] = 0x1D52F,
[FR_s] = 0x1D530,
[FR_t] = 0x1D531,
[FR_u] = 0x1D532,
[FR_v] = 0x1D533,
[FR_w] = 0x1D534,
[FR_x] = 0x1D535,
[FR_y] = 0x1D536,
[FR_z] = 0x1D537,
*/
};

#endif
