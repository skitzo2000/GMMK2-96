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

enum custom_keycodes {
    PRNTSCREEN = SAFE_RANGE,
    NAME,
    GOOD_MORNING,
    HAPPY_MONDAY,
    HAPPY_FRIDAY,
};

//  Skitzo2000's Custom Colors
#define ORANGE_RGB        120, 26, 0
#define DARKORANGE_RGB    60, 13, 0
#define BLUE_RGB          0, 26, 255
#define DARKBLUE_RGB      0, 60, 120
//  GMMK 2 96 Default Function Layer colors
#define ARROW_KEY_COLORS        ORANGE_RGB
#define MISC_KEY_COLORS         RGB_YELLOW
#define RESET_KEY_COLORS        RGB_RED
#define RGB_KEY_COLORS          RGB_PURPLE
#define MEDIA_KEY_COLORS        RGB_GOLD
//  Skitzo2000's custom keys
#define TO_KEY_COLORS          BLUE_RGB
//  GMMK 2 96 Default FN layer keys and Others
int ARROW_KEYS[] = {82, 94, 95, 96};
int MISC_KEYS[]  = {1, 2, 3, 4, 88};
int RESET_KEY    =  49;
int RGB_KEYS[]   =  {71, 72, 73, 74, 82, 94, 95, 96};
int MEDIA_KEYS[] =  {5, 6, 7, 8, 9, 10, 11};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case PRNTSCREEN:
        if (record->event.pressed) {
            SEND_STRING(SS_RGUI(SS_RSFT("s")));
        } else {

        }
        break;
    case NAME:
        if (record->event.pressed) {
            SEND_STRING("Paul Norton");
        } else {

        }
        break;
    case GOOD_MORNING:
        if (record->event.pressed) {
            SEND_STRING("Good Morning, ");
        } else {

        }
        break;
    case HAPPY_MONDAY:
        if (record->event.pressed) {
            SEND_STRING("Happy Monday, ");
        } else {

        }
        break;
    case HAPPY_FRIDAY:
        if (record->event.pressed) {
            SEND_STRING("Happy Friday, ");
        } else {

        }
        break;
    }
    return true;
};


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
  KC_GESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   KC_INS,   KC_PGUP,  KC_PGDN,
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,   KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,   KC_P4,    KC_P5,    KC_P6,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_P1,    KC_P2,    KC_P3,    KC_PENT,
  KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,                                 KC_RALT,  MO(_FL),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT),

[_1L] = LAYOUT(
  KC_GESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   KC_INS,   KC_PGUP,  KC_PGDN,
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,   KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,   KC_P4,    KC_P5,    KC_P6,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_P1,    KC_P2,    KC_P3,    KC_PENT,
  KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,                                 KC_RALT,  MO(_FL),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT),


[_2L] = LAYOUT(
  KC_GESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   KC_INS,   KC_PGUP,  KC_PGDN,
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,   KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,   KC_P4,    KC_P5,    KC_P6,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_P1,    KC_P2,    KC_P3,    KC_PENT,
  KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,                                 KC_RALT,  MO(_FL),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT),

  /* Keymap _FL: Function Layer
   */
[_FL] = LAYOUT(
    RESET,  KC_MYCM,  KC_WHOM,  KC_CALC,  KC_MSEL,  KC_MPRV,  KC_MRWD,  KC_MPLY,  KC_MSTP,  KC_MUTE,  KC_VOLU,  KC_VOLD,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,
  _______,  RGB_HUI,  RGB_HUD,  RGB_SPD,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   RGB_VAI,  _______,  _______,  _______,  _______,
	_______,  UC_M_WI,  _______,                      _______,                                _______,  _______,  _______, RGB_RMOD,   RGB_VAD,  RGB_MOD,  _______,  _______)
};

enum LEDLAYER {
    L0 = 0x1,
    L1 = 0x2,
    L2 = 0x4,
    L3 = 0x8,
};

uint32_t layer_state_set_user(uint32_t state) {
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
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
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
        RGB_MATRIX_INDICATOR_SET_COLOR(30, 255, 255, 255); //capslock key
    }

    switch(get_highest_layer(layer_state)){  // special handling per layer
        case 0:  //Layer 0
            break;
        case 1:  //layer 1
            break;
        case 2:  //layer 2
            break;
        case 3:  //layer 2
            //TO(Layers)
            rgb_matrix_set_color(16, TO_KEY_COLORS);
            rgb_matrix_set_color(17, TO_KEY_COLORS);
            rgb_matrix_set_color(18, TO_KEY_COLORS);
            // KC_MYCM,  KC_WHOM,  KC_CALC,  KC_MSEL, UC_M_WI
            for(int i = 0; i < (sizeof(MISC_KEYS)-1 ); i++) {
                rgb_matrix_set_color(MISC_KEYS[i], MISC_KEY_COLORS);
            }
            // Reset
            rgb_matrix_set_color(61, RESET_KEY_COLORS);  //  KC_HOME
            //RGBMatrix
            rgb_matrix_set_color(45, RGB_KEY_COLORS);  // RGB_HUI
            rgb_matrix_set_color(46, RGB_KEY_COLORS);  // RGB_HUD
            rgb_matrix_set_color(47, RGB_KEY_COLORS);  // RGB_SPD
            rgb_matrix_set_color(48, RGB_KEY_COLORS);  // RGB_SPI
            //Media
            rgb_matrix_set_color(49, MEDIA_KEY_COLORS);  // KC_MUTE
            rgb_matrix_set_color(50, MEDIA_KEY_COLORS);  // KC_VOLU
            rgb_matrix_set_color(51, MEDIA_KEY_COLORS);  // KC_VOLD
            rgb_matrix_set_color(52, MEDIA_KEY_COLORS);  // KC_MPRV
            rgb_matrix_set_color(53, MEDIA_KEY_COLORS);  // KC_MPLY
            rgb_matrix_set_color(54, MEDIA_KEY_COLORS);  // KC_MNXT
            //  Arrow Keys
            rgb_matrix_set_color(56, ARROW_KEY_COLORS);  // RGB_VAI
            rgb_matrix_set_color(64, ARROW_KEY_COLORS);  // RGB_RMOD
            rgb_matrix_set_color(65, ARROW_KEY_COLORS);  // RGB_VAD
            rgb_matrix_set_color(66, ARROW_KEY_COLORS);  // RGB_MOD
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
}

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_set_speed(25);
  set_glorious_side_96('r', BLUE_RGB);
  set_glorious_side_96('l', ORANGE_RGB);
}