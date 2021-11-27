#include QMK_KEYBOARD_H

#include "oneshot.h"

enum layers {
    QWERTY,
    SYMBOLS,
    NAVIGATION,
    FUNCTIONS_NUMPAD,
    MISC,
};

enum keycodes {
    OS_SFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_GUI,
    OS_FUN,
    OS_MISC,
};

#define L_SYM MO(SYMBOLS)
#define L_NAV MO(NAVIGATION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
        KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,                          KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,
    // ├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
        KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                          KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,
    // ├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
        KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,                          KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,
    // └────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                        L_NAV   ,    KC_SPC  ,        KC_LSFT ,    L_SYM
    //                                 └────────┘   └────────┘       └────────┘   └────────┘
    ),

    [SYMBOLS] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
        KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                          KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,
    // ├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
        OS_GUI  ,OS_ALT  ,OS_SFT  ,OS_CTRL ,KC_GRV  ,                          KC_QUOT ,OS_CTRL ,OS_SFT  ,OS_ALT  ,OS_GUI  ,
    // ├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          KC_BSLS ,KC_LBRC ,KC_RBRC ,KC_MINS ,KC_EQL  ,
    // └────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                        _______ ,    _______ ,        _______ ,    _______
    //                                 └────────┘   └────────┘       └────────┘   └────────┘
    ),

    // TODO: Can maybe remove KC_SLCK and KC_PAUS. I have never used these in my life
    [NAVIGATION] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
        KC_TAB  ,KC_ESC  ,OS_FUN  ,XXXXXXX ,XXXXXXX ,                          KC_INS  ,KC_HOME ,KC_UP   ,KC_PGUP ,KC_BSPC ,
    // ├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
        OS_GUI  ,OS_ALT  ,OS_SFT  ,OS_CTRL ,XXXXXXX ,                          XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_ENT  ,
    // ├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
        KC_PSCR ,KC_SLCK ,KC_PAUS ,XXXXXXX ,OS_MISC ,                          KC_DEL  ,KC_END  ,XXXXXXX ,KC_PGDN ,XXXXXXX ,
    // └────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                        _______ ,    _______ ,        _______ ,    _______
    //                                 └────────┘   └────────┘       └────────┘   └────────┘
    ),

    [FUNCTIONS_NUMPAD] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
        XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F10  ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,KC_F4   ,KC_F5   ,KC_F6   ,KC_F11  ,                          XXXXXXX ,OS_CTRL ,OS_SFT  ,OS_ALT  ,OS_GUI  ,
    // ├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F12  ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
    // └────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                        _______ ,    _______ ,        _______ ,    _______
    //                                 └────────┘   └────────┘       └────────┘   └────────┘
    ),

    [MISC] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
        RESET   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
    // └────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                        _______ ,    _______ ,        _______ ,    _______
    //                                 └────────┘   └────────┘       └────────┘   └────────┘
    ),
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case L_SYM:
    case L_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_layer_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case L_SYM:
    case L_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case L_SYM:
    case L_NAV:
    // TODO: figure out if this case is needed
    // case KC_LSFT:
    case OS_SFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_GUI:
    case OS_FUN:
    case OS_MISC:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_mod_key(uint16_t keycode) {
    switch (keycode) {
    case OS_SFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_GUI:
        return true;
    default:
        return false;
    }
}

oneshot_state os_sft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;
oneshot_state os_fun_state = os_up_unqueued;
oneshot_state os_misc_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_sft_state, KC_LSFT, OS_SFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_gui_state, KC_LCMD, OS_GUI,
        keycode, record
    );

    bool handled = true;
    handled = update_oneshot_layer(
        &os_fun_state, FUNCTIONS_NUMPAD, OS_FUN,
        keycode, record
    ) & handled;

    handled = update_oneshot_layer(
        &os_misc_state, MISC, OS_MISC,
        keycode, record
    ) & handled;

    if (!handled) return false;

    return true;
}
