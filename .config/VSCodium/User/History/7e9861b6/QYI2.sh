#!/usr/bin/env sh
# AUTHOR: gotbletu (@gmail|twitter|youtube|github|lbry)
#         https://www.youtube.com/user/gotbletu
# DESC:   launch other fzf scripts
# DEMO:   https://youtu.be/8SqakfCSzQk
# DEPEND: fzf grep findutils coreutils
# REFF:   Xterm config https://www.youtube.com/watch?v=mAUQsNUnk9I

# Hotkey Binding Examples ~/.xbindkeysrc
# "xterm -T fzf-nova -geometry 90x25+350+200 -fs 16 -e .scripts/fzf-nova.sh"
#   Mod4+space
#
# "alacritty -t fzf-nova --dimensions 90 20 --position 350 200 -e /path/to/script/fzf-nova"
#   Mod4+space

# DIR="${0%/*}"
# "$DIR"/"$(find "$DIR" -type f -exec basename {} \; | grep '^_' | sort | fzf -e -i --delimiter _ --with-nth='2..' --reverse --prompt="fzf: ")" 

cat ~/.scripts/fzf/options.txt | fzf -e -i  --reverse --prompt="fzf: "
