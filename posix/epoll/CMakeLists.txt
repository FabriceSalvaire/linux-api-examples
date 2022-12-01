# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright Fabrice SALVAIRE 2022

####################################################################################################

cmake_minimum_required(VERSION 3.16)
project(epoll LANGUAGES C)

set(CMAKE_C_STANDARD 99)

####################################################################################################

add_executable(${PROJECT_NAME}
  main.c
)
