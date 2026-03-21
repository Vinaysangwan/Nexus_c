#pragma once

#include "glad/glad.h"
#include "nx_utils.h"

bool create_window(const char *title, int width, int height);
bool window_isOpen();
void close_window();
void clear_background(const Color *color);

int get_window_width();
int get_window_height();
Vec2i get_window_size();
