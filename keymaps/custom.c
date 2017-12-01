#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german_ch.h"

#define EECONFIG_PLATFORM (uint8_t *)0x10

enum custom_keycodes {
	PLACEHOLDER = SAFE_RANGE, // can always be here
	EPRM,
	VRSN,
	RGB_SLD,
	PW1,
	PW2,
	BL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = KEYMAP(
		KC_AMPR,		KC_LBRACKET,	KC_LCBR,	KC_RCBR,	KC_LPRN,	KC_SCOLON,	TO(6),
		LT(2,KC_TAB),	KC_EQUAL,		KC_COMMA,	KC_DOT,		KC_P,		KC_Y,		BL,
		KC_BSPACE,		KC_A,			KC_O,		KC_E,		KC_U,		KC_I,
		F(2),			KC_QUOTE,		KC_Q,		KC_J,		KC_K,		KC_X,		TG(3),
		KC_TRNS,		KC_DLR,			KC_AT,		KC_LALT,	KC_LGUI,
		
							KC_TRNS,	KC_TRNS,
										KC_HOME,
		CTL_T(KC_ESCAPE),	KC_DELETE,	KC_END,
		
		
		TO(4),			KC_ASTR,		KC_RPRN,		KC_PLUS,	KC_RBRACKET,KC_EXLM,	KC_HASH,
		KC_TRNS,		KC_F,			KC_G,			KC_C,		KC_R,		KC_L,		KC_SLASH,
						KC_D,			KC_H,			KC_T,		KC_N,		KC_S,		KC_MINUS,
		KC_TRNS,		KC_B,			KC_M,			KC_W,		KC_V,		KC_Z,		KC_BSLASH,
										CTL_T(KC_NO),	KC_LEFT,	KC_DOWN,	KC_UP,		KC_RIGHT,
										
		KC_TRNS,		KC_TRNS,
		KC_PGUP,
		KC_PGDOWN,		KC_ENTER,	KC_SPACE),

	[1] = KEYMAP(
		KC_TRNS,		KC_F1,			KC_F2,			KC_F3,			KC_F4,		KC_F5,		KC_F6,
		LSFT(KC_TAB),	KC_COLN,		LSFT(KC_COMMA),	LSFT(KC_DOT),	LSFT(KC_P),	LSFT(KC_Y),	KC_F7,
		LSFT(KC_BSPACE),LSFT(KC_A),		LSFT(KC_O),		LSFT(KC_E),		LSFT(KC_U),	LSFT(KC_I),
		KC_TRNS,		LSFT(KC_QUOTE),	LSFT(KC_Q),		LSFT(KC_J),		LSFT(KC_K),	LSFT(KC_X),	KC_F8,
		KC_TRNS,		KC_TILD,		KC_CIRC,		KC_LALT,	KC_LGUI,
		
							KC_TRNS,	KC_TRNS,
										KC_TRNS,
				KC_TRNS,	KC_TRNS,	KC_TRNS,
				
		KC_F11,			KC_F12,			KC_F13,			KC_F14,			KC_F15,			KC_PERC,	KC_GRAVE,
		KC_F10,			LSFT(KC_F),		LSFT(KC_G),		LSFT(KC_C),		LSFT(KC_R),		LSFT(KC_L),	LSFT(KC_SLASH),
						LSFT(KC_D),		LSFT(KC_H),		LSFT(KC_T),		LSFT(KC_N),		LSFT(KC_S),	KC_UNDS,
		KC_F9,			LSFT(KC_B),		LSFT(KC_M),		LSFT(KC_W),		LSFT(KC_V),		LSFT(KC_Z),	KC_PIPE,
										KC_TRNS,		LSFT(KC_LEFT),	LSFT(KC_DOWN),	LSFT(KC_UP),LSFT(KC_RIGHT),
										
				KC_TRNS,	KC_TRNS,
				KC_TRNS,
				KC_TRNS,	LSFT(KC_ENTER),	LSFT(KC_SPACE)),

	[2] = KEYMAP(KC_TRNS,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRNS,KC_TRNS,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,KC_TRNS,KC_HASH,KC_DLR,KC_LPRN,KC_RPRN,KC_GRAVE,KC_TRNS,KC_PERC,KC_CIRC,KC_LBRACKET,KC_RBRACKET,KC_TILD,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_TRNS,KC_TRNS,KC_TRNS,KC_7,KC_8,KC_9,KC_TRNS,KC_TRNS,KC_TRNS,KC_4,KC_5,KC_6,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_1,KC_2,KC_3,KC_TRNS,KC_TRNS,KC_DOT,KC_0,KC_EQUAL,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS),

	[3] = KEYMAP(PW1,PW2,KC_TRNS,BL,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,KC_AUDIO_VOL_UP,KC_TRNS,KC_TRNS,KC_TRNS,KC_MEDIA_REWIND,KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_MEDIA_FAST_FORWARD,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,VRSN,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_SYSTEM_POWER,KC_TRNS,KC_TRNS,KC_TRNS,KC_MS_UP,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,RESET,KC_TRNS,KC_TRNS,KC_TRNS,KC_MS_BTN2,KC_MS_BTN1),

	[4] = KEYMAP(KC_ESCAPE,KC_1,KC_2,KC_3,KC_4,KC_5,TO(0),KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_TRNS,LT(5,KC_CAPSLOCK),KC_A,KC_S,KC_D,KC_F,KC_G,KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_TRNS,KC_LCTL,KC_GRAVE,KC_TRNS,KC_LALT,KC_LGUI,KC_NONUS_BSLASH,KC_EQUAL,KC_HOME,KC_SPACE,KC_BSPACE,KC_END,TO(6),KC_6,KC_7,KC_8,KC_9,KC_0,KC_QUOTE,KC_TRNS,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_LBRACKET,KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_QUOTE,KC_TRNS,KC_N,KC_M,KC_COMMA,KC_DOT,KC_MINUS,KC_RSHIFT,KC_RGUI,KC_LEFT,KC_UP,KC_DOWN,KC_RIGHT,KC_RBRACKET,KC_BSLASH,KC_PGUP,KC_PGDOWN,KC_ENTER,KC_SPACE),

	[5] = KEYMAP(KC_ESCAPE,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_F12,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS),

	[6] = KEYMAP(
		KC_AMPR,		KC_LBRACKET,	KC_LCBR,	KC_RCBR,	KC_LPRN,	KC_SCOLON,	TO(4),
		KC_TAB,			KC_EQUAL,		KC_COMMA,	KC_DOT,		KC_P,		KC_Y,		BL,
		KC_BSPACE,		KC_A,			KC_O,		KC_E,		KC_U,		KC_I,
		KC_LSHIFT,		KC_QUOTE,		KC_Q,		KC_J,		KC_K,		KC_X,		TG(3),
		KC_LCTL,		KC_DLR,			KC_AT,		KC_LALT,	KC_SPACE,
		
							KC_TRNS,	KC_TRNS,
										KC_HOME,
				KC_ESCAPE,	KC_LGUI,	KC_END,
		
		
		TO(0),			KC_ASTR,		KC_RPRN,		KC_PLUS,	KC_RBRACKET,KC_EXLM,	KC_HASH,
		KC_TRNS,		KC_F,			KC_G,			KC_C,		KC_R,		KC_L,		KC_SLASH,
						KC_D,			KC_H,			KC_T,		KC_N,		KC_S,		KC_MINUS,
		KC_TRNS,		KC_B,			KC_M,			KC_W,		KC_V,		KC_Z,		KC_BSLASH,
										CTL_T(KC_NO),	KC_LEFT,	KC_DOWN,	KC_UP,		KC_RIGHT,
										
		KC_TRNS,		KC_TRNS,
		KC_PGUP,
		KC_PGDOWN,		KC_ENTER,	KC_SPACE),


};

const uint16_t PROGMEM fn_actions[] = {
	[1] = ACTION_LAYER_TAP_TOGGLE(1),
	[2] = ACTION_LAYER_MODS(1, MOD_LSFT),
};


static uint16_t c = 0; 
void blink(void) {
	c = 1 << 7;
	ergodox_right_led_3_on();
}


static uint8_t to_put = 0;

void debug_blink(uint8_t n) {
	if (to_put) return;
	else to_put = n;
}

//static uint8_t os = 0; 


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (!record->event.pressed) return true;

	switch (keycode) {
	case EPRM:
		eeconfig_init();
		return false;
	case VRSN:
		SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
		return false;
	case PW1:
		SEND_STRING ("@PW1@\n");
		blink();
		return false;
	case PW2:
		SEND_STRING ("REDACTED\n");
		blink();
		return false;
	case BL:
		//uint8_t *p = (uint8_t *) 12;
		//uint8_t x = eeprom_read_byte(p);
		//debug_blink(x);
		//eeprom_update_byte(p, x+1);
		//return false;
	case KC_GRAVE:
	case KC_F1:
	case KC_F2:
	case KC_F3:
	case KC_F4:
	case KC_F5:
	case KC_F6:
	case KC_F7:
	case KC_F8:
	case KC_F9:
	case KC_F10:
	case KC_F11:
	case KC_F12:
	case KC_F13:
	case KC_F14:
	case KC_F15:
		if (biton32(layer_state) == 1) {
			uint8_t mods = get_mods();
			clear_mods();
			send_keyboard_report();
			register_code(keycode);
			unregister_code(keycode);
			register_mods(mods);
			return false;
		}
		break;
	}
	return true;
}

#define WAT 50

void debug_loop(void) {
	static int16_t counter = -WAT;
	if (!to_put) return;

	if (counter == -WAT) {
		counter = (to_put % 2 + 1) * WAT;
	} else {
		counter--;
	}

	if (counter > 0) {
		ergodox_right_led_2_on();
	} else if (counter < 0) {
		ergodox_right_led_2_off();
	} else if (counter == -WAT) {
		to_put /= 2;
	}
}

static uint16_t counter = 0;
static uint8_t layer_to_blink = 0;

#define CYCLE (1<<9)
#define BLINK (1<<5)
void show_layer(void) {
	uint8_t layer = biton32(layer_state);
	ergodox_right_led_1_off();
	
	if (layer != layer_to_blink) {
		counter = 0;
		layer_to_blink = layer;
	}

	uint16_t sub = counter / BLINK;
	if (layer_to_blink > sub/2) {
		if (sub%2 == 0) {
			 ergodox_right_led_1_on();
		}
	}

	counter++;

	if (layer_to_blink < sub/2) {
		counter = 0;
	}		
}

void blink_loop(void) {
	if (c)
		c--;
	else
		ergodox_right_led_3_off();	
}

void matrix_init_user(void) {
	
}

void matrix_scan_user(void) {
	blink_loop();	
	debug_loop();
	show_layer();
	return;
};
