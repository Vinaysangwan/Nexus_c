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
//                           Mouse Functions
// #############################################################################
bool mouse_button_down(MouseButton btn)
{
  return input.currMouseBtns[btn];
}

bool mouse_button_pressed(MouseButton btn)
{
  return input.currMouseBtns[btn] && !input.prevMouseBtns[btn];
}

bool mouse_button_released(MouseButton btn)
{
  return !input.currMouseBtns[btn] && input.prevMouseBtns[btn];
}

int mouse_x(void)
{
  return input.mouseX;
}

int mouse_y(void)
{
  return input.mouseY;
}

Vec2i mouse_pos(void)
{
  return (Vec2i){
    input.mouseX,
    input.mouseY
  };
}

int mouse_dx(void)
{
  return input.mouseX - input.prevMouseX;
}

int mouse_dy(void)
{
  return input.mouseY - input.prevMouseY;
}

int mouse_scroll(void)
{
  return input.mouseScroll;
}

// #############################################################################
//                           Common Functions
// #############################################################################
void input_update(void)
{
  memcpy(input.prevKeys, input.currKeys, KEY_COUNT);
  memcpy(input.prevMouseBtns, input.currMouseBtns, MOUSE_BTN_COUNT);

  input.prevMouseX = input.mouseX;
  input.prevMouseY = input.mouseY;

  input.mouseScroll = 0;
}
