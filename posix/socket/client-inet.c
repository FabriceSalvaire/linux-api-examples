// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright Fabrice SALVAIRE 2022

/**************************************************************************************************/

#include <arpa/inet.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "../common.h"

/**************************************************************************************************/

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: client-inet NUMBER\n");
    return EXIT_FAILURE;
  }

  int rc;

  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address = {
    .sin_family = AF_INET,
    .sin_port = htons(5566),
    .sin_addr.s_addr = inet_addr("127.0.0.1")
  };
  // initiate a connection on a socket
  rc = connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address));
  if (rc == -1)
    handle_error("connect");

  char *message = (char *)calloc(strlen(argv[1]) + 1, sizeof(char));
  strcpy(message, argv[1]);
  ssize_t bytes_sent = send(socket_fd, message, strlen(message) + 1, 0);
  if (bytes_sent == -1)
    handle_error("send");

  const size_t buffer_size = 1024;
  char *buffer = (char *)calloc(buffer_size, sizeof(char));
  ssize_t bytes_read = read(socket_fd, buffer, buffer_size);
  if (bytes_read == -1)
    handle_error("read");
  printf("result form server: %s\n", buffer);

  free(message);
  free(buffer);
  close(socket_fd);
  return EXIT_SUCCESS;
}
