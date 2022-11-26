wayland-scanner \
    private-code \
    /usr/share/wayland-protocols/unstable/xdg-shell/xdg-shell-unstable-v6.xml \
    xdg-shell-client-protocol.c
wayland-scanner \
  client-header \
  /usr/share/wayland-protocols/unstable/xdg-shell/xdg-shell-unstable-v6.xml \
  xdg-shell-client-protocol.h

gcc \
    -lEGL -lGLESv2 \
    -lwayland-client -lwayland-server -lwayland-client-protocol -lwayland-egl  \
    -I. \
    -o test init_window.c xdg-shell-client-protocol.c

