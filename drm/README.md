# Direct Rendering Manager (DRM) / Kernel Mode Setting (KMS)

## Introduction

**DRM** stands for Direct Rendering Manager and was introduced to deal
with graphic cards embedding GPUs.

**KMS** stands for Kernel Mode Setting and is a sub-part of the DRM
API. KMS provide a way to configure the display pipeline of a graphic
card or an embedded system.

**Video Architecture**
```
DRM Framebuffer ->
                    CRTC  -> Encoder -> Connector (HDMI / DisplayPort)
         Planes ->
```

**CRTC** stands for Cathode Ray Tube Controller.

A **plane** is an an image layer, and the final image displayed by the CRTC is
the composition of one or several planes.

* [The DRM/KMS subsystem from a newbie’s point of view](https://events.static.linuxfound.org/sites/events/files/slides/brezillon-drm-kms.pdf)
* https://wiki.st.com/stm32mpu/wiki/DRM_KMS_overview

## /dev/dri

Example for an Intel CPU/GPU:
```
# device for mode setting
crw-rw----+ 1 root video  226,   1 24 nov.  04:32 /dev/dri/card1

# device for rendering
crw-rw-rw-. 1 root render 226, 128 24 nov.  04:32 /dev/dri/renderD128

/dev/dri/by-path:
lrwxrwxrwx. 1 root root  8 24 nov.  04:32 pci-0000:00:02.0-card -> ../card1
lrwxrwxrwx. 1 root root 13 24 nov.  04:32 pci-0000:00:02.0-render -> ../renderD128
```

## libdrm - userspace library for drm

* https://gitlab.freedesktop.org/mesa/drm
* https://gitlab.freedesktop.org/mesa/drm/-/tree/main/tests/modetest

## Tools

* `/usr/bin/drm_info`- dump information about DRM devices
  see https://github.com/ascent12/drm_info

**libdrm tools**
* `/usr/bin/modetest`
* `/usr/bin/drmdevice`

* `/usr/bin/amdgpu_stress`
* `/usr/bin/modeprint`
* `/usr/bin/proptest`
* `/usr/bin/vbltest`

## Examples

* https://gitlab.freedesktop.org/daniels/kms-quads - Straightforward and well-documented KMS example
* https://github.com/nyorain/kms-vulkan - Example for using vulkan with drm and kms