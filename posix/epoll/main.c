// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright Fabrice SALVAIRE 2022

/**************************************************************************************************/

// #include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <unistd.h>

/**************************************************************************************************/

int
main(int argc, char *argv[], char **envp)
{
  // creates a new epoll instance
  // epoll_create(2)
  int epoll_fd = epoll_create1(0);
  if (epoll_fd == -1) {
    perror("Failed to create epoll file descriptor");
    return EXIT_FAILURE;
  }

  const int POLLED_FD = STDIN_FILENO;
  struct epoll_event event = { 0 };
  event.events = EPOLLIN;
  event.data.fd = POLLED_FD;
  if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, POLLED_FD, &event)) {
    perror("Failed to add file descriptor to epoll");
    close(epoll_fd);
    return 1;
  }

  int running = 1;
  while (running) {
    printf("\nPolling for input... (type some characters and flush with enter key)\n");

    const int MAX_EVENTS = 5;
    const int READ_SIZE = 10;
    const int TIMEOUT = 10000;
    struct epoll_event events[MAX_EVENTS];
    // wait for an I/O event on an epoll file descriptor
    // epoll_wait(2)
    int event_count = epoll_wait(epoll_fd, events, MAX_EVENTS, TIMEOUT);
    printf("%d ready events\n", event_count);

    for (size_t i = 0; i < event_count; i++) {
      const epoll_data_t *data = &(events[i].data);
      char read_buffer[READ_SIZE + 1];
      size_t bytes_read = read(data->fd, read_buffer, READ_SIZE);
      printf("Read %zd bytes on file descriptor '%d'\n", bytes_read, data->fd);
      read_buffer[bytes_read] = '\0';
      printf("%s", read_buffer);

      const char * STOP = "stop\n";
      if (!strncmp(read_buffer, STOP, strlen(STOP)))
        running = 0;
    }
  }

  if (close(epoll_fd)) {
    perror( "Failed to close epoll file descriptor\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
