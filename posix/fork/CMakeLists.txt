# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright Fabrice SALVAIRE 2022

####################################################################################################

cmake_minimum_required(VERSION 3.16)
project(fork LANGUAGES C)

set(CMAKE_C_STANDARD 99)

add_compile_options(
  -Wall -Wextra -Wpedantic -Werror
)

####################################################################################################

add_executable(${PROJECT_NAME}
  main.c
)

add_executable(fork-child
  child.c
)
