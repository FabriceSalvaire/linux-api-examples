// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright Fabrice SALVAIRE 2022

/**************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <unistd.h>

/**************************************************************************************************/

int
main()
{
  // creates a new epoll instance
  //   epoll_create(2)
  int epoll_fd = epoll_create1(0);
  if (epoll_fd == -1) {
    perror("Failed to create epoll file descriptor");
    return EXIT_FAILURE;
  }

  const int POLLED_FD = STDIN_FILENO;
  struct epoll_event event = { 0 };
  event.events = EPOLLIN; // read
  event.data.fd = POLLED_FD; // set fd in user data
  // Add a file descriptor to epoll monitoring
  //    epoll_ctl(2)
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
    //   epoll_wait(2)
    int event_count = epoll_wait(epoll_fd, events, MAX_EVENTS, TIMEOUT);
    printf("%d ready events\n", event_count);

    for (int i = 0; i < event_count; i++) {
      // Wrong: taking address of packed member of 'struct epoll_event' may result in an unaligned pointer value
      // const epoll_data_t *data = &(events[i].data);
      int fd = events[i].data.fd;
      char read_buffer[READ_SIZE + 1];
      int bytes_read = read(fd, read_buffer, READ_SIZE);
      printf("Read %i bytes on file descriptor '%d'\n", bytes_read, fd);
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
