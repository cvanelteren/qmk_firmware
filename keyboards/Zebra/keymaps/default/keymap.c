/* Copyright 2017 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software             : you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "Zebra.h"
// added by me // Layer shorthand /*

#define _QW 0
#define _FN 1
#define _FN2 2

//Tap Dance Declarations
enum {
  TD_ESC_CAPS = 0,
  TD_WORD_LEFT,
  TD_WORD_RIGHT,
  TAP_BRACKET_LEFT,
  TAP_BRACKET_RIGHT,
  TAP_BSLSH_EQ,
  TAP_QUOTE,
  TAP_SCLN
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
  [TD_WORD_LEFT] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, LCTL(KC_LEFT)),
  [TD_WORD_RIGHT] = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT, LCTL(KC_RIGHT)),
  [TAP_BRACKET_LEFT] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, LSFT(KC_LBRC)),
  [TAP_BRACKET_RIGHT] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, LSFT(KC_RBRC)),
  [TAP_BSLSH_EQ] = ACTION_TAP_DANCE_DOUBLE( KC_EQL, KC_BSLS),
  [TAP_QUOTE] = ACTION_TAP_DANCE_DOUBLE( KC_QUOT, LSFT(KC_QUOT)),
  [TAP_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, LSFT(KC_SCLN))
// Other declarations would go here, separated by commas, if you have them
};

enum custom_keycodes{
  NEW_LINE = SAFE_RANGE,
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (record -> event.pressed)
//   {
//     if (get_mods() && MOD_BIT(KC_LCTL) && MOD_BIT(KC_ENT) )
//     {
//       SEND_STRING("TEST" );
//       return false;
//     }
//     else
//       return true;
//     }
//   return true;
// };


//In Layer declaration, add tap dance item in place of a key code
// TD(TD_ESC_CAPS)aaaa

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC | 1 | 2 | 3 | 4 | 5 | - | ` | = | 6 | 7 | 8 | 9 | 0 | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB | Q | W | E | R | T | [ | \ | ] | Y | U | I | O | P | ' |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CAP LK | A | S | D | F | G | HOME | DEL | PG UP | H | J | K | L | ; | ENTER |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z | X | C | V | B | END | UP | PG DN | N | M | , | . | / | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL | LGUI | LALT | FN | SPACE | SPACE | LEFT | DOWN | RIGHT | SPACE | SPACE | FN | RALT | RGUI | RCTRL |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 // [_QW] = { /* modified qwerty */
  /*
  KC_PGDN\=]p0--9-0s44444444
   KC_PGUP,
   KC_HOME,
   KC_END,
   KC_UP,
   KC_RSFT
   KC_RGUI
   LT(_FN2, KC_GRV) // hold tap
   */
// { KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC },
// { KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL },
// { KC_GRV, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT , KC_ENT, KC_ENT},
// {KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM,KC_DOT, KC_SLSH, KC_RSPC, KC_PGUP, KC_UP, KC_PGDN},
// { KC_LCTL, KC_LGUI, MO(_FN), KC_LALT , KC_SPC, KC_SPC, KC_ENT, KC_LBRC, KC_RBRC, KC_EQL, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT},
//   },

  /* QWERTYw
   * .--------------------------------------------------------------------------------------------------------------------------------------.
   * | ESC | 1 | 2 | 3 | 4 | 5 | - | ` | = | 6 | 7 | 8 | 9 | 0 | BACKSP |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
   * | TAB | Q | W | E | R | T | [ | \ | ] | Y | U | I | O | P | ' |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
   * | CAP LK | A | S | D | F | G | HOME | DEL | PG UP | H | J | K | L | ; | ENTER |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
   * | LSHIFT | Z | X | C | V | B | END | UP | PG DN | N | M | , | . | / | RSHIFT |
   * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
   * | LCTRL | LGUI | LALT | FN | SPACE | SPACE | LEFT | DOWN | RIGHT | SPACE | SPACE | FN | RALT | RGUI | RCTRL |
   * '--------------------------------------------------------------------------------------------------------------------------------------'
   */
 [_QW] = { /* QWERTY */
     { KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS, KC_GRV, KC_EQL, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC},
 { KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_BSLS, KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC},
 { KC_GESC , KC_A, KC_S, KC_D, KC_F, KC_G, KC_HOME, KC_DEL, KC_PGUP, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT },
 { KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_END, KC_UP, KC_PGDN, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC },
 { KC_LCTL, KC_LGUI,  MO(_FN), KC_LALT, KC_LCTL, KC_SPC, KC_LEFT, KC_DOWN, KC_RGHT, LT(_FN, KC_ENT), LT(_FN2, KC_ENT), MO(_FN), KC_RALT, KC_RGUI, KC_RCTL },
 },

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1 | F2 | F3 | F4 | F5 | F6 | NUM LK | P/ | P* | F7 | F8 | F9 | F10 | F11 | F12 |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC | MYCOMP | MAIL | | | P7 | P8 | P9 | - | | | PR SCR | SCR LK | PR SCR |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV | PLAY | NEXT | STOP | | | P4 | P5 | P6 | + | | | | | |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL- | MUTE | VOL+ | | | | P1 | P2 | P3 | PENT | | | | | |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | RESET | | | FN | | | P0 | | P. | PENT | PENT | FN | | | |
 * '-------------------------------------, _______,-------------------------------------------------------------------------------------------------'
 */

 [_FN] = { /* FUNCTION */
  { KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, RESET},
  {KC_CAPS, _______, KC_BSLS, KC_LCBR, KC_RCBR, KC_PLUS, _______, _______, _______, _______, _______, KC_HOME, KC_END, _______, _______},
  { KC_GRV, KC_UNDS, KC_EQL, KC_LBRC, KC_RBRC, KC_EQL, _______, _______, _______,KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,  _______, _______},
  { KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU, _______, KC_MINS, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
},

//   { KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS},
//   {KC_CAPS, _______, _______, _______, _______, _______,  _______, KC_HOME, KC_END ,   _______, _______, _______, _______, _______, _______},
//   { _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, _______, _______, _______},
//   { KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
//   { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
// },

 [_FN2] = {
   {KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, _______},
   {_______, LSFT(KC_6) , LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), _______,_______, _______, KC_6, KC_7 ,KC_8, KC_9 , KC_0, _______},
   {TO(_QW), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), _______,_______, _______, KC_1, KC_2, KC_3, KC_4 ,KC_5, _______},
   {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
   {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET},
 }
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0                               :
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }


        break;
      }
    return MACRO_NONE;
};


// LEADER_EXTERNS();
//
// void matrix_scan_user(void) {
//   LEADER_DICTIONARY() {
//     leading = false;
//     leader_end();
//
//     SEQ_ONE_KEY(KC_F) {
//       // Anything you can do in a macro.
//       SEND_STRING("QMK is awesome.");
//     }
//     SEQ_TWO_KEYS(KC_D, KC_D) {
//       SEND_STRING(SS_LCTRL("a")SS_LCTRL("c"));
//     }
//     SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
//       SEND_STRING("https://start.duckduckgo.com"SS_TAP(X_ENTER));
//     }
//     SEQ_TWO_KEYS(KC_A, KC_S) {
//       register_code(KC_LGUI);
//       register_code(KC_S);
//       unregister_code(KC_S);
//       unregister_code(KC_LGUI);
//     }
//   }
// }
