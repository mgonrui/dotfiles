#!/bin/bash

# screen layout for Xorg
xrandr --output "HDMI-1" --set audio force-dvi --mode 1920x1080 --output "VGA-1" --mode 1440x900 --right-of "HDMI-1" &

#mouse settings
xinput set-prop 'SN TECH      GAMINGMOUSᩅ' 'libinput Accel Profile Enabled' 0, 1 &
xinput set-prop 'SN TECH      GAMINGMOUSᩅ' 'libinput Accel Speed' -0.5 &

#keyboard layout
setxkbmap us &
#setxkbmap -option caps:swapescape

#launch programs
redshift &
qbittorrent &
dolphin &
#syncthing runs with a crontab
#setsid syncthing >/dev/null 2>&1 < /dev/null &
flameshot &
emacs --daemon &

#open keepassxc database
#secret-tool lookup keepass pswd | keepassxc --pw-stdin /home/mgr/.pswd/pswd.kdbx &
