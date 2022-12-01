// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright Fabrice SALVAIRE 2022

/**************************************************************************************************/

#define _POSIX_C_SOURCE 1

#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**************************************************************************************************/

int
main(int argc, char *argv[], char **envp)
{
  struct utsname utsname;
  if (uname(&utsname) == -1)
    perror("uname()");
  else {
    printf("machine: %s\n", utsname.machine);
    printf("node: %s\n", utsname.nodename);
    printf("system: %s %s (%s)\n",
           utsname.sysname, utsname.release, utsname.version);
  }

  long sysconf_return = sysconf(_SC_2_VERSION);
  if (sysconf_return != -1)
    printf("POSIX %ld\n", sysconf_return);

  return EXIT_SUCCESS;
}
