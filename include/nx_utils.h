#pragma once

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

Vec4i vec4_i(Vec4 vec);
Vec4 vec4i_f(Vec4i vec);
