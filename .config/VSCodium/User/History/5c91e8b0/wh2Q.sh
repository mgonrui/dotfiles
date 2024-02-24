#!/bin/sh

source ./menu.sh

file=$(du -a --exclude "$HOME/documents/library/.caltrash" ~/documents/library | grep -i "\.pdf$" | cut -f2- | rev | cut -d. -f2- | rev | awk -F'/' '{print $NF}' | fzf -i -m --reverse)
path=$(find ~/documents/library -type f -name "$file".pdf)

if [ -e "$path" ]; then
	setsid zathura  "$path" 
else
	exit
fi