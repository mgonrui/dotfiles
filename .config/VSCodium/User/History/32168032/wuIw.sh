#!/bin/sh
#xprompt -c -i -s -G C -g 400x50+0-150
# xprompt -c -i -s -G C -g 400x50+0-150
file=$(du -a ~/documents/library | grep -i "\.pdf$" | cut -f2- | rev | cut -d. -f2- | rev | awk -F'/' '{print $NF}' | xprompt -f  ) #-c -i -s -G C -g 1000x50+0-150) # fzf -i -m --reverse --border --margin 20%)
path=$(find ~/documents/library -type f -name "$file".pdf)

if [ -e "$path" ]; then
	distrobox enter arch -- zathura >/dev/null 2>&1 "$path" &
else
	exit
fi