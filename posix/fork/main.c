// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright Fabrice SALVAIRE 2022

/**************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)

/**************************************************************************************************/

int
main(int argc, char *argv[], char **envp)
{
  UNUSED(argc);
  UNUSED(envp);

  pid_t process_pid = getpid();
  printf("PID=%u\n", process_pid);

  printf("fork...\n");
  pid_t child_pid = fork();
  if (child_pid == -1) {
    printf("fork failed...\n");
    perror(argv[0]);
    return EXIT_FAILURE;
  }
  else if (child_pid == 0) {
    process_pid = getpid();
    printf("child...\n");

    // do something in child
    // notice child process can exit after parent
    // sleep(1);

    // replace parent code by child code from another executable
    // int execl(const char *pathname, const char *arg, ... /*, (char *) NULL */);
    // int execlp(const char *file, const char *arg, ... /*, (char *) NULL */);
    // int execle(const char *pathname, const char *arg, ... /*, (char *) NULL, char *const envp[] */);
    // int execv(const char *pathname, char *const argv[]);
    // int execvp(const char *file, char *const argv[]);
    // int execvpe(const char *file, char *const argv[], char *const envp[]);
    char child_path[256];
    sprintf(child_path, "%s-child", argv[0]);
    int rc = execvp(child_path, argv);
    if (rc == -1) {
      printf("exec failed...\n");
      perror(argv[0]);
    }
    // due to exec we cannot reach this code anymore

    printf("exit child\n");
    return EXIT_SUCCESS;
  }
  else {
    printf("child PID=%u\n", child_pid);
    // do something in parent
    // sleep(1);
    printf("exit parent\n");
    return EXIT_SUCCESS;
  }

  // common code to parent and child

  // printf("exit PID=%u\n", process_pid);
  // return EXIT_SUCCESS;
}
