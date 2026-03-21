#pragma once

#include "glad/glad.h"

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
static const Color RED = {255, 0, 0, 255};
static const Color GREEN = {0, 255, 0, 255};
static const Color BLUE = {0, 0, 255, 255};

// #############################################################################
//                           Window Functions
// #############################################################################
bool create_window(const char *title, int width, int height);
bool window_isOpen();
void close_window();
void clear_background(const Color *color);

int get_window_width();
int get_window_height();
Vec2i get_window_size();
