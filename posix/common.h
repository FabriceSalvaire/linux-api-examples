// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright Fabrice SALVAIRE 2022

#ifndef COMMON_H
#define COMMON_H

#define UNUSED(x) (void)(x)

#define handle_error(msg) \
  do { perror(msg); exit(EXIT_FAILURE); } while (0)

#endif // COMMON_H
