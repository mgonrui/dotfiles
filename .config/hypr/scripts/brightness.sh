#!/bin/bash

# Set the I2C device for your monitor
i2c_device="/dev/i2c-2"

# Get brightness plus or minus percent from args
change="$1"

# Get the current brightness
current_brightness=$(ddccontrol -r 0x10 dev:/dev/i2c-2 2>/dev/null | grep Brightness | awk '{print $3}' | awk -F/ '{print $2}')
# Calculate the new brightness
new_brightness=$((current_brightness + change))

# Clamp the brightness to the valid range (0–100)
if ((new_brightness > 100)); then
    new_brightness=100
elif ((new_brightness < 0)); then
    new_brightness=0
fi

# Set the new brightness
ddccontrol -r 0x10 -w $new_brightness dev:$i2c_device
# send signal to waybar to update brightness module
pkill -RTMIN+10 waybar
