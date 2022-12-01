# Wayland

* [Wayland](https://wayland.freedesktop.org)
* [Wayland Protocol](https://wayland.freedesktop.org/docs/html/index.html)
* [Wayland Protocol Explorer](https://wayland.app/protocols)
* [Wayland Book](https://wayland-book.com)

# Tools

* [Wayland debugging extras](https://wayland.freedesktop.org/extras.html)

* [wayland-utils](https://gitlab.freedesktop.org/wayland/wayland-utils)
   * **wayland-info** is a utility for displaying information about the Wayland protocols supported
     by a Wayland compositor.

* [wayland-debug](https://github.com/wmww/wayland-debug) a CLI for viewing, filtering, and setting breakpoints on Wayland protocol messages.

* [wayland-tracer](https://github.com/FabriceSalvaire/wayland-tracer) A Wayland protocol dumper, MIT
  licensed, written in C, produces binary and human readable output. Can run as a middle-man for a
  single client, or act as a middle-man Wayland server.

## Client API

The Wayland compositor and a client communicate through a UNIX domain stream socket, usually the
path is `$XDG_RUNTIME_DIR/wayland-0` where the environment variable
`XDG_RUNTIME_DIR=/run/user/<USER_UID>`.

We can list the list of clients using this shell command:
```
> netstat | ag wayland
unix  3      [ ]         STREAM     CONNECTED     129240   /run/user/1000/wayland-0
...
```

See https://wayland.freedesktop.org/docs/html/ch04.html#sect-Protocol-Wire-Format

https://gitlab.freedesktop.org/wayland/wayland/-/tree/main/src

### Wayland Client Library

Argument of type `new_id`, like for this request:
```
wl_registry::bind
bind(name: uint, id: new_id)
```
is transformed by the XML scanner to this C function
```
wl_registry_bind(
  struct wl_registry *wl_registry,
  uint32_t name, // name: uint
  const struct wl_interface *interface, uint32_t version // id: new_id
)
```

## Examples

Some of theses examples can be outdated.

* https://bugaevc.gitbooks.io/writing-wayland-clients/content
  https://github.com/bugaevc/writing-wayland-clients

* https://jan.newmarch.name/Wayland/index.html
  Programming Wayland Clients 2017
  Jan Newmarch, University of Canberra

* https://gist.github.com/Miouyouyou/ca15af1c7f2696f66b0e013058f110b4
  A very ugly Wayland EGL OpenGL example

