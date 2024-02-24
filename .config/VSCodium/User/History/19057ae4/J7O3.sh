#!/bin/sh
# fuzzy_win launches the script from param in a centered window

# Check if a Kitty terminal with the class name "KittyFuzzy" is already open
if xdotool search --onlyvisible --classname KittyFuzzy windowunmap; then
    # If it's open and visible, hide it (unmap)
    xdotool search --onlyvisible --classname KittyFuzzy windowunmap
elif xdotool search --classname KittyFuzzy windowmap; then
    # If it's open but not visible, bring it to the front (map)
    xdotool search --classname KittyFuzzy windowmap
else
    # If it's not open, launch a new Kitty terminal with the class name "KittyFuzzy"
    # and run the command passed as a parameter
    kitty --name KittyFuzzy -e "$1"

    # Sleep briefly to ensure the terminal window appears before resizing it
    sleep 0.5

    # Use xdotool to resize and position the terminal window as desired
    xdotool search --classname KittyFuzzy windowsize 40% 40%
    xdotool search --classname KittyFuzzy windowmove -- 30% 30%
fi
