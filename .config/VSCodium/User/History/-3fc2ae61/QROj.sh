#!/bin/sh

# turn on monitors and turn off laptop screen
if (xrandr --listmonitors | grep -q 'eDP1') && (xrandr --listmonitors | grep -q 'HDMI1') && (xrandr --listmonitors | grep -q 'DP2'); then
	xrandr --output "HDMI1" --mode 1920x1080
	#xrandr --output "DP2" --mode 1440x900 --left-of "HDMI1"
	xrandr --output "DP2" --mode 1280x1024 --left-of "HDMI1"
	xrandr --output eDP1 --off
	qtile cmd-obj -o cmd -f reload_config

# turn on laptop screen (and tv) and turn off monitors
else
	xrandr --output "eDP1" --mode 1920x1080
	xrandr --output "HDMI1" --mode 1920x1080 --right-of "eDP1"
	xrandr --output DP2 --off
	qtile cmd-obj -o cmd -f reload_config
fi
