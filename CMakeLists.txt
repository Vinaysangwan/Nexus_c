cmake_minimum_required(VERSION 3.20)
project(Nexus_c C)

add_library(Nexus_c STATIC
  src/nx_window.c
)

target_include_directories(Nexus_c PUBLIC include/)
