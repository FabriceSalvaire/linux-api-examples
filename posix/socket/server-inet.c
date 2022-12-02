// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright Fabrice SALVAIRE 2022

/**************************************************************************************************/

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>

#include "../common.h"

/**************************************************************************************************/

void
signal_handler(int signal) {
  UNUSED(signal);
  printf("signal_handler\n");
  int stat;
  // wait for process to change state
  //   wait for any child process whose process group ID is equal to
  //   that of the calling process at the time of the call to waitpid()
  waitpid(0, &stat, WNOHANG);
  return;
}

/**************************************************************************************************/

int
main()
{
  // SIGCHLD: child stopped or terminated
  // signal(SIGCHLD, signal_handler);

  int rc;

  // create an endpoint for communication
  //   socket(2)
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == -1)
    handle_error("socket");

  struct sockaddr_in server_address = {
    .sin_family = AF_INET,
    .sin_port = htons(5566),
    .sin_addr.s_addr = inet_addr("127.0.0.1")
  };

  // bind a name to a socket
  rc = bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address));
  if (rc == -1)
    handle_error("bind");

  // listen for connections on a socket
  const int BACKLOG = 20;
  rc = listen(server_fd, BACKLOG);
  if (rc == -1)
    handle_error("listen");

  // Now we can accept incoming connections one at a time using accept(2).

  while (1) {
    struct sockaddr_in client_address;
    socklen_t client_address_size = sizeof(client_address);

    int client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_address_size);
    if (client_fd == -1)
      handle_error("accept");

    // set recv and send timeout
    struct timeval timeout;
    timeout.tv_sec = 5;  // sec
    timeout.tv_usec = 0; // ms
    if (setsockopt(client_fd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0)
      handle_error("setsockopt");
    if (setsockopt(client_fd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout)) < 0)
      handle_error("setsockopt");

    int pid = fork();
    if (pid == -1) {
      handle_error("fork");
    } else if (pid == 0) {
      printf("child PID %d\n", getpid());

      const size_t buffersize = 1024;

      char *buffer = (char *)calloc(buffersize, sizeof(char));
      recv(client_fd, buffer, buffersize, 0);
      printf("Server receive:%s\n", buffer);

      int total = (int)(atoi(buffer) * atoi(buffer));
      printf("Server return num^2:%d\n", total);

      char *returnvalue = (char *)calloc(buffersize, sizeof(char));
      sprintf(returnvalue, "result:%d", total);
      send(client_fd, returnvalue, buffersize, 0);

      close(client_fd);
      close(server_fd);
      return EXIT_SUCCESS;
    } else {
      close(client_fd);
    }
  }

  close(server_fd);
  return EXIT_SUCCESS;
}
