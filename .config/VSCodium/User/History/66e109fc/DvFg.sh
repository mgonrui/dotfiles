#!/bin/sh
shopt -s expand_aliases

# get the list of all my packages
command_list="$(nix-store -q --references /var/run/current-system/sw | cut -d'-' -f2- |  cut -d '-' -f 1 | 
grep -vw -e "tutanota" -e  "tor" -e "signal")"

# command_list="$(echo "$commandlist" | grep -v "signal")"
# append new options
command_list+="
book
bluetooth
firefox osint
xscreensaver-settings
firefox vanilla
execscript
tor-browser
tutanota-desktop
signal-desktop
lc 
hist
sr
mp
poweroff
proxmox
oil
"

selected="$(echo "$command_list" | fzf -i -m --reverse  )"

killterm(){
    local seconds="$1"
    sleep $seconds
    pkill alacritty
}

source ~/.config/zsh/aliases.sh
[ -z "$selected" ] && exit

# custom menu scripts 
if [ "$selected" == "book" ]; then
    setsid sh ~/.scripts/menu/book.sh
elif [ "$selected" == "execscript" ]; then
    sh ~/.scripts/menu/execscript.sh
elif [ "$selected" == "bluetooth" ]; then
    sh ~/.scripts/menu/bluetooth.sh

# authenticator needs more time to load
elif [ "$selected" == "proxmox" ]; then
    killterm 0.001 &
    setsid chromium &> /dev/null
elif [ "$selected" == "mp" ]; then
    killterm 0.001 &
    setsid strawberry &> /dev/null
elif [ "$selected" == "authenticator" ]; then
    killterm 0.01 &
    setsid authenticator &> /dev/null
elif [ "$selected" == "obsidian" ]; then
    killterm 0.01 &
    setsid obsidian &> /dev/null
elif [ "$selected" == "firefox vanilla" ]; then
    killterm 0.001 &
    setsid firefox -P vanilla 
elif [ "$selected" == "firefox osint" ]; then
    killterm 0.001 &
    setsid firefox -P osint
# elif [ "$selected" == "tutanota" ]; then
#     killterm 0.001 &
#     setsid tutanota-desktop
# elif [ "$selected" == "signal" ]; then
#     killterm 0.001 &
#     setsid signal-desktop 
else
    killterm 10 &
    killterm 0.001 &
    setsid "$selected"  &> /dev/null
fi

