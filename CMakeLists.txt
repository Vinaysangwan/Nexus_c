cmake_minimum_required(VERSION 3.20)
project(Nexus_c C)

add_library(${PROJECT_NAME} STATIC
  src/nx_window.c
  src/glad.c
)

target_include_directories(${PROJECT_NAME} PUBLIC include/)

# OpenGL
target_link_libraries(${PROJECT_NAME} PUBLIC opengl32)
