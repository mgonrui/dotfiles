#!/bin/sh
# shopt -s expand_aliases

# # use it together with fuzzy_win like this: fuzzy_win fuzzy_cmd
# selected="$(compgen -c | fzf -e -i -m --reverse --delimiter / --with-nth -3,-2,-1 )";
# source ~/.config/zsh/aliases.sh
# [ -z "$selected" ] && exit;
# if [ "$selected" == "firefox" ];  then
#     firefox
# else
#     "$selected"
# fi
# kitty zsh -c "fzf $* < /proc/$$/fd/0 > /proc/$$/fd/1" 
kitty bash -c "fzf $* < /proc/$$/fd/0 > /proc/$$/fd/1"