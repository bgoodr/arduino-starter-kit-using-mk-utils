Arduino Starter Kit Project 03
==============================

This directory builds upon the SerialPrint example in
[arduino-mk-utils](https://github.com/bgoodr/arduino-mk-utils) to
build the project.

In addition, a [monitor_xterm_screen.sh](./monitor_xterm_screen.sh)
script is provided that can be invoked with the `monitor`
rule. Typically you want to build, upload, and then run the monitor
program via:

    MONITOR_CMD=./monitor_xterm_screen.sh PATH=/usr/bin:$PATH ARD_MK_UTILS_DIR=$HOME/bgoodr/arduino-mk-utils make upload monitor

This runs the `screen` program on the serial port connected to the
Arduino device, all within a separate `xterm` window. The separate
xterm is needed in cases where you are running make under an Emacs
shell session which has a dumb terminal which won't work with
`screen`.

Do a man on `screen` to find usage. Useful key sequences are:

* **C-a ?** - Online help
* **C-a \\** - Quits the `screen` session

