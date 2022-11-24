# Read and Decode /dev/input/event<NUMBER>

## Introduction

The X86 architecture implements protection rings to separate the
kernel and user space.  It means there is a bridge to cross between
the kernel and user space.  For this reason, the Linux kernel
implements two mechanism to communicate with the user space.

The first one, use the X86_64 `syscall` instruction to perform a
system call.  By simplicity, the Linux kernel can only implement a
limited list of core functions.  Because it would not make no sense to
implement an OO API with zillion of methods wrapped by system calls.
Actually, the kernel implements roughly 400 system calls (see
https://github.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_64.tbl).

The second one, is to use several memory buffers through a virtual
file system (VFS).  It explains why the Linux kernel exports events
from input devices to the user space using the
`/dev/input/event<NUMBER>` devices files.  Basically, the kernel
manages device hot plug and translate a data flow from a bus like USB
to a buffer, where the events are serialised to this simple binary
structure:

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

 - https://en.wikibooks.org/wiki/X86_Assembly/Interfacing_with_Linux
 - https://www.cs.uaf.edu/2017/fall/cs301/lecture/11_17_syscall.html

## How to use the program

List the devices to discover your system, using the command in a terminal:
```
ls -l /dev/input/*
```

Watch kernel events when you unplug/plug devices, using the command:
```
dmesg
```

Run the program, notice it requires superuser right to read the device file:
```
sudo ./read-dev-event <MOUSE_EVENT_NUMBER>
# Hit Ctrl+C to exit
```
