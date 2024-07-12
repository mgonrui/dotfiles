#!/bin/sh
# shopt -s expand_aliases

# term="alacritty"

# killterm(){
#     local seconds="$1"
#     sleep $seconds
#     pkill "$term" 
# }


# desktop_file() {
# find /usr/share/applications -name "*.desktop" 2>/dev/null
# find /usr/local/share/applications -name "*.desktop" 2>/dev/null
# find "$HOME/.local/share/applications" -name "*.desktop" 2>/dev/null
# find /var/lib/flatpak/exports/share/applications -name "*.desktop" 2>/dev/null
# find "$HOME/.local/share/flatpak/exports/share/applications" -name "*.desktop" 2>/dev/null
# echo "
# www
# www osint
# www vanilla
# notes
# email
# library
# bluetooth
# xscreensaver-settings
# execscript
# virt-manager
# tor-browser
# signal-desktop
# lc 
# hist
# sr
# mp
# poweroff
# proxmox
# drracket
# "
# }

# export FZF_DEFAULT_OPTS="-e -i --info=hidden --layout=reverse --scroll-off=5 --tiebreak=index --bind 'home:first,end:last'"
# selected="$(desktop_file | sed 's/.desktop$//g' | sort | fzf -m -d / --with-nth -1 --prompt="select program(s) to open: ")"


# #source ~/.config/zsh/aliases.sh
# [ -z "$selected" ] && exit

# # custom menu scripts 
# if [ "$selected" == "library" ]; then
#     setsid sh ~/.scripts/menu/library.sh
# elif [ "$selected" == "execscript" ]; then
#     sh $HOME/.scripts/menu/execscript.sh
# elif [ "$selected" == "bluetooth" ]; then
#     sh $HOME/.scripts/menu/bluetooth.sh
# elif [ "$selected" == "proxmox" ]; then
#     killterm 0.001 &
#     setsid chromium &> /dev/null
# elif [ "$selected" == "www" ]; then
#     killterm 0.001 &
#     setsid $BROWSER &> /dev/null
# elif [ "$selected" == "mp" ]; then
#     killterm 0.001 &
#     setsid strawberry &> /dev/null
# # authenticator needs more time to load
# elif [ "$selected" == "authenticator" ]; then
#     killterm 0.01 &
#     setsid authenticator &> /dev/null
# elif [ "$selected" == "www vanilla" ]; then
#     killterm 0.001 &
#     setsid $BROWSER -P vanilla 
# elif [ "$selected" == "www osint" ]; then
#     killterm 0.001 &
#     setsid $BROWSER -P osint
# elif [ "$selected" == "email" ]; then
#     killterm 0.001 &
#     setsid tutanota-desktop
# elif [ "$selected" == "signal" ]; then
#     killterm 0.001 &
#     setsid signal-desktop 
# elif [ "$selected" == "notes" ]; then
#     killterm 0.001 &
#     setsid qownnotes
# else
#     killterm 10 &
#     killterm 0.001 &
#     setsid "$selected"  &> /dev/null
# fi


#!/usr/bin/env sh
# AUTHOR: gotbletu (@gmail|twitter|youtube|github|lbry)
#         https://www.youtube.com/user/gotbletu
# DESC:   launch app(s) with fzf like dmenu/rofi
# DEPEND: fzf sed coreutils findutils xdg-utils util-linux

desktop_file() {
  find /usr/share/applications -name "*.desktop" 2>/dev/null \
  && find /usr/local/share/applications -name "*.desktop" 2>/dev/null \
  && find "$HOME/.local/share/applications" -name "*.desktop" 2>/dev/null \
  && find /var/lib/flatpak/exports/share/applications -name "*.desktop" 2>/dev/null \
  && find "$HOME/.local/share/flatpak/exports/share/applications" -name "*.desktop" 2>/dev/null
}

selected="$(desktop_file | sed 's/.desktop//g' | sort | fzf -e -i -m --reverse --delimiter / --with-nth -1)"
[ -z "$selected" ] && exit
cd || return
echo "$selected" | while read -r line ; do setsid xdg-open "$line" ; done