#!/bin/sh

# set screen layout and resolution for X
xrandr --output eDP1 --mode 1920x1080
# xrandr --output "HDMI1" --set audio force-dvi --mode 1920x1080
# xrandr --output "VGA1" --mode 1440x900 --left-of "HDMI1"

#mouse settings
# xinput set-prop 'SN TECH      GAMINGMOUSᩅ' 'libinput Accel Profile Enabled' 0, 1 &
# xinput set-prop 'SN TECH      GAMINGMOUSᩅ' 'libinput Accel Speed' -0.5 &

# disable trackpoint 
# xinput disable "AlpsPS/2 ALPS DualPoint Stick" 
# trackpad settings
xinput set-prop "AlpsPS/2 ALPS DualPoint TouchPad" 'libinput Accel Speed' 1 &
xinput set-prop "AlpsPS/2 ALPS DualPoint TouchPad" 'libinput Accel Profile Enabled' 0, 1 &

#keyboard layout
setxkbmap us &
#setxkbmap -option caps:swapescape

#launch programs
#obsidian &
redshift &
#easyeffects &
#dolphin &
#spotifywm &
#qbittorrent &
flameshot &
#kitty &
#chromium &
#picom &

# _______PROGRAMS THAT RUN WITH A NON-ROOT CRONTAB______
# @reboot syncthing &
#_________PROGRAMS THAT RUN WITH A ROOT CRONTAB________
# @reboot dnf update
# */10 * * * * killall keepassxc
