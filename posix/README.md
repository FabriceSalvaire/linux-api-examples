# POSIX Examples

The **Portable Operating System Interface (POSIX)** is a family of standards ([Std
1003.1-2017](https://standards.ieee.org/ieee/1003.1/7101)) specified by the IEEE Computer Society
for maintaining compatibility between operating systems and that defines both the system- and
user-level API for UNIX OS.

Common **POSIX OS** are:
* Linux
* Android (NDK)
* macOS
* and also [Windows Subsystem for Linux (WSL)](https://learn.microsoft.com/en-gb/windows/wsl)
  implemented by the virtualization of a Linux kernel and distribution

Notice, this list is not exhaustive and the OS doesn't necessarily meet the standards!

## References

* man pages section 2 (system calls) and 3 (library calls)

* https://en.wikipedia.org/wiki/POSIX

## Note about the examples

These examples cover the followings topics:
* config
* epoll
* fork
* signal

They are written in [C99](https://en.wikipedia.org/wiki/C99).

## How to build the examples

Run these commands:
```
mkdir build
cmake -B build
cmake --build build
```
