#ifndef KEYMAP_RUNIC
#define KEYMAP_RUNIC

#include "keymap.h"


#define RN_F  UC(0x16A0)
#define RN_U  UC(0x16A2)
#define RN_X  UC(0x16A6)
#define RN_A  UC(0x16A8)
#define RN_R  UC(0x16B1)
#define RN_KC UC(0x16B2)
#define RN_G  UC(0x16B7)
#define RN_VW UC(0x16B9)
#define RN_H  UC(0x16BA)
#define RN_N  UC(0x16BE)
#define RN_I  UC(0x16C1)
#define RN_J  UC(0x16C3)
#define RN_Y  UC(0x16C7)
#define RN_P  UC(0x16C8)
#define RN_Z  UC(0x16C9)
#define RN_S  UC(0x16CA)
#define RN_T  UC(0x16CF)
#define RN_B  UC(0x16D2)
#define RN_E  UC(0x16D6)
#define RN_M  UC(0x16D7)
#define RN_L  UC(0x16DA)
#define RN_Q  UC(0x16DC)
#define RN_D  UC(0x16DE)
#define RN_O  UC(0x16DF)

#endif
/*
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
RN_O
};

// Default Runes for Dieter Rams Canvas keycaps
const uint32_t PROGMEM unicode_map[] = {
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
[RN_S] = 0x16CA, // ᛊ
//[ᛋ] = 0x16CB,
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
[RN_D] = 0x16DC, // ᛞ
[RN_O] = 0x16DE, // ᛟ
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
};
*/
