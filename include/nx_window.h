#pragma once

#include "glad/glad.h"
#include "nx_utils.h"
#include "nx_inputs.h"

bool window_create(const char *title, int width, int height);
bool window_isOpen();
void window_stop();
void window_close();
void clear_background(const Color *color);

int window_get_width();
int window_get_height();
Vec2i window_get_size();
