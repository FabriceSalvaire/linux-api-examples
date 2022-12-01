# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright Fabrice SALVAIRE 2022

####################################################################################################

cmake_minimum_required(VERSION 3.16)
project(posix-examples LANGUAGES C)

####################################################################################################

add_subdirectory(config)
add_subdirectory(epoll)
add_subdirectory(fork)
add_subdirectory(signal)
