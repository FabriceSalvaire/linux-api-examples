# Read and Decode /dev/input/event<NUMBER>

## Introduction

The X86 architecture implements protection rings to separate the
kernel and user space.  It means there is a bridge to cross between
the kernel and user space.  For this reason, the Linux kernel
implements two mechanismes (*) to communicate with the user space.

(*) We simplify the reality in this introduction.

The first one, use the X86_64 `syscall` instruction to perform a
system call.  By simplicity, the Linux kernel can only implement a
limited list of core functions.  Because it would not make no sense to
implement an OO API with zillion of methods wrapped by system calls.
Actually, the kernel implements roughly 400 system calls (see
https://github.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_64.tbl).
However the Microsoft Windows OS has something like 5 times more
system calls due to its monolitic design.  It means Windows has system
calls to manage mouse for example.

The second one, is to use several memory buffers through a virtual
file system (VFS).  It explains why the Linux kernel exports events
from input devices to the user space using the
`/dev/input/event<NUMBER>` devices files.  Basically, the kernel
manages device hot plug and translate a data flow from a bus like USB
to a buffer, where the events are queued and serialised to this simple
binary structure:

```
struct input_event {
    uint64_t sec;
    uint64_t usec;
    uint16_t type;
    uint16_t code;
    int32_t value;
}
```

For more details, see https://github.com/torvalds/linux/blob/master/include/uapi/linux/input.h#L28

To go further:
* Articles on system calls
    * https://www.cs.uaf.edu/2017/fall/cs301/lecture/11_17_syscall.html
    * https://en.wikibooks.org/wiki/X86_Assembly/Interfacing_with_Linux
    * https://github.com/j00ru/windows-syscalls - Microsoft Windows System Call Tables

## How to use the program

List USB devices, using the command in a terminal:
```
lsusb
```

List the devices to discover your system:
```
ls -l /dev/input/*
```

Watch kernel events when you unplug/plug devices:
```
dmesg
```

Run the program, notice it requires superuser right to read the device file:
```
sudo ./read-event <MOUSE_EVENT_NUMBER>
# Hit Ctrl+C to exit
```

## To go further

### libevdev Tools

See [libevdev group @freedesktop](https://gitlab.freedesktop.org/libevdev)

* (evemu tools)[https://gitlab.freedesktop.org/libevdev/evemu]
    * `/usr/bin/evemu-describe` - print information from an input device
    * `/usr/bin/evemu-record` - print event from an input device
    * `/usr/bin/evemu-device` - creates a virtual input device based on the description-file
    * `/usr/bin/evemu-event` - plays exactly one event with the current time
    * `/usr/bin/evemu-play` - replays the event sequence given on stdin through the input device
*(evtest tool)[https://gitlab.freedesktop.org/libevdev/evtest]
    * `/usr/bin/evtest` - Input device event monitor and query tool
* (hid-tools)(https://gitlab.freedesktop.org/libevdev/hid-tools] a set of tools to interact with the kernel's HID subsystem

### USB Analyser 

* (Wireshark network protocol analyzer](https://www.wireshark.org)

## USB Documentation

* [Human Interface Devices (HID) Specifications and Tools](https://www.usb.org/hid)
* [Device Class Definition for Human Interface Devices (HID) V1.11](https://www.usb.org/sites/default/files/hid1_11.pdf)
* [USB @Microchip Developer Help](https://microchipdeveloper.com/usb:how-it-works)
* [USB in a NutShell @beyondlogic.org](https://www.beyondlogic.org/usbnutshell/usb1.shtml)
* [USB Communications @Wikipedia](https://en.wikipedia.org/wiki/USB_(Communications))
* [USB @Arm Keil](https://www.keil.com/pack/doc/mw/USB/html/index.html)