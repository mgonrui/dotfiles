#!/bin/sh

device="EXIT"
device+="
$(bluetoothctl devices | cut -d ' ' -f3-)"

device=$(echo "$device" | fzf)

bluetoothctl disconnect

if [ "$device" == "EXIT" ]; then
	exit
elif [ "$device" == "OpenRun by Shokz" ]; then
	bluetoothctl connect 20:74:CF:95:6D:8D
	exit
elif [ "$device" == "AUKEY BR-C1" ]; then
	bluetoothctl connect FC:58:FA:A1:00:82
	exit
elif [ "$device" == "Bose QC35 II" ]; then
	bluetoothctl connect 2C:41:A1:82:E2:47
	exit
else
	exit
fi
