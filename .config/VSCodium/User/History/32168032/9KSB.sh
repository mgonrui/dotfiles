#!/bin/sh
file=$(du -a --exclude "$HOME/documents/library/.caltrash" ~/documents/library | grep -i "\.pdf$" | cut -f2- | rev | cut -d. -f2- | rev | awk -F'/' '{print $NF}' | fzf -i -m --reverse)
path=$(find ~/documents/library -type f -name "$file".pdf -type f ! -path "$HOME/documents/library/.caltrash/*")

if [ -e "$path" ]; then
	sh  ~/.scripts/menu/killterm.sh &
	setsid zathura  "$path" 
else
	exit
fi