#!/bin/sh

# set screen layout and resolution for X
sh $HOME/.scripts/switch_screens.sh &

#mouse settings

# disable trackpoint 
# trackpad settings
xinput set-prop "AlpsPS/2 ALPS DualPoint TouchPad" 'libinput Accel Speed' 1 &
xinput set-prop "AlpsPS/2 ALPS DualPoint TouchPad" 'libinput Accel Profile Enabled' 0, 1 &
#perixx mouse
xinput set-prop " MOSART Semi. 2.4G Keyboard Mouse" 'libinput Accel Profile Enabled' 0, 1 &
xinput set-prop " MOSART Semi. 2.4G Keyboard Mouse" 'libinput Accel Speed' -0.4 &'



#launch programs
redshift &
flameshot &

# _______PROGRAMS THAT RUN WITH A NON-ROOT CRONTAB______
# 
#_________PROGRAMS THAT RUN WITH A ROOT CRONTAB________
#
