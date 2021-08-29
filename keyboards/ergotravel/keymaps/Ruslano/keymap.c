#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,--------------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+---------------.
     KC_ESC,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_HOME,          KC_END,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //|--------------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+---------------|
     KC_TAB,        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MINS,          KC_INS,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SLSH, KC_ENT,
  //|--------------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+---------------|
     LSFT_T(KC_DEL),KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_A,             KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   RSFT_T(KC_SLSH),
  //|--------------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+---------------|
     KC_LCTL,       KC_LGUI, KC_LALT, LOWER,            RAISE,   KC_SPC,           KC_SPC,  KC_RALT,          KC_SCLN, KC_LEFT, KC_DOWN, KC_RGHT
  //`--------------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+---------------'
  ),

  [_RAISE] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+---------------.
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_COMM,          KC_DOT,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,       \
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+---------------|
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_END ,          KC_PGDN, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_ENT,        \
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+---------------|
     KC_LSFT, KC_SLSH, KC_BSLS, KC_QUOT, KC_QUES, KC_MINS, KC_UNDS,          KC_MINS, KC_UNDS, KC_PLUS, KC_EQL,  KC_LCBR, KC_RCBR, KC_RSFT,       \
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+---------------|
     KC_LCTL, KC_LGUI, KC_LALT, KC_PSCR,          _______, KC_SPC,           KC_SPC,  KC_RALT,          KC_RGUI, KC_LBRC, KC_RBRC, KC_RCTL        \
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+---------------'

  ),

  [_LOWER] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+---------------.
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______,          _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,        \
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+---------------|
     KC_CAPS, KC_INS,  KC_HOME, KC_PGUP, _______, _______, _______,          _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_ENT,        \
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+---------------|
     KC_LSFT, KC_DEL,  KC_END,  KC_PGDN, _______, _______, _______,          _______, _______, KC_PSCR, KC_NUBS, KC_PAUS, _______, KC_RSFT,       \
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+---------------|
     KC_LCTL, KC_LGUI, KC_LALT, _______,          ADJUST,  KC_BSPC,          KC_BSPC, KC_RALT,          KC_RGUI, KC_APP,  _______, KC_RCTL        \
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+---------------'
  ),

  [_ADJUST] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+---------------.
     _______,  _______,  _______, _______, _______, _______, RESET,          _______, _______, _______, _______, _______, _______, CALTDEL,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+---------------|
     _______, _______,  _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+---------------|
     _______, _______,  _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+---------------|
     _______, _______, _______, _______,           _______, _______,         _______, _______,          _______, _______, _______, RESET
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+---------------'
  )

};







bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}