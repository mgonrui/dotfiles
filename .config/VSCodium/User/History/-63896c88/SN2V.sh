#!/bin/sh

# screen layout for Xorg
#xrandr --output eDP1 --mode 1920x1080
xrandr --output "HDMI1" --set audio force-dvi --mode 1920x1080
xrandr --output "VGA1" --mode 1440x900 --left-of "HDMI1"
#mouse settings
xinput set-prop 'SN TECH      GAMINGMOUSᩅ' 'libinput Accel Profile Enabled' 0, 1 &
xinput set-prop 'SN TECH      GAMINGMOUSᩅ' 'libinput Accel Speed' -0.5 &
# trackpoint settings
xinput set-prop "AlpsPS/2 ALPS DualPoint Stick" 'libinput Accel Speed' 1 &
xinput set-prop "AlpsPS/2 ALPS DualPoint Stick" 'libinput Accel Profile Enabled' 0, 1 &
# disable trackpad
xinput disable "AlpsPS/2 ALPS DualPoint TouchPad"

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

# update distrobox subsystems
distrobox enter arch -- sudo pacman -Syuu &

# minimize windows
xdotool search --onlyvisible --classname --sync Easyeffects windowminimize & # easyeffects

# //////PROGRAMS THAT RUN WITH A NON-ROOT CRONTAB//////
# @reboot syncthing &
#//////PROGRAMS THAT RUN WITH A ROOT CRONTAB////////
# @reboot dnf update
# */10 * * * * killall keepassxc
