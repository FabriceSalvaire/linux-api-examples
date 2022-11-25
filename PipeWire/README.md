# PipeWire

[PipeWire](https://pipewire.org)
[repository](https://gitlab.freedesktop.org/pipewire/pipewire)
is low-level multimedia framework that provides:- Graph based processing.

* Graph based processing.
* Support for out-of-process processing graphs with minimal overhead.
* Flexible and extensible media format negotiation and buffer allocation.
* Hard real-time capable plugins.
* Achieve very low-latency for both audio and video processing.

The framework is used to build a modular daemon that can be configured to:

* Be a low-latency audio server with features like PulseAudio and/or JACK.
* A video capture server that can manage hardware video capture devices and provide access to them.
* A central hub where video can be made available for other applications such as the gnome-shell screencast API.

* For video content, we typically rely on the compositor to render our data.
* For video capture, we usually go directly to the hardware devices,
  with all security implications and inflexible routing that this
  brings.
* For consumer audio, we use PulseAudio to manage and mix multiple streams from clients.
* For Pro audio, we use JACK to manage the graph of nodes.

None of these solutions (except perhaps to some extent Wayland)
however were designed to support the security features that are
required when dealing with flatpaks or other containerized
applications. PipeWire aims to solve this problem and provides a
unified framework to run both consumer and pro audio as well as video
capture and processing in a secure way.

* [Tutorial](https://docs.pipewire.org/page_tutorial.html
* [Tutorial - sources](https://gitlab.freedesktop.org/pipewire/pipewire/-/tree/master/doc)

* [Examples](https://docs.pipewire.org/examples.html
* [Examples - sources](https://gitlab.freedesktop.org/pipewire/pipewire/-/tree/master/src/examples)


* https://gstreamer.freedesktop.org

* https://gstreamer.freedesktop.org/data/events/gstreamer-conference/2017/Wim%20Taymans%20-%20PipeWire.pdf

* https://ardour.org
* https://lmms.io
* VLC https://www.videolan.org/vlc
