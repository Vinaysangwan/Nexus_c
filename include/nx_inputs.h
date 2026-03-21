#pragma once

typedef enum {
  // Letters
  KEY_A = 'A', KEY_B, KEY_C, KEY_D, KEY_E,
  KEY_F, KEY_G, KEY_H, KEY_I, KEY_J,
  KEY_K, KEY_L, KEY_M, KEY_N, KEY_O,
  KEY_P, KEY_Q, KEY_R, KEY_S, KEY_T,
  KEY_U, KEY_V, KEY_W, KEY_X, KEY_Y, KEY_Z,

  // Digits
  KEY_0 = '0', KEY_1, KEY_2, KEY_3, KEY_4,
  KEY_5,       KEY_6, KEY_7, KEY_8, KEY_9,

  // Function keys
  KEY_F1  = 0x70, KEY_F2,  KEY_F3,  KEY_F4,
  KEY_F5,         KEY_F6,  KEY_F7,  KEY_F8,
  KEY_F9,         KEY_F10, KEY_F11, KEY_F12,

  // Navigation & control
  KEY_UP        = 0x26,
  KEY_DOWN      = 0x28,
  KEY_LEFT      = 0x25,
  KEY_RIGHT     = 0x27,
  KEY_ESCAPE    = 0x1B,
  KEY_ENTER     = 0x0D,
  KEY_SPACE     = 0x20,
  KEY_TAB       = 0x09,
  KEY_BACKSPACE = 0x08,
  KEY_DELETE    = 0x2E,
  KEY_INSERT    = 0x2D,
  KEY_HOME      = 0x24,
  KEY_END       = 0x23,
  KEY_PAGEUP    = 0x21,
  KEY_PAGEDOWN  = 0x22,
  KEY_LSHIFT    = 0xA0,
  KEY_RSHIFT    = 0xA1,
  KEY_LCTRL     = 0xA2,
  KEY_RCTRL     = 0xA3,
  KEY_LALT      = 0xA4,
  KEY_RALT      = 0xA5,
} Keycode;
