# Tablet Notes

* https://linuxwacom.github.io
* [Linux kernel driver for Wacom devices](https://github.com/linuxwacom/input-wacom)
    * [input-wacom driver wiki](https://github.com/linuxwacom/input-wacom/wiki]
* [libwacom is a tablet description library](https://github.com/linuxwacom/libwacom)

## sys

Return an unsigned integer [0-3] to indicate the pad mode:
`
/wacom_led/status_led0_select
`

```
00:14.0 USB controller: Intel Corporation Sunrise Point-LP USB 3.0 xHCI Controller (rev 21)
Bus 001 Device 008: ID 056a:0315 Wacom Co., Ltd PTH-651 [Intuos pro (M)]
```

```
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/uevent
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/report_descriptor
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power/runtime_active_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power/runtime_status
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power/autosuspend_delay_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power/runtime_suspended_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power/control
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/driver
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/subsystem

/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/uevent
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/present
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/power
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/power/runtime_active_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/power/wakeup
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/power/wakeup_count
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/power/wakeup_abort_count
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/power/wakeup_expire_count
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/power/wakeup_total_time_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/power/wakeup_active_count
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/power/runtime_status
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/power/autosuspend_delay_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/power/runtime_suspended_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/power/wakeup_max_time_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/power/wakeup_active
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/power/control
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/power/wakeup_last_time_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/device
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/type
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/capacity
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/scope
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/hwmon7
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/hwmon7/uevent
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/hwmon7/power
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/hwmon7/power/runtime_active_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/hwmon7/power/runtime_status
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/hwmon7/power/autosuspend_delay_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/hwmon7/power/runtime_suspended_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/hwmon7/power/control
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/hwmon7/device
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/hwmon7/subsystem
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/hwmon7/name
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/subsystem
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/status
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/model_name
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/wakeup31
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/wakeup31/uevent
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/wakeup31/event_count
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/wakeup31/max_time_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/wakeup31/wakeup_count
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/wakeup31/total_time_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/wakeup31/expire_count
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/wakeup31/device
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/wakeup31/active_count
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/wakeup31/subsystem
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/wakeup31/last_change_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/wakeup31/prevent_suspend_time_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/wakeup31/name
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/wakeup31/active_time_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/power_supply/wacom_battery_0/powers

/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input

/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/uevent
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.2
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.2/uevent
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.2/brightness
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.2/power
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.2/power/runtime_active_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.2/power/runtime_status
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.2/power/autosuspend_delay_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.2/power/runtime_suspended_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.2/power/control
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.2/device
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.2/trigger
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.2/subsystem
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.2/max_brightness
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.0
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.0/uevent
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.0/brightness
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.0/power
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.0/power/runtime_active_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.0/power/runtime_status
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.0/power/autosuspend_delay_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.0/power/runtime_suspended_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.0/power/control
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.0/device
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.0/trigger
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.0/subsystem
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.0/max_brightness
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/capabilities
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/capabilities/rel
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/capabilities/abs
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/capabilities/ff
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/capabilities/led
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/capabilities/sw
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/capabilities/key
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/capabilities/msc
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/capabilities/snd
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/capabilities/ev
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/power
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/power/runtime_active_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/power/runtime_status
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/power/autosuspend_delay_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/power/runtime_suspended_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/power/control
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/uniq
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/inhibited
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/properties
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/id
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/id/bustype
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/id/vendor
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/id/product
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/id/version
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/js0
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/js0/uevent
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/js0/power
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/js0/power/runtime_active_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/js0/power/runtime_status
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/js0/power/autosuspend_delay_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/js0/power/runtime_suspended_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/js0/power/control
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/js0/dev
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/js0/device
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/js0/subsystem
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/device
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.3
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.3/uevent
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.3/brightness
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.3/power
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.3/power/runtime_active_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.3/power/runtime_status
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.3/power/autosuspend_delay_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.3/power/runtime_suspended_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.3/power/control
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.3/device
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.3/trigger
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.3/subsystem
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.3/max_brightness
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.1
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.1/uevent
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.1/brightness
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.1/power
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.1/power/runtime_active_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.1/power/runtime_status
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.1/power/autosuspend_delay_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.1/power/runtime_suspended_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.1/power/control
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.1/device
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.1/trigger
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.1/subsystem
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/input22::wacom-0.1/max_brightness
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/subsystem
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/phys
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/event20
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/event20/uevent
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/event20/power
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/event20/power/runtime_active_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/event20/power/runtime_status
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/event20/power/autosuspend_delay_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/event20/power/runtime_suspended_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/event20/power/control
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/event20/dev
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/event20/device
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/event20/subsystem
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/name
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input22/modalias

/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/uevent
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/capabilities
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/capabilities/rel
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/capabilities/abs
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/capabilities/ff
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/capabilities/led
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/capabilities/sw
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/capabilities/key
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/capabilities/msc
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/capabilities/snd
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/capabilities/ev
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/mouse4
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/mouse4/uevent
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/mouse4/power
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/mouse4/power/runtime_active_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/mouse4/power/runtime_status
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/mouse4/power/autosuspend_delay_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/mouse4/power/runtime_suspended_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/mouse4/power/control
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/mouse4/dev
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/mouse4/device
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/mouse4/subsystem
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/power
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/power/runtime_active_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/power/runtime_status
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/power/autosuspend_delay_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/power/runtime_suspended_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/power/control
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/uniq
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/inhibited
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/properties
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/id
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/id/bustype
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/id/vendor
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/id/product
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/id/version
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/device
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/subsystem
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/phys
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/event19
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/event19/uevent
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/event19/power
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/event19/power/runtime_active_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/event19/power/runtime_status
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/event19/power/autosuspend_delay_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/event19/power/runtime_suspended_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/event19/power/control
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/event19/dev
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/event19/device
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/event19/subsystem
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/name
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/input/input20/modalias

/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/hidraw
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/hidraw/hidraw1
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/hidraw/hidraw1/uevent
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/hidraw/hidraw1/power
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/hidraw/hidraw1/power/runtime_active_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/hidraw/hidraw1/power/runtime_status
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/hidraw/hidraw1/power/autosuspend_delay_ms
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/hidraw/hidraw1/power/runtime_suspended_time
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/hidraw/hidraw1/power/control
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/hidraw/hidraw1/dev
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/hidraw/hidraw1/device
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/hidraw/hidraw1/subsystem

/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/wacom_led
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/wacom_led/status0_luminance
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/wacom_led/status_led0_select

/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/country
/sys/devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:056A:0315.0002/modalias
```

## USB

```
Bus 001 Device 008: ID 056a:0315 Wacom Co., Ltd PTH-651 [Intuos pro (M)]
Couldn't open device, some information will be missing
Device Descriptor:
  bLength                18
  bDescriptorType         1
  bcdUSB               2.00
  bDeviceClass            0 
  bDeviceSubClass         0 
  bDeviceProtocol         0 
  bMaxPacketSize0        16
  idVendor           0x056a Wacom Co., Ltd
  idProduct          0x0315 PTH-651 [Intuos pro (M)]
  bcdDevice            1.00
  iManufacturer           1 Wacom Co.,Ltd.
  iProduct                2 Intuos5 touch M
  iSerial                 0 
  bNumConfigurations      1

  Configuration Descriptor:
    bLength                 9
    bDescriptorType         2
    wTotalLength       0x0054
    bNumInterfaces          3
    bConfigurationValue     1
    iConfiguration          0 
    bmAttributes         0x80
      (Bus Powered)
    MaxPower              498mA

    Interface Descriptor:
      bLength                 9
      bDescriptorType         4
      bInterfaceNumber        0
      bAlternateSetting       0
      bNumEndpoints           1
      bInterfaceClass         3 Human Interface Device
      bInterfaceSubClass      0 
      bInterfaceProtocol      0 
      iInterface              0 
        HID Device Descriptor:
          bLength                 9
          bDescriptorType        33
          bcdHID               1.10
          bCountryCode            0 Not supported
          bNumDescriptors         1
          bDescriptorType        34 Report
          wDescriptorLength     234
         Report Descriptors: 
           ** UNAVAILABLE **
      Endpoint Descriptor:
        bLength                 7
        bDescriptorType         5
        bEndpointAddress     0x83  EP 3 IN
        bmAttributes            3
          Transfer Type            Interrupt
          Synch Type               None
          Usage Type               Data
        wMaxPacketSize     0x0010  1x 16 bytes
        bInterval               1

    Interface Descriptor:
      bLength                 9
      bDescriptorType         4
      bInterfaceNumber        1
      bAlternateSetting       0
      bNumEndpoints           1
      bInterfaceClass         3 Human Interface Device
      bInterfaceSubClass      0 
      bInterfaceProtocol      0 
      iInterface              0 
        HID Device Descriptor:
          bLength                 9
          bDescriptorType        33
          bcdHID               1.10
          bCountryCode            0 Not supported
          bNumDescriptors         1
          bDescriptorType        34 Report
          wDescriptorLength      23
         Report Descriptors: 
           ** UNAVAILABLE **
      Endpoint Descriptor:
        bLength                 7
        bDescriptorType         5
        bEndpointAddress     0x82  EP 2 IN
        bmAttributes            3
          Transfer Type            Interrupt
          Synch Type               None
          Usage Type               Data
        wMaxPacketSize     0x0040  1x 64 bytes
        bInterval               2

    Interface Descriptor:
      bLength                 9
      bDescriptorType         4
      bInterfaceNumber        2
      bAlternateSetting       0
      bNumEndpoints           1
      bInterfaceClass         3 Human Interface Device
      bInterfaceSubClass      1 Boot Interface Subclass
      bInterfaceProtocol      2 Mouse
      iInterface              0 
        HID Device Descriptor:
          bLength                 9
          bDescriptorType        33
          bcdHID               1.10
          bCountryCode            0 Not supported
          bNumDescriptors         1
          bDescriptorType        34 Report
          wDescriptorLength      52
         Report Descriptors: 
           ** UNAVAILABLE **
      Endpoint Descriptor:
        bLength                 7
        bDescriptorType         5
        bEndpointAddress     0x86  EP 6 IN
        bmAttributes            3
          Transfer Type            Interrupt
          Synch Type               None
          Usage Type               Data
        wMaxPacketSize     0x0010  1x 16 bytes
        bInterval               2
```