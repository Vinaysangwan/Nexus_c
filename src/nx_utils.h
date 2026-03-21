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
static const Color RED        = {255,   0,   0, 255};
static const Color GREEN      = {  0, 255,   0, 255};
static const Color BLUE       = {  0,   0, 255, 255};
static const Color WHITE      = {255, 255, 255, 255};
static const Color BLACK      = {  0,   0,   0, 255};
static const Color YELLOW     = {255, 255,   0, 255};
static const Color CYAN       = {  0, 255, 255, 255};
static const Color MAGENTA    = {255,   0, 255, 255};
static const Color ORANGE     = {255, 165,   0, 255};
static const Color PURPLE     = {128,   0, 128, 255};
static const Color PINK       = {255, 192, 203, 255};
static const Color LIME       = { 50, 205,  50, 255};
static const Color SKYBLUE    = {135, 206, 235, 255};
static const Color GOLD       = {255, 215,   0, 255};
static const Color BROWN      = {139,  69,  19, 255};
static const Color LIGHTGRAY  = {200, 200, 200, 255};
static const Color GRAY       = {130, 130, 130, 255};
static const Color DARKGRAY   = { 80,  80,  80, 255};
