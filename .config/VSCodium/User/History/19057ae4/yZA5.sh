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
    # and position it at a centered location with a specific geometry
    kitty --name KittyFuzzy --geometry 40x8+297+1 -e "$1"
fi
