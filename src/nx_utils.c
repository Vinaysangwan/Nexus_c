#include "Nexus_c.h"

// #############################################################################
//                           Comment
// #############################################################################
const Color COLOR_RED        = {255,   0,   0, 255};
const Color COLOR_GREEN      = {  0, 255,   0, 255};
const Color COLOR_BLUE       = {  0,   0, 255, 255};
const Color COLOR_WHITE      = {255, 255, 255, 255};
const Color COLOR_BLACK      = {  0,   0,   0, 255};
const Color COLOR_YELLOW     = {255, 255,   0, 255};
const Color COLOR_CYAN       = {  0, 255, 255, 255};
const Color COLOR_MAGENTA    = {255,   0, 255, 255};
const Color COLOR_ORANGE     = {255, 165,   0, 255};
const Color COLOR_PURPLE     = {128,   0, 128, 255};
const Color COLOR_PINK       = {255, 192, 203, 255};
const Color COLOR_LIME       = { 50, 205,  50, 255};
const Color COLOR_SKYBLUE    = {135, 206, 235, 255};
const Color COLOR_GOLD       = {255, 215,   0, 255};
const Color COLOR_BROWN      = {139,  69,  19, 255};
const Color COLOR_LIGHTGRAY  = {200, 200, 200, 255};
const Color COLOR_GRAY       = {130, 130, 130, 255};
const Color COLOR_DARKGRAY   = { 80,  80,  80, 255};

// #############################################################################
//                           Vectors
// #############################################################################
Vec2i vec2_i(Vec2 vec)
{
  return (Vec2i) {(int)vec.x, (int)vec.y};
}

Vec2 vec2i_f(Vec2i vec)
{
  return (Vec2) {(float)vec.x, (float)vec.y};
}

Vec3i vec3_i(Vec3 vec)
{
  return (Vec3i) {(int)vec.x, (int)vec.y, (int)vec.z};
}

Vec3 vec3i_f(Vec3i vec)
{
  return (Vec3) {(float)vec.x, (float)vec.y, (float)vec.z};
}

Vec4i vec4_i(Vec4 vec)
{
  return (Vec4i) {(int)vec.x, (int)vec.y, (int)vec.z, (int)vec.w};
}

Vec4 vec4i_f(Vec4i vec)
{
  return (Vec4) {(float)vec.x, (float)vec.y, (float)vec.z, (float)vec.w};
}
