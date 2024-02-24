#!/bin/sh
file=$(du -a --exclude "$HOME/.scrips/menu" ~/.scripts | fzf #| grep -i "\.pdf$" | cut -f2- | rev | cut -d. -f2- | rev | awk -F'/' '{print $NF}' | fzf -i -m --reverse)
path=$(find ~/documents/library -type f -name "$file".pdf)

if [ -e "$path" ]; then
	sh  ~/.scripts/menu/killterm.sh &
	setsid zathura  "$path" 
else
	exit
fi