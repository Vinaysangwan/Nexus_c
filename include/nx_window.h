#pragma once

#include "glad/glad.h"
#include "nx_utils.h"
#include "nx_inputs.h"

bool window_create(const char *title, int width, int height);
bool window_isOpen(void);
void window_stop(void);
void window_close(void);

int window_get_width(void);
int window_get_height(void);
Vec2i window_get_size(void);

void clear_background(const Color *color);
