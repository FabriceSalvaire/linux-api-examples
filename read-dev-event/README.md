# Read and Decode /dev/input/event<NUMBER>

The X86 architecture implements protection rings to separate the
kernel and user space.  It means there is a bridge to cross between
the kernel and user space.  For this reason, the Linux kernel
implements two mechanism to communicate with the user space.

The first one, use the X86_64 syscall instruction to perform a system
call.  By simplicity, the Linux kernel can only implement a limited
list of core functions.  Because it would not make no sense to
implement an OO API with zillion of methods wrapped by system calls.
Actually, the kernel implements a bit less than 500 system calls.

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
