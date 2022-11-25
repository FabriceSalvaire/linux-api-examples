# Linux Kernel Notes

* https://docs.kernel.org

## Linux Module

* https://sysplay.github.io/books/LinuxDrivers/book/index.html
* https://github.com/pokitoz/ioctl_driver - Simple example on how to create a IOCTL driver for Linux

## User Space Interface

* **ioctl** is a system call for device-specific input/output
  operations and other operations which cannot be expressed by regular
  system calls.
* **System calls** are a better choice for a system-wide feature that is
  not tied to a physical device or constrained by the file system
  permissions of a character device node
* **netlink** is the preferred way of configuring any network related objects through sockets.
* **debugfs** is used for ad-hoc interfaces for debugging functionality
  that does not need to be exposed as a stable interface to
  applications.
* **sysfs** is a good way to expose the state of an in-kernel object that is not tied to a file descriptor.
* **configfs** can be used for more complex configuration than sysfs
* A custom file system can provide extra flexibility with a simple
  user interface but adds a lot of complexity to the implementation.

### IOCTL

* https://en.wikipedia.org/wiki/Ioctl
* I/O Control in Linux - https://sysplay.github.io/books/LinuxDrivers/book/Content/Part09.html
* man page ioctl(2) 