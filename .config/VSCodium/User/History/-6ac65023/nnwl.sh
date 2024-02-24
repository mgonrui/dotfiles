#!/bin/sh

	bluetoothctl disconnect
	# echo "please enter the number of the device you want to connect: "
	# echo "(0) EXIT"
	# echo "(1) Shokz openrun"
	# echo "(2) Aukey bluetooth receiver"
	# echo "(3) Bose QC35 II"
	# read chosendevice
	device=$(bluetoothctl devices | cut -d ' ' -f3- | fzf)
	device+="
	quit
	"
	

	if [ "$device" -eq 0 ]; then
		exit
	elif [ "$device" -eq 1 ]; then
		echo "you chose the device shokz openrun"
		bluetoothctl connect 20:74:CF:95:6D:8D
		exit
	elif [ "$device" -eq 2 ]; then
		echo "you chose the device aukey bluetooth receiver"
		bluetoothctl connect FC:58:FA:A1:00:82
		exit
	elif [ "$device" -eq 3 ]; then
		echo "you chose the device aukey bluetooth receiver"
		bluetoothctl connect 2C:41:A1:82:E2:47
		exit
	else
		echo "number incorrect"
		sleep 1
	fi
