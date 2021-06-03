/* Copyright 2020 marksard
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

enum layer_number {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    LOWER = SAFE_RANGE,
    RAISE,
    KANJI,
};

#define KC_AJST  MO(_ADJUST)

// Base layer mod tap
enum combo_events {
  COMBO_BSPC,
  COMBO_NUMBAK,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_DEL,
  COMBO_QUOT
};

#define KC_LSPC LT(_LOWER, KC_SPC)
#define KC_RENT LT(_RAISE, KC_ENT)
#define KC_GA LGUI_T(KC_A)
#define KC_AS LALT_T(KC_S)
#define KC_CD LCTL_T(KC_D)
#define KC_SF LSFT_T(KC_F)
#define KC_SJ RSFT_T(KC_J)
#define KC_CK RCTL_T(KC_K)
#define KC_AL RALT_T(KC_L)
#define KC_GH RGUI_T(KC_H)

// Lower layer mod tap
#define KC_F1AL  LALT_T(KC_F1)
#define KC_F6CT  LCTL_T(KC_F6)
#define KC_11SF  LSFT_T(KC_F11)

#define KC_QUSF  RCTL_T(KC_QUOT)
#define KC_ROSF  RSFT_T(KC_RO)

// Layer tap
#define KC_BSLO  LT(_LOWER, KC_BSPC)
#define KC_SPRA  LT(_RAISE, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //,-----------------------------------------------------------------------------------------.
      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      KC_A,    KC_AS,   KC_CD,   KC_SF,   KC_G,    KC_GH,   KC_SJ,   KC_CK,        KC_AL,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,      KC_DOT,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      _______, KC_LALT, KC_LGUI,          KC_LSPC,          KC_RENT,  KC_ENT, KC_AJST, _______
  //`-----------------------------------------------------------------------------------------'
  ),

  [_LOWER] = LAYOUT(
  //,-----------------------------------------------------------------------------------------.
      KC_F1AL,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      KC_F6CT,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX, XXXXXXX, KC_SCLN,     KC_QUSF,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      KC_11SF,  KC_F12,  KC_ESC,  KC_TAB,   KANJI,   KC_RO,  KC_GRV, KC_SLSH,     KC_ROSF,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      _______, _______, _______,          KC_AJST,          KC_AJST, _______, _______, _______
  //`-----------------------------------------------------------------------------------------'
  ),

  [_RAISE] = LAYOUT(
  //,-----------------------------------------------------------------------------------------.
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP,     KC_RGHT,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL, KC_COMM,  KC_DOT,     KC_BSLS,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      _______, _______, _______,          _______,          _______, _______, _______, _______
  //`-----------------------------------------------------------------------------------------'
  ),

  [_ADJUST] = LAYOUT(
  //,-----------------------------------------------------------------------------------------.
        RESET, XXXXXXX, AG_NORM, AG_SWAP, KC_PSCR, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_NLCK, KC_MS_L, KC_MS_D, KC_MS_U,     KC_MS_R,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_CAPS, KC_BTN1, KC_BTN2, XXXXXXX,     XXXXXXX,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      _______, _______, _______,          _______,          _______, _______, _______, _______
  //`-----------------------------------------------------------------------------------------'
  )
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bspc[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_E, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_MINS, KC_EQL, COMBO_END};
const uint16_t PROGMEM combo_quot[] = {KC_I, KC_O, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC),
  [COMBO_NUMBAK] = COMBO(combo_numbak,KC_BSPC),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_DEL] = COMBO(combo_del,KC_DEL),
  [COMBO_QUOT] = COMBO(combo_quot, KC_QUOT)

};
#endif

// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case KC_SPRA:
//       return TAPPING_LAYER_TERM;
//     default:
//       return TAPPING_TERM;
//   }
// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {

//   bool result = false;
//   switch (keycode) {
//     case KANJI:
//       if (record->event.pressed) {
//           register_code16(keymap_config.swap_lalt_lgui ? A(KC_GRV) : KC_LANG2);
//       } else {
//           unregister_code16(keymap_config.swap_lalt_lgui ? A(KC_GRV) : KC_LANG2);
//       }
//     break;
//     default:
//       result = true;
//       break;
//   }

//   return result;
// }
