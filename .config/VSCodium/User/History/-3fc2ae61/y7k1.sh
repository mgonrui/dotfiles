#!/bin/sh

#mouse settings
# xinput set-prop 'SN TECH      GAMINGMOUSᩅ' 'libinput Accel Profile Enabled' 0, 1 &
# xinput set-prop 'SN TECH      GAMINGMOUSᩅ' 'libinput Accel Speed' -0.5 &

# turn on monitors and turn off laptop screen
if xrandr --listmonitors | grep -q 'eDP1'; then
	xrandr --output "HDMI1" --set audio force-dvi --mode 1920x1080
	#xrandr --output "DP2" --mode 1440x900 --left-of "HDMI1"
	xrandr --output "DP2" --mode 1280x1024 --left-of "HDMI1"
	xrandr --output eDP1 --off
	qtile cmd-obj -o cmd -f reload_config
	# qtile cmd-obj -o cmd -f restart

# turn on laptop screen (and tv) and turn off monitors
else
	xrandr --output "eDP1" --mode 1920x1080
	xrandr --output "HDMI1" --set audio force-dvi --mode 1920x1080 --right-of "eDP1"
	xrandr --output DP2 --off
	qtile cmd-obj -o cmd -f reload_config
	# qtile cmd-obj -o cmd -f restart
fi
