#export TMOUT=50
export LANG="en_US.UTF-8"
export ZDOTDIR=$HOME/.config/zsh
export PATH="$HOME/.config/emacs/bin:$PATH"
# hook direnv to zsh
eval "$(direnv hook zsh)"
export DIRENV_LOG_FORMAT=""
#export DIRENV_WARN_TIMEOUT="100y"

# start ssh-agent
# [ -z "$SSH_AUTH_SOCK" ] && eval "$(ssh-agent -s)" 

# set history
HISTFILE=~/.cache/zsh/history
HISTSIZE=100000
SAVEHIST=100000
unsetopt extended_history 

# enable case-insensitive path autocompletion
autoload -Uz compinit && compinit
zstyle ':completion:*' matcher-list 'm:{a-z}={A-Za-z}'

# load aliases
if [ -f ~/.config/zsh/aliases.sh ]; then
    . ~/.config/zsh/aliases.sh
fi

# enable colors
autoload -U colors && colors
PS1="%B%{$fg[red]%}[%{$fg[yellow]%}%n%{$fg[green]%}@%{$fg[blue]%}%M %{$fg[magenta]%}%~%{$fg[red]%}]%{$reset_color%}$%b "

# basic auto/tab complete:
# tab completion for dnf requires installing sqlite
autoload -U compinit
# zstyle ':completion:*' menu select
zstyle ':completion:*' list-colors ${(s.:.)LS_COLORS}
zstyle ':completion:*' menu select yes=long
zmodload zsh/complist
compinit
_comp_options+=(globdots)		# Include hidden files.

# vi mode
bindkey -v
export KEYTIMEOUT=1

# Use vim keys in tab complete menu:
bindkey -M menuselect 'h' vi-backward-char
bindkey -M menuselect 'k' vi-up-line-or-history
bindkey -M menuselect 'l' vi-forward-char
bindkey -M menuselect 'j' vi-down-line-or-history
bindkey -v '^?' backward-delete-char

# Change cursor shape for different vi modes.
function zle-keymap-select {
    if [[ ${KEYMAP} == vicmd ]] ||
    [[ $1 = 'block' ]]; then
        echo -ne '\e[2 q'
    elif [[ ${KEYMAP} == main ]] ||
    [[ ${KEYMAP} == viins ]] ||
    [[ ${KEYMAP} = '' ]] ||
    [[ $1 = 'beam' ]]; then
        echo -ne '\e[6 q'
    fi
}
zle -N zle-keymap-select
zle-line-init() {
    zle -K viins # initiate `vi insert` as keymap (can be removed if `bindkey -V` has been set elsewhere)
    echo -ne "\e[6 q"
}
zle -N zle-line-init
echo -ne '\e[6 q' # Use beam shape cursor on startup.
preexec() { echo -ne '\e[6 q' ;} # Use beam shape cursor for each new prompt.


vterm_printf() {
    if [ -n "$TMUX" ] && ([ "${TERM%%-*}" = "tmux" ] || [ "${TERM%%-*}" = "screen" ]); then
        # Tell tmux to pass the escape sequences through
        printf "\ePtmux;\e\e]%s\007\e\\" "$1"
    elif [ "${TERM%%-*}" = "screen" ]; then
        # GNU screen (screen, screen-256color, screen-256color-bce)
        printf "\eP\e]%s\007\e\\" "$1"
    else
        printf "\e]%s\e\\" "$1"
    fi
}

declare -A pomo_options
pomo_options["work"]="1"
pomo_options["break"]="1"

pomodoro () {
    if [ -n "$1" -a -n "${pomo_options["$1"]}" ]; then
    val=$1
    echo $val | lolcat
    timer ${pomo_options["$val"]}m
    spd-say "'$val' session done"
    fi
}


compinit -d "$XDG_CACHE_HOME"/zsh/zcompdump-"$ZSH_VERSION"

eval "$(starship init zsh)"


bmenu() {
launchapp=$(IFS=':'; \
  for p in ${PATH}; \
  do find -L "${p}" -type f -executable -print 2> /dev/null; done \
  | fzf --header="Select application to launch from PATH:" \
    --multi=0 \
    --exact \
    --height="50%" \
    --preview="(file -b {})" \
    --preview-window="down:wrap:3") \
  && bash -c "${launchapp}"
}

# Created by `pipx` on 2024-10-20 16:46:56
export PATH="$PATH:/home/mgr/.local/bin"
