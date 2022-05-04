#include QMK_KEYBOARD_H

//#define _QWERTY 0
//#define _LOWER 1
//#define _RAISE 2
//#define _ADJUST 16
#define DEFAULT TO(_QWERTY)
#define LOWER MO(_LOWER) // momentary lower layer
#define RAISE MO(_RAISE) // momentary raise layer
#define ADJUST MO(_ADJUST) // momentary adjust layer
#define NUMPAD TG(_ADJUST) // lock to adjust layer

//#define CALTDEL LCTL(LALT(KC_DEL))
//#define TSKMGR LCTL(LSFT(KC_ESC))

enum custom_keycodes {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,--------------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+---------------.
     KC_ESC,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_HOME,          KC_INS,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //|--------------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+---------------|
     KC_TAB,        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_END,           KC_INS,  KC_H,    KC_J,    KC_K,    KC_L,    KC_BSLS, KC_ENT,
  //|--------------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+---------------|
     LSFT_T(KC_DEL),KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MINS,          KC_UNDS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   RSFT_T(KC_SLSH),
  //|--------------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+---------------|
     KC_LCTL,       KC_LGUI, KC_LALT, LOWER,            RAISE,   KC_SPC,           KC_SPC,  TG(16),           KC_SCLN, KC_LEFT, KC_DOWN, KC_RGHT
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
     KC_ESC,   KC_NUM,  KC_KP_1, KC_KP_2, KC_KP_3, KC_PMNS, _______,          KC_BRIU, _______, _______, _______, _______, _______, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+---------------|
     KC_TAB,  KC_PSLS,  KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, KC_PENT,         KC_BRID, _______, _______, _______, _______, KC_MUTE, KC_MPLY,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+---------------|
     KC_LSFT, KC_PAST,  KC_KP_7, KC_KP_8, KC_KP_9, KC_PENT, _______,         _______, _______, _______, _______, KC_MRWD, KC_VOLU, KC_MFFD,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+---------------|
     KC_LCTL, KC_PEQL,  KC_KP_0, KC_PDOT,          KC_RALT, KC_SPC,          RESET,   TO(0),            DEFAULT, KC_MPRV, KC_VOLD, KC_MNXT
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+---------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      /* Not needed?
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
      */
  }
  return true;
}
