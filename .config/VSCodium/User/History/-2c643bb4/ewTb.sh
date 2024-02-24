#!/bin/bash

# screen layout for Xorg
xrandr --output "HDMI-1" --set audio force-dvi --mode 1920x1080 --output "VGA-1" --mode 1440x900 --left-of "HDMI-1" &

#mouse settings
xinput set-prop 'SN TECH      GAMINGMOUSᩅ' 'libinput Accel Profile Enabled' 0, 1 &
xinput set-prop 'SN TECH      GAMINGMOUSᩅ' 'libinput Accel Speed' -0.5 &

#keyboard layout
setxkbmap us &
#setxkbmap -option caps:swapescape

#launch programs
redshift &
easyeffects &
obsidian &
dolphin &
spotifywm &
qbittorrent &
picom &
flameshot &

# minimize windows
xdotool search --onlyvisible --classname --sync Easyeffects windowminimize & # easyeffects

# //////PROGRAMS THAT RUN WITH A NON-ROOT CRONTAB//////
# @reboot syncthing &
#//////PROGRAMS THAT RUN WITH A ROOT CRONTAB////////
# @reboot dnf update
# */10 * * * * killall keepassxc
