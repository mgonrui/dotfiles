export LANG="en_US.UTF-8"
export ZDOTDIR="$HOME/.config/zsh"
export PATH="$PATH:$HOME/.config/emacs/bin"
export PATH="$PATH:$HOME/bin"
export PATH="$PATH:$HOME/.local/bin"
export HEADER42_LOGIN="mariogo2"
export HEADER42_MAIL="mariogo2@student.42malaga.com"
# hook direnv to zsh
eval "$(direnv hook zsh)"
export DIRENV_LOG_FORMAT=""
# hook starship to zsh
eval "$(starship init zsh)"

# use neovim for opening man pages
export MANPAGER='nvim +Man!'
# start ssh-agent
# [ -z "$SSH_AUTH_SOCK" ] && eval "$(ssh-agent -s)" 

# set history
HISTFILE="$HOME/.cache/zsh/history"
HISTSIZE=100000
SAVEHIST=100000
HISTCONTROL="ignoredups"
unsetopt extended_history 

# enable case-insensitive path autocompletion
autoload -Uz compinit && compinit
zstyle ':completion:*' matcher-list 'm:{a-z}={A-Za-z}'

# load aliases
if [ -f $HOME/.config/zsh/aliases.sh ]; then
    . $HOME/.config/zsh/aliases.sh
fi


# basic auto/tab complete:
autoload -U compinit
compinit -d "$XDG_CACHE_HOME"/zsh/zcompdump-"$ZSH_VERSION"

# zstyle ':completion:*' menu select
zstyle ':completion:*' list-colors ${(s.:.)LS_COLORS}
zstyle ':completion:*' menu select yes=long
zmodload zsh/complist
compinit
_comp_options+=(globdots)		# Include hidden files.

# vi mode
bindkey -v
export KEYTIMEOUT=1

# Use vi keys in tab complete menu:
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

# enable shell to send info to vterm (emacs terminal emulator).
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

42cformat(){
	find . -type f \( -name "*.c" -o -name "*.h" \) | xargs -I {} sh -c 'nvim --headless "+Stdheader" +wq {} &> /dev/null; c_formatter_42 {} &> /dev/null ; norminette {} | grep -v "Setting locale to en_US"'
}


vterm_prompt_end() {
    vterm_printf "51;A$(whoami)@$(hostname):$(pwd)"
}
setopt PROMPT_SUBST
PROMPT=$PROMPT'%{$(vterm_prompt_end)%}'
