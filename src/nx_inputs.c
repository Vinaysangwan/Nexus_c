#include "Nexus_c.h"

#include <string.h>
#include <windows.h>

Input input = {0};

// #############################################################################
//                           Keyboard Functions
// #############################################################################
bool key_down(KeyCode key)
{
  return input.currKeys[key];
}

bool key_pressed(KeyCode key)
{
  return input.currKeys[key] && !input.prevKeys[key];
}

bool key_released(KeyCode key)
{
  return !input.currKeys[key] && input.prevKeys[key];
}

// #############################################################################
//                           Common Functions
// #############################################################################
void input_update()
{
  memcpy(input.prevKeys, input.currKeys, KEY_COUNT);
}
