// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright Fabrice SALVAIRE 2022

/**************************************************************************************************/

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include <unistd.h>

/**************************************************************************************************/

void
signal_handler(int signal)
{
  printf("Received signal %i\n", signal);
}

void
signal_handler2(int signal, siginfo_t *siginfo, void *userdata)
{
  printf("Received signal %i\n", signal);
}

/**************************************************************************************************/

int
main(int argc, char *argv[], char **envp)
{
  int rc;

  // Set a signal handler
  // signal(2)
  typedef void (*sighandler_t)(int);
  sighandler_t old_signal_handler = signal(SIGUSR1, signal_handler);

  // sigaction(2)
  struct sigaction act = { 0 };
  // memset(&act, 0, sizeof(act));
  act.sa_flags = SA_SIGINFO;
  act.sa_sigaction = signal_handler2;
  rc = sigaction(SIGUSR2, &act, NULL);
  if (rc == -1) {
    // printf("Failed to set up signal handling (%s)\n", strerror(errno));
    perror("sigaction");
    return EXIT_FAILURE;
  }

  sleep(1);

  // send a signal to the caller
  printf("Raise SIGUSR1\n");
  rc = raise(SIGUSR1);
  if (rc == -1)
    perror("raise");
  raise(SIGUSR2);

  // send a signal to pid
  printf("Kill SIGUSR1\n");
  pid_t pid = getpid();
  rc = kill(pid, SIGUSR1);
  if (rc == -1)
    perror("kill");

  return EXIT_SUCCESS;
}
