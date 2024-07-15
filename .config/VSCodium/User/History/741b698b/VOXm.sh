#!/bin/sh

# set screen layout and resolution for X
#sh $HOME/.scripts/switch_screens.sh &

export FZF_DEFAULT_OPTS=$FZF_DEFAULT_OPTS' --color=fg:#d3c6aa,bg:#2d353b,hl:#7fbbb3 --color=fg+:#d3c6aa,bg+:#2d353b,hl+:#7fbbb3 --color=info:#afaf87,prompt:#e67e80,pointer:#d699b6 --color=marker:#a7c080,spinner:#d699b6,header:#87afaf'

monitor1="HDMI-1"
monitor1="VGA-1"

xrandr --output $monitor1  --mode 1440x900
xrandr --output $monitor2 --mode 1280x1024 --left-of $monitor1

# disable trackpoint 
# trackpad settings
xinput set-prop "AlpsPS/2 ALPS DualPoint TouchPad" 'libinput Accel Speed' 1 &
xinput set-prop "AlpsPS/2 ALPS DualPoint TouchPad" 'libinput Accel Profile Enabled' 0, 1 &
#perixx mouse
xinput set-prop 14 322 -0.4
xinput set-prop 14 325 0, 1
#launch programs
redshift &
flameshot &

# _______PROGRAMS THAT RUN WITH A NON-ROOT CRONTAB______
# 
#_________PROGRAMS THAT RUN WITH A ROOT CRONTAB________
#

