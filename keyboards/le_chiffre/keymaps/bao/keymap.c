/* Copyright 2020 tominabox1
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
  _NUM_SYM,
  _NAV,
  _MOUSE,
  _GAME
};

enum combo_events {
  COMBO_BSPC,
  COMBO_NUMBAK,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_DEL,
  COMBO_QUOT
};

#define KC_NUM_SPC LT(_NUM_SYM, KC_SPC)
#define KC_NAV_ENT LT(_NAV, KC_ENT)

#define KC_GA LGUI_T(KC_A)
#define KC_AS LALT_T(KC_S)
#define KC_CD LCTL_T(KC_D)
#define KC_SF LSFT_T(KC_F)

#define KC_SJ RSFT_T(KC_J)
#define KC_CK RCTL_T(KC_K)
#define KC_AL RALT_T(KC_L)
#define KC_GSCLN RGUI_T(KC_SCLN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,  LCTL(KC_W),  KC_Y,   KC_U,    KC_I,   KC_O,     KC_P,
    KC_A,  KC_AS,  KC_CD,  KC_SF,   KC_G,               KC_H,  KC_SJ,   KC_CK,  KC_AL, KC_GSCLN,
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,               KC_N,   KC_M, KC_COMM, KC_DOT,  KC_SLSH,
                     KC_LCTL, KC_NUM_SPC,               KC_NAV_ENT, MO(_MOUSE)
  ),

  [_NUM_SYM] = LAYOUT(
        KC_1,   KC_2,     KC_3,     KC_4,      KC_5,  TG(_GAME), KC_6,     KC_7,     KC_8,      KC_9,       KC_0,
    KC_EXLM,   KC_AT,  KC_HASH,   KC_DLR,   KC_PERC,              KC_CIRC,  KC_AMPR,  KC_ASTR,   KC_EQL,  KC_MINS,
    KC_BSLS, KC_LCBR,  KC_LBRC,  KC_LPRN,   KC_UNDS,              KC_RPRN,  KC_RBRC,  KC_RCBR,   KC_DOT,   KC_GRV,
                                KC_CAPS,    KC_TRNS,              KC_TRNS,  KC_TRNS
  ),

  [_NAV] = LAYOUT(
    KC_F1,  RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  RESET,   KC_GRV,   KC_PGDN,    KC_UP,  KC_PGUP,  KC_SCLN,
    KC_F2,  RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,          KC_HOME,   KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_END,
    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,            KC_F8,     KC_F9,   KC_F10,   KC_F11,   KC_F12,
                                  KC_TRNS,KC_TRNS,          KC_TRNS,  KC_TRNS
  ),

  [_MOUSE] = LAYOUT(
    KC_WH_L,  KC_WH_R,  KC_MS_U,  XXXXXXX,  KC_WH_U,  XXXXXXX,  XXXXXXX,  XXXXXXX,     KC_W,     KC_E,  TG(_MOUSE),
    KC_BTN2,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D,            XXXXXXX,     KC_A,     KC_S,     KC_D,    XXXXXXX,
    XXXXXXX,  KC_ACL0,  KC_ACL1,  KC_ACL2,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    KC_CAPS,
                                  KC_BTN3,  KC_BTN1,            XXXXXXX,  XXXXXXX
  ),

  [_GAME] = LAYOUT(
    KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  TG(_GAME),  KC_Y,  KC_U,     KC_I,    KC_O,     KC_P,
    KC_A,  KC_S,  KC_D,  KC_F,  KC_G,              KC_H,  KC_J,     KC_K,    KC_L,  KC_SCLN,
    KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,              KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,
                     KC_ENT,  KC_SPC,              XXXXXXX,  XXXXXXX
  )

};

                 
bool encoder_update_user(uint8_t index, bool clockwise) {
  if(IS_LAYER_ON(_BASE)) { // on base layer cycle tabs
    if (clockwise) {
      tap_code16(S(C(KC_TAB)));
    } else {
      tap_code16(C(KC_TAB));
    }
    return true;  
  }

  else if(IS_LAYER_ON(_NAV)) {
    if (clockwise) {
      tap_code16(C(KC_Z));
    } else {
      tap_code16(C(KC_Y));
    }
    return true;
  }

  else { // on other layers emulate volume control
    if (clockwise) {
      tap_code(KC_VOLD);
    } else {
      tap_code(KC_VOLU);
    }
    return true;
  }
}

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


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_90;
}

void render_lechiffre_logo(void) {
    static const char PROGMEM lechiffre_logo[] = {
  // 'lechiffre_logo', 32x20px
   0x00, 0x3e, 0x20, 0x20, 0x00, 0x18, 0x2c, 0xa8, 0x80, 0x00, 0x1c, 0x22, 0x22, 0x00, 0x3e, 0x08,
0x30, 0x00, 0x34, 0x00, 0x3c, 0x0a, 0x00, 0xbc, 0x8a, 0x00, 0x38, 0x08, 0x00, 0x18, 0x2c, 0x28,
0x00, 0xb6, 0xb6, 0x00, 0xdb, 0xdb, 0x00, 0x6d, 0x6d, 0x00, 0xdb, 0xdb, 0x00, 0xdb, 0xdb, 0x00,
0x00, 0xdb, 0xdb, 0x00, 0xdb, 0xdb, 0x00, 0x6d, 0x6d, 0x00, 0xdb, 0xdb, 0x00, 0xb6, 0xb6, 0x00,
0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00,
0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00
};

  oled_write_raw_P(lechiffre_logo, sizeof(lechiffre_logo));
}

static void render_layer_status(void) {
    oled_write_P(PSTR("-----"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case _NUM_SYM:
            oled_write_ln_P(PSTR("NUM"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("FUNC"), false);
            break;
        case _MOUSE:
            oled_write_ln_P(PSTR("MAUS"), false);
            break;
        default:
            oled_write_ln_P(PSTR("???"), false);
    }
}

#    define KEYLOG_LEN 11
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

//Text only renders
void render_keylogger_status(void) {
    oled_write_P(PSTR("-----"), false);
    oled_write(keylog_str, false);
}

void render_keylock_status(led_t led_state) {
    oled_write_P(PSTR("-----"), false);
    oled_write_P(PSTR("C"), led_state.caps_lock);
  oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_state.num_lock);
  oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), led_state.scroll_lock);
    //oled_write_ln_P(PSTR(" "), false);
}

void render_mod_status(uint8_t modifiers) {
       oled_write_P(PSTR("-----"), false);
    oled_write_ln_P(PSTR("SHFT"), (modifiers & MOD_MASK_SHIFT));
    oled_write_ln_P(PSTR("ALT"), (modifiers & MOD_MASK_ALT));
    oled_write_ln_P(PSTR("CTRL"), (modifiers & MOD_MASK_CTRL));
    oled_write_ln_P(PSTR("GUI"), (modifiers & MOD_MASK_GUI));
}

void oled_task_user(void) {
    render_lechiffre_logo();
    oled_set_cursor(0,3);
    render_layer_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  render_mod_status(get_mods()|get_oneshot_mods());
  render_keylock_status(host_keyboard_led_state());
  render_keylogger_status();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
      add_keylog(keycode);
    }
    return true;
  }
#endif
