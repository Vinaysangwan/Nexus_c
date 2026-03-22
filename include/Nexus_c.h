#pragma once

#include "glad/glad.h"

// #############################################################################
//                           Custom types
// #############################################################################
typedef int bool;
#define true 1
#define false 0

// #############################################################################
//                           Colors
// #############################################################################
typedef struct
{
  int r;
  int g;
  int b;
  int a;
} Color;

extern const Color COLOR_RED;
extern const Color COLOR_GREEN;
extern const Color COLOR_BLUE;
extern const Color COLOR_WHITE;
extern const Color COLOR_BLACK;
extern const Color COLOR_YELLOW;
extern const Color COLOR_CYAN;
extern const Color COLOR_MAGENTA;
extern const Color COLOR_ORANGE;
extern const Color COLOR_PURPLE;
extern const Color COLOR_PINK;
extern const Color COLOR_LIME;
extern const Color COLOR_SKYBLUE;
extern const Color COLOR_GOLD;
extern const Color COLOR_BROWN;
extern const Color COLOR_LIGHTGRAY;
extern const Color COLOR_GRAY;
extern const Color COLOR_DARKGRAY;

// #############################################################################
//                           Vectors
// #############################################################################
typedef struct
{
  int x;
  int y;
} Vec2i;

typedef struct
{
  float x;
  float y;
} Vec2;

Vec2i vec2_i(Vec2 vec);
Vec2 vec2i_f(Vec2i vec);

typedef struct
{
  int x;
  int y;
  int z;
} Vec3i;

typedef struct
{
  float x;
  float y;
  float z;
} Vec3;

Vec3i vec3_i(Vec3 vec);
Vec3 vec3i_f(Vec3i vec);

typedef struct
{
  int x;
  int y;
  int z;
  int w;
} Vec4i;

typedef struct
{
  float x;
  float y;
  float z;
  float w;
} Vec4;

// #############################################################################
//                           nput Structs
// #############################################################################
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

  KEY_COUNT = 256
} KeyCode;

typedef enum {
  MOUSE_LEFT   = 0,
  MOUSE_RIGHT  = 1,
  MOUSE_MIDDLE = 2,

  MOUSE_BTN_COUNT = 3,
} MouseButton;

typedef struct
{
  // Keyboard
  unsigned char prevKeys[KEY_COUNT];
  unsigned char currKeys[KEY_COUNT];

  // Mouse
  unsigned char prevMouseBtns[MOUSE_BTN_COUNT];
  unsigned char currMouseBtns[MOUSE_BTN_COUNT];
  int mouseX, mouseY;
  int prevMouseX, prevMouseY;
  int mouseScroll;
} Input;

// #############################################################################
//                           Static
// #############################################################################
extern Input input;

// #############################################################################
//                           Input Functions
// #############################################################################
// Keyboard Functions
bool key_down(KeyCode key);
bool key_pressed(KeyCode key);
bool key_released(KeyCode key);

// Mouse Functions
bool mouse_button_down(MouseButton btn);
bool mouse_button_pressed(MouseButton btn);
bool mouse_button_released(MouseButton btn);
int mouse_x(void);
int mouse_y(void);
Vec2i mouse_pos(void);
int mouse_dx(void);
int mouse_dy(void);
int mouse_scroll(void);

// Common Functions
void input_update(void);

// #############################################################################
//                           Window Functions
// #############################################################################
Vec4i vec4_i(Vec4 vec);
Vec4 vec4i_f(Vec4i vec);

bool window_create(const char *title, int width, int height);
bool window_isOpen(void);
void window_stop(void);
void window_close(void);

int window_get_width(void);
int window_get_height(void);
Vec2i window_get_size(void);

void clear_background(const Color *color);

// #############################################################################
//                           Audio Functions
// #############################################################################
bool audio_init(void);
void audio_close(void);

// #############################################################################
//                           Sound Functions
// #############################################################################
typedef struct NxSound NxSound;

NxSound* sound_load(const char* path);
void sound_free(NxSound* sound);

void sound_play(NxSound* sound);

void sound_set_volume(NxSound* sound, float volume);
float sound_get_volume(NxSound* sound);

// #############################################################################
//                           music Functions
// #############################################################################
typedef struct NxMusic NxMusic;

NxMusic* music_load(const char* path);
void music_free(NxMusic* music);

void music_play(NxMusic* music);
void music_stop(NxMusic* music);
void music_pause(NxMusic* music);
void music_resume(NxMusic* music);
bool music_is_playing(NxMusic* music);

void music_set_volume(NxMusic* music, float volume);
float music_get_volume(NxMusic* music);
