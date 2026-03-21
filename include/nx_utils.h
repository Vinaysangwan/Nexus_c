#pragma once

// #############################################################################
//                           Typedefs
// #############################################################################
typedef int bool;
#define true 1
#define false 0

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

typedef struct
{
  int r;
  int g;
  int b;
  int a;
} Color;

// #############################################################################
//                           Constants
// #############################################################################
// Colors
static const Color COLOR_RED        = {255,   0,   0, 255};
static const Color COLOR_GREEN      = {  0, 255,   0, 255};
static const Color COLOR_BLUE       = {  0,   0, 255, 255};
static const Color COLOR_WHITE      = {255, 255, 255, 255};
static const Color COLOR_BLACK      = {  0,   0,   0, 255};
static const Color COLOR_YELLOW     = {255, 255,   0, 255};
static const Color COLOR_CYAN       = {  0, 255, 255, 255};
static const Color COLOR_MAGENTA    = {255,   0, 255, 255};
static const Color COLOR_ORANGE     = {255, 165,   0, 255};
static const Color COLOR_PURPLE     = {128,   0, 128, 255};
static const Color COLOR_PINK       = {255, 192, 203, 255};
static const Color COLOR_LIME       = { 50, 205,  50, 255};
static const Color COLOR_SKYBLUE    = {135, 206, 235, 255};
static const Color COLOR_GOLD       = {255, 215,   0, 255};
static const Color COLOR_BROWN      = {139,  69,  19, 255};
static const Color COLOR_LIGHTGRAY  = {200, 200, 200, 255};
static const Color COLOR_GRAY       = {130, 130, 130, 255};
static const Color COLOR_DARKGRAY   = { 80,  80,  80, 255};
