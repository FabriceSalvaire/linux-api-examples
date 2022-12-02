# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright Fabrice SALVAIRE 2022

####################################################################################################

cmake_minimum_required(VERSION 3.16)
project(socket LANGUAGES C)

set(CMAKE_C_STANDARD 99)

add_compile_options(
  -Wall -Wextra -Wpedantic -Werror
)

####################################################################################################

add_executable(server-inet
  server-inet.c
)
add_executable(client-inet
  client-inet.c
)
