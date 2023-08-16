/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
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

#include "glorious_sides96.h"

#include "macros.h"

//  Skitzo2000's Custom Colors
#define ORANGE_RGB        120, 26, 0
#define DARKORANGE_RGB    60, 13, 0
#define BLUE_RGB          0, 26, 255
#define DARKBLUE_RGB      0, 60, 120
#define DARKORANGE_HSV    7, 255, 255
//  GMMK 2 96 Default Function Layer colors
#define ARROW_KEY_COLORS        ORANGE_RGB
#define MISC_KEY_COLORS         RGB_YELLOW
#define RESET_KEY_COLORS        RGB_RED
#define RGB_KEY_COLORS          RGB_PURPLE
#define MEDIA_KEY_COLORS        RGB_GOLD
//  Skitzo2000's custom keys
#define TO_KEY_COLORS          BLUE_RGB
int TO_KEYS[]    = {83, 84, 97};
//  GMMK 2 96 Default FN layer keys and Others
int ARROW_KEYS[] =  {82, 94, 95, 96};
int MISC_KEYS[]  =  {1, 2, 3, 4, 88, 58, 59, 76, 77};
int RGB_KEYS[]   =  {71, 72, 73, 74, 82, 94, 95, 96};
int MEDIA_KEYS[] =  {5, 6, 7, 8, 9, 10, 11};
int RESET_KEY    =  49;

// Just a little clean up to get the lengths of the array's at compile time
int SIZE_OF_ARROW_KEYS = sizeof(ARROW_KEYS)/sizeof(int);
int SIZE_OF_MISC_KEYS = sizeof(MISC_KEYS)/sizeof(int);
int SIZE_OF_RGB_KEYS = sizeof(RGB_KEYS)/sizeof(int);
int SIZE_OF_MEDIA_KEYS = sizeof(MEDIA_KEYS)/sizeof(int);
int SIZE_OF_TO_KEYS = sizeof(TO_KEYS)/sizeof(int);

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
#define _BL 0
#define _1L 1
#define _2L 2
#define _FL 3

// Blank Template
// [X] = LAYOUT(
//   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
//   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
//   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
//   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,
//   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
// 	 _______,  _______,  _______,                      _______,                                _______,  _______,  _______, _______,   _______,  _______,  _______,  _______),


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: Base Layer (Default Layer)
   */
[_BL] = LAYOUT(
  QK_GESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   PRNTSCREEN,  KC_DEL,   KC_INS,   KC_PGUP,  KC_PGDN,
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_NUM,  KC_PSLS,  KC_PAST,  KC_PMNS,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,   KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,   KC_P4,    KC_P5,    KC_P6,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_P1,    KC_P2,    KC_P3,    KC_PENT,
  KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,                                 KC_RALT,  MO(_FL),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT),

[_1L] = LAYOUT(
  QK_GESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   PRNTSCREEN,  KC_DEL,   KC_INS,   KC_PGUP,  KC_PGDN,
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_NUM,  KC_PSLS,  KC_PAST,  KC_PMNS,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,   KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,   KC_P4,    KC_P5,    KC_P6,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_P1,    KC_P2,    KC_P3,    KC_PENT,
  KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,                                 KC_RALT,  MO(_FL),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT),


[_2L] = LAYOUT(
  QK_GESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   PRNTSCREEN,  KC_DEL,   KC_INS,   KC_PGUP,  KC_PGDN,
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_NUM,  KC_PSLS,  KC_PAST,  KC_PMNS,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,   KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,   KC_P4,    KC_P5,    KC_P6,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_P1,    KC_P2,    KC_P3,    KC_PENT,
  KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,                                 KC_RALT,  MO(_FL),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT),

  /* Keymap _FL: Function Layer
   */
[_FL] = LAYOUT(
    RESET,  KC_MYCM,  KC_WHOM,  KC_CALC,  KC_MSEL,  KC_MPRV,  KC_MRWD,  KC_MPLY,  KC_MSTP,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,   KC_PSCR,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   RESET,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  HAPPY_FRIDAY,  GOOD_MORNING,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,
  _______,  RGB_HUI,  RGB_HUD,  RGB_SPD,  RGB_SPI,  _______,  NAME,  HAPPY_MONDAY,  _______,  _______,  _______,  _______,   RGB_VAI,  TO(_1L),  TO(_2L),  _______,  _______,
	_______,  UC_M_WI,  _______,                      _______,                                _______,  _______,  _______, RGB_RMOD,   RGB_VAD,  RGB_MOD,  TO(_BL),  _______)
};

enum LEDLAYER {
    L0 = 0x1,
    L1 = 0x2,
    L2 = 0x4,
    L3 = 0x8,
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if ((state & L3) == L3) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
    }
    else if ((state & L2) == L2) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
    }
    else if ((state & L1) == L1) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_MULTISPLASH);
    }
    else if ((state & L0) == L0) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
    }
    else {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
    }
    return state;
}

// RGB LED layout for GMMK 2 96%
// By Skitzo2000
// led number, function of the key

//   0, Esc     1, F1      2, F2    3, F3       4, F4      5, F5      6, F6    7, F7       8, F8      9, F9     10, F10  11, F11     12, F12    13, Prnscr      14, Del     15, Ins     16, PgUp      17, PgDo

//  18, `      19, 1      20, 2    21, 3       22, 4      23, 5      24, 6    25, 7       26, 8      27, 9      28, 0    29, -       30, =      31, Bkspc       32, NmLk    33, /       34, *         35, -

//  36, Tab    37, Q      38, W    39, E       40, R      41, T      42, Y    43, U       44, I      45, O      46, P    47, [       48, ]      49, "\""        50, 7       51, 8       52, 9         53, +

//  54, CpsLk  55, A      56, S    57, D       58, F      59, G      60, H    61, J       62, K      63, L      64, ;    65, '       66, Enter                  67, 4       68, 5       69, 6

//  70, ShftL  71, Z      72, X    73, C       74, V      75, B      76, N    77, M       78, ,      79, .      80, /    81, ShftR              82, Up          83, 1       84, 2       85, 3         86, EntrR

//  87, CtlL   88, WinL   89, AltL                                   90, Space                                  91, AltR 92, FN      93, CtrlR  94, Left        95, Down    96, Right   97, 0         98, Num .

//  101, LED 1
//  102, LED 2
//  103, LED 3
//  104, LED 4
//  105, LED 5
//  106, LED 6
//  107, LED 7
//  108, LED 8
//  109, LED 9
//  110, LED 10


//  111, LED 11
//  112, LED 12
//  113, LED 13
//  114, LED 14
//  115, LED 15
//  116, LED 16
//  117, LED 17
//  118, LED 18
//  119, LED 19
//  120, LED 20

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(54, 255, 255, 255); //capslock key
    }

    switch(get_highest_layer(layer_state)){  // special handling per layer
        case 0:  //Layer 0
            set_glorious_side_96('r', BLUE_RGB);
            set_glorious_side_96('l', ORANGE_RGB);
            break;
        case 1:  //layer 1
            break;
        case 2:  //layer 2
            break;
        case 3:  //layer 2
            //TO(Layers)
            for(int i = 0; i < SIZE_OF_TO_KEYS; i++) {
                rgb_matrix_set_color(TO_KEYS[i], TO_KEY_COLORS);
            }
            // KC_MYCM,  KC_WHOM,  KC_CALC,  KC_MSEL, UC_M_WI
            for(int i = 0; i < SIZE_OF_MISC_KEYS; i++) {
                rgb_matrix_set_color(MISC_KEYS[i], MISC_KEY_COLORS);
            }
            // Reset
            rgb_matrix_set_color(RESET_KEY, RESET_KEY_COLORS);  //  KC_HOME
            //RGBMatrix
            for(int i = 0; i < SIZE_OF_RGB_KEYS; i++) {
                rgb_matrix_set_color(RGB_KEYS[i], RGB_KEY_COLORS);
            }
            //Media
            for(int i = 0; i < SIZE_OF_MEDIA_KEYS; i++) {
                rgb_matrix_set_color(MEDIA_KEYS[i], MEDIA_KEY_COLORS);
            }
            break;
        default:
        break;
        //case #:
            //Sample options
            //rgb_matrix_set_color(1, 238, 65, 23);
            //rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_NEXUS);
            //rgb_matrix_set_color_all(238, 65, 23);
            //RGB_MATRIX_INDICATOR_SET_COLOR(0, 255, 0, 255);   //Set Color per key
    }
    return false;
}

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_set_speed(25);
  rgblight_sethsv_noeeprom(DARKORANGE_HSV);
  set_glorious_side_96('r', BLUE_RGB);
  set_glorious_side_96('l', ORANGE_RGB);
}
