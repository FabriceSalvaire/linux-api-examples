#wayland-scanner private-code \
#  < /usr/share/wayland-protocols/stable/xdg-shell/xdg-shell.xml \
#  > xdg-shell-protocol.c
#
#wayland-scanner client-header \
#  < /usr/share/wayland-protocols/stable/xdg-shell/xdg-shell.xml \
#  > xdg-shell-client-protocol.h

# librt is glibc real time

#gcc \
#  -lwayland-client -lrt \
#  -o client \
#  client.c xdg-shell-protocol.c

#gcc \
#  -lwayland-client -lrt \
#  -o client2 \
#  client2.c xdg-shell-protocol.c

#gcc \
#  -lwayland-client -lrt \
#  -o seat \
#  seat.c xdg-shell-protocol.c

#  -lwayland-client -lrt -lEGL -lGL \

gcc \
  -lwayland-client -lwayland-server -lwayland-egl -lEGL -lGLESv2 \
  -o pointer \
  pointer.c
