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

enum layers {
  _BASE,
  _LETSGO,
  _BOIS,
  _MAUS,
  _GAME
};

enum combo_events {
  COMBO_BSPC,
  COMBO_NUMBAK,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_DEL,
  COMBO_QUOT,
  COMBO_SCLN,
  COMBO_SLSH
};

#define KC_NSPC LT(_LETSGO, KC_SPC)
#define KC_NENT LT(_BOIS, KC_ENT)

#define KC_GA LGUI_T(KC_A)
#define KC_AS LALT_T(KC_S)
#define KC_CD LCTL_T(KC_D)
#define KC_SF LSFT_T(KC_F)

#define KC_GH RGUI_T(KC_H)
#define KC_SJ RSFT_T(KC_J)
#define KC_CK RCTL_T(KC_K)
#define KC_AL RALT_T(KC_L)

#define KC_AJST  MO(_ADJUST)

// // Lower layer mod tap
// #define KC_F1AL  LALT_T(KC_F1)
// #define KC_F6CT  LCTL_T(KC_F6)
// #define KC_11SF  LSFT_T(KC_F11)

// #define KC_QUSF  RCTL_T(KC_QUOT)
// #define KC_ROSF  RSFT_T(KC_RO)

// // Layer tap
// #define KC_BSLO  LT(_LOWER, KC_BSPC)
// #define KC_SPRA  LT(_RAISE, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //,-----------------------------------------------------------------------------------------.
      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      KC_A,    KC_AS,   KC_CD,   KC_SF,   KC_G,    KC_GH,   KC_SJ,   KC_CK,        KC_AL,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,      KC_DOT,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      _______, KC_LCTL, KC_LALT,     KC_NSPC,               KC_NENT,  KC_ENT, MO(_MAUS), _______
  //`-----------------------------------------------------------------------------------------'
  ),

  [_LETSGO] = LAYOUT(
  //,-----------------------------------------------------------------------------------------.
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,     KC_MINS,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      KC_BSLS, KC_LCBR, KC_LBRC, KC_LPRN, KC_UNDS, KC_RPRN, KC_RBRC, KC_RCBR,     KC_EQL,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      _______, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, _______, _______, _______
  //`-----------------------------------------------------------------------------------------'
  ),

  [_BOIS] = LAYOUT(
  //,-----------------------------------------------------------------------------------------.
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_HOME, KC_PGDN, KC_UP,   KC_PGUP, KC_END,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_GRV,  KC_LEFT, KC_DOWN,     KC_RGHT,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL,  KC_COMM, KC_DOT,      RESET,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      _______, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, _______, _______, _______
  //`-----------------------------------------------------------------------------------------'
  ),

  [_MAUS] = LAYOUT(
  //,-----------------------------------------------------------------------------------------.
      KC_WH_L, KC_WH_R, KC_MS_U, XXXXXXX, KC_WH_U, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX,TG(_GAME),
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_SLCK, XXXXXXX, XXXXXXX,     XXXXXXX,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, KC_NLCK, XXXXXXX, XXXXXXX,     XXXXXXX,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_BTN3,          KC_BTN1,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  //`-----------------------------------------------------------------------------------------'
  ), 

    [_GAME] = LAYOUT(
  //,-----------------------------------------------------------------------------------------.
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,   KC_P,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,      KC_L,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
        KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,     KC_DOT,
  //|--------+--------+--------+--------+--------|--------+--------+--------+--------+--------|
      _______, KC_LCTL, KC_LALT,           KC_SPC,           KC_LSFT, KC_ENT, TG(_GAME), _______
  //`-----------------------------------------------------------------------------------------'
  )
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bspc[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_E, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_ASTR, KC_MINS, COMBO_END};
const uint16_t PROGMEM combo_quot[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_scln[] = {KC_N, KC_P, COMBO_END};
const uint16_t PROGMEM combo_slsh[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC),
  [COMBO_NUMBAK] = COMBO(combo_numbak,KC_BSPC),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_DEL] = COMBO(combo_del,KC_DEL),
  [COMBO_QUOT] = COMBO(combo_quot, KC_QUOT),
  [COMBO_SCLN] = COMBO(combo_scln, KC_SCLN),
  [COMBO_SLSH] = COMBO(combo_slsh, KC_SLSH)

};
#endif

// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case KC_NSPC:
//             return 150;
//         case KC_NENT:
//             return 150;
//         default:
//             return TAPPING_TERM;
//     }
//  }

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
