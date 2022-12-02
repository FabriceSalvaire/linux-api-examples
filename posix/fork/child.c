// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright Fabrice SALVAIRE 2022

/**************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/**************************************************************************************************/

int
main()
{
  pid_t process_pid = getpid();
  printf("I am a child with PID=%u\n", process_pid);
  // sleep(1);
  printf("Exit child\n");
  return EXIT_SUCCESS;
}
