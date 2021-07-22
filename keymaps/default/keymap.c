/* Copyright 2021 Andrew Budziszek
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
    _TOP_LAYER,
    _APPLICATION_LAUNCH_LAYER,
    _RGB_LAYER,
    _DISCORD_LAYER,
    _STREAMLABS_LAYER,
    _PROGRAMMING_LAYER,
    _MAC_LAYER
};

enum custom_keycodes {
    STEAM = SAFE_RANGE, // SAFE_RANGE prevents it from using a clashing keycode
    SLACK,
    DISCORD,
    WEB_BROWSER,
    FILE_BROWSER,
    LOGIN_PIN,
    MUTE_DISCORD,
    COPY,
    SAVE,
    PASTE,
    HOME,
    CTL_TAB,
    TOGGLE_MUTE_ZOOM,
    END_ZOOM_CALL,
    PLACEHOLDER_KEYCODE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_TOP_LAYER] = LAYOUT(TO(_APPLICATION_LAUNCH_LAYER), LOGIN_PIN, TO(_DISCORD_LAYER), RGB_MODE_RGBTEST, RGB_MODE_SNAKE, RGB_MODE_XMAS),
    [_APPLICATION_LAUNCH_LAYER] = LAYOUT(TO(_RGB_LAYER), STEAM, DISCORD, SLACK, WEB_BROWSER, FILE_BROWSER),
    [_RGB_LAYER] = LAYOUT(TO(_DISCORD_LAYER), RGB_MODE_RAINBOW, RGB_MODE_RGBTEST, RGB_MODE_KNIGHT, RGB_MODE_SNAKE, RGB_MODE_XMAS),
    [_DISCORD_LAYER] = LAYOUT(TO(_PROGRAMMING_LAYER), MUTE_DISCORD, RGB_MODE_RAINBOW, RGB_MODE_RGBTEST, RGB_MODE_KNIGHT, RGB_MODE_SNAKE),
    [_PROGRAMMING_LAYER] = LAYOUT(TO(_TOP_LAYER), SAVE, CTL_TAB, COPY, PASTE, HOME),
    [_MAC_LAYER] = LAYOUT(TO(_TOP_LAYER), TOGGLE_MUTE_ZOOM, END_ZOOM_CALL, PLACEHOLDER_KEYCODE, PLACEHOLDER_KEYCODE, PLACEHOLDER_KEYCODE)
    // [_STREAMLABS_LAYER] = LAYOUT(),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _TOP_LAYER:
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        case _PROGRAMMING_LAYER:
            if (clockwise) {
                tap_code16(C(KC_Y));
            } else {
                tap_code16(C(KC_Z));
            }
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case STEAM:
            if (record->event.pressed) {
                tap_code16(G(KC_6));
            }
            break;

        case SLACK:            if (record->event.pressed) {
                tap_code16(G(KC_4));
            }
            break;

        case DISCORD:
            if (record->event.pressed) {
                tap_code16(G(KC_3));
            }
            break;

        case WEB_BROWSER:
            if (record->event.pressed) {
                tap_code16(G(KC_2));
            }
            break;

        case FILE_BROWSER:
            if (record->event.pressed) {
                tap_code16(G(KC_1));
            }
            break;
        case LOGIN_PIN:
            if(record->event.pressed) {
                tap_code16(KC_KP_1);
                tap_code16(KC_KP_2);
                tap_code16(KC_KP_3);
                tap_code16(KC_KP_4);
                tap_code16(KC_ENTER);
            }
            break;
        case MUTE_DISCORD:
            if(record->event.pressed) {
                tap_code16(C(S(KC_F13)));
            }
            break;
        case COPY:
            if(record->event.pressed) {
                tap_code16(C(KC_C));
            }
            break;
        case PASTE:
            if(record->event.pressed) {
                tap_code16(C(KC_V));
            }
            break;
        case SAVE:
            if(record->event.pressed) {
                tap_code16(C(KC_S));
            }
            break;
        case HOME:
            if(record->event.pressed) {
                tap_code16(KC_HOME);
            }
            break;
        case CTL_TAB:
            if(record->event.pressed) {
                tap_code16(C(KC_TAB));
            }
            break;
        case TOGGLE_MUTE_ZOOM:
            if(record->event.pressed) {
                tap_code16(G(S(KC_A)));
            }
            break;
        case PLACEHOLDER_KEYCODE:
            if(record->event.pressed) {
                tap_code16(KC_SPACE);
            }
            break;
        case END_ZOOM_CALL:
            if(record->event.pressed) {
                tap_code16(G(KC_W));
            }
            break;
    }
    return true;
}


#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;  // flips the display 90 degrees if offhand
}

void oled_task_user(void) {
    // Host Keyboard Layer Status

    switch (get_highest_layer(layer_state)) {
        case _TOP_LAYER:
            oled_write_P(PSTR("MAIN\n---\nPIN\n\n\n"), false);
            break;
        case _APPLICATION_LAUNCH_LAYER:
            oled_write_P(PSTR("APPS\n---\nSteam\nDisc.\nSlack\nBrave\nFS\n"), false);
            break;
        case _RGB_LAYER:
            oled_write_P(PSTR("RGB\n---\nRain.\nTest\n\nKR\n\nSnake\nX-Mas\n"), false);
            break;
        case _DISCORD_LAYER:
            oled_write_P(PSTR("DCRD\n---\nMute\n"), false);
            break;
        case _PROGRAMMING_LAYER:
            oled_write_P(PSTR("PRGM\n---\nSave \nCTAB \nCopy \nPaste\nHome\n"), false);
            break;
        case _MAC_LAYER:
            oled_write_P(PSTR("Zoom\n---\nMute \nEND \n\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}
#endif