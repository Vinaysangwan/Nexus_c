cmake_minimum_required(VERSION 3.20)
project(Nexus_c C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(${PROJECT_NAME} STATIC
  src/glad.c
  src/nx_audio.c
  src/nx_inputs.c
  src/nx_utils.c
  src/nx_window.c
)

target_include_directories(${PROJECT_NAME} PUBLIC 
  include/
)

# OpenGL
target_link_libraries(${PROJECT_NAME} PUBLIC opengl32)
