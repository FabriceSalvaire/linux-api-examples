// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright Fabrice SALVAIRE 2022

// Libinput Example
//   inspired from libinput/tools

/**************************************************************************************************/

// #include <cerrno>
#include <fcntl.h>
#include <poll.h>
#include <csignal>
// #include <cstdio>
// #include <cstdlib>
#include <cstring>
// #include <ctime>
// #include <unistd.h>

#include <iostream>

#include <libinput.h>
#include <stdio.h>

using namespace std;

/**************************************************************************************************/

uint32_t start_time;
volatile sig_atomic_t stop = 0;

/**************************************************************************************************/

void
sighandler(int signal, siginfo_t *siginfo, void *userdata)
{
  cout << "signal handler: stop loop" << endl;
  stop = 1;
}

/**************************************************************************************************/

int
open_restricted(const char *path, int flags, void *user_data)
{
  int fd = open(path, flags);
  return fd < 0 ? -errno : fd;
}

void
close_restricted(int fd, void *user_data)
{
  close(fd);
}

const static struct libinput_interface interface = {
  .open_restricted = open_restricted,
  .close_restricted = close_restricted,
};

/**************************************************************************************************/

void
libinput_log_func(struct libinput *libinput,
		  enum libinput_log_priority priority,
		  const char *format, va_list args)
{
  char *message;
  vasprintf(&message, format, args);
  cout << "Libinput " << priority << " " << message;
  free(message);
}

/**************************************************************************************************/

void
print_event_time(uint32_t time)
{
  cout << '@' << (start_time ? (time - start_time) / 1000.0 : 0);
}

/**************************************************************************************************/

void
print_tablet_pad_button_event(struct libinput_event *ev)
{
  auto *p = libinput_event_get_tablet_pad_event(ev);

  print_event_time(libinput_event_tablet_pad_get_time(p));

  const auto button = libinput_event_tablet_pad_get_button_number(p);
  const auto state = libinput_event_tablet_pad_get_button_state(p);
  const auto mode = libinput_event_tablet_pad_get_mode(p);
  cout << " " << button
       << " " << (state == LIBINPUT_BUTTON_STATE_PRESSED ? "pressed" : "released")
       << " mode=" << mode;

  const auto group = libinput_event_tablet_pad_get_mode_group(p);
  if (libinput_tablet_pad_mode_group_button_is_toggle(group, button))
    cout << " <mode toggle>";

  cout << endl;
}

/**************************************************************************************************/

void
print_tablet_pad_ring_event(struct libinput_event *ev)
{
  auto p = libinput_event_get_tablet_pad_event(ev);
  const char *source = "<invalid>";

  print_event_time(libinput_event_tablet_pad_get_time(p));

  switch (libinput_event_tablet_pad_get_ring_source(p)) {
  case LIBINPUT_TABLET_PAD_RING_SOURCE_FINGER:
    source = "finger";
    break;
  case LIBINPUT_TABLET_PAD_RING_SOURCE_UNKNOWN:
    source = "unknown";
    break;
  }

  auto mode = libinput_event_tablet_pad_get_mode(p);
  cout << " ring " << libinput_event_tablet_pad_get_ring_number(p)
       << " position " << libinput_event_tablet_pad_get_ring_position(p)
       << " source " << source
       << " mode " << mode
       << endl;
}

/**************************************************************************************************/

int
handle_and_print_events(struct libinput *li)
{
  int rc = -1;

  if (libinput_dispatch(li) != 0)
    cout << "libinput: Failed to dispatch libinput" << endl;

  struct libinput_event *ev;
  while ((ev = libinput_get_event(li)) != NULL) {
    // const auto li = libinput_event_get_context(ev);
    // libinput_get_user_data(libinput);
    const auto device = libinput_event_get_device(ev);
    const auto sysname = libinput_device_get_sysname(device);
    const auto type = libinput_event_get_type(ev);

    cout << "Event from " << sysname << endl;
    switch (type) {
    case LIBINPUT_EVENT_DEVICE_ADDED:
      cout << "  Device Added" << endl;
      break;
    case LIBINPUT_EVENT_DEVICE_REMOVED:
      cout << "  Device Removed" << endl;
      break;
    case LIBINPUT_EVENT_TABLET_TOOL_BUTTON:
      cout << "LIBINPUT_EVENT_TABLET_TOOL_BUTTON" << endl;
      break;
    case LIBINPUT_EVENT_TABLET_PAD_BUTTON:
      cout << "LIBINPUT_EVENT_TABLET_PAD_BUTTON" << endl;
      print_tablet_pad_button_event(ev);
      break;
    case LIBINPUT_EVENT_TABLET_PAD_RING:
      cout << "LIBINPUT_EVENT_TABLET_PAD_RING" << endl;
      print_tablet_pad_ring_event(ev);
      break;
    case LIBINPUT_EVENT_TABLET_PAD_STRIP:
      break;

    default:
      cout << "Event ? " << type << endl;
    }

    libinput_event_destroy(ev);
    rc = 0;
  }
  return rc;
}

/**************************************************************************************************/

void
mainloop(struct libinput *li)
{
  struct pollfd fds;

  fds.fd = libinput_get_fd(li);
  fds.events = POLLIN;
  fds.revents = 0;

  // Handle already-pending device added events
  if (handle_and_print_events(li))
    cout << "Expected device added events on startup but got none. "
         << "Maybe you don't have the right permissions?"
         << endl;

  // time offset starts with our first received event
  if (poll(&fds, 1, -1) > -1) {
    struct timespec tp;

    clock_gettime(CLOCK_MONOTONIC, &tp);
    start_time = tp.tv_sec * 1000 + tp.tv_nsec / 1000000;
    do {
      handle_and_print_events(li);
    } while (!stop && poll(&fds, 1, -1) > -1);
  }
}

/**************************************************************************************************/

int main(void) {
  // Set signal handler
  struct sigaction act = { 0 };
  act.sa_flags = SA_SIGINFO;
  act.sa_sigaction = sighandler;
  if (sigaction(SIGINT, &act, NULL) == -1) {
    perror("Failed to set up signal handling");
    return EXIT_FAILURE;
  }

  // cout << "libinput version: " << LIBINPUT_VERSION << endl;

  struct udev *udev = udev_new();

  // https://wayland.freedesktop.org/libinput/doc/latest/api/group__base.html
  // struct libinput * 	libinput_udev_create_context (const struct libinput_interface *interface, void *user_data, struct udev *udev)
  struct libinput *li = libinput_udev_create_context(&interface, NULL, udev);
  if (!li) {
    return EXIT_FAILURE;
  }

  libinput_log_set_handler(li, &libinput_log_func);
  libinput_log_set_priority(li, LIBINPUT_LOG_PRIORITY_DEBUG);

  if (libinput_udev_assign_seat(li, "seat0") != 0) {
    libinput_unref(li);
    return EXIT_FAILURE;
  }

  mainloop(li);

  libinput_unref(li);

  return EXIT_SUCCESS;
}
