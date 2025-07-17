# hid-shanwan

A Linux kernel module for supporting Shanwan HID devices (such as the Android Gamepad).

## Features

- Adds support for Shanwan HID devices.
- Plug-and-play compatibility for supported devices.

## Installation and Removal

Build and load the module directly with
```bash
make load
```

For removing, unload and then clean the build
```bash
sudo rmmod hid-shanwan
make clean
```

## Usage

Once installed and loaded, supported Shanwan HID devices should be recognized automatically when plugged in.

## Files

- `hid-shanwan.c`: Source code for the kernel module.
- `hid-ids.h`: Device IDs for supported hardware.
- `Makefile`: Build instructions.

## License

GPLv2
