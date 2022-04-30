/* 
 * Keymap for the GMMK Pro by Glorious
 *
 * Main layout is mostly standard QWERTY
 * 
 * Features:
 * - MO(2) right of SPACE enables german Umlauts using the Linux COMPOSE mechanism
 * - MO(1) right of MO(2) switches to LED Control, the launchers keys on the F1..12 and PrintScreen on DEL
 * - Enabled CAPS WORD Feature (see https://getreuer.info/posts/keyboards/caps-word/index.html)
 */

#include QMK_KEYBOARD_H

#include "features/caps_word.h"

enum custom_keycodes {
    UMLAUT_A = SAFE_RANGE,
    UMLAUT_U,
    UMLAUT_O,
    EUROSIGN
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // For caps_word:
    if (!process_caps_word(keycode, record)) { return false; }

    switch (keycode) {
        case UMLAUT_A:
            if (record->event.pressed) {
                tap_code(KC_CAPS);
                tap_code(KC_A);
                register_code(KC_RSHIFT);
                tap_code(KC_QUOTE);
                unregister_code(KC_RSHIFT);
            } else {
            }
            break;
        case UMLAUT_U:
            if (record->event.pressed) {
                tap_code(KC_CAPS);
                tap_code(KC_U);
                register_code(KC_RSHIFT);
                tap_code(KC_QUOTE);
                unregister_code(KC_RSHIFT);
            } else {
            }
            break;
        case UMLAUT_O:
            if (record->event.pressed) {
                tap_code(KC_CAPS);
                tap_code(KC_O);
                register_code(KC_RSHIFT);
                tap_code(KC_QUOTE);
                unregister_code(KC_RSHIFT);
            } else {
            }
            break;
        case EUROSIGN:
            if (record->event.pressed) {
                tap_code(KC_CAPS);
                tap_code(KC_C);
                tap_code(KC_EQUAL);
            } else {
            }
            break;
        }
    return true;
};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Del           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           INS
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 Home
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgUp
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       PgDown
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatme KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [0] = LAYOUT(
        KC_ESC,     KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,     KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS, KC_EQL,  KC_BSPC,          KC_INS,
        KC_TAB,     KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC, KC_RBRC, KC_BSLS,          KC_HOME,
        KC_CAPS,    KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,          KC_ENT,           KC_PGUP,
        KC_LSFT,    KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,           KC_RSFT,            KC_UP, KC_PGDN,
        KC_LCTL,    KC_LGUI,  KC_LALT,                            KC_SPC,                             MO(2),    MO(1),   KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_PSCR,          _______,
        _______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, RGB_M_TW, _______, _______, _______,       _______,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            KC_END,
        _______, RGB_VAI, RGB_HUI, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______, RGB_VAD, RGB_HUD, RGB_SAD, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______,          RGB_MOD, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),
    [2] = LAYOUT(
        _______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,          _______,
        _______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,          _______,
        _______, _______,  _______, EUROSIGN,_______, _______, _______, UMLAUT_U, _______, UMLAUT_O, _______, _______, _______, _______,          _______,
        _______, UMLAUT_A, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______,          _______,          _______,
        _______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______,          _______, _______, _______,
        _______, _______,  _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
};
// clang-format on

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
    return true;
}
#endif // ENCODER_ENABLE
