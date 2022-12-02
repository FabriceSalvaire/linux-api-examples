// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright Fabrice SALVAIRE 2022

/**************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

/**************************************************************************************************/

int
main()
{
  const size_t BUFFER_SIZE = 1024;
  char buf[1024];
  const char *DATA1 = "Some data abcdefghijklmnopqrstuvwxyz ...";
  const char *DATA2 = "More data 0123456789 ...";

  int socket_pair[2];
  const size_t PARENT_SOCKET = 0;
  const size_t CHILD_SOCKET = 1;
  // create a pair of connected sockets
  //   socketpair(2)
  if (socketpair(AF_UNIX, SOCK_STREAM, 0, socket_pair) < 0) {
    perror("opening stream socket pair");
    exit(EXIT_FAILURE);
  }

  int child_pid = fork();
  if (child_pid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  } else if (child_pid) {
    // parent branch
    close(socket_pair[PARENT_SOCKET]);

    // note: -1 is for \0
    int bytes_read = read(socket_pair[CHILD_SOCKET], buf, BUFFER_SIZE -1);
    if (bytes_read == -1) {
      perror("reading stream message");
      // ...
    }
    buf[bytes_read] = '\0';
    printf("child --> %s\n", buf);

    int bytes_write = write(socket_pair[CHILD_SOCKET], DATA2, strlen(DATA2));
    if (bytes_write == -1)
      perror("writing stream message");

    close(socket_pair[CHILD_SOCKET]);
  } else {
    // child branch
    close(socket_pair[CHILD_SOCKET]);

    int bytes_write = write(socket_pair[PARENT_SOCKET], DATA1, strlen(DATA1));
    if (bytes_write == -1)
      perror("writing stream message");

    int bytes_read = read(socket_pair[PARENT_SOCKET], buf, BUFFER_SIZE -1);
    if (bytes_read == -1)
      perror("reading stream message");
    buf[bytes_read] = '\0';
    printf("parent --> %s\n", buf);

    close(socket_pair[PARENT_SOCKET]);
  }

  return EXIT_SUCCESS;
}
